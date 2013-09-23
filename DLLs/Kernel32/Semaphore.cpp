/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Semaphore.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Semaphore.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Semaphore.h"
#include "Kernel32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Semaphore::Semaphore
(void):
magic(SEM_MAGIC),
id(-1),
count(0)
{
}

Semaphore::~Semaphore
(void)
{
	if (id >= B_OK) delete_sem(id);
	magic = 0;
}

bool
Semaphore::Wait
(DWORD timeout)
{
	WIN32API_INFO("\twait semaphore...\n");
	acquire_sem(id);
	WIN32API_INFO("\tok\n");
	return true;
}

bool
Semaphore::Initialize
(int count, const char *name)
{
	id = create_sem(count, name);
	this->count = count;
	return (id >= B_OK);
}

int
Semaphore::Release
(int count)
{
	int rc = this->count;
	release_sem_etc(id, count, 0);
	this->count += count;
	return rc;
}

Semaphore *
Semaphore::HandleToSemaphore
(HANDLE hSemaphore)
{
	if (NULL == hSemaphore) return NULL;
	Semaphore *sem = (Semaphore *)hSemaphore;
	if (sem->magic != SEM_MAGIC) return NULL;
	return sem;
}

extern "C" HANDLE WINAPI
CreateSemaphoreA
(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCTSTR lpName)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateSemaphoreA", "LPSECURITY_ATTRIBUTES", lpSemaphoreAttributes, "LONG", lInitialCount, "LONG", lMaximumCount, "LPCTSTR", lpName, NULL);
	WIN32API_POINTER(lpName);
	WIN32API_INFO("\tname = %s\n", lpName);
	Semaphore *sem = new Semaphore();
	if (NULL != sem) {
		if (!sem->Initialize(lInitialCount, lpName)) {
			WIN32API_INFO("\tsemaphoe initialize failed\n");
			delete sem;
		} else {
			rc = (HANDLE)sem;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateSemaphoreW
(LPSECURITY_ATTRIBUTES arg0, LONG arg1, LONG arg2, LPCWSTR arg3)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CreateSemaphoreW", "LPSECURITY_ATTRIBUTES", arg0, "LONG", arg1, "LONG", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenSemaphoreA
(DWORD arg0, BOOL arg1, LPCSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenSemaphoreA", "DWORD", arg0, "BOOL", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenSemaphoreW
(DWORD arg0, BOOL arg1, LPCWSTR arg2)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OpenSemaphoreW", "DWORD", arg0, "BOOL", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReleaseSemaphore
(HANDLE hSemaphore, LONG lReleaseCount, LPLONG lpPreviousCount)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReleaseSemaphore", "HANDLE", hSemaphore, "LONG", lReleaseCount, "LPLONG", lpPreviousCount, NULL);
	Semaphore *sem = Semaphore::HandleToSemaphore(hSemaphore);
	if (NULL != sem) {
		int count = sem->Release(lReleaseCount);
		if (NULL != lpPreviousCount) *lpPreviousCount = count;
		rc = TRUE;
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}
