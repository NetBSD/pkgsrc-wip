$NetBSD$

--- cmake/libpoly.cmake.orig	2026-02-11 21:35:14.684915730 +0000
+++ cmake/libpoly.cmake
@@ -104,3 +104,7 @@ endif()
 if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
   find_package(LibInotify REQUIRED)
 endif()
+# NetBSD Support
+if(CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
+  find_package(LibInotify REQUIRED)
+endif()
