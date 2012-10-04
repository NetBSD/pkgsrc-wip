$NetBSD: patch-programs_dtlogin_dm.c,v 1.1 2012/10/04 04:57:03 jellehermsen Exp $

--- programs/dtlogin/dm.c.orig	2012-09-29 12:01:12.000000000 +0000
+++ programs/dtlogin/dm.c
@@ -61,7 +61,7 @@
 # include	<time.h>
 # include	<utime.h>
 # include	<pwd.h>
-#if defined(linux) || defined(__FreeBSD__)
+#if defined(linux) || defined(CSRG_BASED)
 # include	<stdarg.h>
 #else
 # include	<varargs.h>
