$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/wxExtensions.hpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/wxExtensions.hpp
@@ -16,7 +16,7 @@
 #include <functional>
 
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 void                sys_color_changed_menu(wxMenu* menu);
 #else 
 inline void         sys_color_changed_menu(wxMenu* /* menu */) {}
