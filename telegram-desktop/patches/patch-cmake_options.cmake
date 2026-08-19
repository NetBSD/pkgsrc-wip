$NetBSD$

Treat NetBSD as Linux for platform options and set LINUX so that all
if (LINUX) guards throughout the build system work correctly.

--- cmake/options.cmake.orig	2026-07-27 20:19:00.000000000 +0000
+++ cmake/options.cmake
@@ -14,8 +14,9 @@ target_compile_definitions(common_options
 if (WIN32)
     include(cmake/options_win.cmake)
 elseif (APPLE)
     include(cmake/options_mac.cmake)
-elseif (LINUX)
+elseif (LINUX OR CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
+    set(LINUX TRUE)
     include(cmake/options_linux.cmake)
 else()
     message(FATAL_ERROR "Unknown platform type")
