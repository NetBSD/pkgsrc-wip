$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.9 2022/11/14 18:44:05 adam Exp $

On Darwin, use correct install-name for shared libraries.

--- cmake/modules/AddLLVM.cmake.orig	2026-10-06 07:38:51.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -2694,7 +2694,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif("${CMAKE_SYSTEM_NAME}" MATCHES "AIX" AND BUILD_SHARED_LIBS)
     # $ORIGIN is not interpreted at link time by aix ld.
