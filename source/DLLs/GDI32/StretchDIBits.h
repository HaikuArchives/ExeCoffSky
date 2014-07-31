/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: StretchDIBits.h,v 1.1 2003/05/01 03:05:19 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [StretchDIBits.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__StretchDIBits_h__)
#	define	__StretchDIBits_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__GDI32_h__)
#		include "GDI32.h"
#	endif	// !defined(__GDI32_h__)

#	define	SRCCOPY		(DWORD)0x00cc0020
#	define	SRCPAINT	(DWORD)0x00ee0086
#	define	SRCAND		(DWORD)0x008800c6
#	define	SRCINVERT	(DWORD)0x00660046
#	define	SRCERASE	(DWORD)0x00440328
#	define	NOTSRCCOPY	(DWORD)0x00330008
#	define	NOTSRCERASE	(DWORD)0x001100a6
#	define	MERGECOPY	(DWORD)0x00c000ca
#	define	MERGEPAINT	(DWORD)0x00bb0226
#	define	PATCOPY		(DWORD)0x00f00021
#	define	PATPAINT	(DWORD)0x00fb0a09
#	define	PATINVERT	(DWORD)0x005a0049
#	define	DSTINVERT	(DWORD)0x00550009
#	define	BLACKNESS	(DWORD)0x00000042
#	define	WHITENESS	(DWORD)0x00ff0062

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

int WINAPI StretchDIBits(HDC hdc, int XDest, int YDest, int nDestWidth, int nDestHeight, int XSrc, int YSrc,
	int nSrcWidth, int nSrcHeight, CONST VOID *lpBits, CONST BITMAPINFO *lpBitsInfo, UINT iUsage, DWORD dwRop);

BOOL WINAPI BitBlt(HDC hdc, int nXDest, int nYDest, int nWidth, int nHeight,
	HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__StretchDIBits_h__)
