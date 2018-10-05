$NetBSD$

--- cmake/config-ix.cmake.orig	2018-10-05 07:12:08.792736398 +0000
+++ cmake/config-ix.cmake
@@ -584,7 +584,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|Fuchsia|SunOS")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|Fuchsia|SunOS|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
@@ -632,7 +632,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND SCUDO_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Linux|Android|Fuchsia")
+    OS_NAME MATCHES "Linux|Android|Fuchsia|NetBSD")
   set(COMPILER_RT_HAS_SCUDO TRUE)
 else()
   set(COMPILER_RT_HAS_SCUDO FALSE)
