/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DIBSection.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DIBSection.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__DIBSection_h__)
#	define	__DIBSection_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__GDI32_h__)
#		include "GDI32.h"
#	endif	// !defined(__GDI32_h__)

#	define	DIB_RGB_COLORS	0
#	define	DIB_PAL_COLORS	1

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HBITMAP WINAPI CreateDIBSection(HDC hdc, CONST BITMAPINFO *pbmi,
	UINT iUsage, void **ppvBits, HANDLE hSection, DWORD dwOffset);
HBITMAP WINAPI CreateDIBitmap(HDC hdc, CONST BITMAPINFOHEADER *lpbmih,
	DWORD fdwInit, CONST VOID *lpbInit, CONST BITMAPINFO *lpbmi, UINT fuUsage);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__DIBSection_h__)
