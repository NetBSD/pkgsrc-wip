$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/wxExtensions.hpp.orig	2024-06-14 21:54:48.000000000 +0000
+++ src/slic3r/GUI/wxExtensions.hpp
@@ -21,7 +21,7 @@
 #include <boost/filesystem.hpp>
 
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 void                sys_color_changed_menu(wxMenu* menu);
 #else 
 inline void         sys_color_changed_menu(wxMenu* /* menu */) {}
