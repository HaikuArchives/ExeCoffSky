/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: GDI32.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [GDI32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__GDI32_h__)
#	define	__GDI32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

typedef struct tagBITMAPINFOHEADER {
	PACKED(DWORD biSize);
	PACKED(LONG biWidth);
	PACKED(LONG biHeight);
	PACKED(WORD biPlanes);
	PACKED(WORD biBitCount);
	PACKED(DWORD biCompression);
	PACKED(DWORD biSizeImage);
	PACKED(LONG biXPelsPerMeter);
	PACKED(LONG biYPelsPerMeter);
	PACKED(DWORD biClrUsed);
	PACKED(DWORD biClrImportant);
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER;
typedef CONST BITMAPINFOHEADER CBITMAPINFOHEADER, *LPCBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
	PACKED(BYTE rgbBlue);
	PACKED(BYTE rgbGreen);
	PACKED(BYTE rgbRed);
	PACKED(BYTE rgbReserved);
} RGBQUAD, *LPRGBQUAD;

typedef struct tagBITMAPINFO {
	PACKED(BITMAPINFOHEADER bmiHeader);
	PACKED(RGBQUAD bmiColors[1]);
} BITMAPINFO, *LPBITMAPINFO;

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Win32FontStructures_h__)
#		include "Win32FontStructures.h"
#	endif	// !defined(__Win32FontStructures_h__)

#	if !defined(__Palette_h__)
#		include "Palette.h"
#	endif	// !defined(__Palette_h__)

#	if !defined(__DeviceContext_h__)
#		include "DeviceContext.h"
#	endif	// !defined(__DeviceContext_h__)

#	if !defined(__Bitmap_h__)
#		include "Bitmap.h"
#	endif	// !defined(__Bitmap_h__)

#	if !defined(__DIBSection_h__)
#		include "DIBSection.h"
#	endif	// !defined(__DIBSection_h__)

#	if !defined(__StretchDIBits_h__)
#		include "StretchDIBits.h"
#	endif	// !defined(__StretchDIBits_h__)

#	if !defined(__Region_h__)
#		include "Region.h"
#	endif	// !defined(__Region_h__)

#	define	GDI_ERROR	0xffffffffL

#	define	GGO_METRICS	0
#	define	GGO_BITMAP	1
#	define	GGO_NATIVE	2
#	define	GGO_BEZIER	3

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

// Font
DWORD WINAPI GetGlyphOutlineA(HDC hDc, UINT uChar, UINT uFormat, LPGLYPHMETRICS lpgm, DWORD cbBuffer, LPVOID lpvBuffer, LPCMAT2 lpmat2);
DWORD WINAPI GetGlyphOutlineW(HDC hDc, UINT uChar, UINT uFormat, LPGLYPHMETRICS lpgm, DWORD cbBuffer, LPVOID lpvBuffer, LPCMAT2 lpmat2);
HFONT WINAPI CreateFontA(int nHeight, int nWidth, int nEscapement, int nOrientation, int fnWeight,
	DWORD fdwItalic, DWORD fdwUnderline, DWORD fdwStrikeOut, DWORD fdwCharSet,
	DWORD fdwOutputPrecision, DWORD fdwClipPrecision, DWORD fdwQuality, DWORD fdwPitchAndFamily, LPCTSTR lpszFace);
HFONT WINAPI CreateFontW(int nHeight, int nWidth, int nEscapement, int nOrientation, int fnWeight,
	DWORD fdwItalic, DWORD fdwUnderline, DWORD fdwStrikeOut, DWORD fcwCharSet,
	DWORD fdwOutputPrecision, DWORD fdwClipPrecision, DWORD fdwQuality, DWORD fdwPitchAndFamily, LPCWSTR lpszFace);
HFONT WINAPI CreateFontIndirectA(const LOGFONTA* lplf);
HFONT WINAPI CreateFontIndirectW(const LOGFONTW* lplf);
int WINAPI EnumFontFamiliesA(HDC hDc, LPCSTR lpszFamily, FONTENUMPROCA lpEnumFontFamProc, LPARAM lParam);
int WINAPI EnumFontFamiliesW(HDC hDc, LPCWSTR lpszFamily, FONTENUMPROCW lpEnumFontFamProc, LPARAM lParam);
int WINAPI EnumFontFamiliesExA(HDC hDc, LPLOGFONTA lplf, FONTENUMPROCA lpEnumFontFamProc, LPARAM lParam, DWORD dwFlags);
int WINAPI EnumFontFamiliesExW(HDC hDc, LPLOGFONTW lplf, FONTENUMPROCW lpEnumFontFamProc, LPARAM lParam, DWORD dwFlags);
int WINAPI EnumFontsA(HDC hDc, LPCSTR lpFaceName, FONTENUMPROCA lpFontFunc, LPARAM lParam);
int WINAPI EnumFontsW(HDC hDc, LPCWSTR lpFaceName, FONTENUMPROCA lpFontFunc, LPARAM lParam);
BOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden, LPCSTR lpszFontRes, LPCSTR lpszFontFile, LPCSTR lpszCurrentPath);
BOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden, LPCWSTR lpszFontRes, LPCWSTR lpszFontFile, LPCWSTR lpszCurrentPath);
int WINAPI AddFontResourceA(LPCSTR lpszFileName);
int WINAPI AddFontResourceW(LPCWSTR lpszFileName);
BOOL WINAPI RemoveFontResourceA(LPCSTR lpszFileName);
BOOL WINAPI RemoveFontResourceW(LPCWSTR lpszFileName);
DWORD WINAPI GetFontData(HDC hDc, DWORD dwTable, DWORD dwOffset, LPVOID lpvBuffer, DWORD cbData);
DWORD WINAPI GetFontLanguageInfo(HDC hDc);

HGDIOBJ WINAPI GetStockObject(int fnObject);
BOOL WINAPI UpdateColors(HDC hdc);
int WINAPI SetDIBitsToDevice(HDC hdc, int Xdest, int Ydest, DWORD dwWidth, DWORD dwHeight, int XSrc, int YSrc, UINT uStartScan, UINT cScanLines, CONST VOID *lpvBits, CONST BITMAPINFO *lpbmi, UINT fuColorUse);
int WINAPI AbortDoc(HDC);
BOOL WINAPI AbortPath(HDC);
BOOL WINAPI AngleArc(HDC,int,int,DWORD,FLOAT,FLOAT);
BOOL WINAPI Arc(HDC,int,int,int,int,int,int,int,int);
BOOL WINAPI ArcTo(HDC,int,int,int,int,int,int,int,int);
BOOL WINAPI BeginPath(HDC);
BOOL WINAPI CheckColorsInGamut(HDC,PVOID,PVOID,DWORD);
int WINAPI ChoosePixelFormat(HDC,CONST PIXELFORMATDESCRIPTOR*);
BOOL WINAPI Chord(HDC,int,int,int,int,int,int,int,int);
HENHMETAFILE WINAPI CloseEnhMetaFile(HDC);
BOOL WINAPI CloseFigure(HDC);
HMETAFILE WINAPI CloseMetaFile(HDC);
BOOL WINAPI ColorMatchToTarget(HDC,HDC,DWORD);
BOOL WINAPI CombineTransform(LPXFORM,const XFORM*,const XFORM*);
HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE,LPCSTR);
HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE,LPCWSTR);
HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
HBRUSH WINAPI CreateBrushIndirect(const LOGBRUSH*);
HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA);
HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW);
HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL,UINT);
HBRUSH WINAPI CreateDIBPatternBrushPt(PCVOID,UINT);
HBITMAP WINAPI CreateDiscardableBitmap(HDC,int,int);
HDC WINAPI CreateEnhMetaFileA(HDC,LPCSTR,LPCRECT,LPCSTR);
HDC WINAPI CreateEnhMetaFileW(HDC,LPCWSTR,LPCRECT,LPCWSTR);
HBRUSH WINAPI CreateHatchBrush(int,COLORREF);
HDC WINAPI CreateMetaFileA(LPCSTR);
HDC WINAPI CreateMetaFileW(LPCWSTR);
HBRUSH WINAPI CreatePatternBrush(HBITMAP);
HPEN WINAPI CreatePen(int,int,COLORREF);
HPEN WINAPI CreatePenIndirect(const LOGPEN*);
HBRUSH WINAPI CreateSolidBrush(COLORREF);
BOOL WINAPI DPtoLP(HDC,LPPOINT,int);
BOOL WINAPI DeleteColorSpace(HCOLORSPACE);
BOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE);
BOOL WINAPI DeleteMetaFile(HMETAFILE);
BOOL WINAPI DeleteObject(HGDIOBJ);
int WINAPI DescribePixelFormat(HDC,int,UINT,LPPIXELFORMATDESCRIPTOR);
int WINAPI DrawEscape(HDC,int,int,LPCSTR);
BOOL WINAPI Ellipse(HDC,int,int,int,int);
int WINAPI EndDoc(HDC);
int WINAPI EndPage(HDC);
BOOL WINAPI EndPath(HDC);
BOOL WINAPI EnumEnhMetaFile(HDC,HENHMETAFILE,ENHMFENUMPROC,PVOID,LPCRECT);
int WINAPI EnumICMProfilesA(HDC,ICMENUMPROCA,LPARAM);
int WINAPI EnumICMProfilesW(HDC,ICMENUMPROCW,LPARAM);
BOOL WINAPI EnumMetaFile(HDC,HMETAFILE,MFENUMPROC,LPARAM);
int WINAPI EnumObjects(HDC,int,GOBJENUMPROC,LPARAM);
int WINAPI Escape(HDC,int,int,LPCSTR,PVOID);
int WINAPI ExcludeClipRect(HDC,int,int,int,int);
HPEN WINAPI ExtCreatePen(DWORD,DWORD,const LOGBRUSH*,DWORD,const DWORD*);
int WINAPI ExtEscape(HDC,int,int,LPCSTR,int,LPSTR);
BOOL WINAPI ExtFloodFill(HDC,int,int,COLORREF,UINT);
BOOL WINAPI ExtTextOutA(HDC,int,int,UINT,LPCRECT,LPCSTR,UINT,const INT*);
BOOL WINAPI ExtTextOutW(HDC,int,int,UINT,LPCRECT,LPCWSTR,UINT,const INT*);
BOOL WINAPI FillPath(HDC);
BOOL WINAPI FixBrushOrgEx(HDC,int,int,LPPOINT);
BOOL WINAPI FlattenPath(HDC);
BOOL WINAPI FloodFill(HDC,int,int,COLORREF);
BOOL WINAPI GdiComment(HDC,UINT,const BYTE*);
BOOL WINAPI GdiFlush(void);
DWORD WINAPI GdiGetBatchLimit(void);
DWORD WINAPI GdiSetBatchLimit(DWORD);
int WINAPI GetArcDirection(HDC);
BOOL WINAPI GetAspectRatioFilterEx(HDC,LPSIZE);
LONG WINAPI GetBitmapBits(HBITMAP,LONG,PVOID);
BOOL WINAPI GetBitmapDimensionEx(HBITMAP,LPSIZE);
COLORREF WINAPI GetBkColor(HDC);
int WINAPI GetBkMode(HDC);
UINT WINAPI GetBoundsRect(HDC,LPRECT,UINT);
BOOL WINAPI GetBrushOrgEx(HDC,LPPOINT);
BOOL WINAPI GetCharABCWidthsA(HDC,UINT,UINT,LPABC);
BOOL WINAPI GetCharABCWidthsFloatA(HDC,UINT,UINT,LPABCFLOAT);
BOOL WINAPI GetCharABCWidthsFloatW(HDC,UINT,UINT,LPABCFLOAT);
BOOL WINAPI GetCharABCWidthsW(HDC,UINT,UINT,LPABC);
BOOL WINAPI GetCharWidth32A(HDC,UINT,UINT,LPINT);
BOOL WINAPI GetCharWidth32W(HDC,UINT,UINT,LPINT);
BOOL WINAPI GetCharWidthA(HDC,UINT,UINT,LPINT);
BOOL WINAPI GetCharWidthFloatA(HDC,UINT,UINT,PFLOAT);
BOOL WINAPI GetCharWidthFloatW(HDC,UINT,UINT,PFLOAT);
BOOL WINAPI GetCharWidthW(HDC,UINT,UINT,LPINT);
DWORD WINAPI GetCharacterPlacementA(HDC,LPCSTR,int,int,LPGCP_RESULTSA,DWORD);
DWORD WINAPI GetCharacterPlacementW(HDC,LPCWSTR,int,int,LPGCP_RESULTSW,DWORD);
int WINAPI GetClipBox(HDC,LPRECT);
BOOL WINAPI GetColorAdjustment(HDC,LPCOLORADJUSTMENT);
HANDLE WINAPI GetColorSpace(HDC);
HGDIOBJ WINAPI GetCurrentObject(HDC,UINT);
BOOL WINAPI GetCurrentPositionEx(HDC,LPPOINT);
BOOL WINAPI GetDCOrgEx(HDC,LPPOINT);
UINT WINAPI GetDIBColorTable(HDC,UINT,UINT,RGBQUAD*);
int WINAPI GetDIBits(HDC,HBITMAP,UINT,UINT,PVOID,LPBITMAPINFO,UINT);
int WINAPI GetDeviceCaps(HDC,int);
BOOL WINAPI GetDeviceGammaRamp(HDC,PVOID);
HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR);
UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE,UINT,LPSTR);
UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE,UINT,LPWSTR);
UINT WINAPI GetEnhMetaFileHeader(HENHMETAFILE,UINT,LPENHMETAHEADER);
UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE,UINT,LPPALETTEENTRY);
UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE,DWORD,PIXELFORMATDESCRIPTOR*);
HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR);
int WINAPI GetGraphicsMode(HDC);
BOOL WINAPI GetICMProfileA(HDC,DWORD,LPSTR);
BOOL WINAPI GetICMProfileW(HDC,DWORD,LPWSTR);
DWORD WINAPI GetKerningPairsA(HDC,DWORD,LPKERNINGPAIR);
DWORD WINAPI GetKerningPairsW(HDC,DWORD,LPKERNINGPAIR);
BOOL WINAPI GetLogColorSpaceA(HCOLORSPACE,LPLOGCOLORSPACEA,DWORD);
BOOL WINAPI GetLogColorSpaceW(HCOLORSPACE,LPLOGCOLORSPACEW,DWORD);
int WINAPI GetMapMode(HDC);
HMETAFILE WINAPI GetMetaFileA(LPCSTR);
UINT WINAPI GetMetaFileBitsEx(HMETAFILE,UINT,PVOID);
HMETAFILE WINAPI GetMetaFileW(LPCWSTR);
BOOL WINAPI GetMiterLimit(HDC,PFLOAT);
COLORREF WINAPI GetNearestColor(HDC,COLORREF);
int WINAPI GetObjectA(HGDIOBJ,int,PVOID);
DWORD WINAPI GetObjectType(HGDIOBJ);
int WINAPI GetObjectW(HGDIOBJ,int,PVOID);
UINT WINAPI GetOutlineTextMetricsA(HDC,UINT,LPOUTLINETEXTMETRICA);
UINT WINAPI GetOutlineTextMetricsW(HDC,UINT,LPOUTLINETEXTMETRICW);
int WINAPI GetPath(HDC,LPPOINT,PBYTE,int);
COLORREF WINAPI GetPixel(HDC,int,int);
int WINAPI GetPixelFormat(HDC);
int WINAPI GetPolyFillMode(HDC);
int WINAPI GetROP2(HDC);
BOOL WINAPI GetRasterizerCaps(LPRASTERIZER_STATUS,UINT);
HGDIOBJ WINAPI GetStockObject(int);
int WINAPI GetStretchBltMode(HDC);
UINT WINAPI GetTextAlign(HDC);
int WINAPI GetTextCharacterExtra(HDC);
int WINAPI GetTextCharset(HDC);
int WINAPI GetTextCharsetInfo(HDC,LPFONTSIGNATURE,DWORD);
COLORREF WINAPI GetTextColor(HDC);
BOOL WINAPI GetTextExtentExPointA(HDC,LPCSTR,int,int,LPINT,LPINT,LPSIZE);
BOOL WINAPI GetTextExtentExPointW( HDC,LPCWSTR,int,int,LPINT,LPINT,LPSIZE );
BOOL WINAPI GetTextExtentPoint32A(HDC,LPCSTR,int,LPSIZE);
BOOL WINAPI GetTextExtentPoint32W( HDC,LPCWSTR,int,LPSIZE);
BOOL WINAPI GetTextExtentPointA(HDC,LPCSTR,int,LPSIZE);
BOOL WINAPI GetTextExtentPointW(HDC,LPCWSTR,int,LPSIZE);
int WINAPI GetTextFaceA(HDC,int,LPSTR);
int WINAPI GetTextFaceW(HDC,int,LPWSTR);
BOOL WINAPI GetTextMetricsA(HDC,LPTEXTMETRICA);
BOOL WINAPI GetTextMetricsW(HDC,LPTEXTMETRICW);
BOOL WINAPI GetViewportExtEx(HDC,LPSIZE);
BOOL WINAPI GetViewportOrgEx(HDC,LPPOINT);
UINT WINAPI GetWinMetaFileBits(HENHMETAFILE,UINT,LPBYTE,INT,HDC);
BOOL WINAPI GetWindowExtEx(HDC,LPSIZE);
BOOL WINAPI GetWindowOrgEx(HDC,LPPOINT);
BOOL WINAPI GetWorldTransform(HDC,LPXFORM);
int WINAPI IntersectClipRect(HDC,int,int,int,int);
BOOL WINAPI LPtoDP(HDC,LPPOINT,int);
BOOL WINAPI LineDDA(int,int,int,int,LINEDDAPROC,LPARAM);
BOOL WINAPI LineTo(HDC,int,int);
BOOL WINAPI MaskBlt(HDC,int,int,int,int,HDC,int,int,HBITMAP,int,int,DWORD);
BOOL WINAPI ModifyWorldTransform(HDC,const XFORM*,DWORD);
BOOL WINAPI MoveToEx(HDC,int,int,LPPOINT);
BOOL WINAPI OffsetViewportOrgEx(HDC,int,int,LPPOINT);
BOOL WINAPI OffsetWindowOrgEx(HDC,int,int,LPPOINT);
BOOL WINAPI PatBlt(HDC,int,int,int,int,DWORD);
BOOL WINAPI Pie(HDC,int,int,int,int,int,int,int,int);
BOOL WINAPI PlayEnhMetaFile(HDC,HENHMETAFILE,LPCRECT);
BOOL WINAPI PlayEnhMetaFileRecord(HDC,LPHANDLETABLE,const ENHMETARECORD*,UINT);
BOOL WINAPI PlayMetaFile(HDC,HMETAFILE);
BOOL WINAPI PlayMetaFileRecord(HDC,LPHANDLETABLE,LPMETARECORD,UINT);
BOOL WINAPI PlgBlt(HDC,const POINT*,HDC,int,int,int,int,HBITMAP,int,int);
BOOL WINAPI PolyBezier(HDC,const POINT*,DWORD);
BOOL WINAPI PolyBezierTo(HDC,const POINT*,DWORD);
BOOL WINAPI PolyDraw(HDC,const POINT*,const BYTE*,int);
BOOL WINAPI PolyPolygon(HDC,const POINT*,const INT*,int);
BOOL WINAPI PolyPolyline(HDC,const POINT*,const DWORD*,DWORD);
BOOL WINAPI PolyTextOutA(HDC,const POLYTEXTA*,int);
BOOL WINAPI PolyTextOutW(HDC,const POLYTEXTW*,int);
BOOL WINAPI Polygon(HDC,const POINT*,int);
BOOL WINAPI Polyline(HDC,const POINT*,int);
BOOL WINAPI PolylineTo(HDC,const POINT*,DWORD);
BOOL WINAPI PtVisible(HDC,int,int);
BOOL WINAPI RectVisible(HDC,LPCRECT);
BOOL WINAPI Rectangle(HDC,int,int,int,int);
BOOL WINAPI RoundRect(HDC,int,int,int,int,int,int);
BOOL WINAPI ScaleViewportExtEx(HDC,int,int,int,int,LPSIZE);
BOOL WINAPI ScaleWindowExtEx(HDC,int,int,int,int,LPSIZE);
BOOL WINAPI SelectClipPath(HDC,int);
HGDIOBJ WINAPI SelectObject(HDC,HGDIOBJ);
HPALETTE WINAPI SelectPalette(HDC,HPALETTE,BOOL);
int WINAPI SetAbortProc(HDC,ABORTPROC);
int WINAPI SetArcDirection(HDC,int);
LONG WINAPI SetBitmapBits(HBITMAP,DWORD,PCVOID);
BOOL WINAPI SetBitmapDimensionEx(HBITMAP,int,int,LPSIZE);
COLORREF WINAPI SetBkColor(HDC,COLORREF);
int WINAPI SetBkMode(HDC,int);
UINT WINAPI SetBoundsRect(HDC,LPCRECT,UINT);
BOOL WINAPI SetBrushOrgEx(HDC,int,int,LPPOINT);
BOOL WINAPI SetColorAdjustment(HDC,const COLORADJUSTMENT*);
BOOL WINAPI SetColorSpace(HDC,HCOLORSPACE);
UINT WINAPI SetDIBColorTable(HDC,UINT,UINT,const RGBQUAD*);
int WINAPI SetDIBits(HDC,HBITMAP,UINT,UINT,PCVOID,const BITMAPINFO*,UINT);
int WINAPI SetDIBitsToDevice(HDC,int,int,DWORD,DWORD,int,int,UINT,UINT,PCVOID,const BITMAPINFO*,UINT);
BOOL WINAPI SetDeviceGammaRamp(HDC,PVOID);
HENHMETAFILE WINAPI SetEnhMetaFileBits(UINT,const BYTE*);
int WINAPI SetGraphicsMode(HDC,int);
int WINAPI SetICMMode(HDC,int);
BOOL WINAPI SetICMProfileA(HDC,LPSTR);
BOOL WINAPI SetICMProfileW(HDC,LPWSTR);
int WINAPI SetMapMode(HDC,int);
DWORD WINAPI SetMapperFlags(HDC,DWORD);
HMETAFILE WINAPI SetMetaFileBitsEx(UINT,const BYTE *);
BOOL WINAPI SetMiterLimit(HDC,FLOAT,PFLOAT);
COLORREF WINAPI SetPixel(HDC,int,int,COLORREF);
BOOL WINAPI SetPixelFormat(HDC,int,PIXELFORMATDESCRIPTOR*);
BOOL WINAPI SetPixelV(HDC,int,int,COLORREF);
int WINAPI SetPolyFillMode(HDC,int);
int WINAPI SetROP2(HDC,int);
int WINAPI SetStretchBltMode(HDC,int);
UINT WINAPI SetTextAlign(HDC,UINT);
int WINAPI SetTextCharacterExtra(HDC,int);
COLORREF WINAPI SetTextColor(HDC,COLORREF);
BOOL WINAPI SetTextJustification(HDC,int,int);
BOOL WINAPI SetViewportExtEx(HDC,int,int,LPSIZE);
BOOL WINAPI SetViewportOrgEx(HDC,int,int,LPPOINT);
HENHMETAFILE WINAPI SetWinMetaFileBits(UINT,const BYTE*,HDC,const METAFILEPICT*);
BOOL WINAPI SetWindowExtEx(HDC,int,int,LPSIZE);
BOOL WINAPI SetWindowOrgEx(HDC,int,int,LPPOINT);
BOOL WINAPI SetWorldTransform(HDC,const XFORM *);
int WINAPI StartDocA(HDC,const DOCINFO*);
int WINAPI StartDocW(HDC,const DOCINFO*);
int WINAPI StartPage(HDC);
BOOL WINAPI StretchBlt(HDC,int,int,int,int,HDC,int,int,int,int,DWORD);
BOOL WINAPI StrokeAndFillPath(HDC);
BOOL WINAPI StrokePath(HDC);
BOOL WINAPI SwapBuffers(HDC);
BOOL WINAPI TextOutA(HDC,int,int,LPCSTR,int);
BOOL WINAPI TextOutW(HDC,int,int,LPCWSTR,int);
BOOL WINAPI TranslateCharsetInfo(PDWORD,LPCHARSETINFO,DWORD);
BOOL WINAPI UnrealizeObject(HGDIOBJ);
BOOL WINAPI UpdateColors(HDC);
BOOL WINAPI UpdateICMRegKeyA(DWORD,DWORD,LPSTR,UINT);
BOOL WINAPI UpdateICMRegKeyW(DWORD,DWORD,LPWSTR,UINT);
BOOL WINAPI WidenPath(HDC);

#	if defined(_BUILTIN_DLL)
void *GDI32_GetAddressByOrder(int order);
void *GDI32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__GDI32_h__)
