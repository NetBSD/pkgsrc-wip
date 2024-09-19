$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_wtf_Threading.h,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Port over from x11/qt4-libs.
--- qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Threading.h.orig	2014-06-07 00:54:23.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/wtf/Threading.h
@@ -113,6 +113,8 @@ using WTF::createThread;
 using WTF::currentThread;
 using WTF::detachThread;
 using WTF::waitForThreadCompletion;
+#if !OS(SOLARIS)
 using WTF::yield;
+#endif
 
 #endif // Threading_h
