/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ButtonWindowClass.h,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ButtonWindowClass.h]
 * -------------------------------------------------------------------------------------------- */
#include "Window.h"

#define	BS_PUSHBUTTON		0x00000000L
#define	BS_DEFPUSHBUTTON	0x00000001L
#define	BS_CHECKBOX			0x00000002L
#define	BS_AUTOCHECKBOX		0x00000003L
#define	BS_RADIOBUTTON		0x00000004L
#define	BS_3STATE			0x00000005L
#define	BS_AUTO3STATE		0x00000006L
#define	BS_GROUPBOX			0x00000007L
#define	BS_USERBUTTON		0x00000008L
#define	BS_AUTORADIOBUTTON	0x00000009L
#define	BS_OWNERDRAW		0x0000000bL
#define	BS_LEFTTEXT			0x00000020L

#define	BS_TEXT				0x00000000L
#define	BS_ICON				0x00000040L
#define	BS_BITMAP			0x00000080L
#define	BS_LEFT				0x00000100L
#define	BS_RIGHT			0x00000200L
#define	BS_CENTER			(BS_LEFT | BS_RIGHT)
#define	BS_TOP				0x00000400L
#define	BS_BOTTOM			0x00000800L
#define	BS_VCENTER			(BS_TOP | BS_BOTTOM)
#define	BS_PUSHLIKE			0x00001000L
#define	BS_MULTILINE		0x00002000L
#define	BS_NOTIFY			0x00004000L
#define	BS_FLAT				0x00008000L
#define	BS_RIGHTBUTTON		BS_LEFTTEXT

typedef Window _Window;
class Win32Button: public BButton {
private:
	_Window *window;
public:
	Win32Button(BRect rect, LPCSTR lpTitle):
		BButton(rect, "win32 button", lpTitle, NULL),
		window(NULL) {
	};
	status_t Invoke(BMessage *msg) {
		if (NULL != window) window->PostMessage(BM_CLICK, 0, 0);
		BButton::Invoke(msg);
		return B_OK;
	};
	void SetWindow(_Window *window) {
		this->window = window;
	};
};

static LRESULT
ButtonProc
(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	Window *window = Window::HandleToWindow(hWnd);
	LocalWindow *lwnd = DYNAMIC_CAST(LocalWindow *, window);
	LRESULT rc = 0;
	switch (nMsg) {
	case WM_CREATE: {
		WIN32API_INFO("\tButtonProc::WM_CREATE\n");
		if (NULL != lwnd) {
			BView *view = lwnd->LockView();
			Win32Button *btn = DYNAMIC_CAST(Win32Button *, view);
			if (NULL != btn) btn->SetWindow(window);
			lwnd->UnlockView();
		}
		break; }
	case BM_SETCHECK: {
		WIN32API_INFO("\tButtonProc::BM_SETCHECK: %d\n", wParam);
		if (NULL != lwnd) {
			BView *view = lwnd->LockView();
			BControl *ctrl = DYNAMIC_CAST(BControl *, view);
			if (NULL != ctrl) {
				switch ((int)wParam) {
				case BST_UNCHECKED:
					ctrl->SetValue(B_CONTROL_OFF);
					rc = (LRESULT)TRUE;
					break;
				case BST_CHECKED:
					ctrl->SetValue(B_CONTROL_ON);
					rc = (LRESULT)TRUE;
					break;
				default:
					WIN32API_INFO("\tunsupported state\n");
				}
			}
			lwnd->UnlockView();
		}
		break; }
	case BM_CLICK: {
		WIN32API_INFO("\tButtonProc::BM_CLICK\n");
		WIN32API_INTERNAL_START();
		HWND hParentWnd = GetParent(hWnd);
		int id = GetDlgCtrlID(hWnd);
		PostMessageW(hParentWnd, WM_COMMAND, (BN_CLICKED << 16) | id, (LPARAM)hWnd);
//		PostMessageW(hParentWnd, WM_COMMAND, (BN_PUSHED << 16) | id, (LPARAM)hWnd);
//		PostMessageW(hParentWnd, WM_COMMAND, (BN_UNPUSHED << 16) | id, (LPARAM)hWnd);
		WIN32API_INTERNAL_END();
		break; }
	default:
		WIN32API_INFO("\t*** ButtonProc ***\n");
	}
	return rc;
}

static BView *
ButtonCreateCustomView
(HINSTANCE hInstance, BRect rect, LPCSTR lpTitle, DWORD &style)
{
	BControl *rc = NULL;
	int type = style & 0xf;
	style &= ~0xf;
	switch (type) {
	case BS_DEFPUSHBUTTON:
	case BS_PUSHBUTTON: {
		BButton *btn = new Win32Button(rect, lpTitle);
		if ((NULL != btn) && (type == BS_DEFPUSHBUTTON)) btn->MakeDefault(true);
		rc = btn;
		break; }
	case BS_CHECKBOX:
	case BS_AUTOCHECKBOX:
		rc = new BCheckBox(rect, "win32 button", lpTitle, new BMessage((uint32)0));
		break;
	default:
		WIN32API_INFO("\tunknown button type: %d\n", type);
	}
	if (NULL != rc) {
		rc->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
		if (0 != (style & WS_DISABLED)) {
			style &= ~WS_DISABLED;
			rc->SetEnabled(false);
		}
	}
	return rc;
}

static WNDCLASSA
ButtonClass = {
	0,
	ButtonProc,
	0,
	0,
	NULL, NULL, NULL, NULL,
	NULL, "BUTTON",
};

static WindowClass
ButtonWindowClass(&ButtonClass, ButtonCreateCustomView);
