$NetBSD$

Undef any Convex macro, regardless of OS.

--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -96,7 +96,7 @@ float RetinaHelper::get_scale_factor() {
 #endif // __WXGTK3__
 
 // Fixed the collision between BuildVolume::Type::Convex and macro Convex defined inside /usr/include/X11/X.h that is included by WxWidgets 3.0.
-#if defined(__linux__) && defined(Convex)
+#ifdef Convex
 #undef Convex
 #endif
 
