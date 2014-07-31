/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: FindFile.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [FindFile.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "FindFile.h"
#include "Win32Trace.h"

extern "C" HANDLE WINAPI
FindFirstFileA
(LPCSTR arg0, LPWIN32_FIND_DATAA arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_POINTER(arg0);
	WIN32API_ENTER("HANDLE", "FindFirstFileA", "LPCSTR", arg0, "LPWIN32_FIND_DATAA", arg1, NULL);
	WIN32API_INFO("lpFileName: %s\n", arg0);
	WIN32API_INFO("\tnot impl.\n");
/*
	WIN32API_INFO("\tdummy for MA\n");
	arg1->dwFileAttributes = 0x20;
	arg1->nFileSizeLow = 100;
	arg1->nFileSizeHigh = 0;
	snprintf(arg1->cFileName, WIN32_MAX_PATH, "B:\\MA.exe");
	snprintf(arg1->cAlternateFileName, 14, "B:\\MA.exe");
	rc = (HANDLE)1;
*/
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
FindFirstFileW
(LPCWSTR arg0, LPWIN32_FIND_DATAW arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "FindFirstFileW", "LPCWSTR", arg0, "LPWIN32_FIND_DATAW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
FindFirstFileExA
(LPCSTR arg0, FINDEX_INFO_LEVELS arg1, PVOID arg2, FINDEX_SEARCH_OPS arg3, PVOID arg4, DWORD arg5)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "FindFirstFileExA", "LPCSTR", arg0, "FINDEX_INFO_LEVELS", arg1, "PVOID", arg2, "FINDEX_SEARCH_OPS", arg3, "PVOID", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
FindFirstFileExW
(LPCWSTR arg0, FINDEX_INFO_LEVELS arg1, PVOID arg2, FINDEX_SEARCH_OPS arg3, PVOID arg4, DWORD arg5)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "FindFirstFileExW", "LPCWSTR", arg0, "FINDEX_INFO_LEVELS", arg1, "PVOID", arg2, "FINDEX_SEARCH_OPS", arg3, "PVOID", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FindNextFileA
(HANDLE arg0, LPWIN32_FIND_DATAA arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FindNextFileA", "HANDLE", arg0, "LPWIN32_FIND_DATAA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FindNextFileW
(HANDLE arg0, LPWIN32_FIND_DATAW arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FindNextFileW", "HANDLE", arg0, "LPWIN32_FIND_DATAW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FindClose
(HANDLE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FindClose", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
