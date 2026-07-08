$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/wxExtensions.cpp.orig	2026-06-25 15:30:20.000000000 +0000
+++ src/slic3r/GUI/wxExtensions.cpp
@@ -30,7 +30,7 @@
 #include "libslic3r/Color.hpp"
 #include "libslic3r/Model.hpp"
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
 // msw_menuitem_bitmaps is used for MSW and OSX
 static std::map<int, std::string> msw_menuitem_bitmaps;
 void sys_color_changed_menu(wxMenu* menu)
@@ -143,7 +143,7 @@ wxMenuItem* append_menu_item(wxMenu* men
 
     wxBitmapBundle* bmp = icon.empty() ? nullptr : get_bmp_bundle(icon);
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
     if (bmp && bmp->IsOk())
         msw_menuitem_bitmaps[id] = icon;
 #endif /* no __linux__ */
@@ -161,7 +161,7 @@ wxMenuItem* append_submenu(wxMenu* menu,
     if (!icon.empty()) {
         item->SetBitmap(*get_bmp_bundle(icon));
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
         msw_menuitem_bitmaps[id] = icon;
 #endif // no __linux__
     }
@@ -224,7 +224,7 @@ wxMenuItem* append_menu_check_item(wxMen
 void set_menu_item_bitmap(wxMenuItem* item, const std::string& icon_name)
 {
     item->SetBitmap(*get_bmp_bundle(icon_name));
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
     const auto it = msw_menuitem_bitmaps.find(item->GetId());
     if (it != msw_menuitem_bitmaps.end() && it->second != icon_name)
         it->second = icon_name;
