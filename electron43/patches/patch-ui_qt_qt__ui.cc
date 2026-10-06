$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/qt/qt_ui.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/qt/qt_ui.cc
@@ -436,7 +436,8 @@ std::unique_ptr<ui::NavButtonProvider> Q
 }
 
 ui::WindowFrameProvider* QtUi::GetWindowFrameProvider(bool solid_frame,
-                                                      bool tiled) {
+                                                      bool tiled,
+                                                      bool maximized) {
   // QT prefers server-side decorations.
   return nullptr;
 }
