/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Menu.cpp,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Menu.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Menu.h"
#include "Win32Trace.h"
#include "Win32Error.h"
#include "Win32String.h"

MenuItem::MenuItem
(void):
parent(NULL),
item(NULL),
last(false)
{
}

MenuItem::~MenuItem
(void)
{
}

bool
MenuItem::SetTo
(UINT uIDNewItem, LPCSTR lpNewItem)
{
	BString str(lpNewItem);
	int len = str.Length();
	int key = 0;
	for (int i = 0; i < len; i++) {
		if ('&' != str.ByteAt(i)) continue;
		str.Remove(i, 1);
		len--;
		if ('&' != str.ByteAt(i)) key = str.ByteAt(i);
	}
	item = new BMenuItem(str.String(), new BMessage(uIDNewItem));
	if (NULL == item) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		return false;
	}
	if (0 != key) item->SetTrigger(key);
	WIN32API_INFO("\t\t[%s (%c)]\n", str.String(), (0 != key)? key: ' ');
	return true;
}

Menu *
MenuItem::GetParent
(void) const
{
	return parent;
}

void
MenuItem::SetParent
(Menu *parent)
{
	this->parent = parent;
}

bool
MenuItem::IsLastItem
(void) const
{
	return last;
}

void
MenuItem::SetLastItem
(bool flag)
{
	last = flag;
}

BMenuItem *
MenuItem::GetNativeItem
(void)
{
	return item;
}

Menu::Menu
(int type):
magic(MENU_MAGIC),
type(type)
{
	if (MENU_TYPE_MENUBAR == type) {
		menu = new BMenuBar(BRect(0, 0, 0, 0), "win32 menu");
	} else {
		menu = NULL;
	}
}

Menu::~Menu
(void)
{
}

bool
Menu::SetTo
(LPCSTR lpLabel)
{
	if (NULL != menu) return FALSE;
	if (MENU_TYPE_POPUP != type) return FALSE;
	BString str(lpLabel);
	int len = str.Length();
	int key = 0;
	for (int i = 0; i < len; i++) {
		if ('&' != str.ByteAt(i)) continue;
		str.Remove(i, 1);
		len--;
		if ('&' != str.ByteAt(i)) key = str.ByteAt(i);
	}
	menu = new BMenu(str.String());
	if (NULL == menu) return false;
	WIN32API_INFO("\t\t[%s (%c)]\n", str.String(), (0 != key)? key: ' ');
	return true;
}

BOOL
Menu::Append
(UINT uFlags, UINT uIDNewItem, LPCSTR lpNewItem)
{
	if (NULL == menu) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
		return FALSE;
	}
	if (0 == (uFlags & MF_POPUP)) {
		// item
		WIN32API_INFO("\tappend id = %d (%s)\n", uIDNewItem, lpNewItem);
		MenuItem *item = new MenuItem();
		if (NULL == item) {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			return FALSE;
		}
		if (!item->SetTo(uIDNewItem, lpNewItem)) {
			delete item;
			return FALSE;
		}
		if (!menu->AddItem(item->GetNativeItem())) {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			return FALSE;
		}
		children.AddItem((void *)item);
	} else {
		// popup
		WIN32API_INFO("\tappend menu (%s)\n", lpNewItem);
		Menu *menu = Menu::HandleToMenu((HMENU)uIDNewItem);
		if (NULL == menu) {
			WIN32API_ERROR(ERROR_INVALID_HANDLE);
			return FALSE;
		}
		menu->SetParent(this);
		menu->SetTo(lpNewItem);
		if (!this->menu->AddItem(menu->GetNativeMenu())) {
			WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
			return FALSE;
		}
		children.AddItem((void *)menu);
	}
	WIN32API_ERROR(ERROR_SUCCESS);
	return TRUE;
}

BMenu *
Menu::GetNativeMenu
(void) const
{
	return menu;
}

Menu *
Menu::HandleToMenu
(HMENU hMenu)
{
	if (NULL == hMenu) return NULL;
	Menu *menu = (Menu *)hMenu;
	if (menu->magic != MENU_MAGIC) return NULL;
	return menu;
}

extern "C" HMENU WINAPI
LoadMenuIndirectA
(CONST MENUTEMPLATEA *lpMenuTemplate)
{
	HMENU rc = NULL;
	WIN32API_POINTER(lpMenuTemplate);
	WIN32API_ENTER("HMENU", "LoadMenuIndirectA", "CONST MENUTEMPLATEA *", lpMenuTemplate, NULL);
	LPMENUITEMTEMPLATEHEADER mith = (LPMENUITEMTEMPLATEHEADER)lpMenuTemplate;
	WIN32API_INFO("\tversion: %d\n", mith->versionNumber);
	WIN32API_INFO("\toffset: %d\n", mith->offset);
	LPMENUITEMTEMPLATE mit = (LPMENUITEMTEMPLATE)&mith[1];
	WIN32API_INTERNAL_START();
	rc = CreateMenu();
	try {
		if (NULL == rc) throw 0;
		int depth = 1;
		HMENU menu = rc;
		for (;;) {
			bool end = 0 != (mit->mtOption & MF_END);
			WIN32API_INFO("\t--\n\toption: $%08x\n", mit->mtOption);
			if (0 != (mit->mtOption & MF_POPUP)) {
				// popup
				Win32String str;
				str.SetToW(mit->mtPopupString);
				WIN32API_INFO("\tstring: %s\n", str.StringU());
				HMENU popup = CreatePopupMenu();
				if (NULL == popup) throw 0;
				if (0 != (mit->mtOption & MF_END)) {
					Menu::HandleToMenu(menu)->SetLastItem();
				}
				if (!AppendMenuA(menu, mit->mtOption, (UINT)popup, str.StringA())) throw 0;
				menu = popup;
				mit = (LPMENUITEMTEMPLATE)&mit->mtPopupString[str.LengthW() + 1];
				depth++;
				WIN32API_INFO("\t[\n");
			} else {
				Win32String str;
				str.SetToW(mit->mtString);
				WIN32API_INFO("\tid: %d\n", mit->mtID);
					WIN32API_INFO("\tstring: %s\n", str.StringU());
				if (!AppendMenuA(menu, mit->mtOption, mit->mtID, str.StringA())) throw 0;
				mit = (LPMENUITEMTEMPLATE)&mit->mtString[str.LengthW() + 1];
			}
			if (end) {
				do {
					menu = (HMENU)Menu::HandleToMenu(menu)->GetParent();
					WIN32API_INFO("\t]\n");
					depth--;
				} while ((NULL != menu) && Menu::HandleToMenu(menu)->IsLastItem());
			}
			if (0 == depth) {
				WIN32API_ERROR(ERROR_SUCCESS);
				break;
			}
		}
	} catch (int e) {
		if (NULL != rc) {
			DestroyMenu(rc);
			rc = NULL;
		}
		if (0 != e) WIN32API_ERROR(e);
	}
	WIN32API_INTERNAL_END();
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
LoadMenuIndirectW
(CONST MENUTEMPLATEW *lpMenuTemplate)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "LoadMenuIndirectW", "CONST MENUTEMPLATEW *", lpMenuTemplate, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
CreateMenu
(VOID)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "CreateMenu", "VOID", NULL);
	Menu *menu = new Menu(MENU_TYPE_MENUBAR);
	if (NULL == menu) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		rc = (HMENU)menu;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
CreatePopupMenu
(VOID)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "CreatePopupMenu", "VOID", NULL);
	Menu *menu = new Menu(MENU_TYPE_POPUP);
	if (NULL == menu) {
		WIN32API_ERROR(ERROR_NOT_ENOUGH_MEMORY);
	} else {
		rc = (HMENU)menu;
		WIN32API_ERROR(ERROR_SUCCESS);
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AppendMenuA
(HMENU hMenu, UINT uFlags, UINT uIDNewItem, LPCSTR lpNewItem)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpNewItem);
	WIN32API_ENTER("BOOL", "AppendMenuA", "HMENU", hMenu, "UINT", uFlags, "UINT", uIDNewItem, "LPCSTR", lpNewItem, NULL);
	Menu *menu = Menu::HandleToMenu(hMenu);
	if (NULL == menu) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		if (0x80000000 & (long)lpNewItem) { // XXX
			Win32String str;
			str.SetToA(lpNewItem);
			rc = menu->Append(uFlags, uIDNewItem, str.StringU());
		}
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
AppendMenuW
(HMENU hMenu, UINT uFlags, UINT uIDNewItem, LPCWSTR lpNewItem)
{
	BOOL rc = FALSE;
	WIN32API_POINTER(lpNewItem);
	WIN32API_ENTER("BOOL", "AppendMenuW", "HMENU", hMenu, "UINT", uFlags, "UINT", uIDNewItem, "LPCWSTR", lpNewItem, NULL);
	Menu *menu = Menu::HandleToMenu(hMenu);
	if (NULL == menu) {
		WIN32API_ERROR(ERROR_INVALID_HANDLE);
	} else {
		Win32String str;
		str.SetToW(lpNewItem);
		rc = menu->Append(uFlags, uIDNewItem, str.StringU());
	}
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ChangeMenuA
(HMENU arg0, UINT arg1, LPCSTR arg2, UINT arg3, UINT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChangeMenuA", "HMENU", arg0, "UINT", arg1, "LPCSTR", arg2, "UINT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ChangeMenuW
(HMENU arg0, UINT arg1, LPCWSTR arg2, UINT arg3, UINT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ChangeMenuW", "HMENU", arg0, "UINT", arg1, "LPCWSTR", arg2, "UINT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
CheckMenuItem
(HMENU hMenu, UINT uIDCheckItem, UINT uCheck)
{
	DWORD rc = 0;
	WIN32API_ENTER("DWORD", "CheckMenuItem", "HMENU", hMenu, "UINT", uIDCheckItem, "UINT", uCheck, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
CheckMenuRadioItem
(HMENU arg0, UINT arg1, UINT arg2, UINT arg3, UINT arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "CheckMenuRadioItem", "HMENU", arg0, "UINT", arg1, "UINT", arg2, "UINT", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
DestroyMenu
(HMENU arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "DestroyMenu", "HMENU", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
EnableMenuItem
(HMENU hMenu, UINT uIDEnableItem, UINT uEnable)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "EnableMenuItem", "HMENU", hMenu, "UINT", uIDEnableItem, "UINT", uEnable, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" DWORD WINAPI
GetMenuContextHelpId
(HMENU arg0)
{
	DWORD rc = (DWORD)-1;
	WIN32API_ENTER("DWORD", "GetMenuContextHelpId", "HMENU", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetMenuDefaultItem
(HMENU arg0, UINT arg1, UINT arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetMenuDefaultItem", "HMENU", arg0, "UINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetMenuItemCount
(HMENU arg0)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetMenuItemCount", "HMENU", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetMenuItemID
(HMENU arg0, int arg1)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetMenuItemID", "HMENU", arg0, "int", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetMenuItemInfoA
(HMENU arg0, UINT arg1, BOOL arg2, LPMENUITEMINFOA arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetMenuItemInfoA", "HMENU", arg0, "UINT", arg1, "BOOL", arg2, "LPMENUITEMINFOA", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetMenuItemInfoW
(HMENU arg0, UINT arg1, BOOL arg2, LPMENUITEMINFOW arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetMenuItemInfoW", "HMENU", arg0, "UINT", arg1, "BOOL", arg2, "LPMENUITEMINFOW", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
GetMenuItemRect
(HWND arg0, HMENU arg1, UINT arg2, LPRECT arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "GetMenuItemRect", "HWND", arg0, "HMENU", arg1, "UINT", arg2, "LPRECT", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" UINT WINAPI
GetMenuState
(HMENU arg0, UINT arg1, UINT arg2)
{
	UINT rc = (UINT)-1;
	WIN32API_ENTER("UINT", "GetMenuState", "HMENU", arg0, "UINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetMenuStringA
(HMENU arg0, UINT arg1, LPSTR arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetMenuStringA", "HMENU", arg0, "UINT", arg1, "LPSTR", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" int WINAPI
GetMenuStringW
(HMENU arg0, UINT arg1, LPWSTR arg2, int arg3, UINT arg4)
{
	int rc = (int)-1;
	WIN32API_ENTER("int", "GetMenuStringW", "HMENU", arg0, "UINT", arg1, "LPWSTR", arg2, "int", arg3, "UINT", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" HMENU WINAPI
GetSubMenu
(HMENU hMenu, int nPos)
{
	HMENU rc = NULL;
	WIN32API_ENTER("HMENU", "GetSubMenu", "HMENU", hMenu, "int", nPos, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InsertMenuA
(HMENU arg0, UINT arg1, UINT arg2, UINT arg3, LPCSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InsertMenuA", "HMENU", arg0, "UINT", arg1, "UINT", arg2, "UINT", arg3, "LPCSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InsertMenuW
(HMENU arg0, UINT arg1, UINT arg2, UINT arg3, LPCWSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InsertMenuW", "HMENU", arg0, "UINT", arg1, "UINT", arg2, "UINT", arg3, "LPCWSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InsertMenuItemA
(HMENU arg0, UINT arg1, BOOL arg2, LPCMENUITEMINFOA arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InsertMenuItemA", "HMENU", arg0, "UINT", arg1, "BOOL", arg2, "LPCMENUITEMINFOA", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
InsertMenuItemW
(HMENU arg0, UINT arg1, BOOL arg2, LPCMENUITEMINFOW arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "InsertMenuItemW", "HMENU", arg0, "UINT", arg1, "BOOL", arg2, "LPCMENUITEMINFOW", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
IsMenu
(HMENU arg0)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "IsMenu", "HMENU", arg0, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ModifyMenuA
(HMENU arg0, UINT arg1, UINT arg2, UINT arg3, LPCSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ModifyMenuA", "HMENU", arg0, "UINT", arg1, "UINT", arg2, "UINT", arg3, "LPCSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
ModifyMenuW
(HMENU arg0, UINT arg1, UINT arg2, UINT arg3, LPCWSTR arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "ModifyMenuW", "HMENU", arg0, "UINT", arg1, "UINT", arg2, "UINT", arg3, "LPCWSTR", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
RemoveMenu
(HMENU arg0, UINT arg1, UINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "RemoveMenu", "HMENU", arg0, "UINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMenuContextHelpId
(HMENU arg0, DWORD arg1)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMenuContextHelpId", "HMENU", arg0, "DWORD", arg1, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMenuDefaultItem
(HMENU arg0, UINT arg1, UINT arg2)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMenuDefaultItem", "HMENU", arg0, "UINT", arg1, "UINT", arg2, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMenuItemBitmaps
(HMENU arg0, UINT arg1, UINT arg2, HBITMAP arg3, HBITMAP arg4)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMenuItemBitmaps", "HMENU", arg0, "UINT", arg1, "UINT", arg2, "HBITMAP", arg3, "HBITMAP", arg4, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMenuItemInfoA
(HMENU arg0, UINT arg1, BOOL arg2, LPCMENUITEMINFOA arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMenuItemInfoA", "HMENU", arg0, "UINT", arg1, "BOOL", arg2, "LPCMENUITEMINFOA", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}

extern "C" BOOL WINAPI
SetMenuItemInfoW
( HMENU arg0, UINT arg1, BOOL arg2, LPCMENUITEMINFOW arg3)
{
	BOOL rc = FALSE;
	WIN32API_ENTER("BOOL", "SetMenuItemInfoW", " HMENU", arg0, "UINT", arg1, "BOOL", arg2, "LPCMENUITEMINFOW", arg3, NULL);
	WIN32API_INFO("\tnot impl.\n");
	WIN32API_LEAVE(rc);
	return rc;
}
