$NetBSD$

* enable NetBSD

--- src/configure.cmake.orig	2022-10-27 18:39:22.613070517 +0000
+++ src/configure.cmake
@@ -7,7 +7,7 @@ set(INPUT_wayland_text_input_v4_wip OFF 
 
 #### Libraries
 
-if(LINUX OR QT_FIND_ALL_PACKAGES_ALWAYS)
+if(LINUX OR NETBSD OR QT_FIND_ALL_PACKAGES_ALWAYS)
     # waylandclient libraries
     qt_find_package(Wayland
         PROVIDED_TARGETS Wayland::Client
