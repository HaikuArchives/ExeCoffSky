/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: DIBSection.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DIBSection.cpp]
 * TODO: リソースからの読み込みはCreateDIBitmapに変更するべき。
 * -------------------------------------------------------------------------------------------- */
#include "DIBSection.h"
#include "Bitmap.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" HBITMAP WINAPI
CreateDIBSection
(HDC hdc, CONST BITMAPINFO *pbmi, UINT iUsage, void **ppvBits, HANDLE hSection, DWORD dwOffset)
{
	HBITMAP rc = NULL;
	WIN32API_POINTER(pbmi);
	WIN32API_POINTER(ppvBits);
	WIN32API_ENTER("HBITMAP", "CreateDIBSection", "HDC", hdc, "CONST BITMAPINFO *", pbmi, "UINT", iUsage,
		"void **", ppvBits, "HANDLE", hSection, "DWORD", dwOffset, NULL);
	WIN32API_INFO("\tiUsage: %d\n", iUsage);
	WIN32API_INFO("\tignore hSection: $%08x\n", hSection);
	char *bits = NULL;
	if (ppvBits == (VOID **)-1) {
		// hook for LoadBitmap
		if (8 == pbmi->bmiHeader.biBitCount) {
			int clrUsed = pbmi->bmiHeader.biClrUsed;
			if (0 == clrUsed) clrUsed = 256;
			bits = (char *)&pbmi->bmiColors[clrUsed];
			WIN32API_INFO("\tnum of pallete entry: %d\n", clrUsed);
		} else bits = (char *)pbmi->bmiColors;
		ppvBits = NULL;
	}
	Bitmap *bitmap = new Bitmap(pbmi, (void *)bits);
	if (NULL == bitmap) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		if (NULL != ppvBits) *ppvBits = bitmap->Bits();
		rc = (HBITMAP)bitmap;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBITMAP WINAPI
CreateDIBitmap
(HDC hdc, CONST BITMAPINFOHEADER *lpbmih, DWORD fdwInit, CONST VOID *lpbInit, CONST BITMAPINFO *lpbmi, UINT fuUsage)
{
	HBITMAP rc = NULL;
	WIN32API_POINTER(lpbmih);
	WIN32API_POINTER(lpbInit);
	WIN32API_POINTER(lpbmi);
	WIN32API_ENTER("HBITMAP", "CreateDIBitmap", "HDC", hdc, "CONST BITMAPINFOHEADER *", lpbmih, "DWORD", fdwInit,
		"CONST VOID *", lpbInit, "CONST BITMAPINFO *", lpbmi, "UINT", fuUsage, NULL);
	Bitmap *bmp = new Bitmap(lpbmi, (void *)lpbInit);
	rc = (HBITMAP)bmp;
	WIN32API_LEAVE(rc);
	return rc;
}
