static void* varDragAcceptFiles;
void __declspec(dllexport,naked) DragAcceptFiles() {
	_asm jmp varDragAcceptFiles
}

static void* varDragFinish;
void __declspec(dllexport,naked) DragFinish() {
	_asm jmp varDragFinish
}

static void* varDragQueryFileW;
void __declspec(dllexport,naked) DragQueryFileW() {
	_asm jmp varDragQueryFileW
}

static void* varDragQueryPoint;
void __declspec(dllexport,naked) DragQueryPoint() {
	_asm jmp varDragQueryPoint
}

static void* varSHCreateDirectoryExA;
void __declspec(dllexport,naked) SHCreateDirectoryExA() {
	_asm jmp varSHCreateDirectoryExA
}

static void* varSHGetKnownFolderPath;
void __declspec(dllexport,naked) SHGetKnownFolderPath() {
	_asm jmp varSHGetKnownFolderPath
}