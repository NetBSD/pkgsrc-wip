$NetBSD$

--- cmake/config-ix.cmake.orig	2017-08-21 23:23:37.000000000 +0000
+++ cmake/config-ix.cmake
@@ -532,7 +532,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND TSAN_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Android")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Android|NetBSD")
   set(COMPILER_RT_HAS_TSAN TRUE)
 else()
   set(COMPILER_RT_HAS_TSAN FALSE)
@@ -581,7 +581,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND FUZZER_SUPPORTED_ARCH AND
-      OS_NAME MATCHES "Darwin|Linux")
+      OS_NAME MATCHES "Darwin|Linux|NetBSD")
   set(COMPILER_RT_HAS_FUZZER TRUE)
 else()
   set(COMPILER_RT_HAS_FUZZER FALSE)
