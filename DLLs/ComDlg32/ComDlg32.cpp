/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ComDlg32.cpp,v 1.1 2003/05/01 02:58:34 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ComDlg32.cpp.h]
 * -------------------------------------------------------------------------------------------- */
#include "ComDlg32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" BOOL APIENTRY
ChooseColorA
(LPCHOOSECOLORA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChooseColorA", "LPCHOOSECOLORA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
ChooseColorW
(LPCHOOSECOLORW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChooseColorW", "LPCHOOSECOLORW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
ChooseFontA
(LPCHOOSEFONTA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChooseFontA", "LPCHOOSEFONTA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
ChooseFontW
(LPCHOOSEFONTW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChooseFontW", "LPCHOOSEFONTW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD APIENTRY
CommDlgExtendedError
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "CommDlgExtendedError", "VOID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND APIENTRY
FindTextA
(LPFINDREPLACEA arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "FindTextA", "LPFINDREPLACEA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND APIENTRY
FindTextW
(LPFINDREPLACEW arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "FindTextW", "LPFINDREPLACEW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" short APIENTRY
GetFileTitleA
(LPCSTR arg0, LPSTR arg1, WORD arg2)
{
	short rc = 0;
	WIN32API_ENTER("short", "GetFileTitleA", "LPCSTR", arg0, "LPSTR", arg1, "WORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" short APIENTRY
GetFileTitleW
(LPCWSTR arg0, LPWSTR arg1, WORD arg2)
{
	short rc = 0;
	WIN32API_ENTER("short", "GetFileTitleW", "LPCWSTR", arg0, "LPWSTR", arg1, "WORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetOpenFileNameA
(LPOPENFILENAMEA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetOpenFileNameA", "LPOPENFILENAMEA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetOpenFileNameW
(LPOPENFILENAMEW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetOpenFileNameW", "LPOPENFILENAMEW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetSaveFileNameA
(LPOPENFILENAMEA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSaveFileNameA", "LPOPENFILENAMEA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
GetSaveFileNameW
(LPOPENFILENAMEW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSaveFileNameW", "LPOPENFILENAMEW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
PageSetupDlgA
(LPPAGESETUPDLGA  arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PageSetupDlgA", "LPPAGESETUPDLGA ", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
PageSetupDlgW
(LPPAGESETUPDLGW  arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PageSetupDlgW", "LPPAGESETUPDLGW ", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
PrintDlgA
(LPPRINTDLGA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PrintDlgA", "LPPRINTDLGA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL APIENTRY
PrintDlgW
(LPPRINTDLGW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PrintDlgW", "LPPRINTDLGW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND APIENTRY
ReplaceTextA
(LPFINDREPLACEA arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "ReplaceTextA", "LPFINDREPLACEA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND APIENTRY
ReplaceTextW
(LPFINDREPLACEW arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "ReplaceTextW", "LPFINDREPLACEW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	ComDlg32_GetAddressByOrder
#	define	GetAddressByName	ComDlg32_GetAddressByName

#	include "ComDlg32/GetAddressByOrder.h"
#	include "ComDlg32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
