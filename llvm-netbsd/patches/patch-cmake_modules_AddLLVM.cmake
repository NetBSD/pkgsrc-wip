$NetBSD$

--- cmake/modules/AddLLVM.cmake.orig	2018-06-07 17:17:28.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -774,6 +774,9 @@ macro(add_llvm_executable name)
 endmacro(add_llvm_executable name)
 
 function(export_executable_symbols target)
+  if (LLVM_BUILD_STATIC AND ${CMAKE_SYSTEM_NAME} MATCHES "NetBSD")
+    return()
+  endif()
   if (LLVM_EXPORTED_SYMBOL_FILE)
     # The symbol file should contain the symbols we want the executable to
     # export
