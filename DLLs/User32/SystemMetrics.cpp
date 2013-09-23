/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: SystemMetrics.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [SystemMetrics.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "SystemMetrics.h"
#include "Win32Trace.h"

extern "C" int WINAPI
GetSystemMetrics
(int nIndex)
{
	int rc = 0;
	WIN32API_ENTER("int", "GetSystemMetrics", "int", nIndex, NULL);
	switch (nIndex) {
	case SM_CXSCREEN: {
		BScreen scr;
		BRect rect = scr.Frame();
		rc = (int)rect.Width() + 1;
		break; }
	case SM_CYSCREEN: {
		BScreen scr;
		BRect rect = scr.Frame();
		rc = (int)rect.Height() + 1;
		break; }
	case SM_CYMENU: {
		BMenuBar *mbar = new BMenuBar(BRect(0, 0, 0, 0), "SM_CYMENU");
		if (NULL != mbar) {
			BWindow *win = new BWindow(BRect(0, 0, 100, 100), "SM_CYMENU", B_TITLED_WINDOW, 0);
			if (NULL != win) {
				win->AddChild(mbar);
				rc = (int)(mbar->Frame().Height() + 1);
				WIN32API_INFO("\tmenubar height: %d\n", rc);
				win->Quit();
			} else {
				delete mbar;
			}
		}
		break; }
	case SM_CYCAPTION:
	case SM_CXFRAME:
	case SM_CYFRAME:
	case SM_CXDLGFRAME:
	case SM_CYDLGFRAME:
		rc = 0;	//
		break;
	default:
		WIN32API_INFO("\tnot impl.\n");
	}
	WIN32API_LEAVE(rc);
	return rc;
}
