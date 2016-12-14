$NetBSD$

--- cmake/LLDBDependencies.cmake.orig	2016-12-14 14:10:24.000000000 +0000
+++ cmake/LLDBDependencies.cmake
@@ -115,6 +115,7 @@ endif ()
 # NetBSD-only libraries
 if ( CMAKE_SYSTEM_NAME MATCHES "NetBSD" )
   list(APPEND LLDB_USED_LIBS
+    lldbPluginProcessLinux
     lldbPluginProcessPOSIX
     )
 endif ()
