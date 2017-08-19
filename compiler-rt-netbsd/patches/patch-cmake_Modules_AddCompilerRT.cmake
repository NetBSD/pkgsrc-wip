$NetBSD$

--- cmake/Modules/AddCompilerRT.cmake.orig	2017-08-03 21:24:37.000000000 +0000
+++ cmake/Modules/AddCompilerRT.cmake
@@ -202,10 +202,10 @@ function(add_compiler_rt_runtime name ty
     set_target_properties(${libname} PROPERTIES
         OUTPUT_NAME ${output_name_${libname}})
     set_target_properties(${libname} PROPERTIES FOLDER "Compiler-RT Runtime")
+    if(LIB_LINK_LIBS)
+      target_link_libraries(${libname} ${LIB_LINK_LIBS})
+    endif()
     if(${type} STREQUAL "SHARED")
-      if(LIB_LINK_LIBS)
-        target_link_libraries(${libname} ${LIB_LINK_LIBS})
-      endif()
       if(WIN32 AND NOT CYGWIN AND NOT MINGW)
         set_target_properties(${libname} PROPERTIES IMPORT_PREFIX "")
         set_target_properties(${libname} PROPERTIES IMPORT_SUFFIX ".lib")
@@ -320,6 +320,7 @@ macro(add_compiler_rt_test test_suite te
     set(TEST_LINK_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TEST_LINK_FLAGS}")
     separate_arguments(TEST_LINK_FLAGS)
   endif()
+
   add_custom_target(${test_name}
     COMMAND ${COMPILER_RT_TEST_COMPILER} ${TEST_OBJECTS}
             -o "${output_bin}"
