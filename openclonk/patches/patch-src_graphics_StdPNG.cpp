$NetBSD$
--- src/graphics/StdPNG.cpp.orig	2016-01-17 18:37:04.000000000 -0800
+++ src/graphics/StdPNG.cpp	2016-01-17 18:37:14.000000000 -0800
@@ -368,10 +368,8 @@
 		first = false;
 #ifdef HAVE_WINTHREAD
 		Sleep(100);
-#elif defined (__APPLE__)
+#else
 		sched_yield();
-#elif defined(HAVE_PTHREAD)
-		pthread_yield();
 #endif
 	}
 }
