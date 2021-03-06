/*
   FreeRDP: A Remote Desktop Protocol client.
   RDP GDI Adaption Layer Unit Tests

   Copyright 2010 Marc-Andre Moreau <marcandre.moreau@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <freerdp/freerdp.h>
#include "gdi.h"
#include "test_libgdi.h"

int init_libgdi_suite(void)
{
	InitializeGDI();
	return 0;
}

int clean_libgdi_suite(void)
{
	return 0;
}

int add_libgdi_suite(void)
{
	add_test_suite(libgdi);

	add_test_function(GetDC);
	add_test_function(CreateCompatibleDC);
	add_test_function(CreateBitmap);
	add_test_function(CreateCompatibleBitmap);
	add_test_function(CreatePen);
	add_test_function(CreatePalette);
	add_test_function(CreateSolidBrush);
	add_test_function(CreatePatternBrush);
	add_test_function(CreateRectRgn);
	add_test_function(CreateRect);
	add_test_function(GetPixel);
	add_test_function(SetPixel);
	add_test_function(SetROP2);
	add_test_function(MoveToEx);
	add_test_function(LineTo);
	add_test_function(Ellipse);
	add_test_function(PtInRect);
	add_test_function(FillRect);
	add_test_function(BitBlt_32bpp);
	add_test_function(BitBlt_16bpp);
	add_test_function(BitBlt_8bpp);
	add_test_function(ClipCoords);
	add_test_function(InvalidateRegion);

	return 0;
}

/* BitBlt() Test Data */

/* source bitmap (16x16) */
unsigned char bmp_SRC[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* destination bitmap (16x16) */
unsigned char bmp_DST[256] =
{
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
};

/* pattern bitmap (8x8) */
unsigned char bmp_PAT[64] =
{
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
};

/* SRCCOPY (0x00CC0020) */
unsigned char bmp_SRCCOPY[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* BLACKNESS (0x00000042) */
unsigned char bmp_BLACKNESS[256] =
{
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
};

/* WHITENESS (0x00FF0062) */
unsigned char bmp_WHITENESS[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* SRCAND (0x008800C6) */
unsigned char bmp_SRCAND[256] =
{
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
};

/* SRCPAINT (0x00EE0086) */
unsigned char bmp_SRCPAINT[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* SRCINVERT (0x00660046) */
unsigned char bmp_SRCINVERT[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\x00\x00\x00\x00"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\x00\x00\x00\x00\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* SRCERASE (0x00440328) */
unsigned char bmp_SRCERASE[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* NOTSRCCOPY (0x00330008) */
unsigned char bmp_NOTSRCCOPY[256] =
{
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
};

/* NOTSRCERASE (0x001100A6) */
unsigned char bmp_NOTSRCERASE[256] =
{
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
};

/* DSTINVERT (0x00550009) */
unsigned char bmp_DSTINVERT[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* SPna (0x000C0324) */
unsigned char bmp_SPna[256] =
{
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
};

/* MERGEPAINT (0x00BB0226) */
unsigned char bmp_MERGEPAINT[256] =
{
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00"
};

/* MERGECOPY (0x00C000CA) */
unsigned char bmp_MERGECOPY[256] =
{
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\x00\x00\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
};

/* PATPAINT (0x00FB0A09) */
unsigned char bmp_PATPAINT[256] =
{
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
};

/* PATCOPY (0x00F00021) */
unsigned char bmp_PATCOPY[256] =
{
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
};

/* PATINVERT (0x005A0049) */
unsigned char bmp_PATINVERT[256] =
{
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\x00\x00\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\x00\x00"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\xFF\xFF\x00\x00\xFF\xFF"
};

/* LineTo() Test Data */

unsigned char line_to_case_1[256] =
{
	"\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_2[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00"
};

unsigned char line_to_case_3[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_4[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_5[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_6[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_7[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_8[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_9[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_10[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char line_to_case_11[256] =
{
	"\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00"
};

/* PolylineTo() Test Data */

unsigned char polyline_to_case_1[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF"
	"\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
};

unsigned char polyline_to_case_2[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* Ellipse() Test Data */

unsigned char ellipse_case_1[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF"
};

unsigned char ellipse_case_2[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
};

unsigned char ellipse_case_3[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

/* Polygon() Test Data */

unsigned char polygon_case_1[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF"
	"\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
	"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
};

unsigned char polygon_case_2[256] =
{
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
	"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"
};

int CompareBitmaps(HBITMAP hBmp1, HBITMAP hBmp2)
{
	int x, y;
	uint8 *p1, *p2;

	int minw = (hBmp1->width < hBmp2->width) ? hBmp1->width : hBmp2->width;
	int minh = (hBmp1->height < hBmp2->height) ? hBmp1->height : hBmp2->height;

	if (hBmp1->bitsPerPixel == hBmp2->bitsPerPixel)
	{
		p1 = hBmp1->data;
		p2 = hBmp2->data;
		int bpp = hBmp1->bitsPerPixel;

		if (bpp == 32)
		{
			for (y = 0; y < minh; y++)
			{
				for (x = 0; x < minw; x++)
				{
					if (*p1 != *p2)
						return 0;
					p1++;
					p2++;

					if (*p1 != *p2)
						return 0;
					p1++;
					p2++;

					if (*p1 != *p2)
						return 0;
					p1 += 2;
					p2 += 2;
				}
			}
		}
		else if (bpp == 16)
		{
			for (y = 0; y < minh; y++)
			{
				for (x = 0; x < minw; x++)
				{
					if (*p1 != *p2)
						return 0;
					p1++;
					p2++;

					if (*p1 != *p2)
						return 0;
					p1++;
					p2++;
				}
			}
		}
		else if (bpp == 8)
		{
			for (y = 0; y < minh; y++)
			{
				for (x = 0; x < minw; x++)
				{
					if (*p1 != *p2)
						return 0;
					p1++;
					p2++;
				}
			}
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

void dump_bitmap(HBITMAP hBmp, char* name)
{
	dump_data(hBmp->data, hBmp->width * hBmp->height * hBmp->bytesPerPixel, hBmp->width * hBmp->bytesPerPixel, name);
}

void assertBitmapsEqual(HBITMAP hBmpActual, HBITMAP hBmpExpected, char *name)
{
	int bitmapsEqual = CompareBitmaps(hBmpActual, hBmpExpected);

	if (bitmapsEqual != 1)
	{
		printf("\n%s\n", name);
		dump_bitmap(hBmpActual, "Actual");
		dump_bitmap(hBmpExpected, "Expected");
	}

	CU_ASSERT(bitmapsEqual == 1);
}

void test_GetDC(void)
{
	HDC hdc = GetDC();
	CU_ASSERT(hdc->bytesPerPixel == 4);
	CU_ASSERT(hdc->bitsPerPixel == 32);
	CU_ASSERT(hdc->drawMode == R2_COPYPEN);
}

void test_CreateCompatibleDC(void)
{
	HDC hdc;
	HDC chdc;
 
	hdc = GetDC();
	hdc->bytesPerPixel = 2;
	hdc->bitsPerPixel = 16;
	hdc->drawMode = R2_XORPEN;

	chdc = CreateCompatibleDC(hdc);

	CU_ASSERT(chdc->bytesPerPixel == hdc->bytesPerPixel);
	CU_ASSERT(chdc->bitsPerPixel == hdc->bitsPerPixel);
	CU_ASSERT(chdc->drawMode == hdc->drawMode);
}

void test_CreateBitmap(void)
{
	int bpp;
	int width;
	int height;
	uint8* data;
	HBITMAP hBitmap;
	
	bpp = 32;
	width = 32;
	height = 16;
	data = (uint8*) malloc(width * height * 4);
	hBitmap = CreateBitmap(width, height, bpp, data);

	CU_ASSERT(hBitmap->objectType == GDIOBJ_BITMAP);
	CU_ASSERT(hBitmap->bitsPerPixel == bpp);
	CU_ASSERT(hBitmap->width == width);
	CU_ASSERT(hBitmap->height == height);
	CU_ASSERT(hBitmap->data == data);

	DeleteObject((HGDIOBJ) hBitmap);
}

void test_CreateCompatibleBitmap(void)
{
	HDC hdc;
	int width;
	int height;
	HBITMAP hBitmap;
	
	hdc = GetDC();
	hdc->bytesPerPixel = 4;
	hdc->bitsPerPixel = 32;

	width = 32;
	height = 16;
	hBitmap = CreateCompatibleBitmap(hdc, width, height);

	CU_ASSERT(hBitmap->objectType == GDIOBJ_BITMAP);
	CU_ASSERT(hBitmap->bytesPerPixel == hdc->bytesPerPixel);
	CU_ASSERT(hBitmap->bitsPerPixel == hdc->bitsPerPixel);
	CU_ASSERT(hBitmap->width == width);
	CU_ASSERT(hBitmap->height == height);
	CU_ASSERT(hBitmap->data != NULL);

	DeleteObject((HGDIOBJ) hBitmap);
}

void test_CreatePen(void)
{
	HPEN hPen = CreatePen(PS_SOLID, 8, 0xAABBCCDD);
	CU_ASSERT(hPen->style == PS_SOLID);
	CU_ASSERT(hPen->width == 8);
	CU_ASSERT(hPen->color == 0xAABBCCDD);
	DeleteObject((HGDIOBJ) hPen);
}

void test_CreatePalette(void)
{
	HPALETTE hPalette;
	LOGPALETTE *logicalPalette;

	logicalPalette = (LOGPALETTE*) malloc(sizeof(LOGPALETTE));
	logicalPalette->entries = (PALETTEENTRY*) malloc(sizeof(PALETTEENTRY) * 256);
	memset(logicalPalette->entries, 0, sizeof(PALETTEENTRY) * 256);
	logicalPalette->count = 5;

	hPalette = CreatePalette(logicalPalette);
	CU_ASSERT(hPalette->objectType == GDIOBJ_PALETTE);
	CU_ASSERT(hPalette->logicalPalette == logicalPalette);
	DeleteObject((HGDIOBJ) hPalette);
}

void test_CreateSolidBrush(void)
{
	HBRUSH hBrush = CreateSolidBrush(0xAABBCCDD);
	CU_ASSERT(hBrush->objectType == GDIOBJ_BRUSH);
	CU_ASSERT(hBrush->style == BS_SOLID);
	CU_ASSERT(hBrush->color == 0xAABBCCDD);
	DeleteObject((HGDIOBJ) hBrush);
}

void test_CreatePatternBrush(void)
{
	HBRUSH hBrush;
	HBITMAP hBitmap;

	hBitmap = CreateBitmap(64, 64, 32, NULL);
	hBrush = CreatePatternBrush(hBitmap);

	CU_ASSERT(hBrush->objectType == GDIOBJ_BRUSH);
	CU_ASSERT(hBrush->style == BS_PATTERN);
	CU_ASSERT(hBrush->pattern == hBitmap);

	DeleteObject((HGDIOBJ) hBrush);
	DeleteObject((HGDIOBJ) hBitmap);
}

void test_CreateRectRgn(void)
{
	int x1 = 32;
	int y1 = 64;
	int x2 = 128;
	int y2 = 256;

	HRGN hRegion = CreateRectRgn(x1, y1, x2, y2);

	CU_ASSERT(hRegion->objectType == GDIOBJ_REGION);
	CU_ASSERT(hRegion->x == x1);
	CU_ASSERT(hRegion->y == y1);
	CU_ASSERT(hRegion->w == x2 - x1 + 1);
	CU_ASSERT(hRegion->h == y2 - y1 + 1);
	CU_ASSERT(hRegion->null == 0);

	DeleteObject((HGDIOBJ) hRegion);
}

void test_CreateRect(void)
{
	int x1 = 32;
	int y1 = 64;
	int x2 = 128;
	int y2 = 256;

	HRECT hRect = CreateRect(x1, y1, x2, y2);

	CU_ASSERT(hRect->objectType == GDIOBJ_RECT);
	CU_ASSERT(hRect->left == x1);
	CU_ASSERT(hRect->top == y1);
	CU_ASSERT(hRect->right == x2);
	CU_ASSERT(hRect->bottom == y2);

	DeleteObject((HGDIOBJ) hRect);
}

void test_GetPixel(void)
{
	HDC hdc;
	int width = 128;
	int height = 64;
	HBITMAP hBitmap;

	hdc = GetDC();
	hdc->bytesPerPixel = 4;
	hdc->bitsPerPixel = 32;
	
	hBitmap = CreateCompatibleBitmap(hdc, width, height);
	SelectObject(hdc, (HGDIOBJ) hBitmap);

	hBitmap->data[(64 * width * 4) + 32 * 4 + 0] = 0xDD;
	hBitmap->data[(64 * width * 4) + 32 * 4 + 1] = 0xCC;
	hBitmap->data[(64 * width * 4) + 32 * 4 + 2] = 0xBB;
	hBitmap->data[(64 * width * 4) + 32 * 4 + 3] = 0xAA;

	CU_ASSERT(GetPixel(hdc, 32, 64) == 0xAABBCCDD);

	DeleteObject((HGDIOBJ) hBitmap);
}

void test_SetPixel(void)
{
	HDC hdc;
	int width = 128;
	int height = 64;
	HBITMAP hBitmap;

	hdc = GetDC();
	hdc->bytesPerPixel = 4;
	hdc->bitsPerPixel = 32;
	
	hBitmap = CreateCompatibleBitmap(hdc, width, height);
	SelectObject(hdc, (HGDIOBJ) hBitmap);

	SetPixel(hdc, 32, 64, 0xAABBCCDD);
	CU_ASSERT(GetPixel(hdc, 32, 64) == 0xAABBCCDD);

	SetPixel(hdc, width - 1, height - 1, 0xAABBCCDD);
	CU_ASSERT(GetPixel(hdc, width - 1, height - 1) == 0xAABBCCDD);

	DeleteObject((HGDIOBJ) hBitmap);
}

void test_SetROP2(void)
{
	HDC hdc = GetDC();
	SetROP2(hdc, R2_BLACK);
	CU_ASSERT(hdc->drawMode == R2_BLACK);
}

void test_MoveToEx(void)
{
	HDC hdc;
	HPEN hPen;
	HPOINT prevPoint;

	hdc = GetDC();
	hPen = CreatePen(PS_SOLID, 8, 0xAABBCCDD);
	SelectObject(hdc, (HGDIOBJ) hPen);
	MoveToEx(hdc, 128, 256, NULL);

	CU_ASSERT(hdc->pen->posX == 128);
	CU_ASSERT(hdc->pen->posY == 256);

	prevPoint = (HPOINT) malloc(sizeof(POINT));
	memset(prevPoint, '\0', sizeof(POINT));

	MoveToEx(hdc, 64, 128, prevPoint);

	CU_ASSERT(prevPoint->x == 128);
	CU_ASSERT(prevPoint->y == 256);
	CU_ASSERT(hdc->pen->posX == 64);
	CU_ASSERT(hdc->pen->posY == 128);
}

void test_LineTo(void)
{
	HDC hdc;
	HPEN pen;
	uint8* data;
	HBITMAP hBmp;
	HBITMAP hBmp_LineTo_1;
	HBITMAP hBmp_LineTo_2;
	HBITMAP hBmp_LineTo_3;
	HBITMAP hBmp_LineTo_4;
	HBITMAP hBmp_LineTo_5;
	HBITMAP hBmp_LineTo_6;
	HBITMAP hBmp_LineTo_7;
	HBITMAP hBmp_LineTo_8;
	HBITMAP hBmp_LineTo_9;
	HBITMAP hBmp_LineTo_10;
	HBITMAP hBmp_LineTo_11;
	HPALETTE hPalette;
	int bitsPerPixel = 8;
	int bytesPerPixel = 1;

	hdc = GetDC();
	hdc->bitsPerPixel = bitsPerPixel;
	hdc->bytesPerPixel = bytesPerPixel;
	SetNullClipRgn(hdc);

	pen = CreatePen(1, 1, 0);
	SelectObject(hdc, (HGDIOBJ) pen);

	hBmp = CreateCompatibleBitmap(hdc, 16, 16);
	SelectObject(hdc, (HGDIOBJ) hBmp);

	hPalette = GetSystemPalette();

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_1, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_1 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_2, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_2 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_3, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_3 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_4, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_4 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_5, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_5 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_5, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_5 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_6, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_6 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_7, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_7 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_8, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_8 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_9, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_9 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_10, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_10 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) line_to_case_11, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_LineTo_11 = CreateBitmap(16, 16, bitsPerPixel, data);

	/* Test Case 1: (0,0) -> (15, 15) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 15, 15);
	assertBitmapsEqual(hBmp, hBmp_LineTo_1, "Case 1");

	/* Test Case 2: (15,15) -> (0,0) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 15, 15, NULL);
	LineTo(hdc, 0, 0);
	assertBitmapsEqual(hBmp, hBmp_LineTo_2, "Case 2");

	/* Test Case 3: (15,0) -> (0,15) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 15, 0, NULL);
	LineTo(hdc, 0, 15);
	assertBitmapsEqual(hBmp, hBmp_LineTo_3, "Case 3");

	/* Test Case 4: (0,15) -> (15,0) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 0, 15, NULL);
	LineTo(hdc, 15, 0);
	assertBitmapsEqual(hBmp, hBmp_LineTo_4, "Case 4");

	/* Test Case 4: (0,15) -> (15,0) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 0, 15, NULL);
	LineTo(hdc, 15, 0);
	assertBitmapsEqual(hBmp, hBmp_LineTo_4, "Case 4");

	/* Test Case 5: (0,8) -> (15,8) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 0, 8, NULL);
	LineTo(hdc, 15, 8);
	assertBitmapsEqual(hBmp, hBmp_LineTo_5, "Case 5");

	/* Test Case 6: (15,8) -> (0,8) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 15, 8, NULL);
	LineTo(hdc, 0, 8);
	assertBitmapsEqual(hBmp, hBmp_LineTo_6, "Case 6");

	/* Test Case 7: (8,0) -> (8,15) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 8, 0, NULL);
	LineTo(hdc, 8, 15);
	assertBitmapsEqual(hBmp, hBmp_LineTo_7, "Case 7");

	/* Test Case 8: (8,15) -> (8,0) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 8, 15, NULL);
	LineTo(hdc, 8, 0);
	assertBitmapsEqual(hBmp, hBmp_LineTo_8, "Case 8");

	/* Test Case 9: (4,4) -> (12,12) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 4, 4, NULL);
	LineTo(hdc, 12, 12);
	assertBitmapsEqual(hBmp, hBmp_LineTo_9, "Case 9");

	/* Test Case 10: (12,12) -> (4,4) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	MoveToEx(hdc, 12, 12, NULL);
	LineTo(hdc, 4, 4);
	assertBitmapsEqual(hBmp, hBmp_LineTo_10, "Case 10");

	/* Test Case 11: (0,0) -> (+10,+10) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	SetClipRgn(hdc, 0, 0, 16, 16);
	MoveToEx(hdc, 0, 0, NULL);
	LineTo(hdc, 16 + 10, 16 + 10);
	assertBitmapsEqual(hBmp, hBmp_LineTo_11, "Case 11");
}

void test_Ellipse(void)
{
	HDC hdc;
	HPEN pen;
	uint8* data;
	HBITMAP hBmp;
	HBITMAP hBmp_Ellipse_1;
	HBITMAP hBmp_Ellipse_2;
	HBITMAP hBmp_Ellipse_3;
	HPALETTE hPalette;
	int bitsPerPixel = 8;
	int bytesPerPixel = 1;

	hdc = GetDC();
	hdc->bitsPerPixel = bitsPerPixel;
	hdc->bytesPerPixel = bytesPerPixel;
	SetNullClipRgn(hdc);

	pen = CreatePen(1, 1, 0);
	SelectObject(hdc, (HGDIOBJ) pen);

	hBmp = CreateCompatibleBitmap(hdc, 16, 16);
	SelectObject(hdc, (HGDIOBJ) hBmp);

	hPalette = GetSystemPalette();

	data = (uint8*) gdi_image_convert((uint8*) ellipse_case_1, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_Ellipse_1 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) ellipse_case_2, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_Ellipse_2 = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) ellipse_case_3, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_Ellipse_3 = CreateBitmap(16, 16, bitsPerPixel, data);

	/* Test Case 1: (0,0) -> (16, 16) */
	BitBlt(hdc, 0, 0, 16, 16, hdc, 0, 0, WHITENESS);
	Ellipse(hdc, 0, 0, 16, 16);
	//assertBitmapsEqual(hBmp, hBmp_Ellipse_1, "Case 1");
}

void test_PtInRect(void)
{
	HRECT hRect;
	int left = 20;
	int top = 40;
	int right = 60;
	int bottom = 80;

	hRect = CreateRect(left, top, right, bottom);

	CU_ASSERT(PtInRect(hRect, 0, 0) == 0);
	CU_ASSERT(PtInRect(hRect, 500, 500) == 0);
	CU_ASSERT(PtInRect(hRect, 40, 100) == 0);
	CU_ASSERT(PtInRect(hRect, 10, 40) == 0);
	CU_ASSERT(PtInRect(hRect, 30, 50) == 1);
	CU_ASSERT(PtInRect(hRect, left, top) == 1);
	CU_ASSERT(PtInRect(hRect, right, bottom) == 1);
	CU_ASSERT(PtInRect(hRect, right, 60) == 1);
	CU_ASSERT(PtInRect(hRect, 40, bottom) == 1);
}

void test_FillRect(void)
{
	HDC hdc;
	HRECT hRect;
	HBRUSH hBrush;
	HBITMAP hBitmap;
	COLORREF color;

	int x, y;
	int badPixels;
	int goodPixels;
	int width = 200;
	int height = 300;

	int left = 20;
	int top = 40;
	int right = 60;
	int bottom = 80;

	hdc = GetDC();
	hdc->bytesPerPixel = 4;
	hdc->bitsPerPixel = 32;

	hRect = CreateRect(left, top, right, bottom);

	hBitmap = CreateCompatibleBitmap(hdc, width, height);
	memset(hBitmap->data, 0, width * height * hdc->bytesPerPixel);
	SelectObject(hdc, (HGDIOBJ) hBitmap);

	color = (COLORREF) RGB(0xAA, 0xBB, 0xCC);
	hBrush = CreateSolidBrush(color);

	FillRect(hdc, hRect, hBrush);

	badPixels = 0;
	goodPixels = 0;

	for (x = 0; x < width; x++)
	{
		for (y = 0; y < height; y++)
		{
			if (PtInRect(hRect, x, y))
			{
				if (GetPixel(hdc, x, y) == color) {
					goodPixels++;
				}
				else {
					badPixels++;
				}
			}
			else
			{
				if (GetPixel(hdc, x, y) == color) {
					badPixels++;
				}
				else {
					goodPixels++;
				}
			}
		}
	}

	CU_ASSERT(goodPixels == width * height);
	CU_ASSERT(badPixels == 0);

	DeleteObject((HGDIOBJ) hBrush);
	DeleteObject((HGDIOBJ) hBitmap);
}

void test_BitBlt_32bpp(void)
{
	uint8* data;
	HDC hdcSrc;
	HDC hdcDst;
	HBRUSH hBrush;
	HBITMAP hBmpSrc;
	HBITMAP hBmpDst;
	HBITMAP hBmpPat;
	HBITMAP hBmp_SPna;
	HBITMAP hBmp_BLACKNESS;
	HBITMAP hBmp_WHITENESS;
	HBITMAP hBmp_SRCCOPY;
	HBITMAP hBmp_SRCAND;
	HBITMAP hBmp_SRCPAINT;
	HBITMAP hBmp_SRCINVERT;
	HBITMAP hBmp_SRCERASE;
	HBITMAP hBmp_NOTSRCCOPY;
	HBITMAP hBmp_NOTSRCERASE;
	HBITMAP hBmp_DSTINVERT;
	HBITMAP hBmp_MERGECOPY;
	HBITMAP hBmp_MERGEPAINT;
	HBITMAP hBmp_PATCOPY;
	HBITMAP hBmp_PATPAINT;
	HBITMAP hBmp_PATINVERT;
	HBITMAP hBmpDstOriginal;
	HPALETTE hPalette;

	int bytesPerPixel = 4;
	int bitsPerPixel = 32;
	
	hdcSrc = GetDC();
	hdcSrc->bytesPerPixel = bytesPerPixel;
	hdcSrc->bitsPerPixel = bitsPerPixel;

	hdcDst = GetDC();
	hdcDst->bytesPerPixel = bytesPerPixel;
	hdcDst->bitsPerPixel = bitsPerPixel;

	hPalette = GetSystemPalette();

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRC, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpSrc = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DST, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpDst = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DST, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpDstOriginal = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PAT, 8, 8, 8, bitsPerPixel, hPalette);
	hBmpPat = CreateBitmap(8, 8, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SPna, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SPna = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_BLACKNESS, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_BLACKNESS = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_WHITENESS, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_WHITENESS = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCAND, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCAND = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCERASE, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCERASE = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_NOTSRCCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_NOTSRCCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_NOTSRCERASE, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_NOTSRCERASE = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DSTINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_DSTINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_MERGECOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_MERGECOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_MERGEPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_MERGEPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATINVERT = CreateBitmap(16, 16, bitsPerPixel, data);
	
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	SelectObject(hdcDst, (HGDIOBJ) hBmpDst);

	/* SRCCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCCOPY) == 1)

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
		
	/* BLACKNESS */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, BLACKNESS);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_BLACKNESS) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* WHITENESS */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, WHITENESS);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_WHITENESS) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SRCAND */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCAND);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCAND) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SRCPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCPAINT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SRCINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCINVERT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SRCERASE */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCERASE);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCERASE) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* NOTSRCCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, NOTSRCCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_NOTSRCCOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* NOTSRCERASE */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, NOTSRCERASE);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_NOTSRCERASE) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* DSTINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, DSTINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_DSTINVERT) == 1);

	/* select a brush for operations using a pattern */
	hBrush = CreatePatternBrush(hBmpPat);
	SelectObject(hdcDst, (HGDIOBJ) hBrush);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* MERGECOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, MERGECOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_MERGECOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* MERGEPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, MERGEPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_MERGEPAINT) == 1);
	
	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* PATCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATCOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* PATINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATINVERT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* PATPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATPAINT) == 1);
	
	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SPna */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SPna);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SPna) == 1)
}

void test_BitBlt_16bpp(void)
{
	uint8* data;
	HDC hdcSrc;
	HDC hdcDst;
	HBRUSH hBrush;
	HBITMAP hBmpSrc;
	HBITMAP hBmpDst;
	HBITMAP hBmpPat;
	HBITMAP hBmp_SPna;
	HBITMAP hBmp_BLACKNESS;
	HBITMAP hBmp_WHITENESS;
	HBITMAP hBmp_SRCCOPY;
	HBITMAP hBmp_SRCAND;
	HBITMAP hBmp_SRCPAINT;
	HBITMAP hBmp_SRCINVERT;
	HBITMAP hBmp_SRCERASE;
	HBITMAP hBmp_NOTSRCCOPY;
	HBITMAP hBmp_NOTSRCERASE;
	HBITMAP hBmp_DSTINVERT;
	HBITMAP hBmp_MERGECOPY;
	HBITMAP hBmp_MERGEPAINT;
	HBITMAP hBmp_PATCOPY;
	HBITMAP hBmp_PATPAINT;
	HBITMAP hBmp_PATINVERT;
	HBITMAP hBmpDstOriginal;
	HPALETTE hPalette;

	int bytesPerPixel = 2;
	int bitsPerPixel = 16;
	
	hdcSrc = GetDC();
	hdcSrc->bytesPerPixel = bytesPerPixel;
	hdcSrc->bitsPerPixel = bitsPerPixel;

	hdcDst = GetDC();
	hdcDst->bytesPerPixel = bytesPerPixel;
	hdcDst->bitsPerPixel = bitsPerPixel;

	hPalette = GetSystemPalette();

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRC, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpSrc = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DST, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpDst = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DST, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpDstOriginal = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PAT, 8, 8, 8, bitsPerPixel, hPalette);
	hBmpPat = CreateBitmap(8, 8, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SPna, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SPna = CreateBitmap(16, 16, bitsPerPixel, data);
	
	data = (uint8*) gdi_image_convert((uint8*) bmp_BLACKNESS, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_BLACKNESS = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_WHITENESS, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_WHITENESS = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCAND, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCAND = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCERASE, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCERASE = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_NOTSRCCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_NOTSRCCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_NOTSRCERASE, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_NOTSRCERASE = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DSTINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_DSTINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_MERGECOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_MERGECOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_MERGEPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_MERGEPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATINVERT = CreateBitmap(16, 16, bitsPerPixel, data);
	
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	SelectObject(hdcDst, (HGDIOBJ) hBmpDst);

	/* SRCCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCCOPY) == 1)

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
		
	/* BLACKNESS */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, BLACKNESS);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_BLACKNESS) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* WHITENESS */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, WHITENESS);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_WHITENESS) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SRCAND */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCAND);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCAND) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SRCPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCPAINT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SRCINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCINVERT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SRCERASE */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCERASE);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCERASE) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* NOTSRCCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, NOTSRCCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_NOTSRCCOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* NOTSRCERASE */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, NOTSRCERASE);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_NOTSRCERASE) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* DSTINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, DSTINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_DSTINVERT) == 1);

	/* select a brush for operations using a pattern */
	hBrush = CreatePatternBrush(hBmpPat);
	SelectObject(hdcDst, (HGDIOBJ) hBrush);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* MERGECOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, MERGECOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_MERGECOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* MERGEPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, MERGEPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_MERGEPAINT) == 1);
	
	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* PATCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATCOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* PATINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATINVERT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* PATPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATPAINT) == 1);
	
	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	
	/* SPna */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SPna);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SPna) == 1)
}

void test_BitBlt_8bpp(void)
{
	uint8* data;
	HDC hdcSrc;
	HDC hdcDst;
	HBRUSH hBrush;
	HBITMAP hBmpSrc;
	HBITMAP hBmpDst;
	HBITMAP hBmpPat;
	HBITMAP hBmp_SPna;
	HBITMAP hBmp_BLACKNESS;
	HBITMAP hBmp_WHITENESS;
	HBITMAP hBmp_SRCCOPY;
	HBITMAP hBmp_SRCAND;
	HBITMAP hBmp_SRCPAINT;
	HBITMAP hBmp_SRCINVERT;
	HBITMAP hBmp_SRCERASE;
	HBITMAP hBmp_NOTSRCCOPY;
	HBITMAP hBmp_NOTSRCERASE;
	HBITMAP hBmp_DSTINVERT;
	HBITMAP hBmp_MERGECOPY;
	HBITMAP hBmp_MERGEPAINT;
	HBITMAP hBmp_PATCOPY;
	HBITMAP hBmp_PATPAINT;
	HBITMAP hBmp_PATINVERT;
	HBITMAP hBmpDstOriginal;
	HPALETTE hPalette;

	int bytesPerPixel = 1;
	int bitsPerPixel = 8;

	hdcSrc = GetDC();
	hdcSrc->bytesPerPixel = bytesPerPixel;
	hdcSrc->bitsPerPixel = bitsPerPixel;

	hdcDst = GetDC();
	hdcDst->bytesPerPixel = bytesPerPixel;
	hdcDst->bitsPerPixel = bitsPerPixel;

	hPalette = GetSystemPalette();

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRC, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpSrc = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DST, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpDst = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DST, 16, 16, 8, bitsPerPixel, hPalette);
	hBmpDstOriginal = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PAT, 8, 8, 8, bitsPerPixel, hPalette);
	hBmpPat = CreateBitmap(8, 8, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SPna, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SPna = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_BLACKNESS, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_BLACKNESS = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_WHITENESS, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_WHITENESS = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCAND, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCAND = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_SRCERASE, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_SRCERASE = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_NOTSRCCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_NOTSRCCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_NOTSRCERASE, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_NOTSRCERASE = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_DSTINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_DSTINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_MERGECOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_MERGECOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_MERGEPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_MERGEPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATCOPY, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATCOPY = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATPAINT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATPAINT = CreateBitmap(16, 16, bitsPerPixel, data);

	data = (uint8*) gdi_image_convert((uint8*) bmp_PATINVERT, 16, 16, 8, bitsPerPixel, hPalette);
	hBmp_PATINVERT = CreateBitmap(16, 16, bitsPerPixel, data);

	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);
	SelectObject(hdcDst, (HGDIOBJ) hBmpDst);

	/* SRCCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCCOPY) == 1)

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* BLACKNESS */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, BLACKNESS);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_BLACKNESS) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* WHITENESS */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, WHITENESS);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_WHITENESS) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SRCAND */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCAND);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCAND) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SRCPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCPAINT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SRCINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCINVERT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SRCERASE */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCERASE);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SRCERASE) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* NOTSRCCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, NOTSRCCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_NOTSRCCOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* NOTSRCERASE */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, NOTSRCERASE);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_NOTSRCERASE) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* DSTINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, DSTINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_DSTINVERT) == 1);

	/* select a brush for operations using a pattern */
	hBrush = CreatePatternBrush(hBmpPat);
	SelectObject(hdcDst, (HGDIOBJ) hBrush);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* MERGECOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, MERGECOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_MERGECOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* MERGEPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, MERGEPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_MERGEPAINT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* PATCOPY */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATCOPY);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATCOPY) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* PATINVERT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATINVERT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATINVERT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* PATPAINT */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, PATPAINT);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_PATPAINT) == 1);

	/* restore original destination bitmap */
	SelectObject(hdcSrc, (HGDIOBJ) hBmpDstOriginal);
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SRCCOPY);
	SelectObject(hdcSrc, (HGDIOBJ) hBmpSrc);

	/* SPna */
	BitBlt(hdcDst, 0, 0, 16, 16, hdcSrc, 0, 0, SPna);
	CU_ASSERT(CompareBitmaps(hBmpDst, hBmp_SPna) == 1)
}

void test_ClipCoords(void)
{
	HDC hdc;
	HRGN rgn1;
	HRGN rgn2;
	HBITMAP bmp;
	int draw;
	
	hdc = GetDC();
	hdc->bytesPerPixel = 4;
	hdc->bitsPerPixel = 32;
	bmp = CreateBitmap(1024, 768, 4, NULL);
	SelectObject(hdc, (HGDIOBJ) bmp);
	SetNullClipRgn(hdc);

	rgn1 = CreateRectRgn(0, 0, 0, 0);
	rgn2 = CreateRectRgn(0, 0, 0, 0);
	rgn1->null = 1;
	rgn2->null = 1;

	/* null clipping region */
	SetNullClipRgn(hdc);
	SetRgn(rgn1, 20, 20, 100, 100);
	SetRgn(rgn2, 20, 20, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);

	/* region all inside clipping region */
	SetClipRgn(hdc, 0, 0, 1024, 768);
	SetRgn(rgn1, 20, 20, 100, 100);
	SetRgn(rgn2, 20, 20, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);

	/* region all outside clipping region, on the left */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 20, 20, 100, 100);
	SetRgn(rgn2, 0, 0, 0, 0);

	draw = ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(draw == 0);

	/* region all outside clipping region, on the right */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 420, 420, 100, 100);
	SetRgn(rgn2, 0, 0, 0, 0);

	draw = ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(draw == 0);

	/* region all outside clipping region, on top */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 20, 100, 100);
	SetRgn(rgn2, 0, 0, 0, 0);

	draw = ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(draw == 0);

	/* region all outside clipping region, at the bottom */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 420, 100, 100);
	SetRgn(rgn2, 0, 0, 0, 0);

	draw = ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(draw == 0);

	/* left outside, right = clip, top = clip, bottom = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 100, 300, 300, 100);
	SetRgn(rgn2, 300, 300, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);

	/* left outside, right inside, top = clip, bottom = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 100, 300, 250, 100);
	SetRgn(rgn2, 300, 300, 50, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);	
	
	/* left = clip, right outside, top = clip, bottom = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 300, 300, 100);
	SetRgn(rgn2, 300, 300, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);

	/* left inside, right outside, top = clip, bottom = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 350, 300, 200, 100);
	SetRgn(rgn2, 350, 300, 50, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);

	/* top outside, bottom = clip, left = clip, right = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 100, 300, 300);
	SetRgn(rgn2, 300, 300, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);

	/* top = clip, bottom outside, left = clip, right = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 300, 100, 200);
	SetRgn(rgn2, 300, 300, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);
	
	/* top = clip, bottom = clip, top = clip, bottom = clip */
	SetClipRgn(hdc, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 300, 100, 100);
	SetRgn(rgn2, 300, 300, 100, 100);

	ClipCoords(hdc, &(rgn1->x), &(rgn1->y), &(rgn1->w), &(rgn1->h), NULL, NULL);
	CU_ASSERT(EqualRgn(rgn1, rgn2) == 1);
	
	/*printf("\n");
	printf("clip: x:%d y:%d w:%d h:%d\n", hdc->clip->x, hdc->clip->y, hdc->clip->w, hdc->clip->h);
	printf("rgn1: x:%d y:%d w:%d h:%d\n", rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	printf("rgn2: x:%d y:%d w:%d h:%d\n", rgn2->x, rgn2->y, rgn2->w, rgn2->h);*/
}

void test_InvalidateRegion(void)
{
	HDC hdc;
	HRGN rgn1;
	HRGN rgn2;
	HRGN invalid;
	HBITMAP bmp;
	
	hdc = GetDC();
	hdc->bytesPerPixel = 4;
	hdc->bitsPerPixel = 32;
	bmp = CreateBitmap(1024, 768, 4, NULL);
	SelectObject(hdc, (HGDIOBJ) bmp);
	SetNullClipRgn(hdc);

	hdc->hwnd = (HWND) malloc(sizeof(WND));
	hdc->hwnd->invalid = CreateRectRgn(0, 0, 0, 0);
	hdc->hwnd->invalid->null = 1;
	invalid = hdc->hwnd->invalid;
	
	rgn1 = CreateRectRgn(0, 0, 0, 0);
	rgn2 = CreateRectRgn(0, 0, 0, 0);
	rgn1->null = 1;
	rgn2->null = 1;

	/* no previous invalid region */
	invalid->null = 1;
	SetRgn(rgn1, 300, 300, 100, 100);
	SetRgn(rgn2, 300, 300, 100, 100);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* region same as invalid region */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 300, 100, 100);
	SetRgn(rgn2, 300, 300, 100, 100);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* left outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 100, 300, 300, 100);
	SetRgn(rgn2, 100, 300, 300, 100);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* right outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 300, 300, 100);
	SetRgn(rgn2, 300, 300, 300, 100);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* top outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 100, 100, 300);
	SetRgn(rgn2, 300, 100, 100, 300);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* bottom outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 300, 100, 300);
	SetRgn(rgn2, 300, 300, 100, 300);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* left outside, right outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 100, 300, 600, 300);
	SetRgn(rgn2, 100, 300, 600, 300);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* top outside, bottom outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 100, 100, 500);
	SetRgn(rgn2, 300, 100, 100, 500);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* all outside, left */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 100, 300, 100, 100);
	SetRgn(rgn2, 100, 300, 300, 100);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* all outside, right */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 700, 300, 100, 100);
	SetRgn(rgn2, 300, 300, 500, 100);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* all outside, top */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 100, 100, 100);
	SetRgn(rgn2, 300, 100, 100, 300);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* all outside, bottom */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 300, 500, 100, 100);
	SetRgn(rgn2, 300, 300, 100, 300);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* all outside */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 100, 100, 600, 600);
	SetRgn(rgn2, 100, 100, 600, 600);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);

	/* everything */
	SetRgn(invalid, 300, 300, 100, 100);
	SetRgn(rgn1, 0, 0, 1024, 768);
	SetRgn(rgn2, 0, 0, 1024, 768);

	InvalidateRegion(hdc, rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	CU_ASSERT(EqualRgn(invalid, rgn2) == 1);
	
	/*
	printf("\n");
	printf("invalid: x:%d y:%d w:%d h:%d\n", invalid->x, invalid->y, invalid->w, invalid->h);
	printf("rgn1: x:%d y:%d w:%d h:%d\n", rgn1->x, rgn1->y, rgn1->w, rgn1->h);
	printf("rgn2: x:%d y:%d w:%d h:%d\n", rgn2->x, rgn2->y, rgn2->w, rgn2->h);*/
}
