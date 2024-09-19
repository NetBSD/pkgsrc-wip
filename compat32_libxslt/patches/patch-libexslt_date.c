$NetBSD: patch-libexslt_date.c,v 1.1 2019/01/09 19:12:14 adam Exp $

--- libexslt/date.c.orig	2012-09-12 05:58:38.000000000 +0000
+++ libexslt/date.c
@@ -31,6 +31,7 @@
 #if defined(HAVE_LOCALTIME_R) && defined(__GLIBC__)	/* _POSIX_SOURCE required by gnu libc */
 #ifndef _AIX51		/* but on AIX we're not using gnu libc */
 #define _POSIX_SOURCE
+#define _POSIX_C_SOURCE 199506L /* POSIX.1c */
 #endif
 #endif
 
