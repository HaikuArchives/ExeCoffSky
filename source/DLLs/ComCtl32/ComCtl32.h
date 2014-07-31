/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ComCtl32.h,v 1.1 2003/05/01 02:44:51 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ComCtl32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__ComCtl32_h__)
#	define	__ComCtl32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(WINCOMMCTRLAPI)
#		define	WINCOMMCTRLAPI
#	endif	// !defined(WINCOMMCTRLAPI)

struct COLORMAP;
typedef COLORMAP *LPCOLORMAP;
struct PROPSHEETPAGEA;
typedef CONST PROPSHEETPAGEA *LPCPROPSHEETPAGEA;
struct PROPSHEETPAGEW;
typedef CONST PROPSHEETPAGEW *LPCPROPSHEETPAGEW;
struct TBBUTTON;
typedef CONST TBBUTTON *LPCTBBUTTON;
struct IMAGELISTDRAWPARAMS;
struct IMAGEINFO;
struct STREAM;
typedef STREAM *LPSTREAM;
struct INITCOMMONCONTROLSEX;
typedef INITCOMMONCONTROLSEX *LPINITCOMMONCONTROLSEX;
struct PROPSHEETHEADERA;
typedef CONST PROPSHEETHEADERA *LPCPROPSHEETHEADERA;
struct PROPSHEETHEADERW;
typedef CONST PROPSHEETHEADERW *LPCPROPSHEETHEADERW;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

WINCOMMCTRLAPI HBITMAP WINAPI CreateMappedBitmap(HINSTANCE hInstance, int idBitmap, UINT wFlags, LPCOLORMAP lpColorMap, int iNumMaps);
WINCOMMCTRLAPI HPROPSHEETPAGE WINAPI CreatePropertySheetPageA(LPCPROPSHEETPAGEA);
WINCOMMCTRLAPI HPROPSHEETPAGE WINAPI CreatePropertySheetPageW(LPCPROPSHEETPAGEW);
WINCOMMCTRLAPI HWND WINAPI CreateStatusWindowA(LONG style, LPCSTR lpszText, HWND hwndParent, UINT wID);
WINCOMMCTRLAPI HWND WINAPI CreateStatusWindowW(LONG style, LPCWSTR lpszText, HWND hwndParent, UINT wID);
WINCOMMCTRLAPI HWND WINAPI CreateToolbarEx(HWND hwnd, DWORD ws, UINT wID, int nBitmaps, HINSTANCE hBMInst, UINT wBMID, LPCTBBUTTON lpButtons, int iNumButtons, int dxButton, int dyButton, int dxBitmap, int dyBitmap, UINT uStructSize);
WINCOMMCTRLAPI HWND WINAPI CreateUpDownControl(DWORD dwStyle, int x, int y, int cx, int cy, HWND hParent, int nID, HINSTANCE hInst, HWND hBuddy, int nUpper, int nLower, int nPos);
WINCOMMCTRLAPI BOOL WINAPI DestroyPropertySheetPage(HPROPSHEETPAGE);
STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine);
WINCOMMCTRLAPI void WINAPI DrawInsert(HWND handParent, HWND hLB, int nItem);
WINCOMMCTRLAPI void WINAPI DrawStatusTextA(HDC hDC, LPRECT lprc, LPCSTR pszText, UINT uFlags);
WINCOMMCTRLAPI void WINAPI DrawStatusTextW(HDC hDC, LPRECT lprc, LPCWSTR pszText, UINT uFlags);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_EnableScrollBar(HWND, int, UINT);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollInfo(HWND, int code, LPSCROLLINFO);
WINCOMMCTRLAPI int WINAPI FlatSB_GetScrollPos(HWND, int code);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollProp(HWND, int propIndex, LPINT);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_GetScrollRange(HWND, int code, LPINT, LPINT);
WINCOMMCTRLAPI int WINAPI FlatSB_SetScrollInfo(HWND, int code, LPSCROLLINFO, BOOL fRedraw);
WINCOMMCTRLAPI int WINAPI FlatSB_SetScrollPos(HWND, int code, int pos, BOOL fRedraw);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_SetScrollProp(HWND, UINT index, int newValue, BOOL);
WINCOMMCTRLAPI int WINAPI FlatSB_SetScrollRange(HWND, int code, int min, int max, BOOL fRedraw);
WINCOMMCTRLAPI BOOL WINAPI FlatSB_ShowScrollBar(HWND, int code, BOOL);
WINCOMMCTRLAPI void WINAPI GetEffectiveClientRect(HWND hWnd, LPRECT lprc, LPINT lpInfo);
WINCOMMCTRLAPI int WINAPI ImageList_Add(HIMAGELIST himl, HBITMAP hbmImage, HBITMAP hbmMask);
WINCOMMCTRLAPI int ImageList_AddIcon(HIMAGELIST himl, HICON hicon);
WINCOMMCTRLAPI int WINAPI ImageList_AddMasked(HIMAGELIST himl, HBITMAP hbmImage, COLORREF crMask);
WINCOMMCTRLAPI BOOL WINAPI ImageList_BeginDrag(HIMAGELIST himlTrack, int iTrack, int dxHotspot, int dyHotspot);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Copy(HIMAGELIST himlDst, int iDst, HIMAGELIST himlSrc, int iSrc, UINT uFlags);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Create(int cx, int cy, UINT flags, int cInitial, int cGrow);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Destroy(HIMAGELIST himl);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragEnter(HWND hwndLock, int x, int y);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragLeave(HWND hwndLock);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragMove(int x, int y);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DragShowNolock(BOOL fShow);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Draw(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, UINT fStyle);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DrawEx(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, int dx, int dy, COLORREF rgbBk, COLORREF rgbFg, UINT fStyle);
WINCOMMCTRLAPI BOOL WINAPI ImageList_DrawIndirect(IMAGELISTDRAWPARAMS* pimldp);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Duplicate(HIMAGELIST himl);
WINCOMMCTRLAPI void WINAPI ImageList_EndDrag(void);
WINCOMMCTRLAPI COLORREF WINAPI ImageList_GetBkColor(HIMAGELIST himl);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_GetDragImage(POINT *ppt,POINT *pptHotspot);
WINCOMMCTRLAPI HICON WINAPI ImageList_GetIcon(HIMAGELIST himl, int i, UINT flags);
WINCOMMCTRLAPI BOOL WINAPI ImageList_GetIconSize(HIMAGELIST himl, int *cx, int *cy);
WINCOMMCTRLAPI int WINAPI ImageList_GetImageCount(HIMAGELIST himl);
WINCOMMCTRLAPI BOOL WINAPI ImageList_GetImageInfo(HIMAGELIST himl, int i, IMAGEINFO* pImageInfo);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_LoadImageA(HINSTANCE hi, LPCSTR lpbmp, int cx, int cGrow, COLORREF crMask, UINT uType, UINT uFlags);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_LoadImageW(HINSTANCE hi, LPCWSTR lpbmp, int cx, int cGrow, COLORREF crMask, UINT uType, UINT uFlags);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Merge(HIMAGELIST himl1, int i1, HIMAGELIST himl2, int i2, int dx, int dy);
WINCOMMCTRLAPI HIMAGELIST WINAPI ImageList_Read(LPSTREAM pstm);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Remove(HIMAGELIST himl, int i);
WINCOMMCTRLAPI int WINAPI ImageList_ReplaceIcon(HIMAGELIST himl, int i, HICON hicon);
WINCOMMCTRLAPI COLORREF WINAPI ImageList_SetBkColor(HIMAGELIST himl, COLORREF clrBk);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetDragCursorImage(HIMAGELIST himlDrag, int iDrag, int dxHotspot, int dyHotspot);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetIconSize(HIMAGELIST himl, int cx, int cy);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetImageCount(HIMAGELIST himl, UINT uNewCount);
WINCOMMCTRLAPI BOOL WINAPI ImageList_SetOverlayImage(HIMAGELIST himl, int iImage, int iOverlay);
WINCOMMCTRLAPI BOOL WINAPI ImageList_Write(HIMAGELIST himl, LPSTREAM pstm);
WINCOMMCTRLAPI void WINAPI InitCommonControls(void);
WINCOMMCTRLAPI BOOL WINAPI InitCommonControlsEx(LPINITCOMMONCONTROLSEX);
WINCOMMCTRLAPI BOOL WINAPI InitializeFlatSB(HWND);
WINCOMMCTRLAPI int WINAPI LBItemFromPt(HWND hLB, POINT pt, BOOL bAutoScroll);
WINCOMMCTRLAPI BOOL WINAPI MakeDragList(HWND hLB);
WINCOMMCTRLAPI void WINAPI MenuHelp(UINT uMsg, WPARAM wParam, LPARAM lParam, HMENU hMainMenu, HINSTANCE hInst, HWND hwndStatus, UINT *lpwIDs);
WINCOMMCTRLAPI int WINAPI PropertySheetA(LPCPROPSHEETHEADERA);
WINCOMMCTRLAPI int WINAPI PropertySheetW(LPCPROPSHEETHEADERW);
WINCOMMCTRLAPI BOOL WINAPI ShowHideMenuCtl(HWND hWnd, UINT uFlags, LPINT lpInfo);
WINCOMMCTRLAPI HRESULT WINAPI UninitializeFlatSB(HWND);

#	if defined(_BUILTIN_DLL)
void *ComCtl32_GetAddressByOrder(int order);
void *ComCtl32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__ComCtl32_h__)
