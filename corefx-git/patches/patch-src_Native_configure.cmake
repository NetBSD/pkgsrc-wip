$NetBSD$

--- src/Native/configure.cmake.orig	2016-03-01 04:32:05.000000000 +0000
+++ src/Native/configure.cmake
@@ -16,7 +16,6 @@ elseif (CMAKE_SYSTEM_NAME STREQUAL FreeB
     include_directories(SYSTEM /usr/local/include)
 elseif (CMAKE_SYSTEM_NAME STREQUAL NetBSD)
     set(PAL_UNIX_NAME \"NETBSD\")
-    include_directories(SYSTEM /usr/pkg/include)
 else ()
     message(FATAL_ERROR "Unknown platform.  Cannot define PAL_UNIX_NAME, used by RuntimeInformation.")
 endif ()
