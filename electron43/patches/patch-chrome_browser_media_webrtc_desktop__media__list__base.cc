$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/desktop_media_list_base.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/media/webrtc/desktop_media_list_base.cc
@@ -74,12 +74,12 @@ void DesktopMediaListBase::StartUpdating
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
@@ -236,7 +236,11 @@ uint32_t DesktopMediaListBase::GetImageH
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
