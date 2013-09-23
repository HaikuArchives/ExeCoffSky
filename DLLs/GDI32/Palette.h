/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Palette.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Palette.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Palette_h__)
#	define	__Palette_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Object_h__)
#		include "Object.h"
#	endif	// !defined(__Object_h__)

#	if !defined(__PALETTEENTRY__)

typedef struct tagPALETTEENTRY {
	PACKED(BYTE peRed);
	PACKED(BYTE peGreen);
	PACKED(BYTE peBlue);
	PACKED(BYTE peFlags);
} PALETTEENTRY, *LPPALETTEENTRY;

#		define	__PALETTEENTRY__
#	endif	// !defined(__PALETTEENTRY__)

typedef struct tagLOGPALETTE {
	PACKED(WORD palVersion);
	PACKED(WORD palNumEntries);
	PACKED(WORD palPalEntry[1]);
} LOGPALETTE, *LPLOGPALETTE;

#	if !defined(__GDI32_h__)
#		include "GDI32.h"
#	endif	// !defined(__GDI32_h__)

#	if !defined(__DeviceContext__)
class DeviceContext;
#		define	__DeviceContext__
#	endif	// !defined(__DeviceContext__)

#	if !defined(GDI_ERROR)
#		define	GDI_ERROR	0xffffffffL
#	endif	// !defined(GDI_ERROR)

#	define	PALETTE_MAGIC	'_PAL'

class Palette: public Object {
private:
	DWORD magic;
	LPRGBQUAD pal;
	short *pal16;
	int n;
	DeviceContext *owner;
public:

	Palette(void);
	~Palette(void);
	
	bool Initialize(int entry);
	UINT SetEntries(UINT iStart, UINT cEntries, CONST PALETTEENTRY *lppe);
	UINT RealizeEntries(UINT iStart, UINT cEntries = (UINT)-1, bool animate = false);

	LPRGBQUAD PeekEntries(void);
	long *GetNativeEntries32(void);
	short *GetNativeEntries16(void);

	void SetOwner(DeviceContext *dc);

	static Palette *HandleToPalette(HPALETTE hpal);
};

#	if !defined(__Palette__)
#		define	__Palette__
#	endif	// !defined(__Palette__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL WINAPI AnimatePalette(HPALETTE hpal, UINT iStartIndex, UINT cEntries, CONST PALETTEENTRY *ppe);
HPALETTE WINAPI CreateHalftonePalette(HDC hdc);
HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *lplgpl);
UINT WINAPI GetNearestPaletteIndex(HPALETTE hpal, COLORREF crColor);
UINT WINAPI GetPaletteEntries(HPALETTE hpal, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe);
UINT WINAPI GetSystemPaletteEntries(HDC hdc, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe);
UINT WINAPI GetSystemPaletteUse(HDC hdc);
UINT WINAPI RealizePalette(HDC hdc);
BOOL WINAPI ResizePalette(HPALETTE hpal, UINT nEntries);
HPALETTE WINAPI SelectPalette(HDC hdc, HPALETTE hpal, BOOL bForceBackground);
UINT WINAPI SetPaletteEntries(HPALETTE hPal, UINT iStart, UINT cEntries, CONST PALETTEENTRY *lppe);
UINT WINAPI SetSystemPaletteUse(HDC,UINT);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Palette_h__)
