$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/qt/qt_ui.cc.orig	2024-10-18 12:35:12.780248000 +0000
+++ ui/qt/qt_ui.cc
@@ -427,7 +427,8 @@ std::unique_ptr<ui::NavButtonProvider> Q
 }
 
 ui::WindowFrameProvider* QtUi::GetWindowFrameProvider(bool solid_frame,
-                                                      bool tiled) {
+                                                      bool tiled,
+                                                      bool maximized) {
   // QT prefers server-side decorations.
   return nullptr;
 }
