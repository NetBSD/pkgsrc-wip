$NetBSD$

jsoncpp does not provide a pkg-config file, don't insist on one.

--- cmake/FindJsoncpp.cmake.orig	2016-01-17 17:41:13.000000000 +0000
+++ cmake/FindJsoncpp.cmake
@@ -6,7 +6,6 @@
 #  Jsoncpp_LIBRARIES - link these to use Jsoncpp
 
 find_package(PkgConfig)
-pkg_check_modules(PC_JSONCPP REQUIRED jsoncpp)
 
 find_path(JSONCPP_INCLUDE_DIR
   NAMES
