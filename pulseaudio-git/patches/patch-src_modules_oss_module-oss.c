$NetBSD: patch-src_modules_oss_module-oss.c,v 1.2 2014/06/25 15:26:40 ryoon Exp $

Set proper sound device default on NetBSD.

--- src/modules/oss/module-oss.c.orig	2015-09-10 04:51:41.000000000 +0000
+++ src/modules/oss/module-oss.c
@@ -96,7 +96,11 @@ PA_MODULE_USAGE(
 PA_MODULE_DEPRECATED("Please use module-alsa-card instead of module-oss!");
 #endif
 
+#if defined(__NetBSD__)
+#define DEFAULT_DEVICE "/dev/audio"
+#else /* Linux */
 #define DEFAULT_DEVICE "/dev/dsp"
+#endif
 
 struct userdata {
     pa_core *core;
