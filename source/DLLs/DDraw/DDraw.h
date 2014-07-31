/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DDraw.h,v 1.1 2003/05/01 03:02:38 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DDraw.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__DDraw_h__)
#	define	__DDraw_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__COM_h__)
#		include "COM.h"
#	endif	// !defined(__COM_h__)

#	if !defined(__IUnknown_h__)
#		include "IUnknown.h"
#	endif	// !defined(__IUnknown_h__)

DEFINE_GUID(CLSID_DirectDraw,				0xD7B70EE0, 0x4340, 0x11CF, 0xB0, 0x63, 0x00, 0x20, 0xAF, 0xC2, 0xCD, 0x35);
DEFINE_GUID(CLSID_DirectDrawClipper,		0x593817A0, 0x7DB3, 0x11CF, 0xA2, 0xDE, 0x00, 0xAA, 0x00, 0xb9, 0x33, 0x56);

DEFINE_GUID(IID_IDirectDraw,				0x6C14DB80, 0xA733, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);
DEFINE_GUID(IID_IDirectDraw2,				0xB3A6F3E0, 0x2B43, 0x11CF, 0xA2, 0xDE, 0x00, 0xAA, 0x00, 0xB9, 0x33, 0x56);
DEFINE_GUID(IID_IDirectDrawSurface,			0x6C14DB81, 0xA733, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);
DEFINE_GUID(IID_IDirectDrawSurface2,		0x57805885, 0x6eec, 0x11cf, 0x94, 0x41, 0xa8, 0x23, 0x03, 0xc1, 0x0e, 0x27);
DEFINE_GUID(IID_IDirectDrawSurface3,		0xDA044E00, 0x69B2, 0x11D0, 0xA1, 0xD5, 0x00, 0xAA, 0x00, 0xB8, 0xDF, 0xBB);
DEFINE_GUID(IID_IDirectDrawPalette,			0x6C14DB84, 0xA733, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);
DEFINE_GUID(IID_IDirectDrawClipper,			0x6C14DB85, 0xA733, 0x11CE, 0xA5, 0x21, 0x00, 0x20, 0xAF, 0x0B, 0xE5, 0x60);
DEFINE_GUID(IID_IDirectDrawColorControl,	0x4B9F0EE0, 0x0D7E, 0x11D0, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8);

interface IDirectDraw;
interface IDirectDraw2;
interface IDirectDrawSurface;
interface IDirectDrawSurface2;
interface IDirectDrawSurface3;

interface IDirectDrawPalette;
interface IDirectDrawClipper;
interface IDirectDrawColorControl;

typedef interface IDirectDraw					*LPDIRECTDRAW;
typedef interface IDirectDraw2					*LPDIRECTDRAW2;
typedef interface IDirectDrawSurface			*LPDIRECTDRAWSURFACE;
typedef interface IDirectDrawSurface2			*LPDIRECTDRAWSURFACE2;
typedef interface IDirectDrawSurface3			*LPDIRECTDRAWSURFACE3;

typedef interface IDirectDrawPalette			*LPDIRECTDRAWPALETTE;
typedef interface IDirectDrawClipper			*LPDIRECTDRAWCLIPPER;
typedef interface IDirectDrawColorControl		*LPDIRECTDRAWCOLORCONTROL;

struct DDSURFACEDESC;
struct DDCAPS;
typedef struct DDSURFACEDESC					*LPDDSURFACEDESC;
typedef struct DDCAPS							*LPDDCAPS;
#	if !defined(__PALETTEENTRY__)
struct PALETTEENTRY;
typedef struct PALETTEENTRY						*LPPALETTEENTRY;
#	endif	// !defined(__PALETTEENTRY__)


#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HRESULT WINAPI DirectDrawCreate(GUID *lpGUID, LPDIRECTDRAW *lplpDD, IUnknown *pUnkOuter);
HRESULT WINAPI DirectDrawCreateEx(GUID *lpGUID, LPVOID *lplpDD, REFIID iid, IUnknown *pUnkOuter);

#	if defined(_BUILTIN_DLL)
void *DDraw_GetAddressByOrder(int order);
void *DDraw_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__DDraw_h__)
