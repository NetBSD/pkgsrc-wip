$NetBSD$

# Support non-x86

--- plink_common.h.orig	2023-12-25 14:02:07.377466789 +0000
+++ plink_common.h
@@ -187,14 +187,9 @@
 // http://esr.ibiblio.org/?p=5095 ).
 
 #ifdef __LP64__
-  #ifndef __SSE2__
-    // It's obviously possible to support this by writing 64-bit non-SSE2 code
-    // shadowing each SSE2 intrinsic, but this almost certainly isn't worth the
-    // development/testing effort until regular PLINK 2.0 development is
-    // complete.  No researcher has ever asked me for this feature.
-    #error "64-bit builds currently require SSE2.  Try producing a 32-bit build instead."
-  #endif
-  #include <emmintrin.h>
+// #include <emmintrin.h>
+  #define SIMDE_ENABLE_NATIVE_ALIASES
+  #include <simde/x86/sse2.h>
 
   #define VECFTYPE __m128
   #define VECITYPE __m128i
