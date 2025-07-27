$NetBSD$

Treat NetBSD like FreeBSD.

--- buildscripts/packaging/Linux+BSD/SetupAppImagePackaging.cmake.orig	2025-04-24 13:59:18.000000000 +0000
+++ buildscripts/packaging/Linux+BSD/SetupAppImagePackaging.cmake
@@ -1,6 +1,6 @@
 include(GetPlatformInfo)
 
-if(NOT(OS_IS_LIN OR OS_IS_FBSD))
+if(NOT(OS_IS_LIN OR OS_IS_FBSD OR OS_IS_NBSD))
     return()
 endif()
 
