/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Timer.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Timer.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Timer_h__)
#	define	__Timer_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Window__)
class Window;
#		define	__Window__
#	endif	// !defined(__Window__)

typedef VOID CALLBACK (*TIMERPROC)(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime);

class Timer {
friend class Window;
private:
	int elapse;
	int counter;
	bool event;
	UINT id;
	HWND hWnd;
	TIMERPROC lpTimerFunc;
	port_id port;
	bigtime_t next;
public:
	Timer(HWND hWnd, UINT nIDEvent, UINT nElapse, TIMERPROC lpTimerFunc);
	void Set(port_id port);
	void Check(bigtime_t *now);
private:
	void Invoke(void);
};

#	if !defined(__Timer__)
#		define	__Timer__
#	endif	// !defined(__Timer__)

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

UINT WINAPI SetTimer(HWND hWnd, UINT nIDEvent, UINT nElapse, TIMERPROC lpTimerFunc);
BOOL WINAPI KillTimer(HWND hWnd, UINT nIDEvent);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Timer_h__)
