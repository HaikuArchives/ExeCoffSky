/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DeviceContext.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DeviceContext.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "DeviceContext.h"
#include "Kernel32/LastError.h"
#include "User32/Window.h"
#include "User32/Desktop.h"
#include "Bitmap.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

DeviceContext::DeviceContext
(void):
magic(DC_MAGIC),
owner(NULL),
stack(0)
{
	BScreen scr;
	color = scr.ColorSpace();
	objects = new Objects();
	memset(objects, 0, sizeof(Objects));
}

DeviceContext::~DeviceContext
(void)
{
	if (NULL != objects) delete objects;
	magic = 0;
}

DeviceContext *
DeviceContext::CreateCompatible
(void)
{
	DeviceContext *dc = new DeviceContext();
	if (NULL == dc) return NULL;
	dc->color = color;
	return dc;
}

void
DeviceContext::SetOwnerWindow
(Window *window)
{
	owner = window;
}

int
DeviceContext::PushObjects
(void)
{
	WIN32API_INFO("\tnot impl.\n");
	return 0;
}

bool
DeviceContext::PopObjects
(int stack)
{
	return false;
}

Object *
DeviceContext::SelectObject
(Object *object)
{
	Palette *pal = DYNAMIC_CAST(Palette *, object);
	if (NULL != pal) return SelectPalette(pal);
	Bitmap *bmp = DYNAMIC_CAST(Bitmap *, object);
	if (NULL != bmp) return SelectBitmap(bmp);
	WIN32API_INFO("\tnot recognized object\n");
	return NULL;
}

Palette *
DeviceContext::SelectPalette
(Palette *palette)
{
	WIN32API_INFO("\tSelectPalette\n");
	if (NULL == objects) return NULL;
	Palette *pal = objects->palette;
	objects->palette = palette;
	if (NULL != pal) pal->SetOwner(NULL);
	if (NULL != palette) palette->SetOwner(this);
	return pal;
}

Palette*
DeviceContext::GetPalette
(void)
{
	if (NULL == objects) return NULL;
	return objects->palette;
}

UINT
DeviceContext::RealizePalette
(void)
{
	// XXX
	if (NULL != owner) owner->PostMessage(WM_PAINT, 0, 0);
	return 0;
}

Bitmap *
DeviceContext::SelectBitmap
(Bitmap *bitmap)
{
	WIN32API_INFO("\tSelectBitmap\n");
	if (NULL == objects) return NULL;
	Bitmap *bmp = objects->bitmap;
	objects->bitmap = bitmap;
	return bmp;
}

Bitmap *
DeviceContext::GetBitmap
(void)
{
	if (NULL == objects) return NULL;
	return objects->bitmap;
}

int
DeviceContext::GetDepth
(void) const
{
	switch (color) {
	case B_RGB32:
		return 32;
	case B_RGB24:
		return 24;
	case B_RGB15:
	case B_RGB16:
		return 16;
	case B_CMAP8:
		return 8;
	default:
		WIN32API_INFO("\tunknown color space\n");
	}
	return 0;
}

void
DeviceContext::Update
(LPRECT rect)
{
	if (NULL == owner) {
		WIN32API_INFO("\tupdate: not owner window\n");
		return;
	}
	Bitmap *bmp = GetBitmap();
	if (NULL == bmp) return;
	BBitmap *bbmp = bmp->NativeBitmap();
	if (NULL == bbmp) {
		WIN32API_INFO("\tdc update: unsupported depth bitmap\n");
		return;
	} else {
		WIN32API_INFO("\tdc update\n");
	}
	owner->Update(bbmp, rect);
}

DeviceContext *
DeviceContext::HandleToDeviceContext
(HDC hdc)
{
	if (NULL == hdc) return NULL;
	if (INVALID_HANDLE_VALUE == hdc) return NULL;
	DeviceContext *dc = (DeviceContext *)hdc;
	if (dc->magic != DC_MAGIC) return NULL;
	return dc;
}

static HDC
CreateDCU
(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const DEVMODEU *lpInitData)
{
	DeviceContext *rc = NULL;
	WIN32API_INFO("\tlpszDriver: %s\n", lpszDriver);
	WIN32API_INFO("\tlpszDevice: %s\n", lpszDevice);
	WIN32API_INFO("\tlpszOutput: %s\n", lpszOutput);
	if (0 == strcmp("DISPLAY", lpszDriver)) {
		if (NULL != lpszDevice) WIN32API_INFO("\tignore Device: %s\n", lpszDevice);
		if (NULL != lpszOutput) WIN32API_INFO("\tignore Output: %s\n", lpszOutput);
		if (NULL != lpInitData) WIN32API_INFO("\tignore InitData\n");
		WIN32API_INTERNAL_START();
		HWND hWnd = GetDesktopWindow();
		HDC hdc = GetDC(hWnd);
		DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
		if (NULL != dc) rc = dc->CreateCompatible();
		if (NULL != dc) WIN32API_ERROR(ERROR_SUCCESS);
		WIN32API_INTERNAL_END();
	} else {
		WIN32API_INFO("\tnot impl.\n");
		WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	}
	return (HDC)rc;
}

extern "C" BOOL WINAPI
CancelDC
(HDC hdc)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CancelDC", "HDC", hdc, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateCompatibleDC
(HDC hdc)
{
	HDC rc = NULL;
	WIN32API_ENTER("HDC", "CreateCompatibleDC", "HDC", hdc, NULL);
	if (NULL == hdc) {
		WIN32API_INTERNAL_START();
		HWND hWnd = GetDesktopWindow();
		hdc = GetDC(hWnd);
		WIN32API_INTERNAL_END();
	}
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if (NULL != dc) {
		rc = dc->CreateCompatible();
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateDCA
(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const DEVMODEA* lpInitData)
{
	WIN32API_POINTER(lpszDriver);
	WIN32API_POINTER(lpszDevice);
	WIN32API_POINTER(lpszOutput);
	WIN32API_POINTER(lpInitData);
	WIN32API_ENTER("HDC", "CreateDCA", "LPCSTR", lpszDriver, "LPCSTR", lpszDevice, "LPCSTR", lpszOutput, "const DEVMODEA*", lpInitData, NULL);
	Win32String driver;
	driver.SetToA(lpszDriver);
	Win32String device;
	device.SetToA(lpszDevice);
	Win32String output;
	output.SetToA(lpszOutput);
	DEVMODEU mode;
	// XXX: set mode
	HDC rc = CreateDCU(driver.StringU(), device.StringU(), output.StringU(), &mode);
	// XXX: set lpInitData
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateDCW
(LPCWSTR lpszDriver, LPCWSTR lpszDevice, LPCWSTR lpszOutput, const DEVMODEW* lpInitData)
{
	WIN32API_POINTER(lpszDriver);
	WIN32API_POINTER(lpszDevice);
	WIN32API_POINTER(lpszOutput);
	WIN32API_POINTER(lpInitData);
	WIN32API_ENTER("HDC", "CreateDCW", "LPCWSTR", lpszDriver, "LPCWSTR", lpszDevice, "LPCWSTR", lpszOutput, "const DEVMODEW*", lpInitData, NULL);
	Win32String driver;
	driver.SetToW(lpszDriver);
	Win32String device;
	device.SetToW(lpszDevice);
	Win32String output;
	output.SetToW(lpszOutput);
	DEVMODEU mode;
	// XXX: set mode
	HDC rc = CreateDCU(driver.StringU(), device.StringU(), output.StringU(), &mode);
	// XXX: set lpInitData
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateICA
(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const DEVMODEA* lpInitData)
{
	WIN32API_POINTER(lpszDriver);
	WIN32API_POINTER(lpszDevice);
	WIN32API_POINTER(lpszOutput);
	WIN32API_POINTER(lpInitData);
	WIN32API_ENTER("HDC", "CreateICA", "LPCSTR", lpszDriver, "LPCSTR", lpszDevice, "LPCSTR", lpszOutput, "const DEVMODEA*", lpInitData, NULL);
	Win32String driver;
	driver.SetToA(lpszDriver);
	Win32String device;
	device.SetToA(lpszDevice);
	Win32String output;
	output.SetToA(lpszOutput);
	DEVMODEU mode;
	// XXX: set mode
	HDC rc = CreateDCU(driver.StringU(), device.StringU(), output.StringU(), &mode);
	// XXX: set lpInitData
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
CreateICW
(LPCWSTR lpszDriver, LPCWSTR lpszDevice, LPCWSTR lpszOutput, const DEVMODEW* lpInitData)
{
	WIN32API_POINTER(lpszDriver);
	WIN32API_POINTER(lpszDevice);
	WIN32API_POINTER(lpszOutput);
	WIN32API_POINTER(lpInitData);
	WIN32API_ENTER("HDC", "CreateICW", "LPCWSTR", lpszDriver, "LPCWSTR", lpszDevice, "LPCWSTR", lpszOutput, "const DEVMODEW*", lpInitData, NULL);
	Win32String driver;
	driver.SetToW(lpszDriver);
	Win32String device;
	device.SetToW(lpszDevice);
	Win32String output;
	output.SetToW(lpszOutput);
	DEVMODEU mode;
	// XXX: set mode
	HDC rc = CreateDCU(driver.StringU(), device.StringU(), output.StringU(), &mode);
	// XXX: set lpInitData
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DeleteDC
(HDC hdc)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteDC", "HDC", hdc, NULL);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if (NULL != dc) {
		delete REINTERPRET_CAST(DeviceContext *, hdc);
		rc = TRUE;
	} else {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
ResetDCA
(HDC arg0, const DEVMODEA* arg1)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "ResetDCA", "HDC", arg0, "const DEVMODEA*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HDC WINAPI
ResetDCW
(HDC arg0, const DEVMODEW* arg1)
{
	HDC rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HDC", "ResetDCW", "HDC", arg0, "const DEVMODEW*", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RestoreDC
(HDC hdc, int nSavedDC)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RestoreDC", "HDC", hdc, "int", nSavedDC, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SaveDC
(HDC hdc)
{
	int rc = 0;
	WIN32API_ENTER("int", "SaveDC", "HDC", hdc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetDeviceCaps
(HDC hdc, int nIndex)
{
	int rc = 0;
	WIN32API_ENTER("int", "GetDeviceCaps", "HDC", hdc, "int", nIndex, NULL);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hdc);
	if (NULL == dc) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		switch(nIndex) {
		case HORZRES: {
			BScreen scr;
			BRect rect = scr.Frame();
			rc = (int)rect.Width();
			break; }
		case VERTRES: {
			BScreen scr;
			BRect rect = scr.Frame();
			rc = (int)rect.Height();
			break; }
		case BITSPIXEL:
			rc = dc->GetDepth();
			break;
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}
