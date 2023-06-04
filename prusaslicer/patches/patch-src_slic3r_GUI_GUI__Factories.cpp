$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/GUI_Factories.cpp.orig	2023-06-02 13:41:15.000000000 +0000
+++ src/slic3r/GUI/GUI_Factories.cpp
@@ -1345,7 +1345,7 @@ void MenuFactory::sys_color_changed(wxMe
     for (size_t id = 0; id < menubar->GetMenuCount(); id++) {
         wxMenu* menu = menubar->GetMenu(id);
         sys_color_changed_menu(menu);
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
         menu->SetupBitmaps();
 #ifdef _WIN32 
         // but under MSW we have to update item's bachground color
