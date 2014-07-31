/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Region.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Region.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Region_h__)
#	define	__Region_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Object_h__)
#		include "Object.h"
#	endif	// !defined(__Object_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	define	REGION_MAGIC	'_RGN'

class Region: public Object {
public:
	DWORD magic;
private:
	int nRect;
	LPRECT lpRect;
public:
	Region(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
	~Region(void);

	void MakeEmpty(void);
	bool SetTo(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
	bool Append(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);

#	if defined(_DEBUG)
	void PrintToStream(void);
#	endif	// defined(_DEBUG)

	static Region *HandleToRegion(HRGN hRgn);
};

#	if !defined(__Region__)
#		define	__Region__
#	endif	// !defined(__Region__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HRGN WINAPI CreateRectRgn(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);

BOOL WINAPI SetRectRgn(HRGN hRgn, int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);

int WINAPI CombineRgn(HRGN,HRGN,HRGN,int);
HRGN WINAPI CreateEllipticRgn(int,int,int,int);
HRGN WINAPI CreateEllipticRgnIndirect(LPCRECT);
HRGN WINAPI CreatePolyPolygonRgn(const POINT*,const INT*,int,int);
HRGN WINAPI CreatePolygonRgn(const POINT*,int,int);
HRGN WINAPI CreateRectRgnIndirect(LPCRECT);
HRGN WINAPI CreateRoundRectRgn(int,int,int,int,int,int);
BOOL WINAPI EqualRgn(HRGN,HRGN);
int WINAPI ExtSelectClipRgn(HDC,HRGN,int);
int WINAPI FillRgn(HDC,HRGN,HBRUSH);
BOOL WINAPI FrameRgn(HDC,HRGN,HBRUSH,int,int);
int WINAPI GetClipRgn(HDC,HRGN);
int WINAPI GetMetaRgn(HDC,HRGN);
int WINAPI GetRgnBox(HRGN,LPRECT);
BOOL WINAPI InvertRgn(HDC,HRGN);
int WINAPI OffsetClipRgn(HDC,int,int);
int WINAPI OffsetRgn(HRGN,int,int);
BOOL WINAPI PaintRgn(HDC,HRGN);
int WINAPI SelectClipRgn(HDC,HRGN);
int WINAPI SetMetaRgn(HDC);

HRGN WINAPI ExtCreateRegion(const XFORM*,DWORD,const RGNDATA*);
DWORD WINAPI GetRegionData(HRGN,DWORD,LPRGNDATA);
HRGN WINAPI PathToRegion(HDC);
BOOL WINAPI PtInRegion(HRGN,int,int);
BOOL WINAPI RectInRegion(HRGN,LPCRECT);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Region_h__)
