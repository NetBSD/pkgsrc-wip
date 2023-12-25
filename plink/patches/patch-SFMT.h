$NetBSD$

# Support non-x86

--- SFMT.h.orig	2023-12-25 14:05:59.079320161 +0000
+++ SFMT.h
@@ -129,7 +129,10 @@ extern "C" {
   128-bit SIMD like data type for standard C
   ------------------------------------------*/
 #ifdef __LP64__
-  #include <emmintrin.h>
+  // #include <emmintrin.h>
+  #define SIMDE_ENABLE_NATIVE_ALIASES
+  #include <simde/x86/sse2.h>
+
 
 /** 128-bit data structure */
 union W128_T {
