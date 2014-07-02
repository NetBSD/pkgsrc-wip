$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_Platform.h,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Fix build on SunOS.
--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h.orig	2014-06-07 00:54:23.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h
@@ -449,6 +449,7 @@
 /* OS(SOLARIS) - Solaris */
 #if defined(sun) || defined(__sun)
 #define WTF_OS_SOLARIS 1
+#define USE_SYSTEM_MALLOC 1
 #endif
 
 /* OS(WINCE) - Windows CE; note that for this platform OS(WINDOWS) is also defined */
