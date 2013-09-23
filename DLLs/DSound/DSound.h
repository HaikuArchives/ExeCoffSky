/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: DSound.h,v 1.1 2003/05/01 03:03:56 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [DSound.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__DSound_h__)
#	define	__DSound_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__COM_h__)
#		include "COM.h"
#	endif	// !defined(__COM_h__)

struct IUnknown;
struct IDirectSound;

typedef struct IDirectSound	*LPDIRECTSOUND;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HRESULT WINAPI DirectSoundCreate(GUID *lpGUID, LPDIRECTSOUND *ppDS, IUnknown *pUnkOuter);

#	if defined(_BUILTIN_DLL)
void *DSound_GetAddressByOrder(int order);
void *DSound_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__DSound_h__)
