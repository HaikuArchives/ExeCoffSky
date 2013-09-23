/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Resource.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Resource.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Resource_h__)
#	define	__Resource_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__ResourceTable_h__)
#		include "ResourceTable.h"
#	endif	// !defined(__ResourceTable_h__)

typedef BOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE, LPSTR, LONG);
typedef BOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE, LPCSTR, LPSTR, LONG);
typedef BOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE, LPCSTR, LPCSTR, WORD, LONG);
typedef BOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE, LPWSTR, LONG);
typedef BOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE, LPCWSTR, LPWSTR, LONG);
typedef BOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE, LPCWSTR, LPCWSTR, WORD, LONG);

#	define	MAKEINTRESOURCEA(i)	(LPSTR)((DWORD)((WORD)(i)))
#	define	MAKEINTRESOURCEW(i)	(LPWSTR)((DWORD)((WORD)(i)))
#	if defined(UNICODE)
#		define	MAKEINTRESOURCE	MAKEINTRESOURCEW
#	else	// defined(UNICODE)
#		define	MAKEINTRESOURCE	MAKEINTRESOURCEA
#	endif	// defined(UNICODE)

#	define	RT_CURSOR		MAKEINTRESOURCE(1)
#	define	RT_BITMAP		MAKEINTRESOURCE(2)
#	define	RT_ICON			MAKEINTRESOURCE(3)
#	define	RT_MENU			MAKEINTRESOURCE(4)
#	define	RT_DIALOG		MAKEINTRESOURCE(5)
#	define	RT_STRING		MAKEINTRESOURCE(6)
#	define	RT_FONTDIR		MAKEINTRESOURCE(7)
#	define	RT_FONT			MAKEINTRESOURCE(8)
#	define	RT_ACCELERATOR	MAKEINTRESOURCE(9)
#	define	RT_RCDATA		MAKEINTRESOURCE(10)
#	define	RT_MESSAGETABKE	MAKEINTRESOURCE(11)

#	define	DIFFERENCE		11

#	define	RT_GROUP_CURSOR	MAKEINTRESOURCE((DWORD)RT_CURSOR + DIFFERENCE)
#	define	RT_GROUP_ICON	MAKEINTRESOURCE((DWORD)RT_ICON + DIFFERENCE)

#	define	RT_VERSION		MAKEINTRESOURCE(16)
#	define	RT_DLGINCLUDE	MAKEINTRESOURCE(17)
#	define	RT_PLUGPLAY		MAKEINTRESOURCE(19)
#	define	RT_VXD			MAKEINTRESOURCE(20)
#	define	RT_ANICURSOR	MAKEINTRESOURCE(21)
#	define	RT_ANIICON		MAKEINTRESOURCE(22)
#	define	RT_HTML			MAKEINTRESOURCE(23)

#	define	RES_MAGIC		'_RES'
#	define	RES_DATA_MAGIC	'_RDt'

class Resource {
public:
	DWORD magic;
private:
	void *data;
	int size;
public:
	Resource(void);
	~Resource(void);
	bool SetTo(void *base, LpResourceDataEntry entry);
	void *Lock(void) const;
	DWORD Size(void) const;
	
	static Resource *HandleToResource(HGLOBAL hResData);
};

#	if !defined(__Resource__)
#		define	__Resource__
#	endif	// !defined(__Resource__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HRSRC WINAPI FindResourceA(HMODULE hModule, LPCSTR lpName, LPCSTR lpType);
HRSRC WINAPI FindResourceW(HMODULE hModule, LPCWSTR lpName, LPCWSTR lpType);
HRSRC WINAPI FindResourceExA(HMODULE hModule, LPCSTR lpName, LPCSTR lpType, WORD wLanguage);
HRSRC WINAPI FindResourceExW(HMODULE hModule, LPCWSTR lpName, LPCWSTR lpType, WORD wLanguage);

HGLOBAL WINAPI LoadResource(HMODULE hModule, HRSRC hResInfo);
BOOL WINAPI FreeResource(HGLOBAL hResData);
LPVOID WINAPI LockResource(HGLOBAL hResData);
DWORD WINAPI SizeofResource(HMODULE hModule, HRSRC hResInfo);

BOOL WINAPI EnumResourceLanguagesA(HINSTANCE,LPCSTR,LPCSTR,ENUMRESLANGPROCA,LONG);
BOOL WINAPI EnumResourceLanguagesW(HINSTANCE,LPCWSTR,LPCWSTR,ENUMRESLANGPROCW,LONG);
BOOL WINAPI EnumResourceNamesA(HINSTANCE,LPCSTR,ENUMRESNAMEPROCA,LONG);
BOOL WINAPI EnumResourceNamesW(HINSTANCE,LPCWSTR,ENUMRESNAMEPROCW,LONG);
BOOL WINAPI EnumResourceTypesA(HINSTANCE,ENUMRESTYPEPROCA,LONG);
BOOL WINAPI EnumResourceTypesW(HINSTANCE,ENUMRESTYPEPROCW,LONG);

HANDLE WINAPI BeginUpdateResourceA(LPCSTR,BOOL);
HANDLE WINAPI BeginUpdateResourceW(LPCWSTR,BOOL);
BOOL WINAPI EndUpdateResourceA(HANDLE,BOOL);
BOOL WINAPI EndUpdateResourceW(HANDLE,BOOL);
BOOL WINAPI UpdateResourceA(HANDLE,LPCSTR,LPCSTR,WORD,PVOID,DWORD);
BOOL WINAPI UpdateResourceW(HANDLE,LPCWSTR,LPCWSTR,WORD,PVOID,DWORD);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Resource_h__)
