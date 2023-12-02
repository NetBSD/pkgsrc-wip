$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GLCanvas3D.cpp.orig	2023-11-23 14:51:47.000000000 +0000
+++ src/slic3r/GUI/GLCanvas3D.cpp
@@ -108,7 +108,7 @@ float RetinaHelper::get_scale_factor() {
 #endif // __WXGTK3__
 
 // Fixed the collision between BuildVolume::Type::Convex and macro Convex defined inside /usr/include/X11/X.h that is included by WxWidgets 3.0.
-#if defined(__linux__) && defined(Convex)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(Convex)
 #undef Convex
 #endif
 
@@ -3622,7 +3622,7 @@ void GLCanvas3D::on_mouse(wxMouseEvent& 
             mouse_up_cleanup();
         }
 
-//#if defined(__WXMSW__) || defined(__linux__)
+//#if defined(__WXMSW__) || defined(__linux__) || defined(__NetBSD__)
 //        // On Windows and Linux needs focus in order to catch key events
         if (m_canvas != nullptr) {
 
