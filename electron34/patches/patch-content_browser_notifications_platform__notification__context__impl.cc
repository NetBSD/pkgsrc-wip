$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/notifications/platform_notification_context_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/notifications/platform_notification_context_impl.cc
@@ -282,6 +282,7 @@ void PlatformNotificationContextImpl::Sh
 
 void PlatformNotificationContextImpl::CreateService(
     RenderProcessHost* render_process_host,
+    RenderFrameHost* render_frame_host,
     const blink::StorageKey& storage_key,
     const GURL& document_url,
     const WeakDocumentPtr& weak_document_ptr,
@@ -290,7 +291,7 @@ void PlatformNotificationContextImpl::Cr
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
   services_.push_back(std::make_unique<BlinkNotificationServiceImpl>(
       this, browser_context_, service_worker_context_, render_process_host,
-      storage_key, document_url, weak_document_ptr, creator_type,
+      render_frame_host, storage_key, document_url, weak_document_ptr, creator_type,
       std::move(receiver)));
 }
 
