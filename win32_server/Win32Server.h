/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32Server.h,v 1.1 2003/05/01 02:41:08 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32Server.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Win32Server_h__)
#	define	__Win32Server_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	MAX_REQUEST_SIZE	1024

#	define	WIN32SERVER_TYPE	"application/x-vnd.toyoshima-house.win32-server"

class Win32Server: public BApplication {
private:
	port_id port;
	thread_id thread;
public:
	Win32Server(void);
	void ReadyToRun(void);
	bool QuitRequested(void);
	void RefsReceived(BMessage *msg);
	void Launch(BPath *path);
private:
	void SetMIME(void);
	static int32 ServiceLoop(void *data);
};

#	if !defined(__Win32Server__)
#		define	__Win32Server__
#	endif	// !defined(__Win32Server__)

#endif	// !defined(__Win32Server_h__)
