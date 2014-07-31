/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Atom.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Atom.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Atom_h__)
#	define	__Atom_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

ATOM WINAPI AddAtomA(LPCSTR);
ATOM WINAPI AddAtomW(LPCWSTR);
ATOM WINAPI DeleteAtom(ATOM);
ATOM WINAPI FindAtomA(LPCSTR);
ATOM WINAPI FindAtomW(LPCWSTR);
UINT WINAPI GetAtomNameA(ATOM, LPSTR, int);
UINT WINAPI GetAtomNameW(ATOM, LPWSTR, int);
BOOL WINAPI InitAtomTable(DWORD);
ATOM WINAPI GlobalAddAtomA(LPCSTR);
ATOM WINAPI GlobalAddAtomW(LPCWSTR);
ATOM WINAPI GlobalDeleteAtom(ATOM);
ATOM WINAPI GlobalFindAtomA(LPCSTR);
ATOM WINAPI GlobalFindAtomW(LPCWSTR);
UINT WINAPI GlobalGetAtomNameA(ATOM, LPSTR, int);
UINT WINAPI GlobalGetAtomNameW(ATOM, LPWSTR, int);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Atom_h__)
