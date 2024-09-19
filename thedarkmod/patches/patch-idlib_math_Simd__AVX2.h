$NetBSD$

--- idlib/math/Simd_AVX2.h.orig	2019-02-02 17:51:35.000000000 +0000
+++ idlib/math/Simd_AVX2.h
@@ -23,13 +23,7 @@
 ===============================================================================
 */
 
-#ifdef __linux__
 #define ALLOW_AVX2 __attribute__ ((__target__ ("avx2")))  __attribute__ ((__target__ ("fma")))
-#else
-#define ALLOW_AVX2
-#endif
-
-
 
 class idSIMD_AVX2 : public idSIMD_AVX {
 public:
