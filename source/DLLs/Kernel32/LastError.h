/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: LastError.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [LastError.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__LastError_h__)
#	define	__LastError_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

DWORD WINAPI GetLastError(VOID);
VOID WINAPI SetLastError(DWORD dwErrCode);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__LastError_h__)
