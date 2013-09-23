/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Window.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Window.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Window.h"
#include "WindowClass.h"
#include "Thread.h"
#include "Process.h"
#include "Timer.h"
#include "LoadResources.h"
#include "Menu.h"
#include "SystemMetrics.h"
#include "Message.h"
#include "Desktop.h"
#include "CallWindowProcAsm.h"
#include "GDI32/DeviceContext.h"
#include "GDI32/Bitmap.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

Window::Window
(void):
magic(WINDOW_MAGIC),
id(0),
parent(NULL)
{
	memset(param, 0, sizeof(LONG) * WINDOWLONG_MAX);
}

Window::~Window
(void)
{
	magic = 0;
	// XXX: delete children
	if (NULL != parent) parent->RemoveChild(this);
}

bool
Window::AddTimer
(Timer *timer)
{
	return this->timer.AddItem((void *)timer);
}

bool
Window::RemoveTimer
(Timer *timer)
{
	return this->timer.RemoveItem((void *)timer);
}

Timer *
Window::FindTimer
(UINT nIDEvent)
{
	struct find f;
	Lock();
	f.nIDEvent = nIDEvent;
	f.result = NULL;
	timer.DoForEach(FindTimerCallback, (void *)&f);
	Unlock();
	return f.result;
}

void
Window::SetID
(int id)
{
	Lock();
	this->id = id;
	Unlock();
}

int
Window::GetID
(void)
{
	Lock();
	int rc = id;
	Unlock();
	return rc;
}

void
Window::SetParent
(Window *window)
{
	Lock();
	parent = window;
	SetWindowLong(GWL_HWNDPARENT, (LONG)parent);
	Unlock();
}

bool
Window::AddChild
(Window *window)
{
	window->SetParent(this);
	return children.AddItem((void *)window);
}

bool
Window::RemoveChild
(Window *window)
{
	window->SetParent(NULL);
	return children.RemoveItem((void *)window);
}

BOOL
Window::EnumChildWindows
(WNDENUMPROC lpEnumProc, LPARAM lParam)
{
	Lock();
	BList cpyList;
	int32 n = children.CountItems();
	for (int32 i = 0; i < n; i++) cpyList.AddItem(children.ItemAt(i));
	Unlock();
	for (int32 i = 0; i < n; i++) {
		HWND hWnd = (HWND)cpyList.ItemAt(i);
		WIN32API_INFO("\t+++ EnumChildWindows: $%08x (child %d) +++\n", hWnd, (int)i);
		int ct;
		WIN32API_INTERNAL_GET(ct);
		BOOL rc = lpEnumProc(hWnd, lParam);
		WIN32API_INTERNAL_SET(ct);
		WIN32API_INFO("\t--- EnumChildWindows ---\n");
		if (FALSE == rc) break;
	}
	WIN32API_ERROR(ERROR_SUCCESS);
	return TRUE;
}

Window *
Window::HandleToWindow
(HWND hWnd)
{
	WIN32API_INTERNAL_START();
	if (NULL == hWnd) hWnd = GetDesktopWindow();
	WIN32API_INTERNAL_END();
	if (INVALID_HANDLE_VALUE == hWnd) return NULL;
	Window *window = (Window *)hWnd;
	if (window->magic != WINDOW_MAGIC) return NULL;
	return window;
}

bool
Window::FindTimerCallback
(void *item, void *arg)
{
	Timer *timer = (Timer *)item;
	struct find *f = (struct find *)arg;
	if (timer->id != f->nIDEvent) return false;
	f->result = timer;
	return true;
}

LONG
Window::GetWindowLong
(int nIndex)
{
	Lock();
	LONG rc = param[MAKEWLINDEX(nIndex)];
	Unlock();
	return rc;
}

LONG
Window::SetWindowLong
(int nIndex, LONG newLong)
{
	Lock();
	int i = MAKEWLINDEX(nIndex);
	LONG rc = param[i];
	param[i] = newLong;
	Unlock();
	return rc;
}

void
Window::Update
(BBitmap *bmp, LPRECT rect)
{
	WIN32API_INFO("Window::Update => empty function\n");
}

NativeWindow::NativeWindow
(LocalWindow *owner, BRect frame, const char *title, window_look look, window_feel feel, uint32 flags):
BWindow(frame, title, look, feel, flags),
owner(owner),
quitflag(false)
{
	WIN32API_INFO("\tnative window look: $%08x\n", look);
	WIN32API_INFO("\tnative window feel: $%08x\n", feel);
	WIN32API_INFO("\tnative window flags: $%08x\n", flags);
}

NativeWindow::~NativeWindow
(void)
{
	owner->Lock();
	owner->window = NULL;
	owner->Unlock();
}

bool
NativeWindow::QuitRequested
(void)
{
	if (quitflag) return true;
	owner->PostMessage(WM_SYSCOMMAND, SC_CLOSE, 0);
	return false;
}

void
NativeWindow::Quit
(void)
{
	quitflag = true;
	BWindow::Quit();
}

NativeView::NativeView
(NativeWindow *owner, LocalWindow *window, BRect rect):
BView(rect, "", B_FOLLOW_ALL_SIDES, B_WILL_DRAW),
owner(owner),
window(window)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	WIN32API_INFO("\tnative view color set\n");
}

NativeView::~NativeView
(void)
{
}

void
NativeView::Draw
(BRect rect)
{
	// XXX
	window->PostMessage(WM_PAINT, 0, 0);
}

void
NativeView::MouseDown
(BPoint point)
{
	BMessage *message = Window()->CurrentMessage();
	if (NULL == message) return;
	int32 buttons;
	if (B_OK != message->FindInt32("buttons", &buttons)) return;
	WPARAM wParam = 0;
	LPARAM lParam = (int)point.x | ((int)point.y << 16);
	if (0 != (buttons & B_PRIMARY_MOUSE_BUTTON)) wParam |= MK_LBUTTON;
	if (0 != (buttons & B_SECONDARY_MOUSE_BUTTON)) wParam |= MK_RBUTTON;
	if (0 != (buttons & B_TERTIARY_MOUSE_BUTTON)) wParam |= MK_MBUTTON;
	if (0 != (buttons & B_PRIMARY_MOUSE_BUTTON)) window->PostMessage(WM_LBUTTONDOWN, wParam, lParam);
	if (0 != (buttons & B_SECONDARY_MOUSE_BUTTON)) window->PostMessage(WM_RBUTTONDOWN, wParam, lParam);
	if (0 != (buttons & B_TERTIARY_MOUSE_BUTTON)) window->PostMessage(WM_MBUTTONDOWN, wParam, lParam);
}

void
NativeView::MouseUp
(BPoint point)
{
	BMessage *message = Window()->CurrentMessage();
	if (NULL == message) return;
	int32 buttons;
	if (B_OK != message->FindInt32("buttons", &buttons)) return;
	WPARAM wParam = 0;
	LPARAM lParam = (int)point.x | ((int)point.y << 16);
	if (0 != (buttons & B_PRIMARY_MOUSE_BUTTON)) wParam |= MK_LBUTTON;
	if (0 != (buttons & B_SECONDARY_MOUSE_BUTTON)) wParam |= MK_RBUTTON;
	if (0 != (buttons & B_TERTIARY_MOUSE_BUTTON)) wParam |= MK_MBUTTON;
	if (0 == (buttons & B_PRIMARY_MOUSE_BUTTON)) window->PostMessage(WM_LBUTTONUP, wParam, lParam);
	if (0 == (buttons & B_SECONDARY_MOUSE_BUTTON)) window->PostMessage(WM_RBUTTONUP, wParam, lParam);
	if (0 == (buttons & B_TERTIARY_MOUSE_BUTTON)) window->PostMessage(WM_MBUTTONUP, wParam, lParam);
}

void
NativeView::MouseMoved
(BPoint point, uint32 transit, const BMessage *message)
{
	window->PostMessage(WM_MOUSEMOVE, 0, (LPARAM)((int)point.x | ((int)point.y << 16)));
}

void
NativeView::WindowActivated
(bool active)
{
	void *todo = NULL;
	window->PostMessage(WM_ACTIVATEAPP, (WPARAM)(active? TRUE: FALSE), (LPARAM)todo);
	window->PostMessage(WM_ACTIVATE, (WPARAM)(active? WA_ACTIVE: WA_INACTIVE), (LPARAM)window);
}

LocalWindow::LocalWindow
(void):
window(NULL),
view(NULL),
wc(NULL),
owner_thread(0),
message_port(0),
reply_port(0),
dc(NULL),
bmp(NULL),
menu(NULL)
{
}

LocalWindow::~LocalWindow
(void)
{
	Lock();
	if (NULL != window) {
		Unlock();
		window->Lock();
		window->Quit();
	} else {
		Unlock();
	}
	if (NULL != dc) delete dc;
	if (NULL != bmp) delete bmp;
	if (NULL != menu) delete menu;
	if (0 != reply_port) close_port(reply_port);
}

bool
LocalWindow::Create
(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle,
	int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	if (INVALID_HANDLE_VALUE == hWndParent) hWndParent = NULL;
	dc = new DeviceContext();
	BScreen scr;
	int depth;
	if (B_RGB32 == scr.ColorSpace()) depth = 32;
	else depth = 16;
	bmp = new Bitmap(nWidth, -nHeight, depth);
	if ((NULL == dc) || (NULL == bmp)) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		return false;
	}
	dc->SetOwnerWindow(this);
	dc->SelectBitmap(bmp);
	Thread *thread = Thread::GetCurrentThreadObject();
	owner_thread = thread->GetID();
	message_port = thread->GetPort();
	if (CW_USEDEFAULT == x) x = 100;	// XXX
	if (CW_USEDEFAULT == y) y = 100;	// XXX
	wc = WindowClass::FindClass(lpClassName);
	if (NULL == wc) return false;

	SetWindowLong(GWL_WNDPROC, (LONG)wc->lpfnWndProc);
	SetWindowLong(GWL_HINSTANCE, (LONG)hInstance);
	SetWindowLong(GWL_HWNDPARENT, (LONG)hWndParent);
	SetWindowLong(GWL_STYLE, (LONG)dwStyle);
	SetWindowLong(GWL_EXSTYLE, (LONG)dwExStyle);
	SetWindowLong(GWL_ID, (LONG)hMenu);

	DWORD style = (0 != dwStyle)? dwStyle: wc->style;
	window_feel feel = B_NORMAL_WINDOW_FEEL;
	window_look look = B_NO_BORDER_WINDOW_LOOK;
	int flags = B_NOT_ZOOMABLE | B_NOT_MINIMIZABLE | B_NOT_RESIZABLE;
	if (0 != (style & WS_CAPTION)) {
		look = B_TITLED_WINDOW_LOOK;
		style &= ~(WS_CAPTION | WS_BORDER);
	} else if (0 != (style & (WS_BORDER | WS_DLGFRAME))) {
		look = B_BORDERED_WINDOW_LOOK;
		style &= ~(WS_BORDER | WS_DLGFRAME);
	}
	if (0 != (style & WS_MINIMIZEBOX)) {
		flags &= ~B_NOT_MINIMIZABLE;
		style &= ~WS_MINIMIZEBOX;
	}
	if (0 != (style & WS_MAXIMIZEBOX)) {
		flags &= ~B_NOT_ZOOMABLE;
		style &= ~WS_MAXIMIZEBOX;
	}
	if (0 != (style & WS_THICKFRAME)) {
		flags &= ~B_NOT_RESIZABLE;
		style &= ~WS_THICKFRAME;
	}
	if (0 != (style & WS_CHILD)) {
		SetID((int)hMenu);
		hMenu = NULL;
	}
	if (NULL != hWndParent) feel = B_MODAL_SUBSET_WINDOW_FEEL;
	if (NULL == hMenu) {
		WIN32API_INTERNAL_START();
		if (wc->lpszMenuName != NULL) menu = (Menu *)LoadMenuA(hInstance, wc->lpszMenuName);
		else menu = NULL;
		WIN32API_INTERNAL_END();
	} else {
		WIN32API_INFO("\tignore menu\n");
	}

	BRect rect(x, y, x + nWidth - 1, y + nHeight - 1);
	if (0 == (style & WS_CHILD)) {
		LPCSTR windowname = lpWindowName;
		if (0 == (0xffff0000 & (UINT)lpWindowName)) windowname = NULL;
		window = new NativeWindow(this, rect, lpWindowName, look, feel, flags);
		if (NULL == window) {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			return false;
		}
		if (NULL != menu) {
			window->AddChild(menu->GetNativeMenu());
			rect.SetLeftTop(BPoint(0, menu->GetNativeMenu()->Frame().Height() + 1));
		} else {
			rect.SetLeftTop(BPoint(0, 0));
		}
		view = new NativeView(window, this, rect);
		if (NULL == view) {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			return false;
		}
		window->AddChild(view);
	} else {
		view = wc->CreateCustomView(hInstance, rect, lpWindowName, style);
		WIN32API_INFO("\tcustom view: %p\n", view);
		if (NULL == view) view = new NativeView(window, this, rect);	// XXX
		if (NULL == view) return false;
	}
	if (NULL != hWndParent) {
		Window *pwnd = Window::HandleToWindow(hWndParent);
		if (NULL != pwnd) pwnd->AddChild(this);
		LocalWindow *lwnd = DYNAMIC_CAST(LocalWindow *, pwnd);
		if (NULL != lwnd) {
			if (0 == (style & WS_CHILD)) {
				Lock();
//				lwnd->AddSubset(window);
				Unlock();
			} else {
				lwnd->AddChild(view);
				style &= ~WS_CHILD;
				WIN32API_INFO("\tadd to parent view's child\n");
			}
		} else {
			WIN32API_INFO("\tinvalid parent window\n");
		}
	}
	CREATESTRUCT cs;
	cs.lpCreateParams = lpParam;
	cs.hInstance = Process::GetCurrentProcessObject()->GetInstance();
	cs.hMenu = hMenu;
	cs.hwndParent = hWndParent;
	cs.cy = nHeight;
	cs.cx = nWidth;
	cs.y = y;
	cs.x = x;
	cs.style = dwExStyle;
	cs.lpszName =  lpWindowName;	// XXX: A/W
	cs.lpszClass = lpClassName;	// XXX: A/W
	cs.dwExStyle = dwExStyle;
	LRESULT result;
//	result = SendMessage(WM_GETMINMAXINFO, 0, 0);	// XXX
	result = SendMessage(WM_NCCALCSIZE, 0, 0);	// XXX
//	result = SendMessage(WM_ACTIVATEAPP, (WPARAM)TRUE, 0);
	result = SendMessage(WM_NCCREATE, 0, (LPARAM)&cs);
	WIN32API_INFO("\tWM_NCCREATE reply %d\n", result);
	if ((LRESULT)-1 == result) {
		if (NULL != window) window->Run();
		return false;
	}
	result = SendMessage(WM_CREATE, 0, (LPARAM)&cs);
	WIN32API_INFO("\tWM_CREATE reply %d\n", result);
	if ((LRESULT)-1 == result) {
		if (NULL != window) window->Run();
		return false;
	}
	if (0 != (style & WS_MINIMIZE)) {
		if (NULL != window) {
			window->Minimize(true);
			style &= ~WS_MINIMIZE;
		}
	}
	if (0 != (style & WS_MAXIMIZE)) {
		if (NULL != window) {
			window->Zoom();
			style &= ~WS_MAXIMIZE;
		}
	}
	if (0 != (style & WS_VISIBLE)) {
		if (NULL != window) {
			window->Show();
			style &= ~WS_VISIBLE;
		}
	}
	if (0 != style) WIN32API_INFO("\tignore style: $%08x\n", style);
	if (0 != dwExStyle) WIN32API_INFO("\tignore exstyle: $%08x\n", dwExStyle);
	return true;
}

DeviceContext *
LocalWindow::GetDeviceContext
(void) const
{
	return dc;
}

bool
LocalWindow::Show
(bool show)
{
	Lock();
	if (NULL != window) {
		int32 n = subsets.CountItems();
		if (show) for (int32 i = 0; i < n; i++) window->AddToSubset((BWindow *)subsets.ItemAt(i));
		else for (int32 i = 0; i < n; i++) window->RemoveFromSubset((BWindow *)subsets.ItemAt(i));
	} else {
		WIN32API_INFO("\twindow = (null)\n");
		Unlock();
		return false;
	}
	window->Lock();
	WIN32API_INFO("\tLocalWindow::Show(%s)\n", show? "true": "false");
	if (show) window->Show();
	else window->Hide();
	window->Unlock();
	Unlock();
	LPARAM todo = 0;
	PostMessage(WM_SHOWWINDOW, (WPARAM)(show? TRUE: FALSE), todo);
	return true;
}

bool
LocalWindow::GetTitle
(LPSTR lpTitle, UINT &uSize)
{
	// XXX: todo
	return false;
}

bool
LocalWindow::SetTitle
(LPCSTR lpTitle)
{
	bool rc = false;
	Lock();
	if (NULL != window) {
		window->Lock();
		window->SetTitle(lpTitle);
		window->Unlock();
		rc = true;
	}
	Unlock();
	return rc;
}

BOOL
LocalWindow::GetWindowRect
(LPRECT lpRect)
{
	BRect rect;
	Lock();
	if (NULL != window) {
		WIN32API_INFO("\twindow frame\n");
		rect = window->Frame();
	} else if (NULL != view) {
		BWindow *window = view->Window();
		if (NULL != window) window->Lock();
		rect = view->Bounds();
		WIN32API_INFO("\tview bounds (%f, %f) - (%f, %f)\n",
			rect.left, rect.top, rect.right, rect.bottom);
		rect = view->ConvertToScreen(rect);
		if (NULL != window) window->Unlock();
	}
	Unlock();
	lpRect->left = (LONG)rect.left;
	lpRect->top = (LONG)rect.top;
	lpRect->right = (LONG)rect.right + 1;
	lpRect->bottom = (LONG)rect.bottom + 1;
	WIN32API_INFO("\t(%d, %d) - (%d, %d)\n", lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
	WIN32API_ERROR(ERROR_SUCCESS);
	return TRUE;
}

BOOL
LocalWindow::SetWindowPos
(HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
	if (0 == (uFlags & SWP_NOSIZE)) {
		WIN32API_INFO("\tresize: %d x %d\n", cx, cy);
		if (NULL != window) window->ResizeTo((float)cx, (float)cy);
	} else uFlags &= ~SWP_NOSIZE;
	if (0 == (uFlags & SWP_NOMOVE)) {
		WIN32API_INFO("\tmove: (%d, %d)\n", X, Y);
		if (NULL != window) window->MoveTo((float)X, (float)Y);
	} else uFlags &= ~SWP_NOMOVE;
	if (0 != uFlags) WIN32API_INFO("\tignore uFlags: $%08x\n", uFlags);
	return TRUE;
}

void
LocalWindow::AddChild
(BView *aView)
{
	view->AddChild(aView);
}

void
LocalWindow::AddSubset
(BWindow *subset)
{
	subsets.AddItem((void *)subset);
}

LRESULT
LocalWindow::SendMessage
(LPCMSG lpMsg)
{
	LRESULT rc = 0;
	if (owner_thread == Thread::GetCurrentThreadId()) {
		// direct call
		int ct;
		WIN32API_INFO("\t+++ SendMessage +++\n");
		WIN32API_INFO("\t$%08x / $%08x / $%08x / $%08x\n", lpMsg->hwnd, lpMsg->message, lpMsg->wParam, lpMsg->lParam);
		WIN32API_INTERNAL_START();
		WNDPROC proc = (WNDPROC)GetWindowLong(GWL_WNDPROC);
		WIN32API_INTERNAL_END();
		WIN32API_INTERNAL_GET(ct);
		rc = CallWindowProcA(proc, lpMsg->hwnd, lpMsg->message, lpMsg->wParam, lpMsg->lParam);
		WIN32API_INTERNAL_SET(ct);
		WIN32API_INFO("\t--- SendMessage ---\n");
	} else {
		// send message over thread
		WIN32API_INFO("\t+++ SendMessage over Thread +++\n");
		WIN32API_INFO("\t$%08x / $%08x / $%08x / $%08x\n", lpMsg->hwnd, lpMsg->message, lpMsg->wParam, lpMsg->lParam);
		MSGEX msgex;
		memcpy(&msgex, lpMsg, sizeof(MSG));
		if (0 == reply_port) reply_port = create_port(1, "win32 reply");
		if (0 != reply_port) {
			msgex.reply_port = reply_port;
			if (B_OK != write_port_etc(message_port, PCODE_THREAD_SEND, &msgex, sizeof(MSGEX), B_TIMEOUT, 0)) {
				WIN32API_INFO("\t\tsend failed with timeout\n");
					WIN32API_ERROR(ERROR_TIMEOUT);
			} else {
				MSG msg;
				int32 code;
				ssize_t readsize;
				readsize = read_port(reply_port, &code, &msg, sizeof(MSG));
				if ((code != PCODE_THREAD_REPLY) || (readsize != sizeof(MSG))) {
					WIN32API_INFO("\tinvalid reply: code = %d / size = %d\n", code, readsize);
				} else {
					rc = msg.lParam;
					WIN32API_INFO("\t=> %d\n", rc);
				}
			}
		}
		WIN32API_INFO("\t--- SendMessage over Thread ---\n");
	}
	if ((lpMsg->message == WM_SYSCOMMAND) && (lpMsg->wParam == SC_CLOSE)) {
		if (0 != rc) {
			Lock();
			if (NULL != window) window->Quit();
			Unlock();
		}
	}
	return rc;
}

LRESULT
LocalWindow::SendMessage
(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	MSG msg;
	msg.hwnd = (HWND)this;
	msg.message = Msg;
	msg.wParam = wParam;
	msg.lParam = lParam;
	msg.time = (system_time() >> 32) & 0xffffffff;
	return SendMessage(&msg);
}

BOOL
LocalWindow::PostMessage
(LPCMSG lpMsg)
{
	WIN32API_INFO("\tpost message: $%08x\n", lpMsg->message);
	return (B_OK == write_port_etc(message_port, PCODE_THREAD_POST, lpMsg, sizeof(MSG), B_TIMEOUT, 1000))? TRUE: FALSE;
}

BOOL
LocalWindow::PostMessage
(UINT Msg, WPARAM wParam, LPARAM lParam)
{
	MSG msg;
	msg.hwnd = (HWND)this;
	msg.message = Msg;
	msg.wParam = wParam;
	msg.lParam = lParam;
	msg.time = (system_time() >> 32) & 0xffffffff;
	return PostMessage(&msg);
}

void
LocalWindow::ClientToScreen
(LPPOINT lpPoint)
{
	BPoint pt(lpPoint->x, lpPoint->y);
	Lock();
	if (NULL != window) {
		window->Lock();
		window->ConvertToScreen(&pt);
		window->Unlock();
	}
	Unlock();
	WIN32API_INFO("\t(%d, %d) => (%d, %d)\n", lpPoint->x, lpPoint->y, (LONG)pt.x, (LONG)pt.y);
	lpPoint->x = (LONG)pt.x;
	lpPoint->y = (LONG)pt.y;
}

void
LocalWindow::ScreenToClient
(LPPOINT lpPoint)
{
	BPoint pt(lpPoint->x, lpPoint->y);
	Lock();
	if (NULL != window) {
		window->Lock();
		window->ConvertFromScreen(&pt);
		window->Unlock();
	}
	Unlock();
	WIN32API_INFO("\t(%d, %d) => (%d, %d)\n", lpPoint->x, lpPoint->y, (LONG)pt.x, (LONG)pt.y);
	lpPoint->x = (LONG)pt.x;
	lpPoint->y = (LONG)pt.y;
}

void
LocalWindow::Update
(BBitmap *bmp, LPRECT rect)
{
	BRect brect;
	if (NULL != rect) brect.Set((float)rect->left, (float)rect->top, (float)rect->right, (float)rect->bottom);
	Lock();
	if (NULL == view) {
		WIN32API_INFO("\tview = (null)\n");
	} else {
#if defined(_DEBUG)
		color_space cs = bmp->ColorSpace();
		if (B_RGB32 == cs) WIN32API_INFO("\tLocalWindow::Update 32bit\n");
		else if (B_RGB16 == cs) WIN32API_INFO("\tLocalWindow::Update 16bit\n");
		BRect r = bmp->Bounds();
		WIN32API_INFO("\t%f x %f\n", r.Width(), r.Height());
#endif	// defined(_DEBUG)
		view->Window()->Lock();
		if (NULL == rect) view->DrawBitmap(bmp);
		else view->DrawBitmap(bmp, brect, brect);
		view->Window()->Unlock();
	}
	Unlock();
}

NativeWindow *
LocalWindow::LockNativeWindow
(void)
{
	Lock();
	return window;
}

void
LocalWindow::UnlockNativeWindow
(void)
{
	Unlock();
}

BView *
LocalWindow::LockView
(void)
{
	Lock();
	return view;
}

void
LocalWindow::UnlockView
(void)
{
	Unlock();
}

HWND
CreateWindowExU
(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	HWND rc = NULL;
	WIN32API_INFO("\tdwStyle: $%08x\n", dwStyle);
	WIN32API_INFO("\tdwExStyle: $%08x\n", dwExStyle);
	if (0 != (0xffff0000 & (UINT)lpClassName)) {
		WIN32API_INFO("\tClassName: %s\n", lpClassName);
	} else {
		WIN32API_INFO("\tClassName: #%d\n", (int)lpClassName);
	}
	if (0 != (0xffff0000 & (UINT)lpWindowName)) {
		WIN32API_INFO("\tWindowName: %s\n", lpWindowName);
	} else {
		WIN32API_INFO("\tWindowName: #%d\n", (int)lpWindowName);
	}
	WIN32API_INFO("\t(%d,%d)-(%d,%d)\n", x, y, x + nWidth, y + nHeight);
	WIN32API_INFO("\thWndParent: $%08x\n", hWndParent);
	WIN32API_INFO("\thMenu: $%08x\n", hMenu);
	WIN32API_INFO("\thInstance: $%08x\n", hInstance);
	WIN32API_INFO("\tlpParam: $%08x\n", lpParam);
	LocalWindow *window = new LocalWindow();
	if (NULL != window) {
		if (window->Create(dwExStyle, lpClassName, lpWindowName, dwStyle,
			x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)) {
			rc = (HWND)window;
			WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			delete window;
		}
	} else {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

BOOL
SetWindowTextU
(HWND hWnd, LPCSTR lpString)
{
	BOOL rc = FALSE;
	WIN32API_INFO("\tlpString: %s\n", lpString);
	Window *window = Window::HandleToWindow(hWnd);
	if ((NULL != window) && window->SetTitle(lpString)) rc = TRUE;
	return rc;
}

extern "C" HWND WINAPI
CreateWindowExA
(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	WIN32API_POINTER(lpClassName);
	WIN32API_POINTER(lpWindowName);
	WIN32API_POINTER(lpParam);
	WIN32API_ENTER("HWND", "CreateWindowExA", "DWORD", dwExStyle, "LPCSTR", lpClassName,
		"LPCSTR", lpWindowName, "DWORD", dwStyle, "int", x, "int", y, "int", nWidth, "int", nHeight,
		"HWND", hWndParent, "HMENU", hMenu, "HINSTANCE", hInstance, "LPVOID", lpParam, NULL);
	LPCSTR classname = NULL;
	Win32String cname;
	if (0 != (0xffff0000 & (UINT)lpClassName)) {
		cname.SetToA(lpClassName);
		classname = cname.StringU();
	} else {
		classname = (LPCSTR)lpClassName;
	}
	LPCSTR windowname = NULL;
	Win32String winname;
	if (0 != (0xffff0000 & (UINT)lpWindowName)) {
		winname.SetToA(lpWindowName);
		windowname = winname.StringU();
	} else {
		windowname = (LPCSTR)lpWindowName;
	}
	HWND rc = CreateWindowExU(dwExStyle, classname, windowname, dwStyle,
		x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
CreateWindowExW
(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	WIN32API_POINTER(lpClassName);
	WIN32API_POINTER(lpWindowName);
	WIN32API_POINTER(lpParam);
	WIN32API_ENTER("HWND", "CreateWindowExW", "DWORD", dwExStyle, "LPCWSTR", lpClassName,
		"LPCWSTR", lpWindowName, "DWORD", dwStyle, "int", x, "int", y, "int", nWidth, "int", nHeight,
		"HWND", hWndParent, "HMENU", hMenu, "HINSTANCE", hInstance, "LPVOID", lpParam, NULL);
	LPCSTR classname = NULL;
	Win32String cname;
	if (0 != (0xffff0000 & (UINT)lpClassName)) {
		cname.SetToW(lpClassName);
		classname = cname.StringU();
	} else {
		classname = (LPCSTR)lpClassName;
	}
	LPCSTR windowname;
	Win32String winname;
	if (0 != (0xffff0000 & (UINT)lpWindowName)) {
		winname.SetToW(lpWindowName);
		windowname = winname.StringU();
	} else {
		windowname = (LPCSTR)lpWindowName;
	}
	HWND rc = CreateWindowExU(dwExStyle, classname, windowname, dwStyle,
		x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyWindow
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyWindow", "HWND", hWnd, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		window->SendMessage(WM_DESTROY, 0, 0);
		window->SendMessage(WM_NCDESTROY, 0, 0);
		delete window;
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShowWindow
(HWND hWnd, int nCmdShow)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShowWindow", "HWND", hWnd, "int", nCmdShow, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		switch (nCmdShow) {
		case SW_HIDE:
			window->Show(false);
			rc = TRUE;
			break;
		case SW_SHOW:
		case SW_SHOWNORMAL:		// XXX: TODO
		case SW_SHOWDEFAULT:	// XXX: TODO
			window->Show(true);
			rc = TRUE;
			break;
		default:
			WIN32API_INFO("\tnot impl.\n");
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UpdateWindow
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UpdateWindow", "HWND", hWnd, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		rc = TRUE;
		window->SendMessage(WM_PAINT, 0, 0);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
GetDC
(HWND hWnd)
{
	HDC rc = NULL;
	WIN32API_ENTER("HDC", "GetDC", "HWND", hWnd, NULL);
	/// TODO: InvalidateRect(NULL)
	WIN32API_INFO("\tneed invalidation\n");
	if (NULL == hWnd) {
		static DeviceContext desktop;
		rc = (HDC)&desktop;
	} else {
		Window *window = Window::HandleToWindow(hWnd);
		if (NULL != window) {
			rc = window->GetDeviceContext();
			if (NULL != rc) WIN32API_ERROR(ERROR_SUCCESS);
		} else {
			WIN32API_ERROR(ERROR_INVALID_HANDLE);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ReleaseDC
(HWND hWnd, HDC hDc)
{
	int rc = 0;
	WIN32API_ENTER("int", "ReleaseDC", "HWND", hWnd, "HDC", hDc, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if ((NULL != window) && (hDc == (HDC)window->GetDeviceContext())) {
		WIN32API_ERROR(ERROR_SUCCESS);
		rc = 1;
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
BeginPaint
(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
	HDC rc = NULL;
	WIN32API_ENTER("HDC", "BeginPaint", "HWND", hWnd, "LPPAINTSTRUCT", lpPaint, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		rc = (HDC)window->GetDeviceContext();
		if (NULL != lpPaint) {
			lpPaint->hDc = rc;
			lpPaint->fErase = FALSE;
			// invalidate area
			lpPaint->rcPaint.left = 0;
			lpPaint->rcPaint.top = 0;
			RECT rect;
			window->GetWindowRect(&rect);
			lpPaint->rcPaint.right = rect.right - rect.left;
			lpPaint->rcPaint.bottom = rect.bottom - rect.top;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EndPaint
(HWND hWnd, LPCPAINTSTRUCT lpPaint)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EndPaint", "HWND", hWnd, "LPCPAINTSTRUCT", lpPaint, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL != window) {
		DeviceContext *dc = window->GetDeviceContext();
		if (lpPaint->hDc == (HDC)dc) rc = TRUE;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowTextA
(HWND hWnd, LPCSTR lpString)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpString);
	WIN32API_ENTER("BOOL", "SetWindowTextA", "HWND", hWnd, "LPCSTR", lpString, NULL);
	Win32String title;
	title.SetToA(lpString);
	rc = SetWindowTextU(hWnd, title.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowTextW
(HWND hWnd, LPCWSTR lpString)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWindowTextW", "HWND", hWnd, "LPCWSTR", lpString, NULL);
	Win32String title;
	title.SetToW(lpString);
	rc = SetWindowTextU(hWnd, title.StringU());
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetWindowTextA
(HWND hWnd, LPTSTR lpString, int nMaxCount)
{
	int rc = 0;
	WIN32API_ENTER("int", "GetWindowTextA", "HWND", hWnd, "LPTSTR", lpString, "int", nMaxCount, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetWindowTextW
(HWND arg0, LPWSTR arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetWindowTextW", "HWND", arg0, "LPWSTR", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetWindowTextLengthA
(HWND hWnd)
{
	int rc = 0;
	WIN32API_ENTER("int", "GetWindowTextLengthA", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetWindowTextLengthW
(HWND hWnd)
{
	int rc = 0;
	WIN32API_ENTER("int", "GetWindowTextLengthW", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
GetWindowLongA
(HWND hWnd, int nIndex)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "GetWindowLongA", "HWND", hWnd, "int", nIndex, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->GetWindowLong(nIndex);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
GetWindowLongW
(HWND hWnd, int nIndex)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "GetWindowLongW", "HWND", hWnd, "int", nIndex, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->GetWindowLong(nIndex);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
SetWindowLongA
(HWND hWnd, int nIndex, LONG dwNewLong)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "SetWindowLongA", "HWND", hWnd, "int", nIndex, "LONG", dwNewLong, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->SetWindowLong(nIndex, dwNewLong);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
SetWindowLongW
(HWND hWnd, int nIndex, LONG dwNewLong)
{
	LONG rc = 0;
	WIN32API_ENTER("LONG", "SetWindowLongW", "HWND", hWnd, "int", nIndex, "LONG", dwNewLong, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->SetWindowLong(nIndex, dwNewLong);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
GetParent
(HWND hWnd)
{
	HWND rc = NULL;
	WIN32API_ENTER("HWND", "GetParent", "HWND", hWnd, NULL);
	WIN32API_INTERNAL_START();
	rc = (HWND)GetWindowLongW(hWnd, GWL_HWNDPARENT);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
GetMenu
(HWND hWnd)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "GetMenu", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetWindowRect
(HWND hWnd, LPRECT lpRect)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpRect);
	WIN32API_ENTER("BOOL", "GetWindowRect", "HWND", hWnd, "LPRECT", lpRect, NULL);
	if (NULL == hWnd) {
		WIN32API_INTERNAL_START();
		hWnd = GetDesktopWindow();
		WIN32API_INTERNAL_END();
	}
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->GetWindowRect(lpRect);
	}
	WIN32API_INFO("\t(%d, %d) - (%d, %d)\n", lpRect->left, lpRect->top, lpRect->right, lpRect->bottom);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetClientRect
(HWND hWnd, LPRECT lpRect)
{
	WIN32API_POINTER(lpRect);
	WIN32API_ENTER("BOOL", "GetClientRect", "HWND", hWnd, "LPRECT", lpRect, NULL);
	WIN32API_INTERNAL_START();
	BOOL rc = GetWindowRect(hWnd, lpRect);
	if (TRUE == rc) {
		HMENU hMenu = GetMenu(hWnd);
		if (NULL != hMenu) lpRect->bottom -= GetSystemMetrics(SM_CYMENU);
	}
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowPos
(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWindowPos", "HWND", hWnd, "HWND", hWndInsertAfter, "int", X, "int", Y, "int", cx, "int", cy, "UINT", uFlags, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->SetWindowPos(hWndInsertAfter, X, Y, cx, cy, uFlags);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MoveWindow
(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
	WIN32API_ENTER("BOOL", "MoveWindow", "HWND", hWnd, "int", X, "int", Y, "int", nWidth, "int", nHeight, "BOOL", bRepaint, NULL);
	WIN32API_INTERNAL_START();
	BOOL rc = SetWindowPos(hWnd, NULL, X, Y, nWidth, nHeight,
		SWP_NOZORDER | ((TRUE == bRepaint)? 0: SWP_NOREDRAW));
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ClientToScreen
(HWND hWnd, LPPOINT lpPoint)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpPoint);
	WIN32API_ENTER("BOOL", "ClientToScreen", "HWND", hWnd, "LPPOINT", lpPoint, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		window->ClientToScreen(lpPoint);
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScreenToClient
(HWND hWnd, LPPOINT lpPoint)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpPoint);
	WIN32API_ENTER("BOOL", "ScreenToClient", "HWND", hWnd, "LPPOINT", lpPoint, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		window->ScreenToClient(lpPoint);
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumChildWindows
(HWND hWndParent, WNDENUMPROC lpEnumProc, LPARAM lParam)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpEnumProc);
	WIN32API_ENTER("BOOL", "EnumChildWindows", "HWND", hWndParent, "ENUMWINDOWSPROC", lpEnumProc, "LPARAM", lParam, NULL);
	Window *window = Window::HandleToWindow(hWndParent);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = window->EnumChildWindows(lpEnumProc, lParam);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsWindow
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsWindow", "HWND", hWnd, NULL);
	Window *window = Window::HandleToWindow(hWnd);
	if (NULL == window) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefWindowProcA
(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WIN32API_ENTER("LRESULT", "DefWindowProcA", "HWND", hWnd, "UINT", uMsg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	WIN32API_INTERNAL_START();
	LRESULT rc = DefWindowProcW(hWnd, uMsg, wParam, lParam);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
DefWindowProcW
(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc = 0;
	WIN32API_ENTER("LRESULT", "DefWindowProcW", "HWND", hWnd, "UINT", uMsg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	if (uMsg == WM_CLOSE) {
		WIN32API_INTERNAL_START();
		DestroyWindow(hWnd);
		WIN32API_INTERNAL_END();
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
CallWindowProcA
(WNDPROC lpPrevWindowProc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc;
	long regbuf[3];
	WIN32API_ENTER("LRESULT", "CallWindowProcA", "WNDPROC", lpPrevWindowProc, "HWND", hWnd, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	rc = CallWindowProcAsm(lpPrevWindowProc, hWnd, Msg, wParam, lParam, regbuf);
//	rc = lpPrevWindowProc(hWnd, Msg, wParam, lParam);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LRESULT WINAPI
CallWindowProcW
(WNDPROC lpPrevWindowProc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT rc;
	long regbuf[3];
	WIN32API_ENTER("LRESULT", "CallWindowProcW", "WNDPROC", lpPrevWindowProc, "HWND", hWnd, "UINT", Msg, "WPARAM", wParam, "LPARAM", lParam, NULL);
	rc = CallWindowProcAsm(lpPrevWindowProc, hWnd, Msg, wParam, lParam, regbuf);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumWindows
(WNDENUMPROC lpEnumProc, LPARAM lParam)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumWindows", "WNDENUMPROC", lpEnumProc, "LPARAM", lParam, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetForegroundWindow
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetForegroundWindow", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AdjustWindowRect
(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
	BOOL rc = TRUE;
	WIN32API_ENTER("BOOL", "AdjustWindowRect", "LPRECT", lpRect, "DWORD", dwStyle, "BOOL", bMenu, NULL);
	if (TRUE == bMenu) {
		WIN32API_INTERNAL_START();
		int height = GetSystemMetrics(SM_CYMENU);
		WIN32API_INTERNAL_END();
		lpRect->bottom += height;
		WIN32API_INFO("\theight +%d\n", height);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsIconic
(HWND hWnd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsIconic", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
FindWindowA
(LPCTSTR lpClassName, LPCTSTR lpWindowName)
{
	HWND rc = NULL;
	WIN32API_POINTER(lpClassName);
	WIN32API_POINTER(lpWindowName);
	WIN32API_ENTER("HWND", "FindWindowA", "LPCTSTR", lpClassName, "LPCTSTR", lpWindowName, NULL);
	WIN32API_INFO("\tclass name = %s\n", lpClassName);
	WIN32API_INFO("\twindow name = %s\n", lpWindowName);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
GetWindowDC
(HWND hWnd)
{
	HDC rc = FALSE;
	WIN32API_ENTER("HDC", "GetWindowDC", "HWND", hWnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AdjustWindowRectEx
(LPRECT arg0, DWORD arg1, BOOL arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AdjustWindowRectEx", "LPRECT", arg0, "DWORD", arg1, "BOOL", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BringWindowToTop
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BringWindowToTop", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
ChildWindowFromPoint
(HWND arg0, POINT arg1)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "ChildWindowFromPoint", "HWND", arg0, "POINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HWND WINAPI
ChildWindowFromPointEx
(HWND arg0, POINT arg1, UINT arg2)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "ChildWindowFromPointEx", "HWND", arg0, "POINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseWindow
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseWindow", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnableWindow
(HWND arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnableWindow", "HWND", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetWindowRgn
(HWND arg0, HRGN arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetWindowRgn", "HWND", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetWindowThreadProcessId
(HWND arg0, PDWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetWindowThreadProcessId", "HWND", arg0, "PDWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WORD WINAPI
GetWindowWord
(HWND arg0, int arg1)
{
	WORD rc = (WORD)-1;
	WIN32API_ENTER("WORD", "GetWindowWord", "HWND", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsWindowEnabled
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsWindowEnabled", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsWindowUnicode
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsWindowUnicode", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsWindowVisible
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsWindowVisible", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
