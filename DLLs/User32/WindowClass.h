/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: WindowClass.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [WindowClass.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__WindowClass_h__)
#	define	__WindowClass_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Window_h__)
#		include "Window.h"
#	endif	// !defind(__Window_h__)

#	define	MAX_WINDOWCLASS	16

#	define	WS_OVERLAPPED	0x00000000L
#	define	WS_POPUP		0x80000000L
#	define	WS_CHILD		0x40000000L
#	define	WS_MINIMIZE		0x20000000L
#	define	WS_VISIBLE		0x10000000L
#	define	WS_DISABLED		0x08000000L
#	define	WS_CLIPSIBLINGS	0x04000000L
#	define	WS_CLIPCHILDREN	0x02000000L
#	define	WS_MAXIMIZE		0x01000000L
#	define	WS_CAPTION		0x00c00000L
#	define	WS_BORDER		0x00800000L
#	define	WS_DLGFRAME		0x00400000L
#	define	WS_VSCROLL		0x00200000L
#	define	WS_HSCROLL		0x00100000L
#	define	WS_SYSMENU		0x00080000L
#	define	WS_THICKFRAME	0x00040000L
#	define	WS_GROUP		0x00020000L
#	define	WS_TABSTOP		0x00010000L

#	define	WS_MINIMIZEBOX	0x00020000L
#	define	WS_MAXIMIZEBOX	0x00010000L

typedef struct tagWNDCLASSA {
	PACKED(UINT style);
	PACKED(WNDPROC lpfnWndProc);
	PACKED(int cbClsExtra);
	PACKED(int cbWndExtra);
	PACKED(HINSTANCE hInstance);
	PACKED(HICON hIcon);
	PACKED(HCURSOR hCursor);
	PACKED(HBRUSH hbrBackground);
	PACKED(LPCSTR lpszMenuName);
	PACKED(LPCSTR lpszClassName);
} WNDCLASSA, *PWNDCLASSA, *LPWNDCLASSA;
typedef CONST WNDCLASSA CWNDCLASSA, *LPCWNDCLASSA;

typedef struct tagWNDCLASSW {
	PACKED(UINT style);
	PACKED(WNDPROC lpfnWndProc);
	PACKED(int cbClsExtra);
	PACKED(int cbWndExtra);
	PACKED(HINSTANCE hInstance);
	PACKED(HICON hIcon);
	PACKED(HCURSOR hCursor);
	PACKED(HBRUSH hbrBackground);
	PACKED(LPCWSTR lpszMenuName);
	PACKED(LPCWSTR lpszClassName);
} WNDCLASSW, *PWNDCLASSW, *LPWNDCLASSW;
typedef CONST WNDCLASSW CWNDCLASSW, *LPCWNDCLASSW;

typedef struct tragWNDCLASSEXA {
	PACKED(UINT cbSize);
	PACKED(UINT style);
	PACKED(WNDPROC lpfnWndProc);
	PACKED(int cbClsExtra);
	PACKED(int cbWndExtra);
	PACKED(HINSTANCE hInstance);
	PACKED(HICON hIcon);
	PACKED(HCURSOR hCursor);
	PACKED(HBRUSH hbrBackground);
	PACKED(LPCSTR lpszMenuName);
	PACKED(LPCSTR lpszClassName);
	PACKED(HICON hIconSm);
} WNDCLASSEXA, *PWNDCLASSEXA, *LPWNDCLASSEXA;
typedef CONST WNDCLASSEXA CWNDCLASSEXA, *LPCWNDCLASSEXA;

typedef struct tagWNDCLASSEXW {
	PACKED(UINT cbSize);
	PACKED(UINT style);
	PACKED(WNDPROC lpfnWndProc);
	PACKED(int cbClsExtra);
	PACKED(int cbWndExtra);
	PACKED(HINSTANCE hInstance);
	PACKED(HICON hIcon);
	PACKED(HCURSOR hCursor);
	PACKED(HBRUSH hbrBackground);
	PACKED(LPCWSTR lpszMenuName);
	PACKED(LPCWSTR lpszClassName);
	PACKED(HICON hIconSm);
} WNDCLASSEXW, *PWNDCLASSEXW, *LPWNDCLASSEXW;
typedef CONST WNDCLASSEXW CWNDCLASSEXW, *LPCWNDCLASSEXW;

typedef BView *(*NewViewProc)(HINSTANCE, BRect, LPCSTR, DWORD &);

class WindowClass {
public:
	static BLocker lock;
	static BList classes;
	static int id;
	int atom;
	UINT style;
	WNDPROC lpfnWndProc;
	int cbClsExtra;
	int cbWndExtra;
	HINSTANCE hInstance;
	HICON hIcon;
	HCURSOR hCursor;
	HBRUSH hbrBackground;
	char *lpszMenuName;
	char *lpszClassName;
	HICON hIconSm;
	NewViewProc nvc;

	WindowClass(LPCWNDCLASSA wc, NewViewProc nvc = NULL);
	WindowClass(LPCWNDCLASSEXA wcex, NewViewProc nvc = NULL);
	~WindowClass(void);
	
	BView *CreateCustomView(HINSTANCE hInstance, BRect rect, LPCSTR lpTitle, DWORD &style);
	
	static WindowClass *FindClass(const char *name);
};

#	if !defined(__WindowClass__)
#		define	__WindowClass__
#	endif	// !defined(__WindowClass__)

ATOM RegisterClassU(LPWNDCLASSA lpwc);
ATOM RegisterClassExU(LPWNDCLASSEXA lpwcex);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

ATOM WINAPI RegisterClassA(LPCWNDCLASSA lpwc);
ATOM WINAPI RegisterClassW(LPCWNDCLASSW lpwc);
ATOM WINAPI RegisterClassExA(LPCWNDCLASSEXA lpwcex);
ATOM WINAPI RegisterClassExW(LPCWNDCLASSEXW lpwcex);
BOOL WINAPI UnregisterClassA(LPCSTR lpClassName, HINSTANCE hInstance);
BOOL WINAPI UnregisterClassW(LPCWSTR lpClassName, HINSTANCE hInstance);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__WindowClass_h__)
