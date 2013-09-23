/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: IME.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [IME.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__IME_h__)
#	define	__IME_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

LRESULT WINAPI SendIMEMessageExA(HWND hwnd, LPARAM lParam);
LRESULT WINAPI SendIMEMessageExW(HWND hwnd, LPARAM lParam);

BOOL WINAPI WINNLSEnableIME(HWND hwnd, BOOL flag);
BOOL WINAPI WINNLSGetEnableStatus(HWND hwnd);
int WINAPI WINNLSGetIMEHotkey(HWND hwnd);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__IME_h__)
