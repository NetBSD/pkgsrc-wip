$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/fake_desktop_media_list.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/media/webrtc/fake_desktop_media_list.cc
@@ -79,7 +79,8 @@ void FakeDesktopMediaList::StartUpdating
   thumbnail_ = gfx::ImageSkia::CreateFrom1xBitmap(bitmap);
 }
 
-void FakeDesktopMediaList::Update(UpdateCallback callback) {
+void FakeDesktopMediaList::Update(UpdateCallback callback,
+                                  bool refresh_thumbnails) {
   std::move(callback).Run();
 }
 
