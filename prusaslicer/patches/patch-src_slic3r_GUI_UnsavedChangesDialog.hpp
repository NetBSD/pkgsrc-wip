$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/UnsavedChangesDialog.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/UnsavedChangesDialog.hpp
@@ -44,7 +44,7 @@ class ModelNode
     wxString            m_old_color;
     wxString            m_new_color;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     wxIcon              get_bitmap(const wxString& color);
 #else
     wxBitmap            get_bitmap(const wxString& color);
@@ -53,7 +53,7 @@ class ModelNode
 public:
 
     bool        m_toggle {true};
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     wxIcon      m_icon;
     wxIcon      m_old_color_bmp;
     wxIcon      m_new_color_bmp;
