$NetBSD$

Patches from NetBSD xsrc

Jan 23 16:57:01 2019 UTC

Avoid dup inconsistent definitions

Nov 5 17:51:14 2014 UTC

Add RRSetChanged from more recent versions of xorg-server

--- randr/randrstr.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ randr/randrstr.h
@@ -59,11 +59,23 @@
 
 #define RANDR_INTERFACE_VERSION 0x0104
 
+#if defined(__NetBSD__)
+/* All also defined in <X11/extensions/randrproto.h> */
+#ifndef RROutput
+#define RROutput CARD32
+#define RRMode CARD32
+#define RRCrtc CARD32
+#define RRProvider CARD32
+#define RRModeFlags CARD32
+#define RRLease CARD32
+#endif
+#else /* !__NetBSD__ */
 typedef XID RRMode;
 typedef XID RROutput;
 typedef XID RRCrtc;
 typedef XID RRProvider;
 typedef XID RRLease;
+#endif /* __NetBSD__ */
 
 extern int RREventBase, RRErrorBase;
 
@@ -581,6 +593,11 @@ RRSetChanged(ScreenPtr pScreen);
 extern _X_EXPORT void
  RRTellChanged(ScreenPtr pScreen);
 
+#if defined(__NetBSD__) && 0
+extern _X_EXPORT void
+RRSetChanged (ScreenPtr pScreen);
+#endif
+
 /*
  * Poll the driver for changed information
  */
