$NetBSD$

The release tarball does not ship the flatpak integration directory used
for developer builds.  Guard the add_subdirectory() against its absence.
https://github.com/WebKit/WebKit/pull/64697

--- Tools/PlatformGTK.cmake.orig	2026-05-11 18:25:01.546362945 +0000
+++ Tools/PlatformGTK.cmake
@@ -1,5 +1,7 @@ if (DEVELOPER_MODE)
 if (DEVELOPER_MODE)
-    add_subdirectory(flatpak)
+    if (EXISTS "${CMAKE_SOURCE_DIR}/flatpak")
+        add_subdirectory(flatpak)
+    endif ()
 endif ()
 
 if (ENABLE_API_TESTS)
