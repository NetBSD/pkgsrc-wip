$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_Preview.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/GUI_Preview.hpp
@@ -95,7 +95,7 @@ class Preview : public wxPanel
     BackgroundSlicingProcess* m_process;
     GCodeProcessorResult* m_gcode_result;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here.
     bool m_volumes_cleanup_required { false };
