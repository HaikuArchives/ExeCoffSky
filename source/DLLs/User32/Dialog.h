/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Dialog.h,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Dialog.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Dialog_h__)
#	define	__Dialog_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

typedef LRESULT CALLBACK (*DLGPROC)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

typedef struct tagDLGTEMPLATE {
	PACKED(DWORD style);
	PACKED(DWORD dwExtendedStyle);
	PACKED(WORD cdit);
	PACKED(short x);
	PACKED(short y);
	PACKED(short cx);
	PACKED(short cy);
//	PACKED(sz_0r_0rd menu);
//	PACKED(sz_0r_0rd windowClass);
//	PACKED(WCHAR title[titleLen]);
//	PACKED(WORD pointsize);
//	PACKED(WCHAR typeface[typefacelen]);
} DLGTEMPLATE, *LPDLGTEMPLATE;
typedef const DLGTEMPLATE CDLGTEMPLATE, *LPCDLGTEMPLATE;

typedef struct tagDLGTEMPLATEEX {
	PACKED(WORD dlgVer);
	PACKED(WORD signature);
	PACKED(DWORD helpID);
	PACKED(DWORD exStyle);
	PACKED(DWORD style);
	PACKED(WORD cDlgItems);
	PACKED(short x);
	PACKED(short y);
	PACKED(short cx);
	PACKED(short cy);
//	PACKED(sz_0r_0rd menu);
//	PACKED(sz_0r_0rd windowClass);
//	PACKED(WCHAR title[titleLen]);
//	PACKED(WORD pointsize);
//	PACKED(WORD weight);
//	PACKED(BYTE italic);
//	PACKED(BYTE charset);
//	PACKED(WCHAR typeface[typefacelen]);
} DLGTEMPLATEEX, *LPDLGTEMPLATEEX;
typedef const DLGTEMPLATEEX CDLGTEMPLATEEX, *LPCDLGTEMPLATEEX;

typedef struct tagDLGITEMTEMPLATE {
	PACKED(DWORD style);
	PACKED(DWORD dwExtendedStyle);
	PACKED(short x);
	PACKED(short y);
	PACKED(short cx);
	PACKED(short cy);
	PACKED(WORD id);
//	PACKED(sz_0r_0rd windowClass);
//	PACKED(sz_0r_0rd title);
//	PACKED(WORD extraCount);
} DLGITEMTEMPLATE, *LPDLGITEMTEMPLATE;
typedef const DLGITEMTEMPLATE CDLGITEMTEMPLATE, *LPCDLGITEMTEMPLATE;

typedef struct tagDLGITEMTEMPLATEEX {
	PACKED(DWORD helpID);
	PACKED(DWORD exStyle);
	PACKED(DWORD style);
	PACKED(short x);
	PACKED(short y);
	PACKED(short cx);
	PACKED(short cy);
	PACKED(WORD id);
//	PACKED(sz_0r_0rd windowClass);
//	PACKED(sz_0r_0rd title);
//	PACKED(WORD extraCount);
} DLGITEMTEMPLATEEX, *LPDLGITEMTEMPLATEEX;
typedef const DLGITEMTEMPLATEEX CDLGITEMTEMPLATEEX, *LPCDLGITEMTEMPLATEEX;

#	define	DS_ABSALIGN			0x01L
#	define	DS_SYSMODAL			0x02L
#	define	DS_LOCALEDIT		0x20L
#	define	DS_SETFONT			0x40L
#	define	DS_MODALFRAME		0x80L
#	define	DS_NOIDLEMSG		0x100L
#	define	DS_SETFOREGROUND	0x200L

#	define	DS_3DLOOK			0x0004L
#	define	DS_FIXEDSYS			0x0008L
#	define	DS_NOFAILCREATE		0x0010L
#	define	DS_CONTROL			0x0400L
#	define	DS_CENTER			0x0800L
#	define	DS_CENTERMOUSE		0x1000L
#	define	DS_CONTEXTHELP		0x2000L

static HWND CreateDialogIndirectParam(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

int WINAPI DialogBoxParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
int WINAPI DialogBoxParamW(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
int WINAPI DialogBoxIndirectParamA(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit);
int WINAPI DialogBoxIndirectParamW(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit);
HWND WINAPI CreateDialogParamA(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
HWND WINAPI CreateDialogParamW(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam);
HWND WINAPI CreateDialogIndirectParamA(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit);
HWND WINAPI CreateDialogIndirectParamW(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit);
BOOL WINAPI EndDialog(HWND hWnd, INT nResult);
long WINAPI GetDialogBaseUnits(void);
BOOL WINAPI IsDialogMessageA(HWND hWnd, LPMSG lpMsg);
BOOL WINAPI IsDialogMessageW(HWND hWnd, LPMSG lpMsg);
BOOL WINAPI MapDialogRect(HWND hWnd, LPRECT lpRect);

LRESULT WINAPI DefDlgProcA(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI DefDlgProcW(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Dialog_h__)
