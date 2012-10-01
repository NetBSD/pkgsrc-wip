$NetBSD: patch-programs_dtappbuilder_src_ab_proj.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtappbuilder/src/ab/proj.c.orig	2012-09-28 20:55:22.000000000 +0000
+++ programs/dtappbuilder/src/ab/proj.c
@@ -228,7 +228,7 @@ static XtTranslations proj_transtbl = NU
 static XRectangle       *rband_rect = NULL;
 static Boolean          mselect_adjust = False;
 
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
 extern char             *sys_errlist[];
 #endif
 char			Buf[MAXPATHLEN];	/* Work buffer */
