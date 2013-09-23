/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DSound.cpp,v 1.1 2003/05/01 03:03:56 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DSound.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "DSound.h"
#include "HResult.h"
#include "Win32Trace.h"

HRESULT WINAPI
DirectSoundCreate
(GUID *lpGUID, LPDIRECTSOUND *lplpDS, IUnknown *pUnkOuter)
{
	HRESULT rc = E_NOTIMPL;
	WIN32API_ENTER("HRESULT", "DirectSoundCreate", "GUID *", lpGUID, "LPDIRECTSOUND *", lplpDS, "IUnknown *", pUnkOuter, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	DSound_GetAddressByOrder
#	define	GetAddressByName	DSound_GetAddressByName

#	include "DSound/GetAddressByOrder.h"
#	include "DSound/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
