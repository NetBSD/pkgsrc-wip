$NetBSD: patch-src_qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_Platform.h,v 1.1 2013/06/18 11:02:23 fhajny Exp $

Fix build on SunOS.
--- src/qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h.orig	2013-06-13 12:03:59.825500545 +0000
+++ src/qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h
@@ -445,6 +445,7 @@
 /* OS(SOLARIS) - Solaris */
 #if defined(sun) || defined(__sun)
 #define WTF_OS_SOLARIS 1
+#define USE_SYSTEM_MALLOC 1
 #endif
 
 /* OS(WINCE) - Windows CE; note that for this platform OS(WINDOWS) is also defined */
