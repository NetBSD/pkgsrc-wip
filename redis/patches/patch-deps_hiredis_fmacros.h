$NetBSD: patch-deps_hiredis_fmacros.h,v 1.1 2012/02/29 11:34:43 fhajny Exp $

NetBSD needs _XOPEN_SOURCE>=600.

--- deps/hiredis/fmacros.h.orig	2012-02-22 13:23:43.000000000 +0000
+++ deps/hiredis/fmacros.h
@@ -7,7 +7,7 @@
 
 #if defined(__sun__)
 #define _POSIX_C_SOURCE 200112L
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
 #define _XOPEN_SOURCE 600
 #else
 #define _XOPEN_SOURCE
