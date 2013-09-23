/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Message.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Message.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Message.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Kernel32/Thread.h"
#include "Kernel32/Process.h"
#include "Window.h"

LRESULT
DispatchMessageU
(LPCMSG lpMsg)
{
	LRESULT rc = 0;
	if (lpMsg->hwnd != NULL) {
		WIN32API_INFO("\thwnd = %p\n", lpMsg->hwnd);
		WIN32API_INFO("\tmessage = 0x%08x\n", lpMsg->message);
		WIN32API_INFO("\twParam = 0x%08x\n", lpMsg->wParam);
		WIN32API_INFO("\tlParam = 0x%08x\n", lpMsg->lParam);
		Window *window = Window::HandleToWindow(lpMsg->hwnd);
		if (NULL != window) rc = window->SendMessage(lpMsg);
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_INFO("\tnot impl.\n");
		WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	}
	return rc;
}

BOOL
GetMessageU
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
	BOOL rc = FALSE;
	Thread *thread = Thread::GetCurrentThreadObject();
	rc = thread->CheckMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, true, true);
	WIN32API_INFO("\thwnd = %p\n", lpMsg->hwnd);
	WIN32API_INFO("\tmessage = 0x%08x\n", lpMsg->message);
	WIN32API_INFO("\twParam = 0x%08x\n", lpMsg->wParam);
	WIN32API_INFO("\tlParam = 0x%08x\n", lpMsg->lParam);
	if (lpMsg->message == WM_QUIT) rc = FALSE;
	WIN32API_ERROR(ERROR_SUCCESS);
	return rc;
}

BOOL
PeekMessageU
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
	BOOL rc = FALSE;
	Thread *thread = Thread::GetCurrentThreadObject();
	rc = thread->CheckMessage(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, PM_NOREMOVE != wRemoveMsg);
	if (TRUE == rc) {
		WIN32API_INFO("\thwnd = %p\n", lpMsg->hwnd);
		WIN32API_INFO("\tmessage = 0x%08x\n", lpMsg->message);
		WIN32API_INFO("\twParam = 0x%08x\n", lpMsg->wParam);
		WIN32API_INFO("\tlParam = 0x%08x\n", lpMsg->lParam);
	} else {
		WIN32API_INFO("\tmessage queue is empty.\n");
	}
	WIN32API_ERROR(ERROR_SUCCESS);
	return rc;
}

BOOL
PostMessageU
(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	BOOL rc = FALSE;
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		rc = window->PostMessage(Msg, wParam, lParam);
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	return rc;
}

LRESULT
SendMessageU
(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc = 0;
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		rc = window->SendMessage(Msg, wParam, lParam);
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_INFO("\tnot impl.\n");
		WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	}
	return rc;
}

BOOL
PostThreadMessageU
(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	Thread *thread = Thread::GetThreadObject(idThread);
	if (NULL == thread) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
		return FALSE;
	}
	thread->PostMessage(Msg, wParam, lParam);
	return TRUE;
}

extern "C" long WINAPI
BroadcastSystemMessage
(DWORD arg0, LPDWORD arg1, UINT arg2, WPARAM arg3, LPARAM arg4)
{
	long rc = (long)-1;
	WIN32API_ENTER("long", "BroadcastSystemMessage", "DWORD", arg0, "LPDWORD", arg1, "UINT", arg2, "WPARAM", arg3, "LPARAM", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DispatchMessageA
(LPCMSG lpMsg)
{
	WIN32API_ENTER("LRESULT", "DispatchMessageA", "LPCMSG", lpMsg, NULL);
	LRESULT rc = DispatchMessageU(lpMsg);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DispatchMessageW
(LPCMSG lpMsg)
{
	WIN32API_ENTER("LONG", "DispatchMessageW", "const MSG*", lpMsg, NULL);
	LRESULT rc = DispatchMessageU(lpMsg);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetMessageA
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
	WIN32API_ENTER("BOOL", "GetMessageA", "LPMSG", lpMsg, "HWND", hWnd, "UINT", wMsgFilterMin, "UINT", wMsgFilterMax, NULL);
	BOOL rc = GetMessageU(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetMessageW
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
	WIN32API_ENTER("BOOL", "GetMessageW", "LPMSG", lpMsg, "HWND", hWnd, "UINT", wMsgFilterMin, "UINT", wMsgFilterMax, NULL);
	BOOL rc = GetMessageU(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
GetMessageExtraInfo
(void)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "GetMessageExtraInfo", "void", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetMessagePos
(void)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetMessagePos", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
GetMessageTime
(void)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "GetMessageTime", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InSendMessage
(VOID)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InSendMessage", "VOID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PeekMessageA
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
	WIN32API_ENTER("BOOL", "PeekMessageA", "LPMSG", lpMsg, "HWND", hWnd, "UINT", wMsgFilterMin, "UINT", wMsgFilterMax, "UINT", wRemoveMsg, NULL);
	BOOL rc = PeekMessageU(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PeekMessageW
(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
	WIN32API_ENTER("BOOL", "PeekMessageW", "LPMSG", lpMsg, "HWND", hWnd, "UINT", wMsgFilterMin, "UINT", wMsgFilterMax, "UINT", wRemoveMsg, NULL);
	BOOL rc = PeekMessageU(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PostMessageA
(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("BOOL", "PostMessageA", "HWND", hWnd, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	BOOL rc = PostMessageU(hWnd, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PostMessageW
(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("BOOL", "PostMessageW", "HWND", hWnd, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	BOOL rc = PostMessageU(hWnd, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
PostQuitMessage
(int nExitCode)
{
	WIN32API_ENTER("VOID", "PostQuitMessage", "int", nExitCode, NULL);
	Process *process = Process::GetCurrentProcessObject();
	Thread *thread = process->GetMainThread();
	thread->PostMessage(WM_QUIT, nExitCode, 0);
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
PostThreadMessageA
(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("BOOL", "PostThreadMessageA", "DWORD", idThread, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	BOOL rc = PostThreadMessageU(idThread, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PostThreadMessageW
(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("BOOL", "PostThreadMessageW", "DWORD", idThread, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	BOOL rc = PostThreadMessageU(idThread, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReplyMessage
(LRESULT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReplyMessage", "LRESULT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendMessageA
(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("LRESULT", "SendMessageA", "HWND", hWnd, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	LRESULT rc = SendMessageU(hWnd, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendMessageW
(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("LRESULT", "SendMessageW", "HWND", hWnd, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	LRESULT rc = SendMessageU(hWnd, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SendMessageCallbackA
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3, SENDASYNCPROC arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SendMessageCallbackA", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, "SENDASYNCPROC", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SendMessageCallbackW
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3, SENDASYNCPROC arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SendMessageCallbackW", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, "SENDASYNCPROC", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendMessageTimeoutA
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3, UINT arg4, UINT arg5, PDWORD arg6)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "SendMessageTimeoutA", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, "UINT", arg4, "UINT", arg5, "PDWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendMessageTimeoutW
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3, UINT arg4, UINT arg5, PDWORD arg6)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "SendMessageTimeoutW", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, "UINT", arg4, "UINT", arg5, "PDWORD", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SendNotifyMessageA
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SendNotifyMessageA", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SendNotifyMessageW
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SendNotifyMessageW", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPARAM WINAPI
SetMessageExtraInfo
(LPARAM arg0)
{
	LPARAM rc = (LPARAM)-1;
	WIN32API_ENTER("LPARAM", "SetMessageExtraInfo", "LPARAM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMessageQueue
(int arg0)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "SetMessageQueue", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TranslateMessage
(LPCMSG lpMsg)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TranslateMessage", "LPCMSG", lpMsg, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}
