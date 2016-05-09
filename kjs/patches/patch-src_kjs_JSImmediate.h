$NetBSD: patch-kjs_JSImmediate.h,v 1.3 2012/03/31 21:46:55 hans Exp $

--- src/kjs/JSImmediate.h.orig	2016-04-03 20:34:48.000000000 +0000
+++ src/kjs/JSImmediate.h
@@ -33,7 +33,7 @@
 #endif
 #include <stdlib.h>
 
-#if PLATFORM(SOLARIS_OS)
+#if PLATFORM(SOLARIS_OS) && COMPILER(GCC) && (__GNUC__ <= 4 && __GNUC_MINOR__ < 6)
 static inline int signbit(double x)
 {
     return (x < 0.0) ? 1 : 0;
