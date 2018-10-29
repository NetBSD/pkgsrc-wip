$NetBSD$

--- cmake/Modules/HandleCompilerRT.cmake.orig	2018-10-26 19:41:21.261220908 +0000
+++ cmake/Modules/HandleCompilerRT.cmake
@@ -1,5 +1,5 @@
 function(find_compiler_rt_library name variable)
-  set(CLANG_COMMAND ${CMAKE_CXX_COMPILER} ${SANITIZER_COMMON_CFLAGS}
+  set(CLANG_COMMAND ${CMAKE_CXX_COMPILER} ${SANITIZER_COMMON_CFLAGS} ${ARGN}
       "--rtlib=compiler-rt" "--print-libgcc-file-name")
   if (CMAKE_CXX_COMPILER_ID MATCHES Clang AND CMAKE_CXX_COMPILER_TARGET)
     list(APPEND CLANG_COMMAND "--target=${CMAKE_CXX_COMPILER_TARGET}")
