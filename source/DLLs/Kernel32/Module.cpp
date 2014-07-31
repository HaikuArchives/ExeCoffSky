/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Module.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Module.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Module.h"
#include "Process.h"
#include "Coff.h"
#include "Path.h"
#include "Kernel32.h"	// IsBadReadPtr
#include "Win32Trace.h"
#include "Win32String.h"
#include "Win32Error.h"

#if defined(_BUILTIN_DLL)

#include "Kernel32.h"
#include "AdvAPI32.h"
#include "User32.h"
#include "GDI32.h"
#include "WinMM.h"
#include "Shell32.h"
#include "Imm32.h"
#include "ComCtl32.h"
#include "WSock32.h"
#include "Ole32.h"
#include "ComDlg32.h"
#include "Version.h"
#include "DDraw.h"
#include "DSound.h"

BuiltInModule::BuiltInModule
(const char *name, Func_GetAddressByOrder ByOrder, Func_GetAddressByName ByName):
magic(BUILTIN_DLL_MAGIC),
ByOrder(ByOrder),
ByName(ByName)
{
	snprintf(this->name, PATH_MAX, "%s", name);
	AddRef();	// never destroyed
}

BuiltInModule::~BuiltInModule
(void)
{
	magic = 0;
}

const char *
BuiltInModule::GetFileName
(void) const
{
	return name;
}

void *
BuiltInModule::GetAddressByOrder
(int order) const
{
	return ByOrder(order);
}

void *
BuiltInModule::GetAddressByName
(const char *name) const
{
	return ByName(name);
}

void *
BuiltInModule::GetEntryPoint
(void) const
{
	return NULL;
}

HINSTANCE
BuiltInModule::GetInstance
(void) const
{
	return (HINSTANCE)this;
}

DWORD
BuiltInModule::GetVersion
(void) const
{
	return 0;
}

void *
BuiltInModule::GetResourceAddress
(void) const
{
	return NULL;
}

LpResourceDataEntry
BuiltInModule::FindResource
(int type, int id) const
{
	return NULL;
}

bool
BuiltInModule::ProcessAttach
(void)
{
	return true;
}

bool
BuiltInModule::ThreadAttach
(void)
{
	return true;
}

bool
BuiltInModule::ThreadDetach
(void)
{
	return true;
}

bool
BuiltInModule::ProcessDetach
(void)
{
	return true;
}

BuiltInModule *
BuiltInModule::InstanceToModule
(HINSTANCE hInstance)
{
	BuiltInModule *module = (BuiltInModule *)hInstance;
	if (NULL == module) return NULL;
	WIN32API_INTERNAL_START();
	if (TRUE == IsBadReadPtr(hInstance, sizeof(DWORD))) return NULL;
	WIN32API_INTERNAL_END();
	if (module->magic != BUILTIN_DLL_MAGIC) return NULL;
	return module;
}

BuiltInModule kernel32("KERNEL32.dll", Kernel32_GetAddressByOrder, Kernel32_GetAddressByName);
BuiltInModule advapi32("ADVAPI32.dll", AdvAPI32_GetAddressByOrder, AdvAPI32_GetAddressByName);
BuiltInModule user32("USER32.dll", User32_GetAddressByOrder, User32_GetAddressByName);
BuiltInModule gdi32("GDI32.dll", GDI32_GetAddressByOrder, GDI32_GetAddressByName);
BuiltInModule winmm("WINMM.dll", WinMM_GetAddressByOrder, WinMM_GetAddressByName);
BuiltInModule shell32("SHELL32.dll", Shell32_GetAddressByOrder, Shell32_GetAddressByName);
BuiltInModule imm32("IMM32.dll", Imm32_GetAddressByOrder, Imm32_GetAddressByName);
BuiltInModule comctl32("COMCTL32.dll", ComCtl32_GetAddressByOrder, ComCtl32_GetAddressByName);
BuiltInModule wsock32("WSOCK32.dll", WSock32_GetAddressByOrder, WSock32_GetAddressByName);
BuiltInModule ole32("OLE32.dll", Ole32_GetAddressByOrder, Ole32_GetAddressByName);
BuiltInModule comdlg32("COMDLG32.dll", ComDlg32_GetAddressByOrder, ComDlg32_GetAddressByName);
BuiltInModule version("VERSION.dll", Version_GetAddressByOrder, Version_GetAddressByName);
BuiltInModule ddraw("DDRAW.dll", DDraw_GetAddressByOrder, DDraw_GetAddressByName);
BuiltInModule dsound("DSOUND.dll", DSound_GetAddressByOrder, DSound_GetAddressByName);

#endif	// defined(_BUILTIN_DLL)

static Image *
HandleToImage
(HMODULE hModule)
{
	WIN32API_INTERNAL_START();
	if (TRUE == IsBadReadPtr(hModule, sizeof(DWORD))) hModule = NULL;
	if (NULL == hModule) {
		hModule = GetModuleHandleU(NULL);
	}
	WIN32API_INTERNAL_END();
	if (NULL == hModule) return NULL;
#if defined(_BUILTIN_DLL)
	BuiltInModule *module = BuiltInModule::InstanceToModule((HINSTANCE)hModule);
	if (NULL != module) return module;
#endif	// defined(_BUILTIN_DLL)
	return Coff::InstanceToCoff((HINSTANCE)hModule);
}

static bool
FindModule
(BString &filepath, LPCSTR lpFileName)
{
	Path path(lpFileName);
	path.ToNativePath(true);
	lpFileName = path.GetPath();
	WIN32API_INFO("\tnative path: %s\n", lpFileName);
	filepath.SetTo(lpFileName);
#if defined(_BUILTIN_DLL)
	if ((0 == strcasecmp("KERNEL32.dll", lpFileName)) ||
		(0 == strcasecmp("ADVAPI32.dll", lpFileName)) ||
		(0 == strcasecmp("USER32.dll", lpFileName)) ||
		(0 == strcasecmp("GDI32.dll", lpFileName)) ||
		(0 == strcasecmp("WINMM.dll", lpFileName)) ||
		(0 == strcasecmp("SHELL32.dll", lpFileName)) ||
		(0 == strcasecmp("IMM32.dll", lpFileName)) ||
		(0 == strcasecmp("COMCTL32.dll", lpFileName)) ||
		(0 == strcasecmp("WSOCK32.dll", lpFileName)) ||
		(0 == strcasecmp("OLE32.dll", lpFileName)) ||
		(0 == strcasecmp("COMDLG32.dll", lpFileName)) ||
		(0 == strcasecmp("VERSION.dll", lpFileName)) ||
		(0 == strcasecmp("DDRAW.dll", lpFileName)) ||
		(0 == strcasecmp("DSOUND.dll", lpFileName))) {
		WIN32API_INFO("\t\tfind in built-in dlls: %s\n", lpFileName);
		return true;
	}
#endif	// defined(_BUILTIN_DLL)

	struct stat sst;
	if (0 == stat(lpFileName, &sst)) {
		BPath path(lpFileName);
		filepath.SetTo(path.Path());
		WIN32API_INFO("\t\tpath = %s\n", filepath.String());
		return true;
	}
	
	const char *dllpath = getenv("DLL_PATH");
	if (NULL == dllpath) dllpath = ".";
	BString trypath;
	const char *st;
	const char *ed;
	for (st = dllpath; NULL != st; st = (0 == *ed)? NULL: &ed[1]) {
		ed = strchr(st, ':');
		if (NULL == ed) ed = &st[strlen(st)];
		int len = ed - st;
		trypath.SetTo(st, len);
		WIN32API_INFO("\t\tsearch in '%s'\n", trypath.String());
		DIR *dir = opendir(trypath.String());
		if (NULL != dir) {
			struct dirent *et;
			while (NULL != (et = readdir(dir))) {
				if (0 != strcasecmp(et->d_name, lpFileName)) {
					WIN32API_INFO("\t\t\t%s != %s\n", et->d_name, lpFileName);
				} else {
					filepath.SetTo(trypath.String());
					filepath << "/";
					filepath << et->d_name;
					closedir(dir);
					BPath path(filepath.String());
					filepath.SetTo(path.Path());
					WIN32API_INFO("\t\t=> %s\n", filepath.String());
					return true;
				}
			}
			closedir(dir);
		}
	}
	return false;
}

DWORD
GetModuleFileNameU
(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
	DWORD rc = 0;
	if (NULL == hModule) {
		Process *process = Process::GetCurrentProcessObject();
		hModule = (HMODULE)process->GetInstance();
	}
	Image *image = HandleToImage(hModule);
	if (NULL != image) {
		Path path(image->GetFileName());
		path.ToWin32Path();
		if (((DWORD)path.GetPathLength() >= nSize) || (NULL == lpFilename)) {
			rc = path.GetPathLength();
			WIN32API_ERROR(ERROR_MORE_DATA);
		} else {
			rc = snprintf(lpFilename, nSize, "%s", path.GetPath());
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	return rc;
}

HMODULE
GetModuleHandleU
(LPCSTR lpModuleName)
{
	HMODULE rc = NULL;
	WIN32API_INFO("\tlpModuleName: %s\n", lpModuleName);
	BString name;
	if (NULL != lpModuleName) name.SetTo(lpModuleName);
	if ((name.Length() > 4) &&
		(0 != strcasecmp(&(name.String()[name.Length() - 4]), ".dll"))) name << ".dll";
#if defined(_BUILTIN_DLL)
	if (NULL != lpModuleName) {
		if (0 == strcasecmp("KERNEL32.dll", name.String())) return (HINSTANCE)kernel32.GetInstance();
		if (0 == strcasecmp("ADVAPI32.dll", name.String())) return (HINSTANCE)advapi32.GetInstance();
		if (0 == strcasecmp("USER32.dll", name.String())) return (HINSTANCE)user32.GetInstance();
		if (0 == strcasecmp("GDI32.dll", name.String())) return (HINSTANCE)gdi32.GetInstance();
		if (0 == strcasecmp("WINMM.dll", name.String())) return (HINSTANCE)winmm.GetInstance();
		if (0 == strcasecmp("SHELL32.dll", name.String())) return (HINSTANCE)shell32.GetInstance();
		if (0 == strcasecmp("IMM32.dll", name.String())) return (HINSTANCE)imm32.GetInstance();
		if (0 == strcasecmp("COMCTL32.dll", name.String())) return (HINSTANCE)comctl32.GetInstance();
		if (0 == strcasecmp("WSOCK32.dll", name.String())) return (HINSTANCE)wsock32.GetInstance();
		if (0 == strcasecmp("OLE32.dll", name.String())) return (HINSTANCE)ole32.GetInstance();
		if (0 == strcasecmp("COMDLG32.dll", name.String())) return (HINSTANCE)comdlg32.GetInstance();
		if (0 == strcasecmp("VERSION.dll", name.String())) return (HINSTANCE)version.GetInstance();
		if (0 == strcasecmp("DDRAW.dll", name.String())) return (HINSTANCE)ddraw.GetInstance();
		if (0 == strcasecmp("DSOUND.dll", name.String())) return (HINSTANCE)dsound.GetInstance();
	}
#endif	// defined(_BUILTIN_DLL)
	Process *process = Process::GetCurrentProcessObject();
	if (NULL != lpModuleName) rc = process->FindModuleByName(name.String());
	else rc = process->GetInstance();
	if (NULL == rc) WIN32API_ERROR(ERROR_MOD_NOT_FOUND);
	return rc;
}

HMODULE
LoadLibraryU
(LPCSTR lpFileName)
{
	HMODULE rc = LoadLibraryExU(lpFileName, NULL, 0);
	return rc;
}

HMODULE
LoadLibraryExU
(LPCSTR lpFileName, HANDLE hFile, DWORD dwFlags)
{
	HMODULE rc = NULL;
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	if (NULL != hFile) WIN32API_INFO("\tunknown hFile: $%08x\n", hFile);
	if (0 != dwFlags) WIN32API_INFO("\tignore dwFlags: $%08x\n", dwFlags);
	BString filename(lpFileName);
	int len = filename.Length();
	if ((0 != strcasecmp(&lpFileName[len - 4], ".exe")) &&
		(0 != strcasecmp(&lpFileName[len - 4], ".dll"))) {
		filename << ".dll";
	}
	BString path;
	if (FindModule(path, lpFileName)) {
		rc = GetModuleHandleU(path.String());
		if (NULL != rc) {
			Image *image = HandleToImage(rc);
			if (NULL != image) image->AddRef();
		} else {
			Coff *coff = new Coff(path.String());
			Process *process = Process::GetCurrentProcessObject();
			try {
				if (NULL == coff) throw COFF_ERR_NO_MEMORY;
				CoffError err;
				err = coff->Load();
				if (COFF_ERR_OK != err) throw err;
				if (!process->AddModule((HMODULE)coff->GetInstance())) throw COFF_ERR_NO_MEMORY;
				rc = (HMODULE)coff->GetInstance();
				err = coff->Import();
				if (COFF_ERR_OK != err) throw err;
				if (!coff->ProcessAttach()) throw COFF_ERR_UNKNOWN;
				coff->AddRef();
				WIN32API_ERROR(ERROR_SUCCESS);
			} catch (CoffError e) {
				if (NULL != rc) process->DelModule(rc);
				if (NULL != coff) delete coff;
				rc = NULL;
				// XXX: SetLastError
			}
		}
	} else {
		WIN32API_ERROR(ERROR_MOD_NOT_FOUND);
	}
	return rc;
}

extern "C" DWORD WINAPI
GetModuleFileNameA
(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
	DWORD rc = 0;
	WIN32API_POINTER(hModule);
	WIN32API_POINTER(lpFilename);
	WIN32API_ENTER("DWORD", "GetModuleFileNameA", "HMODULE", hModule, "LPSTR", lpFilename, "DWORD", nSize, NULL);
	DWORD size = GetModuleFileNameU(hModule, NULL, 0);
	char *buf = new char[size + 1];
	if (NULL == buf) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		size = GetModuleFileNameU(hModule, buf, size + 1);
		if (0 != size) {
			DOUT("lpFilename = %s\n", buf);
			Win32String str;
			str.SetToU(buf);
			if (str.LengthA() >= nSize) {
				WIN32API_ERROR(ERROR_INSUFFICIENT_BUFFER);
			} else {
				rc = str.LengthA();
				DOUT("rc = %d\n", str.LengthA());
				strcpy(lpFilename, str.StringA());
			}
		}
		delete buf;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetModuleFileNameW
(HMODULE hModule, LPWSTR lpFilename, DWORD nSize)
{
	DWORD rc = 0;
	WIN32API_POINTER(hModule);
	WIN32API_POINTER(lpFilename);
	WIN32API_ENTER("DWORD", "GetModuleFileNameW", "HMODULE", hModule, "LPWSTR", lpFilename, "DWORD", nSize, NULL);
	DWORD size = GetModuleFileNameU(hModule, NULL, 0);
	char *buf = new char[size + 1];
	if (NULL == buf) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		size = GetModuleFileNameU(hModule, buf, size + 1);
		if (0 != size) {
			Win32String str;
			str.SetToU(buf);
			if (str.LengthW() >= nSize) {
				WIN32API_ERROR(ERROR_INSUFFICIENT_BUFFER);
			} else {
				rc = str.LengthW();
				DOUT("rc = %d\n", str.LengthW());
				Win32String::strcpyW(lpFilename, str.StringW());
			}
		}
		delete buf;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
GetModuleHandleA
(LPCSTR lpModuleName)
{
	HMODULE rc = NULL;
	WIN32API_POINTER(lpModuleName);
	WIN32API_ENTER("HMODULE", "GetModuleHandleA", "LPCSTR", lpModuleName, NULL);
	Win32String str;
	str.SetToA(lpModuleName);
	rc = GetModuleHandleU(str.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
GetModuleHandleW
(LPCWSTR lpModuleName)
{
	HMODULE rc = NULL;
	WIN32API_POINTER(lpModuleName);
	WIN32API_ENTER("HMODULE", "GetModuleHandleW", "LPCWSTR", lpModuleName, NULL);
	Win32String str;
	str.SetToW(lpModuleName);
	rc = GetModuleHandleU(str.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" HMODULE WINAPI
LoadLibraryA
(LPCSTR lpFileName)
{
	HMODULE rc = NULL;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("HMODULE", "LoadLibraryA", "LPCSTR", lpFileName, NULL);
	Win32String filename;
	filename.SetToA(lpFileName);
	rc = LoadLibraryU(filename.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
LoadLibraryW
(LPCWSTR lpFileName)
{
	HINSTANCE rc = NULL;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("HMODULE", "LoadLibraryW", "LPCWSTR", lpFileName, NULL);
	Win32String filename;
	filename.SetToW(lpFileName);
	rc = LoadLibraryU(filename.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
LoadLibraryExA
(LPCSTR lpFileName, HANDLE hFile, DWORD dwFlags)
{
	HINSTANCE rc = NULL;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("HMODULE", "LoadLibraryExA", "LPCSTR", lpFileName, "HANDLE", hFile, "DWORD", dwFlags, NULL);
	Win32String filename;
	filename.SetToA(lpFileName);
	rc = LoadLibraryExU(filename.StringU(), hFile, dwFlags);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMODULE WINAPI
LoadLibraryExW
(LPCWSTR lpFileName, HANDLE hFile, DWORD dwFlags)
{
	HINSTANCE rc = NULL;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("HMODULE", "LoadLibraryExW", "LPCWSTR", lpFileName, "HANDLE", hFile, "DWORD", dwFlags, NULL);
	Win32String filename;
	filename.SetToW(lpFileName);
	rc = LoadLibraryExU(filename.StringU(), hFile, dwFlags);
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" BOOL WINAPI
FreeLibrary
(HMODULE hModule)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(hModule);
	WIN32API_ENTER("BOOL", "FreeLibrary", "HMODULE", hModule, NULL);
	Image *image = HandleToImage(hModule);
	if (NULL == image) {
		WIN32API_INFO("\tinvalid handle\n");
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		if (0 == image->ReleaseRef()) {
			Process::GetCurrentProcessObject()->DelModule(image);
			delete image;
		}
		rc = TRUE;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" FARPROC WINAPI
GetProcAddress
(HMODULE hModule, LPCSTR lpProcName)
{
	FARPROC rc = NULL;
	WIN32API_POINTER(hModule);
	WIN32API_POINTER(lpProcName);
	WIN32API_ENTER("FARPROC", "GetProcAddress", "HMODULE", hModule, "LPCSTR", lpProcName, NULL);
	WIN32API_INFO("\tlpProcName: %s\n", lpProcName);
	Image *image = HandleToImage(hModule);
	if (NULL == image) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		if (0 != (0xffff0000 & (DWORD)lpProcName)) WIN32API_INFO("\tProcName: %s\n", lpProcName);
		if (0 != (0xffff0000 & (DWORD)lpProcName)) {
			rc = (FARPROC)image->GetAddressByName(lpProcName);
		} else {
			rc = (FARPROC)image->GetAddressByOrder((int)lpProcName);
		}
		if (NULL == rc) {
			WIN32API_ERROR(ERROR_PROC_NOT_FOUND);
		} else {
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}
