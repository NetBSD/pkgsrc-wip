$NetBSD: patch-cmake_modules_FindFreetype.cmake,v 1.1 2014/02/05 09:36:21 nsloss Exp $

Fix finding location of freetype2 on NetBSD

--- cmake/modules/FindFreetype.cmake.orig	2012-06-26 15:46:32.000000000 +0000
+++ cmake/modules/FindFreetype.cmake
@@ -10,12 +10,13 @@
 FIND_PATH(FREETYPE_INCLUDE_DIR freetype/config/ftheader.h
 /usr/local/include/freetype2
 /usr/include/freetype2
+${CMAKE_INSTALL_PREFIX}/include/freetype2
 )
 
 SET(FREETYPE_NAMES ${FREETYPE_NAMES} freetype)
 FIND_LIBRARY(FREETYPE_LIBRARY
   NAMES ${FREETYPE_NAMES}
-  PATHS /usr/local/lib /usr/lib
+  PATHS /usr/local/lib /usr/lib ${CMAKE_INSTALL_PREFIX}/lib
   )
 
 IF (FREETYPE_LIBRARY AND FREETYPE_INCLUDE_DIR)
