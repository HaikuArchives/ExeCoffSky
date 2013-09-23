/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000, 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32FontStructures.h,v 1.1 2003/05/01 02:43:55 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32FontStructures.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Win32FontStructures_h__)
#	define	__Win32FontStructures_h__

#	if defined(__cplusplus)
#		if !defined(__Common_h__)
#			include "Common.h"
#		endif	// !defined(__Common_h__)
#	endif	// defined(__cplusplus)

#	define	LF_FACESIZE		32
#	define	LF_FULLFACESIZE	64

typedef struct tagFONTSIGNATURE {
} FONTSIGNATURE, *LPFONTSIGNATURE;

typedef struct tagLOGFONTA {
	PACKED(LONG lfHeight);
	PACKED(LONG lfWidth);
	PACKED(LONG lfEscapement);
	PACKED(LONG lfPOrientation);
	PACKED(LONG lfWeight);
	PACKED(BYTE lfItalic);
	PACKED(BYTE lfUnderline);
	PACKED(BYTE lfStrikeOut);
	PACKED(BYTE lfCharSet);
	PACKED(BYTE lfOutPrecision);
	PACKED(BYTE lfClipPrecision);
	PACKED(BYTE lfQuality);
	PACKED(BYTE lfPitchAndFamily);
	PACKED(CHAR lfFaceName[LF_FACESIZE]);
} LOGFONTA, *PLOGFONTA, *LPLOGFONTA;

typedef struct tagLOGFONTW {
	PACKED(LONG lfHeight);
	PACKED(LONG lfWidth);
	PACKED(LONG lfEscapement);
	PACKED(LONG lfPOrientation);
	PACKED(LONG lfWeight);
	PACKED(BYTE lfItalic);
	PACKED(BYTE lfUnderline);
	PACKED(BYTE lfStrikeOut);
	PACKED(BYTE lfCharSet);
	PACKED(BYTE lfOutPrecision);
	PACKED(BYTE lfClipPrecision);
	PACKED(BYTE lfQuality);
	PACKED(BYTE lfPitchAndFamily);
	PACKED(WCHAR lfFaceName[LF_FACESIZE]);
} LOGFONTW, *PLOGFONTW, *LPLOGFONTW;

typedef struct tagENUMLOGFONTA {
	PACKED(LOGFONTA elfLogFont);
	PACKED(CHAR elfFullName[LF_FULLFACESIZE]);
	PACKED(CHAR elfStyle[LF_FACESIZE]);
} ENUMLOGFONTA, *LPENUMLOGFONTA;

typedef struct tagENUMLOGFONTW {
	PACKED(LOGFONTW elfLogFont);
	PACKED(WCHAR elfFullName[LF_FULLFACESIZE]);
	PACKED(WCHAR elfStyle[LF_FACESIZE]);
} ENUMLOGFONTW, *LPENUMLOGFONTW;

typedef struct tagTEXTMETRICA {
	PACKED(LONG tmHeight);
	PACKED(LONG tmAscent);
	PACKED(LONG tmDescent);
	PACKED(LONG tmInternalLeading);
	PACKED(LONG tmExternalLeading);
	PACKED(LONG tmAveCharWidth);
	PACKED(LONG tmMaxCharWidth);
	PACKED(LONG tmWeight);
	PACKED(LONG tmOverhang);
	PACKED(LONG tmDigitizedAspectX);
	PACKED(LONG tmDigitizedAspectY);
	PACKED(CHAR tmFirstChar);
	PACKED(CHAR tmLastChar);
	PACKED(CHAR tmDefaultChar);
	PACKED(CHAR tmBreakChar);
	PACKED(BYTE tmItalic);
	PACKED(BYTE tmUnderlined);
	PACKED(BYTE tmStruckOut);
	PACKED(BYTE tmPitchAndFamily);
	PACKED(BYTE tmCharSet);
} TEXTMETRICA, *LPTEXTMETRICA;

typedef struct tagTEXTMETRICW {
	PACKED(LONG tmHeight);
	PACKED(LONG tmAscent);
	PACKED(LONG tmDescent);
	PACKED(LONG tmInternalLeading);
	PACKED(LONG tmExternalLeading);
	PACKED(LONG tmAveCharWidth);
	PACKED(LONG tmMaxCharWidth);
	PACKED(LONG tmWeight);
	PACKED(LONG tmOverhang);
	PACKED(LONG tmDigitizedAspectX);
	PACKED(LONG tmDigitizedAspectY);
	PACKED(WCHAR tmFirstChar);
	PACKED(WCHAR tmLastChar);
	PACKED(WCHAR tmDefaultChar);
	PACKED(WCHAR tmBreakChar);
	PACKED(BYTE tmItalic);
	PACKED(BYTE tmUnderlined);
	PACKED(BYTE tmStruckOut);
	PACKED(BYTE tmPitchAndFamily);
	PACKED(BYTE tmCharSet);
} TEXTMETRICW, *LPTEXTMETRICW;

typedef struct tagNEWTEXTMETRICA {
	PACKED(LONG tmHeight);
	PACKED(LONG tmAscent);
	PACKED(LONG tmDescent);
	PACKED(LONG tmInternalLeading);
	PACKED(LONG tmExternalLeading);
	PACKED(LONG tmAveCharWidth);
	PACKED(LONG tmMaxCharWidth);
	PACKED(LONG tmWeight);
	PACKED(LONG tmOverhang);
	PACKED(LONG tmDigitizedAspectX);
	PACKED(LONG tmDigitizedAspectY);
	PACKED(CHAR tmFirstChar);
	PACKED(CHAR tmLastChar);
	PACKED(CHAR tmDefaultChar);
	PACKED(CHAR tmBreakChar);
	PACKED(BYTE tmItalic);
	PACKED(BYTE tmUnderlined);
	PACKED(BYTE tmStruckOut);
	PACKED(BYTE tmPitchAndFamily);
	PACKED(BYTE tmCharSet);

	PACKED(DWORD ntmFlags);
	PACKED(UINT ntmSizeEM);
	PACKED(UINT ntmCellHeight);
	PACKED(UINT ntmAvgWidth);
} NEWTEXTMETRICA, *LPNEWTEXTMETRICA;

typedef struct tagNEWTEXTMETRICW {
	PACKED(LONG tmHeight);
	PACKED(LONG tmAscent);
	PACKED(LONG tmDescent);
	PACKED(LONG tmInternalLeading);
	PACKED(LONG tmExternalLeading);
	PACKED(LONG tmAveCharWidth);
	PACKED(LONG tmMaxCharWidth);
	PACKED(LONG tmWeight);
	PACKED(LONG tmOverhang);
	PACKED(LONG tmDigitizedAspectX);
	PACKED(LONG tmDigitizedAspectY);
	PACKED(WCHAR tmFirstChar);
	PACKED(WCHAR tmLastChar);
	PACKED(WCHAR tmDefaultChar);
	PACKED(WCHAR tmBreakChar);
	PACKED(BYTE tmItalic);
	PACKED(BYTE tmUnderlined);
	PACKED(BYTE tmStruckOut);
	PACKED(BYTE tmPitchAndFamily);
	PACKED(BYTE tmCharSet);

	PACKED(DWORD ntmFlags);
	PACKED(UINT ntmSizeEM);
	PACKED(UINT ntmCellHeight);
	PACKED(UINT ntmAvgWidth);
} NEWTEXTMETRICW, *LPNEWTEXTMETRICW;

#	if defined(UNICODE)
typedef ENUMLOGFONTA		ENUMLOGFONT, *LPENUMLOGFONT;
typedef LOGFONTA			LOGFONT, *LPLOGFONT;
typedef TEXTMETRICA			TEXTMETRIC, *LPTEXTMETRIC;
typedef NEWTEXTMETRICA		NEWTEXTMETRIC, *LPNEWTEXTMETRIC;
#	else	// defined(UNICODE)
typedef ENUMLOGFONTW		ENUMLOGFONT, *LPENUMLOGFONT;
typedef LOGFONTW			LOGFONT, *LPLOGFONT;
typedef TEXTMETRICW			TEXTMETRIC, *LPTEXTMETRIC;
typedef NEWTEXTMETRICW		NEWTEXTMETRIC, *LPNEWTEXTMETRIC;
#	endif	// defined(UNICODE)

typedef int CALLBACK (*FONTENUMPROCA)(LPENUMLOGFONTA lpelf, LPNEWTEXTMETRICA lpntm, int FontType, LPARAM lParam);
typedef int CALLBACK (*FONTENUMPROCW)(LPENUMLOGFONTW lpelf, LPNEWTEXTMETRICW lpntm, int FontType, LPARAM lParam);



#endif	// !defined(__Win32FontStructures_h__)
