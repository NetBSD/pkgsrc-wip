$NetBSD: patch-qt_src_3rdparty_webkit_Source_JavaScriptCore_heap_MachineStackMarker.cpp,v 1.1 2014/07/02 21:20:08 fhajny Exp $

Fix build on SunOS.
--- qt/src/3rdparty/webkit/Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2014-06-07 00:54:21.000000000 +0000
+++ qt/src/3rdparty/webkit/Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -382,6 +382,8 @@ static size_t getPlatformThreadRegisters
 #if HAVE(PTHREAD_NP_H) || OS(NETBSD)
     // e.g. on FreeBSD 5.4, neundorf@kde.org
     pthread_attr_get_np(platformThread, &regs);
+#elif OS(SOLARIS)
+    pthread_attr_init(&regs);
 #else
     // FIXME: this function is non-portable; other POSIX systems may have different np alternatives
     pthread_getattr_np(platformThread, &regs);
