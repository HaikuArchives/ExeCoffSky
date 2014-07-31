/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DirectDraw.cpp,v 1.1 2003/05/01 03:02:38 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DirectDraw.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "DirectDraw.h"
#include "Win32Trace.h"
#include "HResult.h"
#include "DDError.h"

DirectDraw::DirectDraw
(void):
ref(0)
{
}

DirectDraw::~DirectDraw
(void)
{
}

HRESULT STDCALL
DirectDraw::QueryInterface
(IN REFIID riid,
 OUT LPVOID *ppvObject)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

ULONG STDCALL
DirectDraw::AddRef
(VOID)
{
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	Lock();
	ULONG rc = ref;
	ref++;
	Unlock();
	WIN32API_LEAVE(rc);
	return rc;
}

ULONG STDCALL
DirectDraw::Release
(VOID)
{
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	ULONG rc = ref;
	ref--;
	Unlock();
	WIN32API_LEAVE(rc);
	if (1 != ref) return rc;
	return Delete(this);
}

ULONG
DirectDraw::Delete
(DirectDraw *obj)
{
	delete obj;
	return 1;
}

HRESULT STDCALL
DirectDraw::Compact
(VOID)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::CreateClipper
(IN DWORD dwFlags,
 OUT LPDIRECTDRAWCLIPPER FAR *lplpDDClipper,
 OUT IUnknown FAR *pUnkOuter)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::CreatePalette
(IN DWORD dwFlags,
 IN LPPALETTEENTRY lpDDColorArray,
 OUT LPDIRECTDRAWPALETTE FAR *lplpDDPalette,
 OUT IUnknown FAR *pUnkOuter)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::CreateSurface
(IN LPDDSURFACEDESC lpDDSurfaceDesc,
 OUT LPDIRECTDRAWSURFACE FAR *lpDDSurface,
 OUT IUnknown FAR *pUnkOuter)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::DuplicateSurface
(IN LPDIRECTDRAWSURFACE lpDDSurface,
 OUT LPDIRECTDRAWSURFACE FAR *lplpDupDDSurface)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::EnumDisplayModes
(IN DWORD dwFlags,
 IN LPDDSURFACEDESC lpDDSurfaceDesc,
 IN LPVOID lpContext,
 IN LPDDENUMMODESCALLBACK lpEnumModesCallback)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::EnumSurfaces
(IN DWORD dwFlags,
 IN LPDDSURFACEDESC lpDDSurfaceDesc,
 IN LPVOID lpContext,
 IN LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::FlipToGDISurface
(VOID)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetCaps
(OUT LPDDCAPS lpDDDriverCaps,
 OUT LPDDCAPS lpDDHelCaps)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetDisplayMode
(OUT LPDDSURFACEDESC lpDDSurfaceDesc)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetFourCCCodes
(IN OUT LPDWORD lpNumCodes,
 OUT LPDWORD lpCodes)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetGDISurface
(OUT LPDIRECTDRAWSURFACE FAR *lplpGDIDDSSurface)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetMonitorFrequency
(OUT LPDWORD lpdwFrequency)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetScanLine
(OUT LPDWORD lpdwScanLine)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::GetVerticalBlankStatus
(OUT LPBOOL lpbIsInVB)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::Initialize
(IN GUID FAR *lpGUID)
{
	HRESULT rc = NOERROR;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_INFO("QueryInterface = %p\n", &DirectDraw::QueryInterface);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::RestoreDisplayMode
(VOID)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::SetCooperativeLevel
(IN HWND hWnd,
 IN DWORD dwFlags)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::SetDisplayMode
(IN DWORD dwWidth,
 IN DWORD dwHeight,
 IN DWORD dwBPP)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT STDCALL
DirectDraw::WaitForVerticalBlank
(IN DWORD dwFlags,
 IN HANDLE hEvent)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER(__PRETTY_FUNCTION__, NULL);
	WIN32API_LEAVE(rc);
	return rc;
}
