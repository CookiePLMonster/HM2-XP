#define WIN32_LEAN_AND_MEAN

#define WINVER 0x0500
#define _WIN32_WINNT 0x0500

#include <Windows.h>

// kernel32 stubs resolving
void ResolveKernelDepends(unsigned int hModule, void* (__stdcall* pGetProcAddressFunc)(unsigned int,const char*));

// shell32 stubs resolving
void ResolveShellDepends(unsigned int hModule, void* (__stdcall* pGetProcAddressFunc)(unsigned int,const char*));