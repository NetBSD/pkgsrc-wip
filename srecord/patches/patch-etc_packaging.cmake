$NetBSD$

Upstream's installation procedure is intermingled with windows bits,
on top of being cmake.

--- etc/packaging.cmake.orig	2022-10-09 08:53:05.000000000 +0000
+++ etc/packaging.cmake
@@ -42,15 +42,6 @@ FUNCTION(INSTALL_SRECORD_EXECUTABLE_TARG
     list(APPEND DLL_SEARCH_DIRS "${COMPILER_C_DIR}")
     list(APPEND DLL_SEARCH_DIRS "${COMPILER_CXX_DIR}")
   endif()
-
-  install(IMPORTED_RUNTIME_ARTIFACTS ${target}
-    RUNTIME_DEPENDENCY_SET ${PROJECT_NAME}_dlls COMPONENT ${target})
-  install(RUNTIME_DEPENDENCY_SET ${PROJECT_NAME}_dlls
-    PRE_EXCLUDE_REGEXES "api-ms-" "ext-ms-"
-    POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
-    DIRECTORIES ${DLL_SEARCH_DIRS}
-    COMPONENT ${target}
-    )
 ENDFUNCTION()
 
 # Packaging
