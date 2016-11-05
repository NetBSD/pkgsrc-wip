$NetBSD$

--- utils/simthread.h.orig	2015-11-29 19:41:00.000000000 +0000
+++ utils/simthread.h
@@ -24,7 +24,7 @@
 
 // Mac OS X defines this initializers without _NP.
 #ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
-#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_RECURSIVE_MUTEX_INITIALIZER
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_MUTEX_INITIALIZER
 #endif
 
 // use our implementation if no posix barriers are available
