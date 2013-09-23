/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 �Ƃ悵��
 *  $Id: HResult.h,v 1.1 2003/05/01 02:43:55 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [HResult.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__HResult_h__)
#	define __HResult_h__

#	define FACILITY_NULL			0
#	define FACILITY_RPC				1
#	define FACILITY_DISPATCH		2
#	define FACILITY_STORAGE			3
#	define FACILITY_ITF				4
#	define FACILITY_WIN32			7
#	define FACILITY_WINDOWS			8
#	define FACILITY_SSPI			9
#	define FACILITY_CONTROL			10
#	define FACILITY_CERT			11
#	define FACILITY_INTERNET		12
#	define FACILITY_MEDIASERVER		13
#	define FACILITY_MSMQ			14
#	define FACILITY_SETUPAPI		15

#	define SEVERITY_SUCCESS			0
#	define SEVERITY_ERROR			1

#	define SUCCEEDED(code)			((HRESULT)code >= 0)
#	define FAILED(code)				((HRESULT)code < 0)

#	define IS_ERROR(code)			((unsigned long)code >> 31 == SEVERITY_ERROR)

#	define HRESULT_CODE(code)		(code & 0xffff)
#	define SCODE_CODE(code)			(code & 0xffff)

#	define HRESULT_FACILITY(code)	((code >> 16) & 0x1fff)
#	define SCODE_FACILITY(code)		((code >> 16) & 0x1fff)

#	define HRESULT_SEVERITY(code)	((code >> 31) & 1)
#	define SCODE_SEVERITY(code)		((code >> 31) & 1)

#	define MAKE_HRESULT(sev, fac, code) \
	((HRESULT) (((unsigned long)(sev) << 31) | ((unsigned long)(fac) << 16) | ((unsigned long)code)))

#	define MAKE_SCODE(sev, fac, code) \
	((SCODE) (((unsigned long)(sev) << 31) | ((unsigned long)(fac) << 16) | ((unsigned long)code)))

#	define HRESULT_FROM_WIN32(code) \
	(code? ((HRESULT) (((code) & 0x0000ffff) | (FACILITY_WIN32 << 16) | 0x80000000)): 0)

#	define	_HRESULT_TYPEDEF_(code) ((HRESULT)code)


#	define NOERROR								0

#	define E_UNEXPECTED							_HRESULT_TYPEDEF_(0x8000ffffL)

#	if defined(__BEOS__) && !defined(_WIN32)
#		define	_WIN32
#	endif	// defined(__BEOS__) && !defined(_WIN32)

#	if defined(_WIN32) && !defined(_MAC)
#		define E_NOTIMPL							_HRESULT_TYPEDEF_(0x80004001L)
#		define E_OUTOFMEMORY						_HRESULT_TYPEDEF_(0x8007000eL)
#		define E_INVALIDARG							_HRESULT_TYPEDEF_(0x80070057L)
#		define E_NOINTERFACE						_HRESULT_TYPEDEF_(0x80004002L)
#		define E_POINTER							_HRESULT_TYPEDEF_(0x80004003L)
#		define E_HANDLE								_HRESULT_TYPEDEF_(0x80070006L)
#		define E_ABORT								_HRESULT_TYPEDEF_(0x80004004L)
#		define E_FAIL								_HRESULT_TYPEDEF_(0x80004005L)
#		define E_ACCESSDENIED						_HRESULT_TYPEDEF_(0x80070005L)
#	else	// defined(_WIN32) && !defined(_MAC)
#		define E_NOTIMPL							_HRESULT_TYPEDEF_(0x80000001L)
#		define E_OUTOFMEMORY						_HRESULT_TYPEDEF_(0x80000002L)
#		define E_INVALIDARG							_HRESULT_TYPEDEF_(0x80000003L)
#		define E_NOINTERFACE						_HRESULT_TYPEDEF_(0x80000004L)
#		define E_POINTER							_HRESULT_TYPEDEF_(0x80000005L)
#		define E_HANDLE								_HRESULT_TYPEDEF_(0x80000006L)
#		define E_ABORT								_HRESULT_TYPEDEF_(0x80000007L)
#		define E_FAIL								_HRESULT_TYPEDEF_(0x80000008L)
#		define E_ACCESSDENIED						_HRESULT_TYPEDEF_(0x80000009L)
#		define E_PENDING							_HRESULT_TYPEDEF_(0x8000000aL)
#	endif	// defined(_WIN32) && !defined(_MAC)

#	define CO_E_INIT_TLS						_HRESULT_TYPEDEF_(0x80004006L)
#	define CO_E_INIT_SHARED_ALLOCATOR			_HRESULT_TYPEDEF_(0x80004007L)
#	define CO_E_INIT_MEMORY_ALLOCATOR			_HRESULT_TYPEDEF_(0x80004008L)
#	define CO_E_INIT_CLASS_CACHE				_HRESULT_TYPEDEF_(0x80004009L)
#	define CO_E_INIT_RPC_CHANNEL				_HRESULT_TYPEDEF_(0x8000400aL)
#	define CO_E_INIT_TLS_SET_CHANNEL_CONTROL	_HRESULT_TYPEDEF_(0x8000400bL)
#	define CO_E_INIT_TLS_CHANNEL_CONTROL		_HRESULT_TYPEDEF_(0x8000400cL)
#	define CO_E_INIT_UNACCEPTED_USER_ALLOCATOR	_HRESULT_TYPEDEF_(0x8000400dL)
#	define CO_E_INIT_SCM_MUTEX_EXISTS			_HRESULT_TYPEDEF_(0x8000400eL)
#	define CO_E_INIT_SCM_FILE_MAPPING_EXISTS	_HRESULT_TYPEDEF_(0x8000400fL)
#	define CO_E_INIT_SCM_MAP_VIEW_OF_FILE		_HRESULT_TYPEDEF_(0x80004010L)
#	define CO_E_INIT_SCM_EXEC_FAILURE			_HRESULT_TYPEDEF_(0x80004011L)
#	define CO_E_INIT_ONLY_SINGLE_THREADED		_HRESULT_TYPEDEF_(0x80004012L)
#	define CO_E_CANT_REMOTE						_HRESULT_TYPEDEF_(0x80004013L)
#	define CO_E_BAD_SERVER_NAME					_HRESULT_TYPEDEF_(0x80004014L)
#	define CO_E_WRONG_SERVER_IDENTITY			_HRESULT_TYPEDEF_(0x80004015L)
#	define CO_E_OLE1DDE_DISABLED				_HRESULT_TYPEDEF_(0x80004016L)
#	define CO_E_RUNAS_SYNTAX					_HRESULT_TYPEDEF_(0x80004017L)
#	define CO_E_CREATEPROCESS_FAILURE			_HRESULT_TYPEDEF_(0x80004018L)
#	define CO_E_RUNAS_CREATEPROCESS_FAILURE		_HRESULT_TYPEDEF_(0x80004019L)
#	define CO_E_RUNAS_LOGON_FAILURE				_HRESULT_TYPEDEF_(0x8000401aL)
#	define CO_E_LAUNCH_PERMSSION_DENIED			_HRESULT_TYPEDEF_(0x8000401bL)
#	define CO_E_START_SERVICE_FAILURE			_HRESULT_TYPEDEF_(0x8000401cL)
#	define CO_E_REMOTE_COMMUNICATION_FAILURE	_HRESULT_TYPEDEF_(0x8000401dL)
#	define CO_E_SERVER_START_TIMEOUT			_HRESULT_TYPEDEF_(0x8000401eL)
#	define CO_E_CLSREG_INCONSISTENT				_HRESULT_TYPEDEF_(0x8000401fL)
#	define CO_E_IIDREG_INCONSISTENT				_HRESULT_TYPEDEF_(0x80004020L)
#	define CO_E_NOT_SUPPORTED					_HRESULT_TYPEDEF_(0x80004021L)
#	define CO_E_RELOAD_DLL						_HRESULT_TYPEDEF_(0x80004022L)
#	define CO_E_MSI_ERROR						_HRESULT_TYPEDEF_(0x80004023L)
#	define CO_E_FIRST							_HRESULT_TYPEDEF_(0x800401f0L)
#	define CO_E_LAST							_HRESULT_TYPEDEF_(0x800401ffL)
#	define CO_E_NOTINITIALIZED					_HRESULT_TYPEDEF_(0x800401f0L)
#	define CO_E_ALREADYINITIALIZED				_HRESULT_TYPEDEF_(0x800401f1L)
#	define CO_E_CANTDETERMINECLASS				_HRESULT_TYPEDEF_(0x800401f2L)
#	define CO_E_CLASSSTRING						_HRESULT_TYPEDEF_(0x800401f3L)
#	define CO_E_IIDSTRING						_HRESULT_TYPEDEF_(0x800401f4L)
#	define CO_E_APPNOTFOUND						_HRESULT_TYPEDEF_(0x800401f5L)
#	define CO_E_APPSINGLEUSE					_HRESULT_TYPEDEF_(0x800401f6L)
#	define CO_E_ERRORINAPP						_HRESULT_TYPEDEF_(0x800401f7L)
#	define CO_E_DLLNOTFOUND						_HRESULT_TYPEDEF_(0x800401f8L)
#	define CO_E_ERRORINDLL						_HRESULT_TYPEDEF_(0x800401f9L)
#	define CO_E_WRONGOSFORAPP					_HRESULT_TYPEDEF_(0x800401faL)
#	define CO_E_OBJNOTREG						_HRESULT_TYPEDEF_(0x800401fbL)
#	define CO_E_OBJISREG						_HRESULT_TYPEDEF_(0x800401fcL)
#	define CO_E_OBJNOTCONNECTED					_HRESULT_TYPEDEF_(0x800401fdL)
#	define CO_E_APPDIDNTREG						_HRESULT_TYPEDEF_(0x800401feL)
#	define CO_E_RELEASED						_HRESULT_TYPEDEF_(0x800401ffL)
#	define CO_E_FAILEDTOIMPERSONATE				_HRESULT_TYPEDEF_(0x80040200L)
#	define CO_E_FAILEDTOGETSECCTX				_HRESULT_TYPEDEF_(0x80040201L)
#	define CO_E_FAILEDTOOPENTHREADTOKEN			_HRESULT_TYPEDEF_(0x80040202L)
#	define CO_E_FAILEDTOGETTOKENINFO			_HRESULT_TYPEDEF_(0x80040203L)
#	define CO_E_TRUSTEEDOESNTMATCHCLIENT		_HRESULT_TYPEDEF_(0x80040204L)
#	define CO_E_FAILEDTOQUERYCLIENTBLANKET		_HRESULT_TYPEDEF_(0x80040205L)
#	define CO_E_FAILEDTOSETDACL					_HRESULT_TYPEDEF_(0x80040206L)
#	define CO_E_ACCESSCHECKFAILED				_HRESULT_TYPEDEF_(0x80040207L)
#	define CO_E_NETACCESSAPIFAILED				_HRESULT_TYPEDEF_(0x80040208L)
#	define CO_E_WRONGTRUSTEENAMESYNTAX			_HRESULT_TYPEDEF_(0x80040209L)
#	define CO_E_INVALIDSID						_HRESULT_TYPEDEF_(0x8004020aL)
#	define CO_E_CONVERSIONFAILED				_HRESULT_TYPEDEF_(0x8004020bL)
#	define CO_E_NOMATCHINGSIDFOUND				_HRESULT_TYPEDEF_(0x8004020cL)
#	define CO_E_LOOKUPACCSIDFAILED				_HRESULT_TYPEDEF_(0x8004020dL)
#	define CO_E_NOMATCHINGNAMEFOUND				_HRESULT_TYPEDEF_(0x8004020eL)
#	define CO_E_LOOKUPACCNAMEFAILED				_HRESULT_TYPEDEF_(0x8004020fL)
#	define CO_E_SETSERLHNDLFAILED				_HRESULT_TYPEDEF_(0x80040210L)
#	define CO_E_FAILEDTOGETWINDIR				_HRESULT_TYPEDEF_(0x80040211L)
#	define CO_E_PATHTOOLONG						_HRESULT_TYPEDEF_(0x80040212L)
#	define CO_E_FAILEDTOGENUUID					_HRESULT_TYPEDEF_(0x80040213L)
#	define CO_E_FAILEDTOCREATEFILE				_HRESULT_TYPEDEF_(0x80040214L)
#	define CO_E_FAILEDTOCLOSEHANDLE				_HRESULT_TYPEDEF_(0x80040215L)
#	define CO_E_EXCEEDSYSACLLIMIT				_HRESULT_TYPEDEF_(0x80040216L)
#	define CO_E_ACESINWRONGORDER				_HRESULT_TYPEDEF_(0x80040217L)
#	define CO_E_INCOMPATIBLESTREAMVERSION		_HRESULT_TYPEDEF_(0x80040218L)
#	define CO_E_FAILEDTOOPENPROCESSTOKEN		_HRESULT_TYPEDEF_(0x80040219L)
#	define CO_E_DECODEFAILED					_HRESULT_TYPEDEF_(0x8004021aL)
#	define CO_E_ACNOTINITIALIZED				_HRESULT_TYPEDEF_(0x8004021bL)
#	define CO_E_CLASS_CREATE_FAILED				_HRESULT_TYPEDEF_(0x80080001L)
#	define CO_E_SCM_ERROR						_HRESULT_TYPEDEF_(0x80080002L)
#	define CO_E_SCM_RPC_FAILURE					_HRESULT_TYPEDEF_(0x80080003L)
#	define CO_E_BAD_PATH						_HRESULT_TYPEDEF_(0x80080004L)
#	define CO_E_SERVER_EXEC_FAILURE				_HRESULT_TYPEDEF_(0x80080005L)
#	define CO_E_OBJSRV_RPC_FAILURE				_HRESULT_TYPEDEF_(0x80080006L)
#	define CO_E_SERVER_STOPPING					_HRESULT_TYPEDEF_(0x80080008L)
#	define CO_E_SERVER_STOPPING					_HRESULT_TYPEDEF_(0x80080008L)
#	define CO_E_SERVER_STOPPING					_HRESULT_TYPEDEF_(0x80080008L)


#endif	// !defined(__HResult_h__)
