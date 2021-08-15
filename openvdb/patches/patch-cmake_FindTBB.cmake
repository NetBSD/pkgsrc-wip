$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- cmake/FindTBB.cmake.orig	2021-06-11 21:38:41.000000000 +0000
+++ cmake/FindTBB.cmake
@@ -169,8 +169,22 @@ find_path(Tbb_INCLUDE_DIR tbb/tbb_stddef
   PATH_SUFFIXES ${CMAKE_INSTALL_INCLUDEDIR} include
 )
 
-if(EXISTS "${Tbb_INCLUDE_DIR}/tbb/tbb_stddef.h")
-  file(STRINGS "${Tbb_INCLUDE_DIR}/tbb/tbb_stddef.h"
+set(_tbb_version_file "${Tbb_INCLUDE_DIR}/tbb/tbb_stddef.h")
+
+if(NOT EXISTS ${_tbb_version_file})
+  # From TBB 2021, tbb_stddef is removed and the directory include/tbb is
+  # simply an alias for include/oneapi/tbb. Try and find the version header
+  # in oneapi/tbb
+  find_path(Tbb_INCLUDE_DIR oneapi/tbb/version.h
+    ${_FIND_TBB_ADDITIONAL_OPTIONS}
+    PATHS ${_TBB_INCLUDE_SEARCH_DIRS}
+    PATH_SUFFIXES ${CMAKE_INSTALL_INCLUDEDIR} include
+  )
+  set(_tbb_version_file "${Tbb_INCLUDE_DIR}/oneapi/tbb/version.h")
+endif()
+
+if(EXISTS ${_tbb_version_file})
+  file(STRINGS ${_tbb_version_file}
     _tbb_version_major_string REGEX "#define TBB_VERSION_MAJOR "
   )
   string(REGEX REPLACE "#define TBB_VERSION_MAJOR" ""
@@ -178,7 +192,7 @@ if(EXISTS "${Tbb_INCLUDE_DIR}/tbb/tbb_st
   )
   string(STRIP "${_tbb_version_major_string}" Tbb_VERSION_MAJOR)
 
-  file(STRINGS "${Tbb_INCLUDE_DIR}/tbb/tbb_stddef.h"
+  file(STRINGS ${_tbb_version_file}
      _tbb_version_minor_string REGEX "#define TBB_VERSION_MINOR "
   )
   string(REGEX REPLACE "#define TBB_VERSION_MINOR" ""
@@ -192,6 +206,8 @@ if(EXISTS "${Tbb_INCLUDE_DIR}/tbb/tbb_st
   set(Tbb_VERSION ${Tbb_VERSION_MAJOR}.${Tbb_VERSION_MINOR})
 endif()
 
+unset(_tbb_version_file)
+
 # ------------------------------------------------------------------------
 #  Search for TBB lib DIR
 # ------------------------------------------------------------------------
