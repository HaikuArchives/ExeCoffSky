/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Timer.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Timer.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Timer.h"
#include "Window.h"
#include "Thread.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Timer::Timer
(HWND hWnd, UINT nIDEvent, UINT nElapse, TIMERPROC lpTimerFunc):
elapse(nElapse),
counter(0),
event(true),
id(nIDEvent),
hWnd(hWnd),
lpTimerFunc(lpTimerFunc)
{
	WIN32API_INFO("\thWnd: $%08x\n", hWnd);
	WIN32API_INFO("\tnIDEvent: $%08x\n", nIDEvent);
	WIN32API_INFO("\tnElapse: $%08x\n", nElapse);
	WIN32API_INFO("\tlpTimerFunc: $%08x\n", lpTimerFunc);
	bigtime_t now = system_time();
	WIN32API_INFO("\tcurrent time: $%08x%08x\n", (UINT)(now >> 32), (UINT)(now & 0xffffffff));
	next = now + elapse * 1000;
}

void
Timer::Set
(port_id port)
{
	this->port = port;
}

void
Timer::Check
(bigtime_t *now)
{
	if (next > *now) return;
	Invoke();
	while (next < *now) next += elapse * 1000;
}

void
Timer::Invoke
(void)
{
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) return;
	window->PostMessage(WM_TIMER, (WPARAM)id, (LPARAM)lpTimerFunc);
}

extern "C" UINT WINAPI
SetTimer
(HWND hWnd, UINT nIDEvent, UINT nElapse, TIMERPROC lpTimerFunc)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "SetTimer", "HWND", hWnd, "UINT", nIDEvent, "UINT", nElapse, "TIMERPROC", lpTimerFunc, NULL);
	if (NULL == hWnd) {
		WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
		WIN32API_INFO("\tnot impl.\n");
	} else {
		Window *window = Window::HandleToWindow(hWnd);
		if (NULL == window) {
			WIN32API_ERROR(ERROR_INVALID_HANDLE);
		} else {
			if (NULL != lpTimerFunc) WIN32API_INFO("\ttimerproc not impl.\n");
			Timer *timer = new Timer(hWnd, nIDEvent, nElapse, lpTimerFunc);
			if (NULL != timer) {
				Thread *thread = Thread::GetCurrentThreadObject();
				if ((NULL != thread) && thread->SetTimer(timer)) {
					rc = nIDEvent;
					window->AddTimer(timer);
					WIN32API_ERROR(ERROR_SUCCESS);
				} else {
					delete timer;
				}
			} else {
				WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			}
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
KillTimer
(HWND hWnd, UINT nIDEvent)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "KillTimer", "HWND", hWnd, "UINT", nIDEvent, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		Timer *timer = window->FindTimer(nIDEvent);
		if (NULL != timer) {
			Thread *thread = Thread::GetCurrentThreadObject();
			if ((NULL != thread) && thread->KillTimer(timer)) {
				rc = TRUE;
				window->RemoveTimer(timer);
				delete timer;
				WIN32API_ERROR(ERROR_SUCCESS);
			}
		} else {
			WIN32API_ERROR(ERROR_BAD_ARGUMENTS);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}
