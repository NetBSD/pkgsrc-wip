$NetBSD$

--- cmake/config-ix.cmake.orig	2018-02-15 16:00:57.000000000 +0000
+++ cmake/config-ix.cmake
@@ -542,7 +542,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|SunOS")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|SunOS|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
@@ -590,14 +590,14 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND SCUDO_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Linux|Android|Fuchsia")
+    OS_NAME MATCHES "Linux|Android|Fuchsia|NetBSD")
   set(COMPILER_RT_HAS_SCUDO TRUE)
 else()
   set(COMPILER_RT_HAS_SCUDO FALSE)
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND XRAY_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD")
   set(COMPILER_RT_HAS_XRAY TRUE)
 else()
   set(COMPILER_RT_HAS_XRAY FALSE)
