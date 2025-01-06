$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/notifications/blink_notification_service_impl_unittest.cc.orig	2024-10-18 12:34:12.955137500 +0000
+++ content/browser/notifications/blink_notification_service_impl_unittest.cc
@@ -132,7 +132,7 @@ class BlinkNotificationServiceImplTest :
     notification_service_ = std::make_unique<BlinkNotificationServiceImpl>(
         notification_context_.get(), &browser_context_,
         embedded_worker_helper_->context_wrapper(), &render_process_host_,
-        storage_key_,
+        nullptr, storage_key_,
         /*document_url=*/GURL(),
         contents_.get()->GetPrimaryMainFrame()->GetWeakDocumentPtr(),
         RenderProcessHost::NotificationServiceCreatorType::kDocument,
