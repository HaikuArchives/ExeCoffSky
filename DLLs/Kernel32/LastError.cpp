/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: LastError.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [LastError.cpp]
 *  TODO: エラーはスレッド毎に保持する。
 * -------------------------------------------------------------------------------------------- */
#include "LastError.h"
#include "Win32Trace.h"
#include "Thread.h"

extern "C" DWORD WINAPI
GetLastError
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "GetLastError", NULL);
	Thread *thread = Thread::GetCurrentThreadObject();
	if (NULL != thread) rc = thread->GetLastError();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
SetLastError
(DWORD dwErrCode)
{
	WIN32API_ENTER("VOID", "SetLastError", "DWORD", dwErrCode, NULL);
	Thread *thread = Thread::GetCurrentThreadObject();
	if (NULL != thread) thread->SetLastError(dwErrCode);
	WIN32API_LEAVE(0);
}
