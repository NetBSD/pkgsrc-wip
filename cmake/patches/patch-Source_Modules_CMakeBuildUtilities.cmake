$NetBSD: patch-Source_Modules_CMakeBuildUtilities.cmake,v 1.1 2022/11/22 19:14:03 adam Exp $

Don't insist on ncurses.

--- Source/Modules/CMakeBuildUtilities.cmake.orig	2025-08-05 14:55:57.000000000 +0000
+++ Source/Modules/CMakeBuildUtilities.cmake
@@ -354,7 +354,6 @@ if(NOT DEFINED BUILD_CursesDialog)
 endif()
 if(BUILD_CursesDialog)
   if(UNIX)
-    set(CURSES_NEED_NCURSES TRUE)
     find_package(Curses)
     if(NOT Curses_FOUND)
       message(WARNING
