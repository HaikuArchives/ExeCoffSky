/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DialogItem.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DialogItem.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "DialogItem.h"
#include "Window.h"
#include "Message.h"
#include "Win32Trace.h"
#include "Win32String.h"
#include "Win32Error.h"

static BOOL
SetDlgItemTextU
(HWND hDlg, int nIDDlgItem, LPCSTR lpString)
{
	WIN32API_INTERNAL_START();
	HWND item = GetDlgItem(hDlg, nIDDlgItem);
	WIN32API_INFO("\tnIDDlgItem %d = HWND $%08x\n", nIDDlgItem, item);
	WIN32API_INFO("\tlpString: %s\n", lpString);
	BOOL rc = (BOOL)SendMessageW(item, WM_SETTEXT, 0, (LPARAM)lpString);
	WIN32API_INTERNAL_END();
	return rc;
}

static BOOL CALLBACK
GetDlgItemCallback
(HWND hWnd, LPARAM lParam)
{
	GetDlgItemParam *param = (GetDlgItemParam *)lParam;
	WIN32API_INTERNAL_START();
	if (param->nID == GetDlgCtrlID(hWnd)) {
		WIN32API_INTERNAL_END();
		param->result = hWnd;
		return FALSE;
	}
	WIN32API_INTERNAL_END();
	return TRUE;
}

extern "C" int WINAPI
GetDlgCtrlID
(HWND hwndCtl)
{
	int rc = 0;
	WIN32API_ENTER("int", "GetDlgCtrlID", "HWND", hwndCtl, NULL);
	Window *window = Window::HandleToWindow(hwndCtl);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->GetID();
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetDlgItem
(HWND hDlg, int nIDDlgItem)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "GetDlgItem", "HWND", hDlg, "int", nIDDlgItem, NULL);
	WIN32API_INTERNAL_START();
	GetDlgItemParam param;
	param.nID = nIDDlgItem;
	param.result = NULL;
	if (TRUE == EnumChildWindows(hDlg, GetDlgItemCallback, (LPARAM)&param)) rc = param.result;
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetDlgItemInt
(HWND arg0, int arg1, PBOOL arg2, BOOL arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetDlgItemInt", "HWND", arg0, "int", arg1, "PBOOL", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetDlgItemTextA
(HWND arg0, int arg1, LPSTR arg2, int arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetDlgItemTextA", "HWND", arg0, "int", arg1, "LPSTR", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetDlgItemTextW
(HWND arg0, int arg1, LPWSTR arg2, int arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetDlgItemTextW", "HWND", arg0, "int", arg1, "LPWSTR", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetDlgItemInt
(HWND arg0, int arg1, UINT arg2, BOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetDlgItemInt", "HWND", arg0, "int", arg1, "UINT", arg2, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetDlgItemTextA
(HWND hDlg, int nIDDlgItem, LPCSTR lpString)
{
	WIN32API_POINTER(lpString);
	WIN32API_ENTER("BOOL", "SetDlgItemTextA", "HWND", hDlg, "int", nIDDlgItem, "LPCSTR", lpString, NULL);
	Win32String str;
	str.SetToA(lpString);
	BOOL rc = SetDlgItemTextU(hDlg, nIDDlgItem, str.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetDlgItemTextW
(HWND hDlg, int nIDDlgItem, LPCWSTR lpString)
{
	WIN32API_POINTER(lpString);
	WIN32API_ENTER("BOOL", "SetDlgItemTextW", "HWND", hDlg, "int", nIDDlgItem, "LPCWSTR", lpString, NULL);
	Win32String str;
	str.SetToW(lpString);
	BOOL rc = SetDlgItemTextU(hDlg, nIDDlgItem, str.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendDlgItemMessageA
(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc = 0;
	WIN32API_ENTER("LRESULT", "SendDlgItemMessageA", "HWND", hDlg, "int", nIDDlgItem, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
SendDlgItemMessageW
(HWND arg0, int arg1, UINT arg2, WPARAM arg3, LPARAM arg4)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "SendDlgItemMessageW", "HWND", arg0, "int", arg1, "UINT", arg2, "WPARAM", arg3, "LPARAM", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CheckDlgButton
(HWND hDlg, int nIDDlgItem, UINT uCheck)
{
	WIN32API_ENTER("BOOL", "CheckDlgButton", "HWND", hDlg, "int", nIDDlgItem, "UINT", uCheck, NULL);
	WIN32API_INTERNAL_START();
	HWND item = GetDlgItem(hDlg, nIDDlgItem);
	WIN32API_INFO("\tnIDDlgItem %d = HWND $%08x\n", nIDDlgItem, item);
	BOOL rc = (BOOL)SendMessageW(item, BM_SETCHECK, (WPARAM)uCheck, 0);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CheckRadioButton
(HWND arg0, int arg1, int arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CheckRadioButton", "HWND", arg0, "int", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
IsDlgButtonChecked
(HWND arg0, int arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "IsDlgButtonChecked", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DlgDirListA
(HWND arg0, LPSTR arg1, int arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DlgDirListA", "HWND", arg0, "LPSTR", arg1, "int", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DlgDirListW
(HWND arg0, LPWSTR arg1, int arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DlgDirListW", "HWND", arg0, "LPWSTR", arg1, "int", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DlgDirListComboBoxA
(HWND arg0, LPSTR arg1, int arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DlgDirListComboBoxA", "HWND", arg0, "LPSTR", arg1, "int", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DlgDirListComboBoxW
(HWND arg0, LPWSTR arg1, int arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DlgDirListComboBoxW", "HWND", arg0, "LPWSTR", arg1, "int", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DlgDirSelectComboBoxExA
(HWND arg0, LPSTR arg1, int arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DlgDirSelectComboBoxExA", "HWND", arg0, "LPSTR", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DlgDirSelectComboBoxExW
(HWND arg0, LPWSTR arg1, int arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DlgDirSelectComboBoxExW", "HWND", arg0, "LPWSTR", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DlgDirSelectExA
(HWND arg0, LPSTR arg1, int arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DlgDirSelectExA", "HWND", arg0, "LPSTR", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DlgDirSelectExW
(HWND arg0, LPWSTR arg1, int arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DlgDirSelectExW", "HWND", arg0, "LPWSTR", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetNextDlgGroupItem
(HWND arg0, HWND arg1, BOOL arg2)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetNextDlgGroupItem", "HWND", arg0, "HWND", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetNextDlgTabItem
(HWND arg0, HWND arg1, BOOL arg2)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "GetNextDlgTabItem", "HWND", arg0, "HWND", arg1, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
