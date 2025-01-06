$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/fake_desktop_media_list.h.orig	2024-10-18 12:34:01.701188800 +0000
+++ chrome/browser/media/webrtc/fake_desktop_media_list.h
@@ -40,7 +40,8 @@ class FakeDesktopMediaList : public Desk
   void SetThumbnailSize(const gfx::Size& thumbnail_size) override;
   void SetViewDialogWindowId(content::DesktopMediaID dialog_id) override;
   void StartUpdating(DesktopMediaListObserver* observer) override;
-  void Update(UpdateCallback callback) override;
+  void Update(UpdateCallback callback,
+              bool refresh_thumbnails = false) override;
   int GetSourceCount() const override;
   const Source& GetSource(int index) const override;
   DesktopMediaList::Type GetMediaListType() const override;
