$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/desktop_media_list_base.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/media/webrtc/desktop_media_list_base.h
@@ -39,7 +39,7 @@ class DesktopMediaListBase : public Desk
   void SetThumbnailSize(const gfx::Size& thumbnail_size) override;
   void SetViewDialogWindowId(content::DesktopMediaID dialog_id) override;
   void StartUpdating(DesktopMediaListObserver* observer) override;
-  void Update(UpdateCallback callback) override;
+  void Update(UpdateCallback callback, bool refresh_thumbnails) override;
   int GetSourceCount() const override;
   const Source& GetSource(int index) const override;
   DesktopMediaList::Type GetMediaListType() const override;
