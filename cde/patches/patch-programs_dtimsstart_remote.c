$NetBSD: patch-programs_dtimsstart_remote.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtimsstart/remote.c.orig	2012-09-28 21:27:25.000000000 +0000
+++ programs/dtimsstart/remote.c
@@ -37,7 +37,7 @@
 #include	<X11/Xproto.h>		/* for X_ChangeHosts */
 #include	<X11/Xatom.h>		/* for XA_STRING */
 
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
 extern char	*sys_errlist[];
 #endif
 
