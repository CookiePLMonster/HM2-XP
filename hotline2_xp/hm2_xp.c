#define WIN32_LEAN_AND_MEAN

#define WINVER 0x0500
#define _WIN32_WINNT 0x0500

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	//UNREFERENCED_PARAMETER(hModule);
	UNREFERENCED_PARAMETER(lpReserved);

	switch ( reason )
	{
	case DLL_PROCESS_ATTACH:
		MessageBox(NULL, L"Yay I launched!", L"HM2 XP Patch", MB_OK);
		break;

	}
	return TRUE;
}