/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: String.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [String.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "String.h"
#include "Kernel32.h"
#include "Win32Trace.h"

extern "C" LPSTR WINAPI
lstrcatA
(LPSTR lpString1, LPCSTR lpString2)
{
	LPSTR rc = NULL;
	WIN32API_POINTER(lpString1);
	WIN32API_POINTER(lpString2);
	WIN32API_ENTER("LPSTR", "lstrcatA", "LPSTR", lpString1, "LPCSTR", lpString2, NULL);
	WIN32API_INFO("\t%s + %s\n", lpString1, lpString2);
	rc = strcat(lpString1, lpString2);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
lstrcatW
(LPWSTR arg0, LPCWSTR arg1)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "lstrcatW", "LPWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
lstrcmpA
(LPCSTR lpString1, LPCSTR lpString2)
{
	int rc = 0;
	WIN32API_POINTER(lpString1);
	WIN32API_POINTER(lpString2);
	WIN32API_ENTER("int", "lstrcmpA", "LPCSTR", lpString1, "LPCSTR", lpString2, NULL);
	WIN32API_INFO("\t%s, %s\n", lpString1, lpString2);
	rc = strcmp(lpString1, lpString2);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
lstrcmpW
(LPCWSTR arg0, LPCWSTR arg1)
{
	int rc = -1;
	WIN32API_ENTER("int", "lstrcmpW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
lstrcmpiA
(LPCSTR lpString1, LPCSTR lpString2)
{
	int rc = 0;
	WIN32API_POINTER(lpString1);
	WIN32API_POINTER(lpString2);
	WIN32API_ENTER("int", "lstrcmpiA", "LPCSTR", lpString1, "LPCSTR", lpString2, NULL);
	WIN32API_INFO("lpString1: %s\n", lpString1);
	WIN32API_INFO("lpString2: %s\n", lpString2);
	rc = strcasecmp(lpString1, lpString2);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
lstrcmpiW
( LPCWSTR arg0, LPCWSTR arg1)
{
	int rc = -1;
	WIN32API_ENTER("int", "lstrcmpiW", " LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPTSTR WINAPI
lstrcpyA
(LPTSTR lpString1, LPCTSTR lpString2)
{
	LPTSTR rc = NULL;
	WIN32API_POINTER(lpString1);
	WIN32API_POINTER(lpString2);
	WIN32API_ENTER("LPTSTR", "lstrcpyA", "LPTSTR", lpString1, "LPCTSTR", lpString2, NULL);
	WIN32API_INFO("lpString: %s\n", lpString2);
	rc = strcpy(lpString1, lpString2);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
lstrcpyW
(LPWSTR arg0, LPCWSTR arg1)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "lstrcpyW", "LPWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
lstrcpynA
(LPSTR lpString1, LPCSTR lpString2, int nLength)
{
	LPSTR rc = NULL;
	WIN32API_POINTER(lpString1);
	WIN32API_POINTER(lpString2);
	WIN32API_ENTER("LPSTR", "lstrcpynA", "LPSTR", lpString1, "LPCSTR", lpString2, "int", nLength, NULL);
#if defined(_DEBUG)
	char *tmp = new char[nLength + 1];
	if (NULL != tmp) {
		strncpy(tmp, lpString2, nLength);
		tmp[nLength] = 0;
		WIN32API_INFO("lpString: %s\n", tmp);
		WIN32API_INFO("nLength: %d\n", nLength);
		delete tmp;
	}
#endif	// defined(_DEBUG)
	rc = strncpy(lpString1, lpString2, nLength);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
lstrcpynW
(LPWSTR arg0, LPCWSTR arg1, int arg2)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "lstrcpynW", "LPWSTR", arg0, "LPCWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
lstrlenA
(LPCSTR lpString)
{
	int rc = -1;
	WIN32API_POINTER(lpString);
	WIN32API_ENTER("int", "lstrlenA", "LPCSTR", lpString, NULL);
	WIN32API_INFO("lpString: %s\n", lpString);
	rc = strlen(lpString);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
lstrlenW
(LPCWSTR arg0)
{
	int rc = -1;
	WIN32API_ENTER("int", "lstrlenW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
