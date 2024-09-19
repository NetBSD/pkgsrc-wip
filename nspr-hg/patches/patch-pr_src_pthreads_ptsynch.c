$NetBSD: patch-pr_src_pthreads_ptsynch.c,v 1.2 2014/09/28 14:29:41 thomasklausner Exp $

DragonFly support.

--- pr/src/pthreads/ptsynch.c.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/src/pthreads/ptsynch.c
@@ -912,7 +912,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphor
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
     || defined(FREEBSD) || defined(OPENBSD) || defined(BSDI) \
-    || defined(DARWIN) || defined(SYMBIAN)
+    || defined(DARWIN) || defined(SYMBIAN) || defined(__DragonFly__)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
