$NetBSD$

--- tigervnc-1.6.0/unix/xserver/hw/vnc/xorg-version.h.orig	2015-12-24 20:18:02.000000000 +0000
+++ tigervnc-1.6.0/unix/xserver/hw/vnc/xorg-version.h
@@ -48,8 +48,10 @@
 #define XORG 116
 #elif XORG_VERSION_CURRENT < ((1 * 10000000) + (17 * 100000) + (99 * 1000))
 #define XORG 117
+#elif XORG_VERSION_CURRENT < ((1 * 10000000) + (18 * 100000) + (99 * 1000))
+#define XORG 118
 #else
-#error "X.Org newer than 1.17 is not supported"
+#error "X.Org newer than 1.18 is not supported"
 #endif
 
 #endif
