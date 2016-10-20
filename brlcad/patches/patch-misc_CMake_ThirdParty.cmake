$NetBSD$

Allow to pass library defintion from command-line.
CMake part in this project is broken and fails to detect some libraries/headers
for unknown reason.

--- misc/CMake/ThirdParty.cmake.orig	2016-08-09 06:52:32.000000000 +0000
+++ misc/CMake/ThirdParty.cmake
@@ -181,15 +181,15 @@ macro(THIRD_PARTY dir varname_root build
     set(${varname_root}_FOUND_STATUS ${${varname_root}_FOUND})
 
     # Initialize (or rather, uninitialize) variables in preparation for search
-    set(${varname_root}_FOUND "${varname_root}-NOTFOUND" CACHE STRING "${varname_root}_FOUND" FORCE)
-    mark_as_advanced(${varname_root}_FOUND)
-    set(${varname_root}_LIBRARY "${varname_root}-NOTFOUND" CACHE STRING "${varname_root}_LIBRARY" FORCE)
-    set(${varname_root}_INCLUDE_DIR "${varname_root}-NOTFOUND" CACHE STRING "${varname_root}_INCLUDE_DIR" FORCE)
+#    set(${varname_root}_FOUND "${varname_root}-NOTFOUND" CACHE STRING "${varname_root}_FOUND" FORCE)
+#    mark_as_advanced(${varname_root}_FOUND)
+#    set(${varname_root}_LIBRARY "${varname_root}-NOTFOUND" CACHE STRING "${varname_root}_LIBRARY" FORCE)
+#    set(${varname_root}_INCLUDE_DIR "${varname_root}-NOTFOUND" CACHE STRING "${varname_root}_INCLUDE_DIR" FORCE)
 
     # Be quiet if we're doing this over
-    if("${${varname_root}_FOUND_STATUS}" MATCHES "NOTFOUND")
-      set(${varname_root}_FIND_QUIETLY TRUE)
-    endif("${${varname_root}_FOUND_STATUS}" MATCHES "NOTFOUND")
+#    if("${${varname_root}_FOUND_STATUS}" MATCHES "NOTFOUND")
+#      set(${varname_root}_FIND_QUIETLY TRUE)
+#    endif("${${varname_root}_FOUND_STATUS}" MATCHES "NOTFOUND")
 
     # Find the package in question.  It is the toplevel CMakeLists.txt's responsibility to make
     # sure that the CMAKE_MODULE_PATH variable is set correctly if there are local versions of
