$NetBSD: patch-double-conversion_src_utils.h,v 1.1.1.1 2011/09/27 13:43:39 phonohawk Exp $

PowerPC has an 80bit wide FPU.

--- double-conversion/src/utils.h.orig	2011-09-27 13:21:00.000000000 +0000
+++ double-conversion/src/utils.h
@@ -57,6 +57,9 @@
 #else
 #undef DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS
 #endif  // _WIN32
+#elif defined(__POWERPC__)
+// PowerPC has an 80bit wide FPU.
+#undef DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS
 #else
 #error Target architecture was not detected as supported by Double-Conversion.
 #endif
@@ -294,4 +297,4 @@ inline Dest BitCast(Source* source) {
 
 }  // namespace double_conversion
 
-#endif  // DOUBLE_CONVERSION_UTILS_H_
\ No newline at end of file
+#endif  // DOUBLE_CONVERSION_UTILS_H_
