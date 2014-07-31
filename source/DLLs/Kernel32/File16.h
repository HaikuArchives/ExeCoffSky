/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: File16.h,v 1.1 2003/05/01 02:57:16 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [File16.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__File16_h__)
#	define	__File16_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	OF_READ								0x00000000
#	define	OF_WRITE							0x00000001
#	define	OF_READWRITE						0x00000002
#	define	OF_SHARE_COMPAT						0x00000000
#	define	OF_SHARE_EXCLUSIVE					0x00000010
#	define	OF_SHARE_DENY_WRITE					0x00000020
#	define	OF_SHARE_DENY_READ					0x00000030
#	define	OF_SHARE_DENY_NONE					0x00000040
#	define	OF_PARSE							0x00000100
#	define	OF_DELETE							0x00000200
#	define	OF_VERIFY							0x00000400
#	define	OF_CANCAL							0x00000800
#	define	OF_CREATE							0x00001000
#	define	OF_PROMPT							0x00002000
#	define	OF_EXIST							0x00004000
#	define	OF_REOPEN							0x00008000
#	define	FILE_ATTRIBUTE_READONLY				0x00000001
#	define	FILE_ATTRIBUTE_HIDDEN				0x00000002
#	define	FILE_ATTRIBUTE_SYSTEM				0x00000004
#	define	FILE_ATTRIBUTE_DIRECTORY			0x00000010
#	define	FILE_ATTRIBUTE_ARCHIVE				0x00000020
#	define	FILE_ATTRIBUTE_ENCRYPTED			0x00000040
#	define	FILE_ATTRIBUTE_NORMAL				0x00000080
#	define	FILE_ATTRIBUTE_TEMPORARY			0x00000100
#	define	FILE_ATTRIBUTE_SPARSE_FILE			0x00000200
#	define	FILE_ATTRIBUTE_REPARSE_POINT		0x00000400
#	define	FILE_ATTRIBUTE_COMPRESSED			0x00000800
#	define	FILE_ATTRIBUTE_OFFLINE				0x00001000
#	define	FILE_ATTRIBUTE_NOT_CONTENT_INDEXED	0x00002000

#	define	OFS_MAXPATHNAME						128
#	define	HFILE_ERROR							(HFILE)-1

typedef struct tagOFSTRUCT {
	PACKED(BYTE cBytes);
	PACKED(BYTE fFixedDisk);
	PACKED(WORD nErrCode);
	PACKED(WORD Reserved1);
	PACKED(WORD Reserved2);
	PACKED(BYTE szPathName[OFS_MAXPATHNAME]);
} OFSTRUCT, *LPOFSTRUCT;

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HFILE WINAPI OpenFile(LPCSTR lpFileName, LPOFSTRUCT lpReOpenBuff, UINT uStyle);
HFILE WINAPI _lcreat(LPCSTR lpFileName, int fnAttribute);
HFILE WINAPI _lopen(LPCSTR lpPathName, int iReadWrite);
UINT WINAPI _lread(HFILE hFile, LPVOID lpBuffer, UINT uBytes);
UINT WINAPI _lwrite(HFILE hFile, LPVOID lpBuffer, UINT cbWrite);
LONG WINAPI _llseek(HFILE hFile, LONG lOffset, int iOrigin);
HFILE WINAPI _lclose(HFILE hFile);
long WINAPI _hread(HFILE hFile, LPVOID lpBuffer, long lBytes);
long WINAPI _hwrite(HFILE hFile, LPVOID lpBuffer, long lBytes);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__File16_h__)
