$NetBSD$

Add missing entries for NetBSD.

--- cmake/ConkyPlatformChecks.cmake.orig	2020-07-27 12:01:52.000000000 +0000
+++ cmake/ConkyPlatformChecks.cmake
@@ -83,6 +83,7 @@ endif(CMAKE_SYSTEM_NAME MATCHES "SunOS")
 
 if(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
   set(OS_NETBSD true)
+  set(conky_libs ${conky_libs} -lkvm -lossaudio -lprop)
 endif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
 
 if(CMAKE_SYSTEM_NAME MATCHES "Haiku")
@@ -96,6 +97,7 @@ endif(CMAKE_SYSTEM_NAME MATCHES "Darwin"
 
 if(NOT OS_LINUX
    AND NOT OS_FREEBSD
+   AND NOT OS_NETBSD
    AND NOT OS_OPENBSD
    AND NOT OS_DRAGONFLY
    AND NOT OS_SOLARIS
@@ -112,6 +114,9 @@ endif(NOT
       OS_FREEBSD
       AND
       NOT
+      OS_NETBSD
+      AND
+      NOT
       OS_OPENBSD
       AND
       NOT
