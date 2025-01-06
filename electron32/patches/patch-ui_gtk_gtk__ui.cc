$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/gtk_ui.cc.orig	2024-10-18 12:35:12.728268900 +0000
+++ ui/gtk/gtk_ui.cc
@@ -577,11 +577,12 @@ std::unique_ptr<ui::NavButtonProvider> G
 }
 
 ui::WindowFrameProvider* GtkUi::GetWindowFrameProvider(bool solid_frame,
-                                                       bool tiled) {
-  auto& provider = frame_providers_[solid_frame][tiled];
+                                                       bool tiled,
+                                                       bool maximized) {
+  auto& provider = frame_providers_[solid_frame][tiled][maximized];
   if (!provider) {
     provider =
-        std::make_unique<gtk::WindowFrameProviderGtk>(solid_frame, tiled);
+        std::make_unique<gtk::WindowFrameProviderGtk>(solid_frame, tiled, maximized);
   }
   return provider.get();
 }
