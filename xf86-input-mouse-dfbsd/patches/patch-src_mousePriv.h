$NetBSD$

Patches from FreeBSD ports / DragonFly dports with include guards.
Support for different versions of system libusb headers.

--- src/mousePriv.h.orig	2012-05-28 00:01:45.000000000 +0000
+++ src/mousePriv.h
@@ -2,6 +2,14 @@
  * Copyright (c) 1997-1999 by The XFree86 Project, Inc.
  */
 
+/* PKGSRC note: To support newer versions of DragonFly and FreeBSD,
+ * this file is patched using DragonFly dports
+ * x11-drivers/xf86-input-mouse/files/patch-src_mousePriv.h
+ * as of master commit 4f04bfe0ea83 ... Tue Jul 14 22:56:44 2015 -0700
+ * The patch's code is enclosed in include defined(FREEBSD_USB) while the
+ * original code is enclosed in include !defined(FREEBSD_USB).
+ */
+
 #ifndef _X_MOUSEPRIV_H
 #define _X_MOUSEPRIV_H
 
@@ -63,8 +71,10 @@ typedef struct {
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
+#if !defined(FREEBSD_USB)
     float       fracdx,fracdy;
     float       sensitivity;
+#endif
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
