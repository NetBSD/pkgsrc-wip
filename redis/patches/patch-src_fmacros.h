$NetBSD: patch-src_fmacros.h,v 1.1 2012/02/29 11:34:43 fhajny Exp $

NetBSD needs _XOPEN_SOURCE>=600.

--- src/fmacros.h.orig	2012-02-22 13:23:43.000000000 +0000
+++ src/fmacros.h
@@ -3,7 +3,7 @@
 
 #define _BSD_SOURCE
 
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #define _XOPEN_SOURCE 700
 #else
 #define _XOPEN_SOURCE
