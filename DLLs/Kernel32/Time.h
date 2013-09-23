/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Time.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Time.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Time_h__)
#	define	__Time_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

LONG WINAPI CompareFileTime(CONST LPFILETIME lpFileTime1,CONST LPFILETIME lpFileTime2);
BOOL WINAPI DosDateTimeToFileTime(WORD,WORD,LPFILETIME);
BOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *,LPWORD,LPWORD);
BOOL WINAPI FileTimeToLocalFileTime(FILETIME *,LPFILETIME);
BOOL WINAPI FileTimeToSystemTime(CONST LPFILETIME lpFileTime, LPSYSTEMTIME lpSystemTime);
VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
VOID WINAPI GetSystemTime(LPSYSTEMTIME);
BOOL WINAPI GetSystemTimeAdjustment(PDWORD,PDWORD,PBOOL);
void WINAPI GetSystemTimeAsFileTime(LPFILETIME);
DWORD WINAPI GetTickCount(VOID);
DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION);
BOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *,LPFILETIME);
BOOL WINAPI SetLocalTime(CONST LPSYSTEMTIME lpSystemTime);
BOOL WINAPI SetSystemTime(CONST LPSYSTEMTIME lpSystemTime);
BOOL WINAPI SetSystemTimeAdjustment(DWORD,BOOL);
BOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *);
BOOL WINAPI SystemTimeToFileTime(CONST LPSYSTEMTIME lpSystemTime, LPFILETIME lpFileTime);
BOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION,LPSYSTEMTIME,LPSYSTEMTIME);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Time_h__)
