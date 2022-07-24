$NetBSD$

--- cmake/Dependencies.cmake.orig	2022-07-22 04:45:54.504308990 +0000
+++ cmake/Dependencies.cmake
@@ -346,7 +346,7 @@ if(USE_NNPACK OR USE_QNNPACK OR USE_PYTO
         "Turn this warning off by USE_{Q/X}NNPACK=OFF.")
       set(DISABLE_NNPACK_AND_FAMILY ON)
     endif()
-    if(NOT IOS AND NOT (CMAKE_SYSTEM_PROCESSOR MATCHES "^(i686|AMD64|x86_64|armv[0-9].*|arm64|aarch64)$"))
+    if(NOT IOS AND NOT (CMAKE_SYSTEM_PROCESSOR MATCHES "^(i686|amd64|x86_64|armv[0-9].*|arm64|aarch64)$"))
       message(WARNING
         "Target architecture \"${CMAKE_SYSTEM_PROCESSOR}\" is not supported in {Q/X}NNPACK. "
         "Supported architectures are x86, x86-64, ARM, and ARM64. "
