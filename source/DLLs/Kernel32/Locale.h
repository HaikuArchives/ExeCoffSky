/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Locale.h,v 1.1 2003/05/01 02:57:17 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Locale.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Locale_h__)
#	define	__Locale_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

typedef struct tagCURRENCYFMTA {
	PACKED(UINT NumDigits);
	PACKED(UINT LeadingZero);
	PACKED(UINT Grouping);
	PACKED(LPSTR lpDecimalSep);
	PACKED(LPSTR lpThousandSep);
	PACKED(UINT NegativeOrder);
	PACKED(UINT PositiveOrder);
	PACKED(LPSTR lpCurrencySymbol);
} CURRENCYFMTA, *LPCURRENCYFMTA;

typedef struct tagCURRENCYFMTW {
	PACKED(UINT NumDigits);
	PACKED(UINT LeadingZero);
	PACKED(UINT Grouping);
	PACKED(LPWSTR lpDecimalSep);
	PACKED(LPWSTR lpThousandSep);
	PACKED(UINT NegativeOrder);
	PACKED(UINT PositiveOrder);
	PACKED(LPWSTR lpCurrencySymbol);
} CURRENCYFMTW, *LPCURRENCYFMTW;

typedef struct tagNUMBERFMTA {
	PACKED(UINT NumDigits);
	PACKED(UINT LeadingZero);
	PACKED(UINT Grouping);
	PACKED(LPSTR lpDecimalSep);
	PACKED(LPSTR lpThousandSep);
	PACKED(UINT NegativeOrder);
} NUMBERFMTA, *LPNUMBERFMTA;

typedef struct tagNUMBERFMTW {
	PACKED(UINT NumDigits);
	PACKED(UINT LeadingZero);
	PACKED(UINT Grouping);
	PACKED(LPWSTR lpDecimalSep);
	PACKED(LPWSTR lpThousandSep);
	PACKED(UINT NegativeOrder);
} NUMBERFMTW, *LPNUMBERFMTW;

typedef BOOL (CALLBACK *CALINFO_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *CALINFO_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *CALINFO_ENUMPROCEXA)(LPSTR, CALID);
typedef BOOL (CALLBACK *CALINFO_ENUMPROCEXW)(LPWSTR, CALID);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCEXA)(LPSTR, CALID);
typedef BOOL (CALLBACK *DATEFMT_ENUMPROCEXW)(LPWSTR, CALID);
typedef BOOL (CALLBACK *TIMEFMT_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *TIMEFMT_ENUMPROCW)(LPWSTR);
typedef BOOL (CALLBACK *LOCALE_ENUMPROCA)(LPSTR);
typedef BOOL (CALLBACK *LOCALE_ENUMPROCW)(LPWSTR);

int WINAPI CompareStringA(LCID Locale, DWORD dwCmpFlags, LPCSTR lpString1, int cchCount1, LPCSTR lpString2, int cchCount2);
int WINAPI CompareStringW(LCID Locale, DWORD dwCmpFlags, LPCWSTR lpString1, int cchCount1, LPCWSTR lpString2, int cchCount2);
LCID WINAPI ConvertDefaultLocale(LCID Locale);
BOOL WINAPI EnumCalendarInfoA(CALINFO_ENUMPROCA lpCalInfoEnumProc, LCID Locale, CALID Calendar, CALTYPE CalType);
BOOL WINAPI EnumCalendarInfoW(CALINFO_ENUMPROCW lpCalInfoEnumProc, LCID Locale, CALID Calendar, CALTYPE CalType);
BOOL WINAPI EnumCalendarInfoExA(CALINFO_ENUMPROCEXA lpCalInfoEnumProcEx, LCID Locale, CALID Calendar, CALTYPE CalType);
BOOL WINAPI EnumCalendarInfoExW(CALINFO_ENUMPROCEXW lpCalInfoEnumProcEx, LCID Locale, CALID Calendar, CALTYPE CalType);
BOOL WINAPI EnumDateFormatsA(DATEFMT_ENUMPROCA lpDateFmtEnumProc, LCID Locale, DWORD dwFlags);
BOOL WINAPI EnumDateFormatsW(DATEFMT_ENUMPROCW lpDateFmtEnumProc, LCID Locale, DWORD dwFlags);
BOOL WINAPI EnumDateFormatsExA(DATEFMT_ENUMPROCEXA lpDateFmtEnumProcEx, LCID Locale, DWORD dwFlags);
BOOL WINAPI EnumDateFormatsExW(DATEFMT_ENUMPROCEXW lpDateFmtEnumProcEx, LCID Locale, DWORD dwFlags);
BOOL WINAPI EnumSystemLocalesA(LOCALE_ENUMPROCA lpLocaleEnumProc, DWORD dwFlags);
BOOL WINAPI EnumSystemLocalesW(LOCALE_ENUMPROCW lpLocaleEnumProc, DWORD dwFlags);
BOOL WINAPI EnumTimeFormatsA(TIMEFMT_ENUMPROCA lpTimeFmtEnumProc, LCID Locale, DWORD dwFlags);
BOOL WINAPI EnumTimeFormatsW(TIMEFMT_ENUMPROCW lpTimeFmtEnumProc, LCID Locale, DWORD dwFlags);
int WINAPI GetCurrencyFormatA(LCID Locale, DWORD dwFlags, LPCSTR lpValue, const CURRENCYFMTA* lpFormat, LPSTR lpCurrencyStr, int cchCurrency);
int WINAPI GetCurrencyFormatW(LCID Locale, DWORD dwFlags, LPCWSTR lpValue, const CURRENCYFMTW* lpFormat, LPWSTR lpCurrencyStr, int cchCurrency);
int WINAPI GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCSTR lpFormat, LPSTR lpDateStr, int cchDate);
int WINAPI GetDateFormatW(LCID Locale, DWORD dwFlags, const SYSTEMTIME *lpDate, LPCWSTR lpFormat, LPWSTR lpDateStr, int cchDate);
int WINAPI GetLocaleInfoA(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData);
int WINAPI GetLocaleInfoW(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData);
int WINAPI GetNumberFormatA(LCID Locale, DWORD dwFlags, LPCSTR lpValue, const NUMBERFMTA *lpFormat, LPSTR lpNumberStr, int cchNumber);
int WINAPI GetNumberFormatW(LCID Locale, DWORD dwFlags, LPCWSTR lpValue, const NUMBERFMTW *lpFormat, LPWSTR lpNumberStr, int cchNumber);
BOOL WINAPI GetStringTypeA(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
BOOL WINAPI GetStringTypeW(DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
BOOL WINAPI GetStringTypeExA(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
BOOL WINAPI GetStringTypeExW(LCID Locale, DWORD dwInfoType, LPCWSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
LCID WINAPI GetSystemDefaultLCID(void);
LANGID WINAPI GetSystemDefaultLangID(void);
LCID WINAPI GetUserDefaultLCID(void);
LANGID WINAPI GetUserDefaultLangID(void);
int WINAPI GetTimeFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, int cchTime);
int WINAPI GetTimeFormatW(LCID Locale, DWORD dwFlags, const SYSTEMTIME* lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, int cchTime);
BOOL WINAPI IsValidLocale(LCID Locale, DWORD dwFlags);
int WINAPI LCMapStringA(LCID Locale, DWORD dwMapFlags, LPCTSTR lpSrcStr, int cchSrc, LPTSTR lpDestStr, int cchDest);
int WINAPI LCMapStringW(LCID Locale, DWORD dwMapFlags, LPCTSTR lpSrcStr, int cchSrc, LPTSTR lpDestStr, int cchDest);
BOOL WINAPI SetLocaleInfoA(LCID Locale, LCTYPE LCType, LPCSTR lpLCData);
BOOL WINAPI SetLocaleInfoW(LCID Locale, LCTYPE LCType, LPCWSTR lpLCData);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Locale_h__)
