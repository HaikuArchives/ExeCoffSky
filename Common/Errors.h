/* --------------------------------------------------------------------------------------------
 *  Pop'n Pop - hotmail to pop3 gateway -
 *  EL-POINT subset version for KARIHITO (C) Grains
 *  ウェブ・サインアップ (C) ACENET, Inc.
 *  music creative driver for Win32 (Netscape Plug-in / WinAmp Plug-in) / BeOS
 *  LwXML - Light weight XML Library -
 *  WinTCPd - Tiny TCP daemon for Win32
 *  ChatRoomServer / ReferenceClient(chat-in) (C) Digital Arts
 *  Meta Gassee - Meta Gate clone for BeOS -
 *  Trance Palrance - WonderWitch TransMagic clone for BeOS -
 *  Asacot2 for Win32 / MacOS (C) ACENET, Inc.
 *  MisuzuWebServer - a httpd for BeOS -
 *  ExeCoffSky for BeOS
 *  MMFake for Win2k / WINMM.DLL compat. Library
 *  Xexex - Incorporated X Server - for BeOS
 *  寿司絵 - GraphicLoader with ECS x SPI for BeOS -
 *  ICO Translator for BeOS
 *  El-Point
 *  ぽえみ for PocketPC
 *  箱入り娘。
 *  (C) 1999 - 2003 とよしま
 *  $Id: Errors.h,v 1.1 2003/05/01 02:35:26 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Errors.h]
 *   エラーを定義する
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Errors_h__)
#	define	__Errors_h__

#	define	ERROR_OK					0
#	define	ERROR_NO_PROBLEM			ERROR_OK

#	if defined(ERROR_UNKNOWN)
#		undef	ERROR_UNKNOWN
#	endif	// defined(ERROR_UNKNOWN)

#	define	ERROR_UNKNOWN				1
#	define	ERROR_MEMORY				2
#	define	ERROR_UNSUPPORTED			3
#	define	ERROR_MEDIACHECK			4
#	define	ERROR_FILE_OPEN				5
#	define	ERROR_FILE_READ				6
#	define	ERROR_FILE_WRITE			7
#	define	ERROR_FILE_SEEK				8
#	define	ERROR_FILE_CLOSE			9
#	define	ERROR_INVAL_DATA			10
#	define	ERROR_GET_INSTANCE			11
#	define	ERROR_REGISTER_CLASS		12
#	define	ERROR_UNREGISTER_CLASS		13
#	define	ERROR_INSTANCE_BUSY			14
#	define	ERROR_CREATEWINDOW			15
#	define	ERROR_DESTROYWINDOW			16
#	define	ERROR_ALREADY_STOP			17
#	define	ERROR_CREATE_SOCK			18
#	define	ERROR_ASYNCSELECT			19
#	define	ERROR_BIND					20
#	define	ERROR_LISTEN				21
#	define	ERROR_CLOSESOCKET			22
#	define	ERROR_WINSOCK				23
#	define	ERROR_INVALID_WINSOCK		24
#	define	ERROR_ACCEPT				25
#	define	ERROR_NEW					26
#	define	ERROR_SESSION_START			27
#	define	ERROR_FD_READ				28
#	define	ERROR_FD_WRITE				29
#	define	ERROR_SHUTDOWN				30
#	define	ERROR_GETHOSTBYNAME			31
#	define	ERROR_CONNECT				32
#	define	ERROR_NOMODEM				33
#	define	ERROR_INVALID_ARGUMENT		34

#	define	ERROR_XML_BASE				100
#	define	ERROR_XML_INVALID_DECL		(ERROR_XML_BASE + 0)
#	define	ERROR_XML_INVALID_VER		(ERROR_XML_BASE + 1)
#	define	ERROR_XML_INVALID_EOF		(ERROR_XML_BASE + 2)
#	define	ERROR_XML_SYNTAX			(ERROR_XML_BASE + 3)
#	define	ERROR_XML_INVALID_TAG_END	(ERROR_XML_BASE + 4)
#	define	ERROR_XML_INVALID_TAG_TYPE	(ERROR_XML_BASE + 5)
#	define	ERROR_XML_INVALID_ATTR		(ERROR_XML_BASE + 6)
#	define	ERROR_XML_INVALID_ATTR_END	(ERROR_XML_BASE + 7)

#	if defined(__BEOS__)
#		include <support/Errors.h>
#	endif	// defined(__BEOS__)

#endif	// !defined(__Errors_h__)
