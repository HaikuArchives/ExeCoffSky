/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: WSock32.h,v 1.1 2003/05/01 03:36:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [WSock32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__WSock32_h__)
#	define	__WSock32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	define	WSADESCRIPTION_LEN	256
#	define	WSASYS_STATUS_LEN	128

typedef struct WSADATA {
	PACKED(WORD wVersion);
	PACKED(WORD wHighVersion);
	PACKED(char szDescription[WSADESCRIPTION_LEN + 1]);
	PACKED(char szSystemStatus[WSASYS_STATUS_LEN + 1]);
	PACKED(unsigned short iMaxSockets);
	PACKED(unsigned short iMaxUdpDg);
	PACKED(char FAR * lpVendorInfo);
} WSADATA, *LPWSADATA;

struct SERVICE_ASYNC_INFO;
typedef SERVICE_ASYNC_INFO *LPSERVICE_ASYNC_INFO;
struct SERVICE_INFOA;
typedef SERVICE_INFOA *LPSERVICE_INFOA;
struct SERVICE_INFOW;
typedef SERVICE_INFOW *LPSERVICE_INFOW;
struct TRANSMIT_FILE_BUFFERS;
typedef TRANSMIT_FILE_BUFFERS *LPTRANSMIT_FILE_BUFFERS;
struct sockaddr;
struct fd_set;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

int PASCAL FAR WSAStartup(WORD wVersionRequired, LPWSADATA lpWSAData);

BOOL PASCAL FAR AcceptEx(IN SOCKET sListenSocket, IN SOCKET sAcceptSocket, IN PVOID lpOutputBuffer,
	IN DWORD dwReceiveDataLength, IN DWORD dwLocalAddressLength, IN DWORD dwRemoteAddressLength,
	OUT LPDWORD lpdwBytesReceived, IN LPOVERLAPPED lpOverlapped);
INT APIENTRY EnumProtocolsA(IN LPINT lpiProtocols, IN OUT LPVOID lpProtocolBuffer, IN OUT LPDWORD lpdwBufferLength);
INT APIENTRY EnumProtocolsW(IN LPINT lpiProtocols, IN OUT LPVOID lpProtocolBuffer, IN OUT LPDWORD lpdwBufferLength);
VOID PASCAL FAR GetAcceptExSockaddrs(IN PVOID lpOutputBuffer, IN DWORD dwReceiveDataLength,
	IN DWORD dwLocalAddressLength, IN DWORD dwRemoteAddressLength, OUT struct sockaddr **LocalSockaddr,
	OUT LPINT LocalSockaddrLength, OUT struct sockaddr **RemoteSockaddr, OUT LPINT RemoteSockaddrLength);
INT APIENTRY GetAddressByNameA(IN DWORD dwNameSpace, IN LPGUID lpServiceType, IN LPSTR lpServiceName OPTIONAL,
	IN LPINT lpiProtocols OPTIONAL, IN DWORD dwResolution, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo OPTIONAL,
	IN OUT LPVOID lpCsaddrBuffer, IN OUT LPDWORD lpdwBufferLength, IN OUT LPSTR lpAliasBuffer OPTIONAL,
	IN OUT LPDWORD lpdwAliasBufferLength OPTIONAL);
INT APIENTRY GetAddressByNameW(IN DWORD dwNameSpace, IN LPGUID lpServiceType, IN LPWSTR lpServiceName OPTIONAL,
	IN LPINT lpiProtocols OPTIONAL, IN DWORD dwResolution, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo OPTIONAL,
	IN OUT LPVOID lpCsaddrBuffer, IN OUT LPDWORD lpdwBufferLength, IN OUT LPWSTR lpAliasBuffer OPTIONAL,
	IN OUT LPDWORD lpdwAliasBufferLength OPTIONAL);
INT APIENTRY GetNameByTypeA(IN LPGUID lpServiceType, IN OUT LPSTR lpServiceName, IN DWORD dwNameLength);
INT APIENTRY GetNameByTypeW(IN LPGUID lpServiceType, IN OUT LPWSTR lpServiceName, IN DWORD dwNameLength);
INT APIENTRY GetServiceA(IN DWORD dwNameSpace, IN LPGUID lpGuid, IN LPSTR lpServiceName, IN DWORD dwProperties,
	IN OUT LPVOID lpBuffer, IN OUT LPDWORD lpdwBufferSize, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo);
INT APIENTRY GetServiceW(IN DWORD dwNameSpace, IN LPGUID lpGuid, IN LPWSTR lpServiceName, IN DWORD dwProperties,
	IN OUT LPVOID lpBuffer, IN OUT LPDWORD lpdwBufferSize, IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo);
INT APIENTRY GetTypeByNameA(IN LPSTR lpServiceName, IN OUT LPGUID lpServiceType);
INT APIENTRY GetTypeByNameW(IN LPWSTR lpServiceName, IN OUT LPGUID lpServiceType);
INT APIENTRY SetServiceA(IN DWORD dwNameSpace, IN DWORD dwOperation, IN DWORD dwFlags, IN LPSERVICE_INFOA lpServiceInfo,
	IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, IN OUT LPDWORD lpdwStatusFlags);
INT APIENTRY SetServiceW(IN DWORD dwNameSpace, IN DWORD dwOperation, IN DWORD dwFlags, IN LPSERVICE_INFOW lpServiceInfo,
	IN LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, IN OUT LPDWORD lpdwStatusFlags);
BOOL PASCAL FAR TransmitFile(IN SOCKET hSocket, IN HANDLE hFile, IN DWORD nNumberOfBytesToWrite, IN DWORD nNumberOfBytesPerSend,
	IN LPOVERLAPPED lpOverlapped, IN LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers, IN DWORD dwReserved);

HANDLE PASCAL FAR WSAAsyncGetHostByAddr(HWND hWnd, u_int wMsg, const char FAR * addr, int len, int type, char FAR * buf, int buflen);
HANDLE PASCAL FAR WSAAsyncGetHostByName(HWND hWnd, u_int wMsg, const char FAR * name, char FAR * buf, int buflen);
HANDLE PASCAL FAR WSAAsyncGetProtoByName(HWND hWnd, u_int wMsg, const char FAR * name, char FAR * buf, int buflen);
HANDLE PASCAL FAR WSAAsyncGetProtoByNumber(HWND hWnd, u_int wMsg, int number, char FAR * buf, int buflen);
HANDLE PASCAL FAR WSAAsyncGetServByName(HWND hWnd, u_int wMsg, const char FAR * name, const char FAR * proto, char FAR * buf, int buflen);
HANDLE PASCAL FAR WSAAsyncGetServByPort(HWND hWnd, u_int wMsg, int port, const char FAR * proto, char FAR * buf, int buflen);
int PASCAL FAR WSAAsyncSelect(SOCKET s, HWND hWnd, u_int wMsg, long lEvent);
int PASCAL FAR WSAGetLastError(void);
int PASCAL FAR WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
int PASCAL FAR WSACancelBlockingCall(void);
int PASCAL FAR WSACleanup(void);
BOOL PASCAL FAR WSAIsBlocking(void);
int PASCAL FAR WSARecvEx(SOCKET s, char FAR *buf, int len, int FAR *flags);
FARPROC PASCAL FAR WSASetBlockingHook(FARPROC lpBlockFunc);
void PASCAL FAR WSASetLastError(int iError);
int PASCAL FAR WSAUnhookBlockingHook(void);
int PASCAL FAR __WSAFDIsSet(SOCKET, fd_set FAR *);

SOCKET PASCAL FAR _accept(SOCKET s, struct sockaddr FAR *addr, int FAR *addrlen);
int PASCAL FAR _bind(SOCKET s, const struct sockaddr FAR *addr, int namelen);
int PASCAL FAR _closesocket(SOCKET s);
int PASCAL FAR _connect(SOCKET s, const struct sockaddr FAR *name, int namelen);
int PASCAL FAR _gethostname(char FAR * name, int namelen);
int PASCAL FAR _getpeername(SOCKET s, struct sockaddr FAR *name, int FAR * namelen);
struct protoent FAR * PASCAL FAR _getprotobyname(const char FAR * name);
struct protoent FAR * PASCAL FAR _getprotobynumber(int proto);
struct servent FAR * PASCAL FAR _getservbyname(const char FAR * name, const char FAR * proto);
struct servent FAR * PASCAL FAR _getservbyport(int port, const char FAR * proto);
int PASCAL FAR _getsockname(SOCKET s, struct sockaddr FAR *name, int FAR * namelen);
int PASCAL FAR _getsockopt(SOCKET s, int level, int optname, char FAR * optval, int FAR *optlen);
u_long PASCAL FAR _htonl(u_long hostlong);
u_short PASCAL FAR _htons(u_short hostshort);
unsigned long PASCAL FAR _inet_addr(const char FAR * cp);
char FAR * PASCAL FAR _inet_ntoa(struct in_addr in);
int PASCAL FAR _ioctlsocket(SOCKET s, long cmd, u_long FAR *argp);
u_long PASCAL FAR _ntohl(u_long netlong);
u_short PASCAL FAR _ntohs(u_short netshort);
int PASCAL FAR _recv(SOCKET s, char FAR * buf, int len, int flags);
int PASCAL FAR _recvfrom(SOCKET s, char FAR * buf, int len, int flags, struct sockaddr FAR *from, int FAR * fromlen);
int PASCAL FAR _send(SOCKET s, const char FAR * buf, int len, int flags);
int PASCAL FAR _sendto(SOCKET s, const char FAR * buf, int len, int flags, const struct sockaddr FAR *to, int tolen);
int PASCAL FAR _setsockopt(SOCKET s, int level, int optname, const char FAR * optval, int optlen);
int PASCAL FAR _shutdown(SOCKET s, int how);
SOCKET PASCAL FAR _socket(int af, int type, int protocol);

#	if defined(_BUILTIN_DLL)
void *WSock32_GetAddressByOrder(int order);
void *WSock32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__WSock32_h__)
