/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: ComDlg32.h,v 1.1 2003/05/01 02:58:34 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ComDlg32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__ComDlg32_h__)
#	define	__ComDlg32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

typedef void *LPCHOOSECOLORA;
typedef void *LPCHOOSECOLORW;
typedef void *LPCHOOSEFONTA;
typedef void *LPCHOOSEFONTW;
typedef void *LPFINDREPLACEA;
typedef void *LPFINDREPLACEW;
typedef void *LPOPENFILENAMEA;
typedef void *LPOPENFILENAMEW;
typedef void *LPPAGESETUPDLGA;
typedef void *LPPAGESETUPDLGW;
typedef void *LPPRINTDLGA;
typedef void *LPPRINTDLGW;
typedef void *LPFINDREPLACEA;
typedef void *LPFINDREPLACEW;

#	if !defined(APIENTRY)
#		define	APIENTRY	WINAPI
#	endif	// !defined(APIENTRY)

BOOL APIENTRY ChooseColorA(LPCHOOSECOLORA);
BOOL APIENTRY ChooseColorW(LPCHOOSECOLORW);
BOOL APIENTRY ChooseFontA(LPCHOOSEFONTA);
BOOL APIENTRY ChooseFontW(LPCHOOSEFONTW);
DWORD APIENTRY CommDlgExtendedError(VOID);
HWND APIENTRY FindTextA(LPFINDREPLACEA);
HWND APIENTRY FindTextW(LPFINDREPLACEW);
short APIENTRY GetFileTitleA(LPCSTR, LPSTR, WORD);
short APIENTRY GetFileTitleW(LPCWSTR, LPWSTR, WORD);
BOOL APIENTRY GetOpenFileNameA(LPOPENFILENAMEA);
BOOL APIENTRY GetOpenFileNameW(LPOPENFILENAMEW);
BOOL APIENTRY GetSaveFileNameA(LPOPENFILENAMEA);
BOOL APIENTRY GetSaveFileNameW(LPOPENFILENAMEW);
BOOL APIENTRY PageSetupDlgA(LPPAGESETUPDLGA);
BOOL APIENTRY PageSetupDlgW(LPPAGESETUPDLGW);
BOOL APIENTRY PrintDlgA(LPPRINTDLGA);
BOOL APIENTRY PrintDlgW(LPPRINTDLGW);
HWND APIENTRY ReplaceTextA(LPFINDREPLACEA);
HWND APIENTRY ReplaceTextW(LPFINDREPLACEW);

#	if defined(_BUILTIN_DLL)
void *ComDlg32_GetAddressByOrder(int order);
void *ComDlg32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__ComDlg32_h__)
