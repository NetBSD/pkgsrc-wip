$NetBSD: patch-cmake_BuildPackages.cmake,v 1.1 2012/11/12 14:03:38 thomasklausner Exp $

Install into "share/doc" instead of non-standard "doc".

--- cmake/BuildPackages.cmake.orig	2011-11-08 09:16:36.000000000 +0000
+++ cmake/BuildPackages.cmake
@@ -86,5 +86,5 @@ endif() #UNIX
 # Common
 #
 
-install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION doc)
-install(FILES ${CMAKE_SOURCE_DIR}/README.txt DESTINATION doc)
+install(FILES ${CMAKE_SOURCE_DIR}/LICENCE.TXT DESTINATION share/doc)
+install(FILES ${CMAKE_SOURCE_DIR}/README.txt DESTINATION share/doc)
