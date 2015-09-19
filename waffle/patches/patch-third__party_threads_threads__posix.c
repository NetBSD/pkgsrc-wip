$NetBSD: patch-third__party_threads_threads__posix.c,v 1.1 2015/09/19 14:51:52 tnn2 Exp $

We don't have pthread_mutex_timedlock.

--- third_party/threads/threads_posix.c.orig	2015-08-25 21:05:10.000000000 +0000
+++ third_party/threads/threads_posix.c
@@ -42,7 +42,7 @@ Configuration macro:
     Use pthread_mutex_timedlock() for `mtx_timedlock()'
     Otherwise use mtx_trylock() + *busy loop* emulation.
 */
-#if !defined(__CYGWIN__) && !defined(ANDROID)
+#if !defined(__CYGWIN__) && !defined(ANDROID) && !defined(__NetBSD__)
 #define EMULATED_THREADS_USE_NATIVE_TIMEDLOCK
 #endif
 
