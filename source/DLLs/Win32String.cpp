/* --------------------------------------------------------------------------------------------
 *  ExeCoffSky for BeOS
 *  (C) 2000 ‚Æ‚æ‚µ‚Ü
 *  $Id: Win32String.cpp,v 1.1 2003/05/01 02:55:03 toyoshim Exp $
 * --------------------------------------------------------------------------------------------
 *  [Win32String.cpp]
 * -------------------------------------------------------------------------------------------- */
#include "Win32String.h"

BLocker
Win32String::lock;

Win32String::Win32String
(VOID):
buf_a(NULL),
buf_w(NULL),
buf_u(NULL)
{
	MakeEmpty();
}

Win32String::Win32String
(LPCSTR lpString):
buf_a(NULL),
buf_w(NULL),
buf_u(NULL)
{
	SetToA(lpString);
}

Win32String::Win32String
(LPCWSTR lpString):
buf_a(NULL),
buf_w(NULL),
buf_u(NULL)
{
	SetToW(lpString);
}

Win32String::~Win32String
(void)
{
	MakeEmpty();
}

bool
Win32String::SetToA
(LPCSTR lpString)
{
	UINT size = 0;
	if (NULL != lpString) size = strlen(lpString);
	return SetToA(lpString, size);
}

bool
Win32String::SetToA
(LPCSTR lpString, UINT uSize)
{
	MakeEmpty();
	if (NULL == lpString) return false;
	sourcetype = 1;
	len_a = uSize;
	buf_a = new char[len_a + 1];
	if (NULL == buf_a) return false;
	memcpy(buf_a, lpString, len_a);
	buf_a[len_a] = 0;
	return true;
}

bool
Win32String::SetToW
(LPCWSTR lpString)
{
	UINT size = 0;
	if (NULL != lpString) size = strlenW(lpString);
	return SetToW(lpString, size);
}

bool
Win32String::SetToW
(LPCWSTR lpString, UINT uSize)
{
	MakeEmpty();
	if (NULL == lpString) return false;
	sourcetype = 2;
	len_w = uSize;
	buf_w = new short[len_w + 1];
	if (NULL == buf_w) return false;
	memcpy(buf_w, lpString, len_w * 2);
	buf_w[len_w] = 0;
	return true;
}

bool
Win32String::SetToU
(LPCSTR lpString)
{
	UINT size = 0;
	if (NULL != lpString) size = strlen(lpString);
	return SetToU(lpString, size);
}

bool
Win32String::SetToU
(LPCSTR lpString, UINT uSize)
{
	MakeEmpty();
	if (NULL == lpString) return false;
	sourcetype = 3;
	len_u = uSize;
	buf_u = new char[len_u + 1];
	if (NULL == buf_u) return false;
	memcpy(buf_u, lpString, len_u);
	buf_u[len_u] = 0;
	return true;
}

LPCSTR
Win32String::StringA
(VOID)
{
	if (NULL == buf_a) {
		if (sourcetype == 2) WtoA();
		else if (sourcetype == 3) UtoA();
	}
	return buf_a;
}

LPCWSTR
Win32String::StringW
(VOID)
{
	if (NULL == buf_w) {
		if (sourcetype == 1) AtoW();
		else if (sourcetype == 3) UtoW();
	}
	return buf_w;
}

LPCSTR
Win32String::StringU
(VOID)
{
	if (NULL == buf_u) {
		if (sourcetype == 1) AtoU();
		else if (sourcetype == 2) WtoU();
	}
	return buf_u;
}

size_t
Win32String::LengthA
(VOID)
{
	StringA();
	return len_a;
}

size_t
Win32String::LengthW
(VOID)
{
	StringW();
	return len_w;
}

size_t
Win32String::LengthU
(VOID)
{
	StringU();
	return len_u;
}

UINT
Win32String::SetCodePage
(UINT CodePage)
{
	// XXX
	return 932;
}

UINT
Win32String::GetCodePage
(VOID)
{
	// XXX
	return 932;
}

size_t
Win32String::strlenW
(const short *s)
{
	Lock();
	size_t rc = 0;
	for (; 0 != *s; s++) rc++;
	Unlock();
	return rc;
}

short *
Win32String::strcpyW
(short *dest, const short *src)
{
	Lock();
	short *rc = dest;
	do {
		*dest++ = *src;
	} while (0 != *src++);
	Unlock();
	return rc;
}

short *
Win32String::strdupW
(const short *src)
{
	Lock();
	size_t len = strlenW(src) + 1;
	short *buf = (short *)malloc(len * 2);
	if (NULL != buf) strcpyW(buf, src);
	Unlock();
	return buf;
}

int
Win32String::strncasecmpW
(const short *s1, const short *s2, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		short src1 = s1[i];
		short src2 = s2[i];
		if (('A' <= src1) && (src1 <= 'Z')) src1 |= 0x20;
		if (('A' <= src2) && (src2 <= 'Z')) src2 |= 0x20;
		short diff = src1 - src2;
		if (0 != diff) return diff;
		if (0 == src1) return 0;
	}
	return 0;
}

void
Win32String::MakeEmpty
(void)
{
	if (NULL != buf_a) delete buf_a;
	if (NULL != buf_w) delete buf_w;
	if (NULL != buf_u) delete buf_u;
	buf_a = NULL;
	buf_w = NULL;
	buf_u = NULL;
	len_a = len_w = len_u = 0;
	sourcetype = 0;
}

void
Win32String::AtoW
(void)
{
	AtoU();
	UtoW();
}

void
Win32String::AtoU
(void)
{
	// ANSI to UTF8
	if (NULL != buf_u) return;
	if (NULL == buf_a) return;
	int32 len = len_a * 3;
	buf_u = new char[len + 1];
	if (NULL == buf_u) return;
	int32 srcLen = len_a;
	int32 state = 0;
	if (B_OK != convert_to_utf8(B_SJIS_CONVERSION, buf_a, &srcLen, buf_u, &len, &state))
		DOUT("conversion failed\n");
	len_u = len;
	buf_u[len_u] = 0;
}

void
Win32String::WtoA
(void)
{
	WtoU();
	UtoA();
}

void
Win32String::WtoU
(void)
{
	// UCS2 to UTF8
	if (NULL != buf_u) return;
	if (NULL == buf_w) return;
	int32 len = len_w * 3;
	buf_u = new char[len + 1];
	if (NULL == buf_u) return;
	unsigned char *p = (unsigned char *)buf_u;
	unsigned short *q = (unsigned short *)buf_w;
	len_u = 0;
	do {
		unsigned short c = *q;
		if (c < 0x80) {
			*p++ = c;
			len_u++;
		} else if (c < 0x800) {
			*p++ = (c >> 6) | 0xc0;
			*p++ = (c & 0x3f) | 0x80;
			len_u += 2;
		} else {
			*p++ = (c >> 12) | 0xe0;
			*p++ = ((c >> 6) & 0x3f) | 0x80;
			*p++ = (c & 0x3f) | 0x80;
			len_u += 3;
		}
	} while (0 != *q++);
	len_u--;
}

void
Win32String::UtoA
(void)
{
	// UTF8 to ANSI
	if (NULL != buf_a) return;
	if (NULL == buf_u) return;
	int32 len = len_u;
	buf_a = new char[len + 1];
	if (NULL == buf_a) return;
	int32 srcLen = len_u;
	int32 state = 0;
	if (B_OK != convert_from_utf8(B_SJIS_CONVERSION, buf_u, &srcLen, buf_a, &len, &state))
		DOUT("conversion failed\n");
	len_a = len;
	buf_a[len_a] = 0;
}

void
Win32String::UtoW
(void)
{
	// UTF8 to UCS2
	if (NULL != buf_w) return;
	if (NULL == buf_u) return;
	int32 len = len_u;
	buf_w = new short[len + 1];
	if (NULL == buf_w) return;
	unsigned short *p = (unsigned short *)buf_w;
	unsigned char *q = (unsigned char *)buf_u;
	len_w = 0;
	do {
		unsigned char c1 = q[0];
		if (c1 < 0x80) {
			*p++ = c1;
		} else if (c1 < 0xe0) {
			*p++ = ((c1 & 0x1f) >> 2) | (q[1] & 0x3f);
			q++;
		} else {
			*p++ = ((c1 & 0x0f) << 12) | ((q[1] & 0x3f) << 6) | (q[2] & 0x3f);
			q += 2;
		}
		len_w++;
	} while (0 != *q++);
	len_w--;
}
