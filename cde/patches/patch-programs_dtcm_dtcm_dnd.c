$NetBSD: patch-programs_dtcm_dtcm_dnd.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtcm/dtcm/dnd.c.orig	2012-09-28 21:20:45.000000000 +0000
+++ programs/dtcm/dtcm/dnd.c
@@ -72,7 +72,7 @@
 
 static Bool lookForButton(Display *, XEvent *, XPointer);
 
-#if !defined(linux) && !defined(__FreeBSD__)
+#if !defined(linux) && !defined(CSRG_BASED)
 extern char	*sys_errlist[];
 #endif
 
