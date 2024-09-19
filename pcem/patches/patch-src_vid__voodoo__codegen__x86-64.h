$NetBSD$

Assume non-Windows is unixy.

--- src/vid_voodoo_codegen_x86-64.h.orig	2020-12-01 20:40:53.000000000 +0000
+++ src/vid_voodoo_codegen_x86-64.h
@@ -5,14 +5,13 @@
   fbzColorPath
 */
 
-#if defined(__linux__) || defined(__APPLE__)
-#include <sys/mman.h>
-#include <unistd.h>
-#endif
 #if WIN64
 #define BITMAP windows_BITMAP
 #include <windows.h>
 #undef BITMAP
+#else
+#include <sys/mman.h>
+#include <unistd.h>
 #endif
 
 #include <xmmintrin.h>
