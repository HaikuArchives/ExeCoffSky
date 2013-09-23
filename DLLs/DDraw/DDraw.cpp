/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DDraw.cpp,v 1.1 2003/05/01 03:02:38 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DDraw.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "DDraw.h"
#include "DirectDraw.h"
#include "Win32Trace.h"
#include "HResult.h"
#include "COM.h"

HRESULT WINAPI
DirectDrawCreate
(GUID *lpGUID, LPDIRECTDRAW *lplpDD, IUnknown *pUnkOuter)
{
	HRESULT rc = E_OUTOFMEMORY;
	WIN32API_ENTER("HRESULT", "DirectDrawCreate", "GUID *", lpGUID, "LPDIRECTDRAW *", lplpDD, "IUnknown *", pUnkOuter, NULL);
	if (NULL != lpGUID) WIN32API_GUID("guid", lpGUID);
	IDirectDraw *ddraw = new DirectDraw();
	if (NULL == ddraw) {
		*lplpDD = NULL;
	} else {
		rc = ddraw->Initialize(lpGUID);
		if (SUCCEEDED(rc)) {
			ddraw->AddRef();
			*lplpDD = (LPDIRECTDRAW)ddraw;
		} else {
			delete ddraw;
		}
	}
	unsigned long *p = *(unsigned long **)ddraw;
	for (int i = 0; i < 16; i++) {
		WIN32API_INFO("\t%3d: %p\n", i, p[i]);
	}
	WIN32API_INFO("\tlplpDD = %p\n", *lplpDD);
	WIN32API_LEAVE(rc);
	return rc;
}

HRESULT WINAPI
DirectDrawCreateEx
(GUID *lpGUID, LPVOID *lplpDD, REFIID iid, IUnknown *pUnkOuter)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER("HRESULT", "DirectDrawCreateEx", "GUID *", lpGUID, "LPVOID *", lplpDD, "REFIID", iid, "IUnknown *", pUnkOuter, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	DDraw_GetAddressByOrder
#	define	GetAddressByName	DDraw_GetAddressByName

#	include "DDraw/GetAddressByOrder.h"
#	include "DDraw/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
