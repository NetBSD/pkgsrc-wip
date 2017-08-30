$NetBSD$

--- cmake/config-ix.cmake.orig	2017-08-21 23:23:37.000000000 +0000
+++ cmake/config-ix.cmake
@@ -511,7 +511,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND LSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD")
   set(COMPILER_RT_HAS_LSAN TRUE)
 else()
   set(COMPILER_RT_HAS_LSAN FALSE)
@@ -525,14 +525,14 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND TSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Android|NetBSD")
   set(COMPILER_RT_HAS_TSAN TRUE)
 else()
   set(COMPILER_RT_HAS_TSAN FALSE)
