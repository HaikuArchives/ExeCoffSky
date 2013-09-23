/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DialogWindowClass.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DialogWindowClass.h]
 * -------------------------------------------------------------------------------------------- */

static LRESULT
DialogProc
(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	Window *window = Window::HandleToWindow(hWnd);
	if (nMsg == WM_CREATE) {
		LPCREATESTRUCT cs = (LPCREATESTRUCT)lParam;
		LONG lpDialogFunc = (LONG)cs->lpCreateParams;
		WIN32API_INFO("\tDialogProc::SetDialogCallback = $%08x\n", lpDialogFunc);
		window->SetWindowLong(GWL_xDIALOGPROC, lpDialogFunc);
	}
	DLGPROC dlgProc = (DLGPROC)window->GetWindowLong(GWL_xDIALOGPROC);
	if (NULL == dlgProc) return 0;
	LRESULT rc = 0;
	int ct;
	WIN32API_INFO("\t+++ DialogProc::lpDialogFunc +++\n");
	WIN32API_INTERNAL_GET(ct);
	rc = dlgProc(hWnd, nMsg, wParam, lParam);
	WIN32API_INTERNAL_SET(ct);
	WIN32API_INFO("\t--- DialogProc::lpDialogFunc: $%08x ---\n", rc);
	return rc;
}

static WNDCLASSA
DialogClass = {
	0,
	DialogProc,
	0,
	0,
	NULL, NULL, NULL, NULL,
	NULL, "Dialog",
};

static WindowClass
DialogWindowClass(&DialogClass);
