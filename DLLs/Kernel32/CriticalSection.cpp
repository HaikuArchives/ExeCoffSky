/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: CriticalSection.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CriticalSection.cpp]
 *  // TODO: Win32オブジェクトを使った厳密な実装
 * -------------------------------------------------------------------------------------------- */
#include "CriticalSection.h"
#include "Win32Trace.h"

extern "C" VOID WINAPI
InitializeCriticalSection
(LPCRITICAL_SECTION lpCriticalSection)
{
	WIN32API_POINTER(lpCriticalSection);
	WIN32API_ENTER("VOID", "InitializeCriticalSection", "LPCRITICAL_SECTION", lpCriticalSection, NULL);
	memset(lpCriticalSection, 0, sizeof(CRITICAL_SECTION));
	lpCriticalSection->DebugInfo = new CRITICAL_SECTION_DEBUG;
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
DeleteCriticalSection
(LPCRITICAL_SECTION lpCriticalSection)
{
	WIN32API_POINTER(lpCriticalSection);
	WIN32API_ENTER("VOID", "DeleteCriticalSection", "LPCRITICAL_SECTION", lpCriticalSection, NULL);
	if (NULL != lpCriticalSection->DebugInfo) {
		delete lpCriticalSection->DebugInfo;
		lpCriticalSection->DebugInfo = NULL;
	}
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
EnterCriticalSection
(LPCRITICAL_SECTION lpCriticalSection)
{
	WIN32API_POINTER(lpCriticalSection);
	WIN32API_ENTER("VOID", "EnterCriticalSection", "LPCRITICAL_SECTION", lpCriticalSection, NULL);
	if (NULL != lpCriticalSection->DebugInfo) lpCriticalSection->DebugInfo->lock.Lock();
	WIN32API_LEAVE(0);
}

extern "C" VOID WINAPI
LeaveCriticalSection
(LPCRITICAL_SECTION lpCriticalSection)
{
	WIN32API_POINTER(lpCriticalSection);
	WIN32API_ENTER("VOID", "LeaveCriticalSection", "LPCRITICAL_SECTION", lpCriticalSection, NULL);
	if (NULL != lpCriticalSection->DebugInfo) lpCriticalSection->DebugInfo->lock.Unlock();
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
TryEnterCriticalSection
(LPCRITICAL_SECTION lpCriticalSection)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCriticalSection);
	WIN32API_ENTER("BOOL", "TryEnterCriticalSection", "LPCRITICAL_SECTION", lpCriticalSection, NULL);
	if (NULL != lpCriticalSection->DebugInfo) rc = (B_OK == lpCriticalSection->DebugInfo->lock.LockWithTimeout(0))? TRUE: FALSE;
	WIN32API_LEAVE(rc);
	return rc;
}
