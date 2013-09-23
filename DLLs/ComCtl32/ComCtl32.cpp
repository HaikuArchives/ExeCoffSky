/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ComCtl32.cpp,v 1.1 2003/05/01 02:44:51 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ComCtl32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "ComCtl32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" WINCOMMCTRLAPI HBITMAP WINAPI
CreateMappedBitmap
(HINSTANCE hInstance,  int idBitmap,  UINT wFlags, LPCOLORMAP lpColorMap,  int iNumMaps)
{
	HBITMAP rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HBITMAP", "CreateMappedBitmap", "HINSTANCE", hInstance, "int", idBitmap,
		"UINT", wFlags, "LPCOLORMAP", lpColorMap, "int", iNumMaps, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HPROPSHEETPAGE WINAPI
CreatePropertySheetPageA
(LPCPROPSHEETPAGEA arg0)
{
	HPROPSHEETPAGE rc = (HPROPSHEETPAGE)0;
	WIN32API_ENTER("HPROPSHEETPAGE", "CreatePropertySheetPageA", "LPCPROPSHEETPAGEA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HPROPSHEETPAGE WINAPI
CreatePropertySheetPageW
(LPCPROPSHEETPAGEW arg0)
{
	HPROPSHEETPAGE rc = (HPROPSHEETPAGE)0;
	WIN32API_ENTER("HPROPSHEETPAGE", "CreatePropertySheetPageW", "LPCPROPSHEETPAGEW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HWND WINAPI
CreateStatusWindowA
(LONG style, LPCSTR lpszText, HWND hwndParent, UINT wID)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "CreateStatusWindowA", "LONG", style, "LPCSTR", lpszText, "HWND", hwndParent, "UINT", wID, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HWND WINAPI
CreateStatusWindowW
(LONG style, LPCWSTR lpszText, HWND hwndParent, UINT wID)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "CreateStatusWindowW", "LONG", style, "LPCWSTR", lpszText, "HWND", hwndParent, "UINT", wID, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HWND WINAPI
CreateToolbarEx
(HWND hwnd, DWORD ws, UINT wID, int nBitmaps, HINSTANCE hBMInst,
	UINT wBMID, LPCTBBUTTON lpButtons, int iNumButtons, int dxButton, 
	int dyButton, int dxBitmap, int dyBitmap, UINT uStructSize)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "CreateToolbarEx", "HWND", hwnd, "DWORD", ws, "UINT", wID,
		"int", nBitmaps, "HINSTANCE", hBMInst, "UINT", wBMID, "LPCTBBUTTON", lpButtons,
		"int", iNumButtons, "int", dxButton, "int", dyButton, "int", dxBitmap, "int", dyBitmap, "UINT", uStructSize, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HWND WINAPI
CreateUpDownControl
(DWORD dwStyle, int x, int y, int cx, int cy, HWND hParent, int nID, HINSTANCE hInst,
	HWND hBuddy, int nUpper, int nLower, int nPos)
{
	HWND rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HWND", "CreateUpDownControl", "DWORD", dwStyle, "int", x, "int", y,
		"int", cx, "int", cy, "HWND", hParent, "int", nID, "HINSTANCE", hInst,
		"HWND", hBuddy, "int", nUpper, "int", nLower, "int", nPos, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
DestroyPropertySheetPage
(HPROPSHEETPAGE arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyPropertySheetPage", "HPROPSHEETPAGE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" STDAPI
DllInstall
(BOOL bInstall, LPCWSTR pszCmdLine)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("STDAPI", "DllInstall", "BOOL", bInstall, "LPCWSTR", pszCmdLine, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI void WINAPI
DrawInsert
(HWND handParent, HWND hLB, int nItem)
{
	WIN32API_ENTER("void", "DrawInsert", "HWND", handParent, "HWND", hLB, "int", nItem, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI void WINAPI
DrawStatusTextA
(HDC hDC, LPRECT lprc, LPCSTR pszText, UINT uFlags)
{
	WIN32API_ENTER("void", "DrawStatusTextA", "HDC", hDC, "LPRECT", lprc, "LPCSTR", pszText, "UINT", uFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI void WINAPI
DrawStatusTextW
(HDC hDC, LPRECT lprc, LPCWSTR pszText, UINT uFlags)
{
	WIN32API_ENTER("void", "DrawStatusTextW", "HDC", hDC, "LPRECT", lprc, "LPCWSTR", pszText, "UINT", uFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
FlatSB_EnableScrollBar
(HWND arg0,  int arg1,  UINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlatSB_EnableScrollBar", "HWND", arg0, " int", arg1, " UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
FlatSB_GetScrollInfo
(HWND arg0, int code, LPSCROLLINFO arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlatSB_GetScrollInfo", "HWND", arg0, "int", code, "LPSCROLLINFO", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
FlatSB_GetScrollPos
(HWND arg0, int code)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FlatSB_GetScrollPos", "HWND", arg0, "int", code, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
FlatSB_GetScrollProp
(HWND arg0, int propIndex, LPINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlatSB_GetScrollProp", "HWND", arg0, "int", propIndex, " LPINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
FlatSB_GetScrollRange
(HWND arg0, int code, LPINT arg2, LPINT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlatSB_GetScrollRange", "HWND", arg0, "int", code, "LPINT", arg2, "LPINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
FlatSB_SetScrollInfo
(HWND arg0, int code, LPSCROLLINFO arg2, BOOL fRedraw)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FlatSB_SetScrollInfo", "HWND", arg0, "int", code, "LPSCROLLINFO", arg2, "BOOL", fRedraw, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
FlatSB_SetScrollPos
(HWND arg0, int code, int pos, BOOL fRedraw)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FlatSB_SetScrollPos", "HWND", arg0, "int", code, "int", pos, "BOOL", fRedraw, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
FlatSB_SetScrollProp
(HWND arg0, UINT index, int newValue, BOOL arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlatSB_SetScrollProp", "HWND", arg0, "UINT", index, "int", newValue, "BOOL", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
FlatSB_SetScrollRange
(HWND arg0, int code, int min, int max, BOOL fRedraw)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "FlatSB_SetScrollRange", "HWND", arg0, "int", code, "int", min, "int", max, "BOOL", fRedraw, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
FlatSB_ShowScrollBar
(HWND arg0, int code, BOOL arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FlatSB_ShowScrollBar", "HWND", arg0, "int", code, "BOOL", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI void WINAPI
GetEffectiveClientRect
(HWND hWnd, LPRECT lprc, LPINT lpInfo)
{
	WIN32API_ENTER("void", "GetEffectiveClientRect", "HWND", hWnd, "LPRECT", lprc, "LPINT", lpInfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI int WINAPI
ImageList_Add
(HIMAGELIST himl, HBITMAP hbmImage, HBITMAP hbmMask)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ImageList_Add", "HIMAGELIST", himl, "HBITMAP", hbmImage, "HBITMAP", hbmMask, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int
ImageList_AddIcon
(HIMAGELIST himl, HICON hicon)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ImageList_AddIcon", "HIMAGELIST", himl, "HICON", hicon, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
ImageList_AddMasked
(HIMAGELIST himl, HBITMAP hbmImage, COLORREF crMask)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ImageList_AddMasked", "HIMAGELIST", himl, "HBITMAP", hbmImage, "COLORREF", crMask, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_BeginDrag
(HIMAGELIST himlTrack, int iTrack, int dxHotspot, int dyHotspot)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_BeginDrag", "HIMAGELIST", himlTrack, "int", iTrack, "int", dxHotspot, "int", dyHotspot, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_Copy
(HIMAGELIST himlDst, int iDst, HIMAGELIST himlSrc, int iSrc, UINT uFlags)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_Copy", "HIMAGELIST", himlDst, "int", iDst, "HIMAGELIST", himlSrc, "int", iSrc, "UINT", uFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_Create
(int cx, int cy, UINT flags, int cInitial, int cGrow)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_Create", "int", cx, "int", cy, "UINT", flags, "int", cInitial, "int", cGrow, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_Destroy
(HIMAGELIST himl)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_Destroy", "HIMAGELIST", himl, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_DragEnter
(HWND hwndLock, int x, int y)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_DragEnter", "HWND", hwndLock, "int", x, "int", y, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_DragLeave
(HWND hwndLock)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_DragLeave", "HWND", hwndLock, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_DragMove
(int x, int y)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_DragMove", "int", x, "int", y, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_DragShowNolock
(BOOL fShow)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_DragShowNolock", "BOOL", fShow, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_Draw
(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, UINT fStyle)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_Draw", "HIMAGELIST", himl, "int", i, "HDC", hdcDst, "int", x, "int", y, "UINT", fStyle, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_DrawEx
(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, int dx, int dy, COLORREF rgbBk, COLORREF rgbFg, UINT fStyle)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_DrawEx", "HIMAGELIST", himl, "int", i, "HDC", hdcDst, "int", x, "int", y, "int", dx, "int", dy, "COLORREF", rgbBk, "COLORREF", rgbFg, "UINT", fStyle, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_DrawIndirect
(IMAGELISTDRAWPARAMS* pimldp)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_DrawIndirect", "IMAGELISTDRAWPARAMS*", pimldp, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_Duplicate
(HIMAGELIST himl)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_Duplicate", "HIMAGELIST", himl, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI void WINAPI
ImageList_EndDrag
(void)
{
	WIN32API_ENTER("void", "ImageList_EndDlag", "void", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI COLORREF WINAPI
ImageList_GetBkColor
(HIMAGELIST himl)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "ImageList_GetBkColor", "HIMAGELIST himl", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_GetDragImage
(POINT *ppt, POINT *pptHotspot)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_GetDragImage", "POINT *", ppt, "POINT *", pptHotspot, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HICON WINAPI
ImageList_GetIcon
(HIMAGELIST himl, int i, UINT flags)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ImageList_GetIcon", "HIMAGELIST", himl, "int", i, "UINT", flags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_GetIconSize
(HIMAGELIST himl, int *cx, int *cy)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_GetIconSize", "HIMAGELIST", himl, "int *", cx, "int *", cy, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
ImageList_GetImageCount
(HIMAGELIST himl)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ImageList_GetImageCount", "HIMAGELIST", himl, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_GetImageInfo
(HIMAGELIST himl, int i, IMAGEINFO *pImageInfo)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_GetImageInfo", "HIMAGELIST", himl, "int", i, "IMAGEINFO *", pImageInfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_LoadImageA
(HINSTANCE hi, LPCSTR lpbmp, int cx, int cGrow, COLORREF crMask, UINT uType, UINT uFlags)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_LoadImageA", "HINSTANCE", hi, "LPCSTR", lpbmp, "int", cx, "int", cGrow, "COLORREF", crMask, "UINT", uType, "UINT", uFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_LoadImageW
(HINSTANCE hi, LPCWSTR lpbmp, int cx, int cGrow, COLORREF crMask, UINT uType, UINT uFlags)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_LoadImageW", "HINSTANCE", hi, "LPCWSTR", lpbmp, "int", cx, "int", cGrow, "COLORREF", crMask, "UINT", uType, "UINT", uFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_Merge
(HIMAGELIST himl1, int i1, HIMAGELIST himl2, int i2, int dx, int dy)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_Merge", "HIMAGELIST", himl1, "int", i1, "HIMAGELIST", himl2, "int", i2, "int", dx, "int", dy, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HIMAGELIST WINAPI
ImageList_Read
(LPSTREAM pstm)
{
	HIMAGELIST rc = (HIMAGELIST)0;
	WIN32API_ENTER("HIMAGELIST", "ImageList_Read", "LPSTREAM", pstm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_Remove
(HIMAGELIST himl, int i)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_Remove", "HIMAGELIST", himl, "int", i, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
ImageList_ReplaceIcon
(HIMAGELIST himl, int i, HICON hicon)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "ImageList_ReplaceIcon", "HIMAGELIST", himl, "int", i, "HICON", hicon, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI COLORREF WINAPI
ImageList_SetBkColor
(HIMAGELIST himl, COLORREF clrBk)
{
	COLORREF rc = (COLORREF)-1;
	WIN32API_ENTER("COLORREF", "ImageList_SetBkColor", "HIMAGELIST", himl, "COLORREF", clrBk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_SetDragCursorImage
(HIMAGELIST himlDrag, int iDrag, int dxHotspot, int dyHotspot)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_SetDragCursorImage", "HIMAGELIST", himlDrag, "int", iDrag, "int", dxHotspot, "int", dyHotspot, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_SetIconSize
(HIMAGELIST himl, int cx, int cy)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_SetIconSize", "HIMAGELIST", himl, "int", cx, "int", cy, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_SetImageCount
(HIMAGELIST himl, UINT uNewCount)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_SetImageCount", "HIMAGELIST", himl, "UINT", uNewCount, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_SetOverlayImage
(HIMAGELIST himl, int iImage, int iOverlay)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_SetOverlayImage", "HIMAGELIST", himl, "int", iImage, "int", iOverlay, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ImageList_Write
(HIMAGELIST himl, LPSTREAM pstm)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ImageList_Write", "HIMAGELIST", himl, "LPSTREAM", pstm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI void WINAPI
InitCommonControls
(void)
{
	WIN32API_ENTER("void", "InitCommonControls", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
InitCommonControlsEx
(LPINITCOMMONCONTROLSEX arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitCommonControlsEx", "LPINITCOMMONCONTROLSEX", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
InitializeFlatSB
(HWND arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InitializeFlatSB", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
LBItemFromPt
(HWND hLB, POINT pt, BOOL bAutoScroll)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "LBItemFromPt", "HWND", hLB, "POINT", pt, "BOOL", bAutoScroll, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
MakeDragList
(HWND hLB)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "MakeDragList", "HWND", hLB, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI void WINAPI
MenuHelp
(UINT uMsg, WPARAM wParam, LPARAM lParam, HMENU hMainMenu, HINSTANCE hInst, HWND hwndStatus, UINT *lpwIDs)
{
	WIN32API_ENTER("void", "MenuHelp", "UINT", uMsg, "WPARAM", wParam, "LPARAM", lParam, "HMENU", hMainMenu, "HINSTANCE", hInst, "HWND", hwndStatus, "UINT *", lpwIDs, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINCOMMCTRLAPI int WINAPI
PropertySheetA
(LPCPROPSHEETHEADERA arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "PropertySheetA", "LPCPROPSHEETHEADERA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI int WINAPI
PropertySheetW
(LPCPROPSHEETHEADERW arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "PropertySheetW", "LPCPROPSHEETHEADERW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI BOOL WINAPI
ShowHideMenuCtl
(HWND hWnd, UINT uFlags, LPINT lpInfo)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShowHideMenuCtl", "HWND", hWnd, "UINT", uFlags, "LPINT", lpInfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINCOMMCTRLAPI HRESULT WINAPI
UninitializeFlatSB
(HWND arg0)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "UninitializeFlatSB", "HWND", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	ComCtl32_GetAddressByOrder
#	define	GetAddressByName	ComCtl32_GetAddressByName

#	include "ComCtl32/GetAddressByOrder.h"
#	include "ComCtl32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
