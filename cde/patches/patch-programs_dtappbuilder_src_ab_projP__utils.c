$NetBSD: patch-programs_dtappbuilder_src_ab_projP__utils.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtappbuilder/src/ab/projP_utils.c.orig	2012-09-28 20:56:22.000000000 +0000
+++ programs/dtappbuilder/src/ab/projP_utils.c
@@ -93,7 +93,7 @@ static void     mult_module_selected(
 **                                                                      **
 **************************************************************************/
 
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
 extern char	*sys_errlist[];
 #endif
 char		Buf[MAXPATHLEN];	/* Work buffer */
