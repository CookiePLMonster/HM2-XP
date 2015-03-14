static void* varCloseHandle;
void __declspec(dllexport,naked) CloseHandle() {
	_asm jmp varCloseHandle
}

static void* varCreateDirectoryExA;
void __declspec(dllexport,naked) CreateDirectoryExA() {
	_asm jmp varCreateDirectoryExA
}

static void* varCreateSemaphoreA;
void __declspec(dllexport,naked) CreateSemaphoreA() {
	_asm jmp varCreateSemaphoreA
}

static void* varDecodePointer;
void __declspec(dllexport,naked) DecodePointer() {
	_asm jmp varDecodePointer
}

static void* varDeleteCriticalSection;
void __declspec(dllexport,naked) DeleteCriticalSection() {
	_asm jmp varDeleteCriticalSection
}

static void* varEncodePointer;
void __declspec(dllexport,naked) EncodePointer() {
	_asm jmp varEncodePointer
}

static void* varEnterCriticalSection;
void __declspec(dllexport,naked) EnterCriticalSection() {
	_asm jmp varEnterCriticalSection
}

static void* varFindClose;
void __declspec(dllexport,naked) FindClose() {
	_asm jmp varFindClose
}

static void* varFindFirstFileA;
void __declspec(dllexport,naked) FindFirstFileA() {
	_asm jmp varFindFirstFileA
}

static void* varFindNextFileA;
void __declspec(dllexport,naked) FindNextFileA() {
	_asm jmp varFindNextFileA
}

static void* varFreeLibrary;
void __declspec(dllexport,naked) FreeLibrary() {
	_asm jmp varFreeLibrary
}

static void* varGetCurrentProcess;
void __declspec(dllexport,naked) GetCurrentProcess() {
	_asm jmp varGetCurrentProcess
}

static void* varGetCurrentProcessId;
void __declspec(dllexport,naked) GetCurrentProcessId() {
	_asm jmp varGetCurrentProcessId
}

static void* varGetCurrentThreadId;
void __declspec(dllexport,naked) GetCurrentThreadId() {
	_asm jmp varGetCurrentThreadId
}

static void* varGetFileAttributesA;
void __declspec(dllexport,naked) GetFileAttributesA() {
	_asm jmp varGetFileAttributesA
}

static void* varGetModuleHandleW;
void __declspec(dllexport,naked) GetModuleHandleW() {
	_asm jmp varGetModuleHandleW
}

static void* varGetProcAddress;
void __declspec(dllexport,naked) GetProcAddress() {
	_asm jmp varGetProcAddress
}

static void* varGetShortPathNameW;
void __declspec(dllexport,naked) GetShortPathNameW() {
	_asm jmp varGetShortPathNameW
}

static void* varGetStartupInfoW;
void __declspec(dllexport,naked) GetStartupInfoW() {
	_asm jmp varGetStartupInfoW
}

static void* varGetSystemTimeAsFileTime;
void __declspec(dllexport,naked) GetSystemTimeAsFileTime() {
	_asm jmp varGetSystemTimeAsFileTime
}

static void* varGetTickCount;
void __declspec(dllexport,naked) GetTickCount() {
	_asm jmp varGetTickCount
}

static void* varHeapSetInformation;
void __declspec(dllexport,naked) HeapSetInformation() {
	_asm jmp varHeapSetInformation
}

static void* varInitializeCriticalSection;
void __declspec(dllexport,naked) InitializeCriticalSection() {
	_asm jmp varInitializeCriticalSection
}

static void* varInterlockedCompareExchange;
void __declspec(dllexport,naked) InterlockedCompareExchange() {
	_asm jmp varInterlockedCompareExchange
}

static void* varInterlockedExchange;
void __declspec(dllexport,naked) InterlockedExchange() {
	_asm jmp varInterlockedExchange
}

static void* varIsDebuggerPresent;
void __declspec(dllexport,naked) IsDebuggerPresent() {
	_asm jmp varIsDebuggerPresent
}

static void* varIsProcessorFeaturePresent;
void __declspec(dllexport,naked) IsProcessorFeaturePresent() {
	_asm jmp varIsProcessorFeaturePresent
}

static void* varLeaveCriticalSection;
void __declspec(dllexport,naked) LeaveCriticalSection() {
	_asm jmp varLeaveCriticalSection
}

static void* varLoadLibraryW;
void __declspec(dllexport,naked) LoadLibraryW() {
	_asm jmp varLoadLibraryW
}

static void* varMultiByteToWideChar;
void __declspec(dllexport,naked) MultiByteToWideChar() {
	_asm jmp varMultiByteToWideChar
}

static void* varQueryPerformanceCounter;
void __declspec(dllexport,naked) QueryPerformanceCounter() {
	_asm jmp varQueryPerformanceCounter
}

static void* varQueryPerformanceFrequency;
void __declspec(dllexport,naked) QueryPerformanceFrequency() {
	_asm jmp varQueryPerformanceFrequency
}

static void* varReleaseSemaphore;
void __declspec(dllexport,naked) ReleaseSemaphore() {
	_asm jmp varReleaseSemaphore
}

static void* varRemoveDirectoryA;
void __declspec(dllexport,naked) RemoveDirectoryA() {
	_asm jmp varRemoveDirectoryA
}

static void* varSetCurrentDirectoryW;
void __declspec(dllexport,naked) SetCurrentDirectoryW() {
	_asm jmp varSetCurrentDirectoryW
}

static void* varSetThreadPriority;
void __declspec(dllexport,naked) SetThreadPriority() {
	_asm jmp varSetThreadPriority
}

static void* varSetUnhandledExceptionFilter;
void __declspec(dllexport,naked) SetUnhandledExceptionFilter() {
	_asm jmp varSetUnhandledExceptionFilter
}

static void* varSleep;
void __declspec(dllexport,naked) Sleep() {
	_asm jmp varSleep
}

static void* varTerminateProcess;
void __declspec(dllexport,naked) TerminateProcess() {
	_asm jmp varTerminateProcess
}

static void* varTlsAlloc;
void __declspec(dllexport,naked) TlsAlloc() {
	_asm jmp varTlsAlloc
}

static void* varTlsFree;
void __declspec(dllexport,naked) TlsFree() {
	_asm jmp varTlsFree
}

static void* varTlsGetValue;
void __declspec(dllexport,naked) TlsGetValue() {
	_asm jmp varTlsGetValue
}

static void* varTlsSetValue;
void __declspec(dllexport,naked) TlsSetValue() {
	_asm jmp varTlsSetValue
}

static void* varUnhandledExceptionFilter;
void __declspec(dllexport,naked) UnhandledExceptionFilter() {
	_asm jmp varUnhandledExceptionFilter
}

static void* varWaitForSingleObject;
void __declspec(dllexport,naked) WaitForSingleObject() {
	_asm jmp varWaitForSingleObject
}

static void* varWaitForSingleObjectEx;
void __declspec(dllexport,naked) WaitForSingleObjectEx() {
	_asm jmp varWaitForSingleObjectEx
}

static void* varWideCharToMultiByte;
void __declspec(dllexport,naked) WideCharToMultiByte() {
	_asm jmp varWideCharToMultiByte
}

void ResolveKernelDepends(unsigned int hModule, void* (__stdcall* pGetProcAddressFunc)(unsigned int,const char*))
{
	varCloseHandle = pGetProcAddressFunc(hModule, "CloseHandle");
	varCreateDirectoryExA = pGetProcAddressFunc(hModule, "CreateDirectoryExA");
	varCreateSemaphoreA = pGetProcAddressFunc(hModule, "CreateSemaphoreA");
	varDecodePointer = pGetProcAddressFunc(hModule, "DecodePointer");
	varDeleteCriticalSection = pGetProcAddressFunc(hModule, "DeleteCriticalSection");
	varEncodePointer = pGetProcAddressFunc(hModule, "EncodePointer");
	varEnterCriticalSection = pGetProcAddressFunc(hModule, "EnterCriticalSection");
	varFindClose = pGetProcAddressFunc(hModule, "FindClose");
	varFindFirstFileA = pGetProcAddressFunc(hModule, "FindFirstFileA");
	varFindNextFileA = pGetProcAddressFunc(hModule, "FindNextFileA");
	varFreeLibrary = pGetProcAddressFunc(hModule, "FreeLibrary");
	varGetCurrentProcess = pGetProcAddressFunc(hModule, "GetCurrentProcess");
	varGetCurrentProcessId = pGetProcAddressFunc(hModule, "GetCurrentProcessId");
	varGetCurrentThreadId = pGetProcAddressFunc(hModule, "GetCurrentThreadId");
	varGetFileAttributesA = pGetProcAddressFunc(hModule, "GetFileAttributesA");
	varGetModuleHandleW = pGetProcAddressFunc(hModule, "GetModuleHandleW");
	varGetProcAddress = pGetProcAddressFunc(hModule, "GetProcAddress");
	varGetShortPathNameW = pGetProcAddressFunc(hModule, "GetShortPathNameW");
	varGetStartupInfoW = pGetProcAddressFunc(hModule, "GetStartupInfoW");
	varGetSystemTimeAsFileTime = pGetProcAddressFunc(hModule, "GetSystemTimeAsFileTime");
	varGetTickCount = pGetProcAddressFunc(hModule, "GetTickCount");
	varHeapSetInformation = pGetProcAddressFunc(hModule, "HeapSetInformation");
	varInitializeCriticalSection = pGetProcAddressFunc(hModule, "InitializeCriticalSection");
	varInterlockedCompareExchange = pGetProcAddressFunc(hModule, "InterlockedCompareExchange");
	varInterlockedExchange = pGetProcAddressFunc(hModule, "InterlockedExchange");
	varIsDebuggerPresent = pGetProcAddressFunc(hModule, "IsDebuggerPresent");
	varIsProcessorFeaturePresent = pGetProcAddressFunc(hModule, "IsProcessorFeaturePresent");
	varLeaveCriticalSection = pGetProcAddressFunc(hModule, "LeaveCriticalSection");
	varLoadLibraryW = pGetProcAddressFunc(hModule, "LoadLibraryW");
	varMultiByteToWideChar = pGetProcAddressFunc(hModule, "MultiByteToWideChar");
	varQueryPerformanceCounter = pGetProcAddressFunc(hModule, "QueryPerformanceCounter");
	varQueryPerformanceFrequency = pGetProcAddressFunc(hModule, "QueryPerformanceFrequency");
	varReleaseSemaphore = pGetProcAddressFunc(hModule, "ReleaseSemaphore");
	varRemoveDirectoryA = pGetProcAddressFunc(hModule, "RemoveDirectoryA");
	varSetCurrentDirectoryW = pGetProcAddressFunc(hModule, "SetCurrentDirectoryW");
	varSetThreadPriority = pGetProcAddressFunc(hModule, "SetThreadPriority");
	varSetUnhandledExceptionFilter = pGetProcAddressFunc(hModule, "SetUnhandledExceptionFilter");
	varSleep = pGetProcAddressFunc(hModule, "Sleep");
	varTerminateProcess = pGetProcAddressFunc(hModule, "TerminateProcess");
	varTlsAlloc = pGetProcAddressFunc(hModule, "TlsAlloc");
	varTlsFree = pGetProcAddressFunc(hModule, "TlsFree");
	varTlsGetValue = pGetProcAddressFunc(hModule, "TlsGetValue");
	varTlsSetValue = pGetProcAddressFunc(hModule, "TlsSetValue");
	varUnhandledExceptionFilter = pGetProcAddressFunc(hModule, "UnhandledExceptionFilter");
	varWaitForSingleObject = pGetProcAddressFunc(hModule, "WaitForSingleObject");
	varWaitForSingleObjectEx = pGetProcAddressFunc(hModule, "WaitForSingleObjectEx");
	varWideCharToMultiByte = pGetProcAddressFunc(hModule, "WideCharToMultiByte");
}