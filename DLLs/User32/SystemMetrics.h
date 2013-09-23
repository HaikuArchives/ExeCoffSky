/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: SystemMetrics.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [SystemMetrics.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__SystemMetrics_h__)
#	define	__SystemMetrics_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	SM_CXSCREEN		0
#	define	SM_CYSCREEN		1
#	define	SM_CXVSCROLL	2
#	define	SM_CYHSCROLL	3
#	define	SM_CYCAPTION	4
#	define	SM_CXBORDER		5
#	define	SM_CYBORDER		6
#	define	SM_CXDLGFRAME	7
#	define	SM_CYDLGFRAME	8
// ...
#	define	SM_CYMENU		15
// ...
#	define	SM_CXFRAME		32
#	define	SM_CYFRAME		33

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

int WINAPI GetSystemMetrics(int nIndex);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__SystemMetrics_h__)
