$NetBSD: patch-pr_include_md___netbsd.h,v 1.2 2014/09/28 14:33:59 thomasklausner Exp $

Improve NetBSD support, add NetBSD/amd64 support.

--- pr/include/md/_netbsd.h.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/include/md/_netbsd.h
@@ -47,7 +47,7 @@
 #define HAVE_DLL
 #define USE_DLFCN
 #define _PR_HAVE_SOCKADDR_LEN
-#define _PR_NO_LARGE_FILES
+#define _PR_HAVE_LARGE_OFF_T
 #define _PR_STAT_HAS_ST_ATIMESPEC
 #define _PR_POLL_AVAILABLE
 #define _PR_USE_POLL
@@ -75,6 +75,8 @@
 #define JB_SP_INDEX 2
 #elif defined(__mips__)
 #define JB_SP_INDEX 4
+#elif defined(__amd64__)
+#define JB_SP_INDEX 6
 #elif defined(__alpha__)
 #define JB_SP_INDEX 34
 #elif defined(__arm32__)
