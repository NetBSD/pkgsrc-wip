$NetBSD$

--- cmake/modules/AddLLDB.cmake.orig	2016-12-17 10:34:01.000000000 +0000
+++ cmake/modules/AddLLDB.cmake
@@ -142,6 +142,12 @@ function(add_lldb_executable name)
         endif()
       endif()
     endif()
+  else()
+    if(ARG_GENERATE_INSTALL)
+      install(TARGETS ${name}
+            COMPONENT ${name}
+            RUNTIME DESTINATION ${install_dir})
+    endif()
   endif()
 
   if(ARG_INCLUDE_IN_FRAMEWORK AND LLDB_BUILD_FRAMEWORK)
