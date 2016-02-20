$NetBSD$
--- ./cmake/FindFaad.cmake.orig	2016-02-19 22:34:01.000000000 -0800
+++ ./cmake/FindFaad.cmake	2016-02-19 22:34:54.000000000 -0800
@@ -29,7 +29,7 @@
   find_library(FAAD_LIBRARY NAMES faad PATHS $ENV{PROGRAMFILES}/FAAD/lib DOC "The libfaad library")
 
 else(WIN32)
-  find_path(FAAD_INCLUDE_DIR faad.h DOC "The directory where faad.h resides")
+  find_path(FAAD_INCLUDE_DIR NAMES faad.h faad2/faad.h DOC "The directory where faad.h resides")
   find_library(FAAD_LIBRARY NAMES faad DOC "The libfaad library")
 
 endif(WIN32)
