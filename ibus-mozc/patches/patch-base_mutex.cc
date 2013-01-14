$NetBSD: patch-base_mutex.cc,v 1.1 2013/01/14 06:21:30 ryo-on Exp $

* Treat FreeBSD/NetBSD like OS X.

--- base/mutex.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/mutex.cc
@@ -296,7 +296,7 @@ Mutex::Mutex() {
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(__FreeBSD__) || defined(__NetBSD__)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
