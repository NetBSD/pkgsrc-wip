$NetBSD$

Just like FREEBSD et al NetBSD requires *_NP #defined

https://sourceforge.net/p/xsb/patches/9/

--- ../emu/thread_xsb.h.orig	2022-05-12 20:54:07.000000000 +0000
+++ ../emu/thread_xsb.h
@@ -215,7 +215,7 @@ int get_waiting_for_tid( int t );
 
 /* TLS: for Cygwin, these constants must be re-defined */
 
-#if defined(DARWIN) || defined(FREEBSD) || defined(SOLARIS) || defined(CYGWIN)
+#if defined(DARWIN) || defined(FREEBSD) || defined(SOLARIS) || defined(CYGWIN) || defined(__NetBSD__)
 
 #define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
 #define PTHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK
