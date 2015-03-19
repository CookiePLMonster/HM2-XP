/*
 *  Hotline Miami 2: Wrong Number XP Support Patch
 *	kernel32/shell wrapper
 *      Created by Silent <zdanio95@gmail.com>
 */


#pragma warning(disable:4273)	// inconsistent dll linkage

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#define WINVER 0x0500
#define _WIN32_WINNT 0x0500

#include <Windows.h>

#include <stdio.h>
#include <Shlobj.h>
#include <locale.h>
#include <stddef.h>
#include <assert.h>

// LCID helpers
#define LCID_PRIMARY_LANG(a)	((a) & 0x3FF)
#define LCID_SUBLANG(a)			(((a) >> 10) & 0x3F)

// kernel32 emulation functions
VOID WINAPI InitializeConditionVariable(PCONDITION_VARIABLE ConditionVariable)
{
	*(PHANDLE)ConditionVariable = CreateEvent(NULL, FALSE, TRUE, NULL);
}

BOOL WINAPI SleepConditionVariableCS( PCONDITION_VARIABLE ConditionVariable, PCRITICAL_SECTION CriticalSection, DWORD dwMilliseconds)
{
	DWORD dwResult;
	assert(CriticalSection->RecursionCount == 1);	// Validating AG's code ;)
	LeaveCriticalSection(CriticalSection);
	dwResult = WaitForSingleObject(*(PHANDLE)ConditionVariable, dwMilliseconds);
	EnterCriticalSection(CriticalSection);

	return dwResult == WAIT_OBJECT_0 ? TRUE : FALSE;
}

VOID WINAPI WakeAllConditionVariable(PCONDITION_VARIABLE ConditionVariable)
{
	// TODO: Probably a bit unreliable?
	SetEvent(*(PHANDLE)ConditionVariable);
	//PulseEvent(*(PHANDLE)ConditionVariable);
}

int WINAPI GetUserDefaultLocaleName(LPWSTR lpLocaleName, int cchLocaleName)
{
	// Those are all locales AG uses
	LCID	LanguageCode = GetUserDefaultLCID();
	switch ( LCID_PRIMARY_LANG(LanguageCode) )
	{
	case LANG_FRENCH:
		wcscpy(lpLocaleName, L"fr");
		return sizeof("fr");	// It's a nice trick, returns the length of the string
								// together with a null terminator, which we need to
								// include in function's return value
	case LANG_ITALIAN:
		wcscpy(lpLocaleName, L"it");
		return sizeof("it");
	case LANG_GERMAN:
		wcscpy(lpLocaleName, L"de");
		return sizeof("de");
	case LANG_SPANISH:
		wcscpy(lpLocaleName, L"es");
		return sizeof("es");
	case LANG_PORTUGUESE:
		if ( LCID_SUBLANG(LanguageCode) == SUBLANG_PORTUGUESE_BRAZILIAN )
		{
			wcscpy(lpLocaleName, L"pt-BR");
			return sizeof("pt-BR");
		}
		wcscpy(lpLocaleName, L"pt");
		return sizeof("pt");
	case LANG_POLISH:
		wcscpy(lpLocaleName, L"pl");
		return sizeof("pl");
	case LANG_RUSSIAN:
		wcscpy(lpLocaleName, L"ru");
		return sizeof("ru");
	}

	// We'll default to en
	wcscpy(lpLocaleName, L"en");
	return sizeof("en");
}

DWORD WINAPI GetVersion()
{
	// TODO: Might not be needed after future official patches
	return 0;
}


// shell32 emulation functions
HRESULT WINAPI SHGetKnownFolderPath(REFKNOWNFOLDERID rfid, DWORD dwFlags, HANDLE hToken, PWSTR *ppszPath)
{
	// NOTE: Not needed as of 1.03, keeping it there for backwarda compatibility purposes

	// Always operates on FOLDERID_Documents here
	HRESULT hResult;
	wchar_t	wcTempString[MAX_PATH];
	size_t	nLen;
	LPVOID	pAlloc;

	hResult = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, wcTempString);
	if ( hResult == S_OK )
	{
		nLen = wcslen(wcTempString);

		pAlloc = CoTaskMemAlloc((nLen+1)*sizeof(wchar_t));
		wcscpy((wchar_t*)pAlloc, wcTempString);
		*ppszPath = (PWSTR)pAlloc;
	}
	return hResult;
}


// EXE patcher
void CALLBACK _patchexeW(HWND hwnd, HINSTANCE hinst, LPWSTR lpszCmdLine, int nCmdShow)
{
	// TODO: MAKE THIS READ AN ENTIRE EXE AT ONCE AND PATCH THOSE STRINGS WITHIN A BUFFER
	// INSTEAD OF THIS ODDLY LOOKING MESS


	// This opens a HM2 EXE and patches kernel32.dll and shell32.dll imports to use hm2_xp.dll instead
	FILE* hFile;

	// First, create a backup
	CopyFile(lpszCmdLine, L"HotlineMiami2.exe.bak", FALSE);

	if ( hFile = _wfopen(lpszCmdLine, L"rb+") )
	{
		DWORD					dwNTOffset;
		WORD					NumberOfSections;
		WORD					i;
		DWORD					IATOffset;
		ptrdiff_t				RVAOffset;
		long					dwKernelOffset = 0, dwShellOffset = 0;
		char					cDLLNameBuf[16];


		// Skip to IMAGE_DOS_HEADER.e_lfanew
		fseek(hFile, offsetof(IMAGE_DOS_HEADER, e_lfanew), SEEK_SET);
		fread(&dwNTOffset, sizeof(DWORD), 1, hFile);

		// Skip to IMAGE_FILE_HEADER.NumberOfSections
		fseek(hFile, dwNTOffset + offsetof(IMAGE_NT_HEADERS, FileHeader.NumberOfSections), SEEK_SET);
		fread(&NumberOfSections, sizeof(NumberOfSections), 1, hFile);

		// Skip to the imports directory
		fseek(hFile, dwNTOffset + offsetof(IMAGE_NT_HEADERS, OptionalHeader) + 104, SEEK_SET);	// 104, as seen on MSDN
		fread(&IATOffset, sizeof(DWORD), 1, hFile);

		// Skip to IMAGE_SECTION_HEADER array
		fseek(hFile, dwNTOffset + sizeof(IMAGE_NT_HEADERS), SEEK_SET);
		//fread(&dwNumSections, sizeof(DWORD), 1, hFile);

		// Read sections until .rdata is found
		for ( i = 0; i < NumberOfSections; i++ )
		{
			IMAGE_SECTION_HEADER	sectionHeader;

			fread(&sectionHeader, sizeof(sectionHeader), 1, hFile);
			if ( strncmp((const char*)sectionHeader.Name, ".rdata", IMAGE_SIZEOF_SHORT_NAME) == 0 )
			{
				RVAOffset = sectionHeader.VirtualAddress - sectionHeader.PointerToRawData;	// We'll need this data later on
				break;
			}
		}

		// Skip to the first IMAGE_IMPORT_DESCRIPTOR
		fseek(hFile, IATOffset - RVAOffset, SEEK_SET);
		i = 0;

		// Read those until we find shell32 or kernel32
		while ( dwKernelOffset == 0 || dwShellOffset == 0 )
		{
			IMAGE_IMPORT_DESCRIPTOR descriptor;
			long dwCurOffset;

			fread(&descriptor, sizeof(descriptor), 1, hFile);
			if ( descriptor.Characteristics == 0 )
				break;	// No more imports, exit

			// Seek to the name
			dwCurOffset = descriptor.Name - RVAOffset;
			fseek(hFile, dwCurOffset, SEEK_SET);
			fread(cDLLNameBuf, 1, sizeof(cDLLNameBuf), hFile);
			if ( strncmp(cDLLNameBuf, "KERNEL32.dll", 16) == 0 )
				dwKernelOffset = dwCurOffset;
			else if ( strncmp(cDLLNameBuf, "SHELL32.dll", 16) == 0 )
				dwShellOffset = dwCurOffset;

			// fseek back
			fseek(hFile, IATOffset - RVAOffset + (++i * sizeof(IMAGE_IMPORT_DESCRIPTOR)), SEEK_SET);
		}

		if ( dwKernelOffset != 0 && dwShellOffset != 0 )
		{
			// Ready to rewind and write new imports names
			static const char		cNewImportName[] = "hm2_xp.dll";

			fseek(hFile, dwKernelOffset, SEEK_SET);
			fwrite(cNewImportName, 1, sizeof(cNewImportName), hFile);

			fseek(hFile, dwShellOffset, SEEK_SET);
			fwrite(cNewImportName, 1, sizeof(cNewImportName), hFile);
		}

		fclose(hFile);
	}
}