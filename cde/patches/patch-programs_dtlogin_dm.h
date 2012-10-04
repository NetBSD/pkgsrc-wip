$NetBSD: patch-programs_dtlogin_dm.h,v 1.1 2012/10/04 04:57:03 jellehermsen Exp $

--- programs/dtlogin/dm.h.orig	2012-09-29 12:02:14.000000000 +0000
+++ programs/dtlogin/dm.h
@@ -202,7 +202,7 @@
  ***************************************************************************/
 
 /*#if defined(SYSV) && !defined(hpux)*/
-#if defined(SYSV) || defined(SVR4) || defined(linux) || defined(__FreeBSD__)
+#if defined(SYSV) || defined(SVR4) || defined(linux) || defined(CSRG_BASED)
 #   include	<sys/wait.h>
 # define waitCode(w)	WEXITSTATUS(w)
 # define waitSig(w)	WTERMSIG(w)
