$NetBSD: patch-src_compat.cpp,v 1.1 2013/12/16 07:54:18 nsloss Exp $

CLOCK_THREAD_CPUTIME_ID does not exit on NetBSD.

--- src/compat.cpp.orig	2013-03-16 11:19:18.000000000 +0000
+++ src/compat.cpp
@@ -74,6 +74,7 @@ uint64_t timespecToUsecs(timespec t)
 
 uint64_t compat_get_thread_cputime_us()
 {
+#ifndef __NetBSD__
 	timespec tp;
 
 #ifndef _POSIX_THREAD_CPUTIME
@@ -81,6 +82,9 @@ uint64_t compat_get_thread_cputime_us()
 #endif
 	clock_gettime(CLOCK_THREAD_CPUTIME_ID,&tp);
 	return timespecToUsecs(tp);
+#else
+	return 0;
+#endif
 }
 
 void aligned_malloc(void **memptr, size_t alignment, size_t size)
