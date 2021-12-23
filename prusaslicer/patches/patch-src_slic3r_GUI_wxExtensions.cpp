$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/wxExtensions.cpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/wxExtensions.cpp
@@ -17,7 +17,7 @@
 #include "../Utils/MacDarkMode.hpp"
 #include "BitmapComboBox.hpp"
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 // msw_menuitem_bitmaps is used for MSW and OSX
 static std::map<int, std::string> msw_menuitem_bitmaps;
 #ifdef __WXMSW__
@@ -677,9 +677,9 @@ void ModeButton::focus_button(const bool
     GetParent()->Refresh(); // force redraw a background of the selected mode button
 #else
     SetForegroundColour(wxSystemSettings::GetColour(focus ? wxSYS_COLOUR_BTNTEXT : 
-#if defined (__linux__) && defined (__WXGTK3__)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined (__WXGTK3__)
         wxSYS_COLOUR_GRAYTEXT
-#elif defined (__linux__) && defined (__WXGTK2__)
+#elif (defined (__linux__) || defined(__NetBSD__)) && defined (__WXGTK2__)
         wxSYS_COLOUR_BTNTEXT
 #else 
         wxSYS_COLOUR_BTNSHADOW
