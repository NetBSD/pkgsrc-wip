$NetBSD$

OpenBSD, FreeBSD, and DragonFly all have pthread_mutex_timedlock
in their manpages.

--- include/c11/threads_posix.h.orig	2017-02-13 11:55:49.000000000 +0000
+++ include/c11/threads_posix.h
@@ -43,7 +43,7 @@ Configuration macro:
     Use pthread_mutex_timedlock() for `mtx_timedlock()'
     Otherwise use mtx_trylock() + *busy loop* emulation.
 */
-#if !defined(__CYGWIN__) && !defined(__APPLE__) && !defined(__NetBSD__)
+#if !defined(__CYGWIN__) && !defined(__APPLE__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #define EMULATED_THREADS_USE_NATIVE_TIMEDLOCK
 #endif
 
