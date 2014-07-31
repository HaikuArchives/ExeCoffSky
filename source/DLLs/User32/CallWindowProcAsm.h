/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: CallWindowProcAsm.h,v 1.1 2003/05/01 03:34:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CallWindowProcAsm.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__CallWindowProcAsm_h__)
#	define	__CallWindowProcAsm_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Window_h__)
#		include "Window.h"
#	endif	// !defined(__Window_h__)

extern "C" LRESULT CallWindowProcAsm(WNDPROC lpWindowProc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, long regbuf[3]);

#endif	// !defined(__CallWindowProcAsm_h__)
