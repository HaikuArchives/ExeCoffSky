/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: MessageBox.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [MessageBox.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "MessageBox.h"
#include "Win32Trace.h"
#include "Win32Structures.h"
#include "Win32String.h"

static int
MessageBoxU
(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
	int rc;
	WIN32API_INFO("lpText = %s\n", lpText);
	WIN32API_INFO("lpCaption = %s\n", lpCaption);
	char *buttons[6][3] = {
		{ "OK", NULL, NULL, },
		{ "OK", "Cancel", NULL, },
		{ "Abort", "Retry", "Ignore", },
		{ "Yes", "No", "Cancel", },
		{ "Yes", "No", NULL, },
		{ "Retry", "Cancel", NULL, },
	};
	int btntype = (uType & 0xf) % 6;
	alert_type atype = B_EMPTY_ALERT;
	switch (uType & 0xf0) {
	case MB_ICONHAND:
		atype = B_STOP_ALERT;
		break;
	case MB_ICONQUESTION:
		atype = B_IDEA_ALERT;
		break;
	case MB_ICONEXCLAMATION:
		atype = B_WARNING_ALERT;
		break;
	case MB_ICONASTERISK:
		atype = B_INFO_ALERT;
		break;
	}
	BAlert *mbox = new BAlert(lpCaption, lpText,
		buttons[btntype][0], buttons[btntype][1], buttons[btntype][2],
		B_WIDTH_AS_USUAL, B_OFFSET_SPACING, atype);
	if (NULL == mbox) return 0;
	mbox->SetLook(B_TITLED_WINDOW_LOOK);
	uint32 flags = mbox->Flags();
	flags |= B_NOT_ZOOMABLE;
	mbox->SetFlags(flags);
	int defbtn = (uType & 0xf00) >> 16;
	mbox->SetShortcut(defbtn, B_ENTER);
	mbox->SetDefaultButton(mbox->ButtonAt(defbtn));
	int escape[6] = {
		1, 2, 3, 3, 2, 2,
	};
	mbox->SetShortcut(escape[btntype], B_ESCAPE);
	uType &= ~0xfff;
	if (0 != uType) WIN32API_INFO("\tignore type: 0x%08x\n", uType);
	rc = mbox->Go();
	int results[6][3] = {
		{ MB_IDOK, 0, 0, },
		{ MB_IDOK, MB_IDCANCEL, 0, },
		{ MB_IDABORT, MB_IDRETRY, MB_IDIGNORE, },
		{ MB_IDYES, MB_IDNO, MB_IDCANCEL, },
		{ MB_IDYES, MB_IDNO, 0, },
		{ MB_IDRETRY, MB_IDCANCEL, 0, },
	};
	rc = results[btntype][rc];
	return rc;
}

extern "C" int WINAPI
MessageBoxA
(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
	int rc = 0;
	WIN32API_POINTER(lpText);
	WIN32API_POINTER(lpCaption);
	WIN32API_ENTER("int", "MessageBoxA", "HWND", hWnd, "LPCSTR", lpText, "LPCSTR", lpCaption, "UINT", uType, NULL);
	Win32String text;
	Win32String caption;
	text.SetToA(lpText);
	caption.SetToA(lpCaption);
	rc = MessageBoxU(hWnd, text.StringU(), caption.StringU(), uType);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MessageBoxW
(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
	int rc = 0;
	WIN32API_POINTER(lpText);
	WIN32API_POINTER(lpCaption);
	WIN32API_ENTER("int", "MessageBoxW", "HWND", hWnd, "LPCWSTR", lpText, "LPCWSTR", lpCaption, "UINT", uType, NULL);
	Win32String text;
	Win32String caption;
	text.SetToW(lpText);
	caption.SetToW(lpCaption);
	rc = MessageBoxU(hWnd, text.StringU(), caption.StringU(), uType);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MessageBoxExA
(HWND arg0, LPCSTR arg1, LPCSTR arg2, UINT arg3, WORD arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "MessageBoxExA", "HWND", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "UINT", arg3, "WORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MessageBoxExW
(HWND arg0, LPCWSTR arg1, LPCWSTR arg2, UINT arg3, WORD arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "MessageBoxExW", "HWND", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "UINT", arg3, "WORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MessageBoxIndirectA
(LPMSGBOXPARAMSA arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "MessageBoxIndirectA", "LPMSGBOXPARAMSA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
MessageBoxIndirectW
(LPMSGBOXPARAMSW arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "MessageBoxIndirectW", "LPMSGBOXPARAMSW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
