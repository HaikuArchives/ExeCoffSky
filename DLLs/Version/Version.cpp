/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Version.cpp,v 1.1 2003/05/01 03:35:15 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Version.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Version.h"
#include "Kernel32.h"	// VerLanguageName
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" BOOL APIENTRY
GetFileVersionInfoA
(LPSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileVersionInfoA", "LPSTR", lptstrFilename, "DWORD", dwHandle, "DWORD", dwLen, "LPVOID", lpData, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetFileVersionInfoSizeA
(LPSTR lptstrFilename, LPDWORD lpdwHandle)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileVersionInfoSizeA", "LPSTR", lptstrFilename, "LPDWORD", lpdwHandle, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetFileVersionInfoSizeW
(LPWSTR lptstrFilename, LPDWORD lpdwHandle)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileVersionInfoSizeW", "LPWSTR", lptstrFilename, "LPDWORD", lpdwHandle, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetFileVersionInfoW
(LPWSTR lptstrFilename, DWORD dwHandle, DWORD dwLen, LPVOID lpData)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileVersionInfoW", "LPWSTR", lptstrFilename, "DWORD", dwHandle, "DWORD", dwLen, "LPVOID", lpData, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
VerFindFileA
(DWORD uFlags, LPSTR szFileName, LPSTR szWinDir, LPSTR szAppDir, LPSTR szCurDir, PUINT lpuCurDirLen, LPSTR szDestDir, PUINT lpuDestDirLen)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "VerFindFileA", "DWORD", uFlags, "LPSTR", szFileName, "LPSTR", szWinDir, "LPSTR", szAppDir, "LPSTR", szCurDir, "PUINT", lpuCurDirLen, "LPSTR", szDestDir, "PUINT", lpuDestDirLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
VerFindFileW
(DWORD uFlags, LPWSTR szFileName, LPWSTR szWinDir, LPWSTR szAppDir, LPWSTR szCurDir, PUINT lpuCurDirLen, LPWSTR szDestDir, PUINT lpuDestDirLen)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "VerFindFileW", "DWORD", uFlags, "LPWSTR", szFileName, "LPWSTR", szWinDir, "LPWSTR", szAppDir, "LPWSTR", szCurDir, "PUINT", lpuCurDirLen, "LPWSTR", szDestDir, "PUINT", lpuDestDirLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
VerInstallFileA
(DWORD uFlags, LPSTR szSrcFileName, LPSTR szDestFileName, LPSTR szSrcDir, LPSTR szDestDir, LPSTR szCurDir, LPSTR szTmpFile, PUINT lpuTmpFileLen)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "VerInstallFileA", "DWORD", uFlags, "LPSTR", szSrcFileName, "LPSTR", szDestFileName, "LPSTR", szSrcDir, "LPSTR", szDestDir, "LPSTR", szCurDir, "LPSTR", szTmpFile, "PUINT", lpuTmpFileLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
VerInstallFileW
(DWORD uFlags, LPWSTR szSrcFileName, LPWSTR szDestFileName, LPWSTR szSrcDir, LPWSTR szDestDir, LPWSTR szCurDir, LPWSTR szTmpFile, PUINT lpuTmpFileLen)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "VerInstallFileW", "DWORD", uFlags, "LPWSTR", szSrcFileName, "LPWSTR", szDestFileName, "LPWSTR", szSrcDir, "LPWSTR", szDestDir, "LPWSTR", szCurDir, "LPWSTR", szTmpFile, "PUINT", lpuTmpFileLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
VerQueryValueA
(const LPVOID pBlock, LPSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VerQueryValueA", "const LPVOID pBlock", 0, "LPSTR", lpSubBlock, "LPVOID *", lplpBuffer, "PUINT", puLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
VerQueryValueW
(const LPVOID pBlock, LPWSTR lpSubBlock, LPVOID * lplpBuffer, PUINT puLen)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "VerQueryValueW", "const LPVOID pBlock", 0, "LPWSTR", lpSubBlock, "LPVOID *", lplpBuffer, "PUINT", puLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
_VerLanguageNameA
(DWORD wLang, LPSTR szLang, DWORD nSize)
{
	WIN32API_POINTER(szLang);
	WIN32API_ENTER("DWORD", "VerLanguageNameA", "DWORD", wLang, "LPSTR", szLang, "DWORD", nSize, NULL);
	WIN32API_INTERNAL_START();
	DWORD rc = VerLanguageNameA(wLang, szLang, nSize);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
_VerLanguageNameW
(DWORD wLang, LPWSTR szLang, DWORD nSize)
{
	WIN32API_POINTER(szLang);
	WIN32API_ENTER("DWORD", "VerLanguageNameW", "DWORD", wLang, "LPWSTR", szLang, "DWORD", nSize, NULL);
	WIN32API_INTERNAL_START();
	DWORD rc = VerLanguageNameW(wLang, szLang, nSize);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	Version_GetAddressByOrder
#	define	GetAddressByName	Version_GetAddressByName

#	include "Version/GetAddressByOrder.h"
#	include "Version/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
