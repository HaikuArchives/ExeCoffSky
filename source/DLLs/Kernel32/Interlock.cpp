/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Interlock.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Interlock.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Interlock.h"
#include "Win32Trace.h"

extern "C" LONG WINAPI
InterlockedDecrement
(LPLONG lpAddress)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "InterLockedDecrement", "LPLONG", lpAddress, NULL);
	rc = atomic_add(lpAddress, -1);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
InterlockedIncrement
(LPLONG lpAddress)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "InterLockedIncrement", "LOLONG", lpAddress, NULL);
	rc = atomic_add(lpAddress, 1);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PVOID WINAPI
InterlockedCompareExchange
(PVOID* Destination, PVOID Exchange, PVOID Comperand)
{
	PVOID rc = NULL;
	WIN32API_ENTER("PVOID", "InterlockedCompareExchange", "PVOID*", Destination, "PVOID", Exchange, "PVOID", Comperand, NULL);
	rc = InterlockedCompareExchangeAsm(Destination, Exchange, Comperand);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
InterlockedExchange
(PLONG Target, LONG Value)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "InterlockedExchange", "PLONG", Target, "LONG", Value, NULL);
	rc = InterlockedExchangeAsm(Target, Value);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
InterlockedExchangeAdd
(PLONG Target, LONG Value)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "InterlockedExchangeAdd", "PLONG", Target, "LONG", Value, NULL);
	rc = InterlockedExchangeAddAsm(Target, Value);
	WIN32API_LEAVE(rc);
	return rc;
}
