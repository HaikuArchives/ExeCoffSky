/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Locale.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Locale.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Locale.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" int WINAPI
CompareStringA
(LCID arg0, DWORD arg1, LPCSTR arg2, int arg3, LPCSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "CompareStringA", "LCID", arg0, "DWORD", arg1, "LPCSTR", arg2, "int", arg3, "LPCSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
CompareStringW
(LCID arg0, DWORD arg1, LPCWSTR arg2, int arg3, LPCWSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "CompareStringW", "LCID", arg0, "DWORD", arg1, "LPCWSTR", arg2, "int", arg3, "LPCWSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LCID WINAPI
ConvertDefaultLocale
(LCID arg0)
{
	LCID rc = (LCID)-1;
	WIN32API_ENTER("LCID", "ConvertDefaultLocale", "LCID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumCalendarInfoA
(CALINFO_ENUMPROCA arg0, LCID arg1, CALID arg2, CALTYPE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumCalendarInfoA", "CALINFO_ENUMPROCA", arg0, "LCID", arg1, "CALID", arg2, "CALTYPE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumCalendarInfoW
(CALINFO_ENUMPROCW arg0, LCID arg1, CALID arg2, CALTYPE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumCalendarInfoW", "CALINFO_ENUMPROCW", arg0, "LCID", arg1, "CALID", arg2, "CALTYPE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumCalendarInfoExA
(CALINFO_ENUMPROCEXA arg0, LCID arg1, CALID arg2, CALTYPE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumCalendarInfoExA", "CALINFO_ENUMPROCEXA", arg0, "LCID", arg1, "CALID", arg2, "CALTYPE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumCalendarInfoExW
(CALINFO_ENUMPROCEXW arg0, LCID arg1, CALID arg2, CALTYPE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumCalendarInfoExW", "CALINFO_ENUMPROCEXW", arg0, "LCID", arg1, "CALID", arg2, "CALTYPE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDateFormatsA
(DATEFMT_ENUMPROCA arg0, LCID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDateFormatsA", "DATEFMT_ENUMPROCA", arg0, "LCID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDateFormatsW
(DATEFMT_ENUMPROCW arg0, LCID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDateFormatsW", "DATEFMT_ENUMPROCW", arg0, "LCID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDateFormatsExA
(DATEFMT_ENUMPROCEXA arg0, LCID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDateFormatsExA", "DATEFMT_ENUMPROCEXA", arg0, "LCID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDateFormatsExW
(DATEFMT_ENUMPROCEXW arg0, LCID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDateFormatsExW", "DATEFMT_ENUMPROCEXW", arg0, "LCID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumSystemLocalesA
(LOCALE_ENUMPROCA arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumSystemLocalesA", "LOCALE_ENUMPROCA", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumSystemLocalesW
(LOCALE_ENUMPROCW arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumSystemLocalesW", "LOCALE_ENUMPROCW", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumTimeFormatsA
(TIMEFMT_ENUMPROCA arg0, LCID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumTimeFormatsA", "TIMEFMT_ENUMPROCA", arg0, "LCID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumTimeFormatsW
(TIMEFMT_ENUMPROCW arg0, LCID arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumTimeFormatsW", "TIMEFMT_ENUMPROCW", arg0, "LCID", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetCurrencyFormatA
(LCID arg0, DWORD arg1, LPCSTR arg2, const CURRENCYFMTA* arg3, LPSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetCurrencyFormatA", "LCID", arg0, "DWORD", arg1, "LPCSTR", arg2, "const CURRENCYFMTA*", arg3, "LPSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetCurrencyFormatW
(LCID arg0, DWORD arg1, LPCWSTR arg2, const CURRENCYFMTW* arg3, LPWSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetCurrencyFormatW", "LCID", arg0, "DWORD", arg1, "LPCWSTR", arg2, "const CURRENCYFMTW*", arg3, "LPWSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetDateFormatA
(LCID arg0, DWORD arg1, const SYSTEMTIME* arg2, LPCSTR arg3, LPSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetDateFormatA", "LCID", arg0, "DWORD", arg1, "const SYSTEMTIME*", arg2, "LPCSTR", arg3, "LPSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetDateFormatW
(LCID arg0, DWORD arg1, const SYSTEMTIME* arg2, LPCWSTR arg3, LPWSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetDateFormatW", "LCID", arg0, "DWORD", arg1, "const SYSTEMTIME*", arg2, "LPCWSTR", arg3, "LPWSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetLocaleInfoA
(LCID arg0, LCTYPE arg1, LPSTR arg2, int arg3)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetLocaleInfoA", "LCID", arg0, "LCTYPE", arg1, "LPSTR", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetLocaleInfoW
(LCID arg0, LCTYPE arg1, LPWSTR arg2, int arg3)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetLocaleInfoW", "LCID", arg0, "LCTYPE", arg1, "LPWSTR", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetNumberFormatA
(LCID arg0, DWORD arg1, LPCSTR arg2, const NUMBERFMTA* arg3, LPSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetNumberFormatA", "LCID", arg0, "DWORD", arg1, "LPCSTR", arg2, "const NUMBERFMTA*", arg3, "LPSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetNumberFormatW
(LCID arg0, DWORD arg1, LPCWSTR arg2, const NUMBERFMTW* arg3, LPWSTR arg4, int arg5)
{
	int rc = -1;
	WIN32API_ENTER("int", "GetNumberFormatW", "LCID", arg0, "DWORD", arg1, "LPCWSTR", arg2, "const NUMBERFMTW*", arg3, "LPWSTR", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetStringTypeA
(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetStringTypeA", "LCID", Locale, "DWORD", dwInfoType, "LPCSTR", lpSrcStr, "int", cchSrc, "LPWORD", lpCharType, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetStringTypeW
(DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetStringTypeW", "DWORD", dwInfoType, "LPCSTR", lpSrcStr, "int", cchSrc, "LPWORD", lpCharType, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetStringTypeExA
(LCID arg0, DWORD arg1, LPCSTR arg2, int arg3, LPWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetStringTypeExA", "LCID", arg0, "DWORD", arg1, "LPCSTR", arg2, "int", arg3, "LPWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetStringTypeExW
(LCID arg0, DWORD arg1, LPCWSTR arg2, int arg3, LPWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetStringTypeExW", "LCID", arg0, "DWORD", arg1, "LPCWSTR", arg2, "int", arg3, "LPWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LCID WINAPI
GetSystemDefaultLCID
(void)
{
	LCID rc = (LCID)0x11;
	WIN32API_ENTER("LCID", "GetSystemDefaultLCID", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LANGID WINAPI
GetSystemDefaultLangID
(void)
{
	LANGID rc = (LANGID)-1;
	WIN32API_ENTER("LANGID", "GetSystemDefaultLangID", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LCID WINAPI
GetUserDefaultLCID
(void)
{
	LCID rc = (LCID)-1;
	WIN32API_ENTER("LCID", "GetUserDefaultLCID", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LANGID WINAPI
GetUserDefaultLangID
(void)
{
	LANGID rc = (LANGID)-1;
	WIN32API_ENTER("LANGID", "GetUserDefaultLangID", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsValidLocale
(LCID arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsValidLocale", "LCID", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
LCMapStringA
(LCID Locale, DWORD dwMapFlags, LPCTSTR lpSrcStr, int cchSrc, LPTSTR lpDestStr, int cchDest)
{
	int rc = 0;
	WIN32API_ENTER("int", "LCMapStringA", "LCID", Locale, "DWORD", dwMapFlags, "LPCTSTR", lpSrcStr, "int", cchSrc, "LPTSTR", lpDestStr, "int", cchDest, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
LCMapStringW
(LCID Locale, DWORD dwMapFlags, LPCTSTR lpSrcStr, int cchSrc, LPTSTR lpDestStr, int cchDest)
{
	int rc = 0;
	WIN32API_ENTER("int", "LCMapStringW", "LCID", Locale, "DWORD", dwMapFlags, "LPCTSTR", lpSrcStr, "int", cchSrc, "LPTSTR", lpDestStr, "int", cchDest, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetLocaleInfoA
(LCID arg0, LCTYPE arg1, LPCSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetLocaleInfoA", "LCID", arg0, "LCTYPE", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetLocaleInfoW
(LCID arg0, LCTYPE arg1, LPCWSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetLocaleInfoW", "LCID", arg0, "LCTYPE", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
