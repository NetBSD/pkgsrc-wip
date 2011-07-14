$NetBSD: patch-kalgebra_cmake_FindReadline.cmake,v 1.1 2011/07/14 12:41:41 mwdavies Exp $

--- kalgebra/cmake/FindReadline.cmake.orig	2011-06-03 21:41:04.000000000 +0000
+++ kalgebra/cmake/FindReadline.cmake
@@ -7,7 +7,7 @@ else(READLINE_INCLUDE_DIR AND READLINE_L
 	)
 	
 	FIND_LIBRARY(READLINE_LIBRARY NAMES readline)
-        FIND_LIBRARY(NCURSES_LIBRARY NAMES ncurses )
+        FIND_LIBRARY(NCURSES_LIBRARY NAMES termcap ncurses )
         include(FindPackageHandleStandardArgs)
         FIND_PACKAGE_HANDLE_STANDARD_ARGS(Readline DEFAULT_MSG NCURSES_LIBRARY READLINE_INCLUDE_DIR READLINE_LIBRARY )
 	
