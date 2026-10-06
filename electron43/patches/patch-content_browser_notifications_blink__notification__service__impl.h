$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/notifications/blink_notification_service_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/notifications/blink_notification_service_impl.h
@@ -44,6 +44,7 @@ class CONTENT_EXPORT BlinkNotificationSe
       BrowserContext* browser_context,
       scoped_refptr<ServiceWorkerContextWrapper> service_worker_context,
       RenderProcessHost* render_process_host,
+      RenderFrameHost* render_frame_host,
       const blink::StorageKey& storage_key,
       const GURL& document_url,
       const WeakDocumentPtr& weak_document_ptr,
@@ -113,6 +114,7 @@ class CONTENT_EXPORT BlinkNotificationSe
   raw_ptr<PlatformNotificationContextImpl, DanglingUntriaged>
       notification_context_;
 
+  raw_ptr<RenderFrameHost> render_frame_host_;
   raw_ptr<BrowserContext> browser_context_;
 
   scoped_refptr<ServiceWorkerContextWrapper> service_worker_context_;
