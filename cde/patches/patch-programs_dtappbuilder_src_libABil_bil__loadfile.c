$NetBSD: patch-programs_dtappbuilder_src_libABil_bil__loadfile.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtappbuilder/src/libABil/bil_loadfile.c.orig	2012-09-28 21:18:00.000000000 +0000
+++ programs/dtappbuilder/src/libABil/bil_loadfile.c
@@ -61,7 +61,7 @@
 
 BIL_LOAD_INFO	bilP_load;
 char		Buf[MAXPATHLEN];
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
 extern char     *sys_errlist[];
 #endif
 
