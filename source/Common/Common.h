/* --------------------------------------------------------------------------------------------
 *  Pop'n Pop - hotmail to pop3 gateway -
 *  EL-POINT subset version for KARIHITO (C) Grains
 *  ウェブ・サインアップ (C) ACENET, Inc.
 *  music creative driver for Win32 (Netscape Plug-in / WinAmp Plug-in) / BeOS
 *  LwXML - Light weight XML Library -
 *  WinTCPd - Tiny TCP daemon for Win32
 *  ChatRoomServer / ReferenceClient(chat-in) (C) Digital Arts
 *  Meta Gassee - Meta Gate clone for BeOS -
 *  Trance Palrance - WonderWitch TransMagic clone for BeOS -
 *  Asacot2 for Win32 / MacOS (C) ACENET, Inc.
 *  MisuzuWebServer - a httpd for BeOS -
 *  ExeCoffSky for BeOS
 *  MMFake for Win2k / WINMM.DLL compat. Library
 *  Xexex - Incorporated X Server - for BeOS
 *  寿司絵 - GraphicLoader with ECS x SPI for BeOS -
 *  ICO Translator for BeOS
 *  El-Point
 *  ぽえみ for PocketPC
 *  箱入り娘。
 *  (C) 1999 - 2003 とよしま
 *  $Id: Common.h,v 1.2 2003/05/11 15:47:13 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Common.h]
 *   共通にインクルードされる。
 *  主にデバッグ用のトリックが中心。メインルーチンの実装時には__Main__を定義してインクルード
 *  すると、デバッグルーチンの実装が取り込まれる。
 *  VisualC++用に特化されているが、逆にこのファイルを修正するだけで他の環境でもコンパイル可能。
 *  DOUT系メッセージはデバッガ等から拾うことができるが、www.sysinternals.com のDebugViewを
 *  使うと目から鱗。
 *  メインルーチンを抜ける際は、exitを使うこと。その際デバッグ用のコードでは、開放し忘れている
 *  メモリをチェックし、必要な情報をダンプしてくれる。
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Common_h__)
#	define	__Common_h__

#	if !defined(__WIN32__) && defined(_WIN32_WCE)
#		define	__WIN32__
#		define	__WINCE__
#		define	_NODEBUGNEW
#		if defined(DEBUG) && !defined(_DEBUG)
#			define _DEBUG
#		endif	// defined(DEBUG) && !defined(_DEBUG)
#	endif	// !defined(__WIN32__) && defined(_WIN32_WCE)

#   if !defined(__WIN32__) && (defined(_WIN32) || defined(__CYGWIN__))
#       define  __WIN32__
#   endif   // !defined(__WIN32__) && (defined(_WIN32) || defined(__CYGWIN__))

#   if !defined(__VISUALC__) && defined(_MSC_VER)
#       define  __VISUALC__
#   endif   // !defined(__VISUALC__) && defined(_MSC_VER)

#	if defined(macintosh)
#		define	__MACOS__
#	endif	// !defined(macintosh)

#	if defined(__palmos__)
#		define __PALMOS__
#	endif	// !defined(__palmos__)

//
// 標準インクルードファイル
// （VisualC++のためのデバッグ用トリックあり）
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(HAVE_CONFIG_H)
#		include "config.h"
#	endif	// defined(HAVE_CONFIG_H)
#	include <stdio.h>
#	if defined(__VISUALC__) && defined(_DEBUG)
#		define	_CRTDBG_MAP_ALLOC
#	endif	// defined(__VISUALC__) && defined(_DEBUG)
#	include <stdlib.h>
#	if defined(__VISUALC__) && defined(_DEBUG) && !defined(__WINCE__)
#		include <crtdbg.h>
#	endif	// defined(__VISUALC__) && defined(_DEBUG) && !defined(__WINCE__)
//#	include <stdarg.h>
#	if !defined(__PALMOS__)
#		include <string.h>
#		include <math.h>
#	endif	// !defined(__PALMOS__)
#	if !defined(__WINCE__) && !defined(__PALMOS__)
#		include <fcntl.h>
#		include <time.h>
#	endif	// !defined(__WINCE__) && !defined(__PALMOS__)
#	if defined(__CYGWIN__) || defined(__BEOS__)
#		include <errno.h>
#	endif	// defined(__CYGWIN__)
#	if !defined(__PALMOS__)
#		include <ctype.h>
#	endif	// !defined(__PALMOS__)

#	if !defined(__WIN32__) && !defined(__PALMOS__)
#		include <unistd.h>
#	endif	// !defined(__WIN32__) && !defined(__PALMOS__)

#	if !defined(__MACOS__) && !defined(__WINCE__) && !defined(__MWERKS__) && !defined(__PALMOS__)
#		include <sys/types.h>
#		include <sys/stat.h>
#	endif	// !defined(__MACOS__) && !defined(__WINCE__) && !defined(__MWERKS__) && !defined(__PALMOS__)

#	if defined(__BEOS__) || (defined(HAVE_CONFIG_H) && defined(HAVE_GETOPT_H))
#		include <getopt.h>
#	endif	// defined(__BEOS__) || (defined(HAVE_CONFIG_H) && defined(HAVE_GETOPT_H))

#	if defined(__MWERKS__) || defined(__CYGWIN__)
#		include <wchar.h>
#	endif	// defined(__MWERKS__) || defined(__CYGWIN__)

#	if defined(__CYGWIN__)
#		include <varargs.h>
#	endif	// defined(__CYGWIN__)

//
// Windows用特殊定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__WIN32__) && !defined(__WINCE__)
//
// VisualC++用 build 時間短縮のトリック
#		if defined(__VISUALC__)
#			if !defined(WIN32_LEAN_AND_MEAN)
#				define	WIN32_LEAN_AND_MEAN
#			endif	// !defined(WIN32_LEAN_AND_MEAN)
#		endif	// defined(__VISUALC__)

//
// Windows バージョン宣言
#		if defined(_WIN32_IE)
#			undef	_WIN32_IE
#		endif	// defined(_WIN32_IE)
#		define	_WIN32_IE	    0x0300
#       define  _WIN32_WINNT    0x0400
#		define	WINVER		    0x0400

//
// Windows インクルード
// （マクロだけWinSock2を使うトリックあり）
#		define _WINSOCKAPI_
#		include <windows.h>
#		include <windowsx.h>
#		undef	_WINSOCKAPI_
#		if !defined(__CYGWIN__)
#			include <winsock2.h>
#		endif	// !defined(__CYGWIN__)
#		include <mmsystem.h>
#		include <ras.h>
#		include <raserror.h>
#		include <shellapi.h>
#		include <commdlg.h>

//
// DirectX バージョン宣言
#		define	DIRECTDRAW_VERSION		0x0300
#		define	DIRECTSOUND_VERSION		0x0300

//
// DirectX インクルード
#		if !defined(NOUSE_DIRECTX)
#			include <ddraw.h>
#			include <dsound.h>
#		endif	// !defined(NOUSE_DIRECTX)

#	endif	// defined(__WIN32__) && !defined(__WINCE__)

//
// WindowsCE用特殊定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__WIN32__) && defined(__WINCE__)
//
// VisualC++用 build 時間短縮のトリック
#		if defined(__VISUALC__)
#			if !defined(WIN32_LEAN_AND_MEAN)
#				define	WIN32_LEAN_AND_MEAN
#			endif	// !defined(WIN32_LEAN_AND_MEAN)
#		endif	// defined(__VISUALC__)

//
// Windows インクルード
#		include <windows.h>
#		include <windowsx.h>
#		include <mmsystem.h>
#		include <ras.h>
#		include <raserror.h>
#		include <shellapi.h>
#		include <commdlg.h>
#		include <winnls.h>

#		if !defined(ZeroMemory)
#			define	ZeroMemory(s, i)	memset(s, 0, i)
#		endif	// !defined(ZeroMemory)
#	endif	// defined(__WIN32__) && defined(__WINCE__)

//
// BeOS インクルード
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__BEOS__)
#		if defined(_COM_GUID)
#			define	GUID	BE_GUID
#		endif	// defined(_WIN32GUID)
#		include <storage/Path.h>
#		include <Be.h>
#		include <NetworkKit.h>
#		include <MidiRoster.h>
#		include <MidiProducer.h>
#		include <MidiConsumer.h>
#		if defined(_COM_GUID)
#			undef	GUID
#		endif	// defined(_COM_GUID)
#		if !defined(_NOUSE_BESOCKET)
#			include "BeSocket.h"
#		endif	// !defined(_NOUSE_BESOCKET)
#	endif	// defined(__BEOS__)

//
// Macintosh インクルード
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__MACOS__)
#		include <Windows.h>
#		include <Events.h>
#		include <Fonts.h>
#		include <Menus.h>
#		include <Dialogs.h>
#		include <TextEdit.h>
#		include <Types.h>
#		include <ToolUtils.h>
#		include <QuickDraw.h>
#		include <QuickdrawText.h>
#		include <unix.h>
#	endif	// defined(__MACOS__)

//
// PalmOS インクルード
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__PALMOS__)
#		include <PalmOS.h>
#		include <PalmCompatibility.h>
#	endif	// defined(__PALMOS__)

//
// VisualC++のための抽象クラスの最適化を助けるおまじない
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__VISUALC__)
#		define	abstract	__declspec(novtable)
#		pragma warning(disable: 4091)
#	else	// defined(__VISUALC__)
#		define	abstract
#	endif	// defined(__VISUALC__)

//
// 定数・型・マクロ定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if !defined(NULL)
#		if defined(__cplusplus)
#			define	NULL (0)
#		else	// defined(__cplusplus)
#			define	NULL ((void *)0)
#		endif	// defined(__cplusplus)
#	endif	// !defined(NULL)
#	if !defined(_MAX_PATH)
#		define	_MAX_PATH	(4096)
#	endif	// !defined(_MAX_PATH)
#	define	WIN32_MAX_PATH	260
#	if !defined(O_SHLOCK)
#		define	O_SHLOCK	(0)
#	endif	// !defined(O_SHLOCK)
#   define  NOUSE(v)    					(void)v;
#	if defined(__GNUC__) && !defined(__CYGWIN__)
#		define	PACKED(x)						x __attribute__ ((packed))
#	elif defined(__MWERKS__)
#		define	PACKED(x)						x
#	endif	// defined(__GNUC__) && !defined(__CYGWIN__)

#	define	STATIC_CAST(t, o)				static_cast<t>(o)
#	define	DYNAMIC_CAST(t, o)				dynamic_cast<t>(o)
#	define	REINTERPRET_CAST(t, o)			reinterpret_cast<t>(o)
#	define	CONST_CAST(t, o)				const_cast<t>(o)
#	define	CONST_REINTERPRET_CAST(t, o)	CONST_CAST(t, REINTERPRET_CAST(const t, o))
#	define	DYNAMIC_REINTERPRET_CAST(t, o)	DYNAMIC_CAST(t, REINTERPRET_CAST(t, o))

#	if defined(__WIN32__)
#		if !defined(EXPORT)
#			define	EXPORT							__declspec(dllexport)
#		endif	// !defined(EXPORT)
#		if !defined(IMPORT)
#			define	IMPORT							__declspec(dllimport)
#		endif	// !defined(IMPORT)
#	else	// defined(__WIN32__)
#		define	EXPORT
#		define	IMPORT
#	endif	// defined(__WIN32__)

//
// Windows系の定数・型・マクロ定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if !defined(__WIN32__)
typedef unsigned char BYTE, *PBYTE, *LPBYTE, UCHAR, *PUCHAR, *LPUCHAR;
typedef unsigned short WORD, *PWORD, *LPWORD, USHORT, *PUSHORT, *LPUSHORT, ATOM, LANGID;
typedef unsigned int WPARAM, *LPWPARAM, UINT, *PUINT, *LPUINT, MMRESULT, MCIDEVICEID, ALG_ID;
typedef unsigned long DWORD, *PDWORD, *LPDWORD, ULONG, *PULONG, *LPULONG, LRESULT, MCIERROR, ACCESS_MASK, REGSAM;
typedef DWORD LCID, LCTYPE, CALID, CALTYPE, FOURCC, COLORREF;
typedef unsigned long long QWORD, *PQWORD, *LPQWORD, ULONGLONG, *PULONGLONG, *LPULONGLONG;
typedef char CHAR, *PCHAR, *LPCHAR, STR, *PSTR, *LPSTR;
typedef short SHORT, *PSHORT, *LPSHORT, WCHAR, *PWCHAR, *LPWCHAR, WSTR, *PWSTR, *LPWSTR;
typedef long LONG, *PLONG, *LPLONG, LPARAM, *PLPARAM, *LPLPARAM, HRESULT;
typedef const char CSTR, *PCSTR, *LPCSTR;
typedef const short CWSTR, *PCWSTR, *LPCWSTR;
typedef void VOID, *PVOID, *LPVOID, UNKNOWN, *LPUNKNOWN;
typedef PVOID PSID;
typedef float FLOAT, *PFLOAT, *LPFLOAT;
typedef const void CVOID, *PCVOID, *LPCVOID;
typedef LPVOID HANDLE, *PHANDLE, *LPHANDLE;
typedef HANDLE HINSTANCE, HWND, HDC, HMODULE, HLOCAL, HGLOBAL;
typedef HANDLE HGDIOBJ, HPALETTE, HKEY, HMENU, HICON, HRSRC;
typedef HANDLE HCURSOR, HWAVEOUT, HBRUSH, HDROP, HFONT;
typedef HANDLE *LPHKEY, *PHKEY, *LPHWAVEOUT;
typedef HANDLE HKL, HDWP, HHOOK, HDESK, HWINSTA, HACCEL;
typedef HANDLE HSZ, HBITMAP, HCONV, HDDEDATA, HCONVLIST, HRGN;
typedef HANDLE HDRVR, HTASK, HMIDI, HMIDIOUT, *LPHMIDIOUT, HMIDIIN, *LPHMIDIIN;
typedef HANDLE HMIDISTRM, *LPHMIDISTRM, HMIXER, *LPHMIXER, HMIXEROBJ, HPSTR;
typedef HANDLE HWAVEIN, *LPHWAVEIN, SERVICE_STATUS_HANDLE;
typedef HANDLE SC_HANDLE, SC_LOCK, HCRYPTPROV, HCRYPTHASH, HCRYPTKEY;
typedef HANDLE HENHMETAFILE, HMETAFILE, HCOLORSPACE, HPEN;
typedef HANDLE HIMC, HKL;
typedef HANDLE HIMAGELIST, HPROPSHEETPAGE;
typedef int BOOL, *PBOOL, *LPBOOL, INT, *PINT, *LPINT, HFILE, HMMIO;
typedef UINT SOCKET;
typedef size_t SIZE_T;
#		if defined(UNICODE)
typedef WSTR TSTR, *PTSTR, *LPTSTR;
#		else	// defined(UNICODE)
typedef STR TSTR, *PTSTR, *LPTSTR;
#		endif	// defined(UNICODE)
typedef const TSTR CTSTR, *PCTSTR, *LPCTSTR;
#		define	ZeroMemory(ptr, size)	memset(ptr, 0, size)
#		define	RGB(r,g,b)	((r << 8) | (g << 16) | (b << 24))
#		if defined(__GNUC__) && defined(i386)
#			define	WINAPI	__attribute__ ((stdcall))
#		elif defined(__MWERKS__)
#			define	WINAPI	pascal
#		else
#			define	WINAPI
#		endif	// defined(__GNUC__) && defined(i386)

#		define	CALLBACK	WINAPI
#		define	PASCAL		WINAPI
#		define	APIENTRY	WINAPI
#		define	STDCALL		WINAPI

#		if !defined(FAR)
#			define	FAR
#		endif	// !defined(FAR)
#		if !defined(IN)
#			define	IN
#		endif	// !defined(IN)
#		if !defined(OUT)
#			define	OUT
#		endif	// !defined(OUT)
#		if !defined(OPTIONAL)
#			define	OPTIONAL
#		endif	// !defined(OPTIONAL)

typedef int CALLBACK (*FARPROC)(VOID);
typedef FARPROC PROC;
#		if !defined(TRUE)
#			define	TRUE	((BOOL)1)
#		endif	// !defined(TRUE)
#		if !defined(FALSE)
#			define	FALSE	((BOOL)0)
#		endif	// !defined(FALSE)
#		if !defined(INVALID_HANDLE_VALUE)
#			define	INVALID_HANDLE_VALUE	((HANDLE)-1)
#		endif	// !defined(INVALID_HANDLE_VALUE)
#		if !defined(CONST)
#			define	CONST	const
#		endif	// !defined(CONST)

#		if !defined(STDAPICALLTYPE)
#			define	STDAPICALLTYPE	__attribute__ ((stdcall))
#		endif	// !defined(STDAPICALLTYPE)
#		if !defined(STDAPIVCALLTYPE)
#			define	STDAPIVCALLTYPE	__attribute__ ((cdecl))
#		endif	// !defined(STDAPIVCALLTYPE)
#		if !defined(STDAPI)
#			define	STDAPI	HRESULT STDAPICALLTYPE
#		endif	// !defined(STDAPI)
#		if !defined(STDAPIV)
#			define	STDAPIV	HRESULT STDAPIVCALLTYPE
#		endif	// !defined(STDAPIV)

//
// COM互換の型の定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#		if defined(__BEOS__) && !defined(_COM_GUID)
#			define	GUID	COM_GUID
#		endif	// defined(__BEOS__) && !defined(_COM_GUID)
typedef struct _GUID {
	PACKED(DWORD Data1);
	PACKED(WORD Data2);
	PACKED(WORD Data3);
	PACKED(BYTE Data4[8]);
} GUID, *LPGUID;
typedef const GUID *REFGUID;

#		if defined(__BEOS__) && !defined(_COM_GUID)
#			undef GUID
#		endif	// defined(__BEOS__) && !defined(_COM_GUID)

#		if defined(__cplusplus)
#			define	REFCLSID	const CLSID &
#		else
#			define	REFCLSID	const CLSID * const
#		endif	// defined(__cplusplus)

typedef struct _IID {
	PACKED(unsigned long x);
	PACKED(unsigned short s1);
	PACKED(unsigned short s2);
	PACKED(unsigned char c[8]);
} IID, *LPIID;
typedef const IID *REFIID;
typedef IID CLSID, *LPCLSID;

#	endif	// !defined(__WIN32__)

//
// ソース互換性維持用の抽象型宣言
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(__WIN32__)
#		define	FILE_HANDLE			HANDLE
#		define	INVALID_FILE_HANDLE	((FILE_HANDLE)INVALID_HANDLE_VALUE)
#       if defined(FILE_READ_ONLY)
#           undef FILE_READ_ONLY
#       endif   // defined(FILE_READ_ONLY)
#		define	FILE_READ_ONLY		(GENERIC_READ)
#		define	FILE_WRITE_ONLY		(GENERIC_WRITE)
#		define	FILE_READ_WRITE		(GENERIC_READ | GENERIC_WRITE)
#		define	FILE_FORCE_CREATE	(CREATE_ALWAYS)
#		define	FILE_CREATE_NEW		(CREATE_NEW)
#		define	FILE_FORCE_OPEN		(OPEN_ALWAYS)
#		define	FILE_OPEN_ONLY		(OPEN_EXISTING)
#		define	FILE_POS_BEGIN		(FILE_BEGIN)
#		define	FILE_POS_CURRENT	(FILE_CURRENT)
#		define	FILE_POS_END		(FILE_END)
#	else	// defined(__WIN32__)
#		define	FILE_HANDLE			int
#		define	INVALID_FILE_HANDLE	((FILE_HANDLE)(-1))
#		define	FILE_READ_ONLY		(O_RDONLY)
#		define	FILE_WRITE_ONLY		(O_WRONLY)
#		define	FILE_READ_WRITE		(O_RDWR)
#		define	FILE_SHARE_READ		(O_SHLOCK)
#		define	FILE_FORCE_CREATE	(O_CREAT | O_TRUNC)
#		define	FILE_CREATE_NEW		(O_CREAT | O_EXCL)
#		define	FILE_FORCE_OPEN		(O_CREAT)
#		define	FILE_OPEN_ONLY		(0)
#		define	FILE_POS_BEGIN		(SEEK_SET)
#		define	FILE_POS_CURRENT	(SEEK_CUR)
#		define	FILE_POS_END		(SEEK_END)
#	endif	// !defined(__WIN32__)
#	if !defined(STDIN_FILENO)
#		define	STDIN_FILENO		0
#	endif	// !defined(STDIN_FILENO)
#	if !defined(STDOUT_FILENO)
#		define	STDOUT_FILENO		1
#	endif	// !defined(STDOUT_FILENO)
#	if !defined(STDERR_FILENO)
#		define	STDERR_FILENO		2
#	endif	// !defined(STDERR_FILENO)
#	if !defined(SEEK_SET)
#		define	SEEK_SET			0
#	endif	// !defined(SEEK_SET)
#	if !defined(SEEK_CUR)
#		define	SEEK_CUR			1
#	endif	// !defined(SEEK_CUR)
#	if !defined(SEEK_END)
#		define	SEEK_END			2
#	endif	// !defined(SEEK_END)

//
// ソース互換性維持用の抽象関数
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// マクロ関数
#	if defined(__WIN32__)
#		if defined(__WINCE__)
#			define	file_open(name, access, share, disp)	::CreateFileW(multi2wide(name), access, share, NULL, disp, FILE_ATTRIBUTE_ARCHIVE, NULL)
#		else	// defined(__WINCE__)
#			define	file_open(name, access, share, disp)	::CreateFileA(name, access, share, NULL, disp, FILE_ATTRIBUTE_ARCHIVE, NULL)
#		endif	// defined(__WINCE__)
#		define	file_close(fh)							(TRUE == ::CloseHandle(fh))
#		define	file_seek(fh, offset, mode)				::SetFilePointer(fh, offset, NULL, mode)
#		define	file_size(fh)							::GetFileSize(fh, NULL)
#		if defined(__WINCE__)
#			define	file_remove(name)						::DeleteFileW(multi2wide(name))
#		else	// defined(__WINCE__)
#			define	file_remove(name)						::DeleteFileA(name)
#		endif	// defined(__WINCE__)
#		define	snprintf								_snprintf
#	else	// defined(__WIN32__)
#		define	file_open(name, access, share, disp)	open(name, access | share | disp, 755)
#		define	file_close(fh)							(0 == close(fh))
#		define	file_seek(fh, offset, mode)				lseek(fh, offset, mode)
#		define	file_read(fh, buf, size)				read(fh, buf, size)
#		define	file_write(fh, buf, size)				write(fh, buf, size)
#		define	file_remove(name)						remove(name)
#	endif	// defined(__WIN32__)

//
// 互換用関数の宣言
#	if defined(__BEOS__) && defined(__POWERPC__)	// CodeWarrior系環境
int snprintf(char *str, size_t size, const char *format, ...);
#	endif	// defined(__BEOS__) && defined(__POWERPC__)
#	if defined(__WIN32__)
size_t file_read(FILE_HANDLE fh, char *buf, size_t size);
size_t file_write(FILE_HANDLE fh, char *buf, size_t size);
#	else	// defined(__WIN32__)
size_t file_size(FILE_HANDLE fh);
#	endif	// defined(__WIN32__)
#	if defined(__WIN32__)
typedef HBITMAP	BITMAP_HANDLE;
#		if defined(__VISUALC__)
#			define	vsnprintf	_vsnprintf
#			if !defined(__WINCE__)
#				define	exit		_exit
#			endif	// !defined(__WINCE__)
#		endif	// defined(__VISUALC__)
#	elif defined(__BEOS__)
class BBitmap;
typedef BBitmap *BITMAP_HANDLE;
#	else	// defined(__WIN32__)
typedef void *BITMAP_HANDLE;
#	endif	// defined(__WIN32__)
#	if defined(__MWERKS__)
#		define	stricmp	strcasecmp
#	endif	// defined(__MWERKS__)
#	if defined(__MACOS__)
char *strdup(const char *str);
#	endif	// defined(__MACOS__)
#	if defined(__WIN32__)
class multi2wide;
class wide2multi;
#	endif	// defined(__WIN32__)

//
// 互換用関数の実装
#	if defined(__Main__)

#		if defined(__BEOS__) && defined(__POWERPC__)
int
snprintf
(char *str, size_t size, const char *format, ...)
{
	va_list list;
	int result;

	va_start(list, format);
	result = vsprintf(str, format, list);
	va_end(list);
	return result;
}
#		endif	// defined(__BEOS__) && defined(__POWERPC__)
#		if defined(__WIN32__)
size_t
file_read
(FILE_HANDLE fh, char *buf, size_t size)
{
	DWORD readsize;
	if (0 == ReadFile(fh, (LPVOID)buf, (DWORD)size, &readsize, NULL)) return 0;
	return readsize;
}

size_t
file_write
(FILE_HANDLE fh, char *buf, size_t size)
{
	DWORD writesize;
	if (0 == WriteFile(fh, (LPVOID)buf, (DWORD)size, &writesize, NULL)) return 0;
	return writesize;
}
#		else	// defined(__WIN32__)
size_t
file_size
(FILE_HANDLE fh)
{
#			if defined(__PALMOS__)
	return 0;
#			else
	unsigned long filesize;
	struct stat sb;
	if (0 == fstat(fh, &sb)) filesize = (unsigned long)sb.st_size;
	else filesize = (unsigned long)-1;
	return filesize;
#			endif	// defined(__PALMOS__)
}
#		endif	// defined(__WIN32__)

#		if defined(__MACOS__)
char *
strdup
(const char *str)
{
	int len = 0;
	char *rv = NULL;
	if (NULL == str) return NULL;
	len = strlen(str) + 1;
	rv = malloc(len);
	if (NULL == rv) return NULL;
	strcpy(rv, str);
	return rv;
}
#		endif	// defined(__MACOS__)
#	endif	// defined(__Main__)

//
// デバッグ用の定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#	if defined(_DEBUG)

//
// デバッグ用関数の宣言
#		if !defined(__BORLANDC__)
#			if defined(__VISUALC__) && !defined(__WINCE__)
#				define  ___debug_malloc(size, file, line)	_malloc_dbg(size, _CLIENT_BLOCK, file, line)
#				define  ___debug_free(pv)					_free_dbg(pv, _CLIENT_BLOCK)
#				define	___debug_realloc(v, s, f, l)		realloc(v, s)
#				define	___debug_strdup(c, f, l)			strdup(c)
#			else    // defined(__VISUALC__) && !defined(__WINCE__)
void *___debug_malloc(size_t size, const char *file, int line);
void ___debug_free(void *pv);
void *___debug_realloc(void *pv, size_t size, const char *file, int line);
char *___debug_strdup(const char *c, const char *fname, int line);
#			endif   // defined(__VISUALC__) && !defined(__WINCE__)
#			if !defined(_NODEBUGNEW)
void *operator new(size_t stAllocateBlock, const char *file, int line);
void *operator new[](size_t stAllocateBlock, const char *file, int line);
void operator delete(void *pv, const char *file, int line);
void operator delete[](void *pv, const char *file, int line);
#			endif	// !defined(_NODEBUGNEW)
#		endif   // !defined(__BORLANDC__)
#		if defined(__cplusplus)
//extern "C" {
#		endif
int ___debug_message(const char *format, ...);
int ___debug_message_n(const char *buffer, int size);
void ___debug_exit(int _int);
void ___error_message(const char *file, int line);
const char *___strip_path(const char *path);
#		if !defined(__WIN32__)
void ___debug_puts(const char *s);
#			if !defined(__MACOS__)
#				define	OutputDebugStringA(s)	___debug_puts(s)
#			else	// !defined(__MACOS__)
void ___debug_syslog(const char *s);
#				define	OutputDebugStringA(s)	___debug_syslog(s)
#			endif	// !defined(__MACOS__)
#		endif	// !defined(__WIN32__)
#		if defined(__cplusplus)
//}
#		endif

//
// デバッグ用関数の実装
#		if defined(__Main__)
#			define	___MAX_MESSAGE_BUFFER	1024

//
// メモリリークチェック機構 

#			if !(defined(__VISUALC__) && !defined(__WINCE__)) && !defined(__BORLANDC__)

struct ___debug_meminfo{
    unsigned long magic;
    const char *fname;
    int line;
    size_t size;
	struct ___debug_meminfo *next;
	struct ___debug_meminfo *before;
};

static struct ___debug_meminfo *___debug_meminfo_first = NULL;
static struct ___debug_meminfo *___debug_meminfo_last = NULL;
static FILE *___debug_file_handle = NULL;

void *
___debug_malloc
(size_t size, const char *file, int line)
{
//    ___debug_message("allocate memory %d byte(s): %s(%d)\n", size, file, line);
    void *pv = malloc(size + sizeof(struct ___debug_meminfo));
    if (NULL == pv) {
        ___debug_message("%s(%d):%s\n", file, line, "##################################");
        ___debug_message("%s(%d):%s\n", file, line, "### memory allocation failed ! ###");
        ___debug_message("%s(%d):%s\n", file, line, "##################################");
        return NULL;
    }
    struct ___debug_meminfo *info = (struct ___debug_meminfo *)pv;
    info->magic = 'sAMy';
    info->fname = file;
    info->line = line;
    info->size = size;
	info->next = NULL;
	info->before = NULL;
	if (NULL == ___debug_meminfo_first) {
		___debug_meminfo_first = ___debug_meminfo_last = info;
	} else {
		___debug_meminfo_last->next = info;
		info->before = ___debug_meminfo_last;
		___debug_meminfo_last = info;
	}
    info++;
    return (void *)info;
}

void
___debug_free
(void *pv)
{
    if (NULL == pv) return;
    struct ___debug_meminfo *info = (struct ___debug_meminfo *)pv;
    info--;
    if (info->magic != 'sAMy') {
    	// Common.hが影響を及ぼすソース外でnewされたオブジェクトをdeleteする際に起き得る
        ___debug_message("### \'free\' called with invalid memory pointer. ###\n");
		free(pv);
        return;
    }
//    ___debug_message("free: %s(%d)[%d]\n", info->fname, info->line, info->size);
	info->magic = 0;	// against next invalid free
	if (NULL != info->next) info->next->before = info->before;
	if (NULL != info->before) info->before->next = info->next;
	if (___debug_meminfo_first == info) ___debug_meminfo_first = info->next;
	if (___debug_meminfo_last == info) ___debug_meminfo_last = info->before;
//	___debug_message("first: %08x / last: %08x / next: %08x / before: %08x\n", ___debug_meminfo_first, ___debug_meminfo_last, info->next, info->before);
	free(info);
}

void *
___debug_realloc
(void *pv, size_t size, const char *fname, int line)
{
	struct ___debug_meminfo *info = (struct ___debug_meminfo *)pv;
	if (NULL == pv) return ___debug_malloc(size, fname, line);
	info--;
	if (info->magic != 'sAMy') {
        ___debug_message("### \'realloc\' called with invalid memory pointer. ###\n");
		___debug_free(pv);
        return NULL;
	}
	void *result = ___debug_malloc(size, fname, line);
	if (NULL == result) {
		___debug_free(pv);
		return NULL;
	}
	memcpy(result, pv, info->size);
	info->size = size;
	___debug_free(pv);
	return result;
}

char *
___debug_strdup
(const char *c, const char *fname, int line)
{
	int size = strlen(c);
	char *result = (char *)___debug_malloc(size + 1, fname, line);
	if (NULL != result) {
		memcpy(result, c, size);
		result[size] = 0;
	}
	return result;
}

#			endif   // !(defined(__VISUALC__) && !defined(__WINCE)) && !defined(__BORLANDC__)

#           if !defined(__BORLANDC__) && !defined(_NODEBUGNEW)
void *
operator new
(size_t stAllocateBlock, const char *file, int line)
{
	return ___debug_malloc(stAllocateBlock, file, line);
}

void *
operator new[]
(size_t stAllocateBlock, const char *file, int line)
{
	return ___debug_malloc(stAllocateBlock, file, line);
}

void
operator delete
(void *pv, const char *file, int line)
{
    NOUSE(file);
    NOUSE(line);
    ___debug_free(pv);
}

void
operator delete[]
(void *pv, const char *file, int line)
{
    NOUSE(file);
    NOUSE(line);
    ___debug_free(pv);
}

#				if !defined(__VISUALC__)

void
operator delete
(void *pv)
{
    ___debug_free(pv);
}

void
operator delete[]
(void *pv)
{
    ___debug_free(pv);
}

#				endif   // !defined(__VISUALC__)
#           endif   // !defined(__BORLANDC__) && !defined(_NODEBUGNEW)

char ___debug_message_buffer[___MAX_MESSAGE_BUFFER];

#			if defined(__WINCE__)
#				if !defined(_WIN32_WCE_EMULATION)

#					define	OutputDebugStringA	___debug_puts
void ___debug_puts(const char *s);

#				else	// !defined(_WIN32_WCE_EMULATION)

void
OutputDebugStringA
(const char *str)
{
	if (0 == *str) OutputDebugStringW((wchar_t *)str);
	else {
		unsigned short wstr[___MAX_MESSAGE_BUFFER];
		MultiByteToWideChar(CP_OEMCP, 0, str, ___MAX_MESSAGE_BUFFER, wstr, ___MAX_MESSAGE_BUFFER);
		OutputDebugStringW(wstr);
	}
}

#				endif // !defined(_WIN32_WCE_EMULATION)
#			endif	// defined(__WINCE__)

int
___debug_message
(const char *format, ...)
{
	va_list list;
	int result;

	va_start(list, format);
	result = vsnprintf(___debug_message_buffer, ___MAX_MESSAGE_BUFFER, format, list);
	OutputDebugStringA(___debug_message_buffer);
	va_end(list);
	return result;
}

int
___debug_message_n
(const char *buffer, int size)
{
	if (-1 == size) size = (int)strlen(buffer);
	char *tmp = (char *)malloc(size + 1);
	if (NULL == tmp) return 0;
	memcpy(tmp, buffer, size);
	tmp[size] = 0;
	OutputDebugStringA(tmp);
	free(tmp);
	return size;
}

void
___debug_exit
(int _int)
{
#           if defined(__VISUALC__) && !defined(__WINCE__)
	_CrtDumpMemoryLeaks();
#			elif !defined(__BORLANDC__)
	struct ___debug_meminfo *p = ___debug_meminfo_first;
	if (NULL != p) {
		___debug_message("### memory leak detented ! ###\n");
		for (struct ___debug_meminfo *p = ___debug_meminfo_first; NULL != p; p = p->next) {
			char *data = (char *)(&p[1]);
			___debug_message("%s(%d): $%08x : %dbyte(s) [", p->fname, p->line, &p[1], p->size);
			unsigned int i;
			for (i = 0; i < p->size; i++) {
				___debug_message("%c", data[i]);
				if (i == 7) {
					___debug_message("...");
					break;
				}
			}
			___debug_message("(");
			for (i = 0; i < p->size; i++) {
				___debug_message("%02X,", (data[i] & 0xff));
				if (i == 7) {
					___debug_message("...");
					break;
				}
			}
			___debug_message(")]\n");
		}
	} else {
		___debug_message("### no memory leak detected ###\n");
	}
#           endif   // defined(__VISUALC__)
#			if !defined(__WIN32__) || (defined(__WINCE__) && !defined(_WIN32_WCE_EMULATION))
	if (NULL != ___debug_file_handle) {
		fclose(___debug_file_handle);
		___debug_file_handle = NULL;
	}
#			endif	// !defined(__WIN32__) || (defined(__WINCE__) && !defined(_WIN32_WCE_EMULATION))
#			if !defined(__WINCE__)
	exit(_int);
#			endif	// !defined(__WINCE__)
}

void
___error_message
(const char *file, int line)
{
#			if defined(__WIN32__)
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0,
		NULL
		);
#				if defined(__WINCE__)
	OutputDebugStringW((unsigned short *)lpMsgBuf);
#				else	// defined(__WINCE__)
	___debug_message("%s (%d) *Error*: %s\n", file, line, lpMsgBuf);
#				endif	// defined(__WINCE__)
	LocalFree(lpMsgBuf);
#			else	// defined(__WIN32__)
	___debug_message("%s (%d) *Error*: %s\n", file, line, strerror(errno));
#			endif	// defined(__WIN32__)
}

const char *
___strip_path
(const char *path)
{
	size_t len = strlen(path);
	const char *rc = path;
	for (size_t i = len - 1; i >= 0; i--) {
		if (path[i] == '/') {
			rc = &path[i + 1];
			break;
		}
	}
	return rc;
}

#			if !defined(__WIN32__) || (defined(__WINCE__) && !defined(_WIN32_WCE_EMULATION))
void
___debug_puts
(const char *str)
{
		if (NULL == ___debug_file_handle) {
#				if !defined(__WINCE__) && !defined(__MACOS__)
			const char *outdev = getenv("DOUT_TTY");
			if (NULL != outdev) ___debug_file_handle = fopen(outdev, "w");
			if (NULL == ___debug_file_handle) ___debug_file_handle = fdopen(STDERR_FILENO, "w");
#				else	// !defined(__WINCE__) && !defined(__MACOS__)
			___debug_file_handle = fopen("debuglog.txt", "a");
#				endif	// !defined(__WINCE__) && !defined(__MACOS__)
		}
		if (NULL != ___debug_file_handle) {
			fprintf(___debug_file_handle, "%s", str);
#				if defined(__MACOS__) || defined(__BEOS__) || defined(__WINCE__)
			fflush(___debug_file_handle);
#				endif	// defined(__MACOS__) || defined(__BEOS__) || defined(__WINCE__)
		}
}
#			endif	// !defined(__WIN32__) || (defined(__WINCE__) && !defined(_WIN32_WCE_EMULATION))

#			if defined(__MACOS__)
#				if !defined(SYSLOG_HOST)
#					define	SYSLOG_HOST	"sasami.toyo-net.local"
#				endif	// !defined(SYSLOG_HOST)
void
___debug_syslog
(const char *str)
{
	static bool init = false;
	static TUnitData ud;
	static InetAddress serv_ia;
	static EndpointRef epref;
	if (!init) {
		OSStatus oss = InitOpenTransport();
		if (0 != oss) return;
		InetSvcRef isref = OTOpenInternetServices(kDefaultInternetServicesPath, 0, &oss);
		if (0 != oss) return;
		InetHostInfo hinfo;
		oss = OTInetStringToAddress(isref, SYSLOG_HOST, &hinfo);
		if (0 != oss) return;
		TEndpointInfo einfo;
		epref = OTOpenEndpoint(OTCreateConfigulation(kUDPName), 0, &einfo, &oss);
		if (0 != oss) return;
		InetAddress ia;
		ia.fAddressType = AF_INET;
		ia.fPort = 0; // any
		ia.fHost = 0; // any
		memset(ia.fUnused, 0, 8);
		TBind retAddr;
		retAddr.qlen = 0;
		retAddr.addr.buf = (UInt8 *)&ia;
		retAddr.addr.len = sizeof(InetAddress);
		retAddr.addr.maxlen = sizeof(InetAddress);
		oss = OTBind(epref, NULL, &retAddr);
		if (0 != oss) return;
		serv_ia.fAddressType = AF_INET;
		serv_ia.fPort = 514; // syslog
		serv_ia.fHost = hinfo.addrs[0];
		memset(serv_ia.fUnused, 0, 8);
		ud.addr.buf = (UInt8 *)&serv_ia;
		ud.addr.len = sizeof(InetAddress);
		ud.opt.buf = NULL;
		ud.opt.len = 0;
		init = true;
	}
	ud.udata.buf = (Uint8 *)str;
	ud.udata.len = strlen(str) + 1;
	OTSndUData(epref, &ud);
}
#			endif	// defined(__MACOS__)

#		endif	// !defined(__Main__)

//
// デバッグ用のマクロ定義
#		if defined(_DOUT_WITH_PRETTY_FUNCTION)
#			define	DOUT		___debug_message("%s: ", __PRETTY_FUNCTION__) && ___debug_message
#			define	DOUTN(b, s)	___debug_message("%s: ", __PRETTY_FUNCTION__) && ___debug_message_n((const char *)b, s)
#			define	DERR()		___error_message(__PRETTY_FUNCTION__)
#		elif defined(_DOUT_WITH_FUNCTION)
#			define	DOUT		___debug_message("%s: ", __FUNCTION__) && ___debug_message
#			define	DOUTN(b, s)	___debug_message("%s: ", __FUNCTION__) && ___debug_message_n((const char *)b, s)
#			define	DERR()		___error_message(__FUNCTION__)
#		elif defined(_DOUT_WITH_FUNC_AND_LINE)
#			define	DOUT		___debug_message("%s (%4d) : ", __FUNCTION__, __LINE__) && ___debug_message
#			define	DOUTN(b, s)	___debug_message("%s (%4d) : ", __FUNCTION__, __LINE__) && ___debug_message_n((const char *)b, s)
#			define	DERR()		___error_message(__FUNCTION__)
#		elif defined(_DOUT_WITH_SHORT)
#			define	DOUT		___debug_message("%s (%4d) : ", ___strip_path(__FILE__), __LINE__) && ___debug_message
#			define	DOUTN(b, s)	___debug_message("%s (%4d) : ", ___strip_path(__FILE__), __LINE__) && ___debug_message_n((const char *)b, s)
#			define	DERR()		___error_message(___strip_path(__FILE__), __LINE__)
#		else	// defined(_DOUT_WITH_SHORT)
#			define	DOUT		___debug_message("%s (%4d) : ", __FILE__, __LINE__) && ___debug_message
#			define	DOUTN(b, s)	___debug_message("%s (%4d) : ", __FILE__, __LINE__) && ___debug_message_n((const char *)b, s)
#			define	DERR()		___error_message(__FILE__, __LINE__)
#		endif	// defined(_DOUT_WITH_PRETTY_FUNCTION)
#		define	DOUTR			___debug_message
#		define	DOUTRN(b, s)	___debug_message_n((const char *)b, s)
#       if !defined(__BORLANDC__) && !defined(_NODEBUGNEW)
#           define	new		new(__FILE__, __LINE__)
#       endif   // !defined(__BORLANDC__) && !defined(_NODEBUGNEW)
#		if defined(__VISUALC__) && defined(exit)
#			undef exit
#		endif	// defined(__VISUALC__) && defined(exit)
#		define	exit(i)	___debug_exit(i)
#		if !defined(__BORLANDC__) && !(defined(__VISUALC__) && !defined(__WINCE__))
#			define	malloc(s)		___debug_malloc(s, __FILE__, __LINE__)
#			define	realloc(v, s)	___debug_realloc(v, s, __FILE__, __LINE__)
#			define	strdup(c)		___debug_strdup(c, __FILE__, __LINE__)
#			define	free(v)			___debug_free(v)
#		endif	// !defined(__BORLANDC__) && !(defined(__VISUALC__) && !defined(__WINCE__))

#	else	// defined(_DEBUG)

//
// VisualC++用の警告抑制
#		if defined(__VISUALC__)
#			pragma warning(disable: 4390)
#		endif	// defined(__VISUALC__)

//
// 最適化で消去
static const int ___debug_flag = false;
static inline bool ___debug_none(const char *fmt, ...) { NOUSE(fmt); return false; };

#		define	DOUT	___debug_flag && ___debug_none
#		define	DOUTN	___debug_flag && ___debug_none
#		define	DOUTR	___debug_flag && ___debug_none
#		define	DOUTRN	___debug_flag && ___debug_none
#		define	DERR()	___debug_flag && ___debug_none(NULL)

#	endif	// defined(_DEBUG)

//
// 省略用マクロの定義
//////////////////////////////////////////////////////////////////////////////////////////////////
#	define	_throw(x)				{ lastError = x; throw x; }	
#	define	_return(x)				{ lastError = x; return false; }
#	define	_verify(x, s, r)		x = s; if (NULL == x) { r; }
#	define	_verifysock(x, s, r)	x = s; if (INVALID_SOCKET == x) { r; }
#	define	_post(x)				{ lastError = x; PostMessage(hWnd, MSG_ERROR, (WPARAM)x, 0); return 0; }
#	define	_error(x)				{ lastError = x; Error(x); return 0; }
#	define	_null(x, f)				{ if (NULL != x) { f(x); x = NULL; } }
#	define	_nulldelete(x)			{ if (NULL != x) { delete x; x = NULL; } }
#	define	_break					goto

#	if defined(UNICODE)
#		define	TO_MULTI(str)	wide2multi(str)
#		define	TO_WIDE(str)	(str)
#		define	tstrchr	wcschr
#		define	tstrcmp	wcscmp
#		define	tstrcpy	wcscpy
#		define	tstrcat	wcscat
#		define	tstrlen	wcslen
#	else	// defined(UNICODE)
#		define	TO_MULTI(str)	(str)
#		define	TO_WIDE(str)	multi2str(str)
#		define	tstrchr	strchr
#		define	tstrcmp	strcmp
#		define	tstrcpy	strcpy
#		define	tstrcat strcat
#		define	tstrlen strlen
#	endif	// defined(UNICODE)

//
// WindowsCE用 Unicode/Endian変換ライブラリ
//////////////////////////////////////////////////////////////////////////////////////////////////

#	if defined(__WIN32__)

#		if !defined(CP_OEMCP)
#			define	CP_OEMCP	1
#		endif	// !defined(CP_OEMCP)

class wide2multi {
public:
	wide2multi(const wchar_t *wc);
	~wide2multi(void);
	operator const char *(void) const { return ((wide2multi *)this)->mc; };
	operator const wchar_t *(void) const { return ((wide2multi *)this)->wc; };
private:
	char *mc;
	const wchar_t *wc;
};

class multi2wide {
public:
	multi2wide(const char *mc);
	~multi2wide(void);
	operator const char *(void) const { return ((multi2wide *)this)->mc; };
	operator const wchar_t *(void) const { return ((multi2wide *)this)->wc; };
private:
	const char *mc;
	wchar_t *wc;
};

class lsb2host {
public:
	lsb2host(DWORD dw);
	lsb2host(LONG l);
	lsb2host(WORD w);
	operator const DWORD(void) const { return *((LPDWORD)((lsb2host *)this)->buf); };
	operator const LONG(void) const { return *((LPLONG)((lsb2host *)this)->buf); };
	operator const WORD(void) const { return *((LPWORD)((lsb2host *)this)->buf); };
private:
	void check(void);
	unsigned char buf[4];
	static bool checked;
	static bool lsbfirst;
};

#		if defined(__Main__)

wide2multi::wide2multi
(const wchar_t *wc):
wc(wc)
{
	int len = (int)wcslen(wc);
	mc = new char[len * 2 + 1];
	BOOL use;
	len = WideCharToMultiByte(CP_OEMCP, 0, wc, len, mc, len * 2, NULL, &use);
	mc[len] = 0;
}

wide2multi::~wide2multi
(void)
{
	if (NULL != mc) delete mc;
}

multi2wide::multi2wide
(const char *mc):
mc(mc)
{
	int len = (int)strlen(mc);
	wc = new wchar_t[len + 1];
	len = MultiByteToWideChar(CP_OEMCP, 0, mc, len, wc, len + 1);
	wc[len] = 0;
}

multi2wide::~multi2wide
(void)
{
	if (NULL != wc) delete wc;
}

lsb2host::lsb2host
(DWORD dw)
{
	if (!checked) check();
	if (lsbfirst) *((LPDWORD)buf) = dw;
	else {
		buf[3] = ((unsigned char *)&dw)[0];
		buf[2] = ((unsigned char *)&dw)[1];
		buf[1] = ((unsigned char *)&dw)[2];
		buf[0] = ((unsigned char *)&dw)[3];
	}
}

lsb2host::lsb2host
(LONG l)
{
	if (!checked) check();
	if (lsbfirst) *((LPLONG)buf) = l;
	else {
		buf[3] = ((unsigned char *)&l)[0];
		buf[2] = ((unsigned char *)&l)[1];
		buf[1] = ((unsigned char *)&l)[2];
		buf[0] = ((unsigned char *)&l)[3];
	}
}

lsb2host::lsb2host
(WORD w)
{
	if (!checked) check();
	if (lsbfirst) *((LPWORD)buf) = w;
	else {
		buf[1] = ((unsigned char *)&w)[0];
		buf[0] = ((unsigned char *)&w)[1];
	}
}

void
lsb2host::check
(void)
{
	buf[0] = 0;
	buf[1] = 1;
	if (*((short *)buf) != 1) lsbfirst = true;
	checked = true;
}

bool
lsb2host::checked = false;

bool
lsb2host::lsbfirst = false;

#		endif	// defined(__Main__)

#	endif	// defined(__WIN32__)

#	if !defined(__Errors_h__)
#		include "Errors.h"
#	endif	// !defined(__Errors_h__)

#endif	// !defined(__Common_h__)
