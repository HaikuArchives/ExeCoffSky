/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Object.cpp,v 1.1 2003/05/01 03:05:18 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Object.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Object.h"
#include "DeviceContext.h"
#include "Win32Trace.h"
#include "Win32Error.h"

Object::Object
(void):
magic(OBJECT_MAGIC)
{
}

Object::~Object
(void)
{
}

Object *
Object::HandleToObject
(HGDIOBJ hObject)
{
	if (NULL == hObject) return NULL;
	if (INVALID_HANDLE_VALUE == hObject) return NULL;
	Object *object = (Object *)hObject;
	if (object->magic != OBJECT_MAGIC) return NULL;
	return object;
}

extern "C" BOOL WINAPI
DeleteObject
(HGDIOBJ hObject)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DeleteObject", "HGDIOBJ", hObject, NULL);
	Object *object = Object::HandleToObject(hObject);
	if (NULL == object) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		delete object;
		WIN32API_ERROR(ERROR_SUCCESS);
		rc = TRUE;
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HGDIOBJ WINAPI
SelectObject
(HDC hDc, HGDIOBJ hgdiobj)
{
	HGDIOBJ rc = NULL;
	WIN32API_ENTER("HGDIOBJ", "SelectObject", "HDC", hDc, "HGDIOBJ", hgdiobj, NULL);
	DeviceContext *dc = DeviceContext::HandleToDeviceContext(hDc);
	Object *obj = Object::HandleToObject(hgdiobj);
	if ((NULL == dc) || (NULL == obj)) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		rc = (HGDIOBJ)dc->SelectObject(obj);
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}
