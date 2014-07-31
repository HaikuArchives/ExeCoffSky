/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: IME.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [IME.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "IME.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" LRESULT WINAPI
SendIMEMessageExA
(HWND hwnd, LPARAM lParam)
{
	LRESULT rc = 0;
	WIN32API_ENTER("LRESULT", "SendIMEMessageExA", "HWND", hwnd, "LPARAM", lParam, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendIMEMessageExW
(HWND hwnd, LPARAM lParam)
{
	LRESULT rc = 0;
	WIN32API_ENTER("LRESULT", "SendIMEMessageExW", "HWND", hwnd, "LPARAM", lParam, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WINNLSEnableIME
(HWND hwnd, BOOL flag)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WINNLSEnableIME", "HWND", hwnd, "BOOL", flag, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WINNLSGetEnableStatus
(HWND hwnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WINNLSGetEnableStatus", "HWND", hwnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
WINNLSGetIMEHotkey
(HWND hwnd)
{
	int rc = 0;
	WIN32API_ENTER("unknown", "WINNLSGetIMEHotkey", "HWND", hwnd, NULL);
	WIN32API_LEAVE(0);
	return rc;
}
