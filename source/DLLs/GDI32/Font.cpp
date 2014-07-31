/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Font.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Font.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Font.h"
#include "GDI32.h"
#include "Win32Trace.h"

extern "C" DWORD WINAPI
GetGlyphOutlineA
(HDC hDc, UINT uChar, UINT uFormat, LPGLYPHMETRICS lpgm, DWORD cbBuffer, LPVOID lpvBuffer, LPCMAT2 lpmat2)
{
	DWORD rc = GDI_ERROR;
	WIN32API_ENTER("DWORD", "GetGlyphOutlineA", "HDC", hDc, "UINT", uChar, "UINT", uFormat, "LPGLYPHMETRICS", lpgm, "DWORD", cbBuffer, "LPVOID", lpvBuffer, "LPCMAT2", lpmat2, NULL);
	WIN32API_INFO("\thDc = %p\n", hDc);
	if (uChar < 0x100) {
		WIN32API_INFO("\tuChar = %c\n", uChar);
	} else {
		WIN32API_INFO("\tuChar = %c%c\n", uChar >> 8, uChar);
	}
#if defined(_DEBUG)
	static char *format[] = {
		"GGO_METRICS", "GGO_BITMAP", "GGO_NATIVE", "GGO_BEZIER",
	};
	WIN32API_INFO("\tuFormat = %s\n", (uFormat < 4)? format[uFormat]: "unknown");
#endif	// defined(_DEBUG)
	WIN32API_INFO("\tcbBuffer = %08x\n", cbBuffer);
	WIN32API_INFO("\tlpvBuffer = %p\n", lpvBuffer);
	if (NULL != lpmat2) {
		WIN32API_INFO("\teM11 = %d x 10^%d\n", lpmat2->eM11.value, lpmat2->eM11.fract);
		WIN32API_INFO("\teM12 = %d x 10^%d\n", lpmat2->eM12.value, lpmat2->eM12.fract);
		WIN32API_INFO("\teM21 = %d x 10^%d\n", lpmat2->eM21.value, lpmat2->eM21.fract);
		WIN32API_INFO("\teM22 = %d x 10^%d\n", lpmat2->eM22.value, lpmat2->eM22.fract);
	}
	if ((lpmat2->eM11.value != 1) || (lpmat2->eM11.fract != 0) ||
		(lpmat2->eM12.value != 0) || (lpmat2->eM12.fract != 0) ||
		(lpmat2->eM21.value != 0) || (lpmat2->eM21.fract != 0) ||
		(lpmat2->eM22.value != 1) || (lpmat2->eM22.fract != 0)) {
		WIN32API_INFO("\tignore matrics\n");
	}
	// convert sjis to utf-8
	char sjis[3];
	int32 sjislen = 0;
	if (uChar < 0x100) {
		sjis[0] = uChar & 0xff;
		sjis[1] = 0;
		sjislen = 1;
	} else {
		sjis[0] = (uChar >> 8) & 0xff;
		sjis[1] = uChar & 0xff;
		sjis[2] = 0;
		sjislen = 2;
	}
	char utf8[6];
	int32 utf8len = 6;
	int32 state = 0;
	convert_to_utf8(B_SJIS_CONVERSION, sjis, &sjislen, utf8, &utf8len, &state);
	utf8[utf8len] = 0;

	// draw font
	BFont font(be_plain_font);
	font.SetSize(23);
	float escapement;
	edge_info edge;
	font_height height;
	float size = font.Size();
	font.GetEscapements(utf8, 1, &escapement);
	font.GetEdges(utf8, 1, &edge);
	font.GetHeight(&height);
	int fontheight = (int)ceil(height.ascent + height.descent + 0.5);
	int box_x = (int)ceil((escapement - edge.left - edge.right) * size + 0.5);
	int cell_x = (int)ceil(escapement * size + 0.5);
	int fontwidth = (box_x < cell_x)? cell_x: box_x;
	if (NULL != lpgm) {
		lpgm->gmBlackBoxX = box_x;
		lpgm->gmBlackBoxY = fontheight;
		lpgm->gmptGlyphOrigin.x = (int)ceil(edge.left * size + 0.5);
		lpgm->gmptGlyphOrigin.y = (int)ceil(height.ascent + 0.5) - 3;	/* -3 ? */
		lpgm->gmCellIncX = cell_x;
		lpgm->gmCellIncY = 0;
		WIN32API_INFO("\t> BlackBox (%d,%d)\n", lpgm->gmBlackBoxX, lpgm->gmBlackBoxY);
		WIN32API_INFO("\t> GlyphOrigin (%d,%d)\n", lpgm->gmptGlyphOrigin.x, lpgm->gmptGlyphOrigin.y);
		WIN32API_INFO("\t> CellInx (%d,%d)\n", lpgm->gmCellIncX, lpgm->gmCellIncY);
	}
	WIN32API_INFO("\tsize: %f\n", size);
	WIN32API_INFO("\tescapement: %f\n", escapement);
	WIN32API_INFO("\tedge: %f/%f\n", edge.left, edge.right);
	WIN32API_INFO("\theight: %f/%f/%f\n", height.ascent, height.descent, height.leading);
	WIN32API_INFO("\trequired buffer size: %d x %d = %d\n", fontwidth, fontheight, fontwidth * fontheight);
	if (0 == cbBuffer) {
		rc = (((fontwidth + 31) / 32) * 4) * fontheight;
		WIN32API_INFO("\trequest %d bytes\n", rc);
	} else {
		BRect rect(0, 0, fontwidth - 1, fontheight - 1);
		BBitmap bmp(rect, B_GRAY8, true);
		BView view(rect, "font drawer", B_FOLLOW_ALL_SIDES, B_WILL_DRAW);
		view.SetFont(&font);
		bmp.AddChild(&view);
		bmp.Lock();
		view.DrawString(utf8, BPoint(-edge.left * size, height.ascent));
		bmp.Unlock();
		bmp.RemoveChild(&view);
		unsigned char *bits = (unsigned char *)bmp.Bits();
		int bpr = bmp.BytesPerRow();
		unsigned char *q = (unsigned char *)lpvBuffer;
		memset(q, 0, cbBuffer);
		int qw = ((fontwidth + 31) / 32) * 4;
		for (int y = fontheight - 1; y >= 0; y--) {
			int y_bpr = y * bpr;
			int y_qw = y * qw;
			for (int x = fontwidth - 1; x >= 0; x--) {
				if ((bits[y_bpr + x]) < 0x10) {
					q[y_qw + x / 8] |= (1 << (7 - x % 8));
				}
			}
		}
		rc = cbBuffer;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetGlyphOutlineW
(HDC arg0, UINT arg1, UINT arg2, LPGLYPHMETRICS arg3, DWORD arg4, PVOID arg5, const MAT2* arg6)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetGlyphOutlineW", "HDC", arg0, "UINT", arg1, "UINT", arg2, "LPGLYPHMETRICS", arg3, "DWORD", arg4, "PVOID", arg5, "const MAT2*", arg6, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFONT WINAPI
CreateFontA
(int nHeight, int nWidth, int nEscapement, int nOrientation, int fnWeight,
	DWORD fdwItalic, DWORD fdwUnderline, DWORD fdwStrikeOut, DWORD fdwCharSet,
	DWORD fdwOutputPrecision, DWORD fdwClipPrecision, DWORD fdwQuality, DWORD fdwPitchAndFamily, LPCTSTR lpszFace)
{
	HFONT rc = NULL;
	WIN32API_POINTER(lpszFace);
	WIN32API_ENTER("HFONT", "CreateFontA", "int", nHeight, "int", nWidth, "int", nEscapement, "int", nOrientation, "int", fnWeight, "DWORD", fdwItalic, "DWORD", fdwUnderline, "DWORD", fdwStrikeOut, "DWORD", fdwCharSet, "DWORD", fdwOutputPrecision, "DWORD", fdwClipPrecision, "DWORD", fdwQuality, "DWORD", fdwPitchAndFamily, "LPCTSTR", lpszFace, NULL);
	WIN32API_INFO("\tnHeight = %d\n", nHeight);
	WIN32API_INFO("\tlpszFace = %s\n", lpszFace);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFONT WINAPI
CreateFontW
(int arg0, int arg1, int arg2, int arg3, int arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8, DWORD arg9, DWORD arg10, DWORD arg11, DWORD arg12, LPCWSTR arg13)
{
	HFONT rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HFONT", "CreateFontW", "int", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "DWORD", arg5, "DWORD", arg6, "DWORD", arg7, "DWORD", arg8, "DWORD", arg9, "DWORD", arg10, "DWORD", arg11, "DWORD", arg12, "LPCWSTR", arg13, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFONT WINAPI
CreateFontIndirectA
(const LOGFONTA* arg0)
{
	HFONT rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HFONT", "CreateFontIndirectA", "const LOGFONTA*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HFONT WINAPI
CreateFontIndirectW
(const LOGFONTW* arg0)
{
	HFONT rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HFONT", "CreateFontIndirectW", "const LOGFONTW*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#include "interface/Font.h"

extern "C" int WINAPI
EnumFontFamiliesA
(HDC hDc, LPCSTR lpszFamily, FONTENUMPROCA lpEnumFontFamProc, LPARAM lParam)
{
	int rc = 0;
	WIN32API_POINTER(lpszFamily);
	WIN32API_POINTER(lpEnumFontFamProc);
	WIN32API_ENTER("int", "EnumFontFamiliesA", "HDC", hDc, "LPCTSTR", lpszFamily, "FONTENUMPROC", lpEnumFontFamProc, "LPARAM", lParam, NULL);
	WIN32API_INFO("\tlpszFamily = %s\n", lpszFamily);
	WIN32API_INFO("\tnot completed function\n");
	int32 n = count_font_families();
	if (NULL != lpEnumFontFamProc) for (int32 i = 0; i < n; i++) {
		font_family family;
		uint32 flags;
		int type = TRUETYPE_FONTTYPE;
		if (B_OK != get_font_family(i, &family, &flags)) continue;
		if ((NULL != lpszFamily) && (0 != strcmp(lpszFamily, family))) continue;
		ENUMLOGFONTA elf;
		NEWTEXTMETRICA ntm;
		memset(&elf, 0, sizeof(ENUMLOGFONTA));
		memset(&ntm, 0, sizeof(NEWTEXTMETRICA));
		// TODO: UTF8 to A
		snprintf(elf.elfFullName, LF_FULLFACESIZE, "%s", family);
		elf.elfLogFont.lfCharSet = 128;	// TODO: ShiftJIS
		int32 nStyles = count_font_styles(family);
		for (int32 j = 0; j < nStyles; j++) {
			font_style style;
			uint32 sflags;
			if (B_OK != get_font_style(family, j, &style, &sflags)) continue;
			snprintf(elf.elfStyle, LF_FACESIZE, "%s", style);
			WIN32API_INFO("\t+++ CALLBACK +++\n");
			WIN32API_INFO("\t\telfFullName: %s\n", family);
			WIN32API_INFO("\t\telfStyle: %s\n", style);
			rc = lpEnumFontFamProc(&elf, &ntm, type, lParam);
			WIN32API_INFO("\t\t <= %d\n", rc);
			WIN32API_INFO("\t--- CALLBACK ---\n");
			if (0 == rc) goto out;
		}
	}
out:
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumFontFamiliesW
(HDC arg0, LPCWSTR arg1, FONTENUMPROCW arg2, LPARAM arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumFontFamiliesW", "HDC", arg0, "LPCWSTR", arg1, "FONTENUMPROCW", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumFontFamiliesExA
(HDC arg0, PLOGFONTA arg1, FONTENUMPROCA arg2, LPARAM arg3, DWORD arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumFontFamiliesExA", "HDC", arg0, "PLOGFONTA", arg1, "FONTENUMPROCA", arg2, "LPARAM", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumFontFamiliesExW
(HDC arg0, PLOGFONTW arg1, FONTENUMPROCW arg2, LPARAM arg3, DWORD arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumFontFamiliesExW", "HDC", arg0, "PLOGFONTW", arg1, "FONTENUMPROCW", arg2, "LPARAM", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumFontsA
(HDC arg0, LPCSTR arg1, FONTENUMPROCA arg2, LPARAM arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumFontsA", "HDC", arg0, "LPCSTR", arg1, "FONTENUMPROCA", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
EnumFontsW
(HDC arg0, LPCWSTR arg1, FONTENUMPROCA arg2, LPARAM arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "EnumFontsW", "HDC", arg0, "LPCWSTR", arg1, "FONTENUMPROCA", arg2, "LPARAM", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateScalableFontResourceA
(DWORD arg0, LPCSTR arg1, LPCSTR arg2, LPCSTR arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateScalableFontResourceA", "DWORD", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CreateScalableFontResourceW
(DWORD arg0, LPCWSTR arg1, LPCWSTR arg2, LPCWSTR arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CreateScalableFontResourceW", "DWORD", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
AddFontResourceA
(LPCSTR arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "AddFontResourceA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
AddFontResourceW
(LPCWSTR arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "AddFontResourceW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RemoveFontResourceA
(LPCSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RemoveFontResourceA", "LPCSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RemoveFontResourceW
(LPCWSTR arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RemoveFontResourceW", "LPCWSTR", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFontData
(HDC arg0, DWORD arg1, DWORD arg2, PVOID arg3, DWORD arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetFontData", "HDC", arg0, "DWORD", arg1, "DWORD", arg2, "PVOID", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetFontLanguageInfo
(HDC arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetFontLanguageInfo", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

