$NetBSD$

--- cmake/LLDBDependencies.cmake.orig	2016-12-17 10:34:01.000000000 +0000
+++ cmake/LLDBDependencies.cmake
@@ -115,6 +115,7 @@ endif ()
 # NetBSD-only libraries
 if ( CMAKE_SYSTEM_NAME MATCHES "NetBSD" )
   list(APPEND LLDB_USED_LIBS
+    lldbPluginProcessNetBSD
     lldbPluginProcessPOSIX
     )
 endif ()
