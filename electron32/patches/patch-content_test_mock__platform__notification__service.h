$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/test/mock_platform_notification_service.h.orig	2024-10-18 12:34:16.189474800 +0000
+++ content/test/mock_platform_notification_service.h
@@ -53,6 +53,7 @@ class MockPlatformNotificationService : 
 
   // PlatformNotificationService implementation.
   void DisplayNotification(
+      RenderFrameHost* render_frame_host,
       const std::string& notification_id,
       const GURL& origin,
       const GURL& document_url,
