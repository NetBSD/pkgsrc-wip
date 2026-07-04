$NetBSD$

Fix build on NetBSD.
https://github.com/pytorch/pytorch/pull/188941

--- c10/core/Scalar.h.orig	2026-06-18 00:45:12.000000000 +0000
+++ c10/core/Scalar.h
@@ -68,10 +68,11 @@ class C10_API Scalar {
       "int64_t is the same as long long on Windows");
   Scalar(long vv) : Scalar(vv, true) {}
 #endif
-#if defined(__linux__) && !defined(__ANDROID__)
+#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__NetBSD__) || \
+    defined(__FreeBSD__) || defined(__OpenBSD__)
   static_assert(
       sizeof(void*) != 8 || std::is_same_v<long, int64_t>,
-      "int64_t is the same as long on 64 bit Linux");
+      "int64_t is the same as long on 64 bit Linux and BSDs");
 #if LONG_MAX != INT_MAX
   Scalar(long long vv) : Scalar(vv, true) {}
 #endif /* not 32-bit system */
