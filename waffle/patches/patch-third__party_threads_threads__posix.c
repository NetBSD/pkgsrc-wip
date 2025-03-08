$NetBSD: patch-third__party_threads_threads__posix.c,v 1.1 2015/09/19 14:51:52 tnn2 Exp $

We don't have pthread_mutex_timedlock.

--- third_party/threads/threads_posix.c.orig	2021-03-07 20:51:15.000000000 +0000
+++ third_party/threads/threads_posix.c
@@ -45,7 +45,7 @@ Configuration macro:
     Use pthread_mutex_timedlock() for `mtx_timedlock()'
     Otherwise use mtx_trylock() + *busy loop* emulation.
 */
-#if !defined(__CYGWIN__) && !defined(ANDROID) && !defined(__APPLE__)
+#if !defined(__CYGWIN__) && !defined(ANDROID) && !defined(__APPLE__) && !defined(__NetBSD__)
 #define EMULATED_THREADS_USE_NATIVE_TIMEDLOCK
 #endif
 
