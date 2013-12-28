$NetBSD: patch-src_plugins.h,v 1.2 2013/12/28 14:42:29 imilh Exp $

using libtool 2.x
http://sources.gentoo.org/cgi-bin/viewvc.cgi/gentoo-x86/net-misc/siproxd/files/siproxd-libtool-2.4.patch?view=markup

--- src/plugins.h.orig	2011-05-28 15:47:15.000000000 +0000
+++ src/plugins.h
@@ -28,6 +28,12 @@
    #include <ltdl.h>
 #endif
 
+#ifndef lt__PROGRAM__LTX_preloaded_symbols
+#define lt__PROGRAM__LTX_preloaded_symbols lt_libltdl_LTX_preloaded_symbols
+#endif
+#ifndef lt_libltdl_LTX_preloaded_symbols
+extern LT_DLSYM_CONST lt_dlsymlist lt__PROGRAM__LTX_preloaded_symbols[];
+#endif
 
 /* Plugins must return STS_SUCCESS / SUCCESS_FAILURE */
 
