$NetBSD$

--- utils/simthread.h.orig	2015-11-29 19:41:00.000000000 +0000
+++ utils/simthread.h
@@ -1,5 +1,6 @@
 #ifndef simthread_h
 #define simthread_h
+#define _USE_POSIX_BARRIERS
 
 #ifdef MULTI_THREAD
 
