/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Environment.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Environment.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Environment.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

BOOL
SetEnvironmentVariableU
(LPCSTR lpName, LPCSTR lpValue)
{
	BString env(lpName);
	env << "=";
	env << lpValue;
	WIN32API_INFO("\t%s\n", env.String());
	return (0 == putenv(env.String()))? TRUE: FALSE;
}

extern "C" DWORD WINAPI
ExpandEnvironmentStringsA
(LPCSTR arg0, LPSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ExpandEnvironmentStringsA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ExpandEnvironmentStringsW
(LPCWSTR arg0, LPWSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ExpandEnvironmentStringsW", "LPCWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FreeEnvironmentStringsA
(LPTSTR lpszEnvironmentBlock)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "FreeEnvironmentStringsA", "LPTSTR", lpszEnvironmentBlock, NULL);
	WIN32API_INFO("\tnot impl. => dummy\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FreeEnvironmentStringsW
(LPTSTR lpszEnvironmentBlock)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "FreeEnvironmentStringsW", "LPTSTR", lpszEnvironmentBlock, NULL);
	WIN32API_INFO("\tnot impl. => dummy\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
GetEnvironmentStrings
(VOID)
{
	LPVOID rc = (LPVOID)"OS=BeOS\0";
	WIN32API_ENTER("LPVOID", "GetEnvironmentStrings", NULL);
	WIN32API_INFO("\tnot impl. => dummy\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
GetEnvironmentStringsA
(void)
{
	LPVOID rc = (LPVOID)"OS=BeOS\0";
	WIN32API_ENTER("LPVOID", "GetEnvironmentStringsA", "VOID", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
GetEnvironmentStringsW
(VOID)
{
	LPVOID rc = NULL;
	Win32String str("OS=BeOS");
	static short buf[9];
	Win32String::strcpyW(buf, str.StringW());
	buf[8] = 0;
	rc = (LPVOID)buf;
	WIN32API_ENTER("LPVOID", "GetEnvironmentStringsW", NULL);
	WIN32API_INFO("\tnot impl. => dummy\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetEnvironmentVariableA
(LPCSTR arg0, LPSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetEnvironmentVariableA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetEnvironmentVariableW
(LPCWSTR arg0, LPWSTR arg1, DWORD arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetEnvironmentVariableW", "LPCWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetEnvironmentVariableA
(LPCSTR lpName, LPCSTR lpValue)
{
	WIN32API_POINTER(lpName);
	WIN32API_POINTER(lpValue);
	WIN32API_ENTER("BOOL", "SetEnvironmentVariableA", "LPCSTR", lpName, "LPCSTR", lpValue, NULL);
	Win32String name;
	name.SetToA(lpName);
	Win32String value;
	value.SetToA(lpValue);
	BOOL rc = SetEnvironmentVariableU(name.StringU(), value.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetEnvironmentVariableW
(LPCWSTR lpName, LPCWSTR lpValue)
{
	WIN32API_POINTER(lpName);
	WIN32API_POINTER(lpValue);
	WIN32API_ENTER("BOOL", "SetEnvironmentVariableW", "LPCWSTR", lpName, "LPCWSTR", lpValue, NULL);
	Win32String name;
	name.SetToW(lpName);
	Win32String value;
	value.SetToW(lpValue);
	BOOL rc = SetEnvironmentVariableU(name.StringU(), value.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}
