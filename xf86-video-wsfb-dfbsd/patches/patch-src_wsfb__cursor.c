$NetBSD$

--- src/wsfb_cursor.c.orig	2019-07-01 02:01:45.611659863 +0000
+++ src/wsfb_cursor.c
@@ -0,0 +1,191 @@
+/*
+ * Copyright (c) 2005 Michael Lorenz
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ *
+ *    - Redistributions of source code must retain the above copyright
+ *      notice, this list of conditions and the following disclaimer.
+ *    - Redistributions in binary form must reproduce the above
+ *      copyright notice, this list of conditions and the following
+ *      disclaimer in the documentation and/or other materials provided
+ *      with the distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
+ * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
+ * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
+ * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
+ * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
+ * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
+ * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
+ * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
+ * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
+ * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
+ * POSSIBILITY OF SUCH DAMAGE.
+ *
+ */
+
+/*
+ * Based on fbdev.c written by:
+ *
+ * Authors:  Alan Hourihane, <alanh@fairlite.demon.co.uk>
+ *	     Michel Dänzer, <michdaen@iiic.ethz.ch>
+ */
+
+#if defined(HWCURSOR_XSRC_NETBSD)
+
+#include <fcntl.h>
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/endian.h>
+#include <dev/wscons/wsconsio.h>
+#include <errno.h>
+
+/* all driver need this */
+#include "xf86.h"
+#include "xf86_OSproc.h"
+#include "xf86_OSlib.h"
+
+#include "wsfb.h"
+
+static void WsfbLoadCursorImage(ScrnInfoPtr pScrn, unsigned char *src);
+static void WsfbSetCursorPosition(ScrnInfoPtr pScrn, int x, int y);
+static void WsfbSetCursorColors(ScrnInfoPtr pScrn, int bg, int fg);
+
+static void
+WsfbLoadCursorImage(ScrnInfoPtr pScrn, unsigned char *src)
+{
+	WsfbPtr pWsfb = WSFBPTR(pScrn);
+	int err, i;
+	
+	pWsfb->cursor.which = WSDISPLAY_CURSOR_DOALL;
+	pWsfb->cursor.image = src;
+	pWsfb->cursor.mask = src + pWsfb->maskoffset;
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_SCURSOR, &pWsfb->cursor) == -1)
+		xf86Msg(X_ERROR, "WsfbLoadCursorImage: %d\n", errno);
+}
+
+void 
+WsfbShowCursor(ScrnInfoPtr pScrn)
+{
+	WsfbPtr pWsfb = WSFBPTR(pScrn);
+
+	pWsfb->cursor.which = WSDISPLAY_CURSOR_DOCUR;
+	pWsfb->cursor.enable = 1;
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_SCURSOR, &pWsfb->cursor) == -1)
+		xf86Msg(X_ERROR, "WsfbShowCursor: %d\n", errno);
+}
+
+void
+WsfbHideCursor(ScrnInfoPtr pScrn)
+{
+	WsfbPtr pWsfb = WSFBPTR(pScrn);
+
+	pWsfb->cursor.which = WSDISPLAY_CURSOR_DOCUR;
+	pWsfb->cursor.enable = 0;
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_SCURSOR, &pWsfb->cursor) == -1)
+		xf86Msg(X_ERROR, "WsfbHideCursor: %d\n", errno);
+}
+
+static void
+WsfbSetCursorPosition(ScrnInfoPtr pScrn, int x, int y)
+{
+	WsfbPtr pWsfb = WSFBPTR(pScrn);
+	int xoff = 0, yoff = 0;
+	
+	pWsfb->cursor.which = WSDISPLAY_CURSOR_DOPOS | WSDISPLAY_CURSOR_DOHOT;
+	
+	if (x < 0) {
+		xoff = -x;
+		x = 0;
+	}
+	if (y < 0) {
+		yoff = -y;
+		y = 0;
+	}
+	
+	pWsfb->cursor.pos.x = x;
+	pWsfb->cursor.hot.x = xoff;
+	pWsfb->cursor.pos.y = y;
+	pWsfb->cursor.hot.y = yoff;
+	
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_SCURSOR, &pWsfb->cursor) == -1)
+		xf86Msg(X_ERROR, "WsfbSetCursorPosition: %d\n", errno);
+}
+
+static void
+WsfbSetCursorColors(ScrnInfoPtr pScrn, int bg, int fg)
+{
+	WsfbPtr pWsfb = WSFBPTR(pScrn);
+	u_char r[4], g[4], b[4];
+	
+	pWsfb->cursor.which = WSDISPLAY_CURSOR_DOCMAP;
+	pWsfb->cursor.cmap.red = r;
+	pWsfb->cursor.cmap.green = g;
+	pWsfb->cursor.cmap.blue = b;
+	r[1] = fg & 0xff;
+	g[1] = (fg & 0xff00) >> 8;
+	b[1] = (fg & 0xff0000) >> 16;
+	r[0] = bg & 0xff;
+	g[0] = (bg & 0xff00) >> 8;
+	b[0] = (bg & 0xff0000) >> 16;
+	pWsfb->cursor.cmap.index = 0;
+	pWsfb->cursor.cmap.count = 2;
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_SCURSOR, &pWsfb->cursor) == -1)
+		xf86Msg(X_ERROR, "WsfbSetCursorColors: %d\n", errno);
+}
+
+Bool 
+WsfbSetupCursor(ScreenPtr pScreen)
+{
+	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	WsfbPtr pWsfb = WSFBPTR(pScrn);
+	xf86CursorInfoPtr infoPtr;
+	
+	pWsfb->cursor.pos.x = 0;
+	pWsfb->cursor.pos.y = 0;
+	pWsfb->cursor.enable = 0;
+
+	infoPtr = xf86CreateCursorInfoRec();
+	if(!infoPtr) return FALSE;
+    
+	pWsfb->CursorInfoRec = infoPtr;
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_GCURMAX, &pWsfb->cursor.size) == -1) {
+		xf86Msg(X_WARNING, "No HW cursor support found\n");
+		return FALSE;
+	}
+		
+	xf86Msg(X_INFO, "HW cursor enabled\n");
+
+	infoPtr->MaxWidth = pWsfb->cursor.size.x;
+	infoPtr->MaxHeight = pWsfb->cursor.size.y;
+	pWsfb->maskoffset = ( pWsfb->cursor.size.x >> 3) * pWsfb->cursor.size.y;
+	
+	pWsfb->cursor.hot.x = 0;
+	pWsfb->cursor.hot.y = 0;
+	pWsfb->cursor.which = WSDISPLAY_CURSOR_DOHOT | WSDISPLAY_CURSOR_DOCUR |
+	    WSDISPLAY_CURSOR_DOPOS;
+	if(ioctl(pWsfb->fd, WSDISPLAYIO_SCURSOR, &pWsfb->cursor) == -1)
+		xf86Msg(X_ERROR, "WSDISPLAYIO_SCURSOR: %d\n", errno);
+	
+	infoPtr->Flags = HARDWARE_CURSOR_AND_SOURCE_WITH_MASK |
+	    HARDWARE_CURSOR_TRUECOLOR_AT_8BPP
+/* XXX not sure why exactly we need this */
+#if BYTE_ORDER == BIG_ENDIAN
+	    | HARDWARE_CURSOR_BIT_ORDER_MSBFIRST
+#endif
+	;
+	infoPtr->SetCursorColors = WsfbSetCursorColors;
+	infoPtr->SetCursorPosition = WsfbSetCursorPosition;
+	infoPtr->LoadCursorImage = WsfbLoadCursorImage;
+	infoPtr->HideCursor = WsfbHideCursor;
+	infoPtr->ShowCursor = WsfbShowCursor;
+	infoPtr->UseHWCursor = NULL;
+
+	return xf86InitCursor(pScreen, infoPtr);
+}
+
+#endif /* HWCURSOR_XSRC_NETBSD */
