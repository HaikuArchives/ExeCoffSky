/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Desktop.h,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Desktop.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Desktop_h__)
#	define	__Desktop_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Window_h__)
#		include "Window.h"
#	endif	// !defined(__Window_h__)

#	if !defined(__DeviceContext__)
#		include "DeviceContext.h"
#	endif	// !defined(__DeviceContext_h__)

class DesktopWindow: public Window {
private:
	DeviceContext dc;
public:
	DesktopWindow(void);
	~DesktopWindow(void);
	
	DeviceContext *GetDeviceContext(void) const;	// Window
	bool Show(bool show);	// Window
	bool GetTitle(LPSTR lpTitle, UINT &uSize);	// Window
	bool SetTitle(LPCSTR lpTitle);	// Window
	BOOL GetWindowRect(LPRECT lpRect);	// Window
	BOOL SetWindowPos(HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);	// Window
	
	LRESULT SendMessage(LPCMSG lpMsg);	// Window
	LRESULT SendMessage(UINT Msg, WPARAM wParam, LPARAM lParam);	// Window
	BOOL PostMessage(LPCMSG lpMsg);	// Window
	BOOL PostMessage(UINT Msg, WPARAM wParam, LPARAM lParam);	// Window
	
	void ClientToScreen(LPPOINT lpPoint);	// Window
	void ScreenToClient(LPPOINT lpPoint);	// Window
};

#	if !defined(__DesktopWindow__)
#		define	__DesktopWindow__
#	endif	// !defined(__DesktopWindow__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HWND WINAPI GetDesktopWindow(void);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Desktop_h__)
