/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 とよしま
 *  $Id: Resource.cpp,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Resource.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Resource.h"
#include "Module.h"
#include "Locale.h"
#include "Win32Trace.h"
#include "Win32String.h"
#include "Win32Error.h"

Resource::Resource
(void):
magic(RES_MAGIC),
data(NULL),
size(0)
{
}

Resource::~Resource
(void)
{
	if (NULL != data) free(data);
}

bool
Resource::SetTo
(void *base, LpResourceDataEntry entry)
{
	WIN32API_INFO("\tbase: %p\n", base);
	WIN32API_INFO("\tsize: %d\n", entry->Size);
	WIN32API_INFO("\tdata rva: $%08x\n", entry->DataRva);
	if (NULL != data) free(data);
	size = entry->Size;
	data = malloc(size);
	if (NULL == data) return false;
	memcpy(data, (char *)((UINT)base + entry->DataRva), size);
	return true;
}

void *
Resource::Lock
(void) const
{
	return data;
}

DWORD
Resource::Size
(void) const
{
	return size;
}

Resource *
Resource::HandleToResource
(HGLOBAL hResData)
{
	if (NULL == hResData) return NULL;
	Resource *rsrc = (Resource *)hResData;
	if (rsrc->magic != RES_MAGIC) return NULL;
	return rsrc;
}

extern "C" HRSRC WINAPI
FindResourceA
(HMODULE hModule, LPCSTR lpName, LPCSTR lpType)
{
	WIN32API_POINTER(lpName);
	WIN32API_POINTER(lpType);
	WIN32API_ENTER("HRSRC", "FindResourceA", "HMODULE", hModule, "LPCSTR", lpName, "LPCSTR", lpType, NULL);
	WIN32API_INTERNAL_START();
	HRSRC rc = FindResourceExA(hModule, lpName, lpType, (WORD)((1 << 10) | GetSystemDefaultLCID()));
	if (NULL == rc) rc = FindResourceExA(hModule, lpName, lpType, (WORD)-1);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRSRC WINAPI
FindResourceW
(HMODULE hModule, LPCWSTR lpName, LPCWSTR lpType)
{
	WIN32API_POINTER(lpName);
	WIN32API_POINTER(lpType);
	WIN32API_ENTER("HRSRC", "FindResourceW", "HMODULE", hModule, "LPCWSTR", lpName, "LPCWSTR", lpType, NULL);
	WIN32API_INTERNAL_START();
	HRSRC rc = FindResourceExW(hModule, lpName, lpType, (WORD)((1 << 10) | GetSystemDefaultLCID()));
	if (NULL == rc) rc = FindResourceExW(hModule, lpName, lpType, (WORD)-1);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRSRC WINAPI
FindResourceExA
(HMODULE hModule, LPCSTR lpName, LPCSTR lpType, WORD wLanguage)
{
	WIN32API_POINTER(lpName);
	WIN32API_POINTER(lpType);
	WIN32API_ENTER("HRSRC", "FindResourceExA", "HMODULE", hModule, "LPCSTR", lpName, "LPCSTR", lpType, "WORD", wLanguage, NULL);
	LPCWSTR lpNameW = (LPWSTR)lpName;
	Win32String name;
	if (0 != (0xffff0000 & (UINT)lpName)) {
		name.SetToA(lpName);
		lpNameW = name.StringW();
	}
	LPCWSTR lpTypeW = (LPWSTR)lpType;
	Win32String type;
	if (0 != (0xffff0000 & (UINT)lpType)) {
		type.SetToA(lpType);
		lpTypeW = type.StringW();
	}
	WIN32API_INTERNAL_START();
	HRSRC rc = FindResourceExW(hModule, lpNameW, lpTypeW, wLanguage);
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HRSRC WINAPI
FindResourceExW
(HMODULE hModule, LPCWSTR lpName, LPCWSTR lpType, WORD wLanguage)
{
	HRSRC rc = NULL;
	WIN32API_POINTER(lpName);
	WIN32API_POINTER(lpType);
	WIN32API_ENTER("HRSRC", "FindResourceExW", "HMODULE", hModule, "LPCWSTR", lpName, "LPCWSTR", lpType, "WORD", wLanguage, NULL);
#if defined(_DEBUG)
	if (0 == (0xffff0000 & (UINT)lpName)) {
		WIN32API_INFO("\tname: #%d / ", lpName);
	} else {
		Win32String name;
		name.SetToW(lpName);
		WIN32API_INFO("\tname: %s / ", name.StringU());
	}
#endif	// defined(_DEBUG)
	DWORD type = (DWORD)lpType;
	Win32String str;
	LPCWSTR typestr = NULL;
	int typelen = 0;
	if (0 != (0xffff0000 & (UINT)lpType)) {
		str.SetToW((short *)lpType);
		if ('#' == str.StringU()[0]) {
			type = atoi(&(str.StringU()[1]));
			WIN32API_INFO("type: #%d / ", type);
		} else {
			type = (DWORD)-1;
			typestr = str.StringW();
			typelen = str.LengthW();
			WIN32API_INFO("type: %s / ", str.StringU());
		}
	}
	WIN32API_INFO("language: #%d\n", (int)((short)wLanguage));
	Image *image = HandleToImage(hModule);
	if (NULL == image) {
		WIN32API_INFO("\tinvalid handle\n");
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		void *rsrc = image->GetResourceAddress();
		if (NULL == rsrc) {
			WIN32API_INFO("\tthis module don't have resource\n");
			WIN32API_ERROR(ERROR_RESOURCE_DATA_NOT_FOUND);
		} else {
			LpResourceDirectoryTable rdt = (LpResourceDirectoryTable)rsrc;
			LpResourceDirectoryEntry rde = (LpResourceDirectoryEntry)&rdt[1];
			// type id/name
			int i;
			for (i = 0; i < rdt->NumberOfNameEntries; i++) {
				LpResourceDirectoryString rds = (LpResourceDirectoryString)((UINT)rsrc + (rde->NameRva & 0x7fffffff));
#if defined(_DEBUG)
				Win32String str;
				str.SetToW(rds->UnicodeString, rds->Length);
				WIN32API_INFO("\t...type %s\n", str.StringU());
#endif	// defined(_DEBUG)
				if ((NULL != typestr) && (typelen == rds->Length) &&
					(0 == Win32String::strncasecmpW(typestr, rds->UnicodeString, typelen))) {
					WIN32API_INFO("\ttype found\n");
					break;
				}
				rde++;
			}
			if (i == rdt->NumberOfNameEntries) for (i = 0; i < rdt->NumberOfIDEntries; i++) {
				WIN32API_INFO("\t...type %d\n", rde->IntegerId);
				if (rde->IntegerId == type) {
					WIN32API_INFO("\ttype %d found\n", type);
					break;
				}
				rde++;
			}
			if (i == rdt->NumberOfIDEntries) rde = NULL;
			if (NULL == rde) {
				WIN32API_ERROR(ERROR_RESOURCE_TYPE_NOT_FOUND);
			} else {
				rdt = (LpResourceDirectoryTable)((UINT)rsrc + (rde->SubdirectoryRva & 0x7fffffff));
				rde = (LpResourceDirectoryEntry)&rdt[1];
				if (0 == (0xffff0000 & (UINT)lpName)) {
					// name id
					int i;
					for (i = 0; i < rdt->NumberOfNameEntries; i++) rde++;
					for (i = 0; i < rdt->NumberOfIDEntries; i++) {
						WIN32API_INFO("\t...name %d\n", rde->IntegerId);
						if ((0 == (DWORD)lpName) || (rde->IntegerId == (DWORD)lpName)) {
							WIN32API_INFO("\tname %d found\n", (int)lpName);
							break;
						}
						rde++;
					}
					if (i == rdt->NumberOfIDEntries) rde = NULL;
				} else {
					// name name
					int i;
					int namelen = Win32String::strlenW(lpName);
					for (i = 0; i < rdt->NumberOfNameEntries; i++) {
						LpResourceDirectoryString rds = (LpResourceDirectoryString)((UINT)rsrc + (rde->NameRva & 0x7fffffff));
#if defined(_DEBUG)
						Win32String str;
						str.SetToW(rds->UnicodeString, rds->Length);
						WIN32API_INFO("\t...name %s\n", str.StringU());
#endif	// defined(_DEBUG)
						if ((namelen == rds->Length) && (0 == memcmp(lpName, rds->UnicodeString, namelen * 2))) {
							WIN32API_INFO("\tname found\n");
							break;
						}
						rde++;
					}
					if (i == rdt->NumberOfNameEntries) rde = NULL;
				}
				if (NULL == rde) {
					WIN32API_ERROR(ERROR_RESOURCE_NAME_NOT_FOUND);
				} else {
					rdt = (LpResourceDirectoryTable)((UINT)rsrc + (rde->SubdirectoryRva & 0x7fffffff));
					rde = (LpResourceDirectoryEntry)&rdt[1];
					if (0 != rdt->NumberOfNameEntries) {
						WIN32API_INFO("\tname language not supported\n");
						WIN32API_ERROR(ERROR_CALL_NOT_IMPLEMENTED);
						rde = NULL;
					} else {
						int i;
						for (i = 0; i < rdt->NumberOfIDEntries; i++) {
							WIN32API_INFO("\t...lang %d\n", rde->IntegerId);
							if ((WORD)-1 == wLanguage) break;
							if (rde->IntegerId == wLanguage) break;
						}
						if (i == rdt->NumberOfIDEntries) rde = NULL;
						else WIN32API_INFO("\tlanguage %d found\n", rde->IntegerId);
					}
					if (NULL == rde) {
						WIN32API_ERROR(ERROR_RESOURCE_LANG_NOT_FOUND);
					} else {
						rc = (HRSRC)rde->DataEntryRva;
						WIN32API_ERROR(ERROR_SUCCESS);
					}
				}
			}
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HGLOBAL WINAPI
LoadResource
(HMODULE hModule, HRSRC hResInfo)
{
	HGLOBAL rc = NULL;
	WIN32API_ENTER("HGLOBAL", "LoadResource", "HMODULE", hModule, "HRSRC", hResInfo, NULL);
	if (NULL == hModule) {
		WIN32API_INTERNAL_START();
		hModule = GetModuleHandleA(NULL);
		WIN32API_INTERNAL_END();
	}
	Image *image = HandleToImage(hModule);
	if (NULL == image) {
		WIN32API_INFO("\tinvalid handle\n");
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		void *rsrc = image->GetResourceAddress();
		if (NULL == rsrc) {
			WIN32API_INFO("\tthis module don't have resource\n");
			WIN32API_ERROR(ERROR_RESOURCE_DATA_NOT_FOUND);
		} else {
			Resource *resource = new Resource();
			if ((NULL == resource) || !resource->SetTo(hModule, (LpResourceDataEntry)((UINT)rsrc + (UINT)hResInfo))) {
				WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			} else {
				// Win32ではLoadの時点でLockしたアドレスが帰るらしい
				// XXX: Lock/Unlock/Size/Freeの調整が必要
//				rc = (HGLOBAL)resource;
				rc = (HGLOBAL)resource->Lock();
				WIN32API_ERROR(ERROR_SUCCESS);
			}
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
FreeResource
(HGLOBAL hResData)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "FreeResource", "HGLOBAL", hResData, NULL);
	Resource *rsrc = Resource::HandleToResource(hResData);
	if (NULL == rsrc) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		delete rsrc;
		rc = TRUE;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" LPVOID WINAPI
LockResource
(HGLOBAL hResData)
{
	LPVOID rc = NULL;
	WIN32API_ENTER("LPVOID", "LockResource", "HGLOBAL", hResData, NULL);
//	Resource *rsrc = Resource::HandleToResource(hResData);
//	if (NULL == rsrc) {
//		WIN32API_ERROR(ERROR_INVALID_HANDLE);
//	} else {
//		rc = rsrc->Lock();
//		WIN32API_ERROR(ERROR_SUCCESS);
//	}
	rc = (LPVOID)hResData;
	WIN32API_ERROR(ERROR_SUCCESS);
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
SizeofResource
(HMODULE hModule, HRSRC hResInfo)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "SizeofResource", "HMODULE", hModule, "HRSRC", hResInfo, NULL);
	Image *image = HandleToImage(hModule);
	if (NULL == image) {
		WIN32API_INFO("\tinvalid handle\n");
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		void *rsrc = image->GetResourceAddress();
		if (NULL == rsrc) {
			WIN32API_INFO("\tthis module don't have resource\n");
			WIN32API_ERROR(ERROR_RESOURCE_DATA_NOT_FOUND);
		} else {
			LpResourceDataEntry rde = (LpResourceDataEntry)((UINT)rsrc + (UINT)hResInfo);
			rc = rde->Size;
			WIN32API_ERROR(ERROR_SUCCESS);
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumResourceLanguagesA
(HINSTANCE arg0, LPCSTR arg1, LPCSTR arg2, ENUMRESLANGPROCA arg3, LONG arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumResourceLanguagesA", "HINSTANCE", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "ENUMRESLANGPROC", arg3, "LONG", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumResourceLanguagesW
(HINSTANCE arg0, LPCWSTR arg1, LPCWSTR arg2, ENUMRESLANGPROCW arg3, LONG arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumResourceLanguagesW", "HINSTANCE", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "ENUMRESLANGPROC", arg3, "LONG", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumResourceNamesA
(HINSTANCE arg0, LPCSTR arg1, ENUMRESNAMEPROCA arg2, LONG arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumResourceNamesA", "HINSTANCE", arg0, "LPCSTR", arg1, "ENUMRESNAMEPROC", arg2, "LONG", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumResourceNamesW
(HINSTANCE arg0, LPCWSTR arg1, ENUMRESNAMEPROCW arg2, LONG arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumResourceNamesW", "HINSTANCE", arg0, "LPCWSTR", arg1, "ENUMRESNAMEPROC", arg2, "LONG", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumResourceTypesA
(HINSTANCE arg0, ENUMRESTYPEPROCA arg1, LONG arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumResourceTypesA", "HINSTANCE", arg0, "ENUMRESTYPEPROC", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnumResourceTypesW
(HINSTANCE arg0, ENUMRESTYPEPROCW arg1, LONG arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnumResourceTypesW", "HINSTANCE", arg0, "ENUMRESTYPEPROC", arg1, "LONG", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
BeginUpdateResourceA
(LPCSTR arg0, BOOL arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "BeginUpdateResourceA", "LPCSTR", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HANDLE WINAPI
BeginUpdateResourceW
(LPCWSTR arg0, BOOL arg1)
{
	HANDLE rc = INVALID_HANDLE_VALUE;
	WIN32API_ENTER("HANDLE", "BeginUpdateResourceW", "LPCWSTR", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EndUpdateResourceA
(HANDLE arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EndUpdateResourceA", "HANDLE", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EndUpdateResourceW
(HANDLE arg0, BOOL arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EndUpdateResourceW", "HANDLE", arg0, "BOOL", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UpdateResourceA
(HANDLE arg0, LPCSTR arg1, LPCSTR arg2, WORD arg3, PVOID arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UpdateResourceA", "HANDLE", arg0, "LPCSTR", arg1, "LPCSTR", arg2, "WORD", arg3, "PVOID", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
UpdateResourceW
(HANDLE arg0, LPCWSTR arg1, LPCWSTR arg2, WORD arg3, PVOID arg4, DWORD arg5)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "UpdateResourceW", "HANDLE", arg0, "LPCWSTR", arg1, "LPCWSTR", arg2, "WORD", arg3, "PVOID", arg4, "DWORD", arg5, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
