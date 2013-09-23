/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Module.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Module.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Module_h__)
#	define	__Module_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Coff_h__)
#		include "Coff.h"
#	endif	// !defined(__Coff_h__)

#	if defined(_BUILTIN_DLL)

typedef void *(*Func_GetAddressByOrder)(int);
typedef void *(*Func_GetAddressByName)(const char *);

#		define	BUILTIN_DLL_MAGIC	'_BiD'

class BuiltInModule: public Image {
private:
	DWORD magic;
	char name[PATH_MAX];
	Func_GetAddressByOrder ByOrder;
	Func_GetAddressByName ByName;
public:
	BuiltInModule(const char *name, Func_GetAddressByOrder ByOrder, Func_GetAddressByName ByName);
	~BuiltInModule(void);
	const char *GetFileName(void) const;
	void *GetAddressByOrder(int order) const;
	void *GetAddressByName(const char *name) const;
	void *GetEntryPoint(void) const;
	HINSTANCE GetInstance(void) const;
	DWORD GetVersion(void) const;
	
	void *GetResourceAddress(void) const;
	LpResourceDataEntry FindResource(int type, int id) const;
	
	bool ProcessAttach(void);
	bool ThreadAttach(void);
	bool ThreadDetach(void);
	bool ProcessDetach(void);

	static BuiltInModule *InstanceToModule(HINSTANCE hInstance);
};

#		if !defined(__BuiltInModule__)
#			define	__BuiltInModule__
#		endif	// !defined(__BuiltInModule__)

#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

Image *HandleToImage(HMODULE hModule);
static bool FindModule(BString &filepath, LPCSTR lpFileName);

static DWORD GetModuleFileNameU(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
static HMODULE GetModuleHandleU(LPCSTR lpModuleName);
static HMODULE LoadLibraryU(LPCSTR lpFileName);
static HMODULE LoadLibraryExU(LPCSTR lpFileName, HANDLE hFile, DWORD dwFlags);

DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
DWORD WINAPI GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);
HMODULE WINAPI LoadLibraryA(LPCSTR lpFileName);
HMODULE WINAPI LoadLibraryW(LPCWSTR lpFileName);
HMODULE WINAPI LoadLibraryExA(LPCSTR lpFileName, HANDLE hFile, DWORD dwFlags);
HMODULE WINAPI LoadLibraryExW(LPCWSTR lpFileName, HANDLE hFile, DWORD dwFlags);
BOOL WINAPI FreeLibrary(HMODULE hModule);
FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Module_h__)
