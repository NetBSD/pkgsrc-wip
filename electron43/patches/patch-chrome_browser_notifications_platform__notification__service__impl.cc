$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/notifications/platform_notification_service_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/notifications/platform_notification_service_impl.cc
@@ -220,6 +220,7 @@ bool PlatformNotificationServiceImpl::Wa
 
 // TODO(awdf): Rename to DisplayNonPersistentNotification (Similar for Close)
 void PlatformNotificationServiceImpl::DisplayNotification(
+    content::RenderFrameHost* render_frame_host,
     const std::string& notification_id,
     const GURL& origin,
     const GURL& document_url,
