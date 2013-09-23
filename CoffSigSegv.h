/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: CoffSigSegv.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [CoffSigSegv.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__CoffSigSegv_h__)
#	define	__CoffSigSegv_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

extern "C" void CoffSigSegv(int no, void *user, vregs *regs);

typedef struct _xxxregs {
	unsigned long edi;
	unsigned long esi;
	unsigned long ebx;
} xxxregs;

#endif	// !defined(__CoffSigSegv_h__)
