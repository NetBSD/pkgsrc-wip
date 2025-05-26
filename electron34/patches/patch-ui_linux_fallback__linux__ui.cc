$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/linux/fallback_linux_ui.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/linux/fallback_linux_ui.cc
@@ -143,7 +143,8 @@ FallbackLinuxUi::CreateNavButtonProvider
 
 ui::WindowFrameProvider* FallbackLinuxUi::GetWindowFrameProvider(
     bool solid_frame,
-    bool tiled) {
+    bool tiled,
+    bool maximized) {
   return nullptr;
 }
 
