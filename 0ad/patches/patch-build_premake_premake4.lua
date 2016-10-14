$NetBSD$

--- build/premake/premake4.lua.orig	2016-03-12 18:15:04.000000000 +0000
+++ build/premake/premake4.lua
@@ -398,6 +398,8 @@ function project_add_x11_dirs()
 		includedirs {
 			"/usr/X11R6/include/X11",
 			"/usr/X11R6/include",
+			"/usr/X11R7/include/X11",
+			"/usr/X11R7/include",
 			"/usr/local/include/X11",
 			"/usr/local/include",
 			"/usr/include/X11"
