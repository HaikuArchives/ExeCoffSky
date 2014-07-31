/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Thread.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Thread.cpp]
 * TODO: ŠeDLL‚É‘Î‚·‚éThreadAttached/Detached
 * -------------------------------------------------------------------------------------------- */
#include "Thread.h"
#include "Timer.h"
#include "Locale.h"
#include "Module.h"
#include "User32/Window.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "LastError.h"

Thread::thread_list *
Thread::tlist = NULL;

BLocker
Thread::lock;

Thread::Thread
(void):
magic(THREAD_MAGIC),
error(STILL_ACTIVE),
tid((DWORD)-1),
ec(0),
lcid(0),
priority(THREAD_PRIORITY_NORMAL),
creation_time(0),
exit_time(0),
user_time(0),
kernel_time(0),
suspend_count(0)
{
	WIN32API_INTERNAL_START();
	lcid = GetSystemDefaultLCID();
	WIN32API_INTERNAL_END();
	creation_time = system_time();
	port = create_port(1000, "win32 thread port");
	// XXX: lcid
}

Thread::~Thread
(void)
{
	thread_list *prev_list = NULL;
	Lock();
	for (thread_list *list = tlist; NULL != list; list = list->next) {
		if (list->id == tid) {
			if (NULL != prev_list) prev_list->next = list->next;
			else tlist = list->next;
			delete list;
			break;
		}
		prev_list = list;
	}
	Unlock();
	magic = 0;
	close_port(port);
}

VOID
Thread::SetLastError
(DWORD error)
{
	this->error = error;
}

DWORD
Thread::GetLastError
(VOID)
{
	return error;
}

VOID
Thread::SetExitCode
(DWORD code)
{
	ec = code;
	exit_time = system_time();
	thread_info info;
	if (B_OK == get_thread_info(GetCurrentThreadId(), &info)) {
		user_time = info.user_time;
		kernel_time = info.kernel_time;
	}
}

DWORD
Thread::GetExitCode
(VOID)
{
	return ec;
}

VOID
Thread::SetLocale
(LCID id)
{
	lcid = id;
}

LCID
Thread::GetLocale
(VOID)
{
	return lcid;
}

VOID
Thread::SetPriority
(int priority)
{
	this->priority = priority;
	set_thread_priority((thread_id)tid, PriorityWinToBe(priority));
}

int
Thread::GetPriority
(VOID)
{
	return priority;
}

DWORD
Thread::GetID
(VOID)
{
	return tid;
}

port_id
Thread::GetPort
(VOID)
{
	return port;
}

VOID
Thread::GetTimes
(LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime)
{
	ToFileTime(lpCreationTime, creation_time);
	ToFileTime(lpExitTime, exit_time);
	if (ec == STILL_ACTIVE) {
		thread_info info;
		if (B_OK == get_thread_info(GetCurrentThreadId(), &info)) {
			ToFileTime(lpUserTime, info.user_time);
			ToFileTime(lpKernelTime, info.kernel_time);
		} else {
			WIN32API_INFO("\tcan not get thread_info\n");
			ToFileTime(lpUserTime, 0);
			ToFileTime(lpKernelTime, 0);
		}
	} else {
		ToFileTime(lpKernelTime, kernel_time);
		ToFileTime(lpUserTime, user_time);
	}
}

status_t
Thread::Spawn
(LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter)
{
	thread_id id = spawn_thread((thread_func)lpStartAddress, "win32 thread", B_NORMAL_PRIORITY, lpParameter);
	if (id >= B_OK) {
		tid = (DWORD)id;
		thread_list *tl = new thread_list;
		if (NULL == tl) return B_ERROR;
		Lock();
		tl->id = tid;
		tl->obj = this;
		tl->next = tlist;
		tlist = tl;
		Unlock();
		return B_OK;
	}
	return (status_t)id;
}

status_t
Thread::Shift
(VOID)
{
	tid = (DWORD)GetCurrentThreadId();
	thread_list *tl = new thread_list;
	if (NULL == tl) return B_ERROR;
	Lock();
	tl->id = tid;
	tl->obj = this;
	tl->next = tlist;
	tlist = tl;
	Unlock();
	return B_OK;
}

status_t
Thread::Resume
(VOID)
{
	thread_id id = (thread_id)tid;
	status_t rc = resume_thread(id);
	if (rc == B_OK) return suspend_count;
	return rc;
}

status_t
Thread::Suspend
(VOID)
{
	thread_id id = (thread_id)tid;
	status_t rc = suspend_thread(id);
	if (rc == B_OK) return suspend_count++;
	return rc;
}

bool
Thread::SetTimer
(Timer *timer)
{
	bool rc = timerlist.AddItem((void *)timer);
	if (rc) {
		timer->Set(port);
		write_port(port, PCODE_TIMEOUT, NULL, 0);
	}
	return rc;
}

bool
Thread::KillTimer
(Timer *timer)
{
	return timerlist.RemoveItem((void *)timer);
}

BOOL
Thread::CheckMessage
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, bool remove, bool block)
{
	int32 n = msg.CountItems();
	for (int i = 0; i < n; i++) {
		LPMSG message = (LPMSG)msg.ItemAt(i);
		if (!MatchMessage(message, hWnd, wMsgFilterMin, wMsgFilterMax)) continue;
		memcpy(lpMsg, message, sizeof(MSG));
		if (remove) {
			delete message;
			msg.RemoveItem(i);
		}
		return TRUE;
	}

	for (;;) {
		bigtime_t now = system_time();
		timerlist.DoForEach(TimerCheck, (void *)&now);

		MSGEX msgex;
		int32 code;
		ssize_t readsize;
		readsize = read_port_etc(port, &code, &msgex, sizeof(MSGEX), B_TIMEOUT, 1000);
		if (B_TIMED_OUT == readsize) {
			if (!block) return FALSE;
			continue;
		}
		if (0 == readsize) continue;
		if ((readsize != sizeof(MSG)) && (readsize != sizeof(MSGEX))) {
			WIN32API_INFO("!!! invalid message size %d !!!\n", readsize);
			return FALSE;
		}
		if (PCODE_THREAD_SEND == code) {
			Window *window = Window::HandleToWindow(msgex.msg.hwnd);
			LRESULT rc = 0;
			if (NULL == window) {
				WIN32API_INFO("!!! target window is invalid !!!\n");
			} else {
				rc = window->SendMessage(&msgex.msg);
			}
			MSG reply;
			reply.lParam = rc;
			write_port(msgex.reply_port, PCODE_THREAD_REPLY, &reply, sizeof(MSG));
			continue;
		} else {
			if (MatchMessage((LPMSG)&msgex, hWnd, wMsgFilterMin, wMsgFilterMax)) {
				if (!remove) {
					LPMSG message = new MSG;
					if (NULL != message) {
						memcpy(message, &msgex, sizeof(MSG));
						msg.AddItem(message);
					}
				}
				memcpy(lpMsg, &msgex, sizeof(MSG));
				return TRUE;
			} else {
				LPMSG message = new MSG;
				if (NULL != message) {
					memcpy(message, &msgex, sizeof(MSG));
					msg.AddItem(message);
				}
			}
		}
	}
	return FALSE;
}

bool
Thread::MatchMessage
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
	if ((HWND)-1 == hWnd) {
		if (lpMsg->hwnd != NULL) return false;
	} else if (hWnd != NULL) {
		if (lpMsg->hwnd != hWnd) return false;
	}
	if ((wMsgFilterMin == 0) && (wMsgFilterMax == 0)) return true;
	if ((wMsgFilterMin <= lpMsg->message) && (lpMsg->message <= wMsgFilterMax)) return true;
	return false;
}

BOOL
Thread::PostMessage
(LPMSG lpMsg)
{
	return (B_OK == write_port_etc(port, PCODE_THREAD_POST, lpMsg, sizeof(MSG), B_TIMEOUT, 0))? TRUE: FALSE;
}

BOOL
Thread::PostMessage
(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	MSG msg;
	msg.hwnd = NULL;
	msg.message = Msg;
	msg.wParam = wParam;
	msg.lParam = lParam;
	msg.time = (system_time() >> 32) & 0xffffffff;
	return PostMessage(&msg);
}

LRESULT
Thread::WaitForReply
(void)
{
	MSGEX msgex;
	int32 code;
	ssize_t readsize;
	for (;;) {
		readsize = read_port(port, &code, &msgex, sizeof(MSGEX));
		if (code != PCODE_THREAD_REPLY) {
			LPMSG message = new MSG;
			if (NULL == message) {
				WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			} else {
				memcpy(message, &msgex, sizeof(MSG));
				msg.AddItem(message);
			}
		} else {
			return msgex.msg.lParam;
		}
	}
}

DWORD
Thread::GetCurrentThreadId
(void)
{
	return (DWORD)find_thread(NULL);
}

Thread *
Thread::GetCurrentThreadObject
(void)
{
	return GetThreadObject(GetCurrentThreadId());
}

Thread *
Thread::GetThreadObject
(DWORD tid)
{
	Thread *obj = NULL;
	Lock();
	for (thread_list *list = tlist; NULL != list; list = list->next) {
		if (list->id == tid) {
			obj = list->obj;
			break;
		}
	}
	Unlock();
	return obj;
}

int
Thread::PriorityWinToBe
(int priority)
{
	switch (priority) {
	case THREAD_PRIORITY_LOWEST:
		return B_LOW_PRIORITY;
	case THREAD_PRIORITY_BELOW_NORMAL:
		return (B_LOW_PRIORITY + B_NORMAL_PRIORITY) / 2;
	case THREAD_PRIORITY_NORMAL:
		return B_NORMAL_PRIORITY;
	case THREAD_PRIORITY_ABOVE_NORMAL:
		return B_DISPLAY_PRIORITY;
	case THREAD_PRIORITY_HIGHEST:
		return B_URGENT_DISPLAY_PRIORITY;
	case THREAD_PRIORITY_TIME_CRITICAL:
		return B_REAL_TIME_DISPLAY_PRIORITY;
	case THREAD_PRIORITY_IDLE:
		return 1;
	}
	WIN32API_INFO("\tunknown priority: %d\n", priority);
	return 0;
}

void
Thread::ToFileTime
(LPFILETIME lpft, bigtime_t t)
{
	if (NULL == lpft) return;
	t *= 10;	// msec to 100nsec
	lpft->dwLowDateTime = t & 0xffffffff;
	lpft->dwHighDateTime = (t >> 32) & 0xffffffff;
}

bool
Thread::TimerCheck
(void *item, void *arg)
{
	Timer *timer = (Timer *)item;
	bigtime_t *now = (bigtime_t *)arg;
	timer->Check(now);
	return false;
}

extern "C" HANDLE WINAPI
CreateRemoteThread
(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
	HANDLE rc = NULL;
	WIN32API_POINTER(lpThreadAttributes);
	WIN32API_POINTER(lpStartAddress);
	WIN32API_POINTER(lpParameter);
	WIN32API_POINTER(lpThreadId);
	WIN32API_ENTER("HANDLE", "CreateRemoteThread", "HANDLE", hProcess, "LPSECURITY_ATTRIBUTES", lpThreadAttributes, "DWORD", dwStackSize, "LPTHREAD_START_ROUTINE", lpStartAddress, "LPVOID", lpParameter, "DWORD", dwCreationFlags, "LPDWORD", lpThreadId, NULL);	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CreateThread
(LPSECURITY_ATTRIBUTES lpThreadAttributes, DWORD dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
	HANDLE rc = NULL;
	WIN32API_POINTER(lpThreadAttributes);
	WIN32API_POINTER(lpStartAddress);
	WIN32API_POINTER(lpParameter);
	WIN32API_POINTER(lpThreadId);
	WIN32API_ENTER("HANDLE", "CreateThread", "LPSECURITY_ATTRIBUTES", lpThreadAttributes, "DWORD", dwStackSize, "LPTHREAD_START_ROUTINE", lpStartAddress, "LPVOID", lpParameter, "DWORD", dwCreationFlags, "LPDWORD", lpThreadId, NULL);
	Thread *thread = new Thread();
	if (NULL == thread) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		if (NULL != lpThreadAttributes) WIN32API_INFO("\tignore lpThreadAttributes: $%08x\n", lpThreadAttributes);
		if (0 != dwStackSize) WIN32API_INFO("\tignore dwStackSize: $%08x (BeOS can not change thread stack size.)\n", dwStackSize);
		if (B_OK == thread->Spawn(lpStartAddress, lpParameter)) {
			if (0 == (dwCreationFlags & CREATE_SUSPEND)) {
				if (thread->Resume() < B_OK) {
					WIN32API_INFO("\tcan not resume thread\n");
					delete thread;
					thread = NULL;
				}
			} else dwCreationFlags &= ~CREATE_SUSPEND;
			if (0 != dwCreationFlags) WIN32API_INFO("\tunknown dwCreationFlags: $%08x\n", dwCreationFlags);
			if ((NULL != thread) && (NULL != lpThreadId)) *lpThreadId = thread->GetID();
		} else {
			WIN32API_INFO("\tcan not spawn thread\n");
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			delete thread;
		}
		rc = (HANDLE)thread;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
ExitThread
(DWORD dwExitCode)
{
	WIN32API_ENTER("void", "ExitThread", "DWORD", dwExitCode, NULL);
	Thread *thread = Thread::GetCurrentThreadObject();
	if (NULL != thread) {
		thread->SetExitCode(dwExitCode);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(0);
	exit_thread((status_t)dwExitCode);
}

extern "C" void WINAPI
FreeLibraryAndExitThread
(HMODULE hModule, DWORD dwExitCode)
{
	WIN32API_ENTER("void", "FreeLibraryAndExitThread", "HMODULE", hModule, "DWORD", dwExitCode, NULL);
	FreeLibrary(hModule);
	Thread *thread = Thread::GetCurrentThreadObject();
	if (NULL != thread) {
		thread->SetExitCode(dwExitCode);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(0);
	exit_thread((status_t)dwExitCode);
}

extern "C" HANDLE WINAPI
GetCurrentThread
(VOID)
{
	HANDLE rc = NULL;
	WIN32API_ENTER("HANDLE", "GetCurrentThread", NULL);
	rc = (HANDLE)Thread::GetCurrentThreadObject();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCurrentThreadId
(VOID)
{
	WIN32API_ENTER("DWORD", "GetCurrentThreadId", NULL);
	DWORD rc = Thread::GetCurrentThreadId();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetExitCodeThread
(HANDLE handle, LPDWORD lpExitCode)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpExitCode);
	WIN32API_ENTER("BOOL", "GetExitCodeThread", "HANDLE", handle, "LPDWORD", lpExitCode, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, handle);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		rc = thread->GetExitCode();
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetThreadContext
(HANDLE handle, LPCONTEXT lpContext)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpContext);
	WIN32API_ENTER("BOOL", "GetThreadContext", "HANDLE", handle, "LPCONTEXT", lpContext, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LCID WINAPI
GetThreadLocale
(void)
{
	LCID rc = 0;
	WIN32API_ENTER("LCID", "GetThreadLocale", "void", NULL);
	Thread *thread = Thread::GetCurrentThreadObject();
	if (NULL != thread) {
		rc = thread->GetLocale();
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetThreadPriority
(HANDLE hThread)
{
	int rc = THREAD_PRIORITY_ERROR_RETURN;
	WIN32API_ENTER("int", "GetThreadPriority", "HANDLE", hThread, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, hThread);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		rc = thread->GetPriority();
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetThreadPriorityBoost
(HANDLE hThread, PBOOL pDisablePriorityBoost)
{
	BOOL rc = TRUE;
	WIN32API_POINTER(pDisablePriorityBoost);
	WIN32API_ENTER("BOOL", "GetThreadPriorityBoost", "HANDLE", hThread, "PBOOL", pDisablePriorityBoost, NULL);
	if (NULL == pDisablePriorityBoost) *pDisablePriorityBoost = TRUE;
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetThreadSelectorEntry
(HANDLE hThread, DWORD dwSelector, LPLDT_ENTRY lpSelectorEntry)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpSelectorEntry);
	WIN32API_ENTER("BOOL", "GetThreadSelectorEntry", "HANDLE", hThread, "DWORD", dwSelector, "LPLDT_ENTRY", lpSelectorEntry, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetThreadTimes
(HANDLE hThread, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpCreationTime);
	WIN32API_POINTER(lpExitTime);
	WIN32API_POINTER(lpKernelTime);
	WIN32API_POINTER(lpUserTime);
	WIN32API_ENTER("BOOL", "GetThreadTimes", "HANDLE", hThread, "LPFILETIME", lpCreationTime, "LPFILETIME", lpExitTime, "LPFILETIME", lpKernelTime, "LPFILETIME", lpUserTime, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, hThread);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		thread->GetTimes(lpCreationTime, lpExitTime, lpKernelTime, lpUserTime);
		WIN32API_ERROR(ERROR_SUCCESS);
		rc = TRUE;
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
ResumeThread
(HANDLE hThread)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "ResumeThread", "HANDLE", hThread, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, hThread);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		status_t rv = thread->Resume();
		if (rv >= B_OK) {
			rc = rv;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetThreadAffinityMask
(HANDLE hThread, DWORD dwThreadAffinityMask)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "SetThreadAffinityMask", "HANDLE", hThread, "DWORD", dwThreadAffinityMask, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetThreadContext
(HANDLE hThread, const CONTEXT* lpContext)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetThreadContext", "HANDLE", hThread, "const CONTEXT*", lpContext, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetThreadIdealProcessor
(HANDLE arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SetThreadIdealProcessor", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetThreadLocale
(LCID Locale)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetThreadLocale", "LCID", Locale, NULL);
	Thread *thread = Thread::GetCurrentThreadObject();
	if (NULL != thread) {
		thread->SetLocale(Locale);
		WIN32API_ERROR(ERROR_SUCCESS);
		rc = TRUE;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetThreadPriority
(HANDLE hThread, int nPriority)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetThreadPriority", "HANDLE", hThread, "int", nPriority, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, hThread);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		thread->SetPriority(nPriority);
		WIN32API_ERROR(ERROR_SUCCESS);
		rc = TRUE;
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetThreadPriorityBoost
(HANDLE hThread, BOOL DisablePriorityBoost)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetThreadPriorityBoost", "HANDLE", hThread, "BOOL", DisablePriorityBoost, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SuspendThread
(HANDLE hThread)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SuspendThread", "HANDLE", hThread, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, hThread);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		status_t rv = thread->Suspend();
		if (rv >= B_OK) {
			rc = rv;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SwitchToThread
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SwitchToThread", "void", 0, NULL);
	rc = (B_OK == snooze(0))? TRUE: FALSE;
	if (TRUE == rc) WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TerminateThread
(HANDLE hThread, DWORD dwExitCode)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TerminateThread", "HANDLE", hThread, "DWORD", dwExitCode, NULL);
	Thread *thread = REINTERPRET_CAST(Thread *, hThread);
	if ((NULL != thread) && (thread->magic == THREAD_MAGIC)) {
		thread->SetExitCode(dwExitCode);
		rc = (B_OK == kill_thread(thread->GetID()))? TRUE: FALSE;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}
