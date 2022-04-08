$NetBSD$

Do not use GNU extensions sincos() and sincosf() for pkgsrc.

--- include/fxmath.h.orig	2022-02-15 03:49:40.000000000 +0000
+++ include/fxmath.h
@@ -172,7 +172,9 @@
 #endif
 
 // Apple is missing sincos
-#if defined(__APPLE__)
+//#if defined(__APPLE__)
+// Do not use GNU extensions for pkgsrc
+#if 1
 #define NO_SINCOS
 #define NO_SINCOSF
 #endif
