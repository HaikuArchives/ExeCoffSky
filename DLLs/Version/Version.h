/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Version.h,v 1.1 2003/05/01 03:35:15 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Version.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Version_h__)
#	define	__Version_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL APIENTRY GetFileVersionInfoA(LPSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
BOOL APIENTRY GetFileVersionInfoSizeA(LPSTR lptstrFilename, LPDWORD lpdwHandle);
BOOL APIENTRY GetFileVersionInfoSizeW(LPWSTR lptstrFilename, LPDWORD lpdwHandle);
BOOL APIENTRY GetFileVersionInfoW(LPWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData);
DWORD APIENTRY VerFindFileA(DWORD uFlags, LPSTR szFileName, LPSTR szWinDir, LPSTR szAppDir, LPSTR szCurDir, PUINT lpuCurDirLen, LPSTR szDestDir, PUINT lpuDestDirLen);
DWORD APIENTRY VerFindFileW(DWORD uFlags, LPWSTR szFileName, LPWSTR szWinDir, LPWSTR szAppDir, LPWSTR szCurDir, PUINT lpuCurDirLen, LPWSTR szDestDir, PUINT lpuDestDirLen);
DWORD APIENTRY VerInstallFileA(DWORD uFlags, LPSTR szSrcFileName, LPSTR szDestFileName, LPSTR szSrcDir, LPSTR szDestDir, LPSTR szCurDir, LPSTR szTmpFile, PUINT lpuTmpFileLen);
DWORD APIENTRY VerInstallFileW(DWORD uFlags, LPWSTR szSrcFileName, LPWSTR szDestFileName, LPWSTR szSrcDir, LPWSTR szDestDir, LPWSTR szCurDir, LPWSTR szTmpFile, PUINT lpuTmpFileLen);
BOOL APIENTRY VerQueryValueA(const LPVOID pBlock, LPSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen);
BOOL APIENTRY VerQueryValueW(const LPVOID pBlock, LPWSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen);

DWORD APIENTRY _VerLanguageNameA(DWORD wLang, LPSTR szLang, DWORD nSize);
DWORD APIENTRY _VerLanguageNameW(DWORD wLang, LPWSTR szLang, DWORD nSize);

#	if defined(_BUILTIN_DLL)
void *Version_GetAddressByOrder(int order);
void *Version_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Version_h__)
