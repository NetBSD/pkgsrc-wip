$NetBSD$

--- cmake/config-ix.cmake.orig	2017-08-05 14:29:08.000000000 +0000
+++ cmake/config-ix.cmake
@@ -470,7 +470,7 @@ set(COMPILER_RT_SANITIZERS_TO_BUILD ${AL
 list_replace(COMPILER_RT_SANITIZERS_TO_BUILD all "${ALL_SANITIZERS}")
 
 if (SANITIZER_COMMON_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    (OS_NAME MATCHES "Android|Darwin|Linux|FreeBSD|Fuchsia" OR
+    (OS_NAME MATCHES "Android|Darwin|Linux|FreeBSD|NetBSD|Fuchsia" OR
     (OS_NAME MATCHES "Windows" AND (NOT MINGW AND NOT CYGWIN))))
   set(COMPILER_RT_HAS_SANITIZER_COMMON TRUE)
 else()
