/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Shell32.cpp,v 1.1 2003/05/01 03:33:11 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Shell32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Shell32.h"
#include "Win32Trace.h"

extern "C" BOOL WINAPI
Shell_NotifyIconW
(DWORD arg0, PNOTIFYICONDATAW arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Shell_NotifyIconW", "DWORD", arg0, "PNOTIFYICONDATAW", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
Shell_NotifyIconA
(DWORD arg0, PNOTIFYICONDATAA arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "Shell_NotifyIconA", "DWORD", arg0, "PNOTIFYICONDATAA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HINSTANCE WINAPI
ShellExecuteW
(HWND arg0, LPCWSTR arg1, LPCWSTR arg2, LPCWSTR arg3, LPCWSTR arg4, INT arg5)
{
	HINSTANCE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HINSTANCE", "ShellExecuteW", "HWND", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "LPCWSTR", arg3, "LPCWSTR", arg4, "INT", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShellExecuteExW
(LPSHELLEXECUTEINFOW arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShellExecuteExW", "LPSHELLEXECUTEINFOW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ShellExecuteExA
(LPSHELLEXECUTEINFOA arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ShellExecuteExA", "LPSHELLEXECUTEINFOA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HINSTANCE WINAPI
ShellExecuteA
(HWND arg0, LPCSTR arg1, LPCSTR arg2, LPCSTR arg3, LPCSTR arg4, INT arg5)
{
	HINSTANCE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HINSTANCE", "ShellExecuteA", "HWND", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "LPCSTR", arg3, "LPCSTR", arg4, "INT", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRESULT WINAPI
SHLoadInProc
(REFCLSID arg0)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SHLoadInProc", "REFCLSID", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRESULT WINAPI
SHGetSpecialFolderLocation
(HWND arg0, int arg1, LPITEMIDLIST* arg2)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SHGetSpecialFolderLocation", "HWND", arg0, "int", arg1, "LPITEMIDLIST*", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SHGetPathFromIDList
(LPCITEMIDLIST arg0, LPSTR arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SHGetPathFromIDList", "LPCITEMIDLIST", arg0, "LPSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRESULT WINAPI
SHGetMalloc
(LPMALLOC* arg0)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SHGetMalloc", "LPMALLOC*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRESULT WINAPI
SHGetInstanceExplorer
(LPUNKNOWN arg0)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SHGetInstanceExplorer", "LPUNKNOWN", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SHGetFileInfoW
(LPCWSTR arg0, DWORD arg1, SHFILEINFOW* arg2, UINT arg3, UINT arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SHGetFileInfoW", "LPCWSTR", arg0, "DWORD", arg1, "SHFILEINFOW*", arg2, "UINT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SHGetFileInfoA
(LPCSTR arg0, DWORD arg1, SHFILEINFOA* arg2, UINT arg3, UINT arg4)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "SHGetFileInfoA", "LPCSTR", arg0, "DWORD", arg1, "SHFILEINFOA*", arg2, "UINT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRESULT WINAPI
SHGetDesktopFolder
(LPSHELLFOLDER* arg0)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SHGetDesktopFolder", "LPSHELLFOLDER*", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
SHFreeNameMappings
(HANDLE arg0)
{
	WIN32API_ENTER("void", "SHFreeNameMappings", "HANDLE", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" int WINAPI
SHFileOperationW
(LPSHFILEOPSTRUCTW arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SHFileOperationW", "LPSHFILEOPSTRUCTW", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
SHFileOperationA
(LPSHFILEOPSTRUCTA arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "SHFileOperationA", "LPSHFILEOPSTRUCTA", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
SHChangeNotify
(LONG arg0, UINT arg1, PCVOID arg2, PCVOID arg3)
{
	WIN32API_ENTER("void", "SHChangeNotify", "LONG", arg0, "UINT", arg1, "PCVOID", arg2, "PCVOID", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" LPITEMIDLIST WINAPI
SHBrowseForFolder
(PBROWSEINFO arg0)
{
	LPITEMIDLIST rc = NULL;
	WIN32API_ENTER("LPITEMIDLIST", "SHBrowseForFolder", "PBROWSEINFO", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
SHAppBarMessage
(DWORD arg0, PAPPBARDATA arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "SHAppBarMessage", "DWORD", arg0, "PAPPBARDATA", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
SHAddToRecentDocs
(UINT arg0, PCVOID arg1)
{
	WIN32API_ENTER("void", "SHAddToRecentDocs", "UINT", arg0, "PCVOID", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" HINSTANCE WINAPI
FindExecutableW
(LPCWSTR arg0, LPCWSTR arg1, LPWSTR arg2)
{
	HINSTANCE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HINSTANCE", "FindExecutableW", "LPCWSTR", arg0, "LPCWSTR", arg1, "LPWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HINSTANCE WINAPI
FindExecutableA
(LPCSTR arg0, LPCSTR arg1, LPSTR arg2)
{
	HINSTANCE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HINSTANCE", "FindExecutableA", "LPCSTR", arg0, "LPCSTR", arg1, "LPSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
ExtractIconW
(HINSTANCE arg0, LPCWSTR arg1, UINT arg2)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ExtractIconW", "HINSTANCE", arg0, "LPCWSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
ExtractIconExW
(LPCWSTR arg0, int arg1, HICON* arg2, HICON* arg3, UINT arg4)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ExtractIconExW", "LPCWSTR", arg0, "int", arg1, "HICON*", arg2, "HICON*", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
ExtractIconExA
(LPCSTR arg0, int arg1, HICON* arg2, HICON* arg3, UINT arg4)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ExtractIconExA", "LPCSTR", arg0, "int", arg1, "HICON*", arg2, "HICON*", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
ExtractIconA
(HINSTANCE arg0, LPCSTR arg1, UINT arg2)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ExtractIconA", "HINSTANCE", arg0, "LPCSTR", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
ExtractAssociatedIconW
(HINSTANCE arg0, LPCWSTR arg1, PWORD arg2)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ExtractAssociatedIconW", "HINSTANCE", arg0, "LPCWSTR", arg1, "PWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HICON WINAPI
ExtractAssociatedIconA
(HINSTANCE arg0, LPCSTR arg1, PWORD arg2)
{
	HICON rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HICON", "ExtractAssociatedIconA", "HINSTANCE", arg0, "LPCSTR", arg1, "PWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DragQueryPoint
(HDROP arg0, LPPOINT arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DragQueryPoint", "HDROP", arg0, "LPPOINT", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
DragQueryFileW
(HDROP arg0, UINT arg1, LPWSTR arg2, UINT arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "DragQueryFileW", "HDROP", arg0, "UINT", arg1, "LPWSTR", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
DragQueryFileA
(HDROP arg0, UINT arg1, LPSTR arg2, UINT arg3)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "DragQueryFileA", "HDROP", arg0, "UINT", arg1, "LPSTR", arg2, "UINT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void WINAPI
DragFinish
(HDROP arg0)
{
	WIN32API_ENTER("void", "DragFinish", "HDROP", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

extern "C" void WINAPI
DragAcceptFiles
(HWND arg0, BOOL arg1)
{
	WIN32API_ENTER("void", "DragAcceptFiles", "HWND", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(0);
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	Shell32_GetAddressByOrder
#	define	GetAddressByName	Shell32_GetAddressByName

#	include "Shell32/GetAddressByOrder.h"
#	include "Shell32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
