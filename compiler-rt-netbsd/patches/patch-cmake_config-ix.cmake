$NetBSD$

--- cmake/config-ix.cmake.orig	2018-05-04 08:00:10.159967293 +0000
+++ cmake/config-ix.cmake
@@ -551,7 +551,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|SunOS")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|SunOS|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
@@ -599,7 +599,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND SCUDO_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Linux|Android|Fuchsia")
+    OS_NAME MATCHES "Linux|Android|Fuchsia|NetBSD")
   set(COMPILER_RT_HAS_SCUDO TRUE)
 else()
   set(COMPILER_RT_HAS_SCUDO FALSE)
