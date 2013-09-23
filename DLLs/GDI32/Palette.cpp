/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Palette.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Message.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Palette.h"
#include "DeviceContext.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Palette::Palette
(void):
magic(PALETTE_MAGIC),
pal(NULL),
pal16(NULL),
n(0),
owner(NULL)
{
}

Palette::~Palette
(void)
{
	if (NULL != pal) free(pal);
	if (NULL != pal16) free(pal16);
	magic = 0;
}

bool
Palette::Initialize
(int entry)
{
	if (NULL != pal) free(pal);
	if (NULL != pal16) free(pal16);
	pal = (LPRGBQUAD)malloc(sizeof(RGBQUAD) * entry);
	pal16 = (short *)malloc(sizeof(short) * entry);
	if ((NULL == pal) || (NULL == pal16)) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		return false;
	}
	memset(pal, 0, sizeof(RGBQUAD) * entry);
	memset(pal16, 0, sizeof(short) * entry);
	n = entry;
	return true;
}

UINT
Palette::SetEntries
(UINT iStart, UINT cEntries, CONST PALETTEENTRY *lppe)
{
	for (UINT i = 0; i < cEntries; i++) {
		LPRGBQUAD p = &pal[iStart + i];
		LPPALETTEENTRY q = CONST_CAST(LPPALETTEENTRY, &lppe[i]);
		p->rgbRed = q->peRed;
		p->rgbGreen = q->peGreen;
		p->rgbBlue = q->peBlue;
	}
	return cEntries;
}

UINT
Palette::RealizeEntries
(UINT iStart, UINT cEntries, bool animate)
{
	if (cEntries > (UINT)n) cEntries = n;
	for (UINT i = 0; i < cEntries; i++) {
		LPRGBQUAD p = &pal[iStart + i];
		short *q = &pal16[iStart + i];
		*q = ((p->rgbRed >> 3) << 11) |
			((p->rgbGreen >> 3) << 6) |
			(p->rgbBlue >> 3);
	}
	if (animate && (0 != cEntries) && (NULL != owner)) {
		WIN32API_INFO("\tupdate palette\n");
		owner->RealizePalette();
	}
	return cEntries;
}

LPRGBQUAD
Palette::PeekEntries
(void)
{
	return pal;
}

long *
Palette::GetNativeEntries32
(void)
{
	return (long *)pal;
}

short *
Palette::GetNativeEntries16
(void)
{
	return pal16;
}

void
Palette::SetOwner
(DeviceContext *dc)
{
	owner = dc;
}

Palette *
Palette::HandleToPalette
(HPALETTE hpal)
{
	if (NULL == hpal) return NULL;
	Palette *pal = (Palette *)hpal;
	if (pal->magic != PALETTE_MAGIC) return NULL;
	return pal;
}

extern "C" BOOL WINAPI
AnimatePalette
(HPALETTE hPal, UINT iStartIndex, UINT cEntries, CONST PALETTEENTRY *ppe)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(ppe);
	WIN32API_ENTER("BOOL", "AnimatePalette", "HPALETTE", hPal, "UINT", iStartIndex, "UINT", cEntries, "CONST PALETTEENTRY *", ppe, NULL);
	Palette *pal = Palette::HandleToPalette(hPal);
	if (NULL != pal) {
		UINT n = pal->SetEntries(iStartIndex, cEntries, ppe);
		if (n == cEntries) {
			pal->RealizeEntries(iStartIndex, cEntries, true);
			rc = TRUE;
		}
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HPALETTE WINAPI
CreateHalftonePalette
(HDC hdc)
{
	HPALETTE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HPALETTE", "CreateHalftonePalette", "HDC", hdc, NULL);
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HPALETTE WINAPI
CreatePalette
(CONST LOGPALETTE *lplgpl)
{
	HPALETTE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HPALETTE", "CreatePalette", "CONST LOGPALETTE *", lplgpl, NULL);
	if (NULL != lplgpl) {
		WIN32API_INFO("\tpalVersion: %08x\n", lplgpl->palVersion);
		WIN32API_INFO("\tpalNumEntries: %08x\n", lplgpl->palNumEntries);
		Palette *pal = new Palette();
		if (NULL != pal) {
			if (pal->Initialize(lplgpl->palNumEntries)) {
				rc = (HPALETTE)pal;
				WIN32API_ERROR(ERROR_SUCCESS);
			}
		} else {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetNearestPaletteIndex
(HPALETTE arg0, COLORREF arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetNearestPaletteIndex", "HPALETTE", arg0, "COLORREF", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetPaletteEntries
(HPALETTE arg0, UINT arg1, UINT arg2, LPPALETTEENTRY arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetPaletteEntries", "HPALETTE", arg0, "UINT", arg1, "UINT", arg2, "LPPALETTEENTRY", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetSystemPaletteEntries
(HDC arg0, UINT arg1, UINT arg2, LPPALETTEENTRY arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetSystemPaletteEntries", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPPALETTEENTRY", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetSystemPaletteUse
(HDC arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetSystemPaletteUse", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
RealizePalette
(HDC hdc)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "RealizePalette", "HDC", hdc, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ResizePalette
(HPALETTE arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ResizePalette", "HPALETTE", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HPALETTE WINAPI
SelectPalette
(HDC hdc, HPALETTE hpal, BOOL bForceBackground)
{
	HPALETTE rc = NULL;
	WIN32API_ENTER("HPALETTE", "SelectPalette", "HDC", hdc, "HPALETTE", hpal, "BOOL", bForceBackground, NULL);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if (NULL != dc) {
		rc = dc->SelectPalette(Palette::HandleToPalette(hpal));
		WIN32API_ERROR(ERROR_SUCCESS);
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetPaletteEntries
(HPALETTE hPal, UINT iStart, UINT cEntries, CONST PALETTEENTRY *lppe)
{
	UINT rc = 0;
	WIN32API_ENTER("UINT", "SetPaletteEntries", "HPALETTE", hPal, "UINT", iStart, "UINT", cEntries, "CONST PALETTEENTRY *", lppe, NULL);
	Palette *pal = Palette::HandleToPalette(hPal);
	if (NULL != pal) rc = pal->SetEntries(iStart, cEntries, lppe);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetSystemPaletteUse
(HDC arg0, UINT arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "SetSystemPaletteUse", "HDC", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
