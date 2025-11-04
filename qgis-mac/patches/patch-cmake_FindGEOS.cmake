$NetBSD$

On Darwin, don't look for frameworks.

--- cmake/FindGEOS.cmake.orig	2024-04-19 12:01:44.000000000 +0000
+++ cmake/FindGEOS.cmake
@@ -42,7 +42,7 @@ if(NOT GEOS_FOUND)
    IF(UNIX)
       # try to use framework on mac
       # want clean framework path, not unix compatibility path
-      IF (APPLE)
+      IF (FALSE)
         IF (CMAKE_FIND_FRAMEWORK MATCHES "FIRST"
             OR CMAKE_FRAMEWORK_PATH MATCHES "ONLY"
             OR NOT CMAKE_FIND_FRAMEWORK)
