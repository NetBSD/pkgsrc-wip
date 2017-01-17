$NetBSD$

Patches from FreeBSD ports / DragonFly dports with include guards.
Support for different versions of system libusb headers.

--- src/mouse.h.orig	2012-10-08 01:40:07.000000000 +0000
+++ src/mouse.h
@@ -27,6 +27,14 @@
 
 /* Public interface to OS-specific mouse support. */
 
+/* PKGSRC note: To support newer versions of DragonFly and FreeBSD,
+ * this file is patched using DragonFly dports
+ * x11-drivers/xf86-input-mouse/files/patch-src_mouse.h
+ * as of master commit 4f04bfe0ea83 ... Tue Jul 14 22:56:44 2015 -0700
+ * The patch's code is enclosed in include defined(FREEBSD_USB) while the
+ * original code is enclosed in include !defined(FREEBSD_USB).
+ */
+
 #ifndef _XF86OSMOUSE_H_
 #define _XF86OSMOUSE_H_
 
@@ -220,10 +228,17 @@ typedef struct _MouseDevRec {
     Bool                emulate3ButtonsSoft;
     int                 emulate3Timeout;/* Timeout for 3 button emulation */
     Bool                chordMiddle;
+#if defined(FREEBSD_USB)
+    Bool		disableXY;
+#endif
     Bool                flipXY;
     int                 invX;
     int                 invY;
     int                 resolution;
+#if defined(FREEBSD_USB)
+    Bool		hasW;
+    Bool		hasZ;
+#endif
     int                 negativeZ;      /* button mask */
     int                 positiveZ;      /* button mask */
     int                 negativeW;      /* button mask */
@@ -262,6 +277,10 @@ typedef struct _MouseDevRec {
     int                 doubleClickOldSourceState;
     int                 lastMappedButtons;
     int                 buttonMap[MSE_MAXBUTTONS];
+#if defined(FREEBSD_USB)
+    float		fracdx, fracdy;
+    float		sensitivity;
+#endif
 } MouseDevRec, *MouseDevPtr;
 
 #endif /* _XF86OSMOUSE_H_ */
