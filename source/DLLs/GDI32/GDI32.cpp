/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: GDI32.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [GDI32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "GDI32.h"
#include "Window.h"
#include "Palette.h"
#include "DeviceContext.h"
#include "Win32Trace.h"

extern "C" HGDIOBJ WINAPI
GetStockObject
(int fnObject)
{
	HGDIOBJ rc = NULL;
	WIN32API_ENTER("HGDIOBJ", "GetStockObject", "int", fnObject, NULL);
	WIN32API_INFO("\tnot impl.\n");
	rc = (HGDIOBJ)0xfcfcfcfc;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UpdateColors
(HDC hdc)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UpdateColors", "HDC", hdc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetDIBitsToDevice
(HDC hdc, int Xdest, int Ydest, DWORD dwWidth, DWORD dwHeight,
	int XSrc, int YSrc, UINT uStartScan, UINT cScanLines, CONST VOID *lpvBits, CONST BITMAPINFO *lpbmi, UINT fuColorUse)
{
	int rc = 0;
	WIN32API_ENTER("int", "SetDIBitsToDevice", "HDC", hdc, "int", Xdest, "int", Ydest, "DWORD", dwWidth, "DWORD", dwHeight, "int", XSrc, "int", YSrc, "UINT", uStartScan, "UINT", cScanLines, "UINT", fuColorUse, NULL);
	WIN32API_INFO("\tTO (%d,%d)-(%d,%d)\n", Xdest, Ydest, Xdest + dwWidth, Ydest + dwHeight);
	WIN32API_INFO("\tFROM (%d,%d)\n", XSrc, YSrc);
	WIN32API_INFO("\tStartScan: %08x\n", uStartScan);
	WIN32API_INFO("\tScanLines: %08x\n", cScanLines);
	WIN32API_INFO("\tColorUse: %08x\n\n", fuColorUse);
	LPCBITMAPINFOHEADER ih = &lpbmi->bmiHeader;
	WIN32API_INFO("\twidth = %d\n", ih->biWidth);
	WIN32API_INFO("\theight = %d\n", ih->biHeight);
	WIN32API_INFO("\tplanes = %d\n", ih->biPlanes);
	WIN32API_INFO("\tbitcount = %d\n", ih->biBitCount);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if (NULL != dc) {
		Bitmap *bitmap = dc->GetBitmap();
		BBitmap *bmp = (NULL != bitmap)? bitmap->NativeBitmap(): NULL;
		if (NULL == bmp) {
			WIN32API_INFO("\tcan not get native bitmap\n");
		} else {
			BRect rect = bmp->Bounds();
			DWORD width = (DWORD)rect.Width() + 1;
			DWORD height = (DWORD)rect.Height() + 1;
			if ((Xdest + dwWidth) > width) dwWidth = width - Xdest;
			if ((Ydest + dwHeight) > height) dwHeight = height - Ydest;
			if (dwHeight > cScanLines) dwHeight = cScanLines;
			if (bmp->ColorSpace() == B_RGB32) {
				// B_RGB32
				long *p = (long *)bmp->Bits();
				int bpl = bmp->BytesPerRow() >> 2;
				p = &p[bpl * Ydest + Xdest];
				if (ih->biBitCount == 8) {
					unsigned char *q = (unsigned char *)lpvBits;
					q += dwWidth * (dwHeight - 1);
					Palette *pal = dc->GetPalette();
					long *cl = NULL;
					if (NULL != pal) cl = pal->GetNativeEntries32();
					if (NULL == cl) {
						WIN32API_INFO("\tcan not get native palette entry\n");
					} else {
						for (int y = dwHeight; y > 0; y--) {
							for (int x = dwWidth - 1; x >= 0; x--) {
								p[x] = cl[q[x]];
							}
							p += bpl;
							q -= dwWidth;
						}
						rc = dwHeight;
					}
				}
			} else {
				// B_RGB16
				short *p = (short *)bmp->Bits();
				int bpl = bmp->BytesPerRow() >> 1;
				p = &p[bpl * Ydest + Xdest];
				if (ih->biBitCount == 8) {
					unsigned char *q = (unsigned char *)lpvBits;
					q += dwWidth * (dwHeight - 1);
					Palette *pal = dc->GetPalette();
					short *cl = NULL;
					if (NULL != pal) cl = pal->GetNativeEntries16();
					if (NULL == cl) {
						WIN32API_INFO("\tcan not get native palette entry\n");
					} else {
						for (int y = dwHeight; y > 0; y--) {
							for (int x = dwWidth - 1; x >= 0; x--) {
								p[x] = cl[q[x]];
							}
							p += bpl;
							q -= dwWidth;
						}
						rc = dwHeight;
					}
				}
			}
		}
		// XXX
		dc->Update();
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
AbortDoc
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "AbortDoc", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AbortPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AbortPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AngleArc
(HDC arg0, int arg1, int arg2, DWORD arg3, FLOAT arg4, FLOAT arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AngleArc", "HDC", arg0, "int", arg1, "int", arg2, "DWORD", arg3, "FLOAT", arg4, "FLOAT", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Arc
(HDC arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Arc", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ArcTo
(HDC arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ArcTo", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
BeginPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "BeginPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CheckColorsInGamut
(HDC arg0, PVOID arg1, PVOID arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CheckColorsInGamut", "HDC", arg0, "PVOID", arg1, "PVOID", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ChoosePixelFormat
(HDC arg0, CONST PIXELFORMATDESCRIPTOR* arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ChoosePixelFormat", "HDC", arg0, "CONST PIXELFORMATDESCRIPTOR*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Chord
(HDC arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Chord", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
CloseEnhMetaFile
(HDC arg0)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "CloseEnhMetaFile", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CloseFigure
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CloseFigure", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMETAFILE WINAPI
CloseMetaFile
(HDC arg0)
{
	HMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMETAFILE", "CloseMetaFile", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ColorMatchToTarget
(HDC arg0, HDC arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ColorMatchToTarget", "HDC", arg0, "HDC", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}


extern "C" BOOL WINAPI
CombineTransform
(LPXFORM arg0, const XFORM* arg1, const XFORM* arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CombineTransform", "LPXFORM", arg0, "const XFORM*", arg1, "const XFORM*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
CopyEnhMetaFileA
(HENHMETAFILE arg0, LPCSTR arg1)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "CopyEnhMetaFileA", "HENHMETAFILE", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
CopyEnhMetaFileW
(HENHMETAFILE arg0, LPCWSTR arg1)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "CopyEnhMetaFileW", "HENHMETAFILE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMETAFILE WINAPI
CopyMetaFileA
(HMETAFILE arg0, LPCSTR arg1)
{
	HMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMETAFILE", "CopyMetaFileA", "HMETAFILE", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMETAFILE WINAPI
CopyMetaFileW
(HMETAFILE arg0, LPCWSTR arg1)
{
	HMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMETAFILE", "CopyMetaFileW", "HMETAFILE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
CreateBrushIndirect
(const LOGBRUSH* arg0)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "CreateBrushIndirect", "const LOGBRUSH*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCOLORSPACE WINAPI
CreateColorSpaceA
(LPLOGCOLORSPACEA arg0)
{
	HCOLORSPACE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCOLORSPACE", "CreateColorSpaceA", "LPLOGCOLORSPACEA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCOLORSPACE WINAPI
CreateColorSpaceW
(LPLOGCOLORSPACEW arg0)
{
	HCOLORSPACE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCOLORSPACE", "CreateColorSpaceW", "LPLOGCOLORSPACEW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
CreateDIBPatternBrush
(HGLOBAL arg0, UINT arg1)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "CreateDIBPatternBrush", "HGLOBAL", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
CreateDIBPatternBrushPt
(PCVOID arg0, UINT arg1)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "CreateDIBPatternBrushPt", "PCVOID", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBITMAP WINAPI
CreateDiscardableBitmap
(HDC arg0, int arg1, int arg2)
{
	HBITMAP rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBITMAP", "CreateDiscardableBitmap", "HDC", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateEnhMetaFileA
(HDC arg0, LPCSTR arg1, LPCRECT arg2, LPCSTR arg3)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "CreateEnhMetaFileA", "HDC", arg0, "LPCSTR", arg1, "LPCRECT", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateEnhMetaFileW
(HDC arg0, LPCWSTR arg1, LPCRECT arg2, LPCWSTR arg3)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "CreateEnhMetaFileW", "HDC", arg0, "LPCWSTR", arg1, "LPCRECT", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
CreateHatchBrush
(int arg0, COLORREF arg1)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "CreateHatchBrush", "int", arg0, "COLORREF", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateMetaFileA
(LPCSTR arg0)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "CreateMetaFileA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateMetaFileW
(LPCWSTR arg0)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "CreateMetaFileW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
CreatePatternBrush
(HBITMAP arg0)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "CreatePatternBrush", "HBITMAP", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HPEN WINAPI
CreatePen
(int arg0, int arg1, COLORREF arg2)
{
	HPEN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HPEN", "CreatePen", "int", arg0, "int", arg1, "COLORREF", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HPEN WINAPI
CreatePenIndirect
(const LOGPEN* arg0)
{
	HPEN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HPEN", "CreatePenIndirect", "const LOGPEN*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBRUSH WINAPI
CreateSolidBrush
(COLORREF arg0)
{
	HBRUSH rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBRUSH", "CreateSolidBrush", "COLORREF", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DPtoLP
(HDC arg0, LPPOINT arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DPtoLP", "HDC", arg0, "LPPOINT", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteColorSpace
(HCOLORSPACE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteColorSpace", "HCOLORSPACE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteEnhMetaFile
(HENHMETAFILE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteEnhMetaFile", "HENHMETAFILE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteMetaFile
(HMETAFILE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteMetaFile", "HMETAFILE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DescribePixelFormat
(HDC arg0, int arg1, UINT arg2, LPPIXELFORMATDESCRIPTOR arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DescribePixelFormat", "HDC", arg0, "int", arg1, "UINT", arg2, "LPPIXELFORMATDESCRIPTOR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
DrawEscape
(HDC arg0, int arg1, int arg2, LPCSTR arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "DrawEscape", "HDC", arg0, "int", arg1, "int", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Ellipse
(HDC arg0, int arg1, int arg2, int arg3, int arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Ellipse", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EndDoc
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EndDoc", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EndPage
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EndPage", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EndPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EndPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumEnhMetaFile
(HDC arg0, HENHMETAFILE arg1, ENHMFENUMPROC arg2, PVOID arg3, LPCRECT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumEnhMetaFile", "HDC", arg0, "HENHMETAFILE", arg1, "ENHMFENUMPROC", arg2, "PVOID", arg3, "LPCRECT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumICMProfilesA
(HDC arg0, ICMENUMPROCA arg1, LPARAM arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumICMProfilesA", "HDC", arg0, "ICMENUMPROCA", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumICMProfilesW
(HDC arg0, ICMENUMPROCW arg1, LPARAM arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumICMProfilesW", "HDC", arg0, "ICMENUMPROCW", arg1, "LPARAM", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumMetaFile
(HDC arg0, HMETAFILE arg1, MFENUMPROC arg2, LPARAM arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumMetaFile", "HDC", arg0, "HMETAFILE", arg1, "MFENUMPROC", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumObjects
(HDC arg0, int arg1, GOBJENUMPROC arg2, LPARAM arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumObjects", "HDC", arg0, "int", arg1, "GOBJENUMPROC", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
Escape
(HDC arg0, int arg1, int arg2, LPCSTR arg3, PVOID arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "Escape", "HDC", arg0, "int", arg1, "int", arg2, "LPCSTR", arg3, "PVOID", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ExcludeClipRect
(HDC arg0, int arg1, int arg2, int arg3, int arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ExcludeClipRect", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HPEN WINAPI
ExtCreatePen
(DWORD arg0, DWORD arg1, const LOGBRUSH* arg2, DWORD arg3, const DWORD* arg4)
{
	HPEN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HPEN", "ExtCreatePen", "DWORD", arg0, "DWORD", arg1, "const LOGBRUSH*", arg2, "DWORD", arg3, "const DWORD*", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ExtEscape
(HDC arg0, int arg1, int arg2, LPCSTR arg3, int arg4, LPSTR arg5)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ExtEscape", "HDC", arg0, "int", arg1, "int", arg2, "LPCSTR", arg3, "int", arg4, "LPSTR", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ExtFloodFill
(HDC arg0, int arg1, int arg2, COLORREF arg3, UINT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ExtFloodFill", "HDC", arg0, "int", arg1, "int", arg2, "COLORREF", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ExtTextOutA
(HDC arg0, int arg1, int arg2, UINT arg3, LPCRECT arg4, LPCSTR arg5, UINT arg6, const INT* arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ExtTextOutA", "HDC", arg0, "int", arg1, "int", arg2, "UINT", arg3, "LPCRECT", arg4, "LPCSTR", arg5, "UINT", arg6, "const INT*", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ExtTextOutW
(HDC arg0, int arg1, int arg2, UINT arg3, LPCRECT arg4, LPCWSTR arg5, UINT arg6, const INT* arg7)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ExtTextOutW", "HDC", arg0, "int", arg1, "int", arg2, "UINT", arg3, "LPCRECT", arg4, "LPCWSTR", arg5, "UINT", arg6, "const INT*", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FillPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FillPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FixBrushOrgEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FixBrushOrgEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FlattenPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlattenPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FloodFill
(HDC arg0, int arg1, int arg2, COLORREF arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FloodFill", "HDC", arg0, "int", arg1, "int", arg2, "COLORREF", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GdiComment
(HDC arg0, UINT arg1, const BYTE* arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GdiComment", "HDC", arg0, "UINT", arg1, "const BYTE*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GdiFlush
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GdiFlush", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GdiGetBatchLimit
(void)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GdiGetBatchLimit", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GdiSetBatchLimit
(DWORD arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GdiSetBatchLimit", "DWORD", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetArcDirection
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetArcDirection", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetAspectRatioFilterEx
(HDC arg0, LPSIZE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetAspectRatioFilterEx", "HDC", arg0, "LPSIZE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
GetBitmapBits
(HBITMAP arg0, LONG arg1, PVOID arg2)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "GetBitmapBits", "HBITMAP", arg0, "LONG", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetBitmapDimensionEx
(HBITMAP arg0, LPSIZE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetBitmapDimensionEx", "HBITMAP", arg0, "LPSIZE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
GetBkColor
(HDC arg0)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "GetBkColor", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetBkMode
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetBkMode", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetBoundsRect
(HDC arg0, LPRECT arg1, UINT arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetBoundsRect", "HDC", arg0, "LPRECT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetBrushOrgEx
(HDC arg0, LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetBrushOrgEx", "HDC", arg0, "LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharABCWidthsA
(HDC arg0, UINT arg1, UINT arg2, LPABC arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharABCWidthsA", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPABC", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharABCWidthsFloatA
(HDC arg0, UINT arg1, UINT arg2, LPABCFLOAT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharABCWidthsFloatA", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPABCFLOAT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharABCWidthsFloatW
(HDC arg0, UINT arg1, UINT arg2, LPABCFLOAT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharABCWidthsFloatW", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPABCFLOAT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharABCWidthsW
(HDC arg0, UINT arg1, UINT arg2, LPABC arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharABCWidthsW", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPABC", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharWidth32A
(HDC arg0, UINT arg1, UINT arg2, LPINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharWidth32A", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharWidth32W
(HDC arg0, UINT arg1, UINT arg2, LPINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharWidth32W", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharWidthA
(HDC arg0, UINT arg1, UINT arg2, LPINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharWidthA", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharWidthFloatA
(HDC arg0, UINT arg1, UINT arg2, PFLOAT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharWidthFloatA", "HDC", arg0, "UINT", arg1, "UINT", arg2, "PFLOAT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharWidthFloatW
(HDC arg0, UINT arg1, UINT arg2, PFLOAT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharWidthFloatW", "HDC", arg0, "UINT", arg1, "UINT", arg2, "PFLOAT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCharWidthW
(HDC arg0, UINT arg1, UINT arg2, LPINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCharWidthW", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCharacterPlacementA
(HDC arg0, LPCSTR arg1, int arg2, int arg3, LPGCP_RESULTSA arg4, DWORD arg5)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetCharacterPlacementA", "HDC", arg0, "LPCSTR", arg1, "int", arg2, "int", arg3, "LPGCP_RESULTSA", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetCharacterPlacementW
(HDC arg0, LPCWSTR arg1, int arg2, int arg3, LPGCP_RESULTSW arg4, DWORD arg5)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetCharacterPlacementW", "HDC", arg0, "LPCWSTR", arg1, "int", arg2, "int", arg3, "LPGCP_RESULTSW", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetClipBox
(HDC arg0, LPRECT arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetClipBox", "HDC", arg0, "LPRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetColorAdjustment
(HDC arg0, LPCOLORADJUSTMENT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetColorAdjustment", "HDC", arg0, "LPCOLORADJUSTMENT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
GetColorSpace
(HDC arg0)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "GetColorSpace", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HGDIOBJ WINAPI
GetCurrentObject
(HDC arg0, UINT arg1)
{
	HGDIOBJ rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HGDIOBJ", "GetCurrentObject", "HDC", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetCurrentPositionEx
(HDC arg0, LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetCurrentPositionEx", "HDC", arg0, "LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDCOrgEx
(HDC arg0, LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetDCOrgEx", "HDC", arg0, "LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetDIBColorTable
(HDC arg0, UINT arg1, UINT arg2, RGBQUAD* arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetDIBColorTable", "HDC", arg0, "UINT", arg1, "UINT", arg2, "RGBQUAD*", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetDIBits
(HDC arg0, HBITMAP arg1, UINT arg2, UINT arg3, PVOID arg4, LPBITMAPINFO arg5, UINT arg6)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetDIBits", "HDC", arg0, "HBITMAP", arg1, "UINT", arg2, "UINT", arg3, "PVOID", arg4, "LPBITMAPINFO", arg5, "UINT", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetDeviceGammaRamp
(HDC arg0, PVOID arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetDeviceGammaRamp", "HDC", arg0, "PVOID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
GetEnhMetaFileA
(LPCSTR arg0)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "GetEnhMetaFileA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetEnhMetaFileDescriptionA
(HENHMETAFILE arg0, UINT arg1, LPSTR arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetEnhMetaFileDescriptionA", "HENHMETAFILE", arg0, "UINT", arg1, "LPSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetEnhMetaFileDescriptionW
(HENHMETAFILE arg0, UINT arg1, LPWSTR arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetEnhMetaFileDescriptionW", "HENHMETAFILE", arg0, "UINT", arg1, "LPWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetEnhMetaFileHeader
(HENHMETAFILE arg0, UINT arg1, LPENHMETAHEADER arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetEnhMetaFileHeader", "HENHMETAFILE", arg0, "UINT", arg1, "LPENHMETAHEADER", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetEnhMetaFilePaletteEntries
(HENHMETAFILE arg0, UINT arg1, LPPALETTEENTRY arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetEnhMetaFilePaletteEntries", "HENHMETAFILE", arg0, "UINT", arg1, "LPPALETTEENTRY", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetEnhMetaFilePixelFormat
(HENHMETAFILE arg0, DWORD arg1, PIXELFORMATDESCRIPTOR* arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetEnhMetaFilePixelFormat", "HENHMETAFILE", arg0, "DWORD", arg1, "PIXELFORMATDESCRIPTOR*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
GetEnhMetaFileW
(LPCWSTR arg0)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "GetEnhMetaFileW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetGraphicsMode
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetGraphicsMode", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetICMProfileA
(HDC arg0, DWORD arg1, LPSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetICMProfileA", "HDC", arg0, "DWORD", arg1, "LPSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetICMProfileW
(HDC arg0, DWORD arg1, LPWSTR arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetICMProfileW", "HDC", arg0, "DWORD", arg1, "LPWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetKerningPairsA
(HDC arg0, DWORD arg1, LPKERNINGPAIR arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetKerningPairsA", "HDC", arg0, "DWORD", arg1, "LPKERNINGPAIR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetKerningPairsW
(HDC arg0, DWORD arg1, LPKERNINGPAIR arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetKerningPairsW", "HDC", arg0, "DWORD", arg1, "LPKERNINGPAIR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetLogColorSpaceA
(HCOLORSPACE arg0, LPLOGCOLORSPACEA arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetLogColorSpaceA", "HCOLORSPACE", arg0, "LPLOGCOLORSPACEA", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetLogColorSpaceW
(HCOLORSPACE arg0, LPLOGCOLORSPACEW arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetLogColorSpaceW", "HCOLORSPACE", arg0, "LPLOGCOLORSPACEW", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetMapMode
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetMapMode", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMETAFILE WINAPI
GetMetaFileA
(LPCSTR arg0)
{
	HMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMETAFILE", "GetMetaFileA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetMetaFileBitsEx
(HMETAFILE arg0, UINT arg1, PVOID arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetMetaFileBitsEx", "HMETAFILE", arg0, "UINT", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMETAFILE WINAPI
GetMetaFileW
(LPCWSTR arg0)
{
	HMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMETAFILE", "GetMetaFileW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetMiterLimit
(HDC arg0, PFLOAT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetMiterLimit", "HDC", arg0, "PFLOAT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
GetNearestColor
(HDC arg0, COLORREF arg1)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "GetNearestColor", "HDC", arg0, "COLORREF", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetObjectA
(HGDIOBJ arg0, int arg1, PVOID arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetObjectA", "HGDIOBJ", arg0, "int", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetObjectType
(HGDIOBJ arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetObjectType", "HGDIOBJ", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetObjectW
(HGDIOBJ arg0, int arg1, PVOID arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetObjectW", "HGDIOBJ", arg0, "int", arg1, "PVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetOutlineTextMetricsA
(HDC arg0, UINT arg1, LPOUTLINETEXTMETRICA arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetOutlineTextMetricsA", "HDC", arg0, "UINT", arg1, "LPOUTLINETEXTMETRICA", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetOutlineTextMetricsW
(HDC arg0, UINT arg1, LPOUTLINETEXTMETRICW arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetOutlineTextMetricsW", "HDC", arg0, "UINT", arg1, "LPOUTLINETEXTMETRICW", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetPath
(HDC arg0, LPPOINT arg1, PBYTE arg2, int arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetPath", "HDC", arg0, "LPPOINT", arg1, "PBYTE", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
GetPixel
(HDC arg0, int arg1, int arg2)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "GetPixel", "HDC", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetPixelFormat
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetPixelFormat", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetPolyFillMode
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetPolyFillMode", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetROP2
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetROP2", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetRasterizerCaps
(LPRASTERIZER_STATUS arg0, UINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetRasterizerCaps", "LPRASTERIZER_STATUS", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetStretchBltMode
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetStretchBltMode", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetTextAlign
(HDC arg0)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetTextAlign", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTextCharacterExtra
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetTextCharacterExtra", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTextCharset
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetTextCharset", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTextCharsetInfo
(HDC arg0, LPFONTSIGNATURE arg1, DWORD arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetTextCharsetInfo", "HDC", arg0, "LPFONTSIGNATURE", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
GetTextColor
(HDC arg0)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "GetTextColor", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextExtentExPointA
(HDC arg0, LPCSTR arg1, int arg2, int arg3, LPINT arg4, LPINT arg5, LPSIZE arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextExtentExPointA", "HDC", arg0, "LPCSTR", arg1, "int", arg2, "int", arg3, "LPINT", arg4, "LPINT", arg5, "LPSIZE", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextExtentExPointW
( HDC arg0, LPCWSTR arg1, int arg2, int arg3, LPINT arg4, LPINT arg5, LPSIZE  arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextExtentExPointW", " HDC", arg0, "LPCWSTR", arg1, "int", arg2, "int", arg3, "LPINT", arg4, "LPINT", arg5, "LPSIZE ", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextExtentPoint32A
(HDC arg0, LPCSTR arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextExtentPoint32A", "HDC", arg0, "LPCSTR", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextExtentPoint32W
( HDC arg0, LPCWSTR arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextExtentPoint32W", " HDC", arg0, "LPCWSTR", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextExtentPointA
(HDC arg0, LPCSTR arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextExtentPointA", "HDC", arg0, "LPCSTR", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextExtentPointW
(HDC arg0, LPCWSTR arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextExtentPointW", "HDC", arg0, "LPCWSTR", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTextFaceA
(HDC arg0, int arg1, LPSTR arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetTextFaceA", "HDC", arg0, "int", arg1, "LPSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetTextFaceW
(HDC arg0, int arg1, LPWSTR arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetTextFaceW", "HDC", arg0, "int", arg1, "LPWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextMetricsA
(HDC arg0, LPTEXTMETRICA arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextMetricsA", "HDC", arg0, "LPTEXTMETRICA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetTextMetricsW
(HDC arg0, LPTEXTMETRICW arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetTextMetricsW", "HDC", arg0, "LPTEXTMETRICW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetViewportExtEx
(HDC arg0, LPSIZE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetViewportExtEx", "HDC", arg0, "LPSIZE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetViewportOrgEx
(HDC arg0, LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetViewportOrgEx", "HDC", arg0, "LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetWinMetaFileBits
(HENHMETAFILE arg0, UINT arg1, LPBYTE arg2, INT arg3, HDC arg4)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetWinMetaFileBits", "HENHMETAFILE", arg0, "UINT", arg1, "LPBYTE", arg2, "INT", arg3, "HDC", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetWindowExtEx
(HDC arg0, LPSIZE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetWindowExtEx", "HDC", arg0, "LPSIZE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetWindowOrgEx
(HDC arg0, LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetWindowOrgEx", "HDC", arg0, "LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetWorldTransform
(HDC arg0, LPXFORM arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetWorldTransform", "HDC", arg0, "LPXFORM", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
IntersectClipRect
(HDC arg0, int arg1, int arg2, int arg3, int arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "IntersectClipRect", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LPtoDP
(HDC arg0, LPPOINT arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LPtoDP", "HDC", arg0, "LPPOINT", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LineDDA
(int arg0, int arg1, int arg2, int arg3, LINEDDAPROC arg4, LPARAM arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LineDDA", "int", arg0, "int", arg1, "int", arg2, "int", arg3, "LINEDDAPROC", arg4, "LPARAM", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
LineTo
(HDC arg0, int arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "LineTo", "HDC", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MaskBlt
(HDC arg0, int arg1, int arg2, int arg3, int arg4, HDC arg5, int arg6, int arg7, HBITMAP arg8, int arg9, int arg10, DWORD arg11)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MaskBlt", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "HDC", arg5, "int", arg6, "int", arg7, "HBITMAP", arg8, "int", arg9, "int", arg10, "DWORD", arg11, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ModifyWorldTransform
(HDC arg0, const XFORM* arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ModifyWorldTransform", "HDC", arg0, "const XFORM*", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
MoveToEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MoveToEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OffsetViewportOrgEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OffsetViewportOrgEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
OffsetWindowOrgEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OffsetWindowOrgEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PatBlt
(HDC arg0, int arg1, int arg2, int arg3, int arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PatBlt", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Pie
(HDC arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Pie", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "int", arg7, "int", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlayEnhMetaFile
(HDC arg0, HENHMETAFILE arg1, LPCRECT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlayEnhMetaFile", "HDC", arg0, "HENHMETAFILE", arg1, "LPCRECT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlayEnhMetaFileRecord
(HDC arg0, LPHANDLETABLE arg1, const ENHMETARECORD* arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlayEnhMetaFileRecord", "HDC", arg0, "LPHANDLETABLE", arg1, "const ENHMETARECORD*", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlayMetaFile
(HDC arg0, HMETAFILE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlayMetaFile", "HDC", arg0, "HMETAFILE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlayMetaFileRecord
(HDC arg0, LPHANDLETABLE arg1, LPMETARECORD arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlayMetaFileRecord", "HDC", arg0, "LPHANDLETABLE", arg1, "LPMETARECORD", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PlgBlt
(HDC arg0, const POINT* arg1, HDC arg2, int arg3, int arg4, int arg5, int arg6, HBITMAP arg7, int arg8, int arg9)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PlgBlt", "HDC", arg0, "const POINT*", arg1, "HDC", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, "HBITMAP", arg7, "int", arg8, "int", arg9, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyBezier
(HDC arg0, const POINT* arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyBezier", "HDC", arg0, "const POINT*", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyBezierTo
(HDC arg0, const POINT* arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyBezierTo", "HDC", arg0, "const POINT*", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyDraw
(HDC arg0, const POINT* arg1, const BYTE* arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyDraw", "HDC", arg0, "const POINT*", arg1, "const BYTE*", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyPolygon
(HDC arg0, const POINT* arg1, const INT* arg2, int arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyPolygon", "HDC", arg0, "const POINT*", arg1, "const INT*", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyPolyline
(HDC arg0, const POINT* arg1, const DWORD* arg2, DWORD arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyPolyline", "HDC", arg0, "const POINT*", arg1, "const DWORD*", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyTextOutA
(HDC arg0, const POLYTEXTA* arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyTextOutA", "HDC", arg0, "const POLYTEXTA*", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolyTextOutW
(HDC arg0, const POLYTEXTW* arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolyTextOutW", "HDC", arg0, "const POLYTEXTW*", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Polygon
(HDC arg0, const POINT* arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Polygon", "HDC", arg0, "const POINT*", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Polyline
(HDC arg0, const POINT* arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Polyline", "HDC", arg0, "const POINT*", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PolylineTo
(HDC arg0, const POINT* arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PolylineTo", "HDC", arg0, "const POINT*", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PtVisible
(HDC arg0, int arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PtVisible", "HDC", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RectVisible
(HDC arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RectVisible", "HDC", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Rectangle
(HDC arg0, int arg1, int arg2, int arg3, int arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Rectangle", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RoundRect
(HDC arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RoundRect", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "int", arg5, "int", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScaleViewportExtEx
(HDC arg0, int arg1, int arg2, int arg3, int arg4, LPSIZE arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ScaleViewportExtEx", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "LPSIZE", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ScaleWindowExtEx
(HDC arg0, int arg1, int arg2, int arg3, int arg4, LPSIZE arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ScaleWindowExtEx", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "LPSIZE", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SelectClipPath
(HDC arg0, int arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SelectClipPath", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetAbortProc
(HDC arg0, ABORTPROC arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetAbortProc", "HDC", arg0, "ABORTPROC", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetArcDirection
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetArcDirection", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
SetBitmapBits
(HBITMAP arg0, DWORD arg1, PCVOID arg2)
{
	LONG rc = (LONG)-1;
	WIN32API_ENTER("LONG", "SetBitmapBits", "HBITMAP", arg0, "DWORD", arg1, "PCVOID", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetBitmapDimensionEx
(HBITMAP arg0, int arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetBitmapDimensionEx", "HBITMAP", arg0, "int", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
SetBkColor
(HDC arg0, COLORREF arg1)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "SetBkColor", "HDC", arg0, "COLORREF", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetBkMode
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetBkMode", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetBoundsRect
(HDC arg0, LPCRECT arg1, UINT arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "SetBoundsRect", "HDC", arg0, "LPCRECT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetBrushOrgEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetBrushOrgEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetColorAdjustment
(HDC arg0, const COLORADJUSTMENT* arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetColorAdjustment", "HDC", arg0, "const COLORADJUSTMENT*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetColorSpace
(HDC arg0, HCOLORSPACE arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetColorSpace", "HDC", arg0, "HCOLORSPACE", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetDIBColorTable
(HDC arg0, UINT arg1, UINT arg2, const RGBQUAD* arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "SetDIBColorTable", "HDC", arg0, "UINT", arg1, "UINT", arg2, "const RGBQUAD*", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetDIBits
(HDC arg0, HBITMAP arg1, UINT arg2, UINT arg3, PCVOID arg4, const BITMAPINFO* arg5, UINT arg6)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetDIBits", "HDC", arg0, "HBITMAP", arg1, "UINT", arg2, "UINT", arg3, "PCVOID", arg4, "const BITMAPINFO*", arg5, "UINT", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetDeviceGammaRamp
(HDC arg0, PVOID arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetDeviceGammaRamp", "HDC", arg0, "PVOID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
SetEnhMetaFileBits
(UINT arg0, const BYTE* arg1)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "SetEnhMetaFileBits", "UINT", arg0, "const BYTE*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetGraphicsMode
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetGraphicsMode", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetICMMode
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetICMMode", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetICMProfileA
(HDC arg0, LPSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetICMProfileA", "HDC", arg0, "LPSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetICMProfileW
(HDC arg0, LPWSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetICMProfileW", "HDC", arg0, "LPWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetMapMode
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetMapMode", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SetMapperFlags
(HDC arg0, DWORD arg1)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SetMapperFlags", "HDC", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMETAFILE WINAPI
SetMetaFileBitsEx
(UINT arg0, const BYTE * arg1)
{
	HMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMETAFILE", "SetMetaFileBitsEx", "UINT", arg0, "const BYTE *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMiterLimit
(HDC arg0, FLOAT arg1, PFLOAT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMiterLimit", "HDC", arg0, "FLOAT", arg1, "PFLOAT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
SetPixel
(HDC arg0, int arg1, int arg2, COLORREF arg3)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "SetPixel", "HDC", arg0, "int", arg1, "int", arg2, "COLORREF", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetPixelFormat
(HDC arg0, int arg1, PIXELFORMATDESCRIPTOR* arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetPixelFormat", "HDC", arg0, "int", arg1, "PIXELFORMATDESCRIPTOR*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetPixelV
(HDC arg0, int arg1, int arg2, COLORREF arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetPixelV", "HDC", arg0, "int", arg1, "int", arg2, "COLORREF", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetPolyFillMode
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetPolyFillMode", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetROP2
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetROP2", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetStretchBltMode
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetStretchBltMode", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SetTextAlign
(HDC arg0, UINT arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "SetTextAlign", "HDC", arg0, "UINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetTextCharacterExtra
(HDC arg0, int arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetTextCharacterExtra", "HDC", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" COLORREF WINAPI
SetTextColor
(HDC arg0, COLORREF arg1)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "SetTextColor", "HDC", arg0, "COLORREF", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetTextJustification
(HDC arg0, int arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetTextJustification", "HDC", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetViewportExtEx
(HDC arg0, int arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetViewportExtEx", "HDC", arg0, "int", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetViewportOrgEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetViewportOrgEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HENHMETAFILE WINAPI
SetWinMetaFileBits
(UINT arg0, const BYTE* arg1, HDC arg2, const METAFILEPICT* arg3)
{
	HENHMETAFILE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HENHMETAFILE", "SetWinMetaFileBits", "UINT", arg0, "const BYTE*", arg1, "HDC", arg2, "const METAFILEPICT*", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowExtEx
(HDC arg0, int arg1, int arg2, LPSIZE arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWindowExtEx", "HDC", arg0, "int", arg1, "int", arg2, "LPSIZE", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWindowOrgEx
(HDC arg0, int arg1, int arg2, LPPOINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWindowOrgEx", "HDC", arg0, "int", arg1, "int", arg2, "LPPOINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetWorldTransform
(HDC arg0, const XFORM * arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetWorldTransform", "HDC", arg0, "const XFORM *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
StartDocA
(HDC arg0, const DOCINFO* arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "StartDocA", "HDC", arg0, "const DOCINFO*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
StartDocW
(HDC arg0, const DOCINFO* arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "StartDocW", "HDC", arg0, "const DOCINFO*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
StartPage
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "StartPage", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StretchBlt
(HDC arg0, int arg1, int arg2, int arg3, int arg4, HDC arg5, int arg6, int arg7, int arg8, int arg9, DWORD arg10)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StretchBlt", "HDC", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "HDC", arg5, "int", arg6, "int", arg7, "int", arg8, "int", arg9, "DWORD", arg10, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StrokeAndFillPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StrokeAndFillPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
StrokePath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "StrokePath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SwapBuffers
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SwapBuffers", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TextOutA
(HDC arg0, int arg1, int arg2, LPCSTR arg3, int arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TextOutA", "HDC", arg0, "int", arg1, "int", arg2, "LPCSTR", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TextOutW
(HDC arg0, int arg1, int arg2, LPCWSTR arg3, int arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TextOutW", "HDC", arg0, "int", arg1, "int", arg2, "LPCWSTR", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
TranslateCharsetInfo
(PDWORD arg0, LPCHARSETINFO arg1, DWORD arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TranslateCharsetInfo", "PDWORD", arg0, "LPCHARSETINFO", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UnrealizeObject
(HGDIOBJ arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UnrealizeObject", "HGDIOBJ", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UpdateICMRegKeyA
(DWORD arg0, DWORD arg1, LPSTR arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UpdateICMRegKeyA", "DWORD", arg0, "DWORD", arg1, "LPSTR", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UpdateICMRegKeyW
(DWORD arg0, DWORD arg1, LPWSTR arg2, UINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UpdateICMRegKeyW", "DWORD", arg0, "DWORD", arg1, "LPWSTR", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
WidenPath
(HDC arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WidenPath", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	GDI32_GetAddressByOrder
#	define	GetAddressByName	GDI32_GetAddressByName

#	include "GDI32/GetAddressByOrder.h"
#	include "GDI32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
