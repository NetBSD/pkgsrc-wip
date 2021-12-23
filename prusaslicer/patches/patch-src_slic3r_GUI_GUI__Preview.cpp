$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_Preview.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/GUI_Preview.cpp
@@ -359,7 +359,7 @@ void Preview::load_print(bool keep_z_ran
 
 void Preview::reload_print(bool keep_volumes)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here: a delayed release of OpenGL vertex buffers.
     if (!IsShown())
@@ -369,14 +369,14 @@ void Preview::reload_print(bool keep_vol
     }
 #endif /* __linux__ */
     if (
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         m_volumes_cleanup_required || 
 #endif /* __linux__ */
         !keep_volumes)
     {
         m_canvas->reset_volumes();
         m_loaded = false;
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         m_volumes_cleanup_required = false;
 #endif /* __linux__ */
     }
