$NetBSD: patch-pr_src_pthreads_ptio.c,v 1.2 2014/09/28 14:29:41 thomasklausner Exp $

DragonFly support.

--- pr/src/pthreads/ptio.c.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/src/pthreads/ptio.c
@@ -180,7 +180,8 @@ static PRBool _pr_ipv6_v6only_on_by_defa
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
-    || defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN)
+    || defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN) \
+    || defined(__DragonFly__)
 #define _PRSelectFdSetArg_t fd_set *
 #else
 #error "Cannot determine architecture"
@@ -3256,7 +3257,7 @@ static PRIOMethods _pr_socketpollfd_meth
     || defined(AIX) || defined(FREEBSD) || defined(NETBSD) \
     || defined(OPENBSD) || defined(BSDI) || defined(NTO) \
     || defined(DARWIN) || defined(UNIXWARE) || defined(RISCOS) \
-    || defined(SYMBIAN)
+    || defined(SYMBIAN) || defined(__DragonFly__)
 #define _PR_FCNTL_FLAGS O_NONBLOCK
 #else
 #error "Can't determine architecture"
