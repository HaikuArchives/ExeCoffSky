/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: MessageBox.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [MessageBox.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__MessageBox_h__)
#	define	__MessageBox_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	MB_OK				0x00000000L
#	define	MB_OKCANCEL			0x00000001L
#	define	MB_ABORTRETRYIGNORE	0x00000002L
#	define	MB_YESNOCANCEL		0x00000003L
#	define	MB_YESNO			0x00000004L
#	define	MB_RETRYCANCEL		0x00000005L

#	define	MB_ICONHAND			0x00000010L	// X
#	define	MB_ICONQUESTION		0x00000020L	// ?
#	define	MB_ICONEXCLAMATION	0x00000030L	// !
#	define	MB_ICONASTERISK		0x00000040L	// i

#	define	MB_DEFBUTTON1		0x00000000L
#	define	MB_DEFBUTTON2		0x00000100L
#	define	MB_DEFBUTTON3		0x00000200L
#	define	MB_DEFBUTTON4		0x00000300L

#	define	MB_APPMODAL			0x00000000L
#	define	MB_SYSTEMMODAL		0x00001000L
#	define	MB_TASKMODAL		0x00002000L

#	define	MB_IDOK				1
#	define	MB_IDCANCEL			2
#	define	MB_IDABORT			3
#	define	MB_IDRETRY			4
#	define	MB_IDIGNORE			5
#	define	MB_IDYES			6
#	define	MB_IDNO				7

typedef struct tagMSGBOXPARAMSA {
} MSGBOXPARAMSA, *LPMSGBOXPARAMSA;

typedef struct tagMSGBOXPARAMSW {
} MSGBOXPARAMSW, *LPMSGBOXPARAMSW;

static int MessageBoxU(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
int WINAPI MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);
int WINAPI MessageBoxExA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType, WORD wLanguageId);
int WINAPI MessageBoxExW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType, WORD wLanguageId);
int WINAPI MessageBoxIndirectA(LPMSGBOXPARAMSA lpMsgBoxParams);
int WINAPI MessageBoxIndirectW(LPMSGBOXPARAMSW lpMsgBoxParams);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__MessageBox_h__)
