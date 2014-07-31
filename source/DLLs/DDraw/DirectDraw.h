/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DirectDraw.h,v 1.1 2003/05/01 03:02:38 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DirectDraw.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__DirectDraw_h__)
#	define	__DirectDraw_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__COM_h__)
#		include "COM.h"
#	endif	// !defined(__COM_h__)

#	if !defined(__IDirectDraw_h__)
#		include "IDirectDraw.h"
#	endif	// !defined(__IDirectDraw_h__)

#	if defined(__cplusplus)

class DirectDraw: public IDirectDraw {
private:
	int ref;
	BLocker lock;
public:
	DirectDraw(void);
	virtual ~DirectDraw(void);
	
	inline void Lock(void) { lock.Lock(); };
	inline void Unlock(void) { lock.Unlock(); };
	
	static ULONG Delete(DirectDraw *obj);
	
	// IUnknown
	STDMETHOD(QueryInterface)(
		IN REFIID riid,
		OUT LPVOID *ppvObject);
	STDMETHOD_(ULONG, AddRef)(
		VOID);
	STDMETHOD_(ULONG, Release)(
		VOID);

	// IDirectDraw
	STDMETHOD(Compact)(
		VOID);
	STDMETHOD(CreateClipper)(
		IN DWORD dwFlags,
		OUT LPDIRECTDRAWCLIPPER FAR *lplpDDClipper,
		OUT IUnknown FAR *pUnkOuter);
	STDMETHOD(CreatePalette)(
		IN DWORD dwFlags,
		IN LPPALETTEENTRY lpDDColorArray,
		OUT LPDIRECTDRAWPALETTE FAR *lplpDDPalette,
		OUT IUnknown FAR *pUnkOuter);
	STDMETHOD(CreateSurface)(
		IN LPDDSURFACEDESC lpDDSurfaceDesc,
		OUT LPDIRECTDRAWSURFACE FAR *lpDDSurface,
		OUT IUnknown FAR *pUnkOuter);
	STDMETHOD(DuplicateSurface)(
		IN LPDIRECTDRAWSURFACE lpDDSurface,
		OUT LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface);
	STDMETHOD(EnumDisplayModes)(
		IN DWORD dwFlags,
		IN LPDDSURFACEDESC lpDDSurfaceDesc,
		IN LPVOID lpContext,
		IN LPDDENUMMODESCALLBACK lpEnumModesCallback);
	STDMETHOD(EnumSurfaces)(
		IN DWORD dwFlags,
		IN LPDDSURFACEDESC lpDDSurfaceDesc,
		IN LPVOID lpContext,
		IN LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback);
	STDMETHOD(FlipToGDISurface)(
		VOID);
	STDMETHOD(GetCaps)(
		OUT LPDDCAPS lpDDDriverCaps,
		OUT LPDDCAPS lpDDHelCaps);
	STDMETHOD(GetDisplayMode)(
		OUT LPDDSURFACEDESC lpDDSurfaceDesc);
	STDMETHOD(GetFourCCCodes)(
		IN OUT LPDWORD lpNumCodes,
		OUT LPDWORD lpCodes);
	STDMETHOD(GetGDISurface)(
		OUT LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface);
	STDMETHOD(GetMonitorFrequency)(
		OUT LPDWORD lpdwFrequency);
	STDMETHOD(GetScanLine)(
		OUT LPDWORD lpdwScanLine);
	STDMETHOD(GetVerticalBlankStatus)(
		OUT LPBOOL lpbIsInVB);
	STDMETHOD(Initialize)(
		IN GUID FAR *lpGIUD);
	STDMETHOD(RestoreDisplayMode)(
		VOID);
	STDMETHOD(SetCooperativeLevel)(
		IN HWND hWnd,
		IN DWORD dwFlags);
	STDMETHOD(SetDisplayMode)(
		IN DWORD dwWidth,
		IN DWORD dwHeight,
		IN DWORD dwBPP);
	STDMETHOD(WaitForVerticalBlank)(
		IN DWORD dwFlags,
		IN HANDLE hEvent);
};

#	if !defined(__DirectDraw__)
#		define	__DirectDraw__
#	endif	// !defined(__DirectDraw__)

#	endif	// defined(__cplusplus)

#endif	// !defined(__DirectDraw_h__)
