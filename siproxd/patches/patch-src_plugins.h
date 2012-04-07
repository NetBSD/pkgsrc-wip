$NetBSD: patch-src_plugins.h,v 1.1 2012/04/07 10:13:28 gschwarz Exp $

--- src/plugins.h.orig	2012-04-07 13:40:18.000000000 +0200
+++ src/plugins.h	2012-04-07 13:41:34.000000000 +0200
@@ -28,6 +28,10 @@
    #include <ltdl.h>
 #endif
 
+/* libtool 2.2 / 2.4 */
+#ifndef lt__PROGRAM__LTX_preloaded_symbols
+#define lt__PROGRAM__LTX_preloaded_symbols lt_libltdl_LTX_preloaded_symbols
+#endif
 
 /* Plugins must return STS_SUCCESS / SUCCESS_FAILURE */
 
