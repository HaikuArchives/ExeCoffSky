/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: User32.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [User32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__User32_h__)
#	define	__User32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__DeviceContext_h__)
#		include "GDI32/DeviceContext.h"
#	endif	// !defined(__DeviceContext_h__)

#	if !defined(__MessageBox_h__)
#		include "MessageBox.h"
#	endif	// !defined(__MessageBox_h__)

#	if !defined(__Message_h__)
#		include "Message.h"
#	endif	// !defined(__Message_h__)

#	if !defined(__WindowClass_h__)
#		include "WindowClass.h"
#	endif	// !defined(__WindowClass_h__)

#	if !defined(__Window_h__)
#		include "Window.h"
#	endif	// !defined(__Window_h__)

#	if !defined(__Timer_h__)
#		include "Timer.h"
#	endif	// !defined(__Timer_h__)

#	if !defined(__LoadResources_h__)
#		include "LoadResources.h"
#	endif	// !defined(__LoadResources_h__)

#	if !defined(__SystemMetrics_h__)
#		include "SystemMetrics.h"
#	endif	// !defined(__SystemMetrics_h__)

#	if !defined(__Menu_h__)
#		include "Menu.h"
#	endif	// !defined(__Menu_h__)

#	if !defined(__Dialog_h__)
#		include "Dialog.h"
#	endif	// !defined(__Dialog_h__)

#	if !defined(__DialogItem_h__)
#		include "DialogItem.h"
#	endif	// !defined(__DialogItem_h__)

#	if !defined(__Desktop_h__)
#		include "Desktop.h"
#	endif	// !defined(__Desktop_h__)

#	if !defined(__IME_h__)
#		include "IME.h"
#	endif	// !defined(__IME_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

// SystemMetrics

int wsprintfA(LPTSTR lpOut, LPCTSTR lpFmt, ...);
BOOL WINAPI MessageBeep(UINT uType);
BOOL WINAPI DrawMenuBar(HWND hWnd);
BOOL WINAPI SetCursorPos(int X, int Y);
SHORT WINAPI GetAsyncKeyState(int vKey);
BOOL WINAPI InvalidateRect(HWND hWnd, LPCRECT lpRect, BOOL bErase);
HWND WINAPI GetFocus(VOID);
BOOL WINAPI EnumDisplaySettingsA(LPCTSTR lpszDeviceName, DWORD iModeNum, LPDEVMODEA lpDevMode);
LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lpDevMode, DWORD dwFlags);
BOOL WINAPI IsZoomed(HWND hWnd);
BOOL WINAPI ExitWindowsEx(UINT uFlags, DWORD dwReserved);
BOOL WINAPI GetCursorPos(LPPOINT lpPoint);
BOOL WINAPI ReleaseCapture(VOID);
HWND WINAPI SetCapture(HWND hWnd);
BOOL WINAPI SetMenu(HWND hWnd, HMENU hMenu);
HCURSOR WINAPI SetCursor(HCURSOR hCursor);
int WINAPI ShowCursor(BOOL bShow);
HMENU WINAPI GetSystemMenu(HWND hWnd, BOOL bRevert);
BOOL WINAPI SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom);
HKL WINAPI ActivateKeyboardLayout(HKL,UINT);
BOOL WINAPI AnyPopup(void);
UINT WINAPI ArrangeIconicWindows(HWND);
BOOL WINAPI AttachThreadInput(DWORD,DWORD,BOOL);
HDWP WINAPI BeginDeferWindowPos(int);
HDC WINAPI BeginPaint(HWND,LPPAINTSTRUCT);
BOOL WINAPI CallMsgFilter(PMSG,int);
LRESULT WINAPI CallNextHookEx(HHOOK,int,WPARAM,LPARAM);
WORD WINAPI CascadeWindows(HWND,UINT,LPCRECT,UINT,const HWND*);
BOOL WINAPI ChangeClipboardChain(HWND,HWND);
LONG WINAPI ChangeDisplaySettingsW(PDEVMODEW,DWORD);
LPSTR WINAPI CharLowerA(LPSTR);
DWORD WINAPI CharLowerBuffA(LPSTR,DWORD);
DWORD WINAPI CharLowerBuffW(LPWSTR,DWORD);
LPWSTR WINAPI CharLowerW(LPWSTR);
LPSTR WINAPI CharNextA(LPCSTR);
LPSTR WINAPI CharNextExA(WORD,LPCSTR,DWORD);
LPWSTR WINAPI CharNextW(LPCWSTR);
LPSTR WINAPI CharPrevA(LPCSTR,LPCSTR);
LPSTR WINAPI CharPrevExA(WORD,LPCSTR,LPCSTR,DWORD);
LPWSTR WINAPI CharPrevW(LPCWSTR,LPCWSTR);
BOOL WINAPI CharToOemA(LPCSTR,LPSTR);
BOOL WINAPI CharToOemBuffA(LPCSTR,LPSTR,DWORD);
BOOL WINAPI CharToOemBuffW(LPCWSTR,LPSTR,DWORD);
BOOL WINAPI CharToOemW(LPCWSTR,LPSTR);
LPSTR WINAPI CharUpperA(LPSTR);
DWORD WINAPI CharUpperBuffA(LPSTR,DWORD);
DWORD WINAPI CharUpperBuffW(LPWSTR,DWORD);
LPWSTR WINAPI CharUpperW(LPWSTR);
BOOL WINAPI ClientToScreen(HWND,LPPOINT);
BOOL WINAPI ClipCursor(LPCRECT);
BOOL WINAPI CloseClipboard(void);
BOOL WINAPI CloseDesktop(HDESK);
BOOL WINAPI CloseWindowStation(HWINSTA);
int WINAPI CopyAcceleratorTableA(HACCEL,LPACCEL,int);
int WINAPI CopyAcceleratorTableW(HACCEL,LPACCEL,int);
HICON WINAPI CopyIcon(HICON);
HANDLE WINAPI CopyImage(HANDLE,UINT,int,int,UINT);
BOOL WINAPI CopyRect(LPRECT,LPCRECT);
int WINAPI CountClipboardFormats(void);
HACCEL WINAPI CreateAcceleratorTableA(LPACCEL,int);
HACCEL WINAPI CreateAcceleratorTableW(LPACCEL,int);
BOOL WINAPI CreateCaret(HWND,HBITMAP,int,int);
HCURSOR WINAPI CreateCursor(HINSTANCE,int,int,int,int,PCVOID,PCVOID);
HDESK WINAPI CreateDesktopA(LPSTR,LPSTR,LPDEVMODEA,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
HDESK WINAPI CreateDesktopW(LPWSTR,LPWSTR,LPDEVMODEW,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
HICON WINAPI CreateIcon(HINSTANCE,int,int,BYTE,BYTE,const BYTE*,const BYTE*);
HICON WINAPI CreateIconFromResource(PBYTE,DWORD,BOOL,DWORD);
HICON WINAPI CreateIconFromResourceEx(PBYTE,DWORD,BOOL,DWORD,int,int,UINT);
HICON WINAPI CreateIconIndirect(PICONINFO);
HWND WINAPI CreateMDIWindowA(LPSTR,LPSTR,DWORD,int,int,int,int,HWND,HINSTANCE,LPARAM);
HWND WINAPI CreateMDIWindowW(LPWSTR,LPWSTR,DWORD,int,int,int,int,HWND,HINSTANCE,LPARAM);
HWINSTA WINAPI CreateWindowStationA(LPSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
HWINSTA WINAPI CreateWindowStationW(LPWSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
BOOL WINAPI DdeAbandonTransaction(DWORD,HCONV,DWORD);
PBYTE WINAPI DdeAccessData(HDDEDATA,PDWORD);
HDDEDATA WINAPI DdeAddData(HDDEDATA,PBYTE,DWORD,DWORD);
HDDEDATA WINAPI DdeClientTransaction(PBYTE,DWORD,HCONV,HSZ,UINT,UINT,DWORD,PDWORD);
int WINAPI DdeCmpStringHandles(HSZ,HSZ);
HCONV WINAPI DdeConnect(DWORD,HSZ,HSZ,PCONVCONTEXT);
HCONVLIST WINAPI DdeConnectList(DWORD,HSZ,HSZ,HCONVLIST,PCONVCONTEXT);
HDDEDATA WINAPI DdeCreateDataHandle(DWORD,PBYTE,DWORD,DWORD,HSZ,UINT,UINT);
HSZ WINAPI DdeCreateStringHandleA(DWORD,LPCSTR,int);
HSZ WINAPI DdeCreateStringHandleW(DWORD,LPCWSTR,int);
BOOL WINAPI DdeDisconnect(HCONV);
BOOL WINAPI DdeDisconnectList(HCONVLIST);
BOOL WINAPI DdeEnableCallback(DWORD,HCONV,UINT);
BOOL WINAPI DdeFreeDataHandle(HDDEDATA);
BOOL WINAPI DdeFreeStringHandle(DWORD,HSZ);
DWORD WINAPI DdeGetData(HDDEDATA,PBYTE,DWORD,DWORD);
UINT WINAPI DdeGetLastError(DWORD);
BOOL WINAPI DdeImpersonateClient(HCONV);
UINT WINAPI DdeInitializeA(PDWORD,PFNCALLBACK,DWORD,DWORD);
UINT WINAPI DdeInitializeW(PDWORD,PFNCALLBACK,DWORD,DWORD);
BOOL WINAPI DdeKeepStringHandle(DWORD,HSZ);
HDDEDATA WINAPI DdeNameService(DWORD,HSZ,HSZ,UINT);
BOOL WINAPI DdePostAdvise(DWORD,HSZ,HSZ);
UINT WINAPI DdeQueryConvInfo(HCONV,DWORD,PCONVINFO);
HCONV WINAPI DdeQueryNextServer(HCONVLIST,HCONV);
DWORD WINAPI DdeQueryStringA(DWORD,HSZ,LPSTR,DWORD,int);
DWORD WINAPI DdeQueryStringW(DWORD,HSZ,LPWSTR,DWORD,int);
HCONV WINAPI DdeReconnect(HCONV);
BOOL WINAPI DdeSetQualityOfService(HWND,const SECURITY_QUALITY_OF_SERVICE*,PSECURITY_QUALITY_OF_SERVICE);
BOOL WINAPI DdeSetUserHandle(HCONV,DWORD,DWORD);
BOOL WINAPI DdeUnaccessData(HDDEDATA);
BOOL WINAPI DdeUninitialize(DWORD);
LRESULT WINAPI DefFrameProcA(HWND,HWND,UINT,WPARAM,LPARAM);
LRESULT WINAPI DefFrameProcW(HWND,HWND,UINT,WPARAM,LPARAM);
LRESULT WINAPI DefMDIChildProcA(HWND,UINT,WPARAM,LPARAM);
LRESULT WINAPI DefMDIChildProcW(HWND,UINT,WPARAM,LPARAM);
HDWP WINAPI DeferWindowPos(HDWP,HWND,HWND,int,int,int,int,UINT);
BOOL WINAPI DestroyAcceleratorTable(HACCEL);
BOOL WINAPI DestroyCaret(void);
BOOL WINAPI DestroyCursor(HCURSOR);
BOOL WINAPI DestroyIcon(HICON);
BOOL WINAPI DragDetect(HWND,POINT);
DWORD WINAPI DragObject(HWND,HWND,UINT,DWORD,HCURSOR);
BOOL WINAPI DrawAnimatedRects(HWND,int,LPCRECT,LPCRECT);
BOOL WINAPI DrawCaption(HWND,HDC,LPCRECT,UINT);
BOOL WINAPI DrawEdge(HDC,LPRECT,UINT,UINT);
BOOL WINAPI DrawFocusRect(HDC,LPCRECT);
BOOL WINAPI DrawFrameControl(HDC,LPRECT,UINT,UINT);
BOOL WINAPI DrawIcon(HDC,int,int,HICON);
BOOL WINAPI DrawIconEx(HDC,int,int,HICON,int,int,UINT,HBRUSH,UINT);
BOOL WINAPI DrawMenuBar(HWND);
BOOL WINAPI DrawStateA(HDC,HBRUSH,DRAWSTATEPROC,LPARAM,WPARAM,int,int,int,int,UINT);
BOOL WINAPI DrawStateW(HDC,HBRUSH,DRAWSTATEPROC,LPARAM,WPARAM,int,int,int,int,UINT);
int WINAPI DrawTextA(HDC,LPCSTR,int,LPRECT,UINT);
int WINAPI DrawTextExA(HDC,LPSTR,int,LPRECT,UINT,LPDRAWTEXTPARAMS);
int WINAPI DrawTextExW(HDC,LPWSTR,int,LPRECT,UINT,LPDRAWTEXTPARAMS);
int WINAPI DrawTextW(HDC,LPCWSTR,int,LPRECT,UINT);
BOOL WINAPI EmptyClipboard(void);
BOOL WINAPI EnableScrollBar(HWND,UINT,UINT);
BOOL WINAPI EndDeferWindowPos(HDWP);
BOOL WINAPI EndPaint(HWND,const PAINTSTRUCT*);
UINT WINAPI EnumClipboardFormats(UINT);
BOOL WINAPI EnumDesktopWindows(HDESK,WNDENUMPROC,LPARAM);
BOOL WINAPI EnumDesktopsA(HWINSTA,DESKTOPENUMPROCA,LPARAM);
BOOL WINAPI EnumDesktopsW(HWINSTA,DESKTOPENUMPROCW,LPARAM);
BOOL WINAPI EnumDisplaySettingsA(LPCSTR,DWORD,PDEVMODEA);
BOOL WINAPI EnumDisplaySettingsW(LPCWSTR,DWORD,PDEVMODEW);
int WINAPI EnumPropsA(HWND,PROPENUMPROCA);
int WINAPI EnumPropsExA(HWND,PROPENUMPROCEXA,LPARAM);
int WINAPI EnumPropsExW(HWND,PROPENUMPROCEXW,LPARAM);
int WINAPI EnumPropsW(HWND,PROPENUMPROCW);
BOOL WINAPI EnumThreadWindows(DWORD,WNDENUMPROC,LPARAM);
BOOL WINAPI EnumWindowStationsA(WINSTAENUMPROCA,LPARAM);
BOOL WINAPI EnumWindowStationsW(WINSTAENUMPROCW,LPARAM);
BOOL WINAPI EnumWindows(WNDENUMPROC,LPARAM);
BOOL WINAPI EqualRect(LPCRECT,LPCRECT);
int WINAPI ExcludeUpdateRgn(HDC,HWND);
BOOL WINAPI ExitWindowsEx(UINT,DWORD);
int WINAPI FillRect(HDC,LPCRECT,HBRUSH);
HWND WINAPI FindWindowA(LPCSTR,LPCSTR);
HWND WINAPI FindWindowExA(HWND,HWND,LPCSTR,LPCSTR);
HWND WINAPI FindWindowExW(HWND,HWND,LPCWSTR,LPCWSTR);
HWND WINAPI FindWindowW(LPCWSTR,LPCWSTR);
BOOL WINAPI FlashWindow(HWND,BOOL);
int WINAPI FrameRect(HDC,LPCRECT,HBRUSH);
BOOL WINAPI FreeDDElParam(UINT,LONG);
HWND WINAPI GetActiveWindow(void);
SHORT WINAPI GetAsyncKeyState(int);
HWND WINAPI GetCapture(void);
UINT WINAPI GetCaretBlinkTime(void);
BOOL WINAPI GetCaretPos(LPPOINT);
BOOL WINAPI GetClassInfoA(HINSTANCE,LPCSTR,PWNDCLASSA);
BOOL WINAPI GetClassInfoExA(HINSTANCE,LPCSTR,PWNDCLASSEXA);
BOOL WINAPI GetClassInfoExW(HINSTANCE,LPCWSTR,PWNDCLASSEXW);
BOOL WINAPI GetClassInfoW(HINSTANCE,LPCWSTR,PWNDCLASSW);
DWORD WINAPI GetClassLongA(HWND,int);
DWORD WINAPI GetClassLongW(HWND,int);
int WINAPI GetClassNameA(HWND,LPSTR,int);
int WINAPI GetClassNameW(HWND,LPWSTR,int);
WORD WINAPI GetClassWord(HWND,int);
BOOL WINAPI GetClipCursor(LPRECT);
HANDLE WINAPI GetClipboardData(UINT);
int WINAPI GetClipboardFormatNameA(UINT,LPSTR,int);
int WINAPI GetClipboardFormatNameW(UINT,LPWSTR,int);
HWND WINAPI GetClipboardOwner(void);
HWND WINAPI GetClipboardViewer(void);
HCURSOR WINAPI GetCursor(void);
BOOL WINAPI GetCursorPos(LPPOINT);
HDC WINAPI GetDC(HWND);
HDC WINAPI GetDCEx(HWND,HRGN,DWORD);
UINT WINAPI GetDoubleClickTime(void);
HWND WINAPI GetFocus(void);
HWND WINAPI GetForegroundWindow(void);
BOOL WINAPI GetIconInfo(HICON,PICONINFO);
BOOL WINAPI GetInputState(void);
UINT WINAPI GetKBCodePage(void);
int WINAPI GetKeyNameTextA(LONG,LPSTR,int);
int WINAPI GetKeyNameTextW(LONG,LPWSTR,int);
SHORT WINAPI GetKeyState(int);
HKL WINAPI GetKeyboardLayout(DWORD);
int WINAPI GetKeyboardLayoutList(int,HKL*);
BOOL WINAPI GetKeyboardLayoutNameA(LPSTR);
BOOL WINAPI GetKeyboardLayoutNameW(LPWSTR);
BOOL WINAPI GetKeyboardState(PBYTE);
int WINAPI GetKeyboardType(int);
HWND WINAPI GetLastActivePopup(HWND);
HMENU WINAPI GetMenu(HWND);
LONG WINAPI GetMenuCheckMarkDimensions(void);
HWND WINAPI GetOpenClipboardWindow(void);
int WINAPI GetPriorityClipboardFormat(UINT*,int);
HWINSTA WINAPI GetProcessWindowStation(void);
HANDLE WINAPI GetPropA(HWND,LPCSTR);
HANDLE WINAPI GetPropW(HWND,LPCWSTR);
DWORD WINAPI GetQueueStatus(UINT);
BOOL WINAPI GetScrollInfo(HWND,int,LPSCROLLINFO);
int WINAPI GetScrollPos(HWND,int);
BOOL WINAPI GetScrollRange(HWND,int,LPINT,LPINT);
DWORD WINAPI GetSysColor(int);
HBRUSH WINAPI GetSysColorBrush(int);
HMENU WINAPI GetSystemMenu(HWND,BOOL);
DWORD WINAPI GetTabbedTextExtentA(HDC,LPCSTR,int,int,LPINT);
DWORD WINAPI GetTabbedTextExtentW(HDC,LPCWSTR,int,int,LPINT);
HDESK WINAPI GetThreadDesktop(DWORD);
HWND WINAPI GetTopWindow(HWND);
BOOL WINAPI GetUpdateRect(HWND,LPRECT,BOOL);
int WINAPI GetUpdateRgn(HWND,HRGN,BOOL);
BOOL WINAPI GetUserObjectInformationA(HANDLE,int,PVOID,DWORD,PDWORD);
BOOL WINAPI GetUserObjectInformationW(HANDLE,int,PVOID,DWORD,PDWORD);
BOOL WINAPI GetUserObjectSecurity(HANDLE,PSECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
HWND WINAPI GetWindow(HWND hWnd, UINT uCmd);
DWORD WINAPI GetWindowContextHelpId(HWND);
HDC WINAPI GetWindowDC(HWND);
BOOL WINAPI GetWindowPlacement(HWND,WINDOWPLACEMENT*);
BOOL WINAPI GrayStringA(HDC,HBRUSH,GRAYSTRINGPROC,LPARAM,int,int,int,int,int);
BOOL WINAPI GrayStringW(HDC,HBRUSH,GRAYSTRINGPROC,LPARAM,int,int,int,int,int);
BOOL WINAPI HideCaret(HWND);
BOOL WINAPI HiliteMenuItem(HWND,HMENU,UINT,UINT);
BOOL WINAPI ImpersonateDdeClientWindow(HWND,HWND);
BOOL WINAPI InflateRect(LPRECT,int,int);
BOOL WINAPI IntersectRect(LPRECT,LPCRECT,LPCRECT);
BOOL WINAPI InvalidateRect(HWND,LPCRECT,BOOL);
BOOL WINAPI InvalidateRgn(HWND,HRGN,BOOL);
BOOL WINAPI InvertRect(HDC,LPCRECT);
BOOL WINAPI IsCharAlphaA(CHAR ch);
BOOL WINAPI IsCharAlphaNumericA(CHAR);
BOOL WINAPI IsCharAlphaNumericW(WCHAR);
BOOL WINAPI IsCharAlphaW(WCHAR);
BOOL WINAPI IsCharLowerA(CHAR);
BOOL WINAPI IsCharLowerW(WCHAR);
BOOL WINAPI IsCharUpperA(CHAR);
BOOL WINAPI IsCharUpperW(WCHAR);
BOOL WINAPI IsChild(HWND,HWND);
BOOL WINAPI IsClipboardFormatAvailable(UINT);
BOOL WINAPI IsIconic(HWND);
BOOL WINAPI IsRectEmpty(LPCRECT);
HCURSOR WINAPI LoadCursorFromFileA(LPCSTR);
HCURSOR WINAPI LoadCursorFromFileW(LPCWSTR);
HKL WINAPI LoadKeyboardLayoutA(LPCSTR,UINT);
HKL WINAPI LoadKeyboardLayoutW(LPCWSTR,UINT);
BOOL WINAPI LockWindowUpdate(HWND);
int WINAPI LookupIconIdFromDirectory(PBYTE,BOOL);
int WINAPI LookupIconIdFromDirectoryEx(PBYTE,BOOL,int,int,UINT);
UINT WINAPI MapVirtualKeyA(UINT,UINT);
UINT WINAPI MapVirtualKeyExA(UINT,UINT,HKL);
UINT WINAPI MapVirtualKeyExW(UINT,UINT,HKL);
UINT WINAPI MapVirtualKeyW(UINT,UINT);
int WINAPI MapWindowPoints(HWND,HWND,LPPOINT,UINT);
int WINAPI MenuItemFromPoint(HWND,HMENU,POINT);
BOOL WINAPI MessageBeep(UINT);
BOOL WINAPI MoveWindow(HWND,int,int,int,int,BOOL);
DWORD WINAPI MsgWaitForMultipleObjects(DWORD,LPHANDLE,BOOL,DWORD,DWORD);
DWORD WINAPI MsgWaitForMultipleObjectsEx(DWORD,LPHANDLE,DWORD,DWORD,DWORD);
DWORD WINAPI OemKeyScan(WORD);
BOOL WINAPI OemToCharA(LPCSTR,LPSTR);
BOOL WINAPI OemToCharBuffA(LPCSTR,LPSTR,DWORD);
BOOL WINAPI OemToCharBuffW(LPCSTR,LPWSTR,DWORD);
BOOL WINAPI OemToCharW(LPCSTR,LPWSTR);
BOOL WINAPI OffsetRect(LPRECT,int,int);
BOOL WINAPI OpenClipboard(HWND);
HDESK WINAPI OpenDesktopA(LPSTR,DWORD,BOOL,DWORD);
HDESK WINAPI OpenDesktopW(LPWSTR,DWORD,BOOL,DWORD);
BOOL WINAPI OpenIcon(HWND);
HDESK WINAPI OpenInputDesktop(DWORD,BOOL,DWORD);
HWINSTA WINAPI OpenWindowStationA(LPSTR,BOOL,DWORD);
HWINSTA WINAPI OpenWindowStationW(LPWSTR,BOOL,DWORD);
LONG WINAPI PackDDElParam(UINT,UINT,UINT);
BOOL WINAPI PaintDesktop(HDC);
BOOL WINAPI PtInRect(LPCRECT,POINT);
BOOL WINAPI RedrawWindow(HWND,LPCRECT,HRGN,UINT);
UINT WINAPI RegisterClipboardFormatA(LPCSTR);
UINT WINAPI RegisterClipboardFormatW(LPCWSTR);
BOOL WINAPI RegisterHotKey(HWND,int,UINT,UINT);
UINT WINAPI RegisterWindowMessageA(LPCSTR);
UINT WINAPI RegisterWindowMessageW(LPCWSTR);
BOOL WINAPI ReleaseCapture(void);
int WINAPI ReleaseDC(HWND,HDC);
HANDLE WINAPI RemovePropA(HWND,LPCSTR);
HANDLE WINAPI RemovePropW(HWND,LPCWSTR);
LONG WINAPI ReuseDDElParam(LONG,UINT,UINT,UINT,UINT);
BOOL WINAPI ScreenToClient(HWND,LPPOINT);
BOOL WINAPI ScrollDC(HDC,int,int,LPCRECT,LPCRECT,HRGN,LPRECT);
BOOL WINAPI ScrollWindow(HWND,int,int,LPCRECT,LPCRECT);
int WINAPI ScrollWindowEx(HWND,int,int,LPCRECT,LPCRECT,HRGN,LPRECT,UINT);
HWND WINAPI SetActiveWindow(HWND);
HWND WINAPI SetCapture(HWND hWnd);
BOOL WINAPI SetCaretBlinkTime(UINT);
BOOL WINAPI SetCaretPos(int,int);
DWORD WINAPI SetClassLongA(HWND,int,LONG);
DWORD WINAPI SetClassLongW(HWND,int,LONG);
WORD WINAPI SetClassWord(HWND,int,WORD);
HANDLE WINAPI SetClipboardData(UINT,HANDLE);
HWND WINAPI SetClipboardViewer(HWND);
HCURSOR WINAPI SetCursor(HCURSOR);
BOOL WINAPI SetCursorPos(int,int);
VOID WINAPI SetDebugErrorLevel(DWORD);
BOOL WINAPI SetDoubleClickTime(UINT);
HWND WINAPI SetFocus(HWND);
BOOL WINAPI SetForegroundWindow(HWND);
BOOL WINAPI SetKeyboardState(PBYTE);
void WINAPI SetLastErrorEx(DWORD,DWORD);
BOOL WINAPI SetMenu(HWND,HMENU);
HWND WINAPI SetParent(HWND,HWND);
BOOL WINAPI SetProcessWindowStation(HWINSTA);
BOOL WINAPI SetPropA(HWND,LPCSTR,HANDLE);
BOOL WINAPI SetPropW(HWND,LPCWSTR,HANDLE);
BOOL WINAPI SetRect(LPRECT,int,int,int,int);
BOOL WINAPI SetRectEmpty(LPRECT);
int WINAPI SetScrollInfo(HWND,int,LPCSCROLLINFO,BOOL);
int WINAPI SetScrollPos(HWND,int,int,BOOL);
BOOL WINAPI SetScrollRange(HWND,int,int,int,BOOL);
BOOL WINAPI SetSysColors(int,const INT *,const COLORREF *);
BOOL WINAPI SetSystemCursor(HCURSOR,DWORD);
BOOL WINAPI SetThreadDesktop(HDESK);
BOOL WINAPI SetUserObjectInformationA(HANDLE,int,PVOID,DWORD);
BOOL WINAPI SetUserObjectInformationW(HANDLE,int,PVOID,DWORD);
BOOL WINAPI SetUserObjectSecurity(HANDLE,PSECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
BOOL WINAPI SetWindowContextHelpId(HWND,DWORD);
BOOL WINAPI SetWindowPlacement(HWND hWnd,const WINDOWPLACEMENT*);
BOOL WINAPI SetWindowPos(HWND,HWND,int,int,int,int,UINT);
int WINAPI SetWindowRgn(HWND,HRGN,BOOL);
WORD WINAPI SetWindowWord(HWND,int,WORD);
HOOKPROC WINAPI SetWindowsHookA(int,HOOKPROC);
HHOOK WINAPI SetWindowsHookExA(int,HOOKPROC,HINSTANCE,DWORD);
HHOOK WINAPI SetWindowsHookExW(int,HOOKPROC,HINSTANCE,DWORD);
BOOL WINAPI ShowCaret(HWND);
int WINAPI ShowCursor(BOOL);
BOOL WINAPI ShowOwnedPopups(HWND,BOOL);
BOOL WINAPI ShowScrollBar(HWND,int,BOOL);
BOOL WINAPI ShowWindow(HWND,int);
BOOL WINAPI ShowWindowAsync(HWND,int);
BOOL WINAPI SubtractRect(LPRECT,LPCRECT,LPCRECT);
BOOL WINAPI SwapMouseButton(BOOL);
BOOL WINAPI SwitchDesktop(HDESK);
BOOL WINAPI SystemParametersInfoA(UINT,UINT,PVOID,UINT);
BOOL WINAPI SystemParametersInfoW(UINT,UINT,PVOID,UINT);
LONG WINAPI TabbedTextOutA(HDC,int,int,LPCSTR,int,int,LPINT,int);
LONG WINAPI TabbedTextOutW(HDC,int,int,LPCWSTR,int,int,LPINT,int);
WORD WINAPI TileWindows(HWND,UINT,LPCRECT,UINT,const HWND *);
int WINAPI ToAscii(UINT,UINT,PBYTE,LPWORD,UINT);
int WINAPI ToAsciiEx(UINT,UINT,PBYTE,LPWORD,UINT,HKL);
int WINAPI ToUnicode(UINT,UINT,PBYTE,LPWSTR,int,UINT);
int WINAPI ToUnicodeEx(UINT,UINT,PBYTE,LPWSTR,int,UINT,HKL);
BOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT);
BOOL WINAPI TrackPopupMenu(HMENU,UINT,int,int,int,HWND,LPCRECT);
BOOL WINAPI TrackPopupMenuEx(HMENU,UINT,int,int,HWND,LPTPMPARAMS);
int WINAPI TranslateAcceleratorA(HWND,HACCEL,LPMSG);
int WINAPI TranslateAcceleratorW(HWND,HACCEL,LPMSG);
BOOL WINAPI TranslateMDISysAccel(HWND,LPMSG);
BOOL WINAPI UnhookWindowsHook(int,HOOKPROC);
BOOL WINAPI UnhookWindowsHookEx(HHOOK);
BOOL WINAPI UnionRect(LPRECT,LPCRECT,LPCRECT);
BOOL WINAPI UnloadKeyboardLayout(HKL);
BOOL WINAPI UnpackDDElParam(UINT,LONG,PUINT,PUINT);
BOOL WINAPI UnregisterHotKey(HWND,int);
BOOL WINAPI UpdateWindow(HWND);
BOOL WINAPI ValidateRect(HWND,LPCRECT);
BOOL WINAPI ValidateRgn(HWND,HRGN);
SHORT WINAPI VkKeyScanA(CHAR);
SHORT WINAPI VkKeyScanExA(CHAR,HKL);
SHORT WINAPI VkKeyScanExW(WCHAR,HKL);
SHORT WINAPI VkKeyScanW(WCHAR);
DWORD WINAPI WaitForInputIdle(HANDLE,DWORD);
BOOL WINAPI WinHelpA(HWND,LPCSTR,UINT,DWORD);
BOOL WINAPI WinHelpW(HWND,LPCWSTR,UINT,DWORD);
HWND WINAPI WindowFromDC(HDC hDC);
HWND WINAPI WindowFromPoint(POINT);
VOID WINAPI keybd_event(BYTE,BYTE,DWORD,DWORD);
void WINAPI mouse_event(DWORD,DWORD,DWORD,DWORD,DWORD);
int WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
int WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);

#	if defined(_BUILTIN_DLL)
void *User32_GetAddressByOrder(int order);
void *User32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__User32_h__)
