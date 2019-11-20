$NetBSD$

--- cmake/modules/FindOpenBabel2.cmake.orig	2019-03-13 20:46:48.000000000 +0000
+++ cmake/modules/FindOpenBabel2.cmake
@@ -20,15 +20,15 @@ else (OPENBABEL2_INCLUDE_DIR AND OPENBAB
   # not cached
   if(NOT WIN32)
 #    set(PKG_CONFIG_PATH ${PKG_CONFIG_PATH} /usr/local)
-    pkg_check_modules(OPENBABEL2 openbabel-2.0)
+    pkg_check_modules(OPENBABEL2 openbabel-3)
 
-    # query pkg-config asking for a openbabel >= 2.1.0
-    exec_program(${PKG_CONFIG_EXECUTABLE} ARGS --atleast-version=2.1.0 openbabel-2.0 RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull )
+    # query pkg-config asking for a openbabel >= 3.0.0
+    exec_program(${PKG_CONFIG_EXECUTABLE} ARGS --atleast-version=3.0.0 openbabel-3 RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull )
     if(_return_VALUE STREQUAL "0")
       set(OPENBABEL_MINI_FOUND TRUE)
     endif(_return_VALUE STREQUAL "0")
 
-    exec_program(${PKG_CONFIG_EXECUTABLE} ARGS --variable=pkgincludedir openbabel-2.0 RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _obPkgIncDir )
+    exec_program(${PKG_CONFIG_EXECUTABLE} ARGS --variable=pkgincludedir openbabel-3 RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _obPkgIncDir )
     message(STATUS "Querying include dir: ${_obPkgIncDir}")
     if (_obPkgIncDir)
       set(OPENBABEL2_INCLUDE_DIR "${_obPkgIncDir}")
