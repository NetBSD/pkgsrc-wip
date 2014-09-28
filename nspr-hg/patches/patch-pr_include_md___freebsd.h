$NetBSD: patch-pr_include_md___freebsd.h,v 1.2 2014/09/28 14:29:41 thomasklausner Exp $

DragonFly support.

--- pr/include/md/_freebsd.h.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/include/md/_freebsd.h
@@ -53,7 +53,7 @@
 #define _PR_HAVE_LARGE_OFF_T
 
 #if defined(_PR_PTHREADS)
-#if __FreeBSD_version >= 400008
+#if defined(__DragonFly__) || __FreeBSD_version >= 400008
 /*
  * libc_r before this version of FreeBSD doesn't have poll().
  * Although libc has poll(), it is not thread-safe so we can't
@@ -62,7 +62,7 @@
 #define _PR_POLL_AVAILABLE
 #endif
 #else
-#if __FreeBSD_version >= 300000
+#if defined(__DragonFly__) || __FreeBSD_version >= 300000
 #define _PR_POLL_AVAILABLE
 #define _PR_USE_POLL
 #endif
@@ -71,7 +71,7 @@
 #define _PR_HAVE_SYSV_SEMAPHORES
 #define PR_HAVE_SYSV_NAMED_SHARED_MEMORY
 
-#if __FreeBSD_version >= 400014
+#if defined(__DragonFly__) || __FreeBSD_version >= 400014
 #define _PR_INET6
 #define _PR_HAVE_INET_NTOP
 #define _PR_HAVE_GETHOSTBYNAME2
