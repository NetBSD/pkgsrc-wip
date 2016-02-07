$NetBSD$

--- src/pal/src/configure.cmake.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/pal/src/configure.cmake
@@ -9,6 +9,8 @@ include(CheckLibraryExists)
 
 if(CMAKE_SYSTEM_NAME STREQUAL FreeBSD)
   set(CMAKE_REQUIRED_INCLUDES /usr/local/include)
+elseif(CMAKE_SYSTEM_NAME STREQUAL NetBSD)
+  set(CMAKE_REQUIRED_INCLUDES /usr/pkg/include)
 elseif(CMAKE_SYSTEM_NAME STREQUAL SunOS)
   set(CMAKE_REQUIRED_INCLUDES /opt/local/include)
 endif()
