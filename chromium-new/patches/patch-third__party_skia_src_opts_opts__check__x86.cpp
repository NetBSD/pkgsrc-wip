$NetBSD$

--- third_party/skia/src/opts/opts_check_x86.cpp.orig	2016-06-24 01:04:04.000000000 +0000
+++ third_party/skia/src/opts/opts_check_x86.cpp
@@ -110,6 +110,13 @@ static inline bool supports_simd(int min
          * instructions. So for that particular case we disable our SSSE3 options.
          */
         return false;
+#elif (__NetBSD__)
+      /* NetBSD/amd64 7.99.34 is configured for nocona and nocona does not
+         support SSSE3. However CPU itself supports SSSE3 and gSIMDLevel()
+         returns SSSE3 is ready. This inconsistency causes runtime error,
+         sk_throw(), in S32_*_SSSE3()
+         in third_party/skia/src/opts/SkBitmapProcState_opts_SSSE3.cpp . */
+        return false;
 #else
         return minLevel <= *gSIMDLevel.get(get_SIMD_level);
 #endif
