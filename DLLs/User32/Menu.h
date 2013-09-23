/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: Menu.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Menu.h]
 * -------------------------------------------------------------------------------------------- */

#if !defined(__Menu_h__)
#	define	__Menu_h__

#	if !defined(__Common_h__)
#		include "Common.h"
#	endif	// !defined(__Common_h__)

#	if !defined(__Win32Structures_h__)
#		include "Win32Structures.h"
#	endif	// !defined(__Win32Structures_h__)

typedef struct tagMENUITEMINFOA {
	PACKED(UINT cbSize);
	PACKED(UINT fMask);
	PACKED(UINT fType);
	PACKED(UINT fState);
	PACKED(UINT wID);
	PACKED(HMENU hSubMenu);
	PACKED(HBITMAP hbmpChecked);
	PACKED(HBITMAP hbmpUnchecked);
	PACKED(DWORD dwItemData);
	PACKED(LPSTR dwTypeData);
	PACKED(UINT cch);
	PACKED(HBITMAP hbmpItem);
} MENUITEMINFOA, *LPMENUITEMINFOA;
typedef const MENUITEMINFOA CMENUITEMINFOA, *LPCMENUITEMINFOA;

typedef struct tagMENUITEMINFOW {
	PACKED(UINT cbSize);
	PACKED(UINT fMask);
	PACKED(UINT fType);
	PACKED(UINT fState);
	PACKED(UINT wID);
	PACKED(HMENU hSubMenu);
	PACKED(HBITMAP hbmpChecked);
	PACKED(HBITMAP hbmpUnchecked);
	PACKED(DWORD dwItemData);
	PACKED(LPWSTR dwTypeData);
	PACKED(UINT cch);
	PACKED(HBITMAP hbmpItem);
} MENUITEMINFOW, *LPMENUITEMINFOW;
typedef const MENUITEMINFOW CMENUITEMINFOW, *LPCMENUITEMINFOW;

typedef struct tagMENUITEMTEMPLATEHEADER {
	PACKED(WORD versionNumber);
	PACKED(WORD offset);
} MENUITEMTEMPLATEHEADER, *LPMENUITEMTEMPLATEHEADER;

typedef struct tagMENUITEMTEMPLATE {
	PACKED(WORD mtOption);
	union {
		PACKED(WORD mtID);
		PACKED(WCHAR mtPopupString[1]);
	};
	PACKED(WCHAR mtString[1]);
} MENUITEMTEMPLATE, *LPMENUITEMTEMPLATE;

typedef struct tagMENUEX_TEMPLATE_HEADER {
	PACKED(WORD wVersion);
	PACKED(WORD wOffset);
	PACKED(WORD dwHelpId);
} MENUEX_TEMPLATE_HEADER, *LPMENUEX_TEMPLATE_HEADER;

typedef struct tagMENUEX_TEMPLATE_ITEM {
	PACKED(DWORD dwHelpId);
	PACKED(DWORD dwType);
	PACKED(DWORD dwState);
	PACKED(DWORD menuId);
	PACKED(WORD bResInfo);
	PACKED(WCHAR szText[1]);
} MENUEX_TEMPLATE_ITEM, *LPMENUEX_TEMPLATE_ITEM;

typedef VOID MENUTEMPLATEA;
typedef VOID MENUTEMPLATEW;

#	define	MF_INSERT			0x00000000L
#	define	MF_CHANGE			0x00000080L
#	define	MF_APPEND			0x00000100L
#	define	MF_DELETE			0x00000200L
#	define	MF_REMOVE			0x00001000L

#	define	MF_BYCOMMAND		0x00000000L
#	define	MF_BYPOSITION		0x00000400L

#	define	MF_SEPARATOR		0x00000800L

#	define	MF_ENABLED			0x00000000L
#	define	MF_GRAYED			0x00000001L
#	define	MF_DISABLED			0x00000002L

#	define	MF_UNCHECKED		0x00000000L
#	define	MF_CHECKED			0x00000008L
#	define	MF_USECHECKBITMAPS	0x00000200L

#	define	MF_STRING			0x00000000L
#	define	MF_BITMAP			0x00000004L
#	define	MF_OWNERDRAW		0x00000100L

#	define	MF_POPUP			0x00000010L
#	define	MF_MENUBARBREAK		0x00000020L
#	define	MF_MENUBREAK		0x00000040L

#	define	MF_UNHILITE			0x00000000L
#	define	MF_HILITE			0x00000080L

#	define	MF_DEFAULT			0x00001000L
#	define	MF_SYSMENU			0x00002000L
#	define	MF_HELP				0x00004000L
#	define	MF_RIGHTJUSTIFY		0x00004000L

#	define	MF_MOUSESELECT		0x00008000L
#	define	MF_END				0x00000080L

#	if !defined(__Menu__)
class Menu;
#		define	__Menu__
#	endif	// !defined(__Menu__)

class MenuItem {
private:
	Menu *parent;
	BMenuItem *item;
	bool last;
public:
	MenuItem(void);
	~MenuItem(void);

	bool SetTo(UINT uIDNewItem, LPCSTR lpNewItem);
	Menu *GetParent(void) const;
	void SetParent(Menu *parent);
	bool IsLastItem(void) const;
	void SetLastItem(bool flag = true);
	BMenuItem *GetNativeItem(void);
};

#	if !defined(__MenuItem__)
#		define	__MenuItem__
#	endif	// !defined(__MenuItem__)

#	define	MENU_MAGIC			'_MNU'

#	define	MENU_TYPE_MENUBAR	0
#	define	MENU_TYPE_POPUP		1

class Menu: public MenuItem {
public:
	DWORD magic;
private:
	int type;
	BMenu *menu;
	BList children;
public:
	Menu(int type = MENU_TYPE_MENUBAR);
	~Menu(void);
	
	bool SetTo(LPCSTR lpLabel);
	
	BOOL Append(UINT uFlags, UINT uIDNewItem, LPCSTR lpNewItem);
	BMenu *GetNativeMenu(void) const;

	static Menu *HandleToMenu(HMENU hMenu);
};

#	if defined(__cplusplus)
extern "C" {
#	endif	// defined(__cplusplus)

HMENU WINAPI LoadMenuIndirectA(CONST MENUTEMPLATEA *lpMenuTemplate);
HMENU WINAPI LoadMenuIndirectW(CONST MENUTEMPLATEW *lpMenuTemplate);

HMENU WINAPI CreateMenu(VOID);
HMENU WINAPI CreatePopupMenu(VOID);
BOOL WINAPI AppendMenuA(HMENU hMenu, UINT uFlags, UINT uIDNewItem, LPCSTR lpNewItem);
BOOL WINAPI AppendMenuW(HMENU hMenu, UINT uFlags, UINT uIDNewItem, LPCWSTR lpNewItem);

BOOL WINAPI ChangeMenuA(HMENU,UINT,LPCSTR,UINT,UINT);
BOOL WINAPI ChangeMenuW(HMENU,UINT,LPCWSTR,UINT,UINT);
DWORD WINAPI CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck);
BOOL WINAPI CheckMenuRadioItem(HMENU,UINT,UINT,UINT,UINT);
BOOL WINAPI DeleteMenu(HMENU hMenu, UINT uPosition, UINT uFlags);
BOOL WINAPI DestroyMenu(HMENU);
BOOL WINAPI EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable);
DWORD WINAPI GetMenuContextHelpId(HMENU);
UINT WINAPI GetMenuDefaultItem(HMENU,UINT,UINT);
int WINAPI GetMenuItemCount(HMENU);
UINT WINAPI GetMenuItemID(HMENU,int);
BOOL WINAPI GetMenuItemInfoA(HMENU,UINT,BOOL,LPMENUITEMINFOA);
BOOL WINAPI GetMenuItemInfoW(HMENU,UINT,BOOL,LPMENUITEMINFOW);
BOOL WINAPI GetMenuItemRect(HWND,HMENU,UINT,LPRECT);
UINT WINAPI GetMenuState(HMENU,UINT,UINT);
int WINAPI GetMenuStringA(HMENU,UINT,LPSTR,int,UINT);
int WINAPI GetMenuStringW(HMENU,UINT,LPWSTR,int,UINT);
HMENU WINAPI GetSubMenu(HMENU hMenu, int nPos);
BOOL WINAPI InsertMenuA(HMENU,UINT,UINT,UINT,LPCSTR);
BOOL WINAPI InsertMenuItemA(HMENU,UINT,BOOL,LPCMENUITEMINFOA);
BOOL WINAPI InsertMenuItemW(HMENU,UINT,BOOL,LPCMENUITEMINFOW);
BOOL WINAPI InsertMenuW(HMENU,UINT,UINT,UINT,LPCWSTR);
BOOL WINAPI IsMenu(HMENU);
BOOL WINAPI ModifyMenuA(HMENU,UINT,UINT,UINT,LPCSTR);
BOOL WINAPI ModifyMenuW(HMENU,UINT,UINT,UINT,LPCWSTR);
BOOL WINAPI RemoveMenu(HMENU,UINT,UINT);
BOOL WINAPI SetMenuContextHelpId(HMENU,DWORD);
BOOL WINAPI SetMenuDefaultItem(HMENU,UINT,UINT);
BOOL WINAPI SetMenuItemBitmaps(HMENU,UINT,UINT,HBITMAP,HBITMAP);
BOOL WINAPI SetMenuItemInfoA(HMENU,UINT,BOOL,LPCMENUITEMINFOA);
BOOL WINAPI SetMenuItemInfoW( HMENU,UINT,BOOL,LPCMENUITEMINFOW);

#	if defined(__cplusplus)
};
#	endif	// defined(__cplusplus)

#endif	// !defined(__Menu_h__)
