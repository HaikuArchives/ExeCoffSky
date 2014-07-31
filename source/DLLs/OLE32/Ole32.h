/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Ole32.h,v 1.1 2003/05/01 03:31:53 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Ole32.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Ole32_h__)
#	define	__Ole32_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if !defined(__COM_h__)
#		include "COM.h"
#	endif	// !defined(__COM_h__)

#	if !defined(WINOLEAPI)
#		define	WINOLEAPI HRESULT WINAPI
#	endif	// !defined(WINOLEAPI)

#	if !defined(WINOLEAPI_)
#		define	WINOLEAPI_(t) t WINAPI
#	endif	// !defined(WINOLEAPI_)

#	if !defined(WINOLEAUTAPI)
#		define	WINOLEAUTAPI	WINOLEAPI
#	endif	// !defined(WINOLEAUTAPI)

#	if !defined(__RPC_USER)
#		define	__RPC_USER	WINAPI
#	endif	// !defined(__RPC_USER)

#	if !defined(__RPC_FAR)
#		define	__RPC_FAR
#	endif	// !defined(__RPC_FAR)

#	if !defined(__IUnknown__)
class IUnknown;
#		define	__IUnknown__
#	endif	// !defined(__IUnknown__)

#	if !defined(__IBindCtx__)
class IBindCtx;
#		define	__IBindCtx__
#	endif	// !defined(__IBindCtx__)

#	if !defined(__IChannelHook__)
class IChannelHook;
#		define	__IChannelHook__
#	endif	// !defined(__IChannelHook__)

#	if !defined(__ICreateErrorInfo__)
class ICreateErrorInfo;
#		define	__ICreateErrorInfo__
#	endif	// !defined(__ICreateErrorInfo__)

#	if !defined(__IBindStatusCallback__)
class IBindStatusCallback;
#		define	__IBindStatusCallback__
#	endif	// !defined(__IBindStatusCallback__)

#	if !defined(__IErrorInfo__)
class IErrorInfo;
#		define	__IErrorInfo__
#	endif	// !defined(__IErrorInfo__)

#	if !defined(__IAdviseSink__)
class IAdviseSink;
#		define	IAdviseSink__
#	endif	// !defined(__IAdviseSink__)

#	if !defined(__ILockBytes__)
class ILockBytes;
#		define	__ILockBytes__
#	endif	// !defined(__ILockBytes__)

#	if !defined(__IStorage__)
class IStorage;
#		define	__IStorage__
#	endif	// !defined(__IStorage__)

#	if !defined(__IPropertyStorage__)
class IPropertyStorage;
#		define	__IPropertyStorage__
#	endif	// !defined(__IPropertySetStorage__)

#	if !defined(__IPropertySetStorage__)
class IPropertySetStorage;
#		define	__IPropertySetStorage__
#	endif	// !defined(__IPropertySetStorage__)

#	if !defined(__IFillLockBytes__)
class IFillLockBytes;
#		define	__IFillLockBytes__
#	endif	// !defined(__IFillLockBytes__)

typedef HANDLE HOLEMENU;
typedef void *LPENUMFORMATETC;
typedef void *LPENUMOLEVERB;

typedef HANDLE RPC_AUTH_IDENTITY_HANDLE;
struct OLEINPLACEFRAME;
typedef OLEINPLACEFRAME *LPOLEINPLACEFRAME;
struct OLEINPLACEFRAMEINFO;
typedef OLEINPLACEFRAMEINFO *LPOLEINPLACEFRAMEINFO;
struct OLEINPLACEACTIVEOBJECT;
typedef OLEINPLACEACTIVEOBJECT *LPOLEINPLACEACTIVEOBJECT;
struct OLEOBJECT;
typedef OLEOBJECT *LPOLEOBJECT;
struct PERSISTSTORAGE;
typedef PERSISTSTORAGE *LPPERSISTSTORAGE;
struct PERSISTSTREAM;
typedef PERSISTSTREAM *LPPERSISTSTREAM;
struct OLECLIENTSITE;
typedef OLECLIENTSITE *LPOLECLIENTSITE;
struct MONIKER;
typedef MONIKER *LPMONIKER;
struct OLESTR;
typedef OLESTR *LPOLESTR;
typedef const OLESTR COLESTR, *LPCOLESTR;
struct COSERVERINFO;
struct STREAM;
typedef STREAM *LPSTREAM;
struct OLESTREAM;
typedef OLESTREAM *LPOLESTREAM;
typedef void *CLIPFORMAT;
struct CLASSFACTORY;
typedef CLASSFACTORY *LPCLASSFACTORY;
struct BIND_OPTS;
struct SOLE_AUTHENTICATION_SERVICE;
struct QUERYCONTEXT;
struct MULTI_QI;
struct OLECHAR;
struct MARSHAL;
typedef MARSHAL *LPMARSHAL;
struct uCLSSPEC;
struct RPC_AUTHZ_HANDLE;
struct MALLOCSPY;
typedef MALLOCSPY *LPMALLOCSPY;
struct SURROGATE;
typedef SURROGATE *LPSURROGATE;
struct MESSAGEFILTER;
typedef MESSAGEFILTER *LPMESSAGEFILTER;
struct BC;
typedef BC *LPBC;
struct DATAADVISEHOLDER;
typedef DATAADVISEHOLDER *LPDATAADVISEHOLDER;
struct OLEADVISEHOLDER;
typedef OLEADVISEHOLDER *LPOLEADVISEHOLDER;
struct DATAOBJECT;
typedef DATAOBJECT *LPDATAOBJECT;
struct LOCKBYTES;
typedef LOCKBYTES *LPLOCKBYTES;
struct DROPSOURCE;
typedef DROPSOURCE *LPDROPSOURCE;
struct DROPTARGET;
typedef DROPTARGET *LPDROPTARGET;
struct PROPVARIANT;
struct STORAGE;
typedef STORAGE *LPSTORAGE;
struct FMTID;
typedef const FMTID *REFFMTID;
struct RUNNINGOBJECTTABLE;
typedef RUNNINGOBJECTTABLE *LPRUNNINGOBJECTTABLE;
struct STGMEDIUM;
typedef STGMEDIUM *LPSTGMEDIUM;
struct DVTARGETDEVICE;
struct FORMATETC;
typedef FORMATETC *LPFORMATETC;
struct OLEMENUGROUPWIDTHS;
typedef OLEMENUGROUPWIDTHS *LPOLEMENUGROUPWIDTHS;
typedef void *SNB;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

WINOLEAPI BindMoniker(LPMONIKER pmk, DWORD grfOpt, REFIID iidResult, LPVOID FAR* ppvResult);
WINOLEAPI CLSIDFromProgID(LPCOLESTR lpszProgID, LPCLSID lpclsid);
WINOLEAPI CLSIDFromProgIDEx(LPCOLESTR lpszProgID, LPCLSID lpclsid);
WINOLEAPI CLSIDFromString(LPOLESTR lpsz, LPCLSID pclsid);
WINOLEAPI_(ULONG) CoAddRefServerProcess(void);
WINOLEAPI_(DWORD) CoBuildVersion(VOID);
WINOLEAPI CoCancelCall(DWORD dwThreadId);
WINOLEAPI CoCopyProxy(IUnknown *pProxy, IUnknown **ppCopy);
WINOLEAPI CoCreateFreeThreadedMarshaler(LPUNKNOWN punkOuter, LPUNKNOWN *ppunkMarshal);
WINOLEAPI CoCreateGuid(GUID FAR *pguid);
WINOLEAPI CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID FAR* ppv);
WINOLEAPI CoCreateInstanceEx(REFCLSID Clsid, IUnknown * punkOuter, DWORD dwClsCtx, COSERVERINFO * pServerInfo, DWORD dwCount, MULTI_QI * pResults);
WINOLEAPI CoDisconnectObject(LPUNKNOWN pUnk, DWORD dwReserved);
WINOLEAPI_(BOOL) CoDosDateTimeToFileTime( WORD nDosDate, WORD nDosTime, FILETIME FAR* lpFileTime);
WINOLEAPI CoFileTimeNow(FILETIME FAR* lpFileTime);
WINOLEAPI_(BOOL) CoFileTimeToDosDateTime(FILETIME FAR* lpFileTime, LPWORD lpDosDate, LPWORD lpDosTime);
WINOLEAPI_(void) CoFreeAllLibraries(void);
WINOLEAPI_(void) CoFreeLibrary(HINSTANCE hInst);
WINOLEAPI_(void) CoFreeUnusedLibraries(void);
WINOLEAPI CoGetCallContext(REFIID riid, void **ppInterface);
WINOLEAPI CoGetCancelObject(DWORD dwThreadId, REFIID iid, void **ppUnk);
WINOLEAPI CoGetClassObject(REFCLSID rclsid, DWORD dwClsContext, LPVOID pvReserved, REFIID riid, LPVOID FAR* ppv);
WINOLEAPI_(DWORD) CoGetCurrentProcess(void);
WINOLEAPI CoGetInstanceFromFile(COSERVERINFO * pServerInfo, CLSID * pClsid, IUnknown * punkOuter, DWORD dwClsCtx, DWORD grfMode, OLECHAR * pwszName, DWORD dwCount, MULTI_QI * pResults);
WINOLEAPI CoGetInstanceFromIStorage(COSERVERINFO * pServerInfo, CLSID * pClsid, IUnknown * punkOuter, DWORD dwClsCtx, struct IStorage * pstg, DWORD dwCount, MULTI_QI * pResults);
WINOLEAPI CoGetInterfaceAndReleaseStream(LPSTREAM pStm, REFIID iid, LPVOID FAR* ppv);
WINOLEAPI CoGetMalloc(DWORD dwMemContext, LPMALLOC FAR* ppMalloc);
WINOLEAPI CoGetMarshalSizeMax(ULONG *pulSize, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags);
WINOLEAPI CoGetObject(LPCWSTR pszName, BIND_OPTS *pBindOptions, REFIID riid, void **ppv);
WINOLEAPI CoGetPSClsid(REFIID riid, CLSID *pClsid);
WINOLEAPI CoGetStandardMarshal(REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags, LPMARSHAL FAR* ppMarshal);
WINOLEAPI CoGetStdMarshalEx(LPUNKNOWN pUnkOuter, DWORD smexflags, LPUNKNOWN FAR* ppUnkInner);
WINOLEAPI CoGetTreatAsClass(REFCLSID clsidOld, LPCLSID pClsidNew);
WINOLEAPI CoImpersonateClient(void);
WINOLEAPI CoInitialize(LPVOID pvReserved);
WINOLEAPI CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
WINOLEAPI CoInitializeSecurity(PSECURITY_DESCRIPTOR pSecDesc, LONG cAuthSvc, SOLE_AUTHENTICATION_SERVICE *asAuthSvc, void *pReserved1, DWORD dwAuthnLevel, DWORD dwImpLevel, void *pReserved2, DWORD dwCapabilities, void *pReserved3);
WINOLEAPI CoInstall(IBindCtx * pbc, DWORD dwFlags, uCLSSPEC * pClassSpec, QUERYCONTEXT * pQuery, LPWSTR pszCodeBase);
WINOLEAPI_(BOOL) CoIsHandlerConnected(LPUNKNOWN pUnk);
WINOLEAPI_(BOOL) CoIsOle1Class(REFCLSID rclsid);
WINOLEAPI_(HINSTANCE) CoLoadLibrary(LPOLESTR lpszLibName, BOOL bAutoFree);
WINOLEAPI CoLockObjectExternal(LPUNKNOWN pUnk, BOOL fLock, BOOL fLastUnlockReleases);
WINOLEAPI CoMarshalHresult(LPSTREAM pstm, HRESULT hresult);
WINOLEAPI CoMarshalInterThreadInterfaceInStream(REFIID riid, LPUNKNOWN pUnk, LPSTREAM *ppStm);
WINOLEAPI CoMarshalInterface(LPSTREAM pStm, REFIID riid, LPUNKNOWN pUnk, DWORD dwDestContext, LPVOID pvDestContext, DWORD mshlflags);
WINOLEAPI CoQueryAuthenticationServices(DWORD *pcAuthSvc, SOLE_AUTHENTICATION_SERVICE **asAuthSvc);
WINOLEAPI CoQueryClientBlanket(DWORD *pAuthnSvc, DWORD *pAuthzSvc, OLECHAR **pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTHZ_HANDLE *pPrivs, DWORD *pCapabilities);
WINOLEAPI CoQueryProxyBlanket(IUnknown *pProxy, DWORD *pwAuthnSvc, DWORD *pAuthzSvc, OLECHAR **pServerPrincName, DWORD *pAuthnLevel, DWORD *pImpLevel, RPC_AUTH_IDENTITY_HANDLE *pAuthInfo, DWORD *pCapabilites);
WINOLEAPI CoRegisterChannelHook(REFGUID ExtensionUuid, IChannelHook *pChannelHook);
WINOLEAPI CoRegisterClassObject(REFCLSID rclsid, LPUNKNOWN pUnk, DWORD dwClsContext, DWORD flags, LPDWORD lpdwRegister);
WINOLEAPI CoRegisterMallocSpy(LPMALLOCSPY pMallocSpy);
WINOLEAPI CoRegisterMessageFilter(LPMESSAGEFILTER lpMessageFilter, LPMESSAGEFILTER FAR* lplpMessageFilter);
WINOLEAPI CoRegisterPSClsid(REFIID riid, REFCLSID rclsid);
WINOLEAPI CoRegisterSurrogate(LPSURROGATE pSurrogate);
WINOLEAPI CoReleaseMarshalData(LPSTREAM pStm);
WINOLEAPI_(ULONG) CoReleaseServerProcess(void);
WINOLEAPI CoResumeClassObjects(void);
WINOLEAPI CoRevertToSelf(void);
WINOLEAPI CoRevokeClassObject(DWORD dwRegister);
WINOLEAPI CoRevokeMallocSpy(void);
WINOLEAPI CoSetCancelObject(IUnknown *pUnk);
WINOLEAPI CoSetProxyBlanket(IUnknown *pProxy, DWORD dwAuthnSvc, DWORD dwAuthzSvc, OLECHAR *pServerPrincName, DWORD dwAuthnLevel, DWORD dwImpLevel, RPC_AUTH_IDENTITY_HANDLE pAuthInfo, DWORD dwCapabilities);
WINOLEAPI CoSuspendClassObjects(void);
WINOLEAPI CoSwitchCallContext(IUnknown *pNewObject, IUnknown **ppOldObject);
WINOLEAPI_(LPVOID) CoTaskMemAlloc(ULONG cb);
WINOLEAPI_(void) CoTaskMemFree(LPVOID pv);
WINOLEAPI_(LPVOID) CoTaskMemRealloc(LPVOID pv, ULONG cb);
WINOLEAPI CoTestCancel(void);
WINOLEAPI CoTreatAsClass(REFCLSID clsidOld, REFCLSID clsidNew);
WINOLEAPI_(void) CoUninitialize(void);
WINOLEAPI CoUnmarshalHresult(LPSTREAM pstm, HRESULT FAR * phresult);
WINOLEAPI CoUnmarshalInterface(LPSTREAM pStm, REFIID riid, LPVOID FAR* ppv);
WINOLEAPI CreateAntiMoniker(LPMONIKER FAR* ppmk);
WINOLEAPI CreateBindCtx(DWORD reserved, LPBC FAR* ppbc);
WINOLEAPI CreateClassMoniker(REFCLSID rclsid, LPMONIKER FAR* ppmk);
WINOLEAPI CreateDataAdviseHolder(LPDATAADVISEHOLDER FAR* ppDAHolder);
WINOLEAPI CreateDataCache(LPUNKNOWN pUnkOuter, REFCLSID rclsid, REFIID iid, LPVOID FAR* ppv);
WINOLEAUTAPI CreateErrorInfo(ICreateErrorInfo ** pperrinfo);
WINOLEAPI CreateFileMoniker(LPCOLESTR lpszPathName, LPMONIKER FAR* ppmk);
WINOLEAPI CreateGenericComposite(LPMONIKER pmkFirst, LPMONIKER pmkRest, LPMONIKER FAR* ppmkComposite);
WINOLEAPI CreateILockBytesOnHGlobal(HGLOBAL hGlobal, BOOL fDeleteOnRelease, LPLOCKBYTES FAR* pplkbyt);
WINOLEAPI CreateItemMoniker(LPCOLESTR lpszDelim, LPCOLESTR lpszItem, LPMONIKER FAR* ppmk);
WINOLEAPI CreateOleAdviseHolder(LPOLEADVISEHOLDER FAR* ppOAHolder);
WINOLEAPI CreatePointerMoniker(LPUNKNOWN punk, LPMONIKER FAR* ppmk);
WINOLEAPI CreateStdProgressIndicator(HWND hwndParent, LPCOLESTR pszTitle, IBindStatusCallback * pIbscCaller, IBindStatusCallback ** ppIbsc);
WINOLEAPI CreateStreamOnHGlobal(HGLOBAL hGlobal, BOOL fDeleteOnRelease, LPSTREAM FAR* ppstm);
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID FAR* ppv);
STDAPI DllRegisterServer(void);
WINOLEAPI DoDragDrop(LPDATAOBJECT pDataObj, LPDROPSOURCE pDropSource, DWORD dwOKEffects, LPDWORD pdwEffect);
WINOLEAPI FmtIdToPropStgName(const FMTID *pfmtid, LPOLESTR oszName);
WINOLEAPI FreePropVariantArray(ULONG cVariants, PROPVARIANT * rgvars);
WINOLEAPI GetClassFile(LPCOLESTR szFilename, CLSID FAR* pclsid);
WINOLEAPI GetConvertStg(LPSTORAGE pStg);
WINOLEAUTAPI GetErrorInfo(ULONG dwReserved, IErrorInfo ** pperrinfo);
WINOLEAPI GetHGlobalFromILockBytes(LPLOCKBYTES plkbyt, HGLOBAL FAR* phglobal);
WINOLEAPI GetHGlobalFromStream(LPSTREAM pstm, HGLOBAL FAR* phglobal);
WINOLEAPI GetRunningObjectTable(DWORD reserved, LPRUNNINGOBJECTTABLE FAR* pprot);
WINOLEAPI IIDFromString(LPOLESTR lpsz, LPIID lpiid);
WINOLEAPI_(BOOL) IsAccelerator(HACCEL hAccel, int cAccelEntries, LPMSG lpMsg, WORD FAR* lpwCmd);
WINOLEAPI_(BOOL) IsEqualGUID(REFGUID rguid1, REFGUID rguid2);
WINOLEAPI MkParseDisplayName(LPBC pbc, LPCOLESTR szUserName, ULONG FAR * pchEaten, LPMONIKER FAR * ppmk);
WINOLEAPI MonikerCommonPrefixWith(LPMONIKER pmkThis, LPMONIKER pmkOther, LPMONIKER FAR* ppmkCommon);
WINOLEAPI MonikerRelativePathTo(LPMONIKER pmkSrc, LPMONIKER pmkDest, LPMONIKER FAR* ppmkRelPath, BOOL dwReserved);
WINOLEAPI_(DWORD) OleBuildVersion(VOID);
WINOLEAPI OleConvertIStorageToOLESTREAM(LPSTORAGE pstg, LPOLESTREAM lpolestream);
WINOLEAPI OleConvertIStorageToOLESTREAMEx(LPSTORAGE pstg, CLIPFORMAT cfFormat, LONG lWidth, LONG lHeight, DWORD dwSize, LPSTGMEDIUM pmedium, LPOLESTREAM polestm);
WINOLEAPI OleConvertOLESTREAMToIStorage(LPOLESTREAM lpolestream, LPSTORAGE pstg, const DVTARGETDEVICE FAR* ptd);
WINOLEAPI OleConvertOLESTREAMToIStorageEx(LPOLESTREAM polestm, LPSTORAGE pstg, CLIPFORMAT FAR* pcfFormat, LONG FAR* plwWidth, LONG FAR* plHeight, DWORD FAR* pdwSize, LPSTGMEDIUM pmedium);
WINOLEAPI OleCreate(REFCLSID rclsid, REFIID riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateDefaultHandler(REFCLSID clsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* lplpObj);
WINOLEAPI OleCreateEmbeddingHelper(REFCLSID clsid, LPUNKNOWN pUnkOuter, DWORD flags, LPCLASSFACTORY pCF, REFIID riid, LPVOID FAR* lplpObj);
WINOLEAPI OleCreateEx(REFCLSID rclsid, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromData(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromDataEx(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromFile(REFCLSID rclsid, LPCOLESTR lpszFileName, REFIID riid, DWORD renderopt, LPFORMATETC lpFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateFromFileEx(REFCLSID rclsid, LPCOLESTR lpszFileName, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLink(LPMONIKER pmkLinkSrc, REFIID riid, DWORD renderopt, LPFORMATETC lpFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkEx(LPMONIKER pmkLinkSrc, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkFromData(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkFromDataEx(LPDATAOBJECT pSrcDataObj, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkToFile(LPCOLESTR lpszFileName, REFIID riid, DWORD renderopt, LPFORMATETC lpFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleCreateLinkToFileEx(LPCOLESTR lpszFileName, REFIID riid, DWORD dwFlags, DWORD renderopt, ULONG cFormats, DWORD* rgAdvf, LPFORMATETC rgFormatEtc, IAdviseSink FAR* lpAdviseSink, DWORD FAR* rgdwConnection, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI_(HOLEMENU) OleCreateMenuDescriptor(HMENU hmenuCombined, LPOLEMENUGROUPWIDTHS lpMenuWidths);
WINOLEAPI OleCreateStaticFromData(LPDATAOBJECT pSrcDataObj, REFIID iid, DWORD renderopt, LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, LPVOID FAR* ppvObj);
WINOLEAPI OleDestroyMenuDescriptor(HOLEMENU holemenu);
WINOLEAPI OleDoAutoConvert(LPSTORAGE pStg, LPCLSID pClsidNew);
WINOLEAPI OleDraw(LPUNKNOWN pUnknown, DWORD dwAspect, HDC hdcDraw, LPCRECT lprcBounds);
WINOLEAPI_(HANDLE) OleDuplicateData(HANDLE hSrc, CLIPFORMAT cfFormat, UINT uiFlags);
WINOLEAPI OleFlushClipboard(void);
WINOLEAPI OleGetAutoConvert(REFCLSID clsidOld, LPCLSID pClsidNew);
WINOLEAPI OleGetClipboard(LPDATAOBJECT FAR* ppDataObj);
WINOLEAPI_(HGLOBAL) OleGetIconOfClass(REFCLSID rclsid, LPOLESTR lpszLabel, BOOL fUseTypeAsLabel);
WINOLEAPI_(HGLOBAL) OleGetIconOfFile(LPOLESTR lpszPath, BOOL fUseFileAsLabel);
WINOLEAPI OleInitialize(LPVOID pvReserved);
WINOLEAPI OleIsCurrentClipboard(LPDATAOBJECT pDataObj);
WINOLEAPI_(BOOL) OleIsRunning(LPOLEOBJECT pObject);
WINOLEAPI OleLoad(LPSTORAGE pStg, REFIID riid, LPOLECLIENTSITE pClientSite, LPVOID FAR* ppvObj);
WINOLEAPI OleLoadFromStream(LPSTREAM pStm, REFIID iidInterface, LPVOID FAR* ppvObj);
WINOLEAPI OleLockRunning(LPUNKNOWN pUnknown, BOOL fLock, BOOL fLastUnlockCloses);
WINOLEAPI_(HGLOBAL) OleMetafilePictFromIconAndLabel(HICON hIcon, LPOLESTR lpszLabel, LPOLESTR lpszSourceFile, UINT iIconIndex);
WINOLEAPI OleNoteObjectVisible(LPUNKNOWN pUnknown, BOOL fVisible);
WINOLEAPI OleQueryCreateFromData(LPDATAOBJECT pSrcDataObject);
WINOLEAPI OleQueryLinkFromData(LPDATAOBJECT pSrcDataObject);
WINOLEAPI OleRegEnumFormatEtc(REFCLSID clsid, DWORD dwDirection, LPENUMFORMATETC FAR* ppenum);
WINOLEAPI OleRegEnumVerbs(REFCLSID clsid, LPENUMOLEVERB FAR* ppenum);
WINOLEAPI OleRegGetMiscStatus(REFCLSID clsid, DWORD dwAspect, DWORD FAR* pdwStatus);
WINOLEAPI OleRegGetUserType(REFCLSID clsid, DWORD dwFormOfType, LPOLESTR FAR* pszUserType);
WINOLEAPI OleRun(LPUNKNOWN pUnknown);
WINOLEAPI OleSave(LPPERSISTSTORAGE pPS, LPSTORAGE pStg, BOOL fSameAsLoad);
WINOLEAPI OleSaveToStream(LPPERSISTSTREAM pPStm, LPSTREAM pStm);
WINOLEAPI OleSetAutoConvert(REFCLSID clsidOld, REFCLSID clsidNew);
WINOLEAPI OleSetClipboard(LPDATAOBJECT pDataObj);
WINOLEAPI OleSetContainedObject(LPUNKNOWN pUnknown, BOOL fContained);
WINOLEAPI OleSetMenuDescriptor(HOLEMENU holemenu, HWND hwndFrame, HWND hwndActiveObject, LPOLEINPLACEFRAME lpFrame, LPOLEINPLACEACTIVEOBJECT lpActiveObj);
WINOLEAPI OleTranslateAccelerator(LPOLEINPLACEFRAME lpFrame, LPOLEINPLACEFRAMEINFO lpFrameInfo, LPMSG lpmsg);
WINOLEAPI_(void) OleUninitialize(void);
WINOLEAPI ProgIDFromCLSID(REFCLSID clsid, LPOLESTR FAR* lplpszProgID);
WINOLEAPI PropStgNameToFmtId(const LPOLESTR oszName, FMTID *pfmtid);
WINOLEAPI PropVariantClear(PROPVARIANT * pvar);
WINOLEAPI PropVariantCopy(PROPVARIANT * pvarDest, const PROPVARIANT * pvarSrc);
WINOLEAPI ReadClassStg(LPSTORAGE pStg, CLSID FAR* pclsid);
WINOLEAPI ReadClassStm(LPSTREAM pStm, CLSID FAR* pclsid);
WINOLEAPI ReadFmtUserTypeStg(LPSTORAGE pstg, CLIPFORMAT FAR* pcf, LPOLESTR FAR* lplpszUserType);
WINOLEAPI RegisterDragDrop(HWND hwnd, LPDROPTARGET pDropTarget);
WINOLEAPI_(void) ReleaseStgMedium(LPSTGMEDIUM);
WINOLEAPI RevokeDragDrop(HWND hwnd);
WINOLEAPI SetConvertStg(LPSTORAGE pStg, BOOL fConvert);
WINOLEAUTAPI SetErrorInfo(ULONG dwReserved, IErrorInfo * perrinfo);
WINOLEAPI StgCreateDocfile(const OLECHAR FAR* pwcsName, DWORD grfMode, DWORD reserved, IStorage FAR * FAR *ppstgOpen);
WINOLEAPI StgCreateDocfileOnILockBytes(ILockBytes FAR *plkbyt, DWORD grfMode, DWORD reserved, IStorage FAR * FAR *ppstgOpen);
WINOLEAPI StgCreatePropSetStg(IStorage *pStorage, DWORD dwReserved, IPropertySetStorage **ppPropSetStg);
WINOLEAPI StgCreatePropStg(IUnknown* pUnk, REFFMTID fmtid, const CLSID *pclsid, DWORD grfFlags, DWORD dwReserved, IPropertyStorage **ppPropStg);
WINOLEAPI StgCreateStorageEx(const WCHAR* pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, void * reserved1, void * reserved2, REFIID riid, void ** ppObjectOpen);
WINOLEAPI StgGetIFillLockBytesOnFile(OLECHAR const *pwcsName, IFillLockBytes **ppflb);
WINOLEAPI StgGetIFillLockBytesOnILockBytes(ILockBytes *pilb, IFillLockBytes **ppflb);
WINOLEAPI StgIsStorageFile(const OLECHAR FAR* pwcsName);
WINOLEAPI StgIsStorageILockBytes(ILockBytes FAR* plkbyt);
WINOLEAPI StgOpenAsyncDocfileOnIFillLockBytes(IFillLockBytes *pflb, DWORD grfMode, DWORD asyncFlags, IStorage **ppstgOpen);
WINOLEAPI StgOpenPropStg(IUnknown* pUnk, REFFMTID fmtid, DWORD grfFlags, DWORD dwReserved, IPropertyStorage **ppPropStg);
WINOLEAPI StgOpenStorage(const OLECHAR FAR* pwcsName, IStorage FAR *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage FAR * FAR *ppstgOpen);
WINOLEAPI StgOpenStorageEx(const WCHAR* pwcsName, DWORD grfMode, DWORD stgfmt, DWORD grfAttrs, void * reserved1, void * reserved2, REFIID riid, void ** ppObjectOpen);
WINOLEAPI StgOpenStorageOnILockBytes(ILockBytes FAR *plkbyt, IStorage FAR *pstgPriority, DWORD grfMode, SNB snbExclude, DWORD reserved, IStorage FAR * FAR *ppstgOpen);
WINOLEAPI StgSetTimes(OLECHAR const FAR* lpszName, FILETIME const FAR* pctime, FILETIME const FAR* patime, FILETIME const FAR* pmtime);
WINOLEAPI StringFromCLSID(REFCLSID rclsid, LPOLESTR FAR* lplpsz);
WINOLEAPI_(int) StringFromGUID2(REFGUID rguid, LPOLESTR lpsz, int cbMax);
WINOLEAPI StringFromIID(REFIID rclsid, LPOLESTR FAR* lplpsz);
WINOLEAPI WriteClassStg(LPSTORAGE pStg, REFCLSID rclsid);
WINOLEAPI WriteClassStm(LPSTREAM pStm, REFCLSID rclsid);
WINOLEAPI WriteFmtUserTypeStg(LPSTORAGE pstg, CLIPFORMAT cf, LPOLESTR lpszUserType);

unsigned long             __RPC_USER  CLIPFORMAT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , CLIPFORMAT __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  CLIPFORMAT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, CLIPFORMAT __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  CLIPFORMAT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, CLIPFORMAT __RPC_FAR * );
void                      __RPC_USER  CLIPFORMAT_UserFree(     unsigned long __RPC_FAR *, CLIPFORMAT __RPC_FAR * );

unsigned long             __RPC_USER  HACCEL_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HACCEL __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HACCEL_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HACCEL __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HACCEL_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HACCEL __RPC_FAR * );
void                      __RPC_USER  HACCEL_UserFree(     unsigned long __RPC_FAR *, HACCEL __RPC_FAR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HBITMAP __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HBITMAP_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HBITMAP __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HBITMAP_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HBITMAP __RPC_FAR * );
void                      __RPC_USER  HBITMAP_UserFree(     unsigned long __RPC_FAR *, HBITMAP __RPC_FAR * );

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long __RPC_FAR*, unsigned long            , HDC __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HDC_UserMarshal(  unsigned long __RPC_FAR*, unsigned char __RPC_FAR *, HDC __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HDC_UserUnmarshal(unsigned long __RPC_FAR*, unsigned char __RPC_FAR *, HDC __RPC_FAR * );
void                      __RPC_USER  HDC_UserFree(     unsigned long __RPC_FAR*, HDC __RPC_FAR * );

unsigned long             __RPC_USER  HGLOBAL_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HGLOBAL __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HGLOBAL_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HGLOBAL __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HGLOBAL_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HGLOBAL __RPC_FAR * );
void                      __RPC_USER  HGLOBAL_UserFree(     unsigned long __RPC_FAR *, HGLOBAL __RPC_FAR * );

unsigned long             __RPC_USER  HICON_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HICON __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HICON_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HICON __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HICON_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HICON __RPC_FAR * );
void                      __RPC_USER  HICON_UserFree(     unsigned long __RPC_FAR *, HICON __RPC_FAR * );

unsigned long             __RPC_USER  HMENU_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HMENU __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HMENU_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HMENU __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HMENU_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HMENU __RPC_FAR * );
void                      __RPC_USER  HMENU_UserFree(     unsigned long __RPC_FAR *, HMENU __RPC_FAR * );

unsigned long             __RPC_USER  HPALETTE_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HPALETTE __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HPALETTE_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HPALETTE __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HPALETTE_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HPALETTE __RPC_FAR * );
void                      __RPC_USER  HPALETTE_UserFree(     unsigned long __RPC_FAR *, HPALETTE __RPC_FAR * );

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long __RPC_FAR *, unsigned long            , HWND __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HWND_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HWND __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  HWND_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, HWND __RPC_FAR * );
void                      __RPC_USER  HWND_UserFree(     unsigned long __RPC_FAR *, HWND __RPC_FAR * );

unsigned long             __RPC_USER  SNB_UserSize(     unsigned long __RPC_FAR *, unsigned long            , SNB __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  SNB_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, SNB __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  SNB_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, SNB __RPC_FAR * );
void                      __RPC_USER  SNB_UserFree(     unsigned long __RPC_FAR *, SNB __RPC_FAR * );

unsigned long             __RPC_USER  STGMEDIUM_UserSize(     unsigned long __RPC_FAR *, unsigned long            , STGMEDIUM __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  STGMEDIUM_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, STGMEDIUM __RPC_FAR * );
unsigned char __RPC_FAR * __RPC_USER  STGMEDIUM_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, STGMEDIUM __RPC_FAR * );
void                      __RPC_USER  STGMEDIUM_UserFree(     unsigned long __RPC_FAR *, STGMEDIUM __RPC_FAR * );

#	if defined(_BUILTIN_DLL)
void *Ole32_GetAddressByOrder(int order);
void *Ole32_GetAddressByName(const char *name);
#	endif	// defined(_BUILTIN_DLL)

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Ole32_h__)
