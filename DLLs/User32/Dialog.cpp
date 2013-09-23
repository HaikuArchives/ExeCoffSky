/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Dialog.cpp,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Dialog.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Dialog.h"
#include "Kernel32/Module.h"
#include "Kernel32/Resource.h"
#include "Message.h"
#include "Window.h"
#include "SystemMetrics.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

static HWND
CreateDialogIndirectParam
(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit)
{
	HWND rc = NULL;
	bool ex = false;
	LPDLGTEMPLATEEX lpTemplateEx= (LPDLGTEMPLATEEX)lpTemplate;
	if (0xffff == lpTemplateEx->signature) {
		ex = true;
		WIN32API_INFO("\tdlgVer: $%04x\n", lpTemplateEx->dlgVer);
		WIN32API_INFO("\tsignature: $%04x\n", lpTemplateEx->signature);
		WIN32API_INFO("\thelpID: $%08x\n", lpTemplateEx->helpID);
		WIN32API_INFO("\texStyle: $%08x\n", lpTemplateEx->exStyle);
		WIN32API_INFO("\tstyle: $%08x\n", lpTemplateEx->style);
		WIN32API_INFO("\tcDlgItems: %d\n", lpTemplateEx->cDlgItems);
		WIN32API_INFO("\tx: %d\n", lpTemplateEx->x);
		WIN32API_INFO("\ty: %d\n", lpTemplateEx->y);
		WIN32API_INFO("\tcx: %d\n", lpTemplateEx->cx);
		WIN32API_INFO("\tcy: %d\n", lpTemplateEx->cy);
	} else {
		WIN32API_INFO("\tstyle: $%08x\n", lpTemplate->style);
		WIN32API_INFO("\tdwExtendedStyle: $%08x\n", lpTemplate->dwExtendedStyle);
		WIN32API_INFO("\tcdit: %d\n", lpTemplate->cdit);
		WIN32API_INFO("\tx: %d\n", lpTemplate->x);
		WIN32API_INFO("\ty: %d\n", lpTemplate->y);
		WIN32API_INFO("\tcx: %d\n", lpTemplate->cx);
		WIN32API_INFO("\tcy: %d\n", lpTemplate->cy);
	}
	Win32String str;
	short *strptr = NULL;
	Win32String menu;
	LPCWSTR menuname = NULL;
	LPWORD ptr = ex? (LPWORD)&lpTemplateEx[1]: (LPWORD)&lpTemplate[1];
	if (0 == *ptr) {
		strptr = (short *)&ptr[1];
		WIN32API_INFO("\tmenu: N/A\n");
	} else {
		if (0xffff == *ptr) {
			menuname = (LPCWSTR)ptr[1];
			WIN32API_INFO("\tmenu: #$%04x\n", ptr[1]);
			strptr = (short *)&ptr[2];
		} else {
			menu.SetToW(strptr);
			WIN32API_INFO("\tmenu: %s\n", menu.StringU());
			strptr = &strptr[menu.LengthW() + 1];
		}
	}
	Win32String cname;
	LPCWSTR classname = NULL;
	ptr = (LPWORD)strptr;
	if (0 == *ptr) {
		strptr = (short *)&ptr[1];
		cname.SetToA("Dialog");
		classname = cname.StringW();
		WIN32API_INFO("\tclass: Dialog (default)\n");
	} else {
		if (0xffff == *ptr) {
			classname = (LPCWSTR)ptr[1];
			WIN32API_INFO("\tclass: #$%04x\n", ptr[1]);
			strptr = (short *)&ptr[2];
		} else {
			cname.SetToW(strptr);
			classname = cname.StringW();
			WIN32API_INFO("\tclass: %s\n", cname.StringU());
			strptr = &strptr[cname.LengthW() + 1];
		}
	}
	Win32String title;
	title.SetToW(strptr);
	WIN32API_INFO("\ttitle: %s\n", title.StringU());
	LPDLGITEMTEMPLATE dit = (LPDLGITEMTEMPLATE)&strptr[title.LengthW() + 1];
	DWORD style = ex? lpTemplateEx->style: lpTemplate->style;
	DWORD exStyle = ex? lpTemplateEx->exStyle: lpTemplate->dwExtendedStyle;
	short x = ex? lpTemplateEx->x: lpTemplate->x;
	short y = ex? lpTemplateEx->y: lpTemplate->y;
	short cx = ex? lpTemplateEx->cx: lpTemplate->cx;
	short cy = ex? lpTemplateEx->cy: lpTemplate->cy;
	float mag = 1.0;
	if (0 != (style & DS_SETFONT)) {
		style &= ~DS_SETFONT;
		if (ex) {
			LPWORD point = (LPWORD)dit;
			mag = *point / 5.0;
			cx = (int)(cx * mag);
			cy = (int)(cy * mag);
			WIN32API_INFO("\tsize mag.: x %f\n", mag);
			WIN32API_INFO("\tpoint: $%04x\n", *point);
			LPWORD weight = &point[1];
			WIN32API_INFO("\tweight: $%04x\n", *weight);	// XXX
			LPBYTE italic = (LPBYTE)&weight[1];
			WIN32API_INFO("\titalic: $%02x\n", *italic);	// XXX
			LPBYTE charset = (LPBYTE)&italic[1];
			WIN32API_INFO("\tcharset: $%02x\n", *charset);	// XXX
			strptr = (short *)&charset[1];
			str.SetToW(strptr);
			WIN32API_INFO("\tfont name: %s\n", str.StringU());
			dit = (LPDLGITEMTEMPLATE)&strptr[str.LengthW() + 1];
			// XXX: font
		} else {
			LPWORD point = (LPWORD)dit;
			mag = *point / 5.0;
			cx = (int)(cx * mag);
			cy = (int)(cy * mag);
			WIN32API_INFO("\tsize mag.: x %f\n", mag);
			WIN32API_INFO("\tfont size: $%04x\n", *point);
			strptr = (short *)&point[1];
			str.SetToW(strptr);
			WIN32API_INFO("\tfont name: %s\n", str.StringU());
			dit = (LPDLGITEMTEMPLATE)&strptr[str.LengthW() + 1];
			// XXX: font
		}
	}
	if (0 != (style & DS_CENTER)) {
		style &= ~DS_CENTER;
		WIN32API_INTERNAL_START();
		int scrx = GetSystemMetrics(SM_CXSCREEN);
		int scry = GetSystemMetrics(SM_CYSCREEN);
		WIN32API_INTERNAL_END();
		x = (scrx - cx) / 2;
		y = (scry - cy) / 2;
	}
	// XXX: load menu
	WIN32API_INTERNAL_START();
	rc = CreateWindowExW(exStyle, classname, title.StringW(), style,
		x, y, cx, cy,
		hWndParent, NULL /*menuname*/, hInstance, (LPVOID)lpDialogFunc);
	WIN32API_INTERNAL_END();
	WIN32API_INFO("\tDialog hWnd = $%08x\n", rc);
	WIN32API_INFO("\t---\n");
	int cdit = ex? lpTemplateEx->cDlgItems: lpTemplate->cdit;
	for (int i = 0; i < cdit; i++) {
		WIN32API_INFO("\t=== item %d ===\n", i);
		dit = (LPDLGITEMTEMPLATE)(((UINT)dit + 0x3) & ~0x3);
		LPDLGITEMTEMPLATEEX ditEx = (LPDLGITEMTEMPLATEEX)dit;
		if (ex) {
			WIN32API_INFO("\thelpID: $%08x\n", ditEx->helpID);
			WIN32API_INFO("\texStyle: $%08x\n", ditEx->exStyle);
			WIN32API_INFO("\tstyle: $%08x\n", ditEx->style);
			WIN32API_INFO("\tx: %d\n", ditEx->x);
			WIN32API_INFO("\ty: %d\n", ditEx->y);
			WIN32API_INFO("\tcx: %d\n", ditEx->cx);
			WIN32API_INFO("\tcy: %d\n", ditEx->cy);
			WIN32API_INFO("\tid: %d\n", ditEx->id);
		} else {
			WIN32API_INFO("\tstyle: $%08x\n", dit->style);
			WIN32API_INFO("\tdwExtendedStyle: $%08x\n", dit->dwExtendedStyle);
			WIN32API_INFO("\tx: %d\n", dit->x);
			WIN32API_INFO("\ty: %d\n", dit->y);
			WIN32API_INFO("\tcx: %d\n", dit->cx);
			WIN32API_INFO("\tcy: %d\n", dit->cy);
			WIN32API_INFO("\tid: %d\n", dit->id);
		}
		LPWORD ptr = ex? (LPWORD)&ditEx[1]: (LPWORD)&dit[1];
		LPCWSTR classname = NULL;
		if (0xffff != *ptr) {
			cname.SetToW(strptr);
			classname = cname.StringW();
			WIN32API_INFO("\tclass: %s\n", cname.StringU());
			strptr = &strptr[cname.LengthW() + 1];
		} else {
			switch (ptr[1]) {
			case 0x80:
				cname.SetToA("BUTTON");
				break;
			case 0x81:
				cname.SetToA("EDIT");
				break;
			case 0x82:
				cname.SetToA("STATIC");
				break;
			case 0x83:
				cname.SetToA("List Box");
				break;
			case 0x84:
				cname.SetToA("Scroll bar");
				break;
			case 0x85:
				cname.SetToA("Combo box");
				break;
			}
			classname = cname.StringW();
			WIN32API_INFO("\tclass: #$%04x (%s)\n", (UINT)ptr[1], cname.StringU());
			strptr = (short *)&ptr[2];
		}
		ptr = (LPWORD)strptr;
		LPCWSTR titlestr = NULL;
		if (0xffff != *ptr) {
			title.SetToW(strptr);
			titlestr = title.StringW();
			WIN32API_INFO("\ttitle: %s\n", title.StringU());
			strptr = &strptr[title.LengthW() + 1];
		} else {
			// XXX
			titlestr = (LPCWSTR)((DWORD)ptr[1]);
			WIN32API_INFO("\ttitle: #$%04x\n", ptr[1]);
			strptr = (short *)&ptr[2];
		}
		ptr = (LPWORD)strptr;
		if (0 == *ptr) {
			strptr = (short *)&ptr[1];
			WIN32API_INFO("\tdata: N/A\n");
		} else {
			// XXX: this data must be send to control as lParam of WM_CREATE
			WIN32API_INFO("\tdata: size = %d\n", *ptr);
			strptr = &strptr[*ptr];
		}
		if (NULL != rc) {
			WIN32API_INFO("\tcreate item ...\n");
			HWND item = CreateWindowExW(dit->dwExtendedStyle, classname, titlestr, dit->style,
				(int)(dit->x * mag), (int)(dit->y * mag),
				(int)(dit->cx * mag), (int)(dit->cy * mag),
				rc, (HMENU)(dit->id), hInstance, NULL);
			WIN32API_INFO("\tItem hWnd = $%08x\n", item);
			if (NULL != item) Window::HandleToWindow(item)->Show(true);
		}
		dit = (LPDLGITEMTEMPLATE)strptr;
		WIN32API_INFO("\t---\n");
	}
	Window *window = Window::HandleToWindow(rc);
	if (NULL != window) window->SendMessage(WM_INITDIALOG, (WPARAM)rc, lParamInit);
	return rc;
}

extern "C" int WINAPI
DialogBoxParamA
(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
{
	WIN32API_POINTER(lpTemplateName);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(dwInitParam);
	WIN32API_ENTER("int", "DialogBoxParamA", "HINSTANCE", hInstance, "LPCSTR", lpTemplateName, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", dwInitParam, NULL);
	Win32String str;
	if (0 != (0xffff0000 & (UINT)lpTemplateName)) {
		str.SetToA(lpTemplateName);
		lpTemplateName = (LPCSTR)str.StringW();
	}
	WIN32API_INTERNAL_START();
	int rc = DialogBoxParamW(hInstance, (LPCWSTR)lpTemplateName, hWndParent, lpDialogFunc, dwInitParam);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DialogBoxParamW
(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
{
	int rc = -1;
	WIN32API_POINTER(lpTemplateName);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(dwInitParam);
	WIN32API_ENTER("int", "DialogBoxParamW", "HINSTANCE", hInstance, "LPCWSTR", lpTemplateName, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", dwInitParam, NULL);
#if defined(_DEBUG)
	if (0 != (0xffff0000 & (UINT)lpTemplateName)) {
		Win32String str;
		str.SetToW(lpTemplateName);
		WIN32API_INFO("\tlpTemplateName: %s\n", str.StringU());
	} else {
		WIN32API_INFO("\tlpTemplateName: #%d\n", (int)lpTemplateName);
	}
#endif	// defined(_DEBUG)
	try {
		Image *image = HandleToImage(hInstance);
		if (NULL == image) throw ERROR_INVALID_HANDLE;
		void *base = image->GetResourceAddress();
		if (NULL == base) throw ERROR_RESOURCE_DATA_NOT_FOUND;
		HRSRC rsrc = FindResourceW((HMODULE)hInstance, lpTemplateName, MAKEINTRESOURCEW(RT_DIALOG));
		if (NULL != rsrc) {
			LpResourceDataEntry rde = (LpResourceDataEntry)((UINT)base + (UINT)rsrc);
			WIN32API_INTERNAL_START();
			rc = DialogBoxIndirectParamW(hInstance, (LPCDLGTEMPLATE)((UINT)hInstance + rde->DataRva), hWndParent, lpDialogFunc, dwInitParam);
			WIN32API_INTERNAL_END();
		}
	} catch (int e) {
		WIN32API_ERROR(e);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DialogBoxIndirectParamA
(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit)
{
	WIN32API_POINTER(lpTemplate);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(lParamInit);
	WIN32API_ENTER("int", "DialogBoxIndirectParamA", "HINSTANCE", hInstance, "LPCDLGTEMPLATE", lpTemplate, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", lParamInit, NULL);
	WIN32API_INTERNAL_START();
	int rc = DialogBoxIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, lParamInit);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DialogBoxIndirectParamW
(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit)
{
	int rc = -1;
	WIN32API_POINTER(lpTemplate);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(lParamInit);
	WIN32API_ENTER("int", "DialogBoxIndirectParamW", "HINSTANCE", hInstance, "LPCDLGTEMPLATE", lpTemplate, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", lParamInit, NULL);
	WIN32API_INTERNAL_START();
	HWND hWnd = CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, lParamInit);
	WIN32API_INFO("\tcreated dialog hwnd = $%08x\n", hWnd);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		WIN32API_INFO("\tshow dialog\n");
		window->Show(true);
		bool loop = true;
		while (loop) {
			MSG msg;
			GetMessageW(&msg, NULL, 0, 0);
			DispatchMessageW(&msg);
			if ((msg.hwnd == hWnd) && (msg.message == WM_xENDDIALOG)) {
				rc = GetWindowLongW(hWnd, DWL_MSGRESULT);
				WIN32API_INFO("\tDialog Result: %d\n", rc);
				DestroyWindow(hWnd);
				loop = false;
			}
		}
	}
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateDialogParamA
(HINSTANCE hInstance, LPCSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
{
	WIN32API_POINTER(lpTemplateName);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(dwInitParam);
	WIN32API_ENTER("HWND", "CreateDialogParamA", "HINSTANCE", hInstance, "LPCSTR", lpTemplateName, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", dwInitParam, NULL);
	WIN32API_INTERNAL_START();
	Win32String name;
	if (0 != (0xffff0000 & (UINT)lpTemplateName)) {
		name.SetToA(lpTemplateName);
		lpTemplateName = (LPCSTR)name.StringW();
	}
	HWND rc = CreateDialogParamW(hInstance, (LPCWSTR)lpTemplateName, hWndParent, lpDialogFunc, dwInitParam);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateDialogParamW
(HINSTANCE hInstance, LPCWSTR lpTemplateName, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM dwInitParam)
{
	HWND rc = NULL;
	WIN32API_POINTER(lpTemplateName);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(dwInitParam);
	WIN32API_ENTER("HWND", "CreateDialogParamW", "HINSTANCE", hInstance, "LPCSTR", lpTemplateName, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", dwInitParam, NULL);
#if defined(_DEBUG)
	Win32String name;
	if (0 != (0xffff0000 & (UINT)lpTemplateName)) {
		name.SetToW(lpTemplateName);
		WIN32API_INFO("\tlpTemplateName: %s\n", name.StringU());
	} else {
		WIN32API_INFO("\tlpTemplateName: #%d\n", lpTemplateName);
	}
#endif	// defined(_DEBUG)
	try {
		Image *image = HandleToImage(hInstance);
		if (NULL == image) throw ERROR_INVALID_HANDLE;
		void *base = image->GetResourceAddress();
		if (NULL == base) throw ERROR_RESOURCE_DATA_NOT_FOUND;
		HRSRC rsrc = FindResourceW((HMODULE)hInstance, lpTemplateName, MAKEINTRESOURCEW(RT_DIALOG));
		if (NULL != rsrc) {
			LpResourceDataEntry rde = (LpResourceDataEntry)((UINT)base + (UINT)rsrc);
			WIN32API_INTERNAL_START();
			rc = CreateDialogIndirectParamW(hInstance, (LPCDLGTEMPLATE)((UINT)hInstance + rde->DataRva), hWndParent, lpDialogFunc, dwInitParam);
			WIN32API_INTERNAL_END();
		}
	} catch (int e) {
		WIN32API_ERROR(e);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateDialogIndirectParamA
(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit)
{
	WIN32API_POINTER(lpTemplate);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(lParamInit);
	WIN32API_ENTER("HWND", "CreateDialogIndirectParamA", "HINSTANCE", hInstance, "LPCDLGTEMPLATE", lpTemplate, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", lParamInit, NULL);
	WIN32API_INTERNAL_START();
	HWND rc = CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, lParamInit);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateDialogIndirectParamW
(HINSTANCE hInstance, LPCDLGTEMPLATE lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc, LPARAM lParamInit)
{
	WIN32API_POINTER(lpTemplate);
	WIN32API_POINTER(lpDialogFunc);
	WIN32API_POINTER(lParamInit);
	WIN32API_ENTER("HWND", "CreateDialogIndirectParamW", "HINSTANCE", hInstance, "LPCDLGTEMPLATE", lpTemplate, "HWND", hWndParent, "DLGPROC", lpDialogFunc, "LPARAM", lParamInit, NULL);
	HWND rc = CreateDialogIndirectParam(hInstance, lpTemplate, hWndParent, lpDialogFunc, lParamInit);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EndDialog
(HWND hWnd, INT nResult)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EndDialog", "HWND", hWnd, "INT", nResult, NULL);
	WIN32API_INTERNAL_START();
	SetWindowLongW(hWnd, DWL_MSGRESULT, (LONG)nResult);
	PostMessageW(hWnd, WM_xENDDIALOG, 0, 0);
	if (ERROR_SUCCESS == GetLastError()) rc = TRUE;
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" long WINAPI
GetDialogBaseUnits
(void)
{
	long rc = (long)-1;
	WIN32API_ENTER("long", "GetDialogBaseUnits", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsDialogMessageA
(HWND arg0, LPMSG arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsDialogMessageA", "HWND", arg0, "LPMSG", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsDialogMessageW
(HWND arg0, LPMSG arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsDialogMessageW", "HWND", arg0, "LPMSG", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MapDialogRect
(HWND arg0, LPRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MapDialogRect", "HWND", arg0, "LPRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefDlgProcA
(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("LRESULT", "DefDlgProcA", "HWND", hDlg, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	WIN32API_INTERNAL_START();
	LRESULT rc = DefDlgProcW(hDlg, Msg, wParam, lParam);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefDlgProcW
(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("LRESULT", "DefDlgProcW", "HWND", hDlg, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	WIN32API_INTERNAL_START();
	LRESULT rc = DefWindowProcW(hDlg, Msg, wParam, lParam);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}
