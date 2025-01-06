$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/notifications/platform_notification_service_impl.h.orig	2024-10-18 12:34:01.761155400 +0000
+++ chrome/browser/notifications/platform_notification_service_impl.h
@@ -57,6 +57,7 @@ class PlatformNotificationServiceImpl
 
   // content::PlatformNotificationService implementation.
   void DisplayNotification(
+      content::RenderFrameHost* render_frame_host,
       const std::string& notification_id,
       const GURL& origin,
       const GURL& document_url,
