$NetBSD$

--- cmake/Modules/CompilerRTUtils.cmake.orig	2018-06-01 09:39:33.000000000 +0000
+++ cmake/Modules/CompilerRTUtils.cmake
@@ -140,6 +140,11 @@ macro(test_target_arch arch def)
 
   set(TARGET_${arch}_CFLAGS ${ARGN})
   set(TARGET_${arch}_LINK_FLAGS ${ARGN})
+  if (COMPILER_RT_RUNTIME_LIBRARY STREQUAL "builtins")
+    include(HandleCompilerRT)
+    find_compiler_rt_library(builtins COMPILER_RT_BUILTINS_LIBRARY_${arch} ${ARGN})
+    list(APPEND TARGET_${arch}_LINK_FLAGS ${COMPILER_RT_BUILTINS_LIBRARY_${arch}})
+  endif()
   set(argstring "")
   foreach(arg ${ARGN})
     set(argstring "${argstring} ${arg}")
