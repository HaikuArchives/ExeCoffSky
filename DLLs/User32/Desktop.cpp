/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Desktop.cpp,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Desktop.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Desktop.h"
#include "Win32Trace.h"
#include "Win32Error.h"

DesktopWindow::DesktopWindow
(void)
{
}

DesktopWindow::~DesktopWindow
(void)
{
}

DeviceContext *
DesktopWindow::GetDeviceContext
(void) const
{
	return &((DesktopWindow *)this)->dc;
}

bool
DesktopWindow::Show
(bool show)
{
	WIN32API_INFO("\tcan not show/hide desktop.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return false;
}

bool
DesktopWindow::GetTitle
(LPSTR lpTitle, UINT &uSize)
{
	WIN32API_INFO("\tcan not get desktop title.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return false;
}

bool
DesktopWindow::SetTitle
(LPCSTR lpTitle)
{
	WIN32API_INFO("\tcan not set desktop title.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return false;
}

BOOL
DesktopWindow::GetWindowRect
(LPRECT lpRect)
{
	BScreen scr;
	BRect rect = scr.Frame();
	lpRect->left = 0;
	lpRect->top = 0;
	lpRect->right = (LONG)rect.Width();
	lpRect->bottom = (LONG)rect.Height();
	return TRUE;
}

BOOL
DesktopWindow::SetWindowPos
(HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
	WIN32API_INFO("\tcan not set desktop window pos.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return FALSE;
}

LRESULT
DesktopWindow::SendMessage
(LPCMSG lpMsg)
{
	WIN32API_INFO("\tcan not send message to desktop window.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return 0;
}

LRESULT
DesktopWindow::SendMessage
(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_INFO("\tcan not send message to desktop window.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return 0;
}

BOOL
DesktopWindow::PostMessage
(LPCMSG lpMsg)
{
	WIN32API_INFO("\tcan not post message to desktop window.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return FALSE;
}

BOOL
DesktopWindow::PostMessage
(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_INFO("\tcan not post message to desktop window.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	return FALSE;
}

void
DesktopWindow::ClientToScreen
(LPPOINT lpPoint)
{
}

void
DesktopWindow::ScreenToClient
(LPPOINT lpPoint)
{
}

extern "C" HWND WINAPI
GetDesktopWindow
(void)
{
	static DesktopWindow desktop;
	HWND rc = (HWND)&desktop;
	WIN32API_ENTER("HWND", "GetDesktopWindow", "void", 0, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}
