/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: Mutex.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Mutex.cpp]
 *   ダミー実装。いずれwin32_serverと通信するように変更すべし。
 * -------------------------------------------------------------------------------------------- */
#include "Mutex.h"
#include "Win32Trace.h"
#include "Win32String.h"
#include "Win32Error.h"

Mutex::Mutex
(void):
magic(MUTEX_MAGIC),
access(0)
{
}

Mutex::~Mutex
(void)
{
}

bool
Mutex::Wait
(DWORD timeout)
{
	return Aquire() == TRUE;
}

bool
Mutex::Create
(LPCSTR lpName, BOOL bInitialOwner)
{
	WIN32API_ERROR(ERROR_SUCCESS);
	return true;
}

DWORD
Mutex::SetAccess
(DWORD dwAccess)
{
	return access = dwAccess;
}

BOOL
Mutex::Aquire
(void)
{
	//
	WIN32API_INFO("\tMutex::Aquire => dummy\n");
	return TRUE;
}

BOOL
Mutex::Release
(void)
{
	//
	WIN32API_INFO("\tMutex::Release => dummy\n");
	return TRUE;
}

Mutex *
Mutex::HandleToMutex
(HANDLE hMutex)
{
	if (NULL == hMutex) return NULL;
	Mutex *mutex = (Mutex *)hMutex;
	if (mutex->magic != MUTEX_MAGIC) return NULL;
	return mutex;
}

static HANDLE
CreateMutexU
(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
	WIN32API_INFO("\tname: %s\n", lpName);
	HANDLE rc = NULL;
	Mutex *mutex = new Mutex();
	if (NULL == mutex) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		if (!mutex->Create(lpName, bInitialOwner)) {
			// すでに名前が他のオブジェクトで使われていた
			WIN32API_ERROR(ERROR_INVALID_HANDLE);
		} else {
			// Create内で、ERROR_ALREADY_EXISTかERROR_SUCCESSが設定される
			rc = (HANDLE)mutex;
		}
	}
	return rc;
}

static HANDLE
OpenMutexU
(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName)
{
	HANDLE hMutex = CreateMutexU(NULL, bInheritHandle, lpName);
	if (NULL != hMutex) {
		if (ERROR_ALREADY_EXISTS != GetLastError()) {
			CloseHandle(hMutex);
			WIN32API_ERROR(ERROR_INVALID_HANDLE);
			return NULL;
		} else {
			Mutex *mutex = Mutex::HandleToMutex(hMutex);
			mutex->SetAccess(dwDesiredAccess);
			WIN32API_ERROR(ERROR_SUCCESS);
			return hMutex;
		}
	}
	return NULL;
}

extern "C" HANDLE WINAPI
CreateMutexA
(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
	WIN32API_POINTER(lpMutexAttributes);
	WIN32API_POINTER(lpName);
	WIN32API_ENTER("HANDLE", "CreateMutexA", "LPSECURITY_ATTRIBUTES", lpMutexAttributes, "BOOL", bInitialOwner, "LPCSTR", lpName, NULL);
	Win32String name;
	name.SetToA(lpName);
	HANDLE rc = CreateMutexU(lpMutexAttributes, bInitialOwner, name.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateMutexW
(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName)
{
	WIN32API_POINTER(lpMutexAttributes);
	WIN32API_POINTER(lpName);
	WIN32API_ENTER("HANDLE", "CreateMutexW", "LPSECURITY_ATTRIBUTES", lpMutexAttributes, "BOOL", bInitialOwner, "LPCWSTR", lpName, NULL);
	Win32String name;
	name.SetToW(lpName);
	HANDLE rc = CreateMutexU(lpMutexAttributes, bInitialOwner, name.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenMutexA
(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName)
{
	WIN32API_POINTER(lpName);
	WIN32API_ENTER("HANDLE", "OpenMutexA", "DWORD", dwDesiredAccess, "BOOL", bInheritHandle, "LPCSTR", lpName, NULL);
	Win32String name;
	name.SetToA(lpName);
	HANDLE rc = OpenMutexU(dwDesiredAccess, bInheritHandle, name.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
OpenMutexW
(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName)
{
	WIN32API_POINTER(lpName);
	WIN32API_ENTER("HANDLE", "OpenMutexW", "DWORD", dwDesiredAccess, "BOOL", bInheritHandle, "LPCWSTR", lpName, NULL);
	Win32String name;
	name.SetToW(lpName);
	HANDLE rc = OpenMutexU(dwDesiredAccess, bInheritHandle, name.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReleaseMutex
(HANDLE hMutex)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReleaseMutex", "HANDLE", hMutex, NULL);
	Mutex *mutex = Mutex::HandleToMutex(hMutex);
	if (NULL == mutex) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = mutex->Release();
	}
	WIN32API_LEAVE(rc);
	return rc;
}
