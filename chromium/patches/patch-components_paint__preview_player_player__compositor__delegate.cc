$NetBSD: patch-components_paint__preview_player_player__compositor__delegate.cc,v 1.1 2025/02/06 09:58:01 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/paint_preview/player/player_compositor_delegate.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/paint_preview/player/player_compositor_delegate.cc
@@ -434,8 +434,8 @@ void PlayerCompositorDelegate::ValidateP
   auto chrome_version = capture_result_->proto.metadata().chrome_version();
   const auto& current_chrome_version = version_info::GetVersion();
   if (capture_result_->proto.metadata().has_chrome_version() &&
-      chrome_version.major() == current_chrome_version.components()[0] &&
-      chrome_version.minor() == current_chrome_version.components()[1] &&
+      chrome_version.gmajor() == current_chrome_version.components()[0] &&
+      chrome_version.gminor() == current_chrome_version.components()[1] &&
       chrome_version.build() == current_chrome_version.components()[2] &&
       chrome_version.patch() == current_chrome_version.components()[3]) {
     paint_preview_service_->GetFileMixin()->GetAXTreeUpdate(
