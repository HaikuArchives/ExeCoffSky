/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: MCI.h,v 1.1 2003/05/01 06:06:00 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [MCI.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__MCI_h__)
#	define	__MCI_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

typedef struct tagMCI_PLAY_PARAMS {
	PACKED(DWORD dwCallback);
	PACKED(DWORD dwFrom);
	PACKED(DWORD dwTo);
} MCI_PLAY_PARAMS, *LPMCI_PLAY_PARAMS;

typedef struct tagMCI_SET_PARAMS {
	PACKED(DWORD dwCallback);
	PACKED(DWORD dwTimeFormat);
	PACKED(DWORD dwAudio);
} MCI_SET_PARAMS, *LPMCI_SET_PARAMS;

typedef struct tagMCI_STATUS_PARAMS {
	PACKED(DWORD dwCallback);
	PACKED(DWORD dwReturn);
	PACKED(DWORD dwItem);
	PACKED(DWORD dwTrack);
} MCI_STATUS_PARAMS, *LPMCI_STATUS_PARAMS;

#	define	MCI_OPEN		(0x0803)
#	define	MCI_CLOSE		(0x0804)

#	define	MCI_PLAY		(0x0806)
#	define	MCI_SEEK		(0x0807)
#	define	MCI_STOP		(0x0808)

#	define	MCI_SET			(0x080d)

#	define	MCI_STATUS		(0x0814)

#	define	MCI_STATUS_ITEM	0x00000100

#endif	// !defined(__MCI_h__)
