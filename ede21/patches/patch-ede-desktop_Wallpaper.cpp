$NetBSD$

Add missing header.

--- ede-desktop/Wallpaper.cpp.orig	2025-01-22 11:06:38.943223541 +0000
+++ ede-desktop/Wallpaper.cpp
@@ -20,6 +20,7 @@
 
 #include <string.h>
 #include <stdlib.h>
+#include <FL/Fl_Group.H>
 #include <FL/Fl_Shared_Image.H>
 #include <FL/Fl_RGB_Image.H>
 #include <FL/fl_draw.H>
