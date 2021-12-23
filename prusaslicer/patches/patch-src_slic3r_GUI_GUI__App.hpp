$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_App.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/GUI_App.hpp
@@ -112,7 +112,7 @@ private:
     bool            m_app_conf_exists{ false };
     EAppMode        m_app_mode{ EAppMode::Editor };
     bool            m_is_recreating_gui{ false };
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     bool            m_opengl_initialized{ false };
 #endif
 
