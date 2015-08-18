$NetBSD: patch-src_platform_Thread.cpp,v 1.1 2015/08/18 20:14:58 yhardy Exp $

Fix pthread_setname_np on NetBSD

--- src/platform/Thread.cpp.orig	2012-08-16 18:07:06.000000000 +0200
+++ src/platform/Thread.cpp	2012-08-16 18:19:04.000000000 +0200
@@ -96,7 +96,11 @@
 	// Set the thread name.
 #if defined(ARX_HAVE_PTHREAD_SETNAME_NP) && ARX_PLATFORM != ARX_PLATFORM_MACOSX
 	// Linux
+# ifdef __NetBSD__
+	pthread_setname_np(thread.thread, "%s", (void*)thread.threadName.c_str());
+# else
 	pthread_setname_np(thread.thread, thread.threadName.c_str());
+# endif
 #elif defined(ARX_HAVE_PTHREAD_SETNAME_NP) && ARX_PLATFORM == ARX_PLATFORM_MACOSX
 	// Mac OS X
 	pthread_setname_np(thread.threadName.c_str());
