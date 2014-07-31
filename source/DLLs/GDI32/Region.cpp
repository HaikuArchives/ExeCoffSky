/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Region.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Region.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Region.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Region::Region
(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect):
magic(REGION_MAGIC),
nRect(0),
lpRect(NULL)
{
	Append(nLeftRect, nTopRect, nRightRect, nBottomRect);
}

Region::~Region
(void)
{
	MakeEmpty();
}

void
Region::MakeEmpty
(void)
{
	if (NULL != lpRect) {
		free(lpRect);
		lpRect = NULL;
	}
	nRect = 0;
}

bool
Region::SetTo
(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
{
	MakeEmpty();
	return Append(nLeftRect, nTopRect, nRightRect, nBottomRect);
}

bool
Region::Append
(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
{
	// XXX
	nRect++;
	void *newrect = NULL;
	if (NULL == lpRect) newrect = malloc(sizeof(RECT) * nRect);
	else newrect = realloc(lpRect, sizeof(RECT) * nRect);
	if (NULL == newrect) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		return false;
	}
	lpRect = (LPRECT)newrect;
	int o = nRect - 1;
	lpRect[o].left = nLeftRect;
	lpRect[o].top = nTopRect;
	lpRect[o].right = nRightRect;
	lpRect[o].bottom = nBottomRect;
	return true;
}

#if defined(_DEBUG)
void
Region::PrintToStream
(void)
{
	if (NULL == lpRect) return;
	for (int i = 0; i < nRect; i++) {
		WIN32API_INFO("%3d: (%d, %d) - (%d, %d)\n", i,
			lpRect[i].left, lpRect[i].top,
			lpRect[i].right, lpRect[i].bottom);
	}
}
#endif	// defined(_DEBUG)

Region *
Region::HandleToRegion
(HRGN hRgn)
{
	if (NULL == hRgn) return NULL;
	if ((HRGN)-1 == hRgn) return NULL;
	Region *rgn = (Region *)hRgn;
	if (rgn->magic != REGION_MAGIC) return NULL;
	return rgn;
}

extern "C" HRGN WINAPI
CreateRectRgn
(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
{
	HRGN rc = NULL;
	WIN32API_ENTER("HRGN", "CreateRectRgn", "int", nLeftRect, "int", nTopRect,
		"int", nRightRect, "int", nBottomRect, NULL);
	rc = (HRGN)new Region(nLeftRect, nTopRect, nRightRect, nBottomRect);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetRectRgn
(HRGN hRgn, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetRectRgn", "HRGN", hRgn, "int", nLeftRect, "int", nTopRect,
		"int", nRightRect, "int", nBottomRect, NULL);
	Region *rgn = Region::HandleToRegion(hRgn);
	if (NULL == rgn) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		if (rgn->SetTo(nLeftRect, nTopRect, nRightRect, nBottomRect)) {
			rc = TRUE;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
CombineRgn
(HRGN arg0, HRGN arg1, HRGN arg2, int arg3)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "CombineRgn", "HRGN", arg0, "HRGN", arg1, "HRGN", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	Region *r1 = Region::HandleToRegion(arg0);
	Region *r2 = Region::HandleToRegion(arg1);
	Region *r3 = Region::HandleToRegion(arg2);
#if defined(_DEBUG)
	if (NULL != r1) r1->PrintToStream();
	if (NULL != r2) r2->PrintToStream();
	if (NULL != r3) r3->PrintToStream();
#endif	// defined(_DEBUG)
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
CreateEllipticRgn
(int arg0, int arg1, int arg2, int arg3)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "CreateEllipticRgn", "int", arg0, "int", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
CreateEllipticRgnIndirect
(LPCRECT arg0)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "CreateEllipticRgnIndirect", "LPCRECT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
CreatePolyPolygonRgn
(const POINT* arg0, const INT* arg1, int arg2, int arg3)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "CreatePolyPolygonRgn", "const POINT*", arg0, "const INT*", arg1, "int", arg2, "int", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
CreatePolygonRgn
(const POINT* arg0, int arg1, int arg2)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "CreatePolygonRgn", "const POINT*", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
CreateRectRgnIndirect
(LPCRECT arg0)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "CreateRectRgnIndirect", "LPCRECT", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
CreateRoundRectRgn
(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "CreateRoundRectRgn", "int", arg0, "int", arg1, "int", arg2, "int", arg3, "int", arg4, "int", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EqualRgn
(HRGN arg0, HRGN arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EqualRgn", "HRGN", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
ExtSelectClipRgn
(HDC arg0, HRGN arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ExtSelectClipRgn", "HDC", arg0, "HRGN", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
FillRgn
(HDC arg0, HRGN arg1, HBRUSH arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FillRgn", "HDC", arg0, "HRGN", arg1, "HBRUSH", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FrameRgn
(HDC arg0, HRGN arg1, HBRUSH arg2, int arg3, int arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FrameRgn", "HDC", arg0, "HRGN", arg1, "HBRUSH", arg2, "int", arg3, "int", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetClipRgn
(HDC arg0, HRGN arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetClipRgn", "HDC", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetMetaRgn
(HDC arg0, HRGN arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetMetaRgn", "HDC", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetRgnBox
(HRGN arg0, LPRECT arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetRgnBox", "HRGN", arg0, "LPRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InvertRgn
(HDC arg0, HRGN arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InvertRgn", "HDC", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
OffsetClipRgn
(HDC arg0, int arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "OffsetClipRgn", "HDC", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
OffsetRgn
(HRGN arg0, int arg1, int arg2)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "OffsetRgn", "HRGN", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PaintRgn
(HDC arg0, HRGN arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PaintRgn", "HDC", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SelectClipRgn
(HDC arg0, HRGN arg1)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SelectClipRgn", "HDC", arg0, "HRGN", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SetMetaRgn
(HDC arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SetMetaRgn", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
ExtCreateRegion
(const XFORM* arg0, DWORD arg1, const RGNDATA* arg2)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "ExtCreateRegion", "const XFORM*", arg0, "DWORD", arg1, "const RGNDATA*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetRegionData
(HRGN arg0, DWORD arg1, LPRGNDATA arg2)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetRegionData", "HRGN", arg0, "DWORD", arg1, "LPRGNDATA", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRGN WINAPI
PathToRegion
(HDC arg0)
{
	HRGN rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HRGN", "PathToRegion", "HDC", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
PtInRegion
(HRGN arg0, int arg1, int arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "PtInRegion", "HRGN", arg0, "int", arg1, "int", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RectInRegion
(HRGN arg0, LPCRECT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RectInRegion", "HRGN", arg0, "LPCRECT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
