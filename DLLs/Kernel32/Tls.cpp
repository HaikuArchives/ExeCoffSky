/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Tls.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Tls.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Tls.h"
#include "Thread.h"
#include "Win32Trace.h"
#include "Win32Error.h"

bool
Tls::used[TLS_MAX];

int
Tls::last_index = 0;

bool
Tls::initialized = false;

BLocker
Tls::lock;

Tls::Tls
(void)
{
	Lock();
	if (!initialized) Initialize();
	for (int i = 0; i < TLS_MAX; i++) params[i] = NULL;
	Unlock();
}

DWORD
Tls::Allocate
(void)
{
	Lock();
	if (!initialized) Initialize();
	int i;
	for (i = last_index; i < TLS_MAX; i++) {
		if (!used[i]) goto found;
	}
	for (i = 0; i < last_index; i++) {
		if (!used[i]) goto found;
	}
	WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	Unlock();
	return (DWORD)-1;
found:
	WIN32API_ERROR(ERROR_SUCCESS);
	used[i] = true;
	Unlock();
	return (DWORD)i;
}

BOOL
Tls::SetValue
(DWORD dwIndex, LPVOID lpValue)
{
	Lock();
	if (!initialized) Initialize();
	if (!used[dwIndex]) {
		WIN32API_ERROR(ERROR_INVALID_INDEX);
		Unlock();
		return FALSE;
	}
	params[dwIndex] = lpValue;
	WIN32API_ERROR(ERROR_SUCCESS);
	Unlock();
	return TRUE;
}

LPVOID
Tls::GetValue
(DWORD dwIndex)
{
	Lock();
	if (!initialized) Initialize();
	if (!used[dwIndex]) {
		WIN32API_ERROR(ERROR_INVALID_INDEX);
		Unlock();
		return NULL;
	}
	WIN32API_ERROR(ERROR_SUCCESS);
	LPVOID rc = params[dwIndex];
	Unlock();
	return rc;
}

BOOL
Tls::Free
(DWORD dwIndex)
{
	Lock();
	if (!initialized) Initialize();
	if (!used[dwIndex]) {
		Unlock();
		return FALSE;
	}
	used[dwIndex] = false;
	Unlock();
	return TRUE;
}

void
Tls::Initialize
(void)
{
	for (int i = 0; i < TLS_MAX; i++) used[i] = false;
	last_index = 0;
	initialized = true;
}

extern "C" DWORD WINAPI
TlsAlloc
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "TlsAlloc", NULL);
	rc = Tls::Allocate();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TlsSetValue
(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpTlsValue);
	WIN32API_ENTER("BOOL", "TlsSetValue", "DWORD", dwTlsIndex, "LPVOID", lpTlsValue, NULL);
	rc = Thread::GetCurrentThreadObject()->SetValue(dwTlsIndex, lpTlsValue);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
TlsGetValue
(DWORD dwTlsIndex)
{
	LPVOID rc = 0;
	WIN32API_ENTER("LPVOID", "TlsGetValue", "DWORD", dwTlsIndex, NULL);
	rc = Thread::GetCurrentThreadObject()->GetValue(dwTlsIndex);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TlsFree
(DWORD dwTlsIndex)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TlsFree", "DWORD", dwTlsIndex, NULL);
	rc = Tls::Free(dwTlsIndex);
	WIN32API_LEAVE(rc);
	return rc;
}
