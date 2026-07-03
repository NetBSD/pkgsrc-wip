$NetBSD$

Avoid undefined reference of __assert_fail().

--- torch/headeronly/macros/Macros.h.orig	2026-07-02 20:56:17.538514982 +0000
+++ torch/headeronly/macros/Macros.h
@@ -415,7 +415,7 @@ static inline int C10_WARP_SIZE_INTERNAL() {
 // CUDA_KERNEL_ASSERT checks the assertion
 // even when NDEBUG is defined. This is useful for important assertions in CUDA
 // code that would otherwise be suppressed when building Release.
-#if defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__ANDROID__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 // Those platforms do not support assert()
 #define CUDA_KERNEL_ASSERT(cond)
 #define CUDA_KERNEL_ASSERT_MSG(cond, msg)
