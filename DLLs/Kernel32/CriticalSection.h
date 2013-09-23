/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: CriticalSection.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CriticalSection.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__CriticalSection_h__)
#	define	__CriticalSection_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)

extern "C" {
#	endif	// defined(__cplusplus)

typedef struct tagCRITICAL_SECTION_DEBUG {
	BLocker lock;
} CRITICAL_SECTION_DEBUG, *LPCRITICAL_SECTION_DEBUG;

typedef struct tagCRITICAL_SECTION {
	LPCRITICAL_SECTION_DEBUG DebugInfo;
	LONG LockCount;
	LONG RecursionCount;
	HANDLE OwningThread;
	HANDLE LockSemaphore;
	DWORD SpinCount;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
BOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__CriticalSection_h__)
