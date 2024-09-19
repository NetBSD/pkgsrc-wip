$NetBSD: patch-Source_WTF_wtf_Threading.h,v 1.1 2015/02/23 16:11:06 leot1990 Exp $

* Add Solaris/SunOS support

--- src/qt/qtwebkit/Source/WTF/wtf/Threading.h.orig	2015-01-24 02:19:52.000000000 +0000
+++ src/qt/qtwebkit/Source/WTF/wtf/Threading.h
@@ -112,6 +112,8 @@ using WTF::createThread;
 using WTF::currentThread;
 using WTF::detachThread;
 using WTF::waitForThreadCompletion;
+#if !OS(SOLARIS)
 using WTF::yield;
+#endif
 
 #endif // Threading_h
