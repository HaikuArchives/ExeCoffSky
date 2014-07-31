/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ShellAbout.h,v 1.1 2003/05/01 03:33:11 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ShellAbout.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__ShellAbout_h__)
#	define	__ShellAbout_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)

extern "C" {
#	endif	// defined(__cplusplus)

int WINAPI ShellAboutA(HWND hWnd, LPCSTR szApp, LPCSTR szOtherStuff, HICON hIcon);
int WINAPI ShellAboutW(HWND hWnd, LPCWSTR szApp, LPCWSTR szOtherStuff, HICON hIcon);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__ShellAbout_h__)
