/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Shell32.h,v 1.1 2003/05/01 03:33:11 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Shell32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Shell32_h__)
#	define	__Shell32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__ShellAbout_h__)
#		include "ShellAbout.h"
#	endif	// !defined(__ShellAbout_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

BOOL WINAPI Shell_NotifyIconW(DWORD,PNOTIFYICONDATAW);
BOOL WINAPI Shell_NotifyIconA(DWORD,PNOTIFYICONDATAA);
HINSTANCE WINAPI ShellExecuteW(HWND,LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,INT);
BOOL WINAPI ShellExecuteExW(LPSHELLEXECUTEINFOW);
BOOL WINAPI ShellExecuteExA(LPSHELLEXECUTEINFOA);
HINSTANCE WINAPI ShellExecuteA(HWND,LPCSTR,LPCSTR,LPCSTR,LPCSTR,INT);
HRESULT WINAPI SHLoadInProc(REFCLSID);
HRESULT WINAPI SHGetSpecialFolderLocation(HWND,int,LPITEMIDLIST*);
BOOL WINAPI SHGetPathFromIDList(LPCITEMIDLIST,LPSTR);
HRESULT WINAPI SHGetMalloc(LPMALLOC*);
HRESULT WINAPI SHGetInstanceExplorer(LPUNKNOWN);
DWORD WINAPI SHGetFileInfoW(LPCWSTR,DWORD,SHFILEINFOW*,UINT,UINT);
DWORD WINAPI SHGetFileInfoA(LPCSTR,DWORD,SHFILEINFOA*,UINT,UINT);
HRESULT WINAPI SHGetDesktopFolder(LPSHELLFOLDER*);
void WINAPI SHFreeNameMappings(HANDLE);
int WINAPI SHFileOperationW(LPSHFILEOPSTRUCTW);
int WINAPI SHFileOperationA(LPSHFILEOPSTRUCTA);
void WINAPI SHChangeNotify(LONG,UINT,PCVOID,PCVOID);
LPITEMIDLIST WINAPI SHBrowseForFolder(PBROWSEINFO);
UINT WINAPI SHAppBarMessage(DWORD,PAPPBARDATA);
void WINAPI SHAddToRecentDocs(UINT,PCVOID);
HINSTANCE WINAPI FindExecutableW(LPCWSTR,LPCWSTR,LPWSTR);
HINSTANCE WINAPI FindExecutableA(LPCSTR,LPCSTR,LPSTR);
HICON WINAPI ExtractIconW(HINSTANCE,LPCWSTR,UINT);
HICON WINAPI ExtractIconExW(LPCWSTR,int,HICON*,HICON*,UINT);
HICON WINAPI ExtractIconExA(LPCSTR,int,HICON*,HICON*,UINT);
HICON WINAPI ExtractIconA(HINSTANCE,LPCSTR,UINT);
HICON WINAPI ExtractAssociatedIconW(HINSTANCE,LPCWSTR,PWORD);
HICON WINAPI ExtractAssociatedIconA(HINSTANCE,LPCSTR,PWORD);
BOOL WINAPI DragQueryPoint(HDROP,LPPOINT);
UINT WINAPI DragQueryFileW(HDROP,UINT,LPWSTR,UINT);
UINT WINAPI DragQueryFileA(HDROP,UINT,LPSTR,UINT);
void WINAPI DragFinish(HDROP);
void WINAPI DragAcceptFiles(HWND,BOOL);

#	if defined(_BUILTIN_DLL)
void *Shell32_GetAddressByOrder(int order);
void *Shell32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Shell32_h__)
