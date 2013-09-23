/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Semaphore.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Semaphore.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Semaphore_h__)
#	define	__Semaphore_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Handle_h__)
#		include "Handle.h"
#	endif	// !defined(__Handle_h__)

#	define	SEM_MAGIC	'_SEM'

class Semaphore: public HandleObject {
public:
	DWORD magic;
private:
	sem_id id;
	int count;
public:
	Semaphore(void);
	~Semaphore(void);
	
	bool Wait(DWORD timeout = INFINITE);
	
	bool Initialize(int count, const char *name);
	int Release(int count);

	static Semaphore *HandleToSemaphore(HANDLE hSemaphore);
};

#	if !defined(__Semaphore__)
#		define	__Semaphore__
#	endif	// !defined(__Semaphore__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCTSTR lpName);
HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCWSTR lpName);
HANDLE WINAPI OpenSemaphoreA(DWORD,BOOL,LPCSTR);
HANDLE WINAPI OpenSemaphoreW(DWORD,BOOL,LPCWSTR);
BOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore, LONG lReleaseCount, LPLONG lpPreviousCount);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Semaphore_h__)
