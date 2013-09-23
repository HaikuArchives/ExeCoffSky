/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: ExportDirectoryTable.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ExportDirectoryTable.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__ExportDirectoryTable_h__)
#	define	__ExportDirectoryTable_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

// export directory table
typedef struct _ExportDirectoryTable {
	PACKED(DWORD exportFlags);
	PACKED(DWORD timeDateStamp);
	PACKED(WORD majorVersion);
	PACKED(WORD minorVersion);
	PACKED(DWORD nameRva);
	PACKED(DWORD ordinalBase);
	PACKED(DWORD addressTableEntries);
	PACKED(DWORD numberOfNamePointers);
	PACKED(DWORD exportAddressTableRva);
	PACKED(DWORD namePointerRva);
	PACKED(DWORD ordinalTableRva);
} ExportDirectoryTable, *LpExportDirectoryTable;

// export address table
typedef struct _ExportAddressTable {
	PACKED(DWORD exportRva);
	PACKED(DWORD forwarderRva);
} ExportAddressTable, *LpExportAddressTable;

#	if !defined(__ExportDirectoryTable__)
#		define	__ExportDirectoryTable__
#	endif	// !defined(__ExportDirectoryTable__)

#endif	// !defined(__ExportDirectoryTable_h__)
