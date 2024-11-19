$NetBSD$

* Support NetBSD for mcode backend.
https://github.com/ghdl/ghdl/issues/2797

--- src/ortho/mcode/memsegs_c.c.orig	2024-11-18 10:40:25.368626207 +0000
+++ src/ortho/mcode/memsegs_c.c
@@ -28,6 +28,8 @@
 
 #if defined(__APPLE__) || defined(__OpenBSD__)
 #define MAP_ANONYMOUS MAP_ANON
+#elif defined(__NetBSD__)
+/* nothing */
 #else
 #define HAVE_MREMAP
 #endif
