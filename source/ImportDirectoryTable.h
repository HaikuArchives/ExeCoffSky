/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: ImportDirectoryTable.h,v 1.1 2003/05/01 01:53:05 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [ImportDirectoryTable.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__ImportDirectoryTable_h__)
#	define	__ImportDirectoryTable_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

// import directory table
typedef struct _ImportDirectoryTable {
	PACKED(DWORD importLookupTableRva);
	PACKED(DWORD timeDateStamp);
	PACKED(DWORD fowarderChain);
	PACKED(DWORD nameRva);
	PACKED(DWORD importAddressTableRva);
} ImportDirectoryTable, *LpImportDirectoryTable;

// import lookup table
typedef struct _HintNameTable {
	PACKED(WORD hint);
	PACKED(CHAR name);
} HintNameTable, *LpHintNameTable;

#	if !defined(__ImportDirectoryTable__)
#		define	__ImportDirectoryTable__
#	endif	// !defined(__ImportDirectoryTable__)

#endif	// !defined(__ImpoerDirectoryTable_h__)
