$NetBSD$

Fix build on Darwin for macOS 26.2.

Patch from https://github.com/markmentovai/gcc/commit/8708938
fixincludes, Darwin: Handle macOS 15 SDK
The macOS 15 SDK has declarations that use the _Float16 type in its
<math.h>, but GCC 12 doesn't support that type in C++ code, support
having been introduced in b042088 (in GCC 13). Add a fixincludes
hack to hide these declarations inside #ifndef __cplusplus guards.

--- fixincludes/tests/base/math.h.orig	2026-02-17 21:20:00.303296688 +0000
+++ fixincludes/tests/base/math.h
@@ -30,6 +30,13 @@
 #endif  /* DARWIN_9_LONG_DOUBLE_FUNCS_2_CHECK */
 
 
+#if defined( DARWIN_FLOAT16_CHECK )
+#ifndef __cplusplus
+extern _Float16 __fabsf16(_Float16) __API_AVAILABLE(macos(15.0), ios(18.0), watchos(11.0), tvos(18.0));
+#endif
+#endif  /* DARWIN_FLOAT16_CHECK */
+
+
 #if defined( DARWIN_FLT_EVAL_METHOD_CHECK )
 #if __FLT_EVAL_METHOD__ == 0 || __FLT_EVAL_METHOD__ == 16
 #if __FLT_EVAL_METHOD__ == 0 || __FLT_EVAL_METHOD__ == -1 || __FLT_EVAL_METHOD__ == 16
