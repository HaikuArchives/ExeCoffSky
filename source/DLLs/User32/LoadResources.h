/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: LoadResources.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [LoadResources.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__LoadResources_h__)
#	define	__LoadResources_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HACCEL WINAPI LoadAcceleratorsA(HINSTANCE hInstance, LPCSTR lpTableName);
HACCEL WINAPI LoadAcceleratorsW(HINSTANCE hInstance, LPCWSTR lpTableName);
HBITMAP WINAPI LoadBitmapA(HINSTANCE hInstance, LPCSTR lpBitmapName);
HBITMAP WINAPI LoadBitmapW(HINSTANCE hInstance, LPCWSTR lpBitmapName);
HCURSOR WINAPI LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName);
HCURSOR WINAPI LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName);
HICON WINAPI LoadIconA(HINSTANCE hInstance, LPCSTR lpIconName);
HICON WINAPI LoadIconW(HINSTANCE hInstance, LPCWSTR lpIconName);
HANDLE WINAPI LoadImageA(HINSTANCE hInstance, LPCSTR lpImageName, UINT uType, int cxDesired, int cyDesired, UINT fuLoad);
HANDLE WINAPI LoadImageW(HINSTANCE hInstance, LPCWSTR lpImageName, UINT uType, int cxDesired, int cyDesired, UINT fuLoad);
HMENU WINAPI LoadMenuA(HINSTANCE hInstance, LPCSTR lpMenuName);
HMENU WINAPI LoadMenuW(HINSTANCE hInstance, LPCWSTR lpMenuName);
int WINAPI LoadStringA(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int nBufferMax);
int WINAPI LoadStringW(HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int nBufferMax);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__LoadResources_h__)
