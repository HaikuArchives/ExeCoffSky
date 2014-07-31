/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Thread.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Thread.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Thread_h__)
#	define	__Thread_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Handle_h__)
#		include "Handle.h"
#	endif	// !defined(__Handle_h__)

#	if !defined(__Tls_h__)
#		include "Tls.h"
#	endif	// !defined(__Tls_h__)

#	define	CREATE_SUSPEND					0x00000004
#	define	STATUS_PENDING					((DWORD)0x00000103L)
#	define	STILL_ACTIVE					STATUS_PENDING

#	define	THREAD_MAGIC					'_TRD'
#	define	PCODE_THREAD_POST				'tPst'
#	define	PCODE_THREAD_SEND				'tSnd'
#	define	PCODE_THREAD_REPLY				'tRpy'
#	define	PCODE_TIMEOUT					'Tout'

#	define	THREAD_BASE_PRIORITY_LOWRT		15
#	define	THREAD_BASE_PRIORITY_MAX		2
#	define	THREAD_BASE_PRIORITY_MIN		-2
#	define	THREAD_BASE_PRIORITY_IDLE		-15

#	define	THREAD_PRIORITY_LOWEST			THREAD_BASE_PRIORITY_MIN
#	define	THREAD_PRIORITY_BELOW_NORMAL	(THREAD_PRIORITY_LOWEST + 1)
#	define	THREAD_PRIORITY_NORMAL			0
#	define	THREAD_PRIORITY_HIGHEST			THREAD_BASE_PRIORITY_MAX
#	define	THREAD_PRIORITY_ABOVE_NORMAL	(THREAD_PRIORITY_HIGHEST - 1)
#	define	THREAD_PRIORITY_ERROR_RETURN	0x7fffffff
#	define	THREAD_PRIORITY_TIME_CRITICAL	THREAD_BASE_PRIORITY_LOWRT
#	define	THREAD_PRIORITY_IDLE			THREAD_BASE_PRIORITY_IDLE

typedef DWORD CALLBACK (*PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct tagMSGEX {
	MSG msg;
	port_id reply_port;
} MSGEX, *LPMSGEX;

#	if !defined(__Timer__)
class Timer;
#		define	__Timer__
#	endif	// !defined(__Timer__)

class Thread: public HandleObject, public Tls {
	typedef struct _thread_list {
		DWORD id;
		Thread *obj;
		struct _thread_list *next;
	} thread_list;
public:
	static thread_list *tlist;
	static BLocker lock;
	DWORD magic;
private:
	DWORD error;
	DWORD tid;
	DWORD ec;
	LCID lcid;
	int priority;
	bigtime_t creation_time;
	bigtime_t exit_time;
	bigtime_t user_time;
	bigtime_t kernel_time;
	int suspend_count;
	port_id port;
	BList timerlist;
	BList msg;
public:
	Thread(void);
	~Thread(void);
	VOID SetLastError(DWORD error);
	DWORD GetLastError(VOID);
	VOID SetExitCode(DWORD code);
	DWORD GetExitCode(VOID);
	VOID SetLocale(LCID id);
	LCID GetLocale(VOID);
	VOID SetPriority(int priority);
	int GetPriority(VOID);

	DWORD GetID(VOID);
	port_id GetPort(VOID);
	VOID GetTimes(LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);

	status_t Spawn(LPTHREAD_START_ROUTINE, LPVOID lpParameter);
	status_t Shift(VOID);
	status_t Resume(VOID);
	status_t Suspend(VOID);

	bool SetTimer(Timer *timer);
	bool KillTimer(Timer *timer);

	BOOL CheckMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax,
		bool remove = false, bool block = false);
	static bool MatchMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);

	BOOL PostMessage(LPMSG lpMsg);
	BOOL PostMessage(UINT Msg, WPARAM wParam, LPARAM lParam);
	LRESULT WaitForReply(void);

	static inline void Lock(void) { lock.Lock(); };
	static inline void Unlock(void) { lock.Unlock(); };

	static DWORD GetCurrentThreadId(void);
	static Thread *GetCurrentThreadObject(void);
	static Thread *GetThreadObject(DWORD id);
private:
	static int PriorityWinToBe(int priority);
public:
	static void ToFileTime(LPFILETIME lpft, bigtime_t t);
private:
	static bool TimerCheck(void *item, void *arg);
};

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HANDLE WINAPI CreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
void WINAPI ExitThread(DWORD dwExitCode);
void WINAPI FreeLibraryAndExitThread(HMODULE hModule, DWORD dwExitCode);
HANDLE WINAPI GetCurrentThread(VOID);
DWORD WINAPI GetCurrentThreadId(VOID);
BOOL WINAPI GetExitCodeThread(HANDLE handle, LPDWORD lpExitCode);
BOOL WINAPI GetThreadContext(HANDLE handle, LPCONTEXT lpContext);
LCID WINAPI GetThreadLocale(void);
int WINAPI GetThreadPriority(HANDLE hThread);
BOOL WINAPI GetThreadPriorityBoost(HANDLE hThread, PBOOL pDisablePriorityBoost);
BOOL WINAPI GetThreadSelectorEntry(HANDLE hThread, DWORD dwSelector, LPLDT_ENTRY lpSelectorEntry);
BOOL WINAPI GetThreadTimes(HANDLE hThread, LPFILETIME lpCreationTime,
	LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
DWORD WINAPI ResumeThread(HANDLE hThread);
DWORD WINAPI SetThreadAffinityMask(HANDLE hThread, DWORD dwThreadAffinityMask);
BOOL WINAPI SetThreadContext(HANDLE hThread, const CONTEXT* lpContext);
DWORD WINAPI SetThreadIdealProcessor(HANDLE hThread, DWORD dwIdealProcessor);
BOOL WINAPI SetThreadLocale(LCID lcid);
BOOL WINAPI SetThreadPriority(HANDLE hThread, int nPriority);
BOOL WINAPI SetThreadPriorityBoost(HANDLE hThread, BOOL DisablePriorityBoost);
DWORD WINAPI SuspendThread(HANDLE hThread);
BOOL WINAPI SwitchToThread(void);
BOOL WINAPI TerminateThread(HANDLE hThread, DWORD dwExitCode);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Thread_h__)
