/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Time.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Time.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Time.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" LONG WINAPI
CompareFileTime
(CONST LPFILETIME arg0, CONST LPFILETIME arg1)
{
	LONG rc = -1;
	WIN32API_ENTER("LONG", "CompareFileTime", "CONST FILETIME*", arg0, "CONST FILETIME*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DosDateTimeToFileTime
(WORD arg0, WORD arg1, LPFILETIME arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DosDateTimeToFileTime", "WORD", arg0, "WORD", arg1, "LPFILETIME", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FileTimeToDosDateTime
(CONST FILETIME * arg0, LPWORD arg1, LPWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FileTimeToDosDateTime", "CONST FILETIME *", arg0, "LPWORD", arg1, "LPWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FileTimeToLocalFileTime
(FILETIME * arg0, LPFILETIME arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FileTimeToLocalFileTime", "FILETIME *", arg0, "LPFILETIME", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FileTimeToSystemTime
(CONST LPFILETIME arg0, LPSYSTEMTIME arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FileTimeToSystemTime", "CONST FILETIME *", arg0, "LPSYSTEMTIME", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
GetLocalTime
(LPSYSTEMTIME lpSystemTime)
{
	WIN32API_ENTER("VOID", "GetLocalTime", "LPSYSTEMTIME", lpSystemTime, NULL);
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	lpSystemTime->wYear = tm->tm_year;
	lpSystemTime->wMonth = tm->tm_mon + 1;
	lpSystemTime->wDayOfWeek = tm->tm_wday;
	lpSystemTime->wDay = tm->tm_mday;
	lpSystemTime->wHour = tm->tm_hour;
	lpSystemTime->wMinute = tm->tm_min;
	lpSystemTime->wSecond = tm->tm_sec;
	lpSystemTime->wMilliseconds = (real_time_clock_usecs() / 1000) % 1000;
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
GetSystemTime
(LPSYSTEMTIME lpSystemTime)
{
	WIN32API_ENTER("VOID", "GetSystemTime", "LPSYSTEMTIME", lpSystemTime, NULL);
	time_t t = time(NULL);
	struct tm *tm = gmtime(&t);
	lpSystemTime->wYear = tm->tm_year;
	lpSystemTime->wMonth = tm->tm_mon + 1;
	lpSystemTime->wDayOfWeek = tm->tm_wday;
	lpSystemTime->wDay = tm->tm_mday;
	lpSystemTime->wHour = tm->tm_hour;
	lpSystemTime->wMinute = tm->tm_min;
	lpSystemTime->wSecond = tm->tm_sec;
	lpSystemTime->wMilliseconds = (real_time_clock_usecs() / 1000) % 1000;
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
GetSystemTimeAdjustment
(PDWORD arg0, PDWORD arg1, PBOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetSystemTimeAdjustment", "PDWORD", arg0, "PDWORD", arg1, "PBOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
GetSystemTimeAsFileTime
(LPFILETIME lpSystemTimeAsFileTime)
{
	WIN32API_POINTER(lpSystemTimeAsFileTime);
	WIN32API_ENTER("void", "GetSystemTimeAsFileTime", "LPFILETIME", lpSystemTimeAsFileTime, NULL);
	WIN32API_INTERNAL_START();
	SYSTEMTIME st;
	GetSystemTime(&st);
	SystemTimeToFileTime(&st, lpSystemTimeAsFileTime);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(0);
}

extern "C" DWORD WINAPI
GetTickCount
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetTickCount", NULL);
	rc = system_time() / 1000;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTimeZoneInformation
(LPTIME_ZONE_INFORMATION arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetTimeZoneInformation", "LPTIME_ZONE_INFORMATION", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LocalFileTimeToFileTime
(CONST FILETIME * arg0, LPFILETIME arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LocalFileTimeToFileTime", "CONST FILETIME *", arg0, "LPFILETIME", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetLocalTime
(CONST LPSYSTEMTIME arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetLocalTime", "const SYSTEMTIME*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSystemTime
(CONST LPSYSTEMTIME arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSystemTime", "const SYSTEMTIME*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSystemTimeAdjustment
(DWORD arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSystemTimeAdjustment", "DWORD", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetTimeZoneInformation
(const TIME_ZONE_INFORMATION * arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetTimeZoneInformation", "const TIME_ZONE_INFORMATION *", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SystemTimeToFileTime
(CONST LPSYSTEMTIME lpSystemTime, LPFILETIME lpFileTime)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "SystemTimeToFileTime", "CONST LPSYSTEMTIME", lpSystemTime, "LPFILETIME", lpFileTime, NULL);
	struct tm tm;
	tm.tm_year = lpSystemTime->wYear;
	tm.tm_mon = lpSystemTime->wMonth - 1;
	tm.tm_wday = lpSystemTime->wDayOfWeek;
	tm.tm_mday = lpSystemTime->wDay;
	tm.tm_hour = lpSystemTime->wHour;
	tm.tm_min = lpSystemTime->wMinute;
	tm.tm_sec = lpSystemTime->wSecond;
	time_t t = mktime(&tm);	// 1970/1/1 00:00:00 - sec
	t += 60 * 60 * 24 * (365 * 369 + 92);	// 1601/1/1 00:00:00 - src
	bigtime_t bt = t * 1000 * 1000 * 10;	// 100nsec
	bt += (real_time_clock_usecs() % (1000 * 1000)) * 10;
	lpFileTime->dwLowDateTime = bt & 0xffffffff;
	lpFileTime->dwHighDateTime = (bt >> 32) & 0xffffffff;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SystemTimeToTzSpecificLocalTime
(LPTIME_ZONE_INFORMATION arg0, LPSYSTEMTIME arg1, LPSYSTEMTIME arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SystemTimeToTzSpecificLocalTime", "LPTIME_ZONE_INFORMATION", arg0, "LPSYSTEMTIME", arg1, "LPSYSTEMTIME", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
