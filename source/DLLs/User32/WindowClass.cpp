/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: WindowClass.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [WindowClass.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "WindowClass.h"
#include "Dialog.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

BLocker
WindowClass::lock;

BList
WindowClass::classes;

int
WindowClass::id = 0;

WindowClass::WindowClass
(LPCWNDCLASSA wc, NewViewProc nvc):
style(wc->style),
lpfnWndProc(wc->lpfnWndProc),
cbClsExtra(wc->cbClsExtra),
cbWndExtra(wc->cbWndExtra),
hInstance(wc->hInstance),
hIcon(wc->hIcon),
hCursor(wc->hCursor),
hbrBackground(wc->hbrBackground),
hIconSm(INVALID_HANDLE_VALUE),
nvc(nvc)
{
	if (NULL == wc->lpszMenuName) lpszMenuName = NULL;
	else {
		if (0 != (0xffff0000 & (UINT)wc->lpszMenuName)) {
			lpszMenuName = strdup(wc->lpszMenuName);
		} else {
			lpszMenuName = (char *)wc->lpszMenuName;
		}
	}
	if (NULL == wc->lpszClassName) lpszClassName = NULL;
	else lpszClassName = strdup(wc->lpszClassName);
	lock.Lock();
	id++;
	atom = id;
	classes.AddItem(this);
	lock.Unlock();
}

WindowClass::WindowClass
(LPCWNDCLASSEXA wcex, NewViewProc nvc):
style(wcex->style),
lpfnWndProc(wcex->lpfnWndProc),
cbClsExtra(wcex->cbClsExtra),
cbWndExtra(wcex->cbWndExtra),
hInstance(wcex->hInstance),
hIcon(wcex->hIcon),
hCursor(wcex->hCursor),
hbrBackground(wcex->hbrBackground),
hIconSm(wcex->hIconSm),
nvc(nvc)
{
	if (NULL == wcex->lpszMenuName) lpszMenuName = NULL;
	else {
		if (0 != (0xffff0000 & (UINT)wcex->lpszMenuName)) {
			lpszMenuName = strdup(wcex->lpszMenuName);
		} else {
			lpszMenuName = (char *)wcex->lpszMenuName;
		}
	}
	if (NULL == wcex->lpszClassName) lpszClassName = NULL;
	else lpszClassName = strdup(wcex->lpszClassName);
	lock.Lock();
	id++;
	atom = id;
	classes.AddItem(this);
	lock.Unlock();
}

WindowClass::~WindowClass
(void)
{
	if (0 != (0xffff0000 & (UINT)lpszMenuName)) free(lpszMenuName);
	if (NULL != lpszClassName) free(lpszClassName);
	lock.Lock();
	classes.RemoveItem(this);
	lock.Unlock();
}

BView *
WindowClass::CreateCustomView
(HINSTANCE hInstance, BRect rect, LPCSTR lpTitle, DWORD &style)
{
	if (NULL == nvc) return NULL;
	return nvc(hInstance, rect, lpTitle, style);
}

WindowClass *
WindowClass::FindClass
(const char *name)
{
	lock.Lock();
	WindowClass *rc = NULL;
	int32 n = classes.CountItems();
	for (int32 i = 0; i < n; i++) {
		WindowClass *wc = (WindowClass *)classes.ItemAt(i);
		WIN32API_INFO("\tfind class %s, %s ...\n", wc->lpszClassName, name);
		if (0 == strcmp(wc->lpszClassName, name)) {
			WIN32API_INFO("\t\tfound\n");
			rc = wc;
			break;
		}
	}
	lock.Unlock();
	return rc;
}

ATOM
RegisterClassU
(LPWNDCLASSA lpwc)
{
	ATOM rc = 0;
	WIN32API_INFO("\tstyle = $%08x\n", lpwc->style);
	WIN32API_INFO("\tlpfnWndProc = %p\n", lpwc->lpfnWndProc);
	WIN32API_INFO("\tcbClsExtra = $%08x\n", lpwc->cbClsExtra);
	WIN32API_INFO("\tcbWndExtra = $%08x\n", lpwc->cbWndExtra);
	WIN32API_INFO("\thInstance = $%08x\n", lpwc->hInstance);
	WIN32API_INFO("\thIcon = $%08x\n", lpwc->hIcon);
	WIN32API_INFO("\thCursor = $%08x\n", lpwc->hCursor);
	WIN32API_INFO("\thbrBackground = $%08x\n", lpwc->hbrBackground);
	if (0 != (0xffff0000 & (UINT)lpwc->lpszMenuName)) {
		WIN32API_INFO("\tlpszMenuName = %s\n", lpwc->lpszMenuName);
	} else {
		WIN32API_INFO("\tlpszMenuName = #%d\n", (UINT)lpwc->lpszMenuName);
	}
	if (0 != (0xffff0000 & (UINT)lpwc->lpszClassName)) {
		WIN32API_INFO("\tlpszClassName = %s\n", lpwc->lpszClassName);
	} else {
		WIN32API_INFO("\tlpszClassName = #%d\n", (UINT)lpwc->lpszClassName);
	}
	WindowClass *wc = new WindowClass(lpwc);
	if (NULL != wc) {
		rc = wc->atom;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	return rc;
}

ATOM
RegisterClassExU
(LPWNDCLASSEXA lpwcex)
{
	ATOM rc = 0;
	WIN32API_INFO("\tcbSize = $%08x\n", lpwcex->cbSize);
	WIN32API_INFO("\tstyle = $%08x\n", lpwcex->style);
	WIN32API_INFO("\tlpfnWndProc = %p\n", lpwcex->lpfnWndProc);
	WIN32API_INFO("\tcbClsExtra = $%08x\n", lpwcex->cbClsExtra);
	WIN32API_INFO("\tcbWndExtra = $%08x\n", lpwcex->cbWndExtra);
	WIN32API_INFO("\thInstance = $%08x\n", lpwcex->hInstance);
	WIN32API_INFO("\thIcon = $%08x\n", lpwcex->hIcon);
	WIN32API_INFO("\thCursor = $%08x\n", lpwcex->hCursor);
	WIN32API_INFO("\thbrBackground = $%08x\n", lpwcex->hbrBackground);
	if (0 != (0xffff0000 & (UINT)lpwcex->lpszMenuName)) {
		WIN32API_INFO("\tlpszMenuName = %s\n", lpwcex->lpszMenuName);
	} else {
		WIN32API_INFO("\tlpszMenuName = %p\n", lpwcex->lpszMenuName);
	}
	if (0 != (0xffff0000 & (UINT)lpwcex->lpszClassName)) {
		WIN32API_INFO("\tlpszClassName = %s\n", lpwcex->lpszClassName);
	} else {
		WIN32API_INFO("\tlpszClassName = #%d\n", (UINT)lpwcex->lpszClassName);
	}
	WIN32API_INFO("\thIconSm = $%08x\n", lpwcex->hIconSm);
	WindowClass *wc = new WindowClass(lpwcex);
	if (NULL != wc) {
		rc = wc->atom;
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	return rc;
}


extern "C" ATOM WINAPI
RegisterClassA
(LPCWNDCLASSA lpwc)
{
	WIN32API_POINTER(lpwc);
	WIN32API_ENTER("ATOM", "RegisterClassA", "LPCWNDCLASSA", lpwc, NULL);
	WNDCLASSA wc;
	memcpy(&wc, lpwc, sizeof(WNDCLASSA));
	WIN32API_POINTER(wc.lpfnWndProc);
	WIN32API_POINTER(wc.lpszMenuName);
	WIN32API_POINTER(wc.lpszClassName);
	Win32String menu;
	if (0 != (0xffff0000 & (unsigned long)wc.lpszMenuName)) {
		menu.SetToA(wc.lpszMenuName);
		wc.lpszMenuName = menu.StringU();
	}
	Win32String cname;
	cname.SetToA(wc.lpszClassName);
	wc.lpszClassName = cname.StringU();
	ATOM rc = RegisterClassU(&wc);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
RegisterClassW
(LPCWNDCLASSW lpwc)
{
	WIN32API_POINTER(lpwc);
	WIN32API_ENTER("ATOM", "RegisterClassW", "LPCWNDCLASSW", lpwc, NULL);
	WNDCLASSA wc;
	memcpy(&wc, lpwc, sizeof(WNDCLASSA));
	WIN32API_POINTER(wc.lpfnWndProc);
	WIN32API_POINTER(wc.lpszMenuName);
	WIN32API_POINTER(wc.lpszClassName);
	Win32String menu;
	if (0 != (0xffff0000 & (unsigned long)wc.lpszMenuName)) {
		menu.SetToW((LPCWSTR)wc.lpszMenuName);
		wc.lpszMenuName = menu.StringU();
	}
	Win32String cname;
	cname.SetToW((LPCWSTR)wc.lpszClassName);
	wc.lpszClassName = cname.StringU();
	ATOM rc = RegisterClassU(&wc);
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" ATOM WINAPI
RegisterClassExA
(LPCWNDCLASSEXA lpwcex)
{
	WIN32API_POINTER(lpwcex);
	WIN32API_ENTER("ATOM", "RegisterClassExA", "LPCWNDCLASSEXA", lpwcex, NULL);
	WNDCLASSEXA wcex;
	memcpy(&wcex, lpwcex, sizeof(WNDCLASSEXA));
	WIN32API_POINTER(wcex.lpfnWndProc);
	WIN32API_POINTER(wcex.lpszMenuName);
	WIN32API_POINTER(wcex.lpszClassName);
	Win32String menu;
	if (0 != (0xffff0000 & (unsigned long)wcex.lpszMenuName)) {
		menu.SetToA(wcex.lpszMenuName);
		wcex.lpszMenuName = menu.StringU();
	}
	Win32String cname;
	cname.SetToA(wcex.lpszClassName);
	wcex.lpszClassName = cname.StringU();
	ATOM rc = RegisterClassExU(&wcex);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" ATOM WINAPI
RegisterClassExW
(LPCWNDCLASSEXW lpwcex)
{
	WIN32API_POINTER(lpwcex);
	WIN32API_ENTER("ATOM", "RegisterClassExW", "LPCWNDCLASSEXW", lpwcex, NULL);
	WNDCLASSEXA wcex;
	memcpy(&wcex, lpwcex, sizeof(WNDCLASSEXA));
	WIN32API_POINTER(wcex.lpfnWndProc);
	WIN32API_POINTER(wcex.lpszMenuName);
	WIN32API_POINTER(wcex.lpszClassName);
	Win32String menu;
	if (0 != (0xffff0000 & (unsigned long)wcex.lpszMenuName)) {
		WIN32API_INFO("\tlpszMenuName = %s\n", wcex.lpszMenuName);
		menu.SetToW(lpwcex->lpszMenuName);
		wcex.lpszMenuName = menu.StringU();
	}
	Win32String cname;
	cname.SetToW(lpwcex->lpszClassName);
	wcex.lpszClassName = cname.StringU();
	ATOM rc = RegisterClassExU(&wcex);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnregisterClassA
(LPCSTR lpClassName, HINSTANCE hInstance)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnregisterClassA", "LPCSTR", lpClassName, "HINSTANCE", hInstance, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnregisterClassW
(LPCWSTR lpClassName, HINSTANCE hInstance)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnregisterClassW", "LPCWSTR", lpClassName, "HINSTANCE", hInstance, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

#include "DialogWindowClass.h"
#include "StaticWindowClass.h"
#include "ButtonWindowClass.h"
#include "EditWindowClass.h"
