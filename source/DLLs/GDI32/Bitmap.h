/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Bitmap.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Bitmap.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Bitmap_h__)
#	define	__Bitmap_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Object_h__)
#		include "Object.h"
#	endif	// !defined(__Object_h__)

#	if !defined(__GDI32_h__)
#		include "GDI32.h"
#	endif	// !defined(__GDI32_h__)

#	define	BITMAP_MAGIC	'_BMP'

class Bitmap: public Object {
private:
	DWORD magic;
	BITMAPINFO *bmi;
	BBitmap *bmp;
	void *bits;
	bool freebits;
public:
	Bitmap(int width, int height, int depth, const void *bits = NULL);
	Bitmap(CONST BITMAPINFO *pbmi, void *bits = NULL, int fix_width = -1, int fix_height = -1);
	~Bitmap(void);
	
	Bitmap *CreateCompatible(int width, int height);
	
	void *Bits(void);
	LPBITMAPINFO Header(void);
	BBitmap *NativeBitmap(void);
	bool IsTopDown(void) const;

#	if defined(_DEBUG)
	void PrintToStream(void);
#	endif	// defined(_DEBUG)
private:
	void Initialize(void);
public:
	static Bitmap *HandleToBitmap(HBITMAP hBitmap);
};

#	if !defined(__Bitmap__)
#		define	__Bitmap__
#	endif	// !defined(__Bitmap__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HBITMAP WINAPI CreateBitmap(int nWidth, int nHeight, UINT cPlanes, UINT cBitsPerPal, CONST VOID *lpvBits);
HBITMAP WINAPI CreateBitmapIndirect(CONST BITMAP *lpbm);
HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc, int nWidth, int nHeight);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Bitmap_h__)
