void *
GetAddressByName
(const char *name)
{
	if (NULL == name) return NULL;
	else if (0 == strcmp(name, "BindMoniker")) return (void *)BindMoniker;
	else if (0 == strcmp(name, "CLIPFORMAT_UserFree")) return (void *)CLIPFORMAT_UserFree;
	else if (0 == strcmp(name, "CLIPFORMAT_UserMarshal")) return (void *)CLIPFORMAT_UserMarshal;
	else if (0 == strcmp(name, "CLIPFORMAT_UserSize")) return (void *)CLIPFORMAT_UserSize;
	else if (0 == strcmp(name, "CLIPFORMAT_UserUnmarshal")) return (void *)CLIPFORMAT_UserUnmarshal;
	else if (0 == strcmp(name, "CLSIDFromProgID")) return (void *)CLSIDFromProgID;
	else if (0 == strcmp(name, "CLSIDFromProgIDEx")) return (void *)CLSIDFromProgIDEx;
	else if (0 == strcmp(name, "CLSIDFromString")) return (void *)CLSIDFromString;
	else if (0 == strcmp(name, "CoAddRefServerProcess")) return (void *)CoAddRefServerProcess;
//	else if (0 == strcmp(name, "CoAllowSetForegroundWindow")) return (void *)CoAllowSetForegroundWindow;
	else if (0 == strcmp(name, "CoBuildVersion")) return (void *)CoBuildVersion;
	else if (0 == strcmp(name, "CoCancelCall")) return (void *)CoCancelCall;
	else if (0 == strcmp(name, "CoCopyProxy")) return (void *)CoCopyProxy;
	else if (0 == strcmp(name, "CoCreateFreeThreadedMarshaler")) return (void *)CoCreateFreeThreadedMarshaler;
	else if (0 == strcmp(name, "CoCreateGuid")) return (void *)CoCreateGuid;
	else if (0 == strcmp(name, "CoCreateInstance")) return (void *)CoCreateInstance;
	else if (0 == strcmp(name, "CoCreateInstanceEx")) return (void *)CoCreateInstanceEx;
//	else if (0 == strcmp(name, "CoCreateObjectInContext")) return (void *)CoCreateObjectInContext;
//	else if (0 == strcmp(name, "CoDeactivateObject")) return (void *)CoDeactivateObject;
//	else if (0 == strcmp(name, "CoDisableCallCancellation")) return (void *)CoDisableCallCancellation;
	else if (0 == strcmp(name, "CoDisconnectObject")) return (void *)CoDisconnectObject;
	else if (0 == strcmp(name, "CoDosDateTimeToFileTime")) return (void *)CoDosDateTimeToFileTime;
//	else if (0 == strcmp(name, "CoEnableCallCancellation")) return (void *)CoEnableCallCancellation;
	else if (0 == strcmp(name, "CoFileTimeNow")) return (void *)CoFileTimeNow;
	else if (0 == strcmp(name, "CoFileTimeToDosDateTime")) return (void *)CoFileTimeToDosDateTime;
	else if (0 == strcmp(name, "CoFreeAllLibraries")) return (void *)CoFreeAllLibraries;
	else if (0 == strcmp(name, "CoFreeLibrary")) return (void *)CoFreeLibrary;
	else if (0 == strcmp(name, "CoFreeUnusedLibraries")) return (void *)CoFreeUnusedLibraries;
//	else if (0 == strcmp(name, "CoGetApartmentID")) return (void *)CoGetApartmentID;
	else if (0 == strcmp(name, "CoGetCallContext")) return (void *)CoGetCallContext;
//	else if (0 == strcmp(name, "CoGetCallerTID")) return (void *)CoGetCallerTID;
	else if (0 == strcmp(name, "CoGetCancelObject")) return (void *)CoGetCancelObject;
	else if (0 == strcmp(name, "CoGetClassObject")) return (void *)CoGetClassObject;
//	else if (0 == strcmp(name, "CoGetClassVersion")) return (void *)CoGetClassVersion;
//	else if (0 == strcmp(name, "CoGetCurrentLogicalThreadId")) return (void *)CoGetCurrentLogicalThreadId;
	else if (0 == strcmp(name, "CoGetCurrentProcess")) return (void *)CoGetCurrentProcess;
	else if (0 == strcmp(name, "CoGetInstanceFromFile")) return (void *)CoGetInstanceFromFile;
	else if (0 == strcmp(name, "CoGetInstanceFromIStorage")) return (void *)CoGetInstanceFromIStorage;
	else if (0 == strcmp(name, "CoGetInterfaceAndReleaseStream")) return (void *)CoGetInterfaceAndReleaseStream;
	else if (0 == strcmp(name, "CoGetMalloc")) return (void *)CoGetMalloc;
	else if (0 == strcmp(name, "CoGetMarshalSizeMax")) return (void *)CoGetMarshalSizeMax;
	else if (0 == strcmp(name, "CoGetObject")) return (void *)CoGetObject;
//	else if (0 == strcmp(name, "CoGetObjectContext")) return (void *)CoGetObjectContext;
	else if (0 == strcmp(name, "CoGetPSClsid")) return (void *)CoGetPSClsid;
	else if (0 == strcmp(name, "CoGetStandardMarshal")) return (void *)CoGetStandardMarshal;
//	else if (0 == strcmp(name, "CoGetState")) return (void *)CoGetState;
	else if (0 == strcmp(name, "CoGetStdMarshalEx")) return (void *)CoGetStdMarshalEx;
	else if (0 == strcmp(name, "CoGetTreatAsClass")) return (void *)CoGetTreatAsClass;
	else if (0 == strcmp(name, "CoImpersonateClient")) return (void *)CoImpersonateClient;
	else if (0 == strcmp(name, "CoInitialize")) return (void *)CoInitialize;
	else if (0 == strcmp(name, "CoInitializeEx")) return (void *)CoInitializeEx;
	else if (0 == strcmp(name, "CoInitializeSecurity")) return (void *)CoInitializeSecurity;
//	else if (0 == strcmp(name, "CoInitializeWOW")) return (void *)CoInitializeWOW;
	else if (0 == strcmp(name, "CoInstall")) return (void *)CoInstall;
	else if (0 == strcmp(name, "CoIsHandlerConnected")) return (void *)CoIsHandlerConnected;
	else if (0 == strcmp(name, "CoIsOle1Class")) return (void *)CoIsOle1Class;
	else if (0 == strcmp(name, "CoLoadLibrary")) return (void *)CoLoadLibrary;
	else if (0 == strcmp(name, "CoLockObjectExternal")) return (void *)CoLockObjectExternal;
	else if (0 == strcmp(name, "CoMarshalHresult")) return (void *)CoMarshalHresult;
	else if (0 == strcmp(name, "CoMarshalInterThreadInterfaceInStream")) return (void *)CoMarshalInterThreadInterfaceInStream;
	else if (0 == strcmp(name, "CoMarshalInterface")) return (void *)CoMarshalInterface;
	else if (0 == strcmp(name, "CoQueryAuthenticationServices")) return (void *)CoQueryAuthenticationServices;
	else if (0 == strcmp(name, "CoQueryClientBlanket")) return (void *)CoQueryClientBlanket;
	else if (0 == strcmp(name, "CoQueryProxyBlanket")) return (void *)CoQueryProxyBlanket;
//	else if (0 == strcmp(name, "CoQueryReleaseObject")) return (void *)CoQueryReleaseObject;
//	else if (0 == strcmp(name, "CoReactivateObject")) return (void *)CoReactivateObject;
	else if (0 == strcmp(name, "CoRegisterChannelHook")) return (void *)CoRegisterChannelHook;
	else if (0 == strcmp(name, "CoRegisterClassObject")) return (void *)CoRegisterClassObject;
	else if (0 == strcmp(name, "CoRegisterMallocSpy")) return (void *)CoRegisterMallocSpy;
	else if (0 == strcmp(name, "CoRegisterMessageFilter")) return (void *)CoRegisterMessageFilter;
	else if (0 == strcmp(name, "CoRegisterPSClsid")) return (void *)CoRegisterPSClsid;
	else if (0 == strcmp(name, "CoRegisterSurrogate")) return (void *)CoRegisterSurrogate;
//	else if (0 == strcmp(name, "CoRegisterSurrogateEx")) return (void *)CoRegisterSurrogateEx;
	else if (0 == strcmp(name, "CoReleaseMarshalData")) return (void *)CoReleaseMarshalData;
	else if (0 == strcmp(name, "CoReleaseServerProcess")) return (void *)CoReleaseServerProcess;
	else if (0 == strcmp(name, "CoResumeClassObjects")) return (void *)CoResumeClassObjects;
	else if (0 == strcmp(name, "CoRevertToSelf")) return (void *)CoRevertToSelf;
	else if (0 == strcmp(name, "CoRevokeClassObject")) return (void *)CoRevokeClassObject;
	else if (0 == strcmp(name, "CoRevokeMallocSpy")) return (void *)CoRevokeMallocSpy;
	else if (0 == strcmp(name, "CoSetCancelObject")) return (void *)CoSetCancelObject;
	else if (0 == strcmp(name, "CoSetProxyBlanket")) return (void *)CoSetProxyBlanket;
//	else if (0 == strcmp(name, "CoSetState")) return (void *)CoSetState;
	else if (0 == strcmp(name, "CoSuspendClassObjects")) return (void *)CoSuspendClassObjects;
	else if (0 == strcmp(name, "CoSwitchCallContext")) return (void *)CoSwitchCallContext;
	else if (0 == strcmp(name, "CoTaskMemAlloc")) return (void *)CoTaskMemAlloc;
	else if (0 == strcmp(name, "CoTaskMemFree")) return (void *)CoTaskMemFree;
	else if (0 == strcmp(name, "CoTaskMemRealloc")) return (void *)CoTaskMemRealloc;
	else if (0 == strcmp(name, "CoTestCancel")) return (void *)CoTestCancel;
	else if (0 == strcmp(name, "CoTreatAsClass")) return (void *)CoTreatAsClass;
	else if (0 == strcmp(name, "CoUninitialize")) return (void *)CoUninitialize;
//	else if (0 == strcmp(name, "CoUnloadingWOW")) return (void *)CoUnloadingWOW;
	else if (0 == strcmp(name, "CoUnmarshalHresult")) return (void *)CoUnmarshalHresult;
	else if (0 == strcmp(name, "CoUnmarshalInterface")) return (void *)CoUnmarshalInterface;
//	else if (0 == strcmp(name, "CoWaitForMultipleHandles")) return (void *)CoWaitForMultipleHandles;
	else if (0 == strcmp(name, "CreateAntiMoniker")) return (void *)CreateAntiMoniker;
	else if (0 == strcmp(name, "CreateBindCtx")) return (void *)CreateBindCtx;
	else if (0 == strcmp(name, "CreateClassMoniker")) return (void *)CreateClassMoniker;
	else if (0 == strcmp(name, "CreateDataAdviseHolder")) return (void *)CreateDataAdviseHolder;
	else if (0 == strcmp(name, "CreateDataCache")) return (void *)CreateDataCache;
	else if (0 == strcmp(name, "CreateErrorInfo")) return (void *)CreateErrorInfo;
	else if (0 == strcmp(name, "CreateFileMoniker")) return (void *)CreateFileMoniker;
	else if (0 == strcmp(name, "CreateGenericComposite")) return (void *)CreateGenericComposite;
	else if (0 == strcmp(name, "CreateILockBytesOnHGlobal")) return (void *)CreateILockBytesOnHGlobal;
	else if (0 == strcmp(name, "CreateItemMoniker")) return (void *)CreateItemMoniker;
//	else if (0 == strcmp(name, "CreateObjrefMoniker")) return (void *)CreateObjrefMoniker;
	else if (0 == strcmp(name, "CreateOleAdviseHolder")) return (void *)CreateOleAdviseHolder;
	else if (0 == strcmp(name, "CreatePointerMoniker")) return (void *)CreatePointerMoniker;
	else if (0 == strcmp(name, "CreateStdProgressIndicator")) return (void *)CreateStdProgressIndicator;
	else if (0 == strcmp(name, "CreateStreamOnHGlobal")) return (void *)CreateStreamOnHGlobal;
//	else if (0 == strcmp(name, "DcomChannelSetHResult")) return (void *)DcomChannelSetHResult;
//	else if (0 == strcmp(name, "DllDebugObjectRPCHook")) return (void *)DllDebugObjectRPCHook;
	else if (0 == strcmp(name, "DllGetClassObject")) return (void *)DllGetClassObject;
//	else if (0 == strcmp(name, "DllGetClassObjectWOW")) return (void *)DllGetClassObjectWOW;
	else if (0 == strcmp(name, "DllRegisterServer")) return (void *)DllRegisterServer;
	else if (0 == strcmp(name, "DoDragDrop")) return (void *)DoDragDrop;
//	else if (0 == strcmp(name, "EnableHookObject")) return (void *)EnableHookObject;
	else if (0 == strcmp(name, "FmtIdToPropStgName")) return (void *)FmtIdToPropStgName;
	else if (0 == strcmp(name, "FreePropVariantArray")) return (void *)FreePropVariantArray;
	else if (0 == strcmp(name, "GetClassFile")) return (void *)GetClassFile;
	else if (0 == strcmp(name, "GetConvertStg")) return (void *)GetConvertStg;
//	else if (0 == strcmp(name, "GetDocumentBitStg")) return (void *)GetDocumentBitStg;
	else if (0 == strcmp(name, "GetErrorInfo")) return (void *)GetErrorInfo;
	else if (0 == strcmp(name, "GetHGlobalFromILockBytes")) return (void *)GetHGlobalFromILockBytes;
	else if (0 == strcmp(name, "GetHGlobalFromStream")) return (void *)GetHGlobalFromStream;
//	else if (0 == strcmp(name, "GetHookInterface")) return (void *)GetHookInterface;
	else if (0 == strcmp(name, "GetRunningObjectTable")) return (void *)GetRunningObjectTable;
	else if (0 == strcmp(name, "HACCEL_UserFree")) return (void *)HACCEL_UserFree;
	else if (0 == strcmp(name, "HACCEL_UserMarshal")) return (void *)HACCEL_UserMarshal;
	else if (0 == strcmp(name, "HACCEL_UserSize")) return (void *)HACCEL_UserSize;
	else if (0 == strcmp(name, "HACCEL_UserUnmarshal")) return (void *)HACCEL_UserUnmarshal;
	else if (0 == strcmp(name, "HBITMAP_UserFree")) return (void *)HBITMAP_UserFree;
	else if (0 == strcmp(name, "HBITMAP_UserMarshal")) return (void *)HBITMAP_UserMarshal;
	else if (0 == strcmp(name, "HBITMAP_UserSize")) return (void *)HBITMAP_UserSize;
	else if (0 == strcmp(name, "HBITMAP_UserUnmarshal")) return (void *)HBITMAP_UserUnmarshal;
//	else if (0 == strcmp(name, "HBRUSH_UserFree")) return (void *)HBRUSH_UserFree;
//	else if (0 == strcmp(name, "HBRUSH_UserMarshal")) return (void *)HBRUSH_UserMarshal;
//	else if (0 == strcmp(name, "HBRUSH_UserSize")) return (void *)HBRUSH_UserSize;
//	else if (0 == strcmp(name, "HBRUSH_UserUnmarshal")) return (void *)HBRUSH_UserUnmarshal;
	else if (0 == strcmp(name, "HDC_UserFree")) return (void *)HDC_UserFree;
	else if (0 == strcmp(name, "HDC_UserMarshal")) return (void *)HDC_UserMarshal;
	else if (0 == strcmp(name, "HDC_UserSize")) return (void *)HDC_UserSize;
	else if (0 == strcmp(name, "HDC_UserUnmarshal")) return (void *)HDC_UserUnmarshal;
//	else if (0 == strcmp(name, "HENHMETAFILE_UserFree")) return (void *)HENHMETAFILE_UserFree;
//	else if (0 == strcmp(name, "HENHMETAFILE_UserMarshal")) return (void *)HENHMETAFILE_UserMarshal;
//	else if (0 == strcmp(name, "HENHMETAFILE_UserSize")) return (void *)HENHMETAFILE_UserSize;
//	else if (0 == strcmp(name, "HENHMETAFILE_UserUnmarshal")) return (void *)HENHMETAFILE_UserUnmarshal;
	else if (0 == strcmp(name, "HGLOBAL_UserFree")) return (void *)HGLOBAL_UserFree;
	else if (0 == strcmp(name, "HGLOBAL_UserMarshal")) return (void *)HGLOBAL_UserMarshal;
	else if (0 == strcmp(name, "HGLOBAL_UserSize")) return (void *)HGLOBAL_UserSize;
	else if (0 == strcmp(name, "HGLOBAL_UserUnmarshal")) return (void *)HGLOBAL_UserUnmarshal;
	else if (0 == strcmp(name, "HICON_UserFree")) return (void *)HICON_UserFree;
	else if (0 == strcmp(name, "HICON_UserMarshal")) return (void *)HICON_UserMarshal;
	else if (0 == strcmp(name, "HICON_UserSize")) return (void *)HICON_UserSize;
	else if (0 == strcmp(name, "HICON_UserUnmarshal")) return (void *)HICON_UserUnmarshal;
	else if (0 == strcmp(name, "HMENU_UserFree")) return (void *)HMENU_UserFree;
	else if (0 == strcmp(name, "HMENU_UserMarshal")) return (void *)HMENU_UserMarshal;
	else if (0 == strcmp(name, "HMENU_UserSize")) return (void *)HMENU_UserSize;
	else if (0 == strcmp(name, "HMENU_UserUnmarshal")) return (void *)HMENU_UserUnmarshal;
//	else if (0 == strcmp(name, "HMETAFILEPICT_UserFree")) return (void *)HMETAFILEPICT_UserFree;
//	else if (0 == strcmp(name, "HMETAFILEPICT_UserMarshal")) return (void *)HMETAFILEPICT_UserMarshal;
//	else if (0 == strcmp(name, "HMETAFILEPICT_UserSize")) return (void *)HMETAFILEPICT_UserSize;
//	else if (0 == strcmp(name, "HMETAFILEPICT_UserUnmarshal")) return (void *)HMETAFILEPICT_UserUnmarshal;
//	else if (0 == strcmp(name, "HMETAFILE_UserFree")) return (void *)HMETAFILE_UserFree;
//	else if (0 == strcmp(name, "HMETAFILE_UserMarshal")) return (void *)HMETAFILE_UserMarshal;
//	else if (0 == strcmp(name, "HMETAFILE_UserSize")) return (void *)HMETAFILE_UserSize;
//	else if (0 == strcmp(name, "HMETAFILE_UserUnmarshal")) return (void *)HMETAFILE_UserUnmarshal;
	else if (0 == strcmp(name, "HPALETTE_UserFree")) return (void *)HPALETTE_UserFree;
	else if (0 == strcmp(name, "HPALETTE_UserMarshal")) return (void *)HPALETTE_UserMarshal;
	else if (0 == strcmp(name, "HPALETTE_UserSize")) return (void *)HPALETTE_UserSize;
	else if (0 == strcmp(name, "HPALETTE_UserUnmarshal")) return (void *)HPALETTE_UserUnmarshal;
	else if (0 == strcmp(name, "HWND_UserFree")) return (void *)HWND_UserFree;
	else if (0 == strcmp(name, "HWND_UserMarshal")) return (void *)HWND_UserMarshal;
	else if (0 == strcmp(name, "HWND_UserSize")) return (void *)HWND_UserSize;
	else if (0 == strcmp(name, "HWND_UserUnmarshal")) return (void *)HWND_UserUnmarshal;
//	else if (0 == strcmp(name, "HkOleRegisterObject")) return (void *)HkOleRegisterObject;
	else if (0 == strcmp(name, "IIDFromString")) return (void *)IIDFromString;
	else if (0 == strcmp(name, "IsAccelerator")) return (void *)IsAccelerator;
	else if (0 == strcmp(name, "IsEqualGUID")) return (void *)IsEqualGUID;
//	else if (0 == strcmp(name, "IsValidIid")) return (void *)IsValidIid;
//	else if (0 == strcmp(name, "IsValidInterface")) return (void *)IsValidInterface;
//	else if (0 == strcmp(name, "IsValidPtrIn")) return (void *)IsValidPtrIn;
//	else if (0 == strcmp(name, "IsValidPtrOut")) return (void *)IsValidPtrOut;
	else if (0 == strcmp(name, "MkParseDisplayName")) return (void *)MkParseDisplayName;
	else if (0 == strcmp(name, "MonikerCommonPrefixWith")) return (void *)MonikerCommonPrefixWith;
	else if (0 == strcmp(name, "MonikerRelativePathTo")) return (void *)MonikerRelativePathTo;
	else if (0 == strcmp(name, "OleBuildVersion")) return (void *)OleBuildVersion;
	else if (0 == strcmp(name, "OleConvertIStorageToOLESTREAM")) return (void *)OleConvertIStorageToOLESTREAM;
	else if (0 == strcmp(name, "OleConvertIStorageToOLESTREAMEx")) return (void *)OleConvertIStorageToOLESTREAMEx;
	else if (0 == strcmp(name, "OleConvertOLESTREAMToIStorage")) return (void *)OleConvertOLESTREAMToIStorage;
	else if (0 == strcmp(name, "OleConvertOLESTREAMToIStorageEx")) return (void *)OleConvertOLESTREAMToIStorageEx;
	else if (0 == strcmp(name, "OleCreate")) return (void *)OleCreate;
	else if (0 == strcmp(name, "OleCreateDefaultHandler")) return (void *)OleCreateDefaultHandler;
	else if (0 == strcmp(name, "OleCreateEmbeddingHelper")) return (void *)OleCreateEmbeddingHelper;
	else if (0 == strcmp(name, "OleCreateEx")) return (void *)OleCreateEx;
	else if (0 == strcmp(name, "OleCreateFromData")) return (void *)OleCreateFromData;
	else if (0 == strcmp(name, "OleCreateFromDataEx")) return (void *)OleCreateFromDataEx;
	else if (0 == strcmp(name, "OleCreateFromFile")) return (void *)OleCreateFromFile;
	else if (0 == strcmp(name, "OleCreateFromFileEx")) return (void *)OleCreateFromFileEx;
	else if (0 == strcmp(name, "OleCreateLink")) return (void *)OleCreateLink;
	else if (0 == strcmp(name, "OleCreateLinkEx")) return (void *)OleCreateLinkEx;
	else if (0 == strcmp(name, "OleCreateLinkFromData")) return (void *)OleCreateLinkFromData;
	else if (0 == strcmp(name, "OleCreateLinkFromDataEx")) return (void *)OleCreateLinkFromDataEx;
	else if (0 == strcmp(name, "OleCreateLinkToFile")) return (void *)OleCreateLinkToFile;
	else if (0 == strcmp(name, "OleCreateLinkToFileEx")) return (void *)OleCreateLinkToFileEx;
	else if (0 == strcmp(name, "OleCreateMenuDescriptor")) return (void *)OleCreateMenuDescriptor;
	else if (0 == strcmp(name, "OleCreateStaticFromData")) return (void *)OleCreateStaticFromData;
	else if (0 == strcmp(name, "OleDestroyMenuDescriptor")) return (void *)OleDestroyMenuDescriptor;
	else if (0 == strcmp(name, "OleDoAutoConvert")) return (void *)OleDoAutoConvert;
	else if (0 == strcmp(name, "OleDraw")) return (void *)OleDraw;
	else if (0 == strcmp(name, "OleDuplicateData")) return (void *)OleDuplicateData;
	else if (0 == strcmp(name, "OleFlushClipboard")) return (void *)OleFlushClipboard;
	else if (0 == strcmp(name, "OleGetAutoConvert")) return (void *)OleGetAutoConvert;
	else if (0 == strcmp(name, "OleGetClipboard")) return (void *)OleGetClipboard;
	else if (0 == strcmp(name, "OleGetIconOfClass")) return (void *)OleGetIconOfClass;
	else if (0 == strcmp(name, "OleGetIconOfFile")) return (void *)OleGetIconOfFile;
	else if (0 == strcmp(name, "OleInitialize")) return (void *)OleInitialize;
//	else if (0 == strcmp(name, "OleInitializeWOW")) return (void *)OleInitializeWOW;
	else if (0 == strcmp(name, "OleIsCurrentClipboard")) return (void *)OleIsCurrentClipboard;
	else if (0 == strcmp(name, "OleIsRunning")) return (void *)OleIsRunning;
	else if (0 == strcmp(name, "OleLoad")) return (void *)OleLoad;
	else if (0 == strcmp(name, "OleLoadFromStream")) return (void *)OleLoadFromStream;
	else if (0 == strcmp(name, "OleLockRunning")) return (void *)OleLockRunning;
	else if (0 == strcmp(name, "OleMetafilePictFromIconAndLabel")) return (void *)OleMetafilePictFromIconAndLabel;
	else if (0 == strcmp(name, "OleNoteObjectVisible")) return (void *)OleNoteObjectVisible;
	else if (0 == strcmp(name, "OleQueryCreateFromData")) return (void *)OleQueryCreateFromData;
	else if (0 == strcmp(name, "OleQueryLinkFromData")) return (void *)OleQueryLinkFromData;
	else if (0 == strcmp(name, "OleRegEnumFormatEtc")) return (void *)OleRegEnumFormatEtc;
	else if (0 == strcmp(name, "OleRegEnumVerbs")) return (void *)OleRegEnumVerbs;
	else if (0 == strcmp(name, "OleRegGetMiscStatus")) return (void *)OleRegGetMiscStatus;
	else if (0 == strcmp(name, "OleRegGetUserType")) return (void *)OleRegGetUserType;
	else if (0 == strcmp(name, "OleRun")) return (void *)OleRun;
	else if (0 == strcmp(name, "OleSave")) return (void *)OleSave;
	else if (0 == strcmp(name, "OleSaveToStream")) return (void *)OleSaveToStream;
	else if (0 == strcmp(name, "OleSetAutoConvert")) return (void *)OleSetAutoConvert;
	else if (0 == strcmp(name, "OleSetClipboard")) return (void *)OleSetClipboard;
	else if (0 == strcmp(name, "OleSetContainedObject")) return (void *)OleSetContainedObject;
	else if (0 == strcmp(name, "OleSetMenuDescriptor")) return (void *)OleSetMenuDescriptor;
	else if (0 == strcmp(name, "OleTranslateAccelerator")) return (void *)OleTranslateAccelerator;
	else if (0 == strcmp(name, "OleUninitialize")) return (void *)OleUninitialize;
//	else if (0 == strcmp(name, "OpenOrCreateStream")) return (void *)OpenOrCreateStream;
	else if (0 == strcmp(name, "ProgIDFromCLSID")) return (void *)ProgIDFromCLSID;
	else if (0 == strcmp(name, "PropStgNameToFmtId")) return (void *)PropStgNameToFmtId;
//	else if (0 == strcmp(name, "PropSysAllocString")) return (void *)PropSysAllocString;
//	else if (0 == strcmp(name, "PropSysFreeString")) return (void *)PropSysFreeString;
//	else if (0 == strcmp(name, "PropVariantChangeType")) return (void *)PropVariantChangeType;
	else if (0 == strcmp(name, "PropVariantClear")) return (void *)PropVariantClear;
	else if (0 == strcmp(name, "PropVariantCopy")) return (void *)PropVariantCopy;
	else if (0 == strcmp(name, "ReadClassStg")) return (void *)ReadClassStg;
	else if (0 == strcmp(name, "ReadClassStm")) return (void *)ReadClassStm;
	else if (0 == strcmp(name, "ReadFmtUserTypeStg")) return (void *)ReadFmtUserTypeStg;
//	else if (0 == strcmp(name, "ReadOleStg")) return (void *)ReadOleStg;
//	else if (0 == strcmp(name, "ReadStringStream")) return (void *)ReadStringStream;
	else if (0 == strcmp(name, "RegisterDragDrop")) return (void *)RegisterDragDrop;
	else if (0 == strcmp(name, "ReleaseStgMedium")) return (void *)ReleaseStgMedium;
	else if (0 == strcmp(name, "RevokeDragDrop")) return (void *)RevokeDragDrop;
	else if (0 == strcmp(name, "SNB_UserFree")) return (void *)SNB_UserFree;
	else if (0 == strcmp(name, "SNB_UserMarshal")) return (void *)SNB_UserMarshal;
	else if (0 == strcmp(name, "SNB_UserSize")) return (void *)SNB_UserSize;
	else if (0 == strcmp(name, "SNB_UserUnmarshal")) return (void *)SNB_UserUnmarshal;
	else if (0 == strcmp(name, "STGMEDIUM_UserFree")) return (void *)STGMEDIUM_UserFree;
	else if (0 == strcmp(name, "STGMEDIUM_UserMarshal")) return (void *)STGMEDIUM_UserMarshal;
	else if (0 == strcmp(name, "STGMEDIUM_UserSize")) return (void *)STGMEDIUM_UserSize;
	else if (0 == strcmp(name, "STGMEDIUM_UserUnmarshal")) return (void *)STGMEDIUM_UserUnmarshal;
	else if (0 == strcmp(name, "SetConvertStg")) return (void *)SetConvertStg;
//	else if (0 == strcmp(name, "SetDocumentBitStg")) return (void *)SetDocumentBitStg;
	else if (0 == strcmp(name, "SetErrorInfo")) return (void *)SetErrorInfo;
//	else if (0 == strcmp(name, "StgConvertPropertyToVariant")) return (void *)StgConvertPropertyToVariant;
//	else if (0 == strcmp(name, "StgConvertVariantToProperty")) return (void *)StgConvertVariantToProperty;
	else if (0 == strcmp(name, "StgCreateDocfile")) return (void *)StgCreateDocfile;
	else if (0 == strcmp(name, "StgCreateDocfileOnILockBytes")) return (void *)StgCreateDocfileOnILockBytes;
	else if (0 == strcmp(name, "StgCreatePropSetStg")) return (void *)StgCreatePropSetStg;
	else if (0 == strcmp(name, "StgCreatePropStg")) return (void *)StgCreatePropStg;
	else if (0 == strcmp(name, "StgCreateStorageEx")) return (void *)StgCreateStorageEx;
	else if (0 == strcmp(name, "StgGetIFillLockBytesOnFile")) return (void *)StgGetIFillLockBytesOnFile;
	else if (0 == strcmp(name, "StgGetIFillLockBytesOnILockBytes")) return (void *)StgGetIFillLockBytesOnILockBytes;
	else if (0 == strcmp(name, "StgIsStorageFile")) return (void *)StgIsStorageFile;
	else if (0 == strcmp(name, "StgIsStorageILockBytes")) return (void *)StgIsStorageILockBytes;
	else if (0 == strcmp(name, "StgOpenAsyncDocfileOnIFillLockBytes")) return (void *)StgOpenAsyncDocfileOnIFillLockBytes;
	else if (0 == strcmp(name, "StgOpenPropStg")) return (void *)StgOpenPropStg;
	else if (0 == strcmp(name, "StgOpenStorage")) return (void *)StgOpenStorage;
	else if (0 == strcmp(name, "StgOpenStorageEx")) return (void *)StgOpenStorageEx;
//	else if (0 == strcmp(name, "StgOpenStorageOnHandle")) return (void *)StgOpenStorageOnHandle;
	else if (0 == strcmp(name, "StgOpenStorageOnILockBytes")) return (void *)StgOpenStorageOnILockBytes;
//	else if (0 == strcmp(name, "StgPropertyLengthAsVariant")) return (void *)StgPropertyLengthAsVariant;
	else if (0 == strcmp(name, "StgSetTimes")) return (void *)StgSetTimes;
	else if (0 == strcmp(name, "StringFromCLSID")) return (void *)StringFromCLSID;
	else if (0 == strcmp(name, "StringFromGUID2")) return (void *)StringFromGUID2;
	else if (0 == strcmp(name, "StringFromIID")) return (void *)StringFromIID;
//	else if (0 == strcmp(name, "UpdateDCOMSettings")) return (void *)UpdateDCOMSettings;
//	else if (0 == strcmp(name, "UtConvertDvtd16toDvtd32")) return (void *)UtConvertDvtd16toDvtd32;
//	else if (0 == strcmp(name, "UtConvertDvtd32toDvtd16")) return (void *)UtConvertDvtd32toDvtd16;
//	else if (0 == strcmp(name, "UtGetDvtd16Info")) return (void *)UtGetDvtd16Info;
//	else if (0 == strcmp(name, "UtGetDvtd32Info")) return (void *)UtGetDvtd32Info;
//	else if (0 == strcmp(name, "WdtpInterfacePointer_UserFree")) return (void *)WdtpInterfacePointer_UserFree;
//	else if (0 == strcmp(name, "WdtpInterfacePointer_UserMarshal")) return (void *)WdtpInterfacePointer_UserMarshal;
//	else if (0 == strcmp(name, "WdtpInterfacePointer_UserSize")) return (void *)WdtpInterfacePointer_UserSize;
//	else if (0 == strcmp(name, "WdtpInterfacePointer_UserUnmarshal")) return (void *)WdtpInterfacePointer_UserUnmarshal;
	else if (0 == strcmp(name, "WriteClassStg")) return (void *)WriteClassStg;
	else if (0 == strcmp(name, "WriteClassStm")) return (void *)WriteClassStm;
	else if (0 == strcmp(name, "WriteFmtUserTypeStg")) return (void *)WriteFmtUserTypeStg;
//	else if (0 == strcmp(name, "WriteOleStg")) return (void *)WriteOleStg;
//	else if (0 == strcmp(name, "WriteStringStream")) return (void *)WriteStringStream;
	return NULL;
}
