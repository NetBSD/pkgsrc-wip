$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/fake_desktop_media_list.cc.orig	2024-10-18 12:34:01.701188800 +0000
+++ chrome/browser/media/webrtc/fake_desktop_media_list.cc
@@ -79,7 +79,8 @@ void FakeDesktopMediaList::StartUpdating
   thumbnail_ = gfx::ImageSkia::CreateFrom1xBitmap(bitmap);
 }
 
-void FakeDesktopMediaList::Update(UpdateCallback callback) {
+void FakeDesktopMediaList::Update(UpdateCallback callback,
+                                  bool refresh_thumbnails) {
   std::move(callback).Run();
 }
 
