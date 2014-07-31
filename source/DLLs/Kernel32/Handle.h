/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 とよしま
 *  $Id: Handle.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Handle.h]
 *  CloseHandleで閉じることができるオブジェクトはHandleObjectを継承している必要がある。
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Handle_h__)
#	define	__Handle_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	HANDLE_MAGIC					'_HDL'

#	define	INFINITE						((DWORD)-1)

class HandleObject {
public:
	DWORD magic;
private:
	BLocker lock;
	DWORD flags;
public:
	HandleObject(void);
	virtual ~HandleObject(void);

	BOOL SetFlags(DWORD flags);
	DWORD GetFlags(void);

	virtual bool Wait(DWORD timeout = INFINITE);
	virtual HandleObject *Duplicate(void);

private:
	inline void Lock(void) { lock.Lock(); };
	inline void Unlock(void) { lock.Unlock(); };
};

#	if !defined(__HandleObject__)
#		define	__HandleObject__
#	endif	// !defined(__HandleObject__)

#	define	STD_INPUT_HANDLE				DWORD(-10)
#	define	STD_OUTPUT_HANDLE				DWORD(-11)
#	define	STD_ERROR_HANDLE				DWORD(-12)

#	define	HANDLE_FLAG_INHERIT				0x00000001
#	define	HANDLE_FLAG_PROTECT_FROM_CLOSE	0x00000002

#	define	STATUS_TIMEOUT					((DWORD)0x00000102L)
#	define	STATUS_WAIT_0					((DWORD)0x00000000L)
#	define	STATUS_ABANDONED_WAIT_0			((DWORD)0x00000080L)

#	define	WAIT_TIMEOUT					STATUS_TIMEOUT
#	define	WAIT_OBJECT_0					STATUS_WAIT_0
#	define	WAIT_ABANDONED					STATUS_ABANDONED_WAIT_0

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL WINAPI CloseHandle(HANDLE hObject);
BOOL WINAPI DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle,
	HANDLE hTargetProcessHandle, LPHANDLE lpTargetHandle,
	DWORD dwDesitedAccess, BOOL bInheritHandle, DWORD dwOptions);
BOOL WINAPI GetHandleInformation(HANDLE hObject, LPDWORD lpdwFlags);
HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
UINT WINAPI SetHandleCount(UINT uNumber);
BOOL WINAPI SetHandleInformation(HANDLE,DWORD,DWORD);
BOOL WINAPI SetStdHandle(DWORD nStdHandle, HANDLE hHandle);
DWORD WINAPI WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable);
DWORD WINAPI WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL fWaitAll, DWORD dwMilliseconds);
DWORD WINAPI WaitForMultipleObjectsEx(DWORD nCount, const HANDLE *lpHandles, BOOL fWaitAll, DWORD dwMilliseconds, BOOL bAlertable);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Handle_h__)
