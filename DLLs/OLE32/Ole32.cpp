/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Ole32.cpp,v 1.1 2003/05/01 03:31:53 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Ole32.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Ole32.h"
#include "Win32Trace.h"
#include "Win32Error.h"

extern "C" WINOLEAPI
BindMoniker
(LPMONIKER pmk, DWORD grfOpt, REFIID iidResult, LPVOID FAR* ppvResult)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "BindMoniker", "LPMONIKER", pmk, "DWORD", grfOpt, "REFIID", iidResult, "LPVOID FAR*", ppvResult, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CLSIDFromProgID
(LPCOLESTR lpszProgID, LPCLSID lpclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CLSIDFromProgID", "LPCOLESTR", lpszProgID, "LPCLSID", lpclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CLSIDFromProgIDEx
(LPCOLESTR lpszProgID, LPCLSID lpclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CLSIDFromProgIDEx", "LPCOLESTR", lpszProgID, "LPCLSID", lpclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CLSIDFromString
(LPOLESTR lpsz, LPCLSID pclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CLSIDFromString", "LPOLESTR", lpsz, "LPCLSID", pclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(ULONG)
CoAddRefServerProcess
(void)
{
	ULONG rc = 0;
	WIN32API_ENTER("ULONG", "CoAddRefServerProcess", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(DWORD)
CoBuildVersion
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "CoBuildVersion", "VOID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoCancelCall
(DWORD dwThreadId)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoCancelCall", "DWORD", dwThreadId, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoCopyProxy
(IUnknown *pProxy, IUnknown **ppCopy)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoCopyProxy", "IUnknown*", pProxy, "IUnknown**", ppCopy, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoCreateFreeThreadedMarshaler
(LPUNKNOWN punkOuter, LPUNKNOWN *ppunkMarshal)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoCreateFreeThreadedMarshaler", "LPUNKNOWN", punkOuter, "LPUNKNOWN*", ppunkMarshal, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoCreateGuid
(GUID FAR *pguid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoCreateGuid", "GUID FAR*", pguid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoCreateInstance
(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID FAR* ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoCreateInstance", "REFCLSID", rclsid, "LPUNKNOWN", pUnkOuter, "DWORD", dwClsContext, "REFIID", riid, "LPVOID FAR*", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoCreateInstanceEx
(REFCLSID Clsid, IUnknown * punkOuter, DWORD dwClsCtx, COSERVERINFO * pServerInfo, DWORD dwCount, MULTI_QI * pResults)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoCreateInstanceEx", "REFCLSID", Clsid, "IUnknown *", punkOuter, "DWORD", dwClsCtx, "COSERVERINFO *", pServerInfo, "DWORD", dwCount, "MULTI_QI *", pResults, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoDisconnectObject
(LPUNKNOWN pUnk, DWORD dwReserved)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoDisconnectObject", "LPUNKNOWN", pUnk, "DWORD", dwReserved, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
CoDosDateTimeToFileTime
(WORD nDosDate, WORD nDosTime, FILETIME FAR* lpFileTime)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CoDosDateTimeToFileTime", "WORD", nDosDate, "WORD", nDosTime, "FILETIME FAR*", lpFileTime, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoFileTimeNow
(FILETIME FAR* lpFileTime)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoFileTimeNow", "FILETIME FAR*", lpFileTime, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
CoFileTimeToDosDateTime
(FILETIME FAR* lpFileTime, LPWORD lpDosDate, LPWORD lpDosTime)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CoFileTimeToDosDateTime", "FILETIME FAR*", lpFileTime, "LPWORD", lpDosDate, "LPWORD", lpDosTime, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(void)
CoFreeAllLibraries
(void)
{
	WIN32API_ENTER("void", "CoFreeAllLibraries", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI_(void)
CoFreeLibrary
(HINSTANCE hInst)
{
	WIN32API_ENTER("void", "CoFreeLibrary", "HINSTANCE", hInst, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI_(void)
CoFreeUnusedLibraries
(void)
{
	WIN32API_ENTER("void", "CoFreeUnusedLibraries", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI
CoGetCallContext
(REFIID riid, void **ppInterface)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetCallContext", "REFIID", riid, "void**", ppInterface, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetCancelObject
(DWORD dwThreadId, REFIID iid, void **ppUnk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetCancelObject", "DWORD", dwThreadId, "REFIID", iid, "void**", ppUnk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetClassObject
(REFCLSID rclsid, DWORD dwClsContext, LPVOID pvReserved, REFIID riid, LPVOID FAR* ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetClassObject", "REFCLSID", rclsid, "DWORD", dwClsContext, "LPVOID", pvReserved, "REFIID", riid, "LPVOID FAR*", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(DWORD)
CoGetCurrentProcess
(void)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "CoGetCurrentProcess", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetInstanceFromFile
(COSERVERINFO * pServerInfo, CLSID * pClsid, IUnknown * punkOuter, DWORD dwClsCtx, DWORD grfMode, OLECHAR * pwszName, DWORD dwCount, MULTI_QI * pResults)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetInstanceFromFile", "COSERVERINFO *", pServerInfo, "CLSID *", pClsid, "IUnknown *", punkOuter, "DWORD", dwClsCtx, "DWORD", grfMode, "OLECHAR *", pwszName, "DWORD", dwCount, "MULTI_QI *", pResults, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetInstanceFromIStorage
(COSERVERINFO * pServerInfo, CLSID * pClsid, IUnknown * punkOuter, DWORD dwClsCtx, struct IStorage * pstg, DWORD dwCount, MULTI_QI * pResults)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetInstanceFromIStorage", "COSERVERINFO *", pServerInfo, "CLSID *", pClsid, "IUnknown *", punkOuter, "DWORD", dwClsCtx, "struct IStorage *", pstg, "DWORD", dwCount, "MULTI_QI *", pResults, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetInterfaceAndReleaseStream
(LPSTREAM pStm, REFIID iid, LPVOID FAR* ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetInterfaceAndReleaseStream", "LPSTREAM", pStm, "REFIID", iid, "LPVOID FAR*", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetMalloc
(DWORD dwMemContext, LPMALLOC FAR* ppMalloc)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetMalloc", "DWORD", dwMemContext, "LPMALLOC FAR*", ppMalloc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetMarshalSizeMax
(ULONG *pulSize, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetMarshalSizeMax", "ULONG*", pulSize, "REFIID", riid, "LPUNKNOWN", pUnk, "DWORD", dwDestContext, "LPVOID", pvDestContext, "DWORD", mshlflags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetObject
(LPCWSTR pszName, BIND_OPTS *pBindOptions, REFIID riid, void **ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetObject", "LPCWSTR", pszName, "BIND_OPTS*", pBindOptions, "REFIID", riid, "void**", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetPSClsid
(REFIID riid, CLSID *pClsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetPSClsid", "REFIID", riid, "CLSID*", pClsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetStandardMarshal
(REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags, LPMARSHAL FAR* ppMarshal)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetStandardMarshal", "REFIID", riid, "LPUNKNOWN", pUnk, "DWORD", dwDestContext, "LPVOID", pvDestContext, "DWORD", mshlflags, "LPMARSHAL FAR*", ppMarshal, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetStdMarshalEx
(LPUNKNOWN pUnkOuter, DWORD smexflags, LPUNKNOWN FAR* ppUnkInner)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetStdMarshalEx", "LPUNKNOWN", pUnkOuter, "DWORD", smexflags, "LPUNKNOWN FAR*", ppUnkInner, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoGetTreatAsClass
(REFCLSID clsidOld, LPCLSID pClsidNew)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoGetTreatAsClass", "REFCLSID", clsidOld, "LPCLSID", pClsidNew, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoImpersonateClient
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoImpersonateClient", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoInitialize
(LPVOID pvReserved)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoInitialize", "LPVOID", pvReserved, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoInitializeEx
(LPVOID pvReserved, DWORD dwCoInit)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoInitializeEx", "LPVOID", pvReserved, "DWORD", dwCoInit, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoInitializeSecurity
(PSECURITY_DESCRIPTOR pSecDesc, LONG cAuthSvc, SOLE_AUTHENTICATION_SERVICE *asAuthSvc, void *pReserved1, DWORD dwAuthnLevel, DWORD dwImpLevel, void *pReserved2, DWORD dwCapabilities, void *pReserved3)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoInitializeSecurity", "PSECURITY_DESCRIPTOR", pSecDesc, "LONG", cAuthSvc, "SOLE_AUTHENTICATION_SERVICE*", asAuthSvc, "void*", pReserved1, "DWORD", dwAuthnLevel, "DWORD", dwImpLevel, "void*", pReserved2, "DWORD", dwCapabilities, "void*", pReserved3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoInstall
(IBindCtx * pbc, DWORD dwFlags, uCLSSPEC * pClassSpec, QUERYCONTEXT * pQuery, LPWSTR pszCodeBase)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoInstall", "IBindCtx *", pbc, "DWORD", dwFlags, "uCLSSPEC *", pClassSpec, "QUERYCONTEXT *", pQuery, "LPWSTR", pszCodeBase, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
CoIsHandlerConnected
(LPUNKNOWN pUnk)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CoIsHandlerConnected", "LPUNKNOWN", pUnk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
CoIsOle1Class
(REFCLSID rclsid)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CoIsOle1Class", "REFCLSID", rclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(HINSTANCE)
CoLoadLibrary
(LPOLESTR lpszLibName, BOOL bAutoFree)
{
	HINSTANCE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HINSTANCE", "CoLoadLibrary", "LPOLESTR", lpszLibName, "BOOL", bAutoFree, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoLockObjectExternal
(LPUNKNOWN pUnk, BOOL fLock, BOOL fLastUnlockReleases)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoLockObjectExternal", "LPUNKNOWN", pUnk, "BOOL", fLock, "BOOL", fLastUnlockReleases, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoMarshalHresult
(LPSTREAM pstm, HRESULT hresult)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoMarshalHresult", "LPSTREAM", pstm, "HRESULT", hresult, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoMarshalInterThreadInterfaceInStream
(REFIID riid, LPUNKNOWN pUnk, LPSTREAM *ppStm)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoMarshalInterThreadInterfaceInStream", "REFIID", riid, "LPUNKNOWN", pUnk, "LPSTREAM*", ppStm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoMarshalInterface
(LPSTREAM pStm, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoMarshalInterface", "LPSTREAM", pStm, "REFIID", riid, "LPUNKNOWN", pUnk, "DWORD", dwDestContext, "LPVOID", pvDestContext, "DWORD", mshlflags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoQueryAuthenticationServices
(DWORD *pcAuthSvc, SOLE_AUTHENTICATION_SERVICE **asAuthSvc)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoQueryAuthenticationServices", "DWORD*", pcAuthSvc, "SOLE_AUTHENTICATION_SERVICE**", asAuthSvc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoQueryClientBlanket
(DWORD *pAuthnSvc, DWORD *pAuthzSvc, OLECHAR **pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTHZ_HANDLE *pPrivs, DWORD *pCapabilities)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoQueryClientBlanket", "DWORD*", pAuthnSvc, "DWORD*", pAuthzSvc, "OLECHAR**", pServerPrincName, "DWORD*", pAuthnLevel, "DWORD*", pImpLevel, "RPC_AUTHZ_HANDLE*", pPrivs, "DWORD*", pCapabilities, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoQueryProxyBlanket
(IUnknown *pProxy, DWORD *pwAuthnSvc, DWORD *pAuthzSvc, OLECHAR **pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTH_IDENTITY_HANDLE *pAuthInfo, DWORD *pCapabilites)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoQueryProxyBlanket", "IUnknown*", pProxy, "DWORD*", pwAuthnSvc, "DWORD*", pAuthzSvc, "OLECHAR**", pServerPrincName, "DWORD*", pAuthnLevel, "DWORD*", pImpLevel, "RPC_AUTH_IDENTITY_HANDLE*", pAuthInfo, "DWORD*", pCapabilites, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRegisterChannelHook
(REFGUID ExtensionUuid, IChannelHook *pChannelHook)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRegisterChannelHook", "REFGUID", ExtensionUuid, "IChannelHook*", pChannelHook, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRegisterClassObject
(REFCLSID rclsid, LPUNKNOWN pUnk, DWORD dwClsContext, DWORD flags, LPDWORD lpdwRegister)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRegisterClassObject", "REFCLSID", rclsid, "LPUNKNOWN", pUnk, "DWORD", dwClsContext, "DWORD", flags, "LPDWORD", lpdwRegister, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRegisterMallocSpy
(LPMALLOCSPY pMallocSpy)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRegisterMallocSpy", "LPMALLOCSPY", pMallocSpy, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRegisterMessageFilter
(LPMESSAGEFILTER lpMessageFilter, LPMESSAGEFILTER FAR* lplpMessageFilter)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRegisterMessageFilter", "LPMESSAGEFILTER", lpMessageFilter, "LPMESSAGEFILTER FAR*", lplpMessageFilter, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRegisterPSClsid
(REFIID riid, REFCLSID rclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRegisterPSClsid", "REFIID", riid, "REFCLSID", rclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRegisterSurrogate
(LPSURROGATE pSurrogate)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRegisterSurrogate", "LPSURROGATE", pSurrogate, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoReleaseMarshalData
(LPSTREAM pStm)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoReleaseMarshalData", "LPSTREAM", pStm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(ULONG)
CoReleaseServerProcess
(void)
{
	ULONG rc = 0;
	WIN32API_ENTER("ULONG", "CoReleaseServerProcess", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoResumeClassObjects
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoResumeClassObjects", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRevertToSelf
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRevertToSelf", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRevokeClassObject
(DWORD dwRegister)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRevokeClassObject", "DWORD", dwRegister, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoRevokeMallocSpy
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoRevokeMallocSpy", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoSetCancelObject
(IUnknown *pUnk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoSetCancelObject", "IUnknown*", pUnk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoSetProxyBlanket
(IUnknown *pProxy, DWORD dwAuthnSvc, DWORD dwAuthzSvc, OLECHAR *pServerPrincName, DWORD dwAuthnLevel, DWORD dwImpLevel, RPC_AUTH_IDENTITY_HANDLE pAuthInfo, DWORD dwCapabilities)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoSetProxyBlanket", "IUnknown*", pProxy, "DWORD", dwAuthnSvc, "DWORD", dwAuthzSvc, "OLECHAR*", pServerPrincName, "DWORD", dwAuthnLevel, "DWORD", dwImpLevel, "RPC_AUTH_IDENTITY_HANDLE", pAuthInfo, "DWORD", dwCapabilities, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoSuspendClassObjects
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoSuspendClassObjects", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoSwitchCallContext
(IUnknown *pNewObject, IUnknown **ppOldObject)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoSwitchCallContext", "IUnknown*", pNewObject, "IUnknown**", ppOldObject, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(LPVOID)
CoTaskMemAlloc
(ULONG cb)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "CoTaskMemAlloc", "ULONG", cb, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(void)
CoTaskMemFree
(LPVOID pv)
{
	WIN32API_ENTER("void", "CoTaskMemFree", "LPVOID", pv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI_(LPVOID)
CoTaskMemRealloc
(LPVOID pv, ULONG cb)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "CoTaskMemRealloc", "LPVOID", pv, "ULONG", cb, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoTestCancel
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoTestCancel", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoTreatAsClass
(REFCLSID clsidOld, REFCLSID clsidNew)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoTreatAsClass", "REFCLSID", clsidOld, "REFCLSID", clsidNew, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(void)
CoUninitialize
(void)
{
	WIN32API_ENTER("void", "CoUninitialize", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI
CoUnmarshalHresult
(LPSTREAM pstm, HRESULT FAR * phresult)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoUnmarshalHresult", "LPSTREAM", pstm, "HRESULT FAR *", phresult, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CoUnmarshalInterface
(LPSTREAM pStm, REFIID riid, LPVOID FAR* ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CoUnmarshalInterface", "LPSTREAM", pStm, "REFIID", riid, "LPVOID FAR*", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateAntiMoniker
(LPMONIKER FAR* ppmk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateAntiMoniker", "LPMONIKER FAR*", ppmk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateBindCtx
(DWORD reserved, LPBC FAR* ppbc)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateBindCtx", "DWORD", reserved, "LPBC FAR*", ppbc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateClassMoniker
(REFCLSID rclsid, LPMONIKER FAR* ppmk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateClassMoniker", "REFCLSID", rclsid, "LPMONIKER FAR*", ppmk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateDataAdviseHolder
(LPDATAADVISEHOLDER FAR* ppDAHolder)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateDataAdviseHolder", "LPDATAADVISEHOLDER FAR*", ppDAHolder, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateDataCache
(LPUNKNOWN pUnkOuter, REFCLSID rclsid, REFIID iid, LPVOID FAR* ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateDataCache", "LPUNKNOWN", pUnkOuter, "REFCLSID", rclsid, "REFIID", iid, "LPVOID FAR*", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAUTAPI
CreateErrorInfo
(ICreateErrorInfo ** pperrinfo)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateErrorInfo", "ICreateErrorInfo **", pperrinfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateFileMoniker
(LPCOLESTR lpszPathName, LPMONIKER FAR* ppmk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateFileMoniker", "LPCOLESTR", lpszPathName, "LPMONIKER FAR*", ppmk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateGenericComposite
(LPMONIKER pmkFirst, LPMONIKER pmkRest, LPMONIKER FAR* ppmkComposite)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateGenericComposite", "LPMONIKER", pmkFirst, "LPMONIKER", pmkRest, "LPMONIKER FAR*", ppmkComposite, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateILockBytesOnHGlobal
(HGLOBAL hGlobal, BOOL fDeleteOnRelease, LPLOCKBYTES FAR* pplkbyt)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateILockBytesOnHGlobal", "HGLOBAL", hGlobal, "BOOL", fDeleteOnRelease, "LPLOCKBYTES FAR*", pplkbyt, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateItemMoniker
(LPCOLESTR lpszDelim, LPCOLESTR lpszItem, LPMONIKER FAR* ppmk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateItemMoniker", "LPCOLESTR", lpszDelim, "LPCOLESTR", lpszItem, "LPMONIKER FAR*", ppmk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateOleAdviseHolder
(LPOLEADVISEHOLDER FAR* ppOAHolder)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateOleAdviseHolder", "LPOLEADVISEHOLDER FAR*", ppOAHolder, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreatePointerMoniker
(LPUNKNOWN punk, LPMONIKER FAR* ppmk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreatePointerMoniker", "LPUNKNOWN", punk, "LPMONIKER FAR*", ppmk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateStdProgressIndicator
(HWND hwndParent, LPCOLESTR pszTitle, IBindStatusCallback * pIbscCaller, IBindStatusCallback ** ppIbsc)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateStdProgressIndicator", "HWND", hwndParent, "LPCOLESTR", pszTitle, "IBindStatusCallback *", pIbscCaller, "IBindStatusCallback **", ppIbsc, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
CreateStreamOnHGlobal
(HGLOBAL hGlobal, BOOL fDeleteOnRelease, LPSTREAM FAR* ppstm)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "CreateStreamOnHGlobal", "HGLOBAL", hGlobal, "BOOL", fDeleteOnRelease, "LPSTREAM FAR*", ppstm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" STDAPI
DllGetClassObject
(REFCLSID rclsid, REFIID riid, LPVOID FAR* ppv)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "DllGetClassObject", "REFCLSID", rclsid, "REFIID", riid, "LPVOID FAR*", ppv, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" STDAPI
DllRegisterServer
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "DllRegisterServer", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
DoDragDrop
(LPDATAOBJECT pDataObj, LPDROPSOURCE pDropSource, DWORD dwOKEffects, LPDWORD pdwEffect)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "DoDragDrop", "LPDATAOBJECT", pDataObj, "LPDROPSOURCE", pDropSource, "DWORD", dwOKEffects, "LPDWORD", pdwEffect, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
FmtIdToPropStgName
(const FMTID *pfmtid, LPOLESTR oszName)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "FmtIdToPropStgName", "const FMTID *pfmtid", 0, "LPOLESTR", oszName, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
FreePropVariantArray
(ULONG cVariants, PROPVARIANT *rgvars)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "FreePropVariantArray", "ULONG", cVariants, "PROPVARIANT *", rgvars, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
GetClassFile
(LPCOLESTR szFilename, CLSID FAR* pclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "GetClassFile", "LPCOLESTR", szFilename, "CLSID FAR*", pclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
GetConvertStg
(LPSTORAGE pStg)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "GetConvertStg", "LPSTORAGE", pStg, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAUTAPI
GetErrorInfo
(ULONG dwReserved, IErrorInfo ** pperrinfo)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "GetErrorInfo", "ULONG", dwReserved, "IErrorInfo **", pperrinfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
GetHGlobalFromILockBytes
(LPLOCKBYTES plkbyt, HGLOBAL FAR* phglobal)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "GetHGlobalFromILockBytes", "LPLOCKBYTES", plkbyt, "HGLOBAL FAR*", phglobal, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
GetHGlobalFromStream
(LPSTREAM pstm, HGLOBAL FAR* phglobal)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "GetHGlobalFromStream", "LPSTREAM", pstm, "HGLOBAL FAR*", phglobal, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
GetRunningObjectTable
(DWORD reserved, LPRUNNINGOBJECTTABLE FAR* pprot)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "GetRunningObjectTable", "DWORD", reserved, "LPRUNNINGOBJECTTABLE FAR*", pprot, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
IIDFromString
(LPOLESTR lpsz, LPIID lpiid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "IIDFromString", "LPOLESTR", lpsz, "LPIID", lpiid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
IsAccelerator
(HACCEL hAccel, int cAccelEntries, LPMSG lpMsg, WORD FAR* lpwCmd)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsAccelerator", "HACCEL", hAccel, "int", cAccelEntries, "LPMSG", lpMsg, "WORD FAR*", lpwCmd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
IsEqualGUID
(REFGUID rguid1, REFGUID rguid2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsEqualGUID", "REFGUID", rguid1, "REFGUID", rguid2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
MkParseDisplayName
(LPBC pbc, LPCOLESTR szUserName, ULONG FAR * pchEaten, LPMONIKER FAR * ppmk)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "MkParseDisplayName", "LPBC", pbc, "LPCOLESTR", szUserName, "ULONG FAR *", pchEaten, "LPMONIKER FAR *", ppmk, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
MonikerCommonPrefixWith
(LPMONIKER pmkThis, LPMONIKER pmkOther, LPMONIKER FAR* ppmkCommon)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "MonikerCommonPrefixWith", "LPMONIKER", pmkThis, "LPMONIKER", pmkOther, "LPMONIKER FAR*", ppmkCommon, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
MonikerRelativePathTo
(LPMONIKER pmkSrc, LPMONIKER pmkDest, LPMONIKER FAR* ppmkRelPath, BOOL dwReserved)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "MonikerRelativePathTo", "LPMONIKER", pmkSrc, "LPMONIKER", pmkDest, "LPMONIKER FAR*", ppmkRelPath, "BOOL", dwReserved, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(DWORD)
OleBuildVersion
(VOID)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "OleBuildVersion", "VOID", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleConvertIStorageToOLESTREAM
(LPSTORAGE pstg, LPOLESTREAM lpolestream)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleConvertIStorageToOLESTREAM", "LPSTORAGE", pstg, "LPOLESTREAM", lpolestream, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleConvertIStorageToOLESTREAMEx
(LPSTORAGE pstg, CLIPFORMAT cfFormat, LONG lWidth, LONG lHeight, DWORD dwSize, LPSTGMEDIUM pmedium, LPOLESTREAM polestm)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleConvertIStorageToOLESTREAMEx", "LPSTORAGE", pstg, "CLIPFORMAT", cfFormat, "LONG", lWidth, "LONG", lHeight, "DWORD", dwSize, "LPSTGMEDIUM", pmedium, "LPOLESTREAM", polestm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleConvertOLESTREAMToIStorage
(LPOLESTREAM lpolestream, LPSTORAGE pstg, const DVTARGETDEVICE FAR* ptd)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleConvertOLESTREAMToIStorage", "LPOLESTREAM", lpolestream, "LPSTORAGE", pstg, "const DVTARGETDEVICE FAR* ptd", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleConvertOLESTREAMToIStorageEx
(LPOLESTREAM polestm, LPSTORAGE pstg, CLIPFORMAT FAR* pcfFormat, LONG FAR* plwWidth, LONG FAR* plHeight, DWORD FAR* pdwSize, LPSTGMEDIUM pmedium)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleConvertOLESTREAMToIStorageEx", "LPOLESTREAM", polestm, "LPSTORAGE", pstg, "CLIPFORMAT FAR*", pcfFormat, "LONG FAR*", plwWidth, "LONG FAR*", plHeight, "DWORD FAR*", pdwSize, "LPSTGMEDIUM", pmedium, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreate
(REFCLSID rclsid, REFIID riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreate", "REFCLSID", rclsid, "REFIID", riid, "DWORD", renderopt, "LPFORMATETC", pFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR *", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateDefaultHandler
(REFCLSID clsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* lplpObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateDefaultHandler", "REFCLSID", clsid, "LPUNKNOWN", pUnkOuter, "REFIID", riid, "LPVOID FAR*", lplpObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateEmbeddingHelper
(REFCLSID clsid, LPUNKNOWN pUnkOuter, DWORD flags, LPCLASSFACTORY pCF, REFIID riid, LPVOID FAR* lplpObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateEmbeddingHelper", "REFCLSID", clsid, "LPUNKNOWN", pUnkOuter, "DWORD", flags, "LPCLASSFACTORY", pCF, "REFIID", riid, "LPVOID FAR*", lplpObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateEx
(REFCLSID rclsid, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateEx", "REFCLSID", rclsid, "REFIID", riid, "DWORD", dwFlags, "DWORD", renderopt, "ULONG", cFormats, "DWORD*", rgAdvf, "LPFORMATETC", rgFormatEtc, "IAdviseSink FAR*", lpAdviseSink, "DWORD FAR*", rgdwConnection, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateFromData
(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateFromData", "LPDATAOBJECT", pSrcDataObj, "REFIID", riid, "DWORD", renderopt, "LPFORMATETC", pFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateFromDataEx
(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateFromDataEx", "LPDATAOBJECT", pSrcDataObj, "REFIID", riid, "DWORD", dwFlags, "DWORD", renderopt, "ULONG", cFormats, "DWORD*", rgAdvf, "LPFORMATETC", rgFormatEtc, "IAdviseSink FAR*", lpAdviseSink, "DWORD FAR*", rgdwConnection, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateFromFile
(REFCLSID rclsid, LPCOLESTR lpszFileName, REFIID riid, DWORD renderopt, LPFORMATETC lpFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateFromFile", "REFCLSID", rclsid, "LPCOLESTR", lpszFileName, "REFIID", riid, "DWORD", renderopt, "LPFORMATETC", lpFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateFromFileEx
(REFCLSID rclsid, LPCOLESTR lpszFileName, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateFromFileEx", "REFCLSID", rclsid, "LPCOLESTR", lpszFileName, "REFIID", riid, "DWORD", dwFlags, "DWORD", renderopt, "ULONG", cFormats, "DWORD*", rgAdvf, "LPFORMATETC", rgFormatEtc, "IAdviseSink FAR*", lpAdviseSink, "DWORD FAR*", rgdwConnection, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateLink
(LPMONIKER pmkLinkSrc, REFIID riid, DWORD renderopt, LPFORMATETC lpFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateLink", "LPMONIKER", pmkLinkSrc, "REFIID", riid, "DWORD", renderopt, "LPFORMATETC", lpFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR *", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateLinkEx
(LPMONIKER pmkLinkSrc, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateLinkEx", "LPMONIKER", pmkLinkSrc, "REFIID", riid, "DWORD", dwFlags, "DWORD", renderopt, "ULONG", cFormats, "DWORD*", rgAdvf, "LPFORMATETC", rgFormatEtc, "IAdviseSink FAR*", lpAdviseSink, "DWORD FAR*", rgdwConnection, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateLinkFromData
(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateLinkFromData", "LPDATAOBJECT", pSrcDataObj, "REFIID", riid, "DWORD", renderopt, "LPFORMATETC", pFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateLinkFromDataEx
(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateLinkFromDataEx", "LPDATAOBJECT", pSrcDataObj, "REFIID", riid, "DWORD", dwFlags, "DWORD", renderopt, "ULONG", cFormats, "DWORD*", rgAdvf, "LPFORMATETC", rgFormatEtc, "IAdviseSink FAR*", lpAdviseSink, "DWORD FAR*", rgdwConnection, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateLinkToFile
(LPCOLESTR lpszFileName, REFIID riid, DWORD renderopt, LPFORMATETC lpFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateLinkToFile", "LPCOLESTR", lpszFileName, "REFIID", riid, "DWORD", renderopt, "LPFORMATETC", lpFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateLinkToFileEx
(LPCOLESTR lpszFileName, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateLinkToFileEx", "LPCOLESTR", lpszFileName, "REFIID", riid, "DWORD", dwFlags, "DWORD", renderopt, "ULONG", cFormats, "DWORD*", rgAdvf, "LPFORMATETC", rgFormatEtc, "IAdviseSink FAR*", lpAdviseSink, "DWORD FAR*", rgdwConnection, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(HOLEMENU)
OleCreateMenuDescriptor
(HMENU hmenuCombined, LPOLEMENUGROUPWIDTHS lpMenuWidths)
{
	HOLEMENU rc = NULL;
	WIN32API_ENTER("HOLEMENU", "OleCreateMenuDescriptor", "HMENU", hmenuCombined, "LPOLEMENUGROUPWIDTHS", lpMenuWidths, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleCreateStaticFromData
(LPDATAOBJECT pSrcDataObj, REFIID iid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleCreateStaticFromData", "LPDATAOBJECT", pSrcDataObj, "REFIID", iid, "DWORD", renderopt, "LPFORMATETC", pFormatEtc, "LPOLECLIENTSITE", pClientSite, "LPSTORAGE", pStg, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleDestroyMenuDescriptor
(HOLEMENU holemenu)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleDestroyMenuDescriptor", "HOLEMENU", holemenu, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleDoAutoConvert
(LPSTORAGE pStg, LPCLSID pClsidNew)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleDoAutoConvert", "LPSTORAGE", pStg, "LPCLSID", pClsidNew, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleDraw
(LPUNKNOWN pUnknown, DWORD dwAspect, HDC hdcDraw, LPCRECT lprcBounds)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleDraw", "LPUNKNOWN", pUnknown, "DWORD", dwAspect, "HDC", hdcDraw, "LPCRECT", lprcBounds, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(HANDLE)
OleDuplicateData
(HANDLE hSrc, CLIPFORMAT cfFormat, UINT uiFlags)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "OleDuplicateData", "HANDLE", hSrc, "CLIPFORMAT", cfFormat, "UINT", uiFlags, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleFlushClipboard
(void)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleFlushClipboard", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleGetAutoConvert
(REFCLSID clsidOld, LPCLSID pClsidNew)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleGetAutoConvert", "REFCLSID", clsidOld, "LPCLSID", pClsidNew, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleGetClipboard
(LPDATAOBJECT FAR* ppDataObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleGetClipboard", "LPDATAOBJECT FAR*", ppDataObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(HGLOBAL)
OleGetIconOfClass
(REFCLSID rclsid, LPOLESTR lpszLabel, BOOL fUseTypeAsLabel)
{
	HGLOBAL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HGLOBAL", "OleGetIconOfClass", "REFCLSID", rclsid, "LPOLESTR", lpszLabel, "BOOL", fUseTypeAsLabel, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(HGLOBAL)
OleGetIconOfFile
(LPOLESTR lpszPath, BOOL fUseFileAsLabel)
{
	HGLOBAL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HGLOBAL", "OleGetIconOfFile", "LPOLESTR", lpszPath, "BOOL", fUseFileAsLabel, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleInitialize
(LPVOID pvReserved)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleInitialize", "LPVOID", pvReserved, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleIsCurrentClipboard
(LPDATAOBJECT pDataObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleIsCurrentClipboard", "LPDATAOBJECT", pDataObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(BOOL)
OleIsRunning
(LPOLEOBJECT pObject)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "OleIsRunning", "LPOLEOBJECT", pObject, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleLoad
(LPSTORAGE pStg, REFIID riid, LPOLECLIENTSITE pClientSite, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleLoad", "LPSTORAGE", pStg, "REFIID", riid, "LPOLECLIENTSITE", pClientSite, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleLoadFromStream
(LPSTREAM pStm, REFIID iidInterface, LPVOID FAR* ppvObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleLoadFromStream", "LPSTREAM", pStm, "REFIID", iidInterface, "LPVOID FAR*", ppvObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleLockRunning
(LPUNKNOWN pUnknown, BOOL fLock, BOOL fLastUnlockCloses)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleLockRunning", "LPUNKNOWN", pUnknown, "BOOL", fLock, "BOOL", fLastUnlockCloses, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(HGLOBAL)
OleMetafilePictFromIconAndLabel
(HICON hIcon, LPOLESTR lpszLabel, LPOLESTR lpszSourceFile, UINT iIconIndex)
{
	HGLOBAL rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HGLOBAL", "OleMetafilePictFromIconAndLabel", "HICON", hIcon, "LPOLESTR", lpszLabel, "LPOLESTR", lpszSourceFile, "UINT", iIconIndex, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleNoteObjectVisible
(LPUNKNOWN pUnknown, BOOL fVisible)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleNoteObjectVisible", "LPUNKNOWN", pUnknown, "BOOL", fVisible, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleQueryCreateFromData
(LPDATAOBJECT pSrcDataObject)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleQueryCreateFromData", "LPDATAOBJECT", pSrcDataObject, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleQueryLinkFromData
(LPDATAOBJECT pSrcDataObject)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleQueryLinkFromData", "LPDATAOBJECT", pSrcDataObject, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleRegEnumFormatEtc
(REFCLSID clsid, DWORD dwDirection, LPENUMFORMATETC FAR* ppenum)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleRegEnumFormatEtc", "REFCLSID", clsid, "DWORD", dwDirection, "LPENUMFORMATETC FAR*", ppenum, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleRegEnumVerbs
(REFCLSID clsid, LPENUMOLEVERB FAR* ppenum)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleRegEnumVerbs", "REFCLSID", clsid, "LPENUMOLEVERB FAR*", ppenum, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleRegGetMiscStatus
(REFCLSID clsid, DWORD dwAspect, DWORD FAR* pdwStatus)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleRegGetMiscStatus", "REFCLSID", clsid, "DWORD", dwAspect, "DWORD FAR*", pdwStatus, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleRegGetUserType
(REFCLSID clsid, DWORD dwFormOfType, LPOLESTR FAR* pszUserType)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleRegGetUserType", "REFCLSID", clsid, "DWORD", dwFormOfType, "LPOLESTR FAR*", pszUserType, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleRun
(LPUNKNOWN pUnknown)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleRun", "LPUNKNOWN", pUnknown, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleSave
(LPPERSISTSTORAGE pPS, LPSTORAGE pStg, BOOL fSameAsLoad)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleSave", "LPPERSISTSTORAGE", pPS, "LPSTORAGE", pStg, "BOOL", fSameAsLoad, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleSaveToStream
(LPPERSISTSTREAM pPStm, LPSTREAM pStm)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleSaveToStream", "LPPERSISTSTREAM", pPStm, "LPSTREAM", pStm, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleSetAutoConvert
(REFCLSID clsidOld, REFCLSID clsidNew)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleSetAutoConvert", "REFCLSID", clsidOld, "REFCLSID", clsidNew, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleSetClipboard
(LPDATAOBJECT pDataObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleSetClipboard", "LPDATAOBJECT", pDataObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleSetContainedObject
(LPUNKNOWN pUnknown, BOOL fContained)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleSetContainedObject", "LPUNKNOWN", pUnknown, "BOOL", fContained, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleSetMenuDescriptor
(HOLEMENU holemenu, HWND hwndFrame, HWND hwndActiveObject, LPOLEINPLACEFRAME lpFrame, LPOLEINPLACEACTIVEOBJECT lpActiveObj)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleSetMenuDescriptor", "HOLEMENU", holemenu, "HWND", hwndFrame, "HWND", hwndActiveObject, "LPOLEINPLACEFRAME", lpFrame, "LPOLEINPLACEACTIVEOBJECT", lpActiveObj, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
OleTranslateAccelerator
(LPOLEINPLACEFRAME lpFrame, LPOLEINPLACEFRAMEINFO lpFrameInfo, LPMSG lpmsg)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "OleTranslateAccelerator", "LPOLEINPLACEFRAME", lpFrame, "LPOLEINPLACEFRAMEINFO", lpFrameInfo, "LPMSG", lpmsg, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(void)
OleUninitialize
(void)
{
	WIN32API_ENTER("void", "OleUninitialize", "void", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI
ProgIDFromCLSID
(REFCLSID clsid, LPOLESTR FAR* lplpszProgID)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "ProgIDFromCLSID", "REFCLSID", clsid, "LPOLESTR FAR*", lplpszProgID, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
PropStgNameToFmtId
(const LPOLESTR oszName, FMTID *pfmtid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "PropStgNameToFmtId", "const LPOLESTR oszName", 0, "FMTID*", pfmtid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
PropVariantClear
(PROPVARIANT * pvar)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "PropVariantClear", "PROPVARIANT *", pvar, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
PropVariantCopy
(PROPVARIANT * pvarDest, const PROPVARIANT * pvarSrc)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "PropVariantCopy", "PROPVARIANT *", pvarDest, "const PROPVARIANT * pvarSrc", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
ReadClassStg
(LPSTORAGE pStg, CLSID FAR* pclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "ReadClassStg", "LPSTORAGE", pStg, "CLSID FAR*", pclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
ReadClassStm
(LPSTREAM pStm, CLSID FAR* pclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "ReadClassStm", "LPSTREAM", pStm, "CLSID FAR*", pclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
ReadFmtUserTypeStg
(LPSTORAGE pstg, CLIPFORMAT FAR* pcf, LPOLESTR FAR* lplpszUserType)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "ReadFmtUserTypeStg", "LPSTORAGE", pstg, "CLIPFORMAT FAR*", pcf, "LPOLESTR FAR*", lplpszUserType, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
RegisterDragDrop
(HWND hwnd, LPDROPTARGET pDropTarget)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "RegisterDragDrop", "HWND", hwnd, "LPDROPTARGET", pDropTarget, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(void)
ReleaseStgMedium
(LPSTGMEDIUM arg0)
{
	WIN32API_ENTER("void", "ReleaseStgMedium", "LPSTGMEDIUM", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" WINOLEAPI
RevokeDragDrop
(HWND hwnd)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "RevokeDragDrop", "HWND", hwnd, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
SetConvertStg
(LPSTORAGE pStg, BOOL fConvert)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SetConvertStg", "LPSTORAGE", pStg, "BOOL", fConvert, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAUTAPI
SetErrorInfo
(ULONG dwReserved, IErrorInfo * perrinfo)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "SetErrorInfo", "ULONG", dwReserved, "IErrorInfo *", perrinfo, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgCreateDocfile
(const OLECHAR FAR* pwcsName, DWORD grfMode, DWORD reserved, IStorage FAR * FAR *ppstgOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgCreateDocfile", "const OLECHAR FAR* pwcsName", 0, "DWORD", grfMode, "DWORD", reserved, "IStorage FAR * FAR*", ppstgOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgCreateDocfileOnILockBytes
(ILockBytes FAR *plkbyt, DWORD grfMode, DWORD reserved, IStorage FAR * FAR *ppstgOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgCreateDocfileOnILockBytes", "ILockBytes FAR*", plkbyt, "DWORD", grfMode, "DWORD", reserved, "IStorage FAR * FAR*", ppstgOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgCreatePropSetStg
(IStorage *pStorage, DWORD dwReserved, IPropertySetStorage **ppPropSetStg)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgCreatePropSetStg", "IStorage*", pStorage, "DWORD", dwReserved, "IPropertySetStorage**", ppPropSetStg, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgCreatePropStg
(IUnknown* pUnk, REFFMTID fmtid, const CLSID *pclsid, DWORD grfFlags, DWORD dwReserved, IPropertyStorage **ppPropStg)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgCreatePropStg", "IUnknown*", pUnk, "REFFMTID", fmtid, "const CLSID *pclsid", 0, "DWORD", grfFlags, "DWORD", dwReserved, "IPropertyStorage**", ppPropStg, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgCreateStorageEx
(const WCHAR* pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, void * reserved1, void * reserved2, REFIID riid, void ** ppObjectOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgCreateStorageEx", "const WCHAR* pwcsName", 0, "DWORD", grfMode, "DWORD", stgfmt, "DWORD", grfAttrs, "void *", reserved1, "void *", reserved2, "REFIID", riid, "void **", ppObjectOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgGetIFillLockBytesOnFile
(OLECHAR const *pwcsName, IFillLockBytes **ppflb)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgGetIFillLockBytesOnFile", "OLECHAR const*", pwcsName, "IFillLockBytes**", ppflb, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgGetIFillLockBytesOnILockBytes
(ILockBytes *pilb, IFillLockBytes **ppflb)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgGetIFillLockBytesOnILockBytes", "ILockBytes*", pilb, "IFillLockBytes**", ppflb, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgIsStorageFile
(const OLECHAR FAR* pwcsName)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgIsStorageFile", "const OLECHAR FAR* pwcsName", 0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgIsStorageILockBytes
(ILockBytes FAR* plkbyt)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgIsStorageILockBytes", "ILockBytes FAR*", plkbyt, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgOpenAsyncDocfileOnIFillLockBytes
(IFillLockBytes *pflb, DWORD grfMode, DWORD asyncFlags, IStorage **ppstgOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgOpenAsyncDocfileOnIFillLockBytes", "IFillLockBytes*", pflb, "DWORD", grfMode, "DWORD", asyncFlags, "IStorage**", ppstgOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgOpenPropStg
(IUnknown* pUnk, REFFMTID fmtid, DWORD grfFlags, DWORD dwReserved, IPropertyStorage **ppPropStg)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgOpenPropStg", "IUnknown*", pUnk, "REFFMTID", fmtid, "DWORD", grfFlags, "DWORD", dwReserved, "IPropertyStorage**", ppPropStg, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgOpenStorage
(const OLECHAR FAR* pwcsName, IStorage FAR *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage FAR * FAR *ppstgOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgOpenStorage", "const OLECHAR FAR* pwcsName", 0, "IStorage FAR*", pstgPriority, "DWORD", grfMode, "SNB", snbExclude, "DWORD", reserved, "IStorage FAR * FAR*", ppstgOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgOpenStorageEx
(const WCHAR* pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, void * reserved1, void * reserved2, REFIID riid, void ** ppObjectOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgOpenStorageEx", "const WCHAR* pwcsName", 0, "DWORD", grfMode, "DWORD", stgfmt, "DWORD", grfAttrs, "void *", reserved1, "void *", reserved2, "REFIID", riid, "void **", ppObjectOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgOpenStorageOnILockBytes
(ILockBytes FAR *plkbyt, IStorage FAR *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage FAR * FAR *ppstgOpen)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgOpenStorageOnILockBytes", "ILockBytes FAR*", plkbyt, "IStorage FAR*", pstgPriority, "DWORD", grfMode, "SNB", snbExclude, "DWORD", reserved, "IStorage FAR * FAR*", ppstgOpen, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StgSetTimes
(OLECHAR const FAR* lpszName, FILETIME const FAR* pctime, FILETIME const FAR* patime, FILETIME const FAR* pmtime)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StgSetTimes", "OLECHAR const FAR*", lpszName, "FILETIME const FAR*", pctime, "FILETIME const FAR*", patime, "FILETIME const FAR*", pmtime, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StringFromCLSID
(REFCLSID rclsid, LPOLESTR FAR* lplpsz)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StringFromCLSID", "REFCLSID", rclsid, "LPOLESTR FAR*", lplpsz, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI_(int)
StringFromGUID2
(REFGUID rguid, LPOLESTR lpsz, int cbMax)
{
	int rc = 0;
	WIN32API_ENTER("int", "StringFromGUID2", "REFGUID", rguid, "LPOLESTR", lpsz, "int", cbMax, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
StringFromIID
(REFIID rclsid, LPOLESTR FAR* lplpsz)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "StringFromIID", "REFIID", rclsid, "LPOLESTR FAR*", lplpsz, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
WriteClassStg
(LPSTORAGE pStg, REFCLSID rclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "WriteClassStg", "LPSTORAGE", pStg, "REFCLSID", rclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
WriteClassStm
(LPSTREAM pStm, REFCLSID rclsid)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "WriteClassStm", "LPSTREAM", pStm, "REFCLSID", rclsid, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" WINOLEAPI
WriteFmtUserTypeStg
(LPSTORAGE pstg, CLIPFORMAT cf, LPOLESTR lpszUserType)
{
	HRESULT rc = (HRESULT)-1;
	WIN32API_ENTER("HRESULT", "WriteFmtUserTypeStg", "LPSTORAGE", pstg, "CLIPFORMAT", cf, "LPOLESTR", lpszUserType, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned long __RPC_USER
CLIPFORMAT_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, CLIPFORMAT __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "CLIPFORMAT_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "CLIPFORMAT __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER
CLIPFORMAT_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, CLIPFORMAT __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "CLIPFORMAT_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "CLIPFORMAT __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER
CLIPFORMAT_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, CLIPFORMAT __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "CLIPFORMAT_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "CLIPFORMAT __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER
CLIPFORMAT_UserFree
(unsigned long __RPC_FAR *arg0, CLIPFORMAT __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "CLIPFORMAT_UserFree", "unsigned long __RPC_FAR *", arg0, "CLIPFORMAT __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER
HACCEL_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HACCEL __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HACCEL_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HACCEL __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HACCEL_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HACCEL __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HACCEL_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HACCEL __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HACCEL_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HACCEL __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HACCEL_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HACCEL __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HACCEL_UserFree
(unsigned long __RPC_FAR *arg0, HACCEL __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HACCEL_UserFree", "unsigned long __RPC_FAR *", arg0, "HACCEL __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HBITMAP_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HBITMAP __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HBITMAP_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HBITMAP __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HBITMAP_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HBITMAP __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HBITMAP_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HBITMAP __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HBITMAP_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HBITMAP __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HBITMAP_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HBITMAP __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HBITMAP_UserFree
(unsigned long __RPC_FAR *arg0, HBITMAP __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HBITMAP_UserFree", "unsigned long __RPC_FAR *", arg0, "HBITMAP __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HDC_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HDC __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HDC_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HDC __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HDC_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HDC __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HDC_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HDC __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HDC_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HDC __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HDC_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HDC __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HDC_UserFree
(unsigned long __RPC_FAR *arg0, HDC __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HDC_UserFree", "unsigned long __RPC_FAR *", arg0, "HDC __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HGLOBAL_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HGLOBAL __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HGLOBAL_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HGLOBAL __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HGLOBAL_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HGLOBAL __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HGLOBAL_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HGLOBAL __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HGLOBAL_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HGLOBAL __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HGLOBAL_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HGLOBAL __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void                      __RPC_USER 
HGLOBAL_UserFree
(unsigned long __RPC_FAR *arg0, HGLOBAL __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HGLOBAL_UserFree", "unsigned long __RPC_FAR *", arg0, "HGLOBAL __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HICON_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HICON __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HICON_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HICON __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HICON_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HICON __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HICON_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HICON __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HICON_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HICON __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HICON_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HICON __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HICON_UserFree
(unsigned long __RPC_FAR *arg0, HICON __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HICON_UserFree", "unsigned long __RPC_FAR *", arg0, "HICON __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HMENU_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HMENU __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HMENU_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HMENU __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HMENU_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HMENU __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HMENU_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HMENU __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HMENU_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HMENU __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HMENU_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HMENU __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HMENU_UserFree
(unsigned long __RPC_FAR *arg0, HMENU __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HMENU_UserFree", "unsigned long __RPC_FAR *", arg0, "HMENU __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HPALETTE_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HPALETTE __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HPALETTE_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HPALETTE __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HPALETTE_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HPALETTE __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HPALETTE_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HPALETTE __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HPALETTE_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HPALETTE __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HPALETTE_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HPALETTE __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HPALETTE_UserFree
(unsigned long __RPC_FAR *arg0, HPALETTE __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HPALETTE_UserFree", "unsigned long __RPC_FAR *", arg0, "HPALETTE __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
HWND_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, HWND __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "HWND_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "HWND __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HWND_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HWND __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HWND_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HWND __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
HWND_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, HWND __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "HWND_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "HWND __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
HWND_UserFree
(unsigned long __RPC_FAR *arg0, HWND __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "HWND_UserFree", "unsigned long __RPC_FAR *", arg1, "HWND __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
SNB_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, SNB __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "SNB_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "SNB __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
SNB_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, SNB __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "SNB_UserMarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "SNB __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
SNB_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, SNB __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "SNB_UserUnmarshal", "unsigned long __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "SNB __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
SNB_UserFree
(unsigned long __RPC_FAR *arg0, SNB __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "SNB_UserFree", "unsigned long __RPC_FAR *", arg0, "SNB __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

extern "C" unsigned long __RPC_USER 
STGMEDIUM_UserSize
(unsigned long __RPC_FAR *arg0, unsigned long arg1, STGMEDIUM __RPC_FAR *arg2)
{
	unsigned long rc = 0;
	WIN32API_ENTER("unsigned long", "STGMEDIUM_UserSize", "unsigned long __RPC_FAR *", arg0, "unsigned long", arg1, "STGMEDIUM __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
STGMEDIUM_UserMarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, STGMEDIUM __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "STGMEDIUM_UserMarshal", "unsignedlong __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "STGMEDIUM __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" unsigned char __RPC_FAR * __RPC_USER 
STGMEDIUM_UserUnmarshal
(unsigned long __RPC_FAR *arg0, unsigned char __RPC_FAR *arg1, STGMEDIUM __RPC_FAR *arg2)
{
	unsigned char *rc = 0;
	WIN32API_ENTER("unsigned char *", "STGMEDIUM_UserUnmarshal", "unsignedlong __RPC_FAR *", arg0, "unsigned char __RPC_FAR *", arg1, "STGMEDIUM __RPC_FAR *", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" void __RPC_USER 
STGMEDIUM_UserFree
(unsigned long __RPC_FAR *arg0, STGMEDIUM __RPC_FAR *arg1)
{
	WIN32API_ENTER("void", "STGMEDIUM_UserFree", "unsignedlong __RPC_FAR *", arg0, "STGMEDIUM __RPC_FAR *", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
	WIN32API_LEAVE(0);
}

#if defined(_BUILTIN_DLL)

#	define	GetAddressByOrder	Ole32_GetAddressByOrder
#	define	GetAddressByName	Ole32_GetAddressByName

#	include "Ole32/GetAddressByOrder.h"
#	include "Ole32/GetAddressByName.h"

#endif	// defined(_BUILTIN_DLL)
