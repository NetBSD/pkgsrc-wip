$NetBSD$

--- cmake/LLDBDependencies.cmake.orig	2017-01-31 17:20:58.000000000 +0000
+++ cmake/LLDBDependencies.cmake
@@ -115,6 +115,7 @@ endif ()
 # NetBSD-only libraries
 if ( CMAKE_SYSTEM_NAME MATCHES "NetBSD" )
   list(APPEND LLDB_USED_LIBS
+    lldbPluginProcessNetBSD
     lldbPluginProcessPOSIX
     )
 endif ()
