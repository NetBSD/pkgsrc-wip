$NetBSD$

Disable library install rules. Handled manually.
Make sure llvm-config goes in libexec/libLLVM to avoid conflict.
Don't use non-portable -z discard-unused on SunOS.
Don't use relative @rpath in llvm-config on Darwin.

--- cmake/modules/AddLLVM.cmake.orig	2021-06-28 16:23:38.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -594,12 +594,12 @@ function(llvm_add_library name)
       set(library_name ${output_name}-${LLVM_VERSION_MAJOR}${LLVM_VERSION_SUFFIX})
       set(api_name ${output_name}-${LLVM_VERSION_MAJOR}.${LLVM_VERSION_MINOR}.${LLVM_VERSION_PATCH}${LLVM_VERSION_SUFFIX})
       set_target_properties(${name} PROPERTIES OUTPUT_NAME ${library_name})
-      llvm_install_library_symlink(${api_name} ${library_name} SHARED
-        COMPONENT ${name}
-        ALWAYS_GENERATE)
-      llvm_install_library_symlink(${output_name} ${library_name} SHARED
-        COMPONENT ${name}
-        ALWAYS_GENERATE)
+#      llvm_install_library_symlink(${api_name} ${library_name} SHARED
+#        COMPONENT ${name}
+#        ALWAYS_GENERATE)
+#      llvm_install_library_symlink(${output_name} ${library_name} SHARED
+#        COMPONENT ${name}
+#        ALWAYS_GENERATE)
     endif()
   endif()
 
@@ -802,12 +802,6 @@ macro(add_llvm_library name)
         set_property(GLOBAL PROPERTY LLVM_HAS_EXPORTS True)
       endif()
 
-      install(TARGETS ${name}
-              ${export_to_llvmexports}
-              LIBRARY DESTINATION lib${LLVM_LIBDIR_SUFFIX} COMPONENT ${name}
-              ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX} COMPONENT ${name}
-              RUNTIME DESTINATION bin COMPONENT ${name})
-
       if (NOT LLVM_ENABLE_IDE)
         add_llvm_install_targets(install-${name}
                                  DEPENDS ${name}
@@ -1015,7 +1009,7 @@ function(process_llvm_pass_plugins)
 
       ## Part 1: Extension header to be included whenever we need extension
       #  processing.
-      set(LLVM_INSTALL_PACKAGE_DIR lib${LLVM_LIBDIR_SUFFIX}/cmake/llvm)
+      set(LLVM_INSTALL_PACKAGE_DIR lib/libLLVM/cmake/llvm)
       set(llvm_cmake_builddir "${LLVM_BINARY_DIR}/${LLVM_INSTALL_PACKAGE_DIR}")
       file(WRITE
           "${llvm_cmake_builddir}/LLVMConfigExtensions.cmake"
@@ -1219,7 +1213,7 @@ macro(add_llvm_tool name)
 
       install(TARGETS ${name}
               ${export_to_llvmexports}
-              RUNTIME DESTINATION ${LLVM_TOOLS_INSTALL_DIR}
+              RUNTIME DESTINATION libexec/libLLVM
               COMPONENT ${name})
 
       if (NOT LLVM_ENABLE_IDE)
@@ -2099,7 +2093,7 @@ function(llvm_setup_rpath name)
   endif()
 
   if (APPLE)
-    set(_install_name_dir INSTALL_NAME_DIR "@rpath")
+    set(_install_name_dir INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib/libLLVM")
     set(_install_rpath "@loader_path/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
