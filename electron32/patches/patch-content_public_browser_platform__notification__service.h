$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/platform_notification_service.h.orig	2024-10-18 12:34:14.414383600 +0000
+++ content/public/browser/platform_notification_service.h
@@ -26,6 +26,8 @@ struct PlatformNotificationData;
 
 namespace content {
 
+class RenderFrameHost;
+
 // The service using which notifications can be presented to the user. There
 // should be a unique instance of the PlatformNotificationService depending
 // on the browsing context being used.
@@ -41,6 +43,7 @@ class CONTENT_EXPORT PlatformNotificatio
   // This method must be called on the UI thread. |document_url| is empty when
   // the display notification originates from a worker.
   virtual void DisplayNotification(
+      RenderFrameHost* render_frame_host,
       const std::string& notification_id,
       const GURL& origin,
       const GURL& document_url,
