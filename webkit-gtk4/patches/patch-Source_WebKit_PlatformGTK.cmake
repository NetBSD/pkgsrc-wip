$NetBSD: patch-Source_WebKit_PlatformGTK.cmake,v 1.3 2019/03/13 20:49:41 leot Exp $

SunOS ld does not support --version-script.

--- Source/WebKit/PlatformGTK.cmake.orig	2020-09-11 08:11:29.000000000 +0000
+++ Source/WebKit/PlatformGTK.cmake
@@ -24,7 +24,7 @@ add_definitions(-DLOCALEDIR="${CMAKE_INS
 add_definitions(-DDATADIR="${CMAKE_INSTALL_FULL_DATADIR}")
 add_definitions(-DLIBDIR="${LIB_INSTALL_DIR}")
 
-if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
+if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin" AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
     WEBKIT_ADD_TARGET_PROPERTIES(WebKit LINK_FLAGS "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/webkitglib-symbols.map")
 endif ()
 
@@ -492,6 +492,11 @@ if (GTK_UNIX_PRINT_FOUND)
     list(APPEND WebKit_LIBRARIES GTK::UnixPrint)
 endif ()
 
+if (USE_ATK)
+    list(APPEND WebKit_LIBRARIES ${ATK_LIBRARIES})
+    list(APPEND WebKit_SYSTEM_INCLUDE_DIRECTORIES ${ATK_INCLUDE_DIRS})
+endif ()
+
 if (LIBNOTIFY_FOUND)
     list(APPEND WebKit_PRIVATE_LIBRARIES
         ${LIBNOTIFY_LIBRARIES}
