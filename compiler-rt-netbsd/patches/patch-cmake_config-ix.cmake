$NetBSD$

--- cmake/config-ix.cmake.orig	2018-06-01 09:39:33.000000000 +0000
+++ cmake/config-ix.cmake
@@ -13,10 +13,7 @@ function(check_linker_flag flag out_var)
 endfunction()
 
 check_library_exists(c fopen "" COMPILER_RT_HAS_LIBC)
-if (COMPILER_RT_RUNTIME_LIBRARY STREQUAL "builtins")
-  include(HandleCompilerRT)
-  find_compiler_rt_library(builtins COMPILER_RT_BUILTINS_LIBRARY)
-else()
+if (NOT COMPILER_RT_RUNTIME_LIBRARY STREQUAL "builtins")
   if (ANDROID)
     check_library_exists(gcc __gcc_personality_v0 "" COMPILER_RT_HAS_GCC_LIB)
   else()
@@ -547,7 +544,7 @@ else()
 endif()
 
 if (PROFILE_SUPPORTED_ARCH AND NOT LLVM_USE_SANITIZER AND
-    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|SunOS")
+    OS_NAME MATCHES "Darwin|Linux|FreeBSD|Windows|Android|SunOS|NetBSD")
   set(COMPILER_RT_HAS_PROFILE TRUE)
 else()
   set(COMPILER_RT_HAS_PROFILE FALSE)
@@ -595,7 +592,7 @@ else()
 endif()
 
 if (COMPILER_RT_HAS_SANITIZER_COMMON AND SCUDO_SUPPORTED_ARCH AND
-    OS_NAME MATCHES "Linux|Android|Fuchsia")
+    OS_NAME MATCHES "Linux|Android|Fuchsia|NetBSD")
   set(COMPILER_RT_HAS_SCUDO TRUE)
 else()
   set(COMPILER_RT_HAS_SCUDO FALSE)
