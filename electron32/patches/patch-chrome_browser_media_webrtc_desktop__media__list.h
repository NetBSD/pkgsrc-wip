$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/desktop_media_list.h.orig	2024-10-18 12:34:01.697191200 +0000
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
@@ -142,6 +143,8 @@ class DesktopMediaList {
   // important when IsSourceDelegated() returns true, as it helps to notify the
   // delegated source list when it should be hidden.
   virtual void HideList() = 0;
+
+  int skip_next_refresh_ = 0;
 };
 
 #endif  // CHROME_BROWSER_MEDIA_WEBRTC_DESKTOP_MEDIA_LIST_H_
