/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DialogItem.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DialogItem.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__DialogItem_h__)
#	define	__DialogItem_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

typedef struct _GetDlgItemParam {
	int nID;
	HWND result;
} GetDlgItemParam;

static BOOL SetDlgItemTextU(HWND hDlg, int nIDDlgItem, LPCSTR lpString);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

static BOOL CALLBACK GetDlgItemCallback(HWND hWnd, LPARAM lParam);

int WINAPI GetDlgCtrlID(HWND hwndCtl);
HWND WINAPI GetDlgItem(HWND hDlg, int nIDDlgItem);

UINT WINAPI GetDlgItemInt(HWND,int,PBOOL,BOOL);
UINT WINAPI GetDlgItemTextA(HWND,int,LPSTR,int);
UINT WINAPI GetDlgItemTextW(HWND,int,LPWSTR,int);
BOOL WINAPI SetDlgItemInt(HWND,int,UINT,BOOL);
BOOL WINAPI SetDlgItemTextA(HWND hDlg, int nIDDlgItem, LPCSTR lpString);
BOOL WINAPI SetDlgItemTextW(HWND hDlg, int nIDDlgITem, LPCWSTR lpString);

LRESULT WINAPI SendDlgItemMessageA(HWND hDlg, int nIDDlgItem, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI SendDlgItemMessageW(HWND,int,UINT,WPARAM,LPARAM);

BOOL WINAPI CheckDlgButton(HWND hDlg, int nIDDlgItem, UINT uCheck);
BOOL WINAPI CheckRadioButton(HWND,int,int,int);
UINT WINAPI IsDlgButtonChecked(HWND,int);

int WINAPI DlgDirListA(HWND,LPSTR,int,int,UINT);
int WINAPI DlgDirListW(HWND,LPWSTR,int,int,UINT);
int WINAPI DlgDirListComboBoxA(HWND,LPSTR,int,int,UINT);
int WINAPI DlgDirListComboBoxW(HWND,LPWSTR,int,int,UINT);
BOOL WINAPI DlgDirSelectComboBoxExA(HWND,LPSTR,int,int);
BOOL WINAPI DlgDirSelectComboBoxExW(HWND,LPWSTR,int,int);
BOOL WINAPI DlgDirSelectExA(HWND,LPSTR,int,int);
BOOL WINAPI DlgDirSelectExW(HWND,LPWSTR,int,int);

HWND WINAPI GetNextDlgGroupItem(HWND,HWND,BOOL);
HWND WINAPI GetNextDlgTabItem(HWND,HWND,BOOL);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__DialogItem_h__)
