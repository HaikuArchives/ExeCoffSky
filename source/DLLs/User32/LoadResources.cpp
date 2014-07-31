/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: LoadResources.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Resource.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "LoadResources.h"
#include "Kernel32/Module.h"
#include "Kernel32/Resource.h"
#include "GDI32/DIBSection.h"
#include "Menu.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"
#include "ResourceTable.h"

extern "C" HACCEL WINAPI
LoadAcceleratorsA
(HINSTANCE arg0, LPCSTR arg1)
{
	HACCEL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HACCEL", "LoadAcceleratorsA", "HINSTANCE", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HACCEL WINAPI
LoadAcceleratorsW
(HINSTANCE arg0, LPCWSTR arg1)
{
	HACCEL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HACCEL", "LoadAcceleratorsW", "HINSTANCE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBITMAP WINAPI
LoadBitmapA
(HINSTANCE hInstance, LPCSTR lpBitmapName)
{
	WIN32API_ENTER("HBITMAP", "LoadBitmapA", "HINSTANCE", hInstance, "LPCSTR", lpBitmapName, NULL);
	Win32String name;
	LPCWSTR lpBitmapNameW = NULL;
	if (0 != (0xffff0000 & (UINT)lpBitmapName)) {
		name.SetToA(lpBitmapName);
		lpBitmapNameW = name.StringW();
	} else {
		lpBitmapNameW = (LPCWSTR)lpBitmapName;
	}
	WIN32API_INTERNAL_START();
	HBITMAP rc = LoadBitmapW(hInstance, lpBitmapNameW);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HBITMAP WINAPI
LoadBitmapW
(HINSTANCE hInstance, LPCWSTR lpBitmapName)
{
	HBITMAP rc = NULL;
	WIN32API_ENTER("HBITMAP", "LoadBitmapW", "HINSTANCE", hInstance, "LPCWSTR", lpBitmapName, NULL);
	try {
		Image *image = HandleToImage(hInstance);
		if (NULL == image) throw ERROR_INVALID_HANDLE;
		void *base = image->GetResourceAddress();
		if (NULL == image) throw ERROR_RESOURCE_DATA_NOT_FOUND;
		WIN32API_INTERNAL_START();
		HRSRC rsrc = FindResourceW((HMODULE)hInstance, lpBitmapName, MAKEINTRESOURCEW(RT_BITMAP));
		WIN32API_INTERNAL_END();
		if (NULL != rsrc) {
			LpResourceDataEntry rde = (LpResourceDataEntry)((UINT)base + (UINT)rsrc);
			LPBITMAPINFO bi = (LPBITMAPINFO)((UINT)hInstance + rde->DataRva);
			LPBITMAPINFOHEADER bih = &bi->bmiHeader;
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
			WIN32API_INTERNAL_START();
			rc = CreateDIBSection(NULL, bi, (0 == bih->biClrUsed)? DIB_RGB_COLORS: DIB_PAL_COLORS, (VOID **)-1, NULL, 0);
			WIN32API_INTERNAL_END();
		}
	} catch (int e) {
		WIN32API_ERROR(e);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
LoadCursorA
(HINSTANCE hInstance, LPCTSTR lpCursorName)
{
	WIN32API_POINTER(lpCursorName);
	HCURSOR rc = NULL;
	WIN32API_ENTER("HCURSOR", "LoadCursorA", "HINSTANCE", hInstance, "LPCTSTR", lpCursorName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HCURSOR WINAPI
LoadCursorW
(HINSTANCE arg0, LPCWSTR arg1)
{
	HCURSOR rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HCURSOR", "LoadCursorW", "HINSTANCE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
LoadIconA
(HINSTANCE hInstance, LPCTSTR lpIconName)
{
	HICON rc = NULL;
	WIN32API_ENTER("HICON", "LoadIconA", "HINSTANCE", hInstance, "LPCTSTR", lpIconName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
LoadIconW
(HINSTANCE arg0, LPCWSTR arg1)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "LoadIconW", "HINSTANCE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
LoadImageA
(HINSTANCE arg0, LPCSTR arg1, UINT arg2, int arg3, int arg4, UINT arg5)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "LoadImageA", "HINSTANCE", arg0, "LPCSTR", arg1, "UINT", arg2, "int", arg3, "int", arg4, "UINT", arg5, NULL);
	rc = LoadBitmapA(arg0, arg1); // XXX
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
LoadImageW
(HINSTANCE arg0, LPCWSTR arg1, UINT arg2, int arg3, int arg4, UINT arg5)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "LoadImageW", "HINSTANCE", arg0, "LPCWSTR", arg1, "UINT", arg2, "int", arg3, "int", arg4, "UINT", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
LoadMenuA
(HINSTANCE hInstance, LPCTSTR lpMenuName)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "LoadMenuA", "HINSTANCE", hInstance, "LPCTSTR", lpMenuName, NULL);
	WIN32API_INTERNAL_START();
	try {
		Image *image = HandleToImage(hInstance);
		if (NULL == image) throw ERROR_INVALID_HANDLE;
		void *base = image->GetResourceAddress();
		if (NULL == base) throw ERROR_RESOURCE_DATA_NOT_FOUND;
		HRSRC rsrc = FindResourceA((HMODULE)hInstance, lpMenuName, RT_MENU);
		if (NULL != rsrc) {
			LpResourceDataEntry rde = (LpResourceDataEntry)((UINT)base + (UINT)rsrc);
			rc = LoadMenuIndirectA((CONST MENUTEMPLATEA *)((UINT)hInstance + rde->DataRva));
		}
	} catch (int e) {
		WIN32API_ERROR(e);
	}
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
LoadMenuW
(HINSTANCE arg0, LPCWSTR arg1)
{
	HMENU rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HMENU", "LoadMenuW", "HINSTANCE", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
LoadStringA
(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int nBufferMax)
{
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("int", "LoadStringA", "HINSTANCE", hInstance, "UINT", uID, "LPSTR", lpBuffer, "int", nBufferMax, NULL);
	WIN32API_INTERNAL_START();
	int rc = LoadStringW(hInstance, uID, NULL, 0);
	short *buf = new short[rc];
	if (NULL == buf) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		rc = LoadStringW(hInstance, uID, buf, rc);
		Win32String str;
		str.SetToW(buf);
		delete buf;
		if (str.LengthA() >= (UINT)nBufferMax) {
			rc = str.LengthA() + 1;
			WIN32API_ERROR(ERROR_MORE_DATA);
		} else {
			strcpy(lpBuffer, str.StringA());
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	}
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
LoadStringW
(HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int nBufferMax)
{
	int rc = 0;
	WIN32API_POINTER(lpBuffer);
	WIN32API_ENTER("int", "LoadStringW", "HINSTANCE", hInstance, "UINT", uID, "LPWSTR", lpBuffer, "int", nBufferMax, NULL);
	WIN32API_INTERNAL_START();
	try {
		if (NULL == hInstance) hInstance = GetModuleHandleW(NULL);
		Image *image = HandleToImage(hInstance);
		if (NULL == image) throw ERROR_INVALID_HANDLE;
		void *base = image->GetResourceAddress();
		if (NULL == base) throw ERROR_RESOURCE_DATA_NOT_FOUND;
		HRSRC rsrc = FindResourceW((HMODULE)hInstance, MAKEINTRESOURCEW((uID >> 4) + 1), MAKEINTRESOURCEW(RT_STRING));
		if (NULL != rsrc) {
			LpResourceDataEntry rde = (LpResourceDataEntry)((UINT)base + (UINT)rsrc);
			LpResourceDirectoryString rds;
			Win32String str;
#if defined(_DEBUG)
			rds = (LpResourceDirectoryString)((UINT)hInstance + (UINT)rde->DataRva);
			for (UINT i = 0; i <= (uID & 0xf); i++) {
				str.SetToW(rds->UnicodeString, rds->Length);
				WIN32API_INFO("\tskip %4d =>%s\n", (uID & ~0xf) + i, str.StringU());
				rds = (LpResourceDirectoryString)&rds->UnicodeString[rds->Length];
			}
#endif	// defined(_DEBUG)
			rds = (LpResourceDirectoryString)((UINT)hInstance + (UINT)rde->DataRva);
			for (UINT i = 0; i < (uID & 0xf); i++) rds = (LpResourceDirectoryString)&rds->UnicodeString[rds->Length];
			str.SetToW(rds->UnicodeString, rds->Length);
			WIN32API_INFO("\t found => %s\n", str.StringU());
			if ((DWORD)nBufferMax <= str.LengthW()) {
				rc = str.LengthW() + 1;
				WIN32API_ERROR(ERROR_MORE_DATA);
			} else {
				rc = str.LengthW();
				Win32String::strcpyW(lpBuffer, str.StringW());
				WIN32API_ERROR(ERROR_SUCCESS);
			}
		} else {
			WIN32API_INFO("\tnot found.\n");
			WIN32API_ERROR(ERROR_NOT_FOUND);
		}
	} catch (int e) {
		WIN32API_ERROR(e);
	}
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}
