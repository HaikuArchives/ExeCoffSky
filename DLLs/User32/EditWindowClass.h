/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: EditWindowClass.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [EditWindowClass.h]
 * -------------------------------------------------------------------------------------------- */

static LRESULT
EditProc
(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	Window *window = Window::HandleToWindow(hWnd);
	LRESULT rc = 0;
	switch (nMsg) {
	case WM_SETTEXT: {
		WIN32API_INFO("\tEditProc::WM_SETTEXT: %s\n", (char *)lParam);
		LocalWindow *lwnd = DYNAMIC_CAST(LocalWindow *, window);
		if (NULL != lwnd) {
			BView *view = lwnd->LockView();
			BTextControl *text = DYNAMIC_CAST(BTextControl *, view);
			if (NULL != text) {
				text->Window()->Lock();
				text->SetText((const char *)lParam);
				text->Window()->Unlock();
				rc = (LRESULT)TRUE;
			}
			lwnd->UnlockView();
		}
		break; }
	default:
		WIN32API_INFO("\t*** EditProc ***\n");
	}
	return rc;
}

static BView *
EditCreateCustomView
(HINSTANCE hInstance, BRect rect, LPCSTR lpTitle, DWORD &style)
{
//	BRect text(0, 0, rect.Width(), rect.Height());
//	return new BTextView(rect, "win32 edit", text, 0);
	BView *rc = new BTextControl(rect, "win32 edit", NULL, lpTitle, NULL);
	if (NULL != rc) rc->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	return rc;
}

static WNDCLASSA
EditClass = {
	0,
	EditProc,
	0,
	0,
	NULL, NULL, NULL, NULL,
	NULL, "EDIT",
};

static WindowClass
EditWindowClass(&EditClass, EditCreateCustomView);
