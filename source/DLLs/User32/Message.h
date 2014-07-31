/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Message.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Message.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Message_h__)
#	define	__Message_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	define	PM_NOREMOVE	0
#	define	PM_REMOVE	1
#	define	PM_NOYIELD	2

static BOOL GetMessageU(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
static BOOL PeekMessageU(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
static BOOL PostMessageU(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
static LRESULT SendMessageU(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
static BOOL PostThreadMessageU(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

long WINAPI BroadcastSystemMessage(DWORD dwFlags, LPDWORD lpdwRecipients, UINT uiMessage, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI DispatchMessageA(LPCMSG lpMsg);
LRESULT WINAPI DispatchMessageW(LPCMSG lpMSG);
BOOL WINAPI GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL WINAPI GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
LONG WINAPI GetMessageExtraInfo(void);
DWORD WINAPI GetMessagePos(void);
LONG WINAPI GetMessageTime(void);
BOOL WINAPI InSendMessage(VOID);
BOOL WINAPI PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL WINAPI PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL WINAPI PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
VOID WINAPI PostQuitMessage(int nExitCode);
BOOL WINAPI PostThreadMessageA(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI PostThreadMessageW(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI ReplyMessage(LRESULT lResult);
LRESULT WINAPI SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI SendMessageCallbackA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpCallback, DWORD dwData);
BOOL WINAPI SendMessageCallbackW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpCallback, DWORD dwData);
LRESULT WINAPI SendMessageTimeoutA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD lpdwResult);
LRESULT WINAPI SendMessageTimeoutW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD lpdwResult);
BOOL WINAPI SendNotifyMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI SendNotifyMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LPARAM WINAPI SetMessageExtraInfo(LPARAM lParam);
BOOL WINAPI SetMessageQueue(int iSize);
BOOL WINAPI TranslateMessage(LPCMSG lpMsg);
BOOL WINAPI WaitMessage(void);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Message_h__)
