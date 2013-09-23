/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Imm32.cpp,v 1.1 2003/05/01 03:30:54 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Imm32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Imm32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" HIMC WINAPI
ImmAssociateContext
(HWND arg0,  HIMC arg1)
{
	HIMC rc = (HIMC)0;
	WIN32API_ENTER("HIMC", "ImmAssociateContext", "HWND", arg0, " HIMC", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmAssociateContextEx
(HWND arg0,  HIMC arg1,  DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmAssociateContextEx", "HWND", arg0, " HIMC", arg1, " DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmConfigureIMEA
(HKL arg0,  HWND arg1,  DWORD arg2,  LPVOID arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmConfigureIMEA", "HKL", arg0, " HWND", arg1, " DWORD", arg2, " LPVOID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmConfigureIMEW
(HKL arg0,  HWND arg1,  DWORD arg2,  LPVOID arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmConfigureIMEW", "HKL", arg0, " HWND", arg1, " DWORD", arg2, " LPVOID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HIMC WINAPI
ImmCreateContext
(void)
{
	HIMC rc = (HIMC)0;
	WIN32API_ENTER("HIMC", "ImmCreateContext", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmDestroyContext
(HIMC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmDestroyContext", "HIMC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmDisableIME
(DWORD arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmDisableIME", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmEnumRegisterWordA
(HKL arg0, REGISTERWORDENUMPROCA arg1, LPCSTR lpszReading, DWORD arg3, LPCSTR lpszRegister, LPVOID arg5)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmEnumRegisterWordA", "HKL", arg0, "REGISTERWORDENUMPROCA", arg1, "LPCSTR", lpszReading, "DWORD", arg3, "LPCSTR", lpszRegister, "LPVOID", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmEnumRegisterWordW
(HKL arg0, REGISTERWORDENUMPROCW arg1, LPCWSTR lpszReading, DWORD arg3, LPCWSTR lpszRegister, LPVOID arg5)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmEnumRegisterWordW", "HKL", arg0, "REGISTERWORDENUMPROCW", arg1, "LPCWSTR", lpszReading, "DWORD", arg3, "LPCWSTR", lpszRegister, "LPVOID", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
ImmEscapeA
(HKL arg0,  HIMC arg1,  UINT arg2,  LPVOID arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "ImmEscapeA", "HKL", arg0, " HIMC", arg1, " UINT", arg2, " LPVOID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
ImmEscapeW
(HKL arg0,  HIMC arg1,  UINT arg2,  LPVOID arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "ImmEscapeW", "HKL", arg0, " HIMC", arg1, " UINT", arg2, " LPVOID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetCandidateListA
(HIMC arg0, DWORD deIndex, LPCANDIDATELIST arg2, DWORD dwBufLen)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetCandidateListA", "HIMC", arg0, "DWORD", "LPCANDIDATELIST", arg2, "DWORD", dwBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetCandidateListCountA
(HIMC arg0, LPDWORD lpdwListCount)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetCandidateListCountA", "HIMC", arg0, "LPDWORD", lpdwListCount, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetCandidateListCountW
(HIMC arg0, LPDWORD lpdwListCount)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetCandidateListCountW", "HIMC", arg0, "LPDWORD", lpdwListCount, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetCandidateListW
(HIMC arg0, DWORD deIndex, LPCANDIDATELIST arg2, DWORD dwBufLen)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetCandidateListW", "HIMC", arg0, "DWORD", deIndex, "LPCANDIDATELIST", arg2, "DWORD", dwBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetCandidateWindow
(HIMC arg0,  DWORD arg1,  LPCANDIDATEFORM arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetCandidateWindow", "HIMC", arg0, " DWORD", arg1, " LPCANDIDATEFORM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetCompositionFontA
(HIMC arg0,  LPLOGFONTA arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetCompositionFontA", "HIMC", arg0, " LPLOGFONTA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetCompositionFontW
(HIMC arg0,  LPLOGFONTW arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetCompositionFontW", "HIMC", arg0, " LPLOGFONTW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
ImmGetCompositionStringA
(HIMC arg0,  DWORD arg1,  LPVOID arg2,  DWORD arg3)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "ImmGetCompositionStringA", "HIMC", arg0, " DWORD", arg1, " LPVOID", arg2, " DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
ImmGetCompositionStringW
(HIMC arg0,  DWORD arg1,  LPVOID arg2,  DWORD arg3)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "ImmGetCompositionStringW", "HIMC", arg0, " DWORD", arg1, " LPVOID", arg2, " DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetCompositionWindow
(HIMC arg0,  LPCOMPOSITIONFORM arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetCompositionWindow", "HIMC", arg0, " LPCOMPOSITIONFORM", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HIMC WINAPI
ImmGetContext
(HWND arg0)
{
	HIMC rc = (HIMC)0;
	WIN32API_ENTER("HIMC", "ImmGetContext", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetConversionListA
(HKL arg0, HIMC arg1, LPCSTR arg2, LPCANDIDATELIST arg3, DWORD dwBufLen, UINT uFlag)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetConversionListA", "HKL", arg0, "HIMC", arg1, "LPCSTR", arg2, "LPCANDIDATELIST", arg3, "DWORD", dwBufLen, "UINT", uFlag, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetConversionListW
(HKL arg0, HIMC arg1, LPCWSTR arg2, LPCANDIDATELIST arg3, DWORD dwBufLen, UINT uFlag)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetConversionListW", "HKL", arg0, "HIMC", arg1, "LPCWSTR", arg2, "LPCANDIDATELIST", arg3, "DWORD", dwBufLen, "UINT", uFlag, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetConversionStatus
(HIMC arg0,  LPDWORD arg1,  LPDWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetConversionStatus", "HIMC", arg0, " LPDWORD", arg1, " LPDWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
ImmGetDefaultIMEWnd
(HWND arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "ImmGetDefaultIMEWnd", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetDescriptionA
(HKL arg0, LPSTR arg1, UINT uBufLen)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetDescriptionA", "HKL", arg0, "LPSTR", arg1, "UINT", uBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetDescriptionW
(HKL arg0, LPWSTR arg1, UINT uBufLen)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetDescriptionW", "HKL", arg0, "LPWSTR", arg1, "UINT", uBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetGuideLineA
(HIMC arg0, DWORD dwIndex, LPSTR arg2, DWORD dwBufLen)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetGuideLineA", "HIMC", arg0, "DWORD", dwIndex, "LPSTR", arg2, "DWORD", dwBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetGuideLineW
(HIMC arg0, DWORD dwIndex, LPWSTR arg2, DWORD dwBufLen)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetGuideLineW", "HIMC", arg0, "DWORD", dwIndex, "LPWSTR", arg2, "DWORD", dwBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetIMEFileNameA
(HKL arg0, LPSTR arg1, UINT uBufLen)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetIMEFileNameA", "HKL", arg0, "LPSTR", arg1, "UINT", uBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetIMEFileNameW
(HKL arg0, LPWSTR arg1, UINT uBufLen)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetIMEFileNameW", "HKL", arg0, "LPWSTR", arg1, "UINT", uBufLen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetImeMenuItemsA
(HIMC arg0,  DWORD arg1,  DWORD arg2,  LPIMEMENUITEMINFOA arg3,  LPIMEMENUITEMINFOA arg4,  DWORD arg5)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetImeMenuItemsA", "HIMC", arg0, " DWORD", arg1, " DWORD", arg2, " LPIMEMENUITEMINFOA", arg3, " LPIMEMENUITEMINFOA", arg4, " DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetImeMenuItemsW
(HIMC arg0,  DWORD arg1,  DWORD arg2,  LPIMEMENUITEMINFOW arg3,  LPIMEMENUITEMINFOW arg4,  DWORD arg5)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetImeMenuItemsW", "HIMC", arg0, " DWORD", arg1, " DWORD", arg2, " LPIMEMENUITEMINFOW", arg3, " LPIMEMENUITEMINFOW", arg4, " DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetOpenStatus
(HIMC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetOpenStatus", "HIMC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ImmGetProperty
(HKL arg0,  DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ImmGetProperty", "HKL", arg0, " DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetRegisterWordStyleA
(HKL arg0, UINT nItem, LPSTYLEBUFA arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetRegisterWordStyleA", "HKL", arg0, "UINT", nItem, "LPSTYLEBUFA", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetRegisterWordStyleW
(HKL arg0, UINT nItem, LPSTYLEBUFW arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetRegisterWordStyleW", "HKL", arg0, "UINT", nItem, "LPSTYLEBUFW", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmGetStatusWindowPos
(HIMC arg0,  LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmGetStatusWindowPos", "HIMC", arg0, " LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ImmGetVirtualKey
(HWND arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ImmGetVirtualKey", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HKL WINAPI
ImmInstallIMEA
(LPCSTR lpszIMEFileName, LPCSTR lpszLayoutText)
{
	HKL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HKL", "ImmInstallIMEA", "LPCSTR", lpszIMEFileName, "LPCSTR", lpszLayoutText, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HKL WINAPI
ImmInstallIMEW
(LPCWSTR lpszIMEFileName, LPCWSTR lpszLayoutText)
{
	HKL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HKL", "ImmInstallIMEW", "LPCWSTR", lpszIMEFileName, "LPCWSTR", lpszLayoutText, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmIsIME
(HKL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmIsIME", "HKL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmIsUIMessageA
(HWND arg0,  UINT arg1,  WPARAM arg2,  LPARAM arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmIsUIMessageA", "HWND", arg0, " UINT", arg1, " WPARAM", arg2, " LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmIsUIMessageW
(HWND arg0,  UINT arg1,  WPARAM arg2,  LPARAM arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmIsUIMessageW", "HWND", arg0, " UINT", arg1, " WPARAM", arg2, " LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmNotifyIME
(HIMC arg0, DWORD dwAction, DWORD dwIndex, DWORD dwValue)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmNotifyIME", "HIMC", arg0, "DWORD", dwAction, "DWORD", dwIndex, "DWORD", dwValue, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmRegisterWordA
(HKL arg0, LPCSTR lpszReading, DWORD arg2, LPCSTR lpszRegister)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmRegisterWordA", "HKL", arg0, "LPCSTR", lpszReading, "DWORD", arg2, "LPCSTR", lpszRegister, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmRegisterWordW
(HKL arg0, LPCWSTR lpszReading, DWORD arg2, LPCWSTR lpszRegister)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmRegisterWordW", "HKL", arg0, "LPCWSTR", lpszReading, "DWORD", arg2, "LPCWSTR", lpszRegister, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmReleaseContext
(HWND arg0,  HIMC arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmReleaseContext", "HWND", arg0, " HIMC", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetCandidateWindow
(HIMC arg0,  LPCANDIDATEFORM arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetCandidateWindow", "HIMC", arg0, " LPCANDIDATEFORM", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetCompositionFontA
(HIMC arg0,  LPLOGFONTA arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetCompositionFontA", "HIMC", arg0, " LPLOGFONTA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetCompositionFontW
(HIMC arg0,  LPLOGFONTW arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetCompositionFontW", "HIMC", arg0, " LPLOGFONTW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetCompositionStringA
(HIMC arg0, DWORD dwIndex, LPCVOID lpComp, DWORD arg3, LPCVOID lpRead, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetCompositionStringA", "HIMC", arg0, "DWORD", dwIndex, "LPCVOID", lpComp, "DWORD", arg3, "LPCVOID", lpRead, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetCompositionStringW
(HIMC arg0, DWORD dwIndex, LPCVOID lpComp, DWORD arg3, LPCVOID lpRead, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetCompositionStringW", "HIMC", arg0, "DWORD", dwIndex, "LPCVOID", lpComp, "DWORD", arg3, "LPCVOID", lpRead, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetCompositionWindow
(HIMC arg0,  LPCOMPOSITIONFORM arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetCompositionWindow", "HIMC", arg0, " LPCOMPOSITIONFORM", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetConversionStatus
(HIMC arg0,  DWORD arg1,  DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetConversionStatus", "HIMC", arg0, " DWORD", arg1, " DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetOpenStatus
(HIMC arg0,  BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetOpenStatus", "HIMC", arg0, " BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSetStatusWindowPos
(HIMC arg0,  LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSetStatusWindowPos", "HIMC", arg0, " LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmSimulateHotKey
(HWND arg0,  DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmSimulateHotKey", "HWND", arg0, " DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmUnregisterWordA
(HKL arg0, LPCSTR lpszReading, DWORD arg2, LPCSTR lpszUnregister)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmUnregisterWordA", "HKL", arg0, "LPCSTR", lpszReading, "DWORD", arg2, "LPCSTR", lpszUnregister, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImmUnregisterWordW
(HKL arg0, LPCWSTR lpszReading, DWORD arg2, LPCWSTR lpszUnregister)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImmUnregisterWordW", "HKL", arg0, "LPCWSTR", lpszReading, "DWORD", arg2, "LPCWSTR", lpszUnregister, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	Imm32_GetAddressByOrder
#	define	GetAddressByName	Imm32_GetAddressByName

#	include "Imm32/GetAddressByOrder.h"
#	include "Imm32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
