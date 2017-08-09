$NetBSD$

--- cmake/config-ix.cmake.orig	2017-08-08 20:43:41.000000000 +0000
+++ cmake/config-ix.cmake
@@ -541,7 +541,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND SAFESTACK_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|NetBSD")
   set(COMPILER_RT_HAS_SAFESTACK TRUE)
 else()
   set(COMPILER_RT_HAS_SAFESTACK FALSE)
