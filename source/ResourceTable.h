/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: ResourceTable.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ResourceTable.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__ResourceTable_h__)
#	define	__ResourceTable_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

typedef struct _ResourceDirectoryTable {
	PACKED(DWORD Characteristics);
	PACKED(DWORD TimeDateStamp);
	PACKED(WORD MajorVersion);
	PACKED(WORD MinorVersion);
	PACKED(WORD NumberOfNameEntries);
	PACKED(WORD NumberOfIDEntries);
} ResourceDirectoryTable, *LpResourceDirectoryTable;

typedef struct _ResourceDirectoryEntry {
	union {
		PACKED(DWORD NameRva);
		PACKED(DWORD IntegerId);
	};
	union {
		PACKED(DWORD DataEntryRva);
		PACKED(DWORD SubdirectoryRva);
	};
} ResourceDirectoryEntry, *LpResourceDirectoryEntry;

typedef struct _ResourceDirectoryString {
	PACKED(WORD Length);
	PACKED(WSTR UnicodeString[1]);
} ResourceDirectoryString, *LpResourceDirectoryString;

typedef struct _ResourceDataEntry {
	PACKED(DWORD DataRva);
	PACKED(DWORD Size);
	PACKED(DWORD Codepage);
	PACKED(DWORD Reserved);
} ResourceDataEntry, *LpResourceDataEntry;

#endif	// !defined(__ResourceTable_h__)
