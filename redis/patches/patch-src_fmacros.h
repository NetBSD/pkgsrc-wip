$NetBSD: patch-src_fmacros.h,v 1.2 2012/12/15 20:39:54 fhajny Exp $

NetBSD needs _XOPEN_SOURCE>=600.

--- src/fmacros.h.orig	2012-12-03 11:53:09.000000000 +0000
+++ src/fmacros.h
@@ -36,7 +36,7 @@
 #define _GNU_SOURCE
 #endif
 
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define _XOPEN_SOURCE 700
 #else
 #define _XOPEN_SOURCE
