/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 とよしま
 *  $Id: Window.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Window.h]
 * TODO: LocalWindowで破棄の際に親のリストからRemoveする必要がある。
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Window_h__)
#	define	__Window_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__DeviceContext_h__)
#		include "GDI32/DeviceContext.h"
#	endif	// !defined(__DevuceContext_h__)

#	if !defined(__WindowClass__)
class WindowClass;
#		define	__WindowClass__
#	endif	// !defined(__WindowClass__)

#	if !defined(__Timer__)
class Timer;
#		define	__Timer__
#	endif	// !defined(__Timer__)

#	if !defined(__Menu__)
class Menu;
#		define	__Menu__
#	endif	// !defined(__Menu__)

#	define	MK_LBUTTON			(0x0001)
#	define	MK_RBUTTON			(0x0002)
#	define	MK_SHIFT			(0x0004)
#	define	MK_CONTROL			(0x0008)
#	define	MK_MBUTTON			(0x0010)

#	define	CW_USEDEFAULT		(int)0x80000000

#	define	WM_NULL				(0x0000)
#	define	WM_CREATE			(0x0001)
#	define	WM_DESTROY			(0x0002)
#	define	WM_MOVE				(0x0003)
#	define	WM_SIZE				(0x0005)
#	define	WM_ACTIVATE			(0x0006)
#	define	WM_SETFOCUS			(0x0007)
#	define	WM_KILLFOCUS		(0x0008)

#	define	WM_ENABLE			(0x000a)
#	define	WM_SETREDRAW		(0x000b)
#	define	WM_SETTEXT			(0x000c)
#	define	WM_GETTEXT			(0x000d)
#	define	WM_GETTEXTLENGTH	(0x000e)
#	define	WM_PAINT			(0x000f)
#	define	WM_CLOSE			(0x0010)
#	define	WM_QUERYENDSESSION	(0x0011)
#	define	WM_QUIT				(0x0012)
#	define	WM_QUERYOPEN		(0x0013)
#	define	WM_ERASEBKGND		(0x0014)
#	define	WM_SYSCOLORCHANGE	(0x0015)
#	define	WM_ENDSESSION		(0x0016)

#	define	WM_SHOWWINDOW		(0x0018)

#	define	WM_ACTIVATEAPP		(0x001c)

#	define	WM_SETCURSOR		(0x0020)
#	define	WM_MOUSEACTIVATE	(0x0021)
#	define	WM_CHILDACTIVATE	(0x0022)
#	define	WM_QUEUESYNC		(0x0023)
#	define	WM_GETMINMAXINFO	(0x0024)

#	define	WM_CONTEXTMENU		(0x007b)
#	define	WM_STYLECHANGING	(0x007c)
#	define	WM_STYLECHANGED		(0x007d)
#	define	WM_DISPLAYCHANGE	(0x007e)
#	define	WM_GETICON			(0x007f)
#	define	WM_SETICON			(0x0080)
#	define	WM_NCCREATE			(0x0081)
#	define	WM_NCDESTROY		(0x0082)
#	define	WM_NCCALCSIZE		(0x0083)
#	define	WM_NCHITTEST		(0x0084)
#	define	WM_NCPAINT			(0x0085)
#	define	WM_NCACTIVATE		(0x0086)
#	define	WM_GETDLGCODE		(0x0087)
#	define	WM_SYNCPAINT		(0x0088)

#	define	WM_NCMOUSEMOVE		(0x00a0)
#	define	WM_NCLBUTTONDOWN	(0x00a1)
#	define	WM_NCLBUTTONUP		(0x00a2)
#	define	WM_NCLBUTTONDBLCLK	(0x00a3)
#	define	WM_NCRBUTTONDOWN	(0x00a4)
#	define	WM_NCRBUTTONUP		(0x00a5)
#	define	WM_NCRBUTTONDBLCLK	(0x00a6)
#	define	WM_NCMBUTTONDOWN	(0x00a7)
#	define	WM_NCMBUTTONUP		(0x00a8)
#	define	WM_NCMBUTTONDBLCLK	(0x00a9)

#	define	BM_GETCHECK			(0x00f0)
#	define	BM_SETCHECK			(0x00f1)
#	define	BM_GETSTATE			(0x00f2)
#	define	BM_SETSTATE			(0x00f3)
#	define	BM_SETSTYLE			(0x00f4)
#	define	BM_CLICK			(0x00f5)
#	define	BM_GETIMAGE			(0x00f6)
#	define	BM_SETIMAGE			(0x00f7)

#	define	WM_KEYFIRST			(0x0100)
#	define	WM_KEYDOWN			(0x0100)
#	define	WM_KEYUP			(0x0101)
#	define	WM_CHAR				(0x0102)
#	define	WM_DEADCHAR			(0x0103)
#	define	WM_SYSKEYDOWN		(0x0104)
#	define	WM_SYSKEYUP			(0x0105)
#	define	WM_SYSCHAR			(0x0106)
#	define	WM_SYSDEADCHAR		(0x0107)
#	define	WM_KEYLAST			(0x0108)

#	define	WM_INITDIALOG		(0x0110)
#	define	WM_COMMAND			(0x0111)
#	define	WM_SYSCOMMAND		(0x0112)
#	define	WM_TIMER			(0x0113)

#	define	WM_MOUSEMOVE		(0x0200)
#	define	WM_LBUTTONDOWN		(0x0201)
#	define	WM_LBUTTONUP		(0x0202)

#	define	WM_RBUTTONDOWN		(0x0204)
#	define	WM_RBUTTONUP		(0x0205)

#	define	WM_MBUTTONDOWN		(0x0207)
#	define	WM_MBUTTONUP		(0x0208)

#	define	WM_SIZING			(0x0214)

#	define	WM_WINBE			(0x0300)
#	define	WM_xENDDIALOG		(WM_WINBE + 0)

#	define	WM_USER				(0x0400)

#	define	WA_INACTIVE			0
#	define	WA_ACTIVE			1
#	define	WA_CLICKACTIVE		2

#	define	BN_CLICKED			0
#	define	BN_PAINT			1
#	define	BN_HILITE			2
#	define	BN_UNHILITE			3
#	define	BN_DISABLE			4
#	define	BN_DOUBLECLICKED	5
#	define	BN_PUSHED			BN_HILITE
#	define	BN_UNPUSHED			BN_UNHILITE
#	define	BN_DBLCLK			BN_DOUBLECLICKED
#	define	BN_SETFOCUS			6
#	define	BN_KILLFOCUS		7

#	define	SC_SIZE				0xf000
#	define	SC_MOVE				0xf010
#	define	SC_MINIMIZE			0xf020
#	define	SC_MAXIMIZE			0xf030
#	define	SC_NEXTWINDOW		0xf040
#	define	SC_PREVWINDOW		0xf050
#	define	SC_CLOSE			0xf060

#	define	SW_HIDE				0
#	define	SW_SHOWNORMAL		1
#	define	SW_NORMAL			1
#	define	SW_SHOWMINIMIZED	2
#	define	SW_SHOWMAXIMIZED	3
#	define	SW_MAXIMIZE			3
#	define	SW_SHOWNOACTIVATE	4
#	define	SW_SHOW				5
#	define	SW_MINIMIZE			6
#	define	SW_SHOWMINNOACTIVE	7
#	define	SW_SHOWNA			8
#	define	SW_SHOWRESTORE		9
#	define	SW_SHOWDEFAULT		10
#	define	SW_FORCEMINIMIZE	11
#	define	SW_MAX				11

#	define	BST_UNCHECKED		0x0000
#	define	BST_CHECKED			0x0001
#	define	BST_INDETERMINATE	0x0002
#	define	BST_PUSHED			0x0004
#	define	BST_FOCUS			0x0008

#	define	SWP_NOSIZE			0x0001
#	define	SWP_NOMOVE			0x0002
#	define	SWP_NOZORDER		0x0004
#	define	SWP_NOREDRAW		0x0008
#	define	SWP_NOACTIVATE		0x0010
#	define	SWP_FRAMECHANGED	0x0020
#	define	SWP_SHOWWINDOW		0x0040
#	define	SWP_HIDEWINDOW		0x0080
#	define	SWP_NOCOPYBITS		0x0100
#	define	SWP_NOOWNERZORDER	0x0200
#	define	SWP_NOSENDCHANGING	0x0400
#	define	SWP_DRAWFRAME		SWP_FRAMECHANGED
#	define	SWP_NOREPOSITION	SWP_NOOWNERZORDER
#	define	SWP_DEFERERASE		0x2000
#	define	SWP_ASYNCWINDOWPOS	0x4000

#	define	WINDOW_MAGIC		'_WND'

typedef struct tagCREATESTRUCT {
	PACKED(LPVOID lpCreateParams);
	PACKED(HINSTANCE hInstance);
	PACKED(HMENU hMenu);
	PACKED(HWND hwndParent);
	PACKED(int cy);
	PACKED(int cx);
	PACKED(int y);
	PACKED(int x);
	PACKED(LONG style);
	PACKED(LPCSTR lpszName);
	PACKED(LPCSTR lpszClass);
	PACKED(DWORD dwExStyle);
} CREATESTRUCT, *LPCREATESTRUCT;

#	define	GWL_WNDPROC			(-4)
#	define	GWL_HINSTANCE		(-6)
#	define	GWL_HWNDPARENT		(-8)
#	define	GWL_STYLE			(-16)
#	define	GWL_EXSTYLE			(-20)
#	define	GWL_USERDATA		(-21)
#	define	GWL_ID				(-12)

#	define	GWL_xDIALOGPROC		DWL_DLGPROC

#	define	DWL_MSGRESULT		0
#	define	DWL_DLGPROC			4
#	define	DWL_USER			8



#	define	MAKEWLINDEX(x)		(x + 21)
#	define	WINDOWLONG_MAX		30

typedef BOOL CALLBACK (*WNDENUMPROC)(HWND hWnd, LPARAM lParam);
typedef LRESULT CALLBACK (*WNDPROC)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

abstract class Window {
	struct find {
		UINT nIDEvent;
		Timer *result;
	};
public:
	DWORD magic;
private:
	BList timer;
	BLocker lock;
	LONG param[WINDOWLONG_MAX];
	int id;
	BList children;
	Window *parent;
public:
	Window(void);
	virtual ~Window(void);

	virtual DeviceContext *GetDeviceContext(void) const = NULL;

	bool AddTimer(Timer *timer);
	bool RemoveTimer(Timer *timer);
	Timer *FindTimer(UINT nIDEvent);
	
	void SetID(int id);
	int GetID(void);

	void SetParent(Window *window);
	bool AddChild(Window *window);
	bool RemoveChild(Window *window);
	BOOL EnumChildWindows(WNDENUMPROC lpEnumProc, LPARAM lParam);

	virtual bool Show(bool show) = NULL;
	virtual bool GetTitle(LPSTR lpTitle, UINT &uSize) = NULL;
	virtual bool SetTitle(LPCSTR lpTitle) = NULL;
	virtual BOOL GetWindowRect(LPRECT lpRect) = NULL;
	virtual BOOL SetWindowPos(HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags) = NULL;

	virtual LRESULT SendMessage(LPCMSG lpMsg) = NULL;
	virtual LRESULT SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam) = NULL;
	virtual BOOL PostMessage(LPCMSG lpMsg) = NULL;
	virtual BOOL PostMessage(UINT Msg, WPARAM wParam, LPARAM lParam) = NULL;

	virtual LONG GetWindowLong(int nIndex);
	virtual LONG SetWindowLong(int nIndex, LONG newLong);
	
	virtual void ClientToScreen(LPPOINT lpPoint) = NULL;
	virtual void ScreenToClient(LPPOINT lpPoint) = NULL;

	virtual void Update(BBitmap *bmp, LPRECT rect = NULL);

	inline void Lock(void) { lock.Lock(); };
	inline void Unlock(void) { lock.Unlock(); };

	static Window *HandleToWindow(HWND hWnd);
private:
	static bool FindTimerCallback(void *item, void *arg);
};

#	if !defined(__Window__)
#		define	__Window__
#	endif	// !defined(__Window__)

class LocalWindow;

class NativeWindow: public BWindow {
private:
	LocalWindow *owner;
	bool quitflag;
public:
	NativeWindow(LocalWindow *owner, BRect frame, const char *title, window_look look, window_feel feel, uint32 flags);
	~NativeWindow(void);
	bool QuitRequested(void);
	void Quit(void);
};

#	if !defined(__NativeWindow__)
#		define	__NativeWindow__
#	endif	// !defined(__NatvieWindow__)

class NativeView: public BView {
private:
	NativeWindow *owner;
	LocalWindow *window;
public:
	NativeView(NativeWindow *owner, LocalWindow *window, BRect rect);
	virtual ~NativeView(void);

	void Draw(BRect rect);
	void MouseDown(BPoint point);
	void MouseUp(BPoint point);
	void MouseMoved(BPoint point, uint32 transit, const BMessage *message);
	void WindowActivated(bool active);
};

#	if !defined(__NativeView__)
#		define	__NativeView__
#	endif	// !defined(__NativeView__)

class LocalWindow: public Window {
friend class NativeWindow;
private:
	NativeWindow *window;
	BView *view;
	WindowClass *wc;
	DWORD owner_thread;
	port_id message_port;
	port_id reply_port;
	DeviceContext *dc;
	Bitmap *bmp;
	Menu *menu;
	BList subsets;
public:
	LocalWindow(void);
	~LocalWindow(void);

	bool Create(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle,
		int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);

	DeviceContext *GetDeviceContext(void) const;

	bool Show(bool show);
	bool GetTitle(LPSTR lpTitle, UINT &uSize);
	bool SetTitle(LPCSTR lpTitle);
	BOOL GetWindowRect(LPRECT lpRect);
	BOOL SetWindowPos(HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
	
	void AddChild(BView *aView);
	void AddSubset(BWindow *subset);
	
	LRESULT SendMessage(LPCMSG lpMsg);	// Window
	LRESULT SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam);	// Window
	BOOL PostMessage(LPCMSG lpMsg);	// Window
	BOOL PostMessage(UINT Msg, WPARAM wParam, LPARAM lParam);	// Window

	void ClientToScreen(LPPOINT lpPoint);	// Window
	void ScreenToClient(LPPOINT lpPoint);	// Window

	void Update(BBitmap *bmp, LPRECT rect = NULL);	// Window

	NativeWindow *LockNativeWindow(void);
	void UnlockNativeWindow(void);
	BView *LockView(void);
	void UnlockView(void);
};

#	if !defined(__LocalWindow__)
#		define	__LocalWindow__
#	endif	// !defined(__LocalWindow__)

HWND CreateWindowExU(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle,
	int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
BOOL SetWindowTextU(HWND hWnd, LPCSTR lpString);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HWND WINAPI CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle,
	int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
HWND WINAPI CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
	int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
BOOL WINAPI DestroyWindow(HWND hWnd);

BOOL WINAPI ShowWindow(HWND hWnd, int nCmdShow);
BOOL WINAPI UpdateWindow(HWND hWnd);

HDC WINAPI GetDC(HWND hWnd);
int WINAPI ReleaseDC(HWND hWnd, HDC hDc);

HDC WINAPI BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
BOOL WINAPI EndPaint(HWND hWnd, LPCPAINTSTRUCT lpPaint);

BOOL WINAPI SetWindowTextA(HWND hWnd, LPCSTR lpString);
BOOL WINAPI SetWindowTextW(HWND hWnd, LPCWSTR lpString);
int WINAPI GetWindowTextA(HWND hWnd, LPTSTR lpString, int nMaxCount);
int WINAPI GetWindowTextW(HWND,LPWSTR,int);
int WINAPI GetWindowTextLengthA(HWND hWnd);
int WINAPI GetWindowTextLengthW(HWND hWnd);

LONG WINAPI GetWindowLongA(HWND hWnd, int nIndex);
LONG WINAPI GetWindowLongW(HWND hWnd, int nIndex);
LONG WINAPI SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong);
LONG WINAPI SetWindowLongW(HWND hWnd, int nIndex, LONG dwNewLong);

HWND WINAPI GetParent(HWND hWnd);
HMENU WINAPI GetMenu(HWND hWnd);

BOOL WINAPI GetWindowRect(HWND hWnd, LPRECT lpRect);
BOOL WINAPI GetClientRect(HWND hWnd, LPRECT lpRect);
BOOL WINAPI SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
BOOL WINAPI MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint);

BOOL WINAPI ClientToScreen(HWND hWnd, LPPOINT lpPoint);
BOOL WINAPI ScreenToClient(HWND hWnd, LPPOINT lpPoint);

BOOL WINAPI EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumProc, LPARAM lParam);

BOOL WINAPI IsWindow(HWND hWnd);

LRESULT WINAPI DefWindowProcA(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI DefWindowProcW(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI CallWindowProcA(WNDPROC lpPrevWindowProc ,HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI CallWindowProcW(WNDPROC lpPrevWindowProc ,HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

BOOL WINAPI EnumWindows(WNDENUMPROC lpEnumProc, LPARAM lParam);
BOOL WINAPI SetForegroundWindow(HWND hWnd);
BOOL WINAPI AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu);
BOOL WINAPI IsIconic(HWND hWnd);
HWND WINAPI FindWindowA(LPCTSTR lpClassName, LPCTSTR lpWindowName);
HDC WINAPI GetWindowDC(HWND hWnd);
BOOL WINAPI AdjustWindowRect(LPRECT,DWORD,BOOL);
BOOL WINAPI AdjustWindowRectEx(LPRECT,DWORD,BOOL,DWORD);
BOOL WINAPI BringWindowToTop(HWND);
HWND WINAPI ChildWindowFromPoint(HWND,POINT);
HWND WINAPI ChildWindowFromPointEx(HWND,POINT,UINT);
BOOL WINAPI CloseWindow(HWND);
BOOL WINAPI EnableWindow(HWND,BOOL);
int WINAPI GetWindowRgn(HWND,HRGN);
DWORD WINAPI GetWindowThreadProcessId(HWND,PDWORD);
WORD WINAPI GetWindowWord(HWND,int);
BOOL WINAPI IsWindowEnabled(HWND);
BOOL WINAPI IsWindowUnicode(HWND);
BOOL WINAPI IsWindowVisible(HWND);
BOOL WINAPI IsZoomed(HWND);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Window_h__)
