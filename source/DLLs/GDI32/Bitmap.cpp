/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Bitmap.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Bitmap.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Bitmap.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Bitmap::Bitmap
(int width, int height, int depth, const void *bits):
magic(BITMAP_MAGIC),
bmp(NULL),
bits(NULL),
freebits(false)
{
	bmi = (LPBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER));
	if (NULL == bmi) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		WIN32API_INFO("\tcan not allocate bitmapinfo\n");
		return;
	}
	memset(bmi, 0, sizeof(BITMAPINFOHEADER));
	LPBITMAPINFOHEADER bih = &bmi->bmiHeader;
	bih->biWidth = width;
	bih->biHeight = height;
	bih->biBitCount = depth;
	if (NULL == bits) Initialize();
	else this->bits = (void *)bits;
#if defined(_DEBUG)
	PrintToStream();
#endif	// defined(_DEBUG)
}

Bitmap::Bitmap
(CONST BITMAPINFO *pbmi, void *srcbits, int width, int height):
magic(BITMAP_MAGIC),
bmp(NULL),
bits(NULL),
freebits(false)
{
//	int clrUsed = pbmi->bmiHeader.biClrUsed;
//	if ((0 == clrUsed) && (8 == pbmi->bmiHeader.biBitCount)) clrUsed = 256;
	int clrUsed = 0;
	if (8 == pbmi->bmiHeader.biBitCount) clrUsed = 256;
	bmi = (LPBITMAPINFO)malloc(sizeof(BITMAPINFOHEADER) + clrUsed * sizeof(RGBQUAD));
	if (NULL == bmi) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		WIN32API_INFO("\tcan not allocate bitmapinfo\n");
		return;
	}
	memcpy(bmi, pbmi, sizeof(BITMAPINFOHEADER) + clrUsed * sizeof(RGBQUAD));
	LPBITMAPINFOHEADER bih = &bmi->bmiHeader;
	if (-1 != width) bih->biWidth = width;
	if (-1 != height) bih->biHeight = (bih->biHeight >= 0)? height: -height;
	bih->biClrUsed = clrUsed;
	if (0 != clrUsed) WIN32API_INFO("\tpalette table allocated\n");
	Initialize();
#if defined(_DEBUG)
	PrintToStream();
#endif	// defined(_DEBUG)
	if ((NULL == bits) || (NULL == srcbits)) return;
	int size = bih->biWidth * bih->biBitCount / 8;
	size += 3;
	size &= ~3;
	int h = bih->biHeight;
	if (h < 0) h = -h;
	size *= h;
	WIN32API_INFO("\tcopying bits (%d bytes) ...\n", size);
	memcpy(bits, srcbits, size);
	WIN32API_INFO("\tok\n");
}

Bitmap::~Bitmap
(void)
{
	if (NULL != bmp) delete bmp;
	if (freebits && (NULL != bits)) free(bits);
	if (NULL != bmi) free(bmi);
	magic = 0;
}

Bitmap *
Bitmap::CreateCompatible
(int width, int height)
{
	return new Bitmap(bmi, NULL, width, height);
}

void *
Bitmap::Bits
(void)
{
	return bits;
}

LPBITMAPINFO
Bitmap::Header
(void)
{
	return bmi;
}

BBitmap *
Bitmap::NativeBitmap
(void)
{
	return bmp;
}

bool
Bitmap::IsTopDown
(void) const
{
	if (NULL == bmi) return false;
	return bmi->bmiHeader.biHeight < 0;
}

#if defined(_DEBUG)
void
Bitmap::PrintToStream
(void)
{
	LPBITMAPINFOHEADER bih = &bmi->bmiHeader;
	WIN32API_INFO("\tbiSize: %d\n", bih->biSize);
	WIN32API_INFO("\tbiWidth: %d\n", bih->biWidth);
	WIN32API_INFO("\tbiHeight: %d\n", bih->biHeight);
	WIN32API_INFO("\tbiPlanes: %d\n", bih->biPlanes);
	WIN32API_INFO("\tbiBitCount: %d\n", bih->biBitCount);
	WIN32API_INFO("\tbiCompression: %d\n", bih->biCompression);
	WIN32API_INFO("\tbiSizeImage: %d\n", bih->biSizeImage);
	WIN32API_INFO("\tbiXPelsPerMeter: %d\n", bih->biXPelsPerMeter);
	WIN32API_INFO("\tbiYPelsPerMeter: %d\n", bih->biYPelsPerMeter);
	WIN32API_INFO("\tbiClrUsed: %d\n", bih->biClrUsed);
	WIN32API_INFO("\tbiClrImportant: %d\n", bih->biClrImportant);
}
#endif	// defined(_DEBUG)

void
Bitmap::Initialize
(void)
{
	LPBITMAPINFOHEADER bih = &bmi->bmiHeader;
	int h = bih->biHeight;
	if (h < 0) h = -h;
	int bpr = bih->biWidth * bih->biBitCount / 8;
	bpr += 3;
	bpr &= ~3;
	if ((16 == bih->biBitCount) || (32 == bih->biBitCount)) {
		color_space cs;
		if (16 == bih->biBitCount) cs = B_RGB16;
		else cs = B_RGB32;
		bmp = new BBitmap(BRect(0, 0, bih->biWidth - 1, h - 1), cs);
		if (NULL == bmp) bits = NULL;
		else bits = bmp->Bits();
		WIN32API_INFO("\tallocating native bitmap (%d bytes)\n", bmp->BytesPerRow() * h);
	} else {
		bmp = NULL;
		bits = malloc(bpr * h);
		freebits = true;
		WIN32API_INFO("\tallocating bitmap (%d bytes)\n", bpr * h);
	}
}

Bitmap *
Bitmap::HandleToBitmap
(HBITMAP hBitmap)
{
	if (NULL == hBitmap) return NULL;
	Bitmap *bmp = (Bitmap *)hBitmap;
	if (bmp->magic != BITMAP_MAGIC) return NULL;
	return bmp;
}

extern "C" HBITMAP WINAPI
CreateBitmap
(int nWidth, int nHeight, UINT cPlanes, UINT cBitsPerPal, CONST VOID *lpvBits)
{
	HBITMAP rc = NULL;
	WIN32API_ENTER("HBITMAP", "CreateBitmap", "int", nWidth, "int", nHeight, "UINT", cPlanes, "UINT", cBitsPerPal, "CONST VOID *", lpvBits, NULL);
	if (1 != cPlanes) {
		WIN32API_INFO("\tcPlanes != 1: not impl\n");
		WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	} else {
		rc = (HBITMAP)new Bitmap(nWidth, nHeight, cBitsPerPal, lpvBits);
		if (NULL != rc) WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBITMAP WINAPI
CreateBitmapIndirect
(CONST BITMAP *lpbm)
{
	HBITMAP rc = NULL;
	WIN32API_ENTER("HBITMAP", "CreateBitmapIndirect", "CONST BITMAP *", lpbm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBITMAP WINAPI
CreateCompatibleBitmap
(HDC hdc, int nWidth, int nHeight)
{
	HBITMAP rc = NULL;
	WIN32API_ENTER("HBITMAP", "CreateCompatibleBitmap", "HDC", hdc, "int", nWidth, "int", nHeight, NULL);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if (NULL == dc) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		Bitmap *bmp = dc->GetBitmap();
		if (NULL != bmp) rc = (HBITMAP)bmp->CreateCompatible(nWidth, nHeight);
	}
	WIN32API_LEAVE(rc);
	return rc;
}
