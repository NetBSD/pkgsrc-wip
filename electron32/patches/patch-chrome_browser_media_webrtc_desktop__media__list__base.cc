$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/desktop_media_list_base.cc.orig	2024-10-18 12:34:01.697191200 +0000
+++ chrome/browser/media/webrtc/desktop_media_list_base.cc
@@ -69,12 +69,12 @@ void DesktopMediaListBase::StartUpdating
   Refresh(true);
 }
 
-void DesktopMediaListBase::Update(UpdateCallback callback) {
+void DesktopMediaListBase::Update(UpdateCallback callback, bool refresh_thumbnails) {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
   DCHECK(sources_.empty());
   DCHECK(!refresh_callback_);
   refresh_callback_ = std::move(callback);
-  Refresh(false);
+  Refresh(refresh_thumbnails);
 }
 
 int DesktopMediaListBase::GetSourceCount() const {
@@ -230,7 +230,11 @@ uint32_t DesktopMediaListBase::GetImageH
 void DesktopMediaListBase::OnRefreshComplete() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
   DCHECK(refresh_callback_);
-  std::move(refresh_callback_).Run();
+  if (skip_next_refresh_ > 0) {
+    skip_next_refresh_--;
+  } else {
+    std::move(refresh_callback_).Run();
+  }
 }
 
 void DesktopMediaListBase::ScheduleNextRefresh() {
