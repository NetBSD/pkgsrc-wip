$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/desktop_media_list.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/media/webrtc/desktop_media_list.h
@@ -107,7 +107,8 @@ class DesktopMediaList {
   // once per DesktopMediaList instance.  It should not be called after
   // StartUpdating(), and StartUpdating() should not be called until |callback|
   // has been called.
-  virtual void Update(UpdateCallback callback) = 0;
+  virtual void Update(UpdateCallback callback,
+                      bool refresh_thumbnails = false) = 0;
 
   virtual int GetSourceCount() const = 0;
   virtual const Source& GetSource(int index) const = 0;
@@ -147,6 +148,8 @@ class DesktopMediaList {
   // source lists that need to be displayed independently from when the
   // DesktopMediaList gains focus.
   virtual void ShowDelegatedList() = 0;
+
+  int skip_next_refresh_ = 0;
 };
 
 #endif  // CHROME_BROWSER_MEDIA_WEBRTC_DESKTOP_MEDIA_LIST_H_
