#include "hm2_xp.h"
#include <stdio.h>
#include <Shlobj.h>
#include <locale.h>

HMODULE		hKernelLibrary, hShellLibrary;

// GetProcAddress with validator
FARPROC WINAPI GetProcAddress_Validate(HMODULE hModule, LPCSTR lpProcName)
{
	FARPROC		tempFarproc = GetProcAddress(hModule, lpProcName);
	if ( tempFarproc == NULL )
	{
		char		cTemp[MAX_PATH];
		sprintf(cTemp, "Failed to locate %s", lpProcName);
		MessageBoxA(NULL, cTemp, "HM2 XP Patch", MB_OK);
	}
	return tempFarproc;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	//UNREFERENCED_PARAMETER(hModule);
	UNREFERENCED_PARAMETER(lpReserved);

	switch ( reason )
	{
	case DLL_PROCESS_ATTACH:
		hKernelLibrary = LoadLibrary(L"kernel32");
		hShellLibrary = LoadLibrary(L"shell32");
#ifdef _DEBUG
		ResolveKernelDepends((unsigned int)hKernelLibrary, (void*(__stdcall*)(unsigned int,const char*))GetProcAddress_Validate);
		ResolveShellDepends((unsigned int)hShellLibrary, (void*(__stdcall*)(unsigned int,const char*))GetProcAddress_Validate);
#else
		ResolveKernelDepends((unsigned int)hKernelLibrary, (void*(__stdcall*)(unsigned int,const char*))GetProcAddress);
		ResolveShellDepends((unsigned int)hShellLibrary, (void*(__stdcall*)(unsigned int,const char*))GetProcAddress);
#endif
		break;
	case DLL_PROCESS_DETACH:
		FreeLibrary(hKernelLibrary);
		FreeLibrary(hShellLibrary);
		break;
	}
	return TRUE;
}


// kernel32 emulation functions
VOID WINAPI InitializeConditionVariable(PCONDITION_VARIABLE ConditionVariable) 
{
	*(PHANDLE)ConditionVariable = CreateEvent(NULL, FALSE, TRUE, NULL);
}

BOOL WINAPI SleepConditionVariableCS( PCONDITION_VARIABLE ConditionVariable, PCRITICAL_SECTION CriticalSection, DWORD dwMilliseconds)
{
	DWORD dwResult;
	LeaveCriticalSection(CriticalSection);
	dwResult = WaitForSingleObject(*(PHANDLE)ConditionVariable, dwMilliseconds);
	//LeaveCriticalSection(CriticalSection);
	EnterCriticalSection(CriticalSection);

	return dwResult == WAIT_OBJECT_0 ? TRUE : FALSE;
}

VOID WINAPI WakeAllConditionVariable(PCONDITION_VARIABLE ConditionVariable)
{
	// TODO: Probably unreliable
	SetEvent(*(PHANDLE)ConditionVariable);
	//PulseEvent(*(PHANDLE)ConditionVariable);
}

int WINAPI GetUserDefaultLocaleName(LPWSTR lpLocaleName, int cchLocaleName)
{
	lpLocaleName = _wsetlocale(LC_ALL, NULL);
	return wcslen(lpLocaleName);
}

DWORD WINAPI GetVersion()
{
	return 0;
}


// shell32 emulation functions
HRESULT WINAPI SHGetKnownFolderPath(REFKNOWNFOLDERID rfid, DWORD dwFlags, HANDLE hToken, PWSTR *ppszPath)
{
	// Always operates on FOLDERID_Documents here
	HRESULT hResult;
	wchar_t	wcTempString[MAX_PATH];
	size_t	nLen;
	LPVOID	pAlloc;
	
	hResult = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wcTempString);
	if ( hResult == S_OK )
	{
		nLen = wcslen(wcTempString) + 1;

		pAlloc = CoTaskMemAlloc((nLen+1)*sizeof(wchar_t));
		wcscpy((wchar_t*)pAlloc, wcTempString);
		*ppszPath = (PWSTR)pAlloc;
	}
	return hResult;
}