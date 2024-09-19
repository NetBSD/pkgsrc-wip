$NetBSD: patch-cmake_modules_AddLLVM.cmake,v 1.1 2016/03/11 06:50:42 tnn Exp $

Don't use non-portable -z discard-unused on SunOS.

--- cmake/modules/AddLLVM.cmake.orig	2016-02-12 17:52:29.000000000 +0000
+++ cmake/modules/AddLLVM.cmake
@@ -174,9 +174,9 @@ function(add_link_opts target_name)
         # ld64's implementation of -dead_strip breaks tools that use plugins.
         set_property(TARGET ${target_name} APPEND_STRING PROPERTY
                      LINK_FLAGS " -Wl,-dead_strip")
-      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
-        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
-                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
+#      elseif(${CMAKE_SYSTEM_NAME} MATCHES "SunOS")
+#        set_property(TARGET ${target_name} APPEND_STRING PROPERTY
+#                     LINK_FLAGS " -Wl,-z -Wl,discard-unused=sections")
       elseif(NOT WIN32 AND NOT LLVM_LINKER_IS_GOLD)
         # Object files are compiled with -ffunction-data-sections.
         # Versions of bfd ld < 2.23.1 have a bug in --gc-sections that breaks
@@ -546,7 +546,7 @@ macro(add_llvm_library name)
     set_target_properties( ${name} PROPERTIES EXCLUDE_FROM_ALL ON)
   elseif(NOT _is_gtest)
     if (NOT LLVM_INSTALL_TOOLCHAIN_ONLY OR ${name} STREQUAL "LTO")
-      set(install_dir lib${LLVM_LIBDIR_SUFFIX})
+	    set(install_dir lib/libLLVM38)
       if(ARG_SHARED OR BUILD_SHARED_LIBS)
         if(WIN32 OR CYGWIN OR MINGW)
           set(install_type RUNTIME)
@@ -590,12 +590,12 @@ macro(add_llvm_loadable_module name)
           # DLL platform
           set(dlldir "bin")
         else()
-          set(dlldir "lib${LLVM_LIBDIR_SUFFIX}")
+		set(dlldir "lib/libLLVM38")
         endif()
         install(TARGETS ${name}
           EXPORT LLVMExports
           LIBRARY DESTINATION ${dlldir}
-          ARCHIVE DESTINATION lib${LLVM_LIBDIR_SUFFIX})
+	  ARCHIVE DESTINATION libLLVM38)
       endif()
       set_property(GLOBAL APPEND PROPERTY LLVM_EXPORTS ${name})
     endif()
@@ -702,7 +702,7 @@ macro(add_llvm_tool name)
     if( LLVM_BUILD_TOOLS )
       install(TARGETS ${name}
               EXPORT LLVMExports
-              RUNTIME DESTINATION bin
+	      RUNTIME DESTINATION libexec/libLLVM38
               COMPONENT ${name})
 
       if (NOT CMAKE_CONFIGURATION_TYPES)
@@ -738,7 +738,7 @@ macro(add_llvm_utility name)
   set_target_properties(${name} PROPERTIES FOLDER "Utils")
   if( LLVM_INSTALL_UTILS )
     install (TARGETS ${name}
-      RUNTIME DESTINATION bin
+	    RUNTIME DESTINATION libexec/libLLVM38
       COMPONENT ${name})
     if (NOT CMAKE_CONFIGURATION_TYPES)
       add_custom_target(install-${name}
