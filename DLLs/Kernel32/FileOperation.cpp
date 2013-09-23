/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: FileOperation.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [FileOperation.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "FileOperation.h"
#include "Path.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" BOOL WINAPI
CopyFileA
(LPCSTR arg0, LPCSTR arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CopyFileA", "LPCSTR", arg0, "LPCSTR", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CopyFileW
(LPCWSTR arg0, LPCWSTR arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CopyFileW", "LPCWSTR", arg0, "LPCWSTR", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CopyFileExA
(LPCSTR arg0, LPCSTR arg1, LPPROGRESS_ROUTINE arg2, LPVOID arg3, LPBOOL arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CopyFileExA", "LPCSTR", arg0, "LPCSTR", arg1, "LPPROGRESS_ROUTINE", arg2, "LPVOID", arg3, "LPBOOL", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CopyFileExW
(LPCWSTR arg0, LPCWSTR arg1, LPPROGRESS_ROUTINE arg2, LPVOID arg3, LPBOOL arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CopyFileExW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPPROGRESS_ROUTINE", arg2, "LPVOID", arg3, "LPBOOL", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteFileA
(LPCSTR lpFileName)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("BOOL", "DeleteFileA", "LPCSTR", lpFileName, NULL);
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteFileW
(LPCWSTR lpFileName)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteFileW", "LPCWSTR", lpFileName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFileAttributesA
(LPCSTR lpFileName)
{
	DWORD rc = (DWORD)-1;
	WIN32API_POINTER(lpFileName);
	WIN32API_ENTER("DWORD", "GetFileAttributesA", "LPCSTR", lpFileName, NULL);
	WIN32API_INFO("\tlpFileName: %s\n", lpFileName);
	Path path(lpFileName);
	path.ToNativePath(true);
	struct stat st;
	if (0 == stat(path.GetPath(), &st)) {
		rc = 0;
		WIN32API_INFO("\tnot impl (dummy).\n");
	} else {
		WIN32API_INTERNAL_START();
		SetLastError(ERROR_FILE_NOT_FOUND);
		WIN32API_INTERNAL_END();
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFileAttributesW
(LPCWSTR arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetFileAttributesW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetFileAttributesExA
(LPCSTR arg0, GET_FILEEX_INFO_LEVELS arg1, PVOID arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileAttributesExA", "LPCSTR", arg0, "GET_FILEEX_INFO_LEVELS", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetFileAttributesExW
(LPCWSTR arg0, GET_FILEEX_INFO_LEVELS arg1, PVOID arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetFileAttributesExW", "LPCSTR", arg0, "GET_FILEEX_INFO_LEVELS", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetFileAttributesA
(LPCSTR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetFileAttributesA", "LPCSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetFileAttributesW
(LPCWSTR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetFileAttributesW", "LPCWSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MoveFileA
(LPCSTR arg0, LPCSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MoveFileA", "LPCSTR", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MoveFileW
(LPCWSTR arg0, LPCWSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MoveFileW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MoveFileExA
(LPCSTR arg0, LPCSTR arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MoveFileExA", "LPCSTR", arg0, "LPCSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MoveFileExW
(LPCWSTR arg0, LPCWSTR arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MoveFileExW", "LPCWSTR", arg0, "LPCWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
