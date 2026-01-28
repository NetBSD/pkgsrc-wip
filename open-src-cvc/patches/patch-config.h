$NetBSD$

HAVE_ALLOCA_H assumption restricted to Linux

--- config.h.orig	2023-07-16 21:42:51.000000000 +0000
+++ config.h
@@ -14,7 +14,11 @@
 
 /* Define to 1 if you have <alloca.h> and it should be used (not on Ultrix).
    */
+#if defined(__linux)
 #define HAVE_ALLOCA_H 1
+#else
+#undef HAVE_ALLOCA_H
+#endif
 
 /* Define to 1 if you have the `atexit' function. */
 #define HAVE_ATEXIT 1
