$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/paint_preview/player/player_compositor_delegate.cc.orig	2024-09-24 20:49:25.390590400 +0000
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
