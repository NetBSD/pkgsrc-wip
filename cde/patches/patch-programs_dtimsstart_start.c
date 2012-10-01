$NetBSD: patch-programs_dtimsstart_start.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtimsstart/start.c.orig	2012-09-28 21:28:07.000000000 +0000
+++ programs/dtimsstart/start.c
@@ -32,7 +32,7 @@
 #define _NFILE FOPEN_MAX
 #endif
 
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
 extern char	*sys_errlist[];
 extern int	sys_nerr;
 #endif
