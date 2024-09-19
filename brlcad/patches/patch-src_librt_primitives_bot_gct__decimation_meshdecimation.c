$NetBSD$

__float128 is unsupported on NetBSD-7.99.39/amd64

--- src/librt/primitives/bot/gct_decimation/meshdecimation.c.orig	2016-08-09 06:47:48.000000000 +0000
+++ src/librt/primitives/bot/gct_decimation/meshdecimation.c
@@ -88,7 +88,9 @@
 #endif
 
 
+#if !defined(__NetBSD__)
 #define MD_CONFIG_HIGH_QUADRICS
+#endif
 
 
 #define MD_CONFIG_AREA_QUADRICS
