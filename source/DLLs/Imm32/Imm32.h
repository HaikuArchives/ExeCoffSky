/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Imm32.h,v 1.1 2003/05/01 03:30:54 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Imm32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Imm32_h__)
#	define	__Imm32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__Win32FontStructures_h__)
#		include "Win32FontStructures.h"
#	endif	// !defined(__Win32FontStructures_h__)

typedef void *REGISTERWORDENUMPROCA;
typedef void *REGISTERWORDENUMPROCW;
struct CANDIDATELIST;
typedef CANDIDATELIST *LPCANDIDATELIST;
struct CANDIDATEFORM;
typedef CANDIDATEFORM *LPCANDIDATEFORM;
struct COMPOSITIONFORM;
typedef COMPOSITIONFORM *LPCOMPOSITIONFORM;
struct IMEMENUITEMINFOA;
typedef IMEMENUITEMINFOA *LPIMEMENUITEMINFOA; 
struct IMEMENUITEMINFOW;
typedef IMEMENUITEMINFOW *LPIMEMENUITEMINFOW; 
struct STYLEBUFA;
typedef STYLEBUFA *LPSTYLEBUFA;
struct STYLEBUFW;
typedef STYLEBUFW *LPSTYLEBUFW;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HIMC WINAPI ImmAssociateContext(HWND, HIMC);
BOOL WINAPI ImmAssociateContextEx(HWND, HIMC, DWORD);
BOOL WINAPI ImmConfigureIMEA(HKL, HWND, DWORD, LPVOID);
BOOL WINAPI ImmConfigureIMEW(HKL, HWND, DWORD, LPVOID);
HIMC WINAPI ImmCreateContext(void);
BOOL WINAPI ImmDestroyContext(HIMC);
BOOL WINAPI ImmDisableIME(DWORD);
UINT WINAPI ImmEnumRegisterWordA(HKL, REGISTERWORDENUMPROCA, LPCSTR lpszReading, DWORD, LPCSTR lpszRegister, LPVOID);
UINT WINAPI ImmEnumRegisterWordW(HKL, REGISTERWORDENUMPROCW, LPCWSTR lpszReading, DWORD, LPCWSTR lpszRegister, LPVOID);
LRESULT WINAPI ImmEscapeA(HKL, HIMC, UINT, LPVOID);
LRESULT WINAPI ImmEscapeW(HKL, HIMC, UINT, LPVOID);
DWORD WINAPI ImmGetCandidateListA(HIMC, DWORD deIndex, LPCANDIDATELIST, DWORD dwBufLen);
DWORD WINAPI ImmGetCandidateListCountA(HIMC, LPDWORD lpdwListCount);
DWORD WINAPI ImmGetCandidateListCountW(HIMC, LPDWORD lpdwListCount);
DWORD WINAPI ImmGetCandidateListW(HIMC, DWORD deIndex, LPCANDIDATELIST, DWORD dwBufLen);
BOOL WINAPI ImmGetCandidateWindow(HIMC, DWORD, LPCANDIDATEFORM);
BOOL WINAPI ImmGetCompositionFontA(HIMC, LPLOGFONTA);
BOOL WINAPI ImmGetCompositionFontW(HIMC, LPLOGFONTW);
LONG WINAPI ImmGetCompositionStringA(HIMC, DWORD, LPVOID, DWORD);
LONG WINAPI ImmGetCompositionStringW(HIMC, DWORD, LPVOID, DWORD);
BOOL WINAPI ImmGetCompositionWindow(HIMC, LPCOMPOSITIONFORM);
HIMC WINAPI ImmGetContext(HWND);
DWORD WINAPI ImmGetConversionListA(HKL, HIMC, LPCSTR, LPCANDIDATELIST, DWORD dwBufLen, UINT uFlag);
DWORD WINAPI ImmGetConversionListW(HKL, HIMC, LPCWSTR, LPCANDIDATELIST, DWORD dwBufLen, UINT uFlag);
BOOL WINAPI ImmGetConversionStatus(HIMC, LPDWORD, LPDWORD);
HWND WINAPI ImmGetDefaultIMEWnd(HWND);
UINT WINAPI ImmGetDescriptionA(HKL, LPSTR, UINT uBufLen);
UINT WINAPI ImmGetDescriptionW(HKL, LPWSTR, UINT uBufLen);
DWORD WINAPI ImmGetGuideLineA(HIMC, DWORD dwIndex, LPSTR, DWORD dwBufLen);
DWORD WINAPI ImmGetGuideLineW(HIMC, DWORD dwIndex, LPWSTR, DWORD dwBufLen);
UINT WINAPI ImmGetIMEFileNameA(HKL, LPSTR, UINT uBufLen);
UINT WINAPI ImmGetIMEFileNameW(HKL, LPWSTR, UINT uBufLen);
DWORD WINAPI ImmGetImeMenuItemsA(HIMC, DWORD, DWORD, LPIMEMENUITEMINFOA, LPIMEMENUITEMINFOA, DWORD);
DWORD WINAPI ImmGetImeMenuItemsW(HIMC, DWORD, DWORD, LPIMEMENUITEMINFOW, LPIMEMENUITEMINFOW, DWORD);
BOOL WINAPI ImmGetOpenStatus(HIMC);
DWORD WINAPI ImmGetProperty(HKL, DWORD);
UINT WINAPI ImmGetRegisterWordStyleA(HKL, UINT nItem, LPSTYLEBUFA);
UINT WINAPI ImmGetRegisterWordStyleW(HKL, UINT nItem, LPSTYLEBUFW);
BOOL WINAPI ImmGetStatusWindowPos(HIMC, LPPOINT);
UINT WINAPI ImmGetVirtualKey(HWND);
HKL WINAPI ImmInstallIMEA(LPCSTR lpszIMEFileName, LPCSTR lpszLayoutText);
HKL WINAPI ImmInstallIMEW(LPCWSTR lpszIMEFileName, LPCWSTR lpszLayoutText);
BOOL WINAPI ImmIsIME(HKL);
BOOL WINAPI ImmIsUIMessageA(HWND, UINT, WPARAM, LPARAM);
BOOL WINAPI ImmIsUIMessageW(HWND, UINT, WPARAM, LPARAM);
BOOL WINAPI ImmNotifyIME(HIMC, DWORD dwAction, DWORD dwIndex, DWORD dwValue);
BOOL WINAPI ImmRegisterWordA(HKL, LPCSTR lpszReading, DWORD, LPCSTR lpszRegister);
BOOL WINAPI ImmRegisterWordW(HKL, LPCWSTR lpszReading, DWORD, LPCWSTR lpszRegister);
BOOL WINAPI ImmReleaseContext(HWND, HIMC);
BOOL WINAPI ImmSetCandidateWindow(HIMC, LPCANDIDATEFORM);
BOOL WINAPI ImmSetCompositionFontA(HIMC, LPLOGFONTA);
BOOL WINAPI ImmSetCompositionFontW(HIMC, LPLOGFONTW);
BOOL WINAPI ImmSetCompositionStringA(HIMC, DWORD dwIndex, LPCVOID lpComp, DWORD, LPCVOID lpRead, DWORD);
BOOL WINAPI ImmSetCompositionStringW(HIMC, DWORD dwIndex, LPCVOID lpComp, DWORD, LPCVOID lpRead, DWORD);
BOOL WINAPI ImmSetCompositionWindow(HIMC, LPCOMPOSITIONFORM);
BOOL WINAPI ImmSetConversionStatus(HIMC, DWORD, DWORD);
BOOL WINAPI ImmSetOpenStatus(HIMC, BOOL);
BOOL WINAPI ImmSetStatusWindowPos(HIMC, LPPOINT);
BOOL WINAPI ImmSimulateHotKey(HWND, DWORD);
BOOL WINAPI ImmUnregisterWordA(HKL, LPCSTR lpszReading, DWORD, LPCSTR lpszUnregister);
BOOL WINAPI ImmUnregisterWordW(HKL, LPCWSTR lpszReading, DWORD, LPCWSTR lpszUnregister);

#	if defined(_BUILTIN_DLL)
void *Imm32_GetAddressByOrder(int order);
void *Imm32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Imm32_h__)
