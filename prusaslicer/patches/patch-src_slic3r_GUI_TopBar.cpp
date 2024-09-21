$NetBSD$

Treat NetBSD like linux.

--- src/slic3r/GUI/TopBar.cpp.orig	2024-09-18 13:39:04.000000000 +0000
+++ src/slic3r/GUI/TopBar.cpp
@@ -52,7 +52,7 @@ TopBarItemsCtrl::Button::Button(wxWindow
     Bind(wxEVT_LEAVE_WINDOW, [this](wxMouseEvent& event) { set_hovered(false); event.Skip(); });
 
     Bind(wxEVT_PAINT,        [this](wxPaintEvent&) { render(); });
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     Bind(wxEVT_LEFT_UP,      [this](wxMouseEvent& event) {
 #else
     Bind(wxEVT_LEFT_DOWN,    [this](wxMouseEvent& event) {
