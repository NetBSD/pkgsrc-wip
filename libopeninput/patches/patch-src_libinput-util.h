$NetBSD$

* Add NetBSD support

--- src/libinput-util.h.orig	2025-08-17 15:49:37.000000000 +0000
+++ src/libinput-util.h
@@ -66,7 +66,7 @@
 #define LIBINPUT_EXPORT __attribute__ ((visibility("default")))
 #define LIBINPUT_UNUSED __attribute__ ((unused))
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #define bit(x_) (1UL << (x_))
 #define NBITS(b) (b * 8)
 #endif
