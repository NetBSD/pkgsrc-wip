$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/UnsavedChangesDialog.hpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/UnsavedChangesDialog.hpp
@@ -48,7 +48,7 @@ class ModelNode
     wxString            m_mod_color;
     wxString            m_new_color;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     wxIcon              get_bitmap(const wxString& color);
 #else
     wxBitmap            get_bitmap(const wxString& color);
@@ -57,7 +57,7 @@ class ModelNode
 public:
 
     bool        m_toggle {true};
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     wxIcon      m_icon;
     wxIcon      m_old_color_bmp;
     wxIcon      m_mod_color_bmp;
