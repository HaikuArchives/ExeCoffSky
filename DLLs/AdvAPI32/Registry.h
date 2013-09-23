/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Registry.h,v 1.1 2003/05/01 02:42:42 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Registry.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Registry_h__)
#	define __Registry_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	define	HKEY_CLASSES_ROOT				((HKEY)0x80000000)
#	define	HKEY_CURRENT_USER				((HKEY)0x80000001)
#	define	HKEY_LOCAL_MACHINE				((HKEY)0x80000002)
#	define	HKEY_USERS						((HKEY)0x80000003)
#	define	HKEY_PERFORMANCE_DATA			((HKEY)0x80000004)
#	define	HKEY_CURRENT_CONFIG				((HKEY)0x80000005)
#	define	HKEY_DYN_DATA					((HKEY)0x80000006)

#	define	DELETE							(0x00010000L)
#	define	READ_CONTROL					(0x00020000L)
#	define	WRITE_DAC						(0x00040000L)
#	define	WRITE_OWNER						(0x00080000L)
#	define	SYNCHRONIZE						(0x00100000L)

#	define	STANDARD_RIGHTS_REQUIRED		(0x000f0000L)
#	define	STANDARD_RIGHTS_READ			(READ_CONTROL)
#	define	STANDARD_RIGHTS_WRITE			(READ_CONTROL)
#	define	STANDARD_RIGHTS_EXECUTE			(READ_CONTROL)
#	define	STANDARD_RIGHTS_ALL				(0x001f0000L)
#	define	SPECIFIC_RIGHTS_ALL				(0x0000ffffL)

#	define	KEY_QUERY_VALUE					(0x0001)
#	define	KEY_SET_VALUE					(0x0002)
#	define	KEY_CREATE_SUB_KEY				(0x0004)
#	define	KEY_ENUMRATE_SUB_KEYS			(0x0008)
#	define	KEY_NOTIFY						(0x0010)
#	define	KEY_CREATE_LINK					(0x0020)

#	define	KEY_READ						((STANDARD_RIGHTS_READ | KEY_QUERY_VALUE | KEY_ENUMRATE_SUB_KEYS | KEY_NOTIFY) & ~SYNCHRONIZE)
#	define	KEY_WRITE						((STANDARD_RIGHTS_WRITE | KEY_SET_VALUE | KEY_CREATE_SUB_KEYS) & ~SYNCHRONIZE)
#	define	KEY_EXECUTE						(KEY_READ & ~SYNCHRONIZE)
#	define	KEY_ALL_ACCESS					((STANDARD_RIGHTS_ALL | KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY | KEY_ENUMRATE_SUB_KEYS | KEY_NOTIFY) & ~SYNCHRONIZE)

#	define	REG_NONE						0
#	define	REG_SZ							1
#	define	REG_EXPAND_SZ					2
#	define	REG_BINARY						3
#	define	REG_DWORD						4
#	define	REG_DWORD_LITTLE_ENDIAN			4
#	define	REG_DWORD_BIG_ENDIAN			5
#	define	REG_LINK						6
#	define	REG_MULTI_SZ					7
#	define	REG_RESOURCE_LIST				8
#	define	REG_FULL_RESOURCE_DESCRIPTOR	9
#	define	REG_RESOURCE_REQUIREMENTS_LIST	10

#	define	REGISTRY_MAGIC					'_REG'

class Registry {
public:
	DWORD magic;
	static char *syskeys[];
private:
	char *keypath;
	size_t keypathlen;
	REGSAM sam;
public:
	Registry(REGSAM sam);
	Registry(const Registry &src);
	~Registry(void);

	ULONG Open(HKEY hKey, LPCSTR lpSubKey);
	ULONG Query(LPCSTR lpValueName, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);

	void SetSam(REGSAM);
	REGSAM GetSam(void) const;
	LPCSTR GetPath(void) const;
	
	static Registry *HandleToRegistry(HKEY hKey);
};

#	if !defined(__Registry__)
#		define	__Registry__
#	endif	// !defined(__Registry__)

static LONG RegOpenKeyExU(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
static LONG RegQueryValueExU(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved,
	LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

LONG WINAPI RegCloseKey(HKEY hKey);
LONG WINAPI RegConnectRegistryA(LPSTR lpMachineName, HKEY hKey, PHKEY phkResult);
LONG WINAPI RegConnectRegistryW(LPWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
LONG WINAPI RegCreateKeyA(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
LONG WINAPI RegCreateKeyW(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
LONG WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass,
	DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	PHKEY phkResult, LPDWORD lpdwDisposition);
LONG WINAPI RegCreateKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass,
	DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	PHKEY phkResult, LPDWORD lpdwDisposition);
LONG WINAPI RegDeleteKeyA(HKEY hKey, LPCSTR lpSubKey);
LONG WINAPI RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey);
LONG WINAPI RegDeleteValueA(HKEY hKey, LPCSTR lpValueName);
LONG WINAPI RegDeleteValueW(HKEY hKey, LPCWSTR lpValueName);
LONG WINAPI RegEnumKeyA(HKEY hKey, DWORD dwIndex, LPSTR lpName, DWORD cbName);
LONG WINAPI RegEnumKeyW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, DWORD cbName);
LONG WINAPI RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcbName,
	LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcbClass, PFILETIME lpftLastWriteTime);
LONG WINAPI RegEnumKeyExW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcbName,
	LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcbClass, PFILETIME lpftLastWriteTime);
LONG WINAPI RegEnumValueA(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, 
	LPDWORD lpcbValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG WINAPI RegEnumValueW(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName,
	LPDWORD lpcbValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG WINAPI RegFlushKey(HKEY hKey);
LONG WINAPI RegGetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation,
	PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor);
LONG WINAPI RegLoadKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile);
LONG WINAPI RegLoadKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile);
LONG WINAPI RegNotifyChangeKeyValue(HKEY hKey, BOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, BOOL fAsyncronus);
LONG WINAPI RegOpenKeyA(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
LONG WINAPI RegOpenKeyW(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
LONG WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LONG WINAPI RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LONG WINAPI RegQueryInfoKeyA(HKEY hKey, LPSTR lpClass, LPDWORD lpcbClass, LPDWORD lpReserved,
	LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues,
	LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, PFILETIME lpftLastWriteTime);
LONG WINAPI RegQueryInfoKeyW(HKEY hKey, LPWSTR lpClass, LPDWORD lpcbClass, LPDWORD lpReserved,
	LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues,
	LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, PFILETIME lpftLastWriteTime);
LONG WINAPI RegQueryMultipleValuesA(HKEY hKey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize);
LONG WINAPI RegQueryMultipleValuesW(HKEY hKey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize);
LONG WINAPI RegQueryValueA(HKEY hKey, LPCSTR lpSubKey, LPSTR lpValue, PLONG lpcbValue);
LONG WINAPI RegQueryValueW(HKEY hKey, LPCWSTR lpSubKey, LPWSTR lpValue, PLONG lpcbValue);
LONG WINAPI RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved,
	LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG WINAPI RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved,
	LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LONG WINAPI RegReplaceKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);
LONG WINAPI RegReplaceKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
LONG WINAPI RegRestoreKeyA(HKEY hKey, LPCSTR lpFile, DWORD dwFlags);
LONG WINAPI RegRestoreKeyW(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags);
LONG WINAPI RegSaveKeyA(HKEY hKey, LPCSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
LONG WINAPI RegSaveKeyW(HKEY hKey, LPCWSTR lpFile, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
LONG WINAPI RegSetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);
LONG WINAPI RegSetValueA(HKEY hKey, LPCSTR lpSubKey, DWORD dwType, LPCSTR lpData, DWORD cbData);
LONG WINAPI RegSetValueW(HKEY hKey, LPCWSTR lpSubKey, DWORD dwType, LPCWSTR lpData, DWORD cbData);
LONG WINAPI RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE *lpData, DWORD cbData);
LONG WINAPI RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData);
LONG WINAPI RegUnLoadKeyA(HKEY hKey, LPCSTR lpSubKey);
LONG WINAPI RegUnLoadKeyW(HKEY hKey, LPCWSTR lpSubKey);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Registry_h__)
