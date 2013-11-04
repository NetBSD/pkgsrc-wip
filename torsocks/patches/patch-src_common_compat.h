$NetBSD: patch-src_common_compat.h,v 1.1 2013/11/04 00:23:47 thomasklausner Exp $

Handle NetBSD like FreeBSD.

--- src/common/compat.h.orig	2013-11-03 18:24:51.000000000 +0000
+++ src/common/compat.h
@@ -22,7 +22,7 @@
 #define __darwin__	1
 #endif
 
-#if (defined(__GLIBC__) || defined(__FreeBSD__) || defined(__darwin__))
+#if (defined(__GLIBC__) || defined(__FreeBSD__) || defined(__darwin__) || defined(__NetBSD__))
 
 #define RTLD_NEXT	((void *) -1)
 
