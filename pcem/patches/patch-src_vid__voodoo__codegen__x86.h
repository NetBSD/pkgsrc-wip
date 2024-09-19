$NetBSD$

Assume non-Windows is unixy.

--- src/vid_voodoo_codegen_x86.h.orig	2020-12-01 20:40:53.000000000 +0000
+++ src/vid_voodoo_codegen_x86.h
@@ -5,14 +5,13 @@
   fbzColorPath
 */
 
-#if defined(__linux__) || defined(__APPLE__)
-#include <sys/mman.h>
-#include <unistd.h>
-#endif
 #if defined WIN32 || defined _WIN32 || defined _WIN32
 #define BITMAP windows_BITMAP
 #include <windows.h>
 #undef BITMAP
+#else
+#include <sys/mman.h>
+#include <unistd.h>
 #endif
 
 #include <xmmintrin.h>
@@ -3367,7 +3366,7 @@ voodoo_recomp++;
 void voodoo_codegen_init(voodoo_t *voodoo)
 {
         int c;
-#if defined(__linux__) || defined(__APPLE__)
+#ifndef _WIN32
 	void *start;
 	size_t len;
 	long pagesize = sysconf(_SC_PAGESIZE);
