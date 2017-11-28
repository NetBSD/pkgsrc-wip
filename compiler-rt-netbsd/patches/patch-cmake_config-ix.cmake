$NetBSD$

--- cmake/config-ix.cmake.orig	2017-11-28 08:25:28.000000000 +0000
+++ cmake/config-ix.cmake
@@ -525,7 +525,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
@@ -573,7 +573,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND SCUDO_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Linux|Android")
+    OS_NAME MATCHES "Linux|Android|NetBSD")
   set(COMPILER_RT_HAS_SCUDO TRUE)
 else()
   set(COMPILER_RT_HAS_SCUDO FALSE)
