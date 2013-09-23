/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: StretchDIBits.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [StretchDIBits.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "StretchDIBits.h"
#include "Palette.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" int WINAPI
StretchDIBits
(HDC hdc, int XDest, int YDest, int nDestWidth, int nDestHeight,
		int XSrc, int YSrc, int nSrcWidth, int nSrcHeight,
		CONST VOID *lpBits, CONST BITMAPINFO *lpBitsInfo, UINT iUsage, DWORD dwRop)
{
	// 双方のサイズ比を求めた後に、それぞれクリッピング。サイズ比を元に
	// 転送先のクリッピング領域を転送元とAND写像（端数は切り捨てる）
	// 結果の領域で転送先サイズベースで伸長転送。
	int rc = 0;
	WIN32API_ENTER("int", "StretchDIBits", "HDC", hdc, "int", XDest, "int", YDest,
		"int", nDestWidth, "int", nDestHeight, "int", XSrc, "int", YSrc, "int", nSrcWidth, "int", nSrcHeight,
		"CONST VOID *", lpBits, "CONST BITMAPINFO *", lpBitsInfo, "UINT", iUsage, "DWORD", dwRop, NULL);
	WIN32API_INFO("\tTO (%d,%d)-(%d,%d)\n", XDest, YDest, XDest + nDestWidth, YDest + nDestHeight);
	WIN32API_INFO("\tFROM (%d,%d)-(%d,%d)\n", XSrc, YSrc, XSrc + nSrcWidth, YSrc + nSrcHeight);
	LPCBITMAPINFOHEADER ih = NULL;
	LPRGBQUAD rgbQuad = NULL;
	bool topdown = false;
	if (NULL != lpBitsInfo) {
		ih = &lpBitsInfo->bmiHeader;
		WIN32API_INFO("\tsize = %d\n", ih->biSize);
		WIN32API_INFO("\twidth = %d\n", ih->biWidth);
		WIN32API_INFO("\theight = %d\n", ih->biHeight);
		WIN32API_INFO("\tplanes = %d\n", ih->biPlanes);
		WIN32API_INFO("\tbitcount = %d\n", ih->biBitCount);
		if (ih->biHeight < 0) topdown = true;
		if (ih->biClrUsed != 0) rgbQuad = (LPRGBQUAD)lpBitsInfo->bmiColors;
	}
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if ((nDestWidth != nSrcWidth) || (nDestHeight != nSrcHeight)) {
		WIN32API_INFO("\tstretch not impl.\n");
		nSrcWidth = nDestWidth;
		nSrcHeight = nDestHeight;
	}
	if ((NULL != lpBitsInfo) && (NULL != dc)) {
		Bitmap *bitmap = dc->GetBitmap();
		bool dest_topdown = false;
		BBitmap *bmp = NULL;
		if (NULL != bitmap) {
			dest_topdown = bitmap->IsTopDown();
			bmp = bitmap->NativeBitmap();
		}
		if (NULL != bmp) {
			// clip
			BRect rect = bmp->Bounds();
			int width = (DWORD)rect.Width() + 1;
			int height = (DWORD)rect.Height() + 1;
			if (XSrc < 0) {
				nSrcWidth += XSrc;
				nDestWidth += XSrc;
				XDest -= XSrc;
				XSrc = 0;
			}
			if (YSrc < 0) {
				nSrcHeight += YSrc;
				nDestHeight += YSrc;
				YSrc = 0;
			}
			if (XDest < 0) {
				nDestWidth += XDest;
				nSrcWidth += YDest;
				XSrc -= XDest;
				XDest = 0;
			}
			if (YDest < 0) {
				nDestHeight += YDest;
				nSrcHeight += YDest;
				YDest = 0;
			}
			if ((XDest + nDestWidth) > width) {
				int diff = width - XDest - nDestWidth;
				nSrcWidth += diff;
				nDestWidth += diff;
			}
			if ((YDest + nDestHeight) > height) {
				int diff = height - YDest - nDestHeight;
				nSrcHeight += diff;
				nDestHeight += diff;
				YSrc -= diff;
			}
			WIN32API_INFO("\tCLIP TO (%d,%d)-(%d,%d)\n", XDest, YDest, XDest + nDestWidth, YDest + nDestHeight);
			WIN32API_INFO("\tCLIP FROM (%d,%d)-(%d,%d)\n", XSrc, YSrc, XSrc + nSrcWidth, YSrc + nSrcHeight);
			if (bmp->ColorSpace() == B_RGB32) {
				// B_RGB32
				long *p = (long *)bmp->Bits();
				int bpl = bmp->BytesPerRow() >> 2;
				if (dest_topdown) {
					p = &p[bpl * YDest + XDest];
				} else {
					p = &p[bpl * (nDestHeight - YDest - 1) + XDest];
					bpl = -bpl;
				}
				if (ih->biBitCount == 8) {
					unsigned char *q = (unsigned char *)lpBits;
					int qbpl = (ih->biWidth + 3) & ~3;
					if (topdown) q += qbpl * YSrc + XSrc;
					else q += qbpl * (nSrcHeight + YSrc - 1) + XSrc;
					long *cl = (long *)rgbQuad;
					if (NULL == cl) {
						Palette *pal = dc->GetPalette();
						if (NULL != pal) cl = pal->GetNativeEntries32();
					}
					if (NULL != cl) {
						if (!topdown) qbpl = -qbpl;
						for (int y = nDestHeight; y > 0; y--) {
							for (int x = nDestWidth - 1; x >= 0; x--) {
								p[x] = cl[q[x]];
							}
							p += bpl;
							q += qbpl;
						}
						rc = nDestHeight;
					}
				} else if (ih->biBitCount == 24) {
					unsigned char *q = (unsigned char *)lpBits;
					int qbpl = (ih->biWidth * 3 + 3) & ~3;
					if (topdown) q += qbpl * YSrc + XSrc * 3;
					else q += qbpl * (nSrcHeight + YSrc - 1) + XSrc * 3;
					if (!topdown) qbpl = -qbpl;
					for (int y = nDestHeight; y > 0; y--) {
						int o = (nDestWidth - 1) * 3;
						for (int x = nDestWidth - 1; x >= 0; x--) {
							p[x] = q[o + 2] << 16 | q[o + 1] << 8 | q[o + 0];
							o -= 3;
						}
						p += bpl;
						q += qbpl;
					}
					rc = nDestHeight;
				} else if (ih->biBitCount == 32) {
					unsigned long *q = (unsigned long *)lpBits;
					int qbpl = ih->biWidth;
					if (topdown) q += qbpl * YSrc + XSrc;
					else q += qbpl * (nSrcHeight + YSrc - 1) + XSrc;
					if (!topdown) qbpl = -qbpl;
					for (int y = nDestHeight; y > 0; y--) {
						for (int x = nDestWidth - 1; x >= 0; x--) p[x] = q[x];
						p += bpl;
						q += qbpl;
					}
					rc = nDestHeight;
				}
			} else {
				// B_RGB16
				short *p = (short *)bmp->Bits();
				int bpl = bmp->BytesPerRow() >> 1;
				p = &p[bpl * YDest + XDest];
				if (ih->biBitCount == 8) {
/*
					char *q = (char *)lpBits;
					if (topdown) q += ih->biWidth * YSrc + XSrc;
					else q += (ih->biWidth * (nDestHeight + YSrc - 1)) + XSrc;
					HPALETTE hPal = dc->GetPalette();
					Palette *pal = DYNAMIC_CAST(Palette *, Win32Handle::GetInstance((HANDLE)hPal));
					short *cl = NULL;
					if (NULL != pal) cl = pal->GetNativeEntries16();
					if (NULL != cl) {
						int qbpl = topdown? ih->biWidth: -ih->biWidth;
						for (int y = nDestHeight; y > 0; y--) {
							for (int x = nDestWidth - 1; x >= 0; x--) {
								p[x] = cl[q[x]];
							}
							p += bpl;
							q += qbpl;
						}
						rc = nDestHeight;
					}
*/
				} else if (ih->biBitCount == 24) {
					unsigned char *q = (unsigned char *)lpBits;
					if (topdown) q += (ih->biWidth * YSrc + XSrc) * 3;
					else q += (ih->biWidth * (nDestHeight + YSrc - 1) + XSrc) * 3;
					int qbpl = topdown? ih->biWidth * 3: -ih->biWidth * 3;
					for (int y = nDestHeight; y > 0; y--) {
						int o = (nDestWidth - 1) * 3;
						for (int x = nDestWidth - 1; x >= 0; x--) {
							p[x] = ((q[o + 2] & 0xf8) << 8) |
								((q[o + 1] & 0xf8) << 3) |
								(q[o + 0] >> 3);
							o -= 3;
						}
						p += bpl;
						q += qbpl;
					}
					rc = nDestHeight;
				}
			}
		}
		if (0 != rc) {
			WIN32API_INFO("\tupdate %d lines\n", rc);
			// XXX
			dc->Update();
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BitBlt
(HDC hdc, int nXDest, int nYDest, int nWidth, int nHeight, HDC hdcSrc, int nXSrc, int nYSrc, DWORD dwRop)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BitBlt", "HDC", hdc, "int", nXDest, "int", nYDest, "int", nWidth, "int", nHeight,
		"HDC", hdcSrc, "int", nXSrc, "int", nYSrc, "DWORD", dwRop, NULL);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdcSrc);
	if (NULL == dc) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		Bitmap *bmp = dc->GetBitmap();
		if (NULL != bmp) {
			LPBITMAPINFO bmi = bmp->Header();
			void *bits = bmp->Bits();
			WIN32API_INTERNAL_START();
			StretchDIBits(hdc, nXDest, nYDest, nWidth, nHeight,
				nXSrc, nYSrc, nWidth, nHeight, bits,
				(CONST BITMAPINFO *)bmi,
				(bmi->bmiHeader.biClrUsed == 0)? DIB_RGB_COLORS: DIB_PAL_COLORS, dwRop);
			WIN32API_INTERNAL_END();
		}
		rc = TRUE;
	}
	WIN32API_LEAVE(rc);
	return rc;
}
