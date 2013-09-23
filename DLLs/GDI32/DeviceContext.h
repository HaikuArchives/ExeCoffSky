/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DeviceContext.h,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DeviceContext.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__DeviceContext_h__)
#	define	__DeviceContext_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Palette__)
class Palette;
#		define	__Palette__
#	endif	// !defined(__Palette__)

#	if !defined(__Bitmap__)
class Bitmap;
#		define	__Bitmap__
#	endif	// !defined(__Bitmap__)

#	if !defined(__Window__)
class Window;
#		define	__Window__
#	endif	// !defined(__Window__)

#	if !defined(__Object__)
class Object;
#		define	__Object__
#	endif	// !defined(__Object__)

typedef struct tagDEVMODEA {
} DEVMODEA, *PDEVMODEA, *LPDEVMODEA;

typedef struct tagDEVMODEW {
} DEVMODEW, *PDEVMODEW, *LPDEVMODEW;

typedef struct tagDEVMODEU {
} DEVMODEU, *PDEVMODEU, *LPDEVMODEU;

#	if defined(UNICODE)
typedef DEVMODEW DEVMODE;
#	else
typedef DEVMODEA DEVMODE;
#	endif	// defined(UNICODE)
typedef DEVMODE *PDEVMODE, *LPDEVMODE;

#	define	DC_MAGIC	'_HDC'

#	define	HORZRES				8
#	define	VERTRES				10
#	define	BITSPIXEL			12

class DeviceContext {
	typedef struct _Objects {
		Palette *palette;
		Bitmap *bitmap;
	} Objects;
public:
	DWORD magic;
private:
	Window *owner;
	color_space color;
	BList objstack;
	int stack;
	Objects *objects;
public:
	DeviceContext(void);
	~DeviceContext(void);
	
	DeviceContext *CreateCompatible(void);
	
	void SetOwnerWindow(Window *owner = NULL);
	int PushObjects(void);
	bool PopObjects(int stack = -1);
	
	Object *SelectObject(Object *object);
	Palette *SelectPalette(Palette *palette);
	Palette *GetPalette(void);
	UINT RealizePalette(void);
	Bitmap *SelectBitmap(Bitmap *bitmap);
	Bitmap *GetBitmap(void);
	
	int GetDepth(void) const;
	
	void Update(LPRECT rect = NULL);
	
	static DeviceContext *HandleToDeviceContext(HDC hdc);
};

#	if !defined(__DeviceContext__)
#		define	__DeviceContext__
#	endif	// !defined(__DeviceContext__)

static HDC CreateDCU(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const DEVMODEU *lpInitData);
static HDC CreateICU(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const DEVMODEU *lpInitData);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

BOOL WINAPI CancelDC(HDC hdc);
HDC WINAPI CreateCompatibleDC(HDC hdc);
HDC WINAPI CreateDCA(LPCSTR lpszDriver, LPCSTR lpszDevice, LPCSTR lpszOutput, const DEVMODEA *lpInitData);
HDC WINAPI CreateDCW(LPCWSTR lpszDriver, LPCWSTR lpszDevice, LPCWSTR lpszOutput, const DEVMODEW *lpInitData);
HDC WINAPI CreateICA(LPCSTR,LPCSTR,LPCSTR,const DEVMODEA*);
HDC WINAPI CreateICW(LPCWSTR,LPCWSTR,LPCWSTR,const DEVMODEW*);
BOOL WINAPI DeleteDC(HDC hdc);
HDC WINAPI ResetDCA(HDC,const DEVMODEA*);
HDC WINAPI ResetDCW(HDC,const DEVMODEW*);
BOOL WINAPI RestoreDC(HDC hdc, int nSavedDC);
int WINAPI SaveDC(HDC hdc);
int WINAPI GetDeviceCaps(HDC hdc, int nIndex);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__DeviceContext_h__)
