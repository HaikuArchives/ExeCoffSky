/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Interlock.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Interlock.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Interlock_h__)
#	define	__Interlock_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

// asm code (Interlock.s)
PVOID InterlockedCompareExchangeAsm(PVOID *Destination, PVOID Exchange, PVOID Comperand);
LONG InterlockedExchangeAsm(PLONG Target, LONG Value);
LONG InterlockedExchangeAddAsm(PLONG Target, LONG Value);

LONG WINAPI InterlockedDecrement(LPLONG lpAddress);
LONG WINAPI InterlockedIncrement(LPLONG lpAddress);
PVOID WINAPI InterlockedCompareExchange(PVOID* Destination, PVOID Exchange, PVOID Comperand);
LONG WINAPI InterlockedExchange(PLONG Target, LONG Value);
LONG WINAPI InterlockedExchangeAdd(PLONG Target, LONG Value);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Interlock_h__)
