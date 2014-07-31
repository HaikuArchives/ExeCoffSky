/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: User32.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [User32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "User32.h"
#include "Win32Trace.h"
#include "Window.h"
#include "Process.h"

extern "C" int
wsprintfA
(LPTSTR lpOut, LPCTSTR lpFmt, ...)
{
	int rc = 0;
	WIN32API_POINTER(lpOut);
	WIN32API_POINTER(lpFmt);
	WIN32API_ENTER("int", "wsprintfA", "LPTSTR", lpOut, "LPCTSTR", lpFmt, "...", NULL, NULL);
	WIN32API_INFO("lpFmt: %s\n", (char *)lpFmt);
	va_list list;
	va_start(list, lpFmt);
	for (const char *p = strchr(lpFmt, '%') + 1; (void *)1 != p; p = strchr(p, '%') + 1) {
		// 不完全だけど、無いよりはマシ
		char **ptr = ((char **)(list += sizeof(char *))) - 1;
		if ('s' == *p) {
			if (___dynreloc) Win32Trace::Relocate((void **)ptr);
			WIN32API_INFO("string ptr: $%08x\n", *ptr);
			WIN32API_INFO("string str: %s\n", *ptr);
		} else WIN32API_INFO("%c:\n", *p);
	}
	va_end(list);
	va_start(list, lpFmt);
	rc = vsprintf((char *)lpOut, (char *)lpFmt, list);
	WIN32API_INFO("lpOut: %s\n", (char *)lpOut);
	va_end(list);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MessageBeep
(UINT uType)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MessageBeep", "UINT", uType, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawMenuBar
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawMenuBar", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCursorPos
(int X, int Y)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "SetCursorPos", "int", X, "int", Y, NULL);
	set_mouse_position(X, Y);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SHORT WINAPI
GetAsyncKeyState
(int vKey)
{
	SHORT rc = 0;
	WIN32API_ENTER("SHORT", "GetAsyncKeyState", "int", vKey, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InvalidateRect
(HWND hWnd, LPCRECT lpRect, BOOL bErase)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InvalidateRect", "HWND", hWnd, "LPCRECT", lpRect, "BOOL", bErase, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetFocus
(VOID)
{
	HWND rc = (HWND)-1;
	WIN32API_ENTER("HWND", "GetFocus", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDisplaySettingsA
(LPCTSTR lpszDeviceName, DWORD iModeNum, LPDEVMODE lpDevMode)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDisplaySettingsA", "LPCTSTR", lpszDeviceName, "DWORD", iModeNum, "LPDEVMODE", lpDevMode, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
ChangeDisplaySettingsA
(LPDEVMODE lpDevMode, DWORD dwFlags)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "ChangeDisplaySettingsA", "LPDEVMODE", lpDevMode, "DWORD", dwFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsZoomed
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsZoomed", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetWindow
(HWND hWnd, UINT uCmd)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "GetWindow", "HWND", hWnd, "UINT", uCmd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCursorPos
(LPPOINT lpPoint)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpPoint);
	WIN32API_ENTER("BOOL", "GetCursorPos", "LPPOINT", lpPoint, NULL);
	static BWindow *window = NULL;
	static BView *view = NULL;
	if (NULL == window) {
		window = new BWindow(BRect(0, 0, 0, 0), "GetCursorPos", B_NO_BORDER_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL, 0);
		if (NULL != window) {
			if (NULL != view) window->AddChild(view);
			window->Run();
		}
	}
	if (NULL == view) {
		view = new BView(BRect(0, 0, 0, 0), "GetCursorPos", 0, 0);
		if (NULL != view) {
			view->SetEventMask(B_POINTER_EVENTS);
			if (NULL != window) {
				window->Lock();
				window->AddChild(view);
				window->Unlock();
			}
		}
	}
	if ((NULL != window) && (NULL != view)) {
		rc = TRUE;
		BPoint pt;
		uint32 buttons;
		window->Lock();
		view->GetMouse(&pt, &buttons);
		window->Unlock();
		WIN32API_INFO("\t(%f,%f)\n", pt.x, pt.y);
		lpPoint->x = (int)pt.x;
		lpPoint->y = (int)pt.y;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ReleaseCapture
(VOID)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ReleaseCapture", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
SetCapture
(HWND hWnd)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "SetCapture", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMenu
(HWND hWnd, HMENU hMenu)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "SetMenu", "HWND", hWnd, "HMENU", hMenu, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
SetCursor
(HCURSOR hCursor)
{
	HCURSOR rc = NULL;
	WIN32API_ENTER("HCURSOR", "SetCursor", "HCURSOR", hCursor, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ShowCursor
(BOOL bShow)
{
	static int rc = 0;
	WIN32API_ENTER("int", "ShowCursor", "BOOL", bShow, NULL);
	if (TRUE == bShow) rc++;
	else rc--;
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteMenu
(HMENU hMenu, UINT uPosition, UINT uFlags)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteMenu", "HMENU", hMenu, "UINT", uPosition, "UINT", uFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
GetSystemMenu
(HWND hWnd, BOOL bRevert)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "GetSystemMenu", "HWND", hWnd, "BOOL", bRevert, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetRect
(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "SetRect", "LPRECT", lprc, "int", xLeft, "int", yTop, "int", xRight, "int", yBottom, NULL);
	lprc->left = xLeft;
	lprc->top = yTop;
	lprc->right = xRight;
	lprc->bottom = yBottom;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HKL WINAPI
ActivateKeyboardLayout
(HKL arg0, UINT arg1)
{
	HKL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HKL", "ActivateKeyboardLayout", "HKL", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AnyPopup
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AnyPopup", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
ArrangeIconicWindows
(HWND arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "ArrangeIconicWindows", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AttachThreadInput
(DWORD arg0, DWORD arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AttachThreadInput", "DWORD", arg0, "DWORD", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDWP WINAPI
BeginDeferWindowPos
(int arg0)
{
	HDWP rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDWP", "BeginDeferWindowPos", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CallMsgFilter
(PMSG arg0, int arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CallMsgFilter", "PMSG", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
CallNextHookEx
(HHOOK arg0, int arg1, WPARAM arg2, LPARAM arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "CallNextHookEx", "HHOOK", arg0, "int", arg1, "WPARAM", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WORD WINAPI
CascadeWindows
(HWND arg0, UINT arg1, LPCRECT arg2, UINT arg3, const HWND* arg4)
{
	WORD rc = (WORD)-1;
	WIN32API_ENTER("WORD", "CascadeWindows", "HWND", arg0, "UINT", arg1, "LPCRECT", arg2, "UINT", arg3, "const HWND*", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ChangeClipboardChain
(HWND arg0, HWND arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChangeClipboardChain", "HWND", arg0, "HWND", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
ChangeDisplaySettingsW
(PDEVMODEW arg0, DWORD arg1)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "ChangeDisplaySettingsW", "PDEVMODEW", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
CharLowerA
(LPSTR arg0)
{
	LPSTR rc = NULL;
	WIN32API_ENTER("LPSTR", "CharLowerA", "LPSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
CharLowerBuffA
(LPSTR arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "CharLowerBuffA", "LPSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
CharLowerBuffW
(LPWSTR arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "CharLowerBuffW", "LPWSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
CharLowerW
(LPWSTR arg0)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "CharLowerW", "LPWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
CharNextA
(LPCSTR arg0)
{
	LPSTR rc = (LPSTR)arg0;
	if (0 != *rc) rc++;
	WIN32API_ENTER("LPSTR", "CharNextA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
CharNextExA
(WORD arg0, LPCSTR arg1, DWORD arg2)
{
	LPSTR rc = NULL;
	WIN32API_ENTER("LPSTR", "CharNextExA", "WORD", arg0, "LPCSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
CharNextW
(LPCWSTR arg0)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "CharNextW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
CharPrevA
(LPCSTR arg0, LPCSTR arg1)
{
	LPSTR rc = (LPSTR)arg1;
	if (arg0 != rc) rc--;
	WIN32API_ENTER("LPSTR", "CharPrevA", "LPCSTR", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
CharPrevExA
(WORD arg0, LPCSTR arg1, LPCSTR arg2, DWORD arg3)
{
	LPSTR rc = NULL;
	WIN32API_ENTER("LPSTR", "CharPrevExA", "WORD", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
CharPrevW
(LPCWSTR arg0, LPCWSTR arg1)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "CharPrevW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CharToOemA
(LPCSTR arg0, LPSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CharToOemA", "LPCSTR", arg0, "LPSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CharToOemBuffA
(LPCSTR arg0, LPSTR arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CharToOemBuffA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CharToOemBuffW
(LPCWSTR arg0, LPSTR arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CharToOemBuffW", "LPCWSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CharToOemW
(LPCWSTR arg0, LPSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CharToOemW", "LPCWSTR", arg0, "LPSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPSTR WINAPI
CharUpperA
(LPSTR arg0)
{
	LPSTR rc = NULL;
	WIN32API_ENTER("LPSTR", "CharUpperA", "LPSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
CharUpperBuffA
(LPSTR arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "CharUpperBuffA", "LPSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
CharUpperBuffW
(LPWSTR arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "CharUpperBuffW", "LPWSTR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPWSTR WINAPI
CharUpperW
(LPWSTR arg0)
{
	LPWSTR rc = NULL;
	WIN32API_ENTER("LPWSTR", "CharUpperW", "LPWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ClipCursor
(LPCRECT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ClipCursor", "LPCRECT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseClipboard
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseClipboard", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseDesktop
(HDESK arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseDesktop", "HDESK", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseWindowStation
(HWINSTA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseWindowStation", "HWINSTA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
CopyAcceleratorTableA
(HACCEL arg0, LPACCEL arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "CopyAcceleratorTableA", "HACCEL", arg0, "LPACCEL", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
CopyAcceleratorTableW
(HACCEL arg0, LPACCEL arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "CopyAcceleratorTableW", "HACCEL", arg0, "LPACCEL", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
CopyIcon
(HICON arg0)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "CopyIcon", "HICON", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
CopyImage
(HANDLE arg0, UINT arg1, int arg2, int arg3, UINT arg4)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "CopyImage", "HANDLE", arg0, "UINT", arg1, "int", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CopyRect
(LPRECT arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CopyRect", "LPRECT", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
CountClipboardFormats
(void)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "CountClipboardFormats", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HACCEL WINAPI
CreateAcceleratorTableA
(LPACCEL arg0, int arg1)
{
	HACCEL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HACCEL", "CreateAcceleratorTableA", "LPACCEL", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HACCEL WINAPI
CreateAcceleratorTableW
(LPACCEL arg0, int arg1)
{
	HACCEL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HACCEL", "CreateAcceleratorTableW", "LPACCEL", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateCaret
(HWND arg0, HBITMAP arg1, int arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateCaret", "HWND", arg0, "HBITMAP", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
CreateCursor
(HINSTANCE arg0, int arg1, int arg2, int arg3, int arg4, PCVOID arg5, PCVOID arg6)
{
	HCURSOR rc = (HCURSOR)0x80000000;
	WIN32API_ENTER("HCURSOR", "CreateCursor", "HINSTANCE", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "PCVOID", arg5, "PCVOID", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDESK WINAPI
CreateDesktopA
(LPSTR arg0, LPSTR arg1, LPDEVMODEA arg2, DWORD arg3, DWORD arg4, LPSECURITY_ATTRIBUTES arg5)
{
	HDESK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDESK", "CreateDesktopA", "LPSTR", arg0, "LPSTR", arg1, "LPDEVMODEA", arg2, "DWORD", arg3, "DWORD", arg4, "LPSECURITY_ATTRIBUTES", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDESK WINAPI
CreateDesktopW
(LPWSTR arg0, LPWSTR arg1, LPDEVMODEW arg2, DWORD arg3, DWORD arg4, LPSECURITY_ATTRIBUTES arg5)
{
	HDESK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDESK", "CreateDesktopW", "LPWSTR", arg0, "LPWSTR", arg1, "LPDEVMODEW", arg2, "DWORD", arg3, "DWORD", arg4, "LPSECURITY_ATTRIBUTES", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
CreateIcon
(HINSTANCE arg0, int arg1, int arg2, BYTE arg3, BYTE arg4, const BYTE* arg5, const BYTE* arg6)
{
	HICON rc = NULL;
	WIN32API_ENTER("HICON", "CreateIcon", "HINSTANCE", arg0, "int", arg1, "int", arg2, "BYTE", arg3, "BYTE", arg4, "const BYTE*", arg5, "const BYTE*", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
CreateIconFromResource
(PBYTE arg0, DWORD arg1, BOOL arg2, DWORD arg3)
{
	HICON rc = NULL;
	WIN32API_ENTER("HICON", "CreateIconFromResource", "PBYTE", arg0, "DWORD", arg1, "BOOL", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
CreateIconFromResourceEx
(PBYTE arg0, DWORD arg1, BOOL arg2, DWORD arg3, int arg4, int arg5, UINT arg6)
{
	HICON rc = NULL;
	WIN32API_ENTER("HICON", "CreateIconFromResourceEx", "PBYTE", arg0, "DWORD", arg1, "BOOL", arg2, "DWORD", arg3, "int", arg4, "int", arg5, "UINT", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
CreateIconIndirect
(PICONINFO arg0)
{
	HICON rc = (HICON)0x80000000;
	WIN32API_ENTER("HICON", "CreateIconIndirect", "PICONINFO", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateMDIWindowA
(LPSTR arg0, LPSTR arg1, DWORD arg2, int arg3, int arg4, int arg5, int arg6, HWND arg7, HINSTANCE arg8, LPARAM arg9)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "CreateMDIWindowA", "LPSTR", arg0, "LPSTR", arg1, "DWORD", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "HWND", arg7, "HINSTANCE", arg8, "LPARAM", arg9, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateMDIWindowW
(LPWSTR arg0, LPWSTR arg1, DWORD arg2, int arg3, int arg4, int arg5, int arg6, HWND arg7, HINSTANCE arg8, LPARAM arg9)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "CreateMDIWindowW", "LPWSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "HWND", arg7, "HINSTANCE", arg8, "LPARAM", arg9, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWINSTA WINAPI
CreateWindowStationA
(LPSTR arg0, DWORD arg1, DWORD arg2, LPSECURITY_ATTRIBUTES arg3)
{
	HWINSTA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWINSTA", "CreateWindowStationA", "LPSTR", arg0, "DWORD", arg1, "DWORD", arg2, "LPSECURITY_ATTRIBUTES", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWINSTA WINAPI
CreateWindowStationW
(LPWSTR arg0, DWORD arg1, DWORD arg2, LPSECURITY_ATTRIBUTES arg3)
{
	HWINSTA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWINSTA", "CreateWindowStationW", "LPWSTR", arg0, "DWORD", arg1, "DWORD", arg2, "LPSECURITY_ATTRIBUTES", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeAbandonTransaction
(DWORD arg0, HCONV arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeAbandonTransaction", "DWORD", arg0, "HCONV", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" PBYTE WINAPI
DdeAccessData
(HDDEDATA arg0, PDWORD arg1)
{
	PBYTE rc = NULL;
	WIN32API_ENTER("PBYTE", "DdeAccessData", "HDDEDATA", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDDEDATA WINAPI
DdeAddData
(HDDEDATA arg0, PBYTE arg1, DWORD arg2, DWORD arg3)
{
	HDDEDATA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDDEDATA", "DdeAddData", "HDDEDATA", arg0, "PBYTE", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDDEDATA WINAPI
DdeClientTransaction
(PBYTE arg0, DWORD arg1, HCONV arg2, HSZ arg3, UINT arg4, UINT arg5, DWORD arg6, PDWORD arg7)
{
	HDDEDATA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDDEDATA", "DdeClientTransaction", "PBYTE", arg0, "DWORD", arg1, "HCONV", arg2, "HSZ", arg3, "UINT", arg4, "UINT", arg5, "DWORD", arg6, "PDWORD", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DdeCmpStringHandles
(HSZ arg0, HSZ arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DdeCmpStringHandles", "HSZ", arg0, "HSZ", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCONV WINAPI
DdeConnect
(DWORD arg0, HSZ arg1, HSZ arg2, PCONVCONTEXT arg3)
{
	HCONV rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCONV", "DdeConnect", "DWORD", arg0, "HSZ", arg1, "HSZ", arg2, "PCONVCONTEXT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCONVLIST WINAPI
DdeConnectList
(DWORD arg0, HSZ arg1, HSZ arg2, HCONVLIST arg3, PCONVCONTEXT arg4)
{
	HCONVLIST rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCONVLIST", "DdeConnectList", "DWORD", arg0, "HSZ", arg1, "HSZ", arg2, "HCONVLIST", arg3, "PCONVCONTEXT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDDEDATA WINAPI
DdeCreateDataHandle
(DWORD arg0, PBYTE arg1, DWORD arg2, DWORD arg3, HSZ arg4, UINT arg5, UINT arg6)
{
	HDDEDATA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDDEDATA", "DdeCreateDataHandle", "DWORD", arg0, "PBYTE", arg1, "DWORD", arg2, "DWORD", arg3, "HSZ", arg4, "UINT", arg5, "UINT", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HSZ WINAPI
DdeCreateStringHandleA
(DWORD arg0, LPCSTR arg1, int arg2)
{
	HSZ rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HSZ", "DdeCreateStringHandleA", "DWORD", arg0, "LPCSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HSZ WINAPI
DdeCreateStringHandleW
(DWORD arg0, LPCWSTR arg1, int arg2)
{
	HSZ rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HSZ", "DdeCreateStringHandleW", "DWORD", arg0, "LPCWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeDisconnect
(HCONV arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeDisconnect", "HCONV", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeDisconnectList
(HCONVLIST arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeDisconnectList", "HCONVLIST", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeEnableCallback
(DWORD arg0, HCONV arg1, UINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeEnableCallback", "DWORD", arg0, "HCONV", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeFreeDataHandle
(HDDEDATA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeFreeDataHandle", "HDDEDATA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeFreeStringHandle
(DWORD arg0, HSZ arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeFreeStringHandle", "DWORD", arg0, "HSZ", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
DdeGetData
(HDDEDATA arg0, PBYTE arg1, DWORD arg2, DWORD arg3)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "DdeGetData", "HDDEDATA", arg0, "PBYTE", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
DdeGetLastError
(DWORD arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "DdeGetLastError", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeImpersonateClient
(HCONV arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeImpersonateClient", "HCONV", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
DdeInitializeA
(PDWORD arg0, PFNCALLBACK arg1, DWORD arg2, DWORD arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "DdeInitializeA", "PDWORD", arg0, "PFNCALLBACK", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
DdeInitializeW
(PDWORD arg0, PFNCALLBACK arg1, DWORD arg2, DWORD arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "DdeInitializeW", "PDWORD", arg0, "PFNCALLBACK", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeKeepStringHandle
(DWORD arg0, HSZ arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeKeepStringHandle", "DWORD", arg0, "HSZ", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDDEDATA WINAPI
DdeNameService
(DWORD arg0, HSZ arg1, HSZ arg2, UINT arg3)
{
	HDDEDATA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDDEDATA", "DdeNameService", "DWORD", arg0, "HSZ", arg1, "HSZ", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdePostAdvise
(DWORD arg0, HSZ arg1, HSZ arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdePostAdvise", "DWORD", arg0, "HSZ", arg1, "HSZ", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
DdeQueryConvInfo
(HCONV arg0, DWORD arg1, PCONVINFO arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "DdeQueryConvInfo", "HCONV", arg0, "DWORD", arg1, "PCONVINFO", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCONV WINAPI
DdeQueryNextServer
(HCONVLIST arg0, HCONV arg1)
{
	HCONV rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCONV", "DdeQueryNextServer", "HCONVLIST", arg0, "HCONV", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
DdeQueryStringA
(DWORD arg0, HSZ arg1, LPSTR arg2, DWORD arg3, int arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "DdeQueryStringA", "DWORD", arg0, "HSZ", arg1, "LPSTR", arg2, "DWORD", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
DdeQueryStringW
(DWORD arg0, HSZ arg1, LPWSTR arg2, DWORD arg3, int arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "DdeQueryStringW", "DWORD", arg0, "HSZ", arg1, "LPWSTR", arg2, "DWORD", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCONV WINAPI
DdeReconnect
(HCONV arg0)
{
	HCONV rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCONV", "DdeReconnect", "HCONV", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeSetQualityOfService
(HWND arg0, const SECURITY_QUALITY_OF_SERVICE* arg1, PSECURITY_QUALITY_OF_SERVICE arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeSetQualityOfService", "HWND", arg0, "const SECURITY_QUALITY_OF_SERVICE*", arg1, "PSECURITY_QUALITY_OF_SERVICE", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeSetUserHandle
(HCONV arg0, DWORD arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeSetUserHandle", "HCONV", arg0, "DWORD", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeUnaccessData
(HDDEDATA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeUnaccessData", "HDDEDATA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DdeUninitialize
(DWORD arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DdeUninitialize", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefFrameProcA
(HWND arg0, HWND arg1, UINT arg2, WPARAM arg3, LPARAM arg4)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "DefFrameProcA", "HWND", arg0, "HWND", arg1, "UINT", arg2, "WPARAM", arg3, "LPARAM", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefFrameProcW
(HWND arg0, HWND arg1, UINT arg2, WPARAM arg3, LPARAM arg4)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "DefFrameProcW", "HWND", arg0, "HWND", arg1, "UINT", arg2, "WPARAM", arg3, "LPARAM", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefMDIChildProcA
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "DefMDIChildProcA", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefMDIChildProcW
(HWND arg0, UINT arg1, WPARAM arg2, LPARAM arg3)
{
	LRESULT rc = (LRESULT)-1;
	WIN32API_ENTER("LRESULT", "DefMDIChildProcW", "HWND", arg0, "UINT", arg1, "WPARAM", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDWP WINAPI
DeferWindowPos
(HDWP arg0, HWND arg1, HWND arg2, int arg3, int arg4, int arg5, int arg6, UINT arg7)
{
	HDWP rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDWP", "DeferWindowPos", "HDWP", arg0, "HWND", arg1, "HWND", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "UINT", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyAcceleratorTable
(HACCEL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyAcceleratorTable", "HACCEL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyCaret
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyCaret", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyCursor
(HCURSOR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyCursor", "HCURSOR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyIcon
(HICON arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyIcon", "HICON", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DragDetect
(HWND arg0, POINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DragDetect", "HWND", arg0, "POINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
DragObject
(HWND arg0, HWND arg1, UINT arg2, DWORD arg3, HCURSOR arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "DragObject", "HWND", arg0, "HWND", arg1, "UINT", arg2, "DWORD", arg3, "HCURSOR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawAnimatedRects
(HWND arg0, int arg1, LPCRECT arg2, LPCRECT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawAnimatedRects", "HWND", arg0, "int", arg1, "LPCRECT", arg2, "LPCRECT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawCaption
(HWND arg0, HDC arg1, LPCRECT arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawCaption", "HWND", arg0, "HDC", arg1, "LPCRECT", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawEdge
(HDC arg0, LPRECT arg1, UINT arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawEdge", "HDC", arg0, "LPRECT", arg1, "UINT", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawFocusRect
(HDC arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawFocusRect", "HDC", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawFrameControl
(HDC arg0, LPRECT arg1, UINT arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawFrameControl", "HDC", arg0, "LPRECT", arg1, "UINT", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawIcon
(HDC arg0, int arg1, int arg2, HICON arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawIcon", "HDC", arg0, "int", arg1, "int", arg2, "HICON", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawIconEx
(HDC arg0, int arg1, int arg2, HICON arg3, int arg4, int arg5, UINT arg6, HBRUSH arg7, UINT arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawIconEx", "HDC", arg0, "int", arg1, "int", arg2, "HICON", arg3, "int", arg4, "int", arg5, "UINT", arg6, "HBRUSH", arg7, "UINT", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawStateA
(HDC arg0, HBRUSH arg1, DRAWSTATEPROC arg2, LPARAM arg3, WPARAM arg4, int arg5, int arg6, int arg7, int arg8, UINT arg9)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawStateA", "HDC", arg0, "HBRUSH", arg1, "DRAWSTATEPROC", arg2, "LPARAM", arg3, "WPARAM", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, "UINT", arg9, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DrawStateW
(HDC arg0, HBRUSH arg1, DRAWSTATEPROC arg2, LPARAM arg3, WPARAM arg4, int arg5, int arg6, int arg7, int arg8, UINT arg9)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DrawStateW", "HDC", arg0, "HBRUSH", arg1, "DRAWSTATEPROC", arg2, "LPARAM", arg3, "WPARAM", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, "UINT", arg9, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DrawTextA
(HDC arg0, LPCSTR arg1, int arg2, LPRECT arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DrawTextA", "HDC", arg0, "LPCSTR", arg1, "int", arg2, "LPRECT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DrawTextExA
(HDC arg0, LPSTR arg1, int arg2, LPRECT arg3, UINT arg4, LPDRAWTEXTPARAMS arg5)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DrawTextExA", "HDC", arg0, "LPSTR", arg1, "int", arg2, "LPRECT", arg3, "UINT", arg4, "LPDRAWTEXTPARAMS", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DrawTextExW
(HDC arg0, LPWSTR arg1, int arg2, LPRECT arg3, UINT arg4, LPDRAWTEXTPARAMS arg5)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DrawTextExW", "HDC", arg0, "LPWSTR", arg1, "int", arg2, "LPRECT", arg3, "UINT", arg4, "LPDRAWTEXTPARAMS", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DrawTextW
(HDC arg0, LPCWSTR arg1, int arg2, LPRECT arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DrawTextW", "HDC", arg0, "LPCWSTR", arg1, "int", arg2, "LPRECT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EmptyClipboard
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EmptyClipboard", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnableScrollBar
(HWND arg0, UINT arg1, UINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnableScrollBar", "HWND", arg0, "UINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EndDeferWindowPos
(HDWP arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EndDeferWindowPos", "HDWP", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
EnumClipboardFormats
(UINT arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "EnumClipboardFormats", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDesktopWindows
(HDESK arg0, WNDENUMPROC arg1, LPARAM arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDesktopWindows", "HDESK", arg0, "ENUMWINDOWSPROC", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDesktopsA
(HWINSTA arg0, DESKTOPENUMPROCA arg1, LPARAM arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDesktopsA", "HWINSTA", arg0, "DESKTOPENUMPROCA", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDesktopsW
(HWINSTA arg0, DESKTOPENUMPROCW arg1, LPARAM arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDesktopsW", "HWINSTA", arg0, "DESKTOPENUMPROCW", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumDisplaySettingsW
(LPCWSTR arg0, DWORD arg1, PDEVMODEW arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumDisplaySettingsW", "LPCWSTR", arg0, "DWORD", arg1, "PDEVMODEW", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumPropsA
(HWND arg0, PROPENUMPROCA arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumPropsA", "HWND", arg0, "PROPENUMPROCA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumPropsExA
(HWND arg0, PROPENUMPROCEXA arg1, LPARAM arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumPropsExA", "HWND", arg0, "PROPENUMPROCEXA", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumPropsExW
(HWND arg0, PROPENUMPROCEXW arg1, LPARAM arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumPropsExW", "HWND", arg0, "PROPENUMPROCEXW", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumPropsW
(HWND arg0, PROPENUMPROCW arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumPropsW", "HWND", arg0, "PROPENUMPROCW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumThreadWindows
(DWORD arg0, WNDENUMPROC arg1, LPARAM arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumThreadWindows", "DWORD", arg0, "WNDENUMPROC", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumWindowStationsA
(WINSTAENUMPROCA arg0, LPARAM arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumWindowStationsA", "WINSTAENUMPROCA", arg0, "LPARAM", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumWindowStationsW
(WINSTAENUMPROCW arg0, LPARAM arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumWindowStationsW", "WINSTAENUMPROCW", arg0, "LPARAM", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EqualRect
(LPCRECT arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EqualRect", "LPCRECT", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ExcludeUpdateRgn
(HDC arg0, HWND arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ExcludeUpdateRgn", "HDC", arg0, "HWND", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ExitWindowsEx
(UINT arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ExitWindowsEx", "UINT", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
FillRect
(HDC arg0, LPCRECT arg1, HBRUSH arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FillRect", "HDC", arg0, "LPCRECT", arg1, "HBRUSH", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
FindWindowExA
(HWND arg0, HWND arg1, LPCSTR arg2, LPCSTR arg3)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "FindWindowExA", "HWND", arg0, "HWND", arg1, "LPCSTR", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
FindWindowExW
(HWND arg0, HWND arg1, LPCWSTR arg2, LPCWSTR arg3)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "FindWindowExW", "HWND", arg0, "HWND", arg1, "LPCWSTR", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
FindWindowW
(LPCWSTR arg0, LPCWSTR arg1)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "FindWindowW", "LPCWSTR", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FlashWindow
(HWND arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlashWindow", "HWND", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
FrameRect
(HDC arg0, LPCRECT arg1, HBRUSH arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FrameRect", "HDC", arg0, "LPCRECT", arg1, "HBRUSH", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FreeDDElParam
(UINT arg0, LONG arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FreeDDElParam", "UINT", arg0, "LONG", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetActiveWindow
(void)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetActiveWindow", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetCapture
(void)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetCapture", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetCaretBlinkTime
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetCaretBlinkTime", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCaretPos
(LPPOINT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCaretPos", "LPPOINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetClassInfoA
(HINSTANCE arg0, LPCSTR arg1, PWNDCLASSA arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetClassInfoA", "HINSTANCE", arg0, "LPCSTR", arg1, "PWNDCLASSA", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetClassInfoExA
(HINSTANCE arg0, LPCSTR arg1, PWNDCLASSEXA arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetClassInfoExA", "HINSTANCE", arg0, "LPCSTR", arg1, "PWNDCLASSEXA", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetClassInfoExW
(HINSTANCE arg0, LPCWSTR arg1, PWNDCLASSEXW arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetClassInfoExW", "HINSTANCE", arg0, "LPCWSTR", arg1, "PWNDCLASSEXW", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetClassInfoW
(HINSTANCE arg0, LPCWSTR arg1, PWNDCLASSW arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetClassInfoW", "HINSTANCE", arg0, "LPCWSTR", arg1, "PWNDCLASSW", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetClassLongA
(HWND arg0, int arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetClassLongA", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetClassLongW
(HWND arg0, int arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetClassLongW", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetClassNameA
(HWND arg0, LPSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetClassNameA", "HWND", arg0, "LPSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetClassNameW
(HWND arg0, LPWSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetClassNameW", "HWND", arg0, "LPWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WORD WINAPI
GetClassWord
(HWND arg0, int arg1)
{
	WORD rc = (WORD)-1;
	WIN32API_ENTER("WORD", "GetClassWord", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetClipCursor
(LPRECT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetClipCursor", "LPRECT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetClipboardData
(UINT arg0)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "GetClipboardData", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetClipboardFormatNameA
(UINT arg0, LPSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetClipboardFormatNameA", "UINT", arg0, "LPSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetClipboardFormatNameW
(UINT arg0, LPWSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetClipboardFormatNameW", "UINT", arg0, "LPWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetClipboardOwner
(void)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetClipboardOwner", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetClipboardViewer
(void)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetClipboardViewer", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
GetCursor
(void)
{
	HCURSOR rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCURSOR", "GetCursor", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
GetDCEx
(HWND arg0, HRGN arg1, DWORD arg2)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "GetDCEx", "HWND", arg0, "HRGN", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetDoubleClickTime
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetDoubleClickTime", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetForegroundWindow
(void)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetForegroundWindow", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetIconInfo
(HICON arg0, PICONINFO arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetIconInfo", "HICON", arg0, "PICONINFO", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetInputState
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetInputState", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetKBCodePage
(void)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetKBCodePage", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetKeyNameTextA
(LONG arg0, LPSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetKeyNameTextA", "LONG", arg0, "LPSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetKeyNameTextW
(LONG arg0, LPWSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetKeyNameTextW", "LONG", arg0, "LPWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SHORT WINAPI
GetKeyState
(int arg0)
{
	SHORT rc = (SHORT)-1;
	WIN32API_ENTER("SHORT", "GetKeyState", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HKL WINAPI
GetKeyboardLayout
(DWORD arg0)
{
	HKL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HKL", "GetKeyboardLayout", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetKeyboardLayoutList
(int arg0, HKL* arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetKeyboardLayoutList", "int", arg0, "HKL*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetKeyboardLayoutNameA
(LPSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetKeyboardLayoutNameA", "LPSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetKeyboardLayoutNameW
(LPWSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetKeyboardLayoutNameW", "LPWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetKeyboardState
(PBYTE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetKeyboardState", "PBYTE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetKeyboardType
(int arg0)
{
	int rc = 7;
	WIN32API_ENTER("int", "GetKeyboardType", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetLastActivePopup
(HWND arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetLastActivePopup", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
GetMenuCheckMarkDimensions
(void)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "GetMenuCheckMarkDimensions", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetOpenClipboardWindow
(void)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetOpenClipboardWindow", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetPriorityClipboardFormat
(UINT* arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetPriorityClipboardFormat", "UINT*", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWINSTA WINAPI
GetProcessWindowStation
(void)
{
	HWINSTA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWINSTA", "GetProcessWindowStation", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetPropA
(HWND arg0, LPCSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "GetPropA", "HWND", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetPropW
(HWND arg0, LPCWSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "GetPropW", "HWND", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetQueueStatus
(UINT arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetQueueStatus", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetScrollInfo
(HWND arg0, int arg1, LPSCROLLINFO arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetScrollInfo", "HWND", arg0, "int", arg1, "LPSCROLLINFO", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetScrollPos
(HWND arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetScrollPos", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetScrollRange
(HWND arg0, int arg1, LPINT arg2, LPINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetScrollRange", "HWND", arg0, "int", arg1, "LPINT", arg2, "LPINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetSysColor
(int arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetSysColor", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
GetSysColorBrush
(int arg0)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "GetSysColorBrush", "int", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTabbedTextExtentA
(HDC arg0, LPCSTR arg1, int arg2, int arg3, LPINT arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetTabbedTextExtentA", "HDC", arg0, "LPCSTR", arg1, "int", arg2, "int", arg3, "LPINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetTabbedTextExtentW
(HDC arg0, LPCWSTR arg1, int arg2, int arg3, LPINT arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetTabbedTextExtentW", "HDC", arg0, "LPCWSTR", arg1, "int", arg2, "int", arg3, "LPINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDESK WINAPI
GetThreadDesktop
(DWORD arg0)
{
	HDESK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDESK", "GetThreadDesktop", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetTopWindow
(HWND arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetTopWindow", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetUpdateRect
(HWND arg0, LPRECT arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetUpdateRect", "HWND", arg0, "LPRECT", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetUpdateRgn
(HWND arg0, HRGN arg1, BOOL arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetUpdateRgn", "HWND", arg0, "HRGN", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetUserObjectInformationA
(HANDLE arg0, int arg1, PVOID arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetUserObjectInformationA", "HANDLE", arg0, "int", arg1, "PVOID", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetUserObjectInformationW
(HANDLE arg0, int arg1, PVOID arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetUserObjectInformationW", "HANDLE", arg0, "int", arg1, "PVOID", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetUserObjectSecurity
(HANDLE arg0, PSECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, DWORD arg3, PDWORD arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetUserObjectSecurity", "HANDLE", arg0, "PSECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "DWORD", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetWindowContextHelpId
(HWND arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetWindowContextHelpId", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetWindowPlacement
(HWND arg0, WINDOWPLACEMENT* arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetWindowPlacement", "HWND", arg0, "WINDOWPLACEMENT*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GrayStringA
(HDC arg0, HBRUSH arg1, GRAYSTRINGPROC arg2, LPARAM arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GrayStringA", "HDC", arg0, "HBRUSH", arg1, "GRAYSTRINGPROC", arg2, "LPARAM", arg3, "int", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GrayStringW
(HDC arg0, HBRUSH arg1, GRAYSTRINGPROC arg2, LPARAM arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GrayStringW", "HDC", arg0, "HBRUSH", arg1, "GRAYSTRINGPROC", arg2, "LPARAM", arg3, "int", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HideCaret
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "HideCaret", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
HiliteMenuItem
(HWND arg0, HMENU arg1, UINT arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "HiliteMenuItem", "HWND", arg0, "HMENU", arg1, "UINT", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ImpersonateDdeClientWindow
(HWND arg0, HWND arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImpersonateDdeClientWindow", "HWND", arg0, "HWND", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InflateRect
(LPRECT arg0, int arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InflateRect", "LPRECT", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IntersectRect
(LPRECT arg0, LPCRECT arg1, LPCRECT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IntersectRect", "LPRECT", arg0, "LPCRECT", arg1, "LPCRECT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InvalidateRgn
(HWND arg0, HRGN arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InvalidateRgn", "HWND", arg0, "HRGN", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InvertRect
(HDC arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InvertRect", "HDC", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharAlphaA
(CHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharAlphaA", "CHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharAlphaNumericA
(CHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharAlphaNumericA", "CHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharAlphaNumericW
(WCHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharAlphaNumericW", "WCHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharAlphaW
(WCHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharAlphaW", "WCHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharLowerA
(CHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharLowerA", "CHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharLowerW
(WCHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharLowerW", "WCHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharUpperA
(CHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharUpperA", "CHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsCharUpperW
(WCHAR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsCharUpperW", "WCHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsChild
(HWND arg0, HWND arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsChild", "HWND", arg0, "HWND", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsClipboardFormatAvailable
(UINT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsClipboardFormatAvailable", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsRectEmpty
(LPCRECT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsRectEmpty", "LPCRECT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
LoadCursorFromFileA
(LPCSTR arg0)
{
	HCURSOR rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCURSOR", "LoadCursorFromFileA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
LoadCursorFromFileW
(LPCWSTR arg0)
{
	HCURSOR rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCURSOR", "LoadCursorFromFileW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HKL WINAPI
LoadKeyboardLayoutA
(LPCSTR arg0, UINT arg1)
{
	HKL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HKL", "LoadKeyboardLayoutA", "LPCSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HKL WINAPI
LoadKeyboardLayoutW
(LPCWSTR arg0, UINT arg1)
{
	HKL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HKL", "LoadKeyboardLayoutW", "LPCWSTR", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LockWindowUpdate
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LockWindowUpdate", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
LookupIconIdFromDirectory
(PBYTE arg0, BOOL arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "LookupIconIdFromDirectory", "PBYTE", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
LookupIconIdFromDirectoryEx
(PBYTE arg0, BOOL arg1, int arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "LookupIconIdFromDirectoryEx", "PBYTE", arg0, "BOOL", arg1, "int", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
MapVirtualKeyA
(UINT arg0, UINT arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "MapVirtualKeyA", "UINT", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
MapVirtualKeyExA
(UINT arg0, UINT arg1, HKL arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "MapVirtualKeyExA", "UINT", arg0, "UINT", arg1, "HKL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
MapVirtualKeyExW
(UINT arg0, UINT arg1, HKL arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "MapVirtualKeyExW", "UINT", arg0, "UINT", arg1, "HKL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
MapVirtualKeyW
(UINT arg0, UINT arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "MapVirtualKeyW", "UINT", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MapWindowPoints
(HWND arg0, HWND arg1, LPPOINT arg2, UINT arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "MapWindowPoints", "HWND", arg0, "HWND", arg1, "LPPOINT", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MenuItemFromPoint
(HWND arg0, HMENU arg1, POINT arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "MenuItemFromPoint", "HWND", arg0, "HMENU", arg1, "POINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
MsgWaitForMultipleObjects
(DWORD arg0, LPHANDLE arg1, BOOL arg2, DWORD arg3, DWORD arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "MsgWaitForMultipleObjects", "DWORD", arg0, "LPHANDLE", arg1, "BOOL", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
MsgWaitForMultipleObjectsEx
(DWORD arg0, LPHANDLE arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "MsgWaitForMultipleObjectsEx", "DWORD", arg0, "LPHANDLE", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
OemKeyScan
(WORD arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "OemKeyScan", "WORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OemToCharA
(LPCSTR arg0, LPSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OemToCharA", "LPCSTR", arg0, "LPSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OemToCharBuffA
(LPCSTR arg0, LPSTR arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OemToCharBuffA", "LPCSTR", arg0, "LPSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OemToCharBuffW
(LPCSTR arg0, LPWSTR arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OemToCharBuffW", "LPCSTR", arg0, "LPWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OemToCharW
(LPCSTR arg0, LPWSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OemToCharW", "LPCSTR", arg0, "LPWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OffsetRect
(LPRECT arg0, int arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OffsetRect", "LPRECT", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OpenClipboard
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OpenClipboard", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDESK WINAPI
OpenDesktopA
(LPSTR arg0, DWORD arg1, BOOL arg2, DWORD arg3)
{
	HDESK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDESK", "OpenDesktopA", "LPSTR", arg0, "DWORD", arg1, "BOOL", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDESK WINAPI
OpenDesktopW
(LPWSTR arg0, DWORD arg1, BOOL arg2, DWORD arg3)
{
	HDESK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDESK", "OpenDesktopW", "LPWSTR", arg0, "DWORD", arg1, "BOOL", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OpenIcon
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OpenIcon", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDESK WINAPI
OpenInputDesktop
(DWORD arg0, BOOL arg1, DWORD arg2)
{
	HDESK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDESK", "OpenInputDesktop", "DWORD", arg0, "BOOL", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWINSTA WINAPI
OpenWindowStationA
(LPSTR arg0, BOOL arg1, DWORD arg2)
{
	HWINSTA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWINSTA", "OpenWindowStationA", "LPSTR", arg0, "BOOL", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWINSTA WINAPI
OpenWindowStationW
(LPWSTR arg0, BOOL arg1, DWORD arg2)
{
	HWINSTA rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWINSTA", "OpenWindowStationW", "LPWSTR", arg0, "BOOL", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
PackDDElParam
(UINT arg0, UINT arg1, UINT arg2)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "PackDDElParam", "UINT", arg0, "UINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PaintDesktop
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PaintDesktop", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PtInRect
(LPCRECT arg0, POINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PtInRect", "LPCRECT", arg0, "POINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RedrawWindow
(HWND arg0, LPCRECT arg1, HRGN arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RedrawWindow", "HWND", arg0, "LPCRECT", arg1, "HRGN", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
RegisterClipboardFormatA
(LPCSTR arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "RegisterClipboardFormatA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
RegisterClipboardFormatW
(LPCWSTR arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "RegisterClipboardFormatW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RegisterHotKey
(HWND arg0, int arg1, UINT arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RegisterHotKey", "HWND", arg0, "int", arg1, "UINT", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
RegisterWindowMessageA
(LPCSTR arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "RegisterWindowMessageA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
RegisterWindowMessageW
(LPCWSTR arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "RegisterWindowMessageW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
RemovePropA
(HWND arg0, LPCSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "RemovePropA", "HWND", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
RemovePropW
(HWND arg0, LPCWSTR arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "RemovePropW", "HWND", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
ReuseDDElParam
(LONG arg0, UINT arg1, UINT arg2, UINT arg3, UINT arg4)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "ReuseDDElParam", "LONG", arg0, "UINT", arg1, "UINT", arg2, "UINT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScrollDC
(HDC arg0, int arg1, int arg2, LPCRECT arg3, LPCRECT arg4, HRGN arg5, LPRECT arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ScrollDC", "HDC", arg0, "int", arg1, "int", arg2, "LPCRECT", arg3, "LPCRECT", arg4, "HRGN", arg5, "LPRECT", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScrollWindow
(HWND arg0, int arg1, int arg2, LPCRECT arg3, LPCRECT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ScrollWindow", "HWND", arg0, "int", arg1, "int", arg2, "LPCRECT", arg3, "LPCRECT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ScrollWindowEx
(HWND arg0, int arg1, int arg2, LPCRECT arg3, LPCRECT arg4, HRGN arg5, LPRECT arg6, UINT arg7)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ScrollWindowEx", "HWND", arg0, "int", arg1, "int", arg2, "LPCRECT", arg3, "LPCRECT", arg4, "HRGN", arg5, "LPRECT", arg6, "UINT", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
SetActiveWindow
(HWND arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "SetActiveWindow", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCaretBlinkTime
(UINT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCaretBlinkTime", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetCaretPos
(int arg0, int arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetCaretPos", "int", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetClassLongA
(HWND arg0, int arg1, LONG arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SetClassLongA", "HWND", arg0, "int", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetClassLongW
(HWND arg0, int arg1, LONG arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SetClassLongW", "HWND", arg0, "int", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WORD WINAPI
SetClassWord
(HWND arg0, int arg1, WORD arg2)
{
	WORD rc = (WORD)-1;
	WIN32API_ENTER("WORD", "SetClassWord", "HWND", arg0, "int", arg1, "WORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
SetClipboardData
(UINT arg0, HANDLE arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "SetClipboardData", "UINT", arg0, "HANDLE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
SetClipboardViewer
(HWND arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "SetClipboardViewer", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
SetDebugErrorLevel
(DWORD arg0)
{
	WIN32API_ENTER("VOID", "SetDebugErrorLevel", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" BOOL WINAPI
SetDoubleClickTime
(UINT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetDoubleClickTime", "UINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
SetFocus
(HWND arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "SetFocus", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetKeyboardState
(PBYTE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetKeyboardState", "PBYTE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
SetLastErrorEx
(DWORD arg0, DWORD arg1)
{
	WIN32API_ENTER("void", "SetLastErrorEx", "DWORD", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" HWND WINAPI
SetParent
(HWND arg0, HWND arg1)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "SetParent", "HWND", arg0, "HWND", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetProcessWindowStation
(HWINSTA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetProcessWindowStation", "HWINSTA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetPropA
(HWND arg0, LPCSTR arg1, HANDLE arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetPropA", "HWND", arg0, "LPCSTR", arg1, "HANDLE", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetPropW
(HWND arg0, LPCWSTR arg1, HANDLE arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetPropW", "HWND", arg0, "LPCWSTR", arg1, "HANDLE", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetRectEmpty
(LPRECT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetRectEmpty", "LPRECT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetScrollInfo
(HWND arg0, int arg1, LPCSCROLLINFO arg2, BOOL arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetScrollInfo", "HWND", arg0, "int", arg1, "LPCSCROLLINFO", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetScrollPos
(HWND arg0, int arg1, int arg2, BOOL arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetScrollPos", "HWND", arg0, "int", arg1, "int", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetScrollRange
(HWND arg0, int arg1, int arg2, int arg3, BOOL arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetScrollRange", "HWND", arg0, "int", arg1, "int", arg2, "int", arg3, "BOOL", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSysColors
(int arg0, const INT * arg1, const COLORREF * arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSysColors", "int", arg0, "const INT *", arg1, "const COLORREF *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetSystemCursor
(HCURSOR arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetSystemCursor", "HCURSOR", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetThreadDesktop
(HDESK arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetThreadDesktop", "HDESK", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetUserObjectInformationA
(HANDLE arg0, int arg1, PVOID arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetUserObjectInformationA", "HANDLE", arg0, "int", arg1, "PVOID", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetUserObjectInformationW
(HANDLE arg0, int arg1, PVOID arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetUserObjectInformationW", "HANDLE", arg0, "int", arg1, "PVOID", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetUserObjectSecurity
(HANDLE arg0, PSECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetUserObjectSecurity", "HANDLE", arg0, "PSECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowContextHelpId
(HWND arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWindowContextHelpId", "HWND", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowPlacement
(HWND arg0, const WINDOWPLACEMENT* arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWindowPlacement", "HWND", arg0, "const WINDOWPLACEMENT*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetWindowRgn
(HWND arg0, HRGN arg1, BOOL arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetWindowRgn", "HWND", arg0, "HRGN", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WORD WINAPI
SetWindowWord
(HWND arg0, int arg1, WORD arg2)
{
	WORD rc = (WORD)-1;
	WIN32API_ENTER("WORD", "SetWindowWord", "HWND", arg0, "int", arg1, "WORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HOOKPROC WINAPI
SetWindowsHookA
(int arg0, HOOKPROC arg1)
{
	HOOKPROC rc = NULL;
	WIN32API_ENTER("HOOKPROC", "SetWindowsHookA", "int", arg0, "HOOKPROC", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HHOOK WINAPI
SetWindowsHookExA
(int arg0, HOOKPROC arg1, HINSTANCE arg2, DWORD arg3)
{
	HHOOK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HHOOK", "SetWindowsHookExA", "int", arg0, "HOOKPROC", arg1, "HINSTANCE", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HHOOK WINAPI
SetWindowsHookExW
(int arg0, HOOKPROC arg1, HINSTANCE arg2, DWORD arg3)
{
	HHOOK rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HHOOK", "SetWindowsHookExW", "int", arg0, "HOOKPROC", arg1, "HINSTANCE", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShowCaret
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShowCaret", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShowOwnedPopups
(HWND arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShowOwnedPopups", "HWND", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShowScrollBar
(HWND arg0, int arg1, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShowScrollBar", "HWND", arg0, "int", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShowWindowAsync
(HWND arg0, int arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShowWindowAsync", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SubtractRect
(LPRECT arg0, LPCRECT arg1, LPCRECT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SubtractRect", "LPRECT", arg0, "LPCRECT", arg1, "LPCRECT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SwapMouseButton
(BOOL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SwapMouseButton", "BOOL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SwitchDesktop
(HDESK arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SwitchDesktop", "HDESK", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SystemParametersInfoA
(UINT arg0, UINT arg1, PVOID arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SystemParametersInfoA", "UINT", arg0, "UINT", arg1, "PVOID", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SystemParametersInfoW
(UINT arg0, UINT arg1, PVOID arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SystemParametersInfoW", "UINT", arg0, "UINT", arg1, "PVOID", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
TabbedTextOutA
(HDC arg0, int arg1, int arg2, LPCSTR arg3, int arg4, int arg5, LPINT arg6, int arg7)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "TabbedTextOutA", "HDC", arg0, "int", arg1, "int", arg2, "LPCSTR", arg3, "int", arg4, "int", arg5, "LPINT", arg6, "int", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
TabbedTextOutW
(HDC arg0, int arg1, int arg2, LPCWSTR arg3, int arg4, int arg5, LPINT arg6, int arg7)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "TabbedTextOutW", "HDC", arg0, "int", arg1, "int", arg2, "LPCWSTR", arg3, "int", arg4, "int", arg5, "LPINT", arg6, "int", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WORD WINAPI
TileWindows
(HWND arg0, UINT arg1, LPCRECT arg2, UINT arg3, const HWND * arg4)
{
	WORD rc = (WORD)-1;
	WIN32API_ENTER("WORD", "TileWindows", "HWND", arg0, "UINT", arg1, "LPCRECT", arg2, "UINT", arg3, "const HWND *", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ToAscii
(UINT arg0, UINT arg1, PBYTE arg2, LPWORD arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ToAscii", "UINT", arg0, "UINT", arg1, "PBYTE", arg2, "LPWORD", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ToAsciiEx
(UINT arg0, UINT arg1, PBYTE arg2, LPWORD arg3, UINT arg4, HKL arg5)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ToAsciiEx", "UINT", arg0, "UINT", arg1, "PBYTE", arg2, "LPWORD", arg3, "UINT", arg4, "HKL", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ToUnicode
(UINT arg0, UINT arg1, PBYTE arg2, LPWSTR arg3, int arg4, UINT arg5)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ToUnicode", "UINT", arg0, "UINT", arg1, "PBYTE", arg2, "LPWSTR", arg3, "int", arg4, "UINT", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ToUnicodeEx
(UINT arg0, UINT arg1, PBYTE arg2, LPWSTR arg3, int arg4, UINT arg5, HKL arg6)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ToUnicodeEx", "UINT", arg0, "UINT", arg1, "PBYTE", arg2, "LPWSTR", arg3, "int", arg4, "UINT", arg5, "HKL", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TrackMouseEvent
(LPTRACKMOUSEEVENT arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TrackMouseEvent", "LPTRACKMOUSEEVENT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TrackPopupMenu
(HMENU arg0, UINT arg1, int arg2, int arg3, int arg4, HWND arg5, LPCRECT arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TrackPopupMenu", "HMENU", arg0, "UINT", arg1, "int", arg2, "int", arg3, "int", arg4, "HWND", arg5, "LPCRECT", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TrackPopupMenuEx
(HMENU arg0, UINT arg1, int arg2, int arg3, HWND arg4, LPTPMPARAMS arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TrackPopupMenuEx", "HMENU", arg0, "UINT", arg1, "int", arg2, "int", arg3, "HWND", arg4, "LPTPMPARAMS", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
TranslateAcceleratorA
(HWND arg0, HACCEL arg1, LPMSG arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "TranslateAcceleratorA", "HWND", arg0, "HACCEL", arg1, "LPMSG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
TranslateAcceleratorW
(HWND arg0, HACCEL arg1, LPMSG arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "TranslateAcceleratorW", "HWND", arg0, "HACCEL", arg1, "LPMSG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TranslateMDISysAccel
(HWND arg0, LPMSG arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TranslateMDISysAccel", "HWND", arg0, "LPMSG", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnhookWindowsHook
(int arg0, HOOKPROC arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnhookWindowsHook", "int", arg0, "HOOKPROC", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnhookWindowsHookEx
(HHOOK arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnhookWindowsHookEx", "HHOOK", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnionRect
(LPRECT arg0, LPCRECT arg1, LPCRECT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnionRect", "LPRECT", arg0, "LPCRECT", arg1, "LPCRECT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnloadKeyboardLayout
(HKL arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnloadKeyboardLayout", "HKL", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnpackDDElParam
(UINT arg0, LONG arg1, PUINT arg2, PUINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnpackDDElParam", "UINT", arg0, "LONG", arg1, "PUINT", arg2, "PUINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnregisterHotKey
(HWND arg0, int arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnregisterHotKey", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ValidateRect
(HWND arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ValidateRect", "HWND", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ValidateRgn
(HWND arg0, HRGN arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ValidateRgn", "HWND", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SHORT WINAPI
VkKeyScanA
(CHAR arg0)
{
	SHORT rc = (SHORT)-1;
	WIN32API_ENTER("SHORT", "VkKeyScanA", "CHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SHORT WINAPI
VkKeyScanExA
(CHAR arg0, HKL arg1)
{
	SHORT rc = (SHORT)-1;
	WIN32API_ENTER("SHORT", "VkKeyScanExA", "CHAR", arg0, "HKL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SHORT WINAPI
VkKeyScanExW
(WCHAR arg0, HKL arg1)
{
	SHORT rc = (SHORT)-1;
	WIN32API_ENTER("SHORT", "VkKeyScanExW", "WCHAR", arg0, "HKL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SHORT WINAPI
VkKeyScanW
(WCHAR arg0)
{
	SHORT rc = (SHORT)-1;
	WIN32API_ENTER("SHORT", "VkKeyScanW", "WCHAR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
WaitForInputIdle
(HANDLE arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "WaitForInputIdle", "HANDLE", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WaitMessage
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WaitMessage", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WinHelpA
(HWND arg0, LPCSTR arg1, UINT arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WinHelpA", "HWND", arg0, "LPCSTR", arg1, "UINT", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WinHelpW
(HWND arg0, LPCWSTR arg1, UINT arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WinHelpW", "HWND", arg0, "LPCWSTR", arg1, "UINT", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
WindowFromDC
(HDC arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "WindowFromDC", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
WindowFromPoint
(POINT arg0)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "WindowFromPoint", "POINT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID WINAPI
keybd_event
(BYTE arg0, BYTE arg1, DWORD arg2, DWORD arg3)
{
	WIN32API_ENTER("VOID", "keybd_event", "BYTE", arg0, "BYTE", arg1, "DWORD", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" void WINAPI
mouse_event
(DWORD arg0, DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4)
{
	WIN32API_ENTER("void", "mouse_event", "DWORD", arg0, "DWORD", arg1, "DWORD", arg2, "DWORD", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" int WINAPI
wvsprintfA
(LPSTR arg0, LPCSTR arg1, va_list arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "wvsprintfA", "LPSTR", arg0, "LPCSTR", arg1, "va_list", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
wvsprintfW
(LPWSTR arg0, LPCWSTR arg1, va_list arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "wvsprintfW", "LPWSTR", arg0, "LPCWSTR", arg1, "va_list", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	User32_GetAddressByOrder
#	define	GetAddressByName	User32_GetAddressByName

#	include "User32/GetAddressByOrder.h"
#	include "User32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
