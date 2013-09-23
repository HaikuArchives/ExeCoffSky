/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: IDirectDraw.h,v 1.1 2003/05/01 03:02:38 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [IDirectDraw.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__IDirectDraw_h__)
#	define	__IDirectDraw_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__COM_h__)
#		include "COM.h"
#	endif	// !defined(__COM_h__)

#	if !defined(__IUnknown_h__)
#		include "IUnknown.h"
#	endif	// !defined(__IUnknown_h__)

#	if !defined(__DDraw_h__)
#		include "DDraw.h"
#	endif	// !defined(__DDraw_h__)

typedef void *LPDDENUMMODESCALLBACK;
typedef void *LPDDENUMSURFACESCALLBACK;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

interface IDirectDraw: public IUnknown {
	BEGIN_INTERFACE
/*
	// IUnknown
	STDMETHOD(QueryInterface)(
		IN REFIID riid,
		OUT LPVOID *ppvObject) PURE;
	STDMETHOD_(ULONG, AddRef)(
		VOID) PURE;
	STDMETHOD_(ULONG, Release)(
		VOID) PURE;
*/
	// IDirectDraw
	STDMETHOD(Compact)(
		VOID) PURE;
	STDMETHOD(CreateClipper)(
		IN DWORD dwFlags,
		OUT LPDIRECTDRAWCLIPPER FAR *lplpDDClipper,
		OUT IUnknown FAR *pUnkOuter) PURE;
	STDMETHOD(CreatePalette)(
		IN DWORD dwFlags,
		IN LPPALETTEENTRY lpDDColorArray,
		OUT LPDIRECTDRAWPALETTE FAR *lplpDDPalette,
		OUT IUnknown FAR *pUnkOuter) PURE;
	STDMETHOD(CreateSurface)(
		IN LPDDSURFACEDESC lpDDSurfaceDesc,
		OUT LPDIRECTDRAWSURFACE FAR *lpDDSurface,
		OUT IUnknown FAR *pUnkOuter) PURE;
	STDMETHOD(DuplicateSurface)(
		IN LPDIRECTDRAWSURFACE lpDDSurface,
		OUT LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface) PURE;
	STDMETHOD(EnumDisplayModes)(
		IN DWORD dwFlags,
		IN LPDDSURFACEDESC lpDDSurfaceDesc,
		IN LPVOID lpContext,
		IN LPDDENUMMODESCALLBACK lpEnumModesCallback) PURE;
	STDMETHOD(EnumSurfaces)(
		IN DWORD dwFlags,
		IN LPDDSURFACEDESC lpDDSurfaceDesc,
		IN LPVOID lpContext,
		IN LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) PURE;
	STDMETHOD(FlipToGDISurface)(
		VOID) PURE;
	STDMETHOD(GetCaps)(
		OUT LPDDCAPS lpDDDriverCaps,
		OUT LPDDCAPS lpDDHelCaps) PURE;
	STDMETHOD(GetDisplayMode)(
		OUT LPDDSURFACEDESC lpDDSurfaceDesc) PURE;
	STDMETHOD(GetFourCCCodes)(
		IN OUT LPDWORD lpNumCodes,
		OUT LPDWORD lpCodes) PURE;
	STDMETHOD(GetGDISurface)(
		OUT LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface) PURE;
	STDMETHOD(GetMonitorFrequency)(
		OUT LPDWORD lpdwFrequency) PURE;
	STDMETHOD(GetScanLine)(
		OUT LPDWORD lpdwScanLine) PURE;
	STDMETHOD(GetVerticalBlankStatus)(
		OUT LPBOOL lpbIsInVB) PURE;
	STDMETHOD(Initialize)(
		GUID FAR *lpGIUD) PURE;
	STDMETHOD(RestoreDisplayMode)(
		VOID) PURE;
	STDMETHOD(SetCooperativeLevel)(
		IN HWND hWnd,
		IN DWORD dwFlags) PURE;
	STDMETHOD(SetDisplayMode)(
		IN DWORD dwWidth,
		IN DWORD dwHeight,
		IN DWORD dwBPP) PURE;
	STDMETHOD(WaitForVerticalBlank)(
		IN DWORD dwFlags,
		IN HANDLE hEvent) PURE;
	END_INTERFACE
};

#	if !defined(__IDirectDraw__)
#		define	__IDirectDraw__
#	endif	// !defined(__IDirectDraw__)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__IDirectDraw_h__)
