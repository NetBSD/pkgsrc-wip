$NetBSD: patch-pr_include_md___pth.h,v 1.2 2014/09/28 14:29:41 thomasklausner Exp $

DragonFly support.

--- pr/include/md/_pth.h.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/include/md/_pth.h
@@ -114,7 +114,7 @@
 #define _PT_PTHREAD_COPY_THR_HANDLE(st, dt)   (dt) = (st)
 #elif defined(IRIX) || defined(OSF1) || defined(AIX) || defined(SOLARIS) \
 	|| defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-	|| defined(HPUX) || defined(FREEBSD) \
+	|| defined(HPUX) || defined(FREEBSD) || defined(__DragonFly__) \
 	|| defined(NETBSD) || defined(OPENBSD) || defined(BSDI) \
 	|| defined(NTO) || defined(DARWIN) \
 	|| defined(UNIXWARE) || defined(RISCOS)	|| defined(SYMBIAN)
@@ -201,7 +201,7 @@
 #endif /* defined(_PR_DCETHREADS) */
 
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-	|| defined(FREEBSD) || defined(SYMBIAN)
+	|| defined(FREEBSD) || defined(SYMBIAN) || defined(__DragonFly__)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(NTO)
@@ -260,6 +260,7 @@ extern int (*_PT_aix_yield_fcn)();
 #elif defined(HPUX) || defined(SOLARIS) \
 	|| defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
 	|| defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
+	|| defined(__DragonFly__) \
 	|| defined(BSDI) || defined(NTO) || defined(DARWIN) \
 	|| defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN)
 #define _PT_PTHREAD_YIELD()            	sched_yield()
