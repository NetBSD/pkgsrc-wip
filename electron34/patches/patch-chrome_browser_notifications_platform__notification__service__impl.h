$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/notifications/platform_notification_service_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/notifications/platform_notification_service_impl.h
@@ -57,6 +57,7 @@ class PlatformNotificationServiceImpl
 
   // content::PlatformNotificationService implementation.
   void DisplayNotification(
+      content::RenderFrameHost* render_frame_host,
       const std::string& notification_id,
       const GURL& origin,
       const GURL& document_url,
