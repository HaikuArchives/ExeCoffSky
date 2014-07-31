/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Path.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Path.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Path_h__)
#	define	__Path_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Win32String_h__)
#		include "Win32String.h"
#	endif	// !defined(__Win32String_h__)

class Path {
private:
	BString path;
public:
	Path(void);
	Path(const char *path);
	
	void SetTo(const char *path);

	bool ToWin32Path(int drive = 0 /* A: */);
	bool ToNativePath(bool fixcase = false);
	
	void MatchCharCase(void);
	
	const char *GetPath(void);
	int32 GetPathLength(void);
};

#		if !defined(__Path__)
#			define	__Path__
#		endif	// !defined(__Path__)

static UINT GetWindowsDirectoryU(LPSTR lpBuffer, UINT uSize);
static UINT GetSystemDirectoryU(LPSTR lpBuffer, UINT uSize);
static DWORD GetCurrentDirectoryU(DWORD nBufferLength, LPSTR lpBuffer);
static bool GetFullPathNameU(LPCSTR lpFileName, Win32String &sBufer);
static bool SearchPathU(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, Win32String &sBuffer);
static LPCSTR FindFilePartA(LPCSTR lpPath);
static LPCWSTR FindFilePartW(LPCWSTR lpPath);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

UINT WINAPI GetWindowsDirectoryA(LPSTR lpBuffer, UINT uSize);
UINT WINAPI GetWindowsDirectoryW(LPWSTR lpBuffer, UINT uSize);
UINT WINAPI GetSystemDirectoryA(LPSTR lpBuffer, UINT uSize);
UINT WINAPI GetSystemDirectoryW(LPWSTR lpBuffer, UINT uSize);
DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer);
DWORD WINAPI GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer);
BOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
BOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
BOOL WINAPI CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory, LPCSTR lpNewDirectory, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory, LPCWSTR lpNewDirectory, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
BOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
DWORD WINAPI GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer);
DWORD WINAPI GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer);
DWORD WINAPI GetShortPathNameA(LPCSTR lpszLongPath, LPSTR lpszShortPath, DWORD cchBuffer);
DWORD WINAPI GetShortPathNameW(LPCWSTR lpszLongPath, LPWSTR lpszShortPath, DWORD cchBuffer);
DWORD WINAPI GetFullPathNameA(LPCSTR lpFileName, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
DWORD WINAPI GetFullPathNameW(LPCWSTR lpFileName, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart);
DWORD WINAPI GetLongPathNameA(LPCSTR lpszShortPath, LPSTR lpszLongPath, DWORD cchBuffer);
DWORD WINAPI GetLongPathNameW(LPCWSTR lpszShortPath, LPWSTR lpszLongPath, DWORD cchBuffer);
DWORD WINAPI SearchPathA(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
DWORD WINAPI SearchPathW(LPCWSTR lpPath, LPCWSTR lpFileName, LPCWSTR lpExtension, DWORD nBufferLength, LPWSTR lpBuffer ,LPWSTR *lpFilePart);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Path_h__)
