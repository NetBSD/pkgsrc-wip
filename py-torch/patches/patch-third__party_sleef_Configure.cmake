$NetBSD$

--- third_party/sleef/Configure.cmake.orig	2022-07-22 04:49:41.023701353 +0000
+++ third_party/sleef/Configure.cmake
@@ -87,7 +87,7 @@ if(CMAKE_SIZEOF_VOID_P EQUAL 4)
   set(SLEEF_ARCH_32BIT ON CACHE INTERNAL "True for 32-bit architecture.")
 endif()
 
-if(SLEEF_TARGET_PROCESSOR MATCHES "(x86|AMD64|amd64|^i.86$)")
+if(SLEEF_TARGET_PROCESSOR MATCHES "(x86|amd64|amd64|^i.86$)")
   set(SLEEF_ARCH_X86 ON CACHE INTERNAL "True for x86 architecture.")
 
   set(CLANG_FLAGS_ENABLE_PURECFMA_SCALAR "-mavx2;-mfma;-fno-strict-aliasing")
