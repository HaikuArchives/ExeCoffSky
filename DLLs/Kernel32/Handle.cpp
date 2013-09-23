/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Handle.cpp,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Handle.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Handle.h"
#include "Process.h"
#include "Win32Trace.h"
#include "Win32Error.h"

HandleObject::HandleObject
(void):
magic(HANDLE_MAGIC),
flags(0)
{
}

HandleObject::~HandleObject
(void)
{
	magic = 0;
}

BOOL
HandleObject::SetFlags(DWORD flags)
{
	Lock();
	this->flags = flags;
	Unlock();
	return TRUE;
}

DWORD
HandleObject::GetFlags(void)
{
	Lock();
	DWORD rc = flags;
	Unlock();
	return rc;
}

bool
HandleObject::Wait
(DWORD timeout)
{
	WIN32API_INFO("*** this object can not wait (not implemented.) ***\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return false;
}

HandleObject *
HandleObject::Duplicate
(void)
{
	WIN32API_INFO("*** this object can not duplicate (not implemented.) ***\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return NULL;
}

extern "C" BOOL WINAPI
CloseHandle
(HANDLE hObject)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseHandle", "HANDLE", hObject, NULL);
	hObject = (HANDLE)((ULONG)hObject | 0x80000000L);
	if (hObject == INVALID_HANDLE_VALUE) hObject = NULL;
	HandleObject *obj = REINTERPRET_CAST(HandleObject *, hObject);
	if ((NULL != obj) && (obj->magic == HANDLE_MAGIC)) {
		DWORD flags = obj->GetFlags();
		if (0 == (flags & HANDLE_FLAG_PROTECT_FROM_CLOSE)) {
			delete obj;
			rc = TRUE;
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			WIN32API_ERROR(ERROR_ACCESS_DENIED);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DuplicateHandle
(HANDLE hSourceProcessHandle, HANDLE hSourceHandle, HANDLE hTargetProcessHandle, LPHANDLE lpTargetHandle,
	DWORD dwDesiredAccess, BOOL bInheritantHandle, DWORD dwOptions)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpTargetHandle);
	WIN32API_ENTER("BOOL", "DuplicateHandle", "HANDLE", hSourceProcessHandle, "HANDLE", hSourceHandle,
		"HANDLE", hTargetProcessHandle, "LPHANDLE", lpTargetHandle,
		"DWORD", dwDesiredAccess, "BOOL", bInheritantHandle, "DWORD", dwOptions, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetHandleInformation
(HANDLE hObject, LPDWORD lpdwFlags)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpdwFlags);
	WIN32API_ENTER("BOOL", "GetHandleInformation", "HANDLE", hObject, "PDWORD", lpdwFlags, NULL);
	HandleObject *obj = REINTERPRET_CAST(HandleObject *, obj);
	if ((NULL != obj) && (obj->magic == HANDLE_MAGIC)) {
		*lpdwFlags = obj->GetFlags();
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetStdHandle
(DWORD nStdHandle)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "GetStdHandle", "DWORD", nStdHandle, NULL);
	rc = Process::GetCurrentProcessObject()->GetStdHandle(nStdHandle);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetHandleCount
(UINT uNumber)
{
	UINT rc = uNumber;
	WIN32API_ENTER("UINT", "SetHandleCount", "UINT", uNumber, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetStdHandle
(DWORD nStdHandle, HANDLE hHandle)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetStdHandle", "DWORD", nStdHandle, "HANDLE", hHandle, NULL);
	Process::GetCurrentProcessObject()->SetStdHandle(nStdHandle, hHandle);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
WaitForSingleObject
(HANDLE hHandle, DWORD dwMilliseconds)
{
	WIN32API_ENTER("DWORD", "WaitForSingleObject", "HANDLE", hHandle, "DWORD", dwMilliseconds, NULL);
	WIN32API_INTERNAL_START();
	DWORD rc = WaitForSingleObjectEx(hHandle, dwMilliseconds, TRUE);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
WaitForSingleObjectEx
(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "WaitForSingleObjectEx", "HANDLE", hHandle, "DWORD", dwMilliseconds, "BOOL", bAlertable, NULL);
	if (INVALID_HANDLE_VALUE == hHandle) hHandle = NULL;
	HandleObject *obj = REINTERPRET_CAST(HandleObject *, hHandle);
	if ((NULL != obj) && (obj->magic == HANDLE_MAGIC)) {
		if (obj->Wait(dwMilliseconds)) {
			rc = WAIT_OBJECT_0;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
WaitForMultipleObjects
(DWORD nCount, const HANDLE *lpHandles, BOOL fWaitAll, DWORD dwMilliseconds)
{
	WIN32API_ENTER("DWORD", "WaitForMultipleObjects", "DWORD", nCount, "const HANDLE*", lpHandles, "BOOL", fWaitAll, "DWORD", dwMilliseconds, NULL);
	WIN32API_INTERNAL_START();
	DWORD rc = WaitForMultipleObjectsEx(nCount, lpHandles, fWaitAll, dwMilliseconds, TRUE);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
WaitForMultipleObjectsEx
(DWORD nCount, const HANDLE *lpHandles, BOOL fWaitAll, DWORD dwMilliseconds, BOOL bAlertable)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "WaitForMultipleObjectsEx", "DWORD", nCount, "const HANDLE*", lpHandles, "BOOL", fWaitAll, "DWORD", dwMilliseconds, "BOOL", bAlertable, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}
