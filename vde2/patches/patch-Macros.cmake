$NetBSD$

from https://github.com/virtualsquare/vde-2/issues/70

--- Macros.cmake.orig	2026-08-03 10:48:09.000000000 +0000
+++ Macros.cmake
@@ -1,4 +1,4 @@
-include(CheckIncludeFile)
+include(CheckIncludeFiles)
 include(CheckFunctionExists)
 include(CheckLibraryExists)
 include(CheckTypeSize)
@@ -30,7 +30,7 @@ macro(cm_check_lib libname)
 endmacro()
 
 macro(cm_check_include include var)
-    check_include_file(${include} ${var})
+    check_include_files("${include}" ${var})
     if(${var})
         set(defines ${defines} "#cmakedefine ${var}\n\n")
     else()
@@ -73,4 +73,4 @@ macro(cm_configure_file to_file)
     file(WRITE ${default_conf_file} ${defines})
     configure_file(${default_conf_file} ${to_file})
     file(REMOVE ${default_conf_file}) # uncomment if you want to check the template
-endmacro()
\ No newline at end of file
+endmacro()
