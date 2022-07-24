$NetBSD$

--- c10/test/util/exception_test.cpp.orig	2022-07-22 04:45:53.177575954 +0000
+++ c10/test/util/exception_test.cpp
@@ -35,7 +35,7 @@ TEST(ExceptionTest, TORCH_INTERNAL_ASSER
 
 // On these platforms there's no assert
 #if !defined(__ANDROID__) && !defined(__APPLE__) && \
-    !(defined(USE_ROCM) && ROCM_VERSION < 40100)
+    !(defined(USE_ROCM) && ROCM_VERSION < 40100) && !defined(__NetBSD__)
 TEST(ExceptionTest, CUDA_KERNEL_ASSERT) {
   // This function always throws even in NDEBUG mode
   ASSERT_DEATH_IF_SUPPORTED({ CUDA_KERNEL_ASSERT(false); }, "Assert");
