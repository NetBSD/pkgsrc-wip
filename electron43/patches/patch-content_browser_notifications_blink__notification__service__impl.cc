$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/notifications/blink_notification_service_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/notifications/blink_notification_service_impl.cc
@@ -87,12 +87,14 @@ BlinkNotificationServiceImpl::BlinkNotif
     BrowserContext* browser_context,
     scoped_refptr<ServiceWorkerContextWrapper> service_worker_context,
     RenderProcessHost* render_process_host,
+    RenderFrameHost* render_frame_host,
     const blink::StorageKey& storage_key,
     const GURL& document_url,
     const WeakDocumentPtr& weak_document_ptr,
     RenderProcessHost::NotificationServiceCreatorType creator_type,
     mojo::PendingReceiver<blink::mojom::NotificationService> receiver)
     : notification_context_(notification_context),
+      render_frame_host_(render_frame_host),
       browser_context_(browser_context),
       service_worker_context_(std::move(service_worker_context)),
       render_process_host_id_(render_process_host->GetID()),
@@ -184,7 +186,7 @@ void BlinkNotificationServiceImpl::Displ
       creator_type_);
 
   browser_context_->GetPlatformNotificationService()->DisplayNotification(
-      notification_id, storage_key_.origin().GetURL(), document_url_,
+      render_frame_host_, notification_id, storage_key_.origin().GetURL(), document_url_,
       platform_notification_data, notification_resources);
 }
 
