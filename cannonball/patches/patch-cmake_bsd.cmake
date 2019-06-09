$NetBSD$

Create a cmake file for NetBSD build.

--- cmake/bsd.cmake.orig	2019-06-09 15:29:08.087446737 +0000
+++ cmake/bsd.cmake
@@ -0,0 +1,21 @@
+# Default CMake Setup. Used for NetBSD Builds.
+
+set(lib_base @PREFIX@/include)
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
+    "@PREFIX@/lib"
+)
+
+# Location for Cannonball to create save files
+# Used to auto-generate setup.hpp with various file paths
+set(xml_directory ./)
+set(sdl_flags "SDL_DOUBLEBUF | SDL_SWSURFACE")
