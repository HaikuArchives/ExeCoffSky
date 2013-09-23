/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Registry.cpp,v 1.1 2003/05/01 02:42:42 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Registry.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Registry.h"
#include "LastError.h"
#include "Kernel32/Path.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

#define WIN_HOME			"/boot/home/config/windows"
#define REG_HOME			"/boot/home/config/windows/registry"
#define IS_SYSHKEY(hKey)	(((ULONG)HKEY_CLASSES_ROOT <= (ULONG)hKey) && ((ULONG)hKey <= (ULONG)HKEY_DYN_DATA))

char *
Registry::syskeys[] = {
	"HKEY_CLASS_ROOT", "HKEY_CURRENT_USER", "HKEY_LOCAL_MACHINE", "HKEY_USERS",
	"HKEY_PERFORMANCE_DATA", "HKEY_CURRENT_CONFIG", "HKEY_DYN_DATA",
};

Registry::Registry
(REGSAM sam):
magic(REGISTRY_MAGIC),
keypath(NULL),
keypathlen(0),
sam(sam)
{
}

Registry::Registry
(const Registry &src):
magic(src.magic),
keypathlen(src.keypathlen),
sam(sam)
{
	keypath = strdup(src.keypath);
}

Registry::~Registry
(void)
{
	if (NULL != keypath) free(keypath);
}

ULONG
Registry::Open
(HKEY hKey, LPCSTR lpSubKey)
{
	ULONG rc = ERROR_SUCCESS;
	struct stat st;
	if ((0 != stat(WIN_HOME, &st)) && (0 != mkdir(WIN_HOME, 0777))) rc = ERROR_PATH_NOT_FOUND;
	else if ((0 != stat(REG_HOME, &st)) && (0 != mkdir(REG_HOME, 0777))) rc = ERROR_PATH_NOT_FOUND;
	else {
		BString path;
		if (IS_SYSHKEY(hKey)) {
			path.SetTo(REG_HOME);
			path << "/";
			path << syskeys[(int)hKey & 0xff];
			if (0 != stat(path.String(), &st)) mkdir(path.String(), 0777);
		} else {
			path.SetTo(REINTERPRET_CAST(Registry *, hKey)->GetPath());
		}
		path << "/" << lpSubKey;
		Path fixpath(path.String());
		fixpath.ToNativePath(false);
		WIN32API_INFO("\tNewRegPath: %s\n", fixpath.GetPath());
		keypath = strdup(fixpath.GetPath());
		if (NULL == keypath) rc = ERROR_NOT_ENOUGH_MEMORY;
		else {
			if ((0 != stat(keypath, &st)) || !S_ISDIR(st.st_mode)) rc = ERROR_PATH_NOT_FOUND;
			else rc = ERROR_SUCCESS;
		}
	}
	WIN32API_INFO("\topen ... %s\n", (rc == ERROR_SUCCESS)? "OK": "ERR");
	return rc;
}

ULONG
Registry::Query
(LPCSTR lpValueName, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	if (0 == (sam & KEY_QUERY_VALUE)) return ERROR_ACCESS_DENIED;
	BString path(keypath);
	path << "/";
	path << lpValueName;
	struct stat st;
	if (0 != stat(path.String(), &st)) return ERROR_NOT_FOUND;
	BNode node(path.String());
	if (B_OK != node.InitCheck()) return ERROR_ACCESS_DENIED;
	while(B_OK != node.Lock()) snooze(1000);
	status_t rc = B_OK;
	if (NULL != lpType) rc = node.ReadAttr("REG:type", B_UINT32_TYPE, 0, lpType, sizeof(DWORD));
	if (rc == sizeof(DWORD)) {
		if (NULL != lpType) WIN32API_INFO("\ttype = %d\n", *lpType);
		attr_info info;
		rc = node.GetAttrInfo("REG:data", &info);
		if (B_OK == rc) {
			if (NULL == lpData) *lpcbData = info.size;
			else if (*lpcbData < info.size) {
				node.Unlock();
				return ERROR_MORE_DATA;
			}
			uint32 type;
			rc = node.ReadAttr("REG:data", B_ANY_TYPE, 0, lpData, *lpcbData);
			if (rc >= B_OK) WIN32API_INFO("\tReadAttr Success: %d\n", rc);
			rc = B_OK;
		}
	} else WIN32API_INFO("\ttype not found\n");
	node.Unlock();
	switch (rc) {
	case B_OK:
		return ERROR_SUCCESS;
	case B_ENTRY_NOT_FOUND:
		return ERROR_PATH_NOT_FOUND;
	case B_FILE_ERROR:
	case B_NOT_ALLOWED:
		return ERROR_ACCESS_DENIED;
	case B_DEVICE_FULL:
		return ERROR_DATABASE_FULL;
	case B_NO_MEMORY:
		return ERROR_NOT_ENOUGH_MEMORY;
	}
	return ERROR_NOT_ENOUGH_MEMORY;
}

void
Registry::SetSam
(REGSAM sam)
{
	this->sam = sam;
}

REGSAM
Registry::GetSam
(void) const
{
	return sam;
}

LPCSTR
Registry::GetPath
(void) const
{
	return keypath;
}

Registry *
Registry::HandleToRegistry
(HKEY hKey)
{
	if (NULL == hKey) return NULL;
	Registry *reg = (Registry *)hKey;
	if (reg->magic != REGISTRY_MAGIC) return NULL;
	return reg;
}

static LONG
RegOpenKeyExU
(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	bool syskey = IS_SYSHKEY(hKey);
	if (!syskey && (NULL == Registry::HandleToRegistry(hKey))) {
		rc = ERROR_INVALID_HANDLE;
	} else if (NULL == phkResult) {
		rc = ERROR_BAD_ARGUMENTS;
	} else {
		Registry *reg = Registry::HandleToRegistry(hKey);
		WIN32API_INFO("\thKey PATH: %s\n", syskey? Registry::syskeys[(int)hKey & 0xff]: reg->GetPath());
		WIN32API_INFO("\tlpSubKey: %s\n", lpSubKey);
		if (0 != ulOptions) WIN32API_INFO("\tWarning: ulOptions: %08x\n", ulOptions);
		if ((NULL == lpSubKey) || ('\0' == *lpSubKey)) {
			// dup handle
			if (!syskey) {
				Registry *newreg = new Registry(*reg);
				if (NULL == newreg) rc = ERROR_NOT_ENOUGH_MEMORY;
				else {
					newreg->SetSam(samDesired);
					*phkResult = REINTERPRET_CAST(HKEY, newreg);
					rc = ERROR_SUCCESS;
				}
			} else {
				*phkResult = hKey;
				rc = ERROR_SUCCESS;
			}
		} else {
			// open handle
			Registry *newreg = new Registry(samDesired);
			if (NULL == newreg) rc = ERROR_NOT_ENOUGH_MEMORY;
			else {
				rc = newreg->Open(hKey, lpSubKey);
				if (ERROR_SUCCESS != rc) delete newreg;
				else {
					*phkResult = REINTERPRET_CAST(HKEY, newreg);
					if (!syskey) delete REINTERPRET_CAST(Registry *, hKey);
				}
			}
		}
	}
	WIN32API_INFO("\t*phkResult: $%08x\n", *phkResult);
	WIN32API_ERROR(rc);
	return rc;
}

static LONG
RegQueryValueExU
(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	bool syskey = IS_SYSHKEY(hKey);
	if (!syskey && (NULL == Registry::HandleToRegistry(hKey))) {
		rc = ERROR_INVALID_HANDLE;
	} else if (NULL == lpcbData) {
		rc = ERROR_BAD_ARGUMENTS;
	} else {
		Registry *reg = Registry::HandleToRegistry(hKey);
		WIN32API_INFO("\thKey PATH: %s\n", syskey? Registry::syskeys[(int)hKey & 0xff]: reg->GetPath());
		WIN32API_INFO("\tlpValueName: %s\n", lpValueName);
		rc = reg->Query(lpValueName, lpType, lpData, lpcbData);
	}
	return rc;
}

extern "C" LONG WINAPI
RegCloseKey
(HKEY hKey)
{
	LONG rc = ERROR_SUCCESS;
	WIN32API_ENTER("LONG", "RegCloseKey", "HKEY", hKey, NULL);
	bool syskey = IS_SYSHKEY(hKey);
	if (!syskey && (NULL == Registry::HandleToRegistry(hKey))) rc = ERROR_INVALID_HANDLE;
	else if (!syskey) delete REINTERPRET_CAST(Registry *, hKey);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegConnectRegistryA
(LPSTR arg0, HKEY arg1, PHKEY arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegConnectRegistryA", "LPSTR", arg0, "HKEY", arg1, "PHKEY", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegConnectRegistryW
(LPWSTR arg0, HKEY arg1, PHKEY arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegConnectRegistryW", "LPWSTR", arg0, "HKEY", arg1, "PHKEY", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegCreateKeyA
(HKEY arg0, LPCSTR arg1, PHKEY arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegCreateKeyA", "HKEY", arg0, "LPCSTR", arg1, "PHKEY", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegCreateKeyW
(HKEY arg0, LPCWSTR arg1, PHKEY arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegCreateKeyW", "HKEY", arg0, "LPCWSTR", arg1, "PHKEY", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegCreateKeyExA
(HKEY arg0, LPCSTR arg1, DWORD arg2, LPSTR arg3, DWORD arg4, REGSAM arg5, LPSECURITY_ATTRIBUTES arg6, PHKEY arg7, PDWORD arg8)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegCreateKeyExA", "HKEY", arg0, "LPCSTR", arg1, "DWORD", arg2, "LPSTR", arg3, "DWORD", arg4, "REGSAM", arg5, "LPSECURITY_ATTRIBUTES", arg6, "PHKEY", arg7, "PDWORD", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegCreateKeyExW
(HKEY arg0, LPCWSTR arg1, DWORD arg2, LPWSTR arg3, DWORD arg4, REGSAM arg5, LPSECURITY_ATTRIBUTES arg6, PHKEY arg7, PDWORD arg8)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegCreateKeyExW", "HKEY", arg0, "LPCWSTR", arg1, "DWORD", arg2, "LPWSTR", arg3, "DWORD", arg4, "REGSAM", arg5, "LPSECURITY_ATTRIBUTES", arg6, "PHKEY", arg7, "PDWORD", arg8, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegDeleteKeyA
(HKEY arg0, LPCSTR arg1)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegDeleteKeyA", "HKEY", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegDeleteKeyW
(HKEY arg0, LPCWSTR arg1)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegDeleteKeyW", "HKEY", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegDeleteValueA
(HKEY arg0, LPCSTR arg1)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegDeleteValueA", "HKEY", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegDeleteValueW
(HKEY arg0, LPCWSTR arg1)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegDeleteValueW", "HKEY", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegEnumKeyA
(HKEY arg0, DWORD arg1, LPSTR arg2, DWORD arg3)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegEnumKeyA", "HKEY", arg0, "DWORD", arg1, "LPSTR", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegEnumKeyW
(HKEY arg0, DWORD arg1, LPWSTR arg2, DWORD arg3)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegEnumKeyW", "HKEY", arg0, "DWORD", arg1, "LPWSTR", arg2, "DWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegEnumKeyExA
(HKEY arg0, DWORD arg1, LPSTR arg2, PDWORD arg3, PDWORD arg4, LPSTR arg5, PDWORD arg6, PFILETIME arg7)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegEnumKeyExA", "HKEY", arg0, "DWORD", arg1, "LPSTR", arg2, "PDWORD", arg3, "PDWORD", arg4, "LPSTR", arg5, "PDWORD", arg6, "PFILETIME", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegEnumKeyExW
(HKEY arg0, DWORD arg1, LPWSTR arg2, PDWORD arg3, PDWORD arg4, LPWSTR arg5, PDWORD arg6, PFILETIME arg7)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegEnumKeyExW", "HKEY", arg0, "DWORD", arg1, "LPWSTR", arg2, "PDWORD", arg3, "PDWORD", arg4, "LPWSTR", arg5, "PDWORD", arg6, "PFILETIME", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegEnumValueA
(HKEY arg0, DWORD arg1, LPSTR arg2, PDWORD arg3, PDWORD arg4, PDWORD arg5, LPBYTE arg6, PDWORD arg7)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegEnumValueA", "HKEY", arg0, "DWORD", arg1, "LPSTR", arg2, "PDWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, "LPBYTE", arg6, "PDWORD", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegEnumValueW
(HKEY arg0, DWORD arg1, LPWSTR arg2, PDWORD arg3, PDWORD arg4, PDWORD arg5, LPBYTE arg6, PDWORD arg7)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegEnumValueW", "HKEY", arg0, "DWORD", arg1, "LPWSTR", arg2, "PDWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, "LPBYTE", arg6, "PDWORD", arg7, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegFlushKey(HKEY hKey)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegFlushKey", "HKEY", hKey, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegGetKeySecurity
(HKEY arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2, PDWORD arg3)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegGetKeySecurity", "HKEY", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, "PDWORD", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegLoadKeyA
(HKEY arg0, LPCSTR arg1, LPCSTR arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegLoadKeyA", "HKEY", arg0, "LPCSTR", arg1, "LPCSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegLoadKeyW
(HKEY arg0, LPCWSTR arg1, LPCWSTR arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegLoadKeyW", "HKEY", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegNotifyChangeKeyValue
(HKEY arg0, BOOL arg1, DWORD arg2, HANDLE arg3, BOOL arg4)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegNotifyChangeKeyValue", "HKEY", arg0, "BOOL", arg1, "DWORD", arg2, "HANDLE", arg3, "BOOL", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegOpenKeyA
(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult)
{
	WIN32API_POINTER(lpSubKey);
	WIN32API_POINTER(phkResult);
	WIN32API_ENTER("LONG", "RegOpenKeyA", "HKEY", hKey, "LPCSTR", lpSubKey, "PHKEY", phkResult, NULL);
	WIN32API_INTERNAL_START();
	ULONG rc = RegOpenKeyExA(hKey, lpSubKey, 0, KEY_ALL_ACCESS, phkResult);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegOpenKeyW
(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult)
{
	WIN32API_POINTER(lpSubKey);
	WIN32API_POINTER(phkResult);
	WIN32API_ENTER("LONG", "RegOpenKeyW", "HKEY", hKey, "LPCWSTR", lpSubKey, "PHKEY", phkResult, NULL);
	WIN32API_INTERNAL_START();
	ULONG rc = RegOpenKeyExW(hKey, lpSubKey, 0, KEY_ALL_ACCESS, phkResult);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegOpenKeyExA
(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_POINTER(lpSubKey);
	WIN32API_POINTER(phkResult);
	WIN32API_ENTER("LONG", "RegOpenKeyExA", "HKEY", hKey, "LPCSTR", lpSubKey, "DWORD", ulOptions, "REGSAM", samDesired, "PHKEY", phkResult, NULL);
	Win32String subkey;
	subkey.SetToA(lpSubKey);
	rc = RegOpenKeyExU(hKey, subkey.StringU(), ulOptions, samDesired, phkResult);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegOpenKeyExW
(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_POINTER(lpSubKey);
	WIN32API_POINTER(phkResult);
	WIN32API_ENTER("LONG", "RegOpenKeyExW", "HKEY", hKey, "LPCWSTR", lpSubKey, "DWORD", ulOptions, "REGSAM", samDesired, "PHKEY", phkResult, NULL);
	Win32String subkey;
	subkey.SetToW(lpSubKey);
	rc = RegOpenKeyExU(hKey, subkey.StringU(), ulOptions, samDesired, phkResult);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryInfoKeyA
(HKEY arg0, LPSTR arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4, PDWORD arg5, PDWORD arg6, PDWORD arg7, PDWORD arg8, PDWORD arg9, PDWORD arg10, PFILETIME arg11)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegQueryInfoKeyA", "HKEY", arg0, "LPSTR", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, "PDWORD", arg6, "PDWORD", arg7, "PDWORD", arg8, "PDWORD", arg9, "PDWORD", arg10, "PFILETIME", arg11, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryInfoKeyW
(HKEY arg0, LPWSTR arg1, PDWORD arg2, PDWORD arg3, PDWORD arg4, PDWORD arg5, PDWORD arg6, PDWORD arg7, PDWORD arg8, PDWORD arg9, PDWORD arg10, PFILETIME arg11)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegQueryInfoKeyW", "HKEY", arg0, "LPWSTR", arg1, "PDWORD", arg2, "PDWORD", arg3, "PDWORD", arg4, "PDWORD", arg5, "PDWORD", arg6, "PDWORD", arg7, "PDWORD", arg8, "PDWORD", arg9, "PDWORD", arg10, "PFILETIME", arg11, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryMultipleValuesA
(HKEY arg0, PVALENTA arg1, DWORD arg2, LPSTR arg3, PDWORD arg4)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegQueryMultipleValuesA", "HKEY", arg0, "PVALENTA", arg1, "DWORD", arg2, "LPSTR", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryMultipleValuesW
(HKEY arg0, PVALENTW arg1, DWORD arg2, LPWSTR arg3, PDWORD arg4)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegQueryMultipleValuesW", "HKEY", arg0, "PVALENTW", arg1, "DWORD", arg2, "LPWSTR", arg3, "PDWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryValueA
(HKEY hKey, LPCSTR lpSubKey, LPSTR lpValue, LPLONG lpcbValue)
{
	WIN32API_POINTER(lpSubKey);
	WIN32API_POINTER(lpValue);
	WIN32API_POINTER(lpcbValue);
	if (NULL != lpcbValue) WIN32API_INFO("\tlpcbValue = $%08x\n", *lpcbValue);
	WIN32API_ENTER("LONG", "RegQueryValueA", "HKEY", hKey, "LPCSTR", lpSubKey, "LPSTR", lpValue, "PLONG", lpcbValue, NULL);
	DWORD size;
	WIN32API_INTERNAL_START();
	ULONG rc = RegQueryValueExA(hKey, lpSubKey, NULL, NULL, (LPBYTE)lpValue, &size);
	WIN32API_INTERNAL_END();
	if (ERROR_SUCCESS == rc) *lpcbValue = size;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryValueW
(HKEY hKey, LPCWSTR lpSubKey, LPWSTR lpValue, LPLONG lpcbValue)
{
	WIN32API_POINTER(lpSubKey);
	WIN32API_POINTER(lpValue);
	WIN32API_POINTER(lpcbValue);
	if (NULL != lpcbValue) WIN32API_INFO("\tlpcbValue = $%08x\n", *lpcbValue);
	WIN32API_ENTER("LONG", "RegQueryValueW", "HKEY", hKey, "LPCWSTR", lpSubKey, "LPSTR", lpValue, "PLONG", lpcbValue, NULL);
	DWORD size;
	WIN32API_INTERNAL_START();
	ULONG rc = RegQueryValueExW(hKey, lpSubKey, NULL, NULL, (LPBYTE)lpValue, &size);
	WIN32API_INTERNAL_END();
	if (ERROR_SUCCESS == rc) *lpcbValue = size;
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryValueExA
(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved,
	LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_POINTER(lpValueName);
	WIN32API_POINTER(lpReserved);
	WIN32API_POINTER(lpType);
	WIN32API_POINTER(lpData);
	WIN32API_POINTER(lpcbData);
	WIN32API_ENTER("LONG", "RegQueryValueExA", "HKEY", hKey, "LPCSTR", lpValueName, "LPDWORD", lpReserved, "LPDWORD", lpType, "LPBYTE", lpData, "LPDWORD", lpcbData, NULL);
	if (NULL != lpcbData) WIN32API_INFO("\tlpcbData = $%08x\n", *lpcbData);
	Win32String value;
	value.SetToA(lpValueName);
	DWORD type;
	DWORD size;
	if (NULL == lpcbData) {
		rc = ERROR_BAD_ARGUMENTS;
	} else {
		rc = RegQueryValueExU(hKey, value.StringU(), lpReserved, &type, NULL, &size);
		WIN32API_INFO("\tsize ... %d\n", (B_OK == rc)? (int)size: -1);
		if (ERROR_SUCCESS == rc) {
			char *data = new char[size];
			if (NULL == data) rc = ERROR_NOT_ENOUGH_MEMORY;
			else {
				rc = RegQueryValueExU(hKey, value.StringU(), lpReserved, &type, (LPBYTE)data, &size);
				if (ERROR_SUCCESS == rc) {
					if ((type == REG_SZ) || (type == REG_EXPAND_SZ)) {
						Win32String datastr;
						datastr.SetToU(data);
						if (datastr.LengthA() >= *lpcbData) rc = ERROR_MORE_DATA;
						else if (NULL != lpData) strcpy((char *)lpData, datastr.StringA());
						*lpcbData = datastr.LengthA() + 1;
					} else if (type == REG_MULTI_SZ) {
						BMallocIO multi;
						char *p = data;
						while (0 != *p) {
							Win32String str;
							str.SetToU(p);
							p += strlen(p) + 1;
							multi.Write(str.StringA(), str.LengthA() + 1);
						}
						multi.Write("\0", 1);
						if (multi.BufferLength() > *lpcbData) rc = ERROR_MORE_DATA;
						else if (NULL != lpData) memcpy((char *)lpData, multi.Buffer(), multi.BufferLength());
						*lpcbData = multi.BufferLength();
					} else {
						if (NULL != lpData) memcpy((char *)lpData, data, size);
						*lpcbData = size;
					}
					if (NULL != lpType) *lpType = type;
				}
				delete data;
			}
		}
	}
	WIN32API_ERROR(rc);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegQueryValueExW
(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved,
	LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_POINTER(lpValueName);
	WIN32API_POINTER(lpReserved);
	WIN32API_POINTER(lpType);
	WIN32API_POINTER(lpData);
	WIN32API_POINTER(lpcbData);
	WIN32API_ENTER("LONG", "RegQueryValueExW", "HKEY", hKey, "LPCWSTR", lpValueName, "LPDWORD", lpReserved, "LPDWORD", lpType, "LPBYTE", lpData, "LPDWORD", lpcbData, NULL);
	if (NULL != lpcbData) WIN32API_INFO("\tlpcbData = $%08x\n", *lpcbData);
	Win32String value;
	value.SetToW(lpValueName);
	DWORD type;
	DWORD size;
	if (NULL == lpcbData) {
		rc = ERROR_BAD_ARGUMENTS;
	} else {
		rc = RegQueryValueExU(hKey, value.StringU(), lpReserved, &type, NULL, &size);
		if (ERROR_SUCCESS == rc) {
			char *data = new char[size];
			if (NULL == data) rc = ERROR_NOT_ENOUGH_MEMORY;
			else {
				rc = RegQueryValueExU(hKey, value.StringU(), lpReserved, &type, (LPBYTE)data, &size);
				if (ERROR_SUCCESS == rc) {
					if ((type == REG_SZ) || (type == REG_EXPAND_SZ)) {
						Win32String datastr;
						datastr.SetToU(data);
						if (datastr.LengthW() >= *lpcbData) rc = ERROR_MORE_DATA;
						else if (NULL != lpData) Win32String::strcpyW((short *)lpData, datastr.StringW());
						*lpcbData = datastr.LengthW() + 2;
					} else if (type == REG_MULTI_SZ) {
						BMallocIO multi;
						char *p = data;
						while (0 != *p) {
							Win32String str;
							str.SetToU(p);
							p += strlen(p) + 1;
							multi.Write((char *)str.StringW(), str.LengthW() + 2);
						}
						multi.Write("\0\0", 2);
						if (multi.BufferLength() > *lpcbData) rc = ERROR_MORE_DATA;
						else if (NULL != lpData) memcpy((char *)lpData, multi.Buffer(), multi.BufferLength());
						*lpcbData = multi.BufferLength();
					} else {
						if (NULL != lpData) memcpy((char *)lpData, data, size);
						*lpcbData = size;
					}
					if (NULL != lpType) *lpType = type;
				}
				delete data;
			}
		}
	}
	WIN32API_ERROR(rc);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegReplaceKeyA
(HKEY arg0, LPCSTR arg1, LPCSTR arg2, LPCSTR arg3)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegReplaceKeyA", "HKEY", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "LPCSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegReplaceKeyW
(HKEY arg0, LPCWSTR arg1, LPCWSTR arg2, LPCWSTR arg3)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegReplaceKeyW", "HKEY", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "LPCWSTR", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegRestoreKeyA
(HKEY arg0, LPCSTR arg1, DWORD arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegRestoreKeyA", "HKEY", arg0, "LPCSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegRestoreKeyW
(HKEY arg0, LPCWSTR arg1, DWORD arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegRestoreKeyW", "HKEY", arg0, "LPCWSTR", arg1, "DWORD", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSaveKeyA
(HKEY arg0, LPCSTR arg1, LPSECURITY_ATTRIBUTES arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSaveKeyA", "HKEY", arg0, "LPCSTR", arg1, "LPSECURITY_ATTRIBUTES", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSaveKeyW
(HKEY arg0, LPCWSTR arg1, LPSECURITY_ATTRIBUTES arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSaveKeyW", "HKEY", arg0, "LPCWSTR", arg1, "LPSECURITY_ATTRIBUTES", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSetKeySecurity
(HKEY arg0, SECURITY_INFORMATION arg1, PSECURITY_DESCRIPTOR arg2)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSetKeySecurity", "HKEY", arg0, "SECURITY_INFORMATION", arg1, "PSECURITY_DESCRIPTOR", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSetValueA
(HKEY arg0, LPCSTR arg1, DWORD arg2, LPCSTR arg3, DWORD arg4)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSetValueA", "HKEY", arg0, "LPCSTR", arg1, "DWORD", arg2, "LPCSTR", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSetValueW
(HKEY arg0, LPCWSTR arg1, DWORD arg2, LPCWSTR arg3, DWORD arg4)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSetValueW", "HKEY", arg0, "LPCWSTR", arg1, "DWORD", arg2, "LPCWSTR", arg3, "DWORD", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSetValueExA
(HKEY arg0, LPCSTR arg1, DWORD arg2, DWORD arg3, const BYTE* arg4, DWORD arg5)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSetValueExA", "HKEY", arg0, "LPCSTR", arg1, "DWORD", arg2, "DWORD", arg3, "const BYTE*", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegSetValueExW
(HKEY arg0, LPCWSTR arg1, DWORD arg2, DWORD arg3, const BYTE* arg4, DWORD arg5)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegSetValueExW", "HKEY", arg0, "LPCWSTR", arg1, "DWORD", arg2, "DWORD", arg3, "const BYTE*", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegUnLoadKeyA
(HKEY arg0, LPCSTR arg1)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegUnLoadKeyA", "HKEY", arg0, "LPCSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LONG WINAPI
RegUnLoadKeyW
(HKEY arg0, LPCWSTR arg1)
{
	LONG rc = ERROR_CALL_NOT_IMPLEMENTED;
	WIN32API_ENTER("LONG", "RegUnLoadKeyW", "HKEY", arg0, "LPCWSTR", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
