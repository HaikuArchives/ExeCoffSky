/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: WSock32.cpp,v 1.1 2003/05/01 03:36:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [WSock32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "WSock32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" int PASCAL FAR
WSAStartup
(WORD wVersionRequired, LPWSADATA lpWSAData)
{
	int rc = 0;
	WIN32API_POINTER(lpWSAData);
	WIN32API_ENTER("int", "WSAStartup", "WORD", wVersionRequired, "LPWSADATA", lpWSAData, NULL);
	WIN32API_INFO("\trequired version: %d.%d\n", wVersionRequired >> 8, wVersionRequired & 0xff);
	lpWSAData->wVersion = wVersionRequired;
	lpWSAData->wHighVersion = (2 << 8) | 0;	// 2.0
	snprintf(lpWSAData->szDescription, WSADESCRIPTION_LEN, "WinBe Sock");
	snprintf(lpWSAData->szSystemStatus, WSASYS_STATUS_LEN, "BeOS");
	lpWSAData->iMaxSockets = 255;
	lpWSAData->iMaxUdpDg = 255;
	lpWSAData->lpVendorInfo = NULL;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL PASCAL FAR
AcceptEx
(IN SOCKET sListenSocket, IN SOCKET sAcceptSocket, IN PVOID lpOutputBuffer, IN DWORD dwReceiveDataLength, IN DWORD dwLocalAddressLength, IN DWORD dwRemoteAddressLength, OUT LPDWORD lpdwBytesReceived, IN LPOVERLAPPED lpOverlapped)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "AcceptEx", "IN SOCKET", 0, "IN SOCKET", 0, "IN PVOID", 0, "IN DWORD", 0, "IN DWORD", 0, "IN DWORD", 0, "OUT LPDWORD", 0, "IN LPOVERLAPPED", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
EnumProtocolsA
(IN LPINT lpiProtocols, IN OUT LPVOID lpProtocolBuffer, IN OUT LPDWORD lpdwBufferLength)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "EnumProtocolsA", "IN LPINT", 0, "IN OUT LPVOID", 0, "IN OUT LPDWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
EnumProtocolsW
(IN LPINT lpiProtocols, IN OUT LPVOID lpProtocolBuffer, IN OUT LPDWORD lpdwBufferLength)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "EnumProtocolsW", "IN LPINT", 0, "IN OUT LPVOID", 0, "IN OUT LPDWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" VOID PASCAL FAR
GetAcceptExSockaddrs
(IN PVOID lpOutputBuffer, IN DWORD dwReceiveDataLength, IN DWORD dwLocalAddressLength, IN DWORD dwRemoteAddressLength, OUT struct sockaddr **LocalSockaddr, OUT LPINT LocalSockaddrLength, OUT struct sockaddr **RemoteSockaddr, OUT LPINT RemoteSockaddrLength)
{
	WIN32API_ENTER("VOID", "GetAcceptExSockaddrs", "IN PVOID", 0, "IN DWORD", 0, "IN DWORD", 0, "IN DWORD", 0, "OUT struct sockaddr", 0, "OUT LPINT", 0, "OUT struct sockaddr", 0, "OUT LPINT", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" INT APIENTRY
GetAddressByNameA
(IN DWORD dwNameSpace, IN LPGUID lpServiceType, IN LPSTR lpServiceName OPTIONAL, IN LPINT lpiProtocols OPTIONAL, IN DWORD dwResolution, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo OPTIONAL, IN OUT LPVOID lpCsaddrBuffer, IN OUT LPDWORD lpdwBufferLength, IN OUT LPSTR lpAliasBuffer OPTIONAL, IN OUT LPDWORD lpdwAliasBufferLength OPTIONAL)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetAddressByNameA", "IN DWORD", 0, "IN LPGUID", 0, "IN LPSTR lpServiceName", 0, "IN LPINT lpiProtocols", 0, "IN DWORD", 0, "IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo", 0, "IN OUT LPVOID", 0, "IN OUT LPDWORD", 0, "IN OUT LPSTR lpAliasBuffer", 0, "IN OUT LPDWORD lpdwAliasBufferLength", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetAddressByNameW
(IN DWORD dwNameSpace, IN LPGUID lpServiceType, IN LPWSTR lpServiceName OPTIONAL, IN LPINT lpiProtocols OPTIONAL, IN DWORD dwResolution, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo OPTIONAL, IN OUT LPVOID lpCsaddrBuffer, IN OUT LPDWORD lpdwBufferLength, IN OUT LPWSTR lpAliasBuffer OPTIONAL, IN OUT LPDWORD lpdwAliasBufferLength OPTIONAL)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetAddressByNameW", "IN DWORD", 0, "IN LPGUID", 0, "IN LPWSTR lpServiceName", 0, "IN LPINT lpiProtocols", 0, "IN DWORD", 0, "IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo", 0, "IN OUT LPVOID", 0, "IN OUT LPDWORD", 0, "IN OUT LPWSTR lpAliasBuffer", 0, "IN OUT LPDWORD lpdwAliasBufferLength", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetNameByTypeA
(IN LPGUID lpServiceType, IN OUT LPSTR lpServiceName, IN DWORD dwNameLength)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetNameByTypeA", "IN LPGUID", 0, "IN OUT LPSTR", 0, "IN DWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetNameByTypeW
(IN LPGUID lpServiceType, IN OUT LPWSTR lpServiceName, IN DWORD dwNameLength)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetNameByTypeW", "IN LPGUID", 0, "IN OUT LPWSTR", 0, "IN DWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetServiceA
(IN DWORD dwNameSpace, IN LPGUID lpGuid, IN LPSTR lpServiceName, IN DWORD dwProperties, IN OUT LPVOID lpBuffer, IN OUT LPDWORD lpdwBufferSize, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetServiceA", "IN DWORD", 0, "IN LPGUID", 0, "IN LPSTR", 0, "IN DWORD", 0, "IN OUT LPVOID", 0, "IN OUT LPDWORD", 0, "IN LPSERVICE_ASYNC_INFO", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetServiceW
(IN DWORD dwNameSpace, IN LPGUID lpGuid, IN LPWSTR lpServiceName, IN DWORD dwProperties, IN OUT LPVOID lpBuffer, IN OUT LPDWORD lpdwBufferSize, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetServiceW", "IN DWORD", 0, "IN LPGUID", 0, "IN LPWSTR", 0, "IN DWORD", 0, "IN OUT LPVOID", 0, "IN OUT LPDWORD", 0, "IN LPSERVICE_ASYNC_INFO", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetTypeByNameA
(IN LPSTR lpServiceName, IN OUT LPGUID lpServiceType)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetTypeByNameA", "IN LPSTR", 0, "IN OUT LPGUID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
GetTypeByNameW
(IN LPWSTR lpServiceName, IN OUT LPGUID lpServiceType)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "GetTypeByNameW", "IN LPWSTR", 0, "IN OUT LPGUID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
SetServiceA
(IN DWORD dwNameSpace, IN DWORD dwOperation, IN DWORD dwFlags, IN LPSERVICE_INFOA lpServiceInfo, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, IN OUT LPDWORD lpdwStatusFlags)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "SetServiceA", "IN DWORD", 0, "IN DWORD", 0, "IN DWORD", 0, "IN LPSERVICE_INFOA", 0, "IN LPSERVICE_ASYNC_INFO", 0, "IN OUT LPDWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" INT APIENTRY
SetServiceW
(IN DWORD dwNameSpace, IN DWORD dwOperation, IN DWORD dwFlags, IN LPSERVICE_INFOW lpServiceInfo, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, IN OUT LPDWORD lpdwStatusFlags)
{
	INT rc = (INT)0;
	WIN32API_ENTER("INT", "SetServiceW", "IN DWORD", 0, "IN DWORD", 0, "IN DWORD", 0, "IN LPSERVICE_INFOW", 0, "IN LPSERVICE_ASYNC_INFO", 0, "IN OUT LPDWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL PASCAL FAR
TransmitFile
(IN SOCKET hSocket, IN HANDLE hFile, IN DWORD nNumberOfBytesToWrite, IN DWORD nNumberOfBytesPerSend, IN LPOVERLAPPED lpOverlapped, IN LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers, IN DWORD dwReserved)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "TransmitFile", "IN SOCKET", 0, "IN HANDLE", 0, "IN DWORD", 0, "IN DWORD", 0, "IN LPOVERLAPPED", 0, "IN LPTRANSMIT_FILE_BUFFERS", 0, "IN DWORD", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE PASCAL FAR
WSAAsyncGetHostByAddr
(HWND hWnd, u_int wMsg, const char FAR *addr, int len, int type, char FAR *buf, int buflen)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "WSAAsyncGetHostByAddr", "HWND", hWnd, "u_int", wMsg, "const char FAR *", addr,
		"int", len, "int", type, "char FAR *", buf, "int", buflen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE PASCAL FAR
WSAAsyncGetHostByName
(HWND hWnd, u_int wMsg, const char FAR *name, char FAR *buf, int buflen)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "WSAAsyncGetHostByName", "HWND", hWnd, "u_int", wMsg, "const char FAR *", name, "char FAR *", buf, "int", buflen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE PASCAL FAR
WSAAsyncGetProtoByName
(HWND hWnd, u_int wMsg, const char FAR *name, char FAR *buf, int buflen)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "WSAAsyncGetProtoByName", "HWND", hWnd, "u_int", wMsg, "const char FAR *", name, "char FAR *", buf, "int", buflen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE PASCAL FAR
WSAAsyncGetProtoByNumber
(HWND hWnd, u_int wMsg, int number, char FAR *buf, int buflen)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "WSAAsyncGetProtoByNumber", "HWND", hWnd, "u_int", wMsg, "int", number, "char FAR *", buf, "int", buflen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE PASCAL FAR
WSAAsyncGetServByName
(HWND hWnd, u_int wMsg, const char FAR *name, const char FAR *proto, char FAR *buf, int buflen)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "WSAAsyncGetServByName", "HWND", hWnd, "u_int", wMsg, "const char FAR *", name, "const char FAR *", proto, "char FAR *", buf, "int", buflen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE PASCAL FAR
WSAAsyncGetServByPort
(HWND hWnd, u_int wMsg, int port, const char FAR *proto, char FAR *buf, int buflen)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "WSAAsyncGetServByPort", "HWND", hWnd, "u_int", wMsg, "int", port, "const char FAR *", proto, "char FAR *", buf, "int", buflen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
WSAAsyncSelect
(SOCKET s, HWND hWnd, u_int wMsg, long lEvent)
{
	int rc = 0;
	WIN32API_ENTER("int", "WSAAsyncSelect", "SOCKET", s, "HWND", hWnd, "u_int", wMsg, "long", lEvent, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
WSAGetLastError
(void)
{
	int rc = 0;
	WIN32API_ENTER("int", "WSAGetLastError", "void", NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
WSACancelAsyncRequest
(HANDLE hAsyncTaskHandle)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "WSACancelAsyncRequest", "HANDLE", hAsyncTaskHandle, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
WSACancelBlockingCall
(void)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "WSACancelBlockingCall", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
WSACleanup
(void)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "WSACleanup", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL PASCAL FAR
WSAIsBlocking
(void)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "WSAIsBlocking", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
WSARecvEx
(SOCKET s, char FAR *buf, int len, int FAR *flags)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "WSARecvEx", "SOCKET", s, "char FAR", 0, "int", len, "int FAR *", flags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" FARPROC PASCAL FAR
WSASetBlockingHook
(FARPROC lpBlockFunc)
{
	FARPROC rc = (FARPROC)NULL;
	WIN32API_ENTER("FARPROC", "WSASetBlockingHook", "FARPROC", lpBlockFunc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void PASCAL FAR
WSASetLastError
(int iError)
{
	WIN32API_ENTER("void", "WSASetLastError", "int", iError, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" int PASCAL FAR
WSAUnhookBlockingHook
(void)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "WSAUnhookBlockingHook", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
__WSAFDIsSet
(SOCKET arg0, fd_set FAR *)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "__WSAFDIsSet", "SOCKET", arg0, "fd_set FAR", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SOCKET PASCAL FAR
_accept
(SOCKET s, struct sockaddr FAR *addr, int FAR *addrlen)
{
	SOCKET rc = (SOCKET)-1;
	WIN32API_ENTER("SOCKET", "accept", "SOCKET", s, "struct sockaddr FAR", 0, "int FAR", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_bind
(SOCKET s, const struct sockaddr FAR *addr, int namelen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "bind", "SOCKET", s, "const struct sockaddr FAR *", addr, "int", namelen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_closesocket
(SOCKET s)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "closesocket", "SOCKET", s, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_connect
(SOCKET s, const struct sockaddr FAR *name, int namelen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "connect", "SOCKET", s, "const struct sockaddr FAR *", name, "int", namelen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_gethostname
(char FAR *name, int namelen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "gethostname", "char FAR *", name, "int", namelen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_getpeername
(SOCKET s, struct sockaddr FAR *name, int FAR *namelen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "getpeername", "SOCKET", s, "struct sockaddr FAR *", name, "int FAR *", namelen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" struct protoent FAR * PASCAL FAR
_getprotobyname
(const char FAR *name)
{
	struct protoent FAR * rc = NULL;
	WIN32API_ENTER("struct protoent FAR *", "getprotobyname", "const char FAR *", name, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" struct protoent FAR * PASCAL FAR
_getprotobynumber
(int proto)
{
	struct protoent FAR * rc = NULL;
	WIN32API_ENTER("struct protoent FAR *", "getprotobynumber", "int", proto, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" struct servent FAR * PASCAL FAR
_getservbyname
(const char FAR * name, const char FAR *proto)
{
	struct servent FAR * rc = NULL;
	WIN32API_ENTER("struct servent FAR *", "getservbyname", "const char FAR *", name, "const char FAR *", proto, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" struct servent FAR * PASCAL FAR
_getservbyport
(int port, const char FAR *proto)
{
	struct servent FAR * rc = NULL;
	WIN32API_ENTER("struct servent FAR *", "getservbyport", "int", port, "const char FAR *", proto, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_getsockname
(SOCKET s, struct sockaddr FAR *name, int FAR *namelen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "getsockname", "SOCKET", s, "struct sockaddr FAR", name, "int FAR *", namelen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_getsockopt
(SOCKET s, int level, int optname, char FAR *optval, int FAR *optlen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "getsockopt", "SOCKET", s, "int", level, "int", optname, "char FAR *", optval, "int FAR", optlen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" u_long PASCAL FAR
_htonl
(u_long hostlong)
{
	u_long rc = (u_long)0;
	WIN32API_ENTER("u_long", "htonl", "u_long", hostlong, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" u_short PASCAL FAR
_htons
(u_short hostshort)
{
	u_short rc = (u_short)0;
	WIN32API_ENTER("u_short", "htons", "u_short", hostshort, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned long PASCAL FAR
_inet_addr
(const char FAR *cp)
{
	unsigned long rc = (unsigned long)0;
	WIN32API_ENTER("unsigned long", "inet_addr", "const char FAR *", cp, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" char FAR * PASCAL FAR
_inet_ntoa
(struct in_addr in)
{
	char FAR * rc = NULL;
	WIN32API_ENTER("char FAR *", "inet_ntoa", "struct in_addr", in, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_ioctlsocket
(SOCKET s, long cmd, u_long FAR *argp)
{
	int rc = 0;
	WIN32API_ENTER("int", "ioctlsocket", "SOCKET", s, "long", cmd, "u_long FAR *", argp);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" u_long PASCAL FAR
_ntohl
(u_long netlong)
{
	u_long rc = (u_long)0;
	WIN32API_ENTER("u_long", "ntohl", "u_long", netlong, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" u_short PASCAL FAR
_ntohs
(u_short netshort)
{
	u_short rc = (u_short)0;
	WIN32API_ENTER("u_short", "ntohs", "u_short", netshort, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_recv
(SOCKET s, char FAR *buf, int len, int flags)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "recvfrom", "SOCKET", s, "char FAR *", buf, "int", len, "int", flags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_recvfrom
(SOCKET s, char FAR *buf, int len, int flags, struct sockaddr FAR *from, int FAR *fromlen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "recvfrom", "SOCKET", s, "char FAR *", buf, "int", len, "int", flags, "struct sockaddr FAR", from, "int FAR *", fromlen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_send
(SOCKET s, const char FAR *buf, int len, int flags)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "sendto", "SOCKET", s, "const char FAR *", buf, "int", len, "int", flags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_sendto
(SOCKET s, const char FAR *buf, int len, int flags, const struct sockaddr FAR *to, int tolen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "sendto", "SOCKET", s, "const char FAR *", buf, "int", len, "int", flags, "const struct sockaddr FAR *", to, "int", tolen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_setsockopt
(SOCKET s, int level, int optname, const char FAR *optval, int optlen)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "setsockopt", "SOCKET", s, "int", level, "int", optname, "const char FAR *", optval, "int", optlen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int PASCAL FAR
_shutdown
(SOCKET s, int how)
{
	int rc = (int)0;
	WIN32API_ENTER("int", "shutdown", "SOCKET", s, "int", how, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" SOCKET PASCAL FAR
_socket
(int af, int type, int protocol)
{
	SOCKET rc = (SOCKET)-1;
	WIN32API_ENTER("SOCKET", "socket", "int", af, "int", type, "int", protocol, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	WSock32_GetAddressByOrder
#	define	GetAddressByName	WSock32_GetAddressByName

#	include "WSock32/GetAddressByOrder.h"
#	include "WSock32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
