$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/linux/fallback_linux_ui.cc.orig	2024-10-18 12:35:12.728268900 +0000
+++ ui/linux/fallback_linux_ui.cc
@@ -143,7 +143,8 @@ FallbackLinuxUi::CreateNavButtonProvider
 
 ui::WindowFrameProvider* FallbackLinuxUi::GetWindowFrameProvider(
     bool solid_frame,
-    bool tiled) {
+    bool tiled,
+    bool maximized) {
   return nullptr;
 }
 
