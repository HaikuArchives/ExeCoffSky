/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2001 ‚Æ‚æ‚µ‚Ü
 *  $Id: StaticWindowClass.h,v 1.1 2003/05/01 03:34:14 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [StaticWindowClass.h]
 * -------------------------------------------------------------------------------------------- */
#include "LoadResources.h"
#include "DeviceContext.h"
#include "Window.h"
#include "User32.h"	// InvalidateRect
#include "GDI32/Object.h"
#include "GDI32/Bitmap.h"
#include "GDI32/StretchDIBits.h"
#include "GDI32/DIBSection.h"

#define	SS_LEFT				0x00000000L
#define	SS_CENTER			0x00000001L
#define	SS_RIGHT			0x00000002L
#define	SS_ICON				0x00000003L
#define	SS_BLACKRECT		0x00000004L
#define	SS_GRAYRECT			0x00000005L
#define	SS_WHITERECT		0x00000006L
#define	SS_BLACKFRAME		0x00000007L
#define	SS_GRAYFRAME		0x00000008L
#define	SS_WHITEFRAME		0x00000009L
#define	SS_USERITEM			0x0000000aL
#define	SS_SIMPLE			0x0000000bL
#define	SS_LEFTNOWORDWRAP	0x0000000cL
#define	SS_OWNERDRAW		0x0000000dL
#define	SS_BITMAP			0x0000000eL
#define	SS_ENHMETAFILE		0x0000000fL
#define	SS_ETCHEDHORZ		0x00000010L
#define	SS_ETCHEDVERT		0x00000011L
#define	SS_ETCHEDFRAME		0x00000012L
#define	SS_TYPEMASK			0x0000001fL

#define	SS_NOPREFIX			0x00000080L
#define	SS_NOTIFY			0x00000100L
#define	SS_CENTERIMAGE		0x00000200L
#define	SS_RIGHTJUST		0x00000400L
#define	SS_REALSIZEIMAGE	0x00000800L
#define	SS_SUNKEN			0x00001000L
#define	SS_ENDELLIPSIS		0x00004000L
#define	SS_PATHELLIPSIS		0x00008000L
#define	SS_WORDELLIPSIS		0x0000c000L
#define	SS_ELLIPSISMASK		0x0000c000L

class BitmapView: public BView {
private:
	HBITMAP hBitmap;
	LocalWindow *window;
	RECT drawRect;
public:
	BitmapView(HINSTANCE hInstance, BRect rect, LPCSTR lpTitle, DWORD &style):
	BView(rect, "win32 static", 0, B_WILL_DRAW),
	window(NULL) {
		WIN32API_INFO("\tBitmapView (%f, %f) - (%f, %f)\n", rect.left, rect.top, rect.right, rect.bottom);
		LPCWSTR lpTitleW;
		Win32String title;
		if (0 != (0xffff0000 & (UINT)lpTitle)) {
			title.SetToU(lpTitle);
			lpTitleW = title.StringW();
		} else {
			lpTitleW = (LPCWSTR)lpTitle;
		}
		hBitmap = LoadBitmapW(hInstance, lpTitleW);
		Bitmap *bmp = Bitmap::HandleToBitmap(hBitmap);
		if (NULL == bmp) {
			WIN32API_INFO("\tcan not load bitmap resource\n");
			return;
		}
		LPBITMAPINFO bmi = bmp->Header();
		int w = (int)rect.Width();
		int h = (int)rect.Height();
		int bw = bmi->bmiHeader.biWidth;
		int bh = bmi->bmiHeader.biHeight;
		if (0 != (style & SS_CENTERIMAGE)) {
			drawRect.left = (w - bw) / 2;
			drawRect.top = (h - bh) / 2;
			style &= ~SS_CENTERIMAGE;
		} else {
			drawRect.left = 0;
			drawRect.top = 0;
		}
		drawRect.right = (w > bw)? bw: w;
		drawRect.bottom = (h > bh)? bh: h;
	};
	~BitmapView(void) {
		if (NULL != hBitmap) DeleteObject(hBitmap);
	};
	void Initialize(LocalWindow *lwnd, LPCREATESTRUCT cs) {
		window = lwnd;
	};
	void Draw(BRect rect) {
		WIN32API_INFO("\tBitmapView::Draw (%f, %f) - (%f, %f)\n", rect.left, rect.top, rect.right, rect.bottom);
		if (NULL == window) return;
		RECT r;
		r.left = (LONG)rect.left;
		r.top = (LONG)rect.top;
		r.right = (LONG)rect.right;
		r.bottom = (LONG)rect.bottom;
		WIN32API_INTERNAL_START();
		InvalidateRect((HWND)window, &r, FALSE);
		WIN32API_INTERNAL_END();
		BWindow *owner = Window();
		window->PostMessage(WM_PAINT, 0, 0);
	};
	Bitmap *GetBitmap(void) {
		return Bitmap::HandleToBitmap(hBitmap);
	};
	void GetDrawRect(LPRECT src, LPRECT dst) {
		if (drawRect.left > 0) {
			src->left = 0;
			dst->left = drawRect.left;
		} else {
			src->left = -drawRect.left;
			dst->left = 0;
		}
		if (drawRect.top > 0) {
			src->top = 0;
			dst->top = drawRect.top;
		} else {
			src->top = -drawRect.top;
			dst->top = 0;
		}
		src->right = dst->right = drawRect.right;
		src->bottom = dst->bottom = drawRect.bottom;
	};
};

static LRESULT
StaticProc
(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	Window *window = Window::HandleToWindow(hWnd);
	LocalWindow *lwnd = DYNAMIC_CAST(LocalWindow *, window);
	LRESULT rc = 0;
	switch (nMsg) {
	case WM_CREATE: {
		LPCREATESTRUCT cs = (LPCREATESTRUCT)lParam;
		if (NULL != lwnd) {
			BView *view = lwnd->LockView();
			BitmapView *bview = DYNAMIC_CAST(BitmapView *, view);
			if (NULL != bview) {
				WIN32API_INFO("\tBitmapView::Initialize\n");
				bview->Initialize(lwnd, cs);
			}
			lwnd->UnlockView();
		}
		break; }
	case WM_PAINT:
		if (NULL != lwnd) {
			BView *view = lwnd->LockView();
			BitmapView *bview = DYNAMIC_CAST(BitmapView *, view);
			if (NULL != bview) {
				WIN32API_INFO("\tBitmapView::WM_PAINT\n");
				WIN32API_INTERNAL_START();
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				// XXX
				// WIN32API_INFO("\tStaticProc::WM_PAINT: update (%d, %d) - (%d, %d)\n", ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right, ps.rcPaint.bottom);
				Bitmap *bmp = bview->GetBitmap();
				lwnd->UnlockView();
				if (NULL != bmp) {
					LPBITMAPINFO bmi = bmp->Header();
					LPBITMAPINFOHEADER bih = &bmi->bmiHeader;
					RECT src;
					RECT dst;
					bview->GetDrawRect(&src, &dst);
					StretchDIBits(hdc,
						dst.left, dst.top, dst.right, dst.bottom,
						src.left, src.top, src.right, src.bottom,
						bmp->Bits(),
						bmi, (bih->biClrUsed == 0)?DIB_RGB_COLORS: DIB_PAL_COLORS, SRCCOPY);
				}
				EndPaint(hWnd, &ps);
				WIN32API_INTERNAL_END();
			} else {
				lwnd->UnlockView();
			}
		}
		break;
	default:
		WIN32API_INFO("\t*** StaticProc ***\n");
	}
	return rc;
}

static BView *
StaticCreateCustomView
(HINSTANCE hInstance, BRect rect, LPCSTR lpTitle, DWORD &style)
{
	BView *rc = NULL;
	if (SS_BITMAP == (style & SS_TYPEMASK)) {
		rc = new BitmapView(hInstance, rect, lpTitle, style);
	} else {
		if (0 == (0xffff0000 & (UINT)lpTitle)) lpTitle = NULL;
		if (NULL == lpTitle) WIN32API_INFO("\ttitle = (null)\n");
		rc = new BStringView(rect, "win32 static", lpTitle);
		if (NULL != rc) rc->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
		if (0 != (style & SS_TYPEMASK)) WIN32API_INFO("\tunknown type: %d\n", style & SS_TYPEMASK);
	}
	style &= ~SS_TYPEMASK;
	return rc;
}

static WNDCLASSA
StaticClass = {
	0,
	StaticProc,
	0,
	0,
	NULL, NULL, NULL, NULL,
	NULL, "STATIC",
};

static WindowClass
StaticWindowClass(&StaticClass, StaticCreateCustomView);
