$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/notifications/platform_notification_context_impl.h.orig	2024-10-18 12:34:12.967131400 +0000
+++ content/browser/notifications/platform_notification_context_impl.h
@@ -47,6 +47,7 @@ class PlatformNotificationServiceProxy;
 class RenderProcessHost;
 class ServiceWorkerContextWrapper;
 class WeakDocumentPtr;
+class RenderFrameHost;
 
 // Implementation of the Web Notification storage context. The public methods
 // defined in this interface must only be called on the UI thread.
@@ -80,6 +81,7 @@ class CONTENT_EXPORT PlatformNotificatio
   // service is created by a dedicated worker, or is `nullptr` otherwise.
   void CreateService(
       RenderProcessHost* render_process_host,
+      RenderFrameHost* render_frame_host,
       const blink::StorageKey& storage_key,
       const GURL& document_url,
       const WeakDocumentPtr& weak_document_ptr,
