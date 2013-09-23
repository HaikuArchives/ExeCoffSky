/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: load_dll.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [load_dll.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__load_dll_h__)
#	define	__load_dll_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

#	if !defined(LD_DLL)
#		define	LD_DLL	__declspec(dllimport)
#	endif	// !defined(LD_DLL)

LD_DLL void ShiftProcess(const char *path, bool dynreloc = false);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__load_dll_h__)
