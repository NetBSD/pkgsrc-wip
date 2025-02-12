$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/paint_preview/browser/paint_preview_client.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/paint_preview/browser/paint_preview_client.cc
@@ -326,8 +326,8 @@ void PaintPreviewClient::CapturePaintPre
   metadata->set_version(kPaintPreviewVersion);
   auto* chromeVersion = metadata->mutable_chrome_version();
   const auto& current_chrome_version = version_info::GetVersion();
-  chromeVersion->set_major(current_chrome_version.components()[0]);
-  chromeVersion->set_minor(current_chrome_version.components()[1]);
+  chromeVersion->set_gmajor(current_chrome_version.components()[0]);
+  chromeVersion->set_gminor(current_chrome_version.components()[1]);
   chromeVersion->set_build(current_chrome_version.components()[2]);
   chromeVersion->set_patch(current_chrome_version.components()[3]);
   document_data.callback = std::move(callback);
