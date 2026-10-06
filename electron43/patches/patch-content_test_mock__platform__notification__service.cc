$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/test/mock_platform_notification_service.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/test/mock_platform_notification_service.cc
@@ -29,6 +29,7 @@ MockPlatformNotificationService::MockPla
 MockPlatformNotificationService::~MockPlatformNotificationService() = default;
 
 void MockPlatformNotificationService::DisplayNotification(
+    RenderFrameHost* render_frame_host,
     const std::string& notification_id,
     const GURL& origin,
     const GURL& document_url,
