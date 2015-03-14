#pragma warning(disable:4273)	// inconsistent dll linkage

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#define WINVER 0x0500
#define _WIN32_WINNT 0x0500

#include <Windows.h>

#include <stdio.h>
#include <Shlobj.h>
#include <locale.h>

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