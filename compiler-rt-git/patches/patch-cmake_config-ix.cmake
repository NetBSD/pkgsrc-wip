$NetBSD$

--- cmake/config-ix.cmake.orig	2017-08-10 22:03:54.137919972 +0000
+++ cmake/config-ix.cmake
@@ -519,7 +519,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
