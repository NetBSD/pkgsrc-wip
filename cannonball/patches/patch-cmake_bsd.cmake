$NetBSD$

Create a cmake file for BSD based builds.

--- cmake/bsd.cmake.orig	2019-08-18 00:41:57.311525123 +0000
+++ cmake/bsd.cmake
@@ -0,0 +1,23 @@
+# Default CMake Setup. Used for BSD Builds.
+
+set(lib_base ${BSD_PREFIX_PATH}/include)
+
+set(BOOST_INCLUDEDIR ${lib_base})
+
+set(sdl_root ${lib_base}/SDL)
+
+include_directories("${sdl_root}")
+
+link_libraries(cannonball
+    SDL
+)
+
+# Linking
+link_directories(
+    "${BSD_PREFIX_PATH}/lib"
+)
+
+# Location for Cannonball to create save files
+# Used to auto-generate setup.hpp with various file paths
+set(xml_directory ./)
+set(sdl_flags "SDL_DOUBLEBUF | SDL_SWSURFACE")
