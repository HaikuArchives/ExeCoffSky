/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32Client.h,v 1.1 2003/05/01 02:41:08 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32Client.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Win32Client_h__)
#	define	__Win32Client_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	define	WIN32CLIENT_TYPE	"application/x-vnd.toyoshima-house.win32-client"

class Win32Client: public BApplication {
private:
	thread_id thread;
	char *path;
public:
	Win32Client(const char *path);
	~Win32Client(void);
	void ReadyToRun(void);
private:
	static int32 Win32Main(void *data);
};

#	if !defined(__Win32Client__)
#		define	__Win32Client__
#	endif	// !defined(__Win32Client__)

#endif	// !defined(__Win32Client_h__)
