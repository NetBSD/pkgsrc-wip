$NetBSD$

--- vm/cmake/platform.cmake.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/cmake/platform.cmake
@@ -53,6 +53,15 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "(Solar
   set(platform_name "Solaris")  
   set(platform "svr4")
   set(TARGET_OS_VERSION "SOLARIS_VERSION")
+
+elseif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
+  
+  set(platform_kind "unix")
+  set(TARGET_OS_FAMILY  "UNIX_FAMILY")
+  
+  set(platform_name "NetBSD")
+  set(platform "netbsd")
+  set(TARGET_OS_VERSION "NETBSD_VERSION")
   
 else()
   
@@ -87,6 +96,3 @@ mark_as_advanced(DYNAMIC COMPILER TARGET
 
 
 message(STATUS "Preparing for ${platform_name} on ${platform_processor}")
-
-
-
