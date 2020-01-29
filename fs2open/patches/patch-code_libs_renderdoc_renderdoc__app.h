$NetBSD$

Add support for NetBSD and OpenBSD.

--- code/libs/renderdoc/renderdoc_app.h.orig	2019-08-28 23:04:20.000000000 +0000
+++ code/libs/renderdoc/renderdoc_app.h
@@ -39,6 +39,12 @@
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC
+#elif defined(__FreeBSD__)
+#define RENDERDOC_CC
+#elif defined(__NetBSD__)
+#define RENDERDOC_CC
+#elif defined(__OpenBSD__)
+#define RENDERDOC_CC
 #else
 #error "Unknown platform"
 #endif
