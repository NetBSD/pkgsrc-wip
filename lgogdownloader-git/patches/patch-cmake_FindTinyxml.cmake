$NetBSD$

tinyxml does not provide a pkg-config file, don't insist on one.

--- cmake/FindTinyxml.cmake.orig	2016-01-17 17:41:13.000000000 +0000
+++ cmake/FindTinyxml.cmake
@@ -6,7 +6,6 @@
 #  Tinyxml_LIBRARIES - The libraries needed to use tinyxml
 
 find_package(PkgConfig)
-pkg_check_modules(PC_TINYXML REQUIRED tinyxml)
 
 find_path(TINYXML_INCLUDE_DIR tinyxml.h
   HINTS
