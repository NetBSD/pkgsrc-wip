$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/webrtc/media_stream_devices_controller.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/webrtc/media_stream_devices_controller.cc
@@ -57,7 +57,8 @@ bool PermissionIsRequested(blink::Permis
 void MediaStreamDevicesController::RequestPermissions(
     const content::MediaStreamRequest& request,
     MediaStreamDeviceEnumerator* enumerator,
-    ResultCallback callback) {
+    ResultCallback callback,
+    bool previously_approved) {
   content::RenderFrameHost* rfh = content::RenderFrameHost::FromID(
       request.render_process_id, request.render_frame_id);
   // The RFH may have been destroyed by the time the request is processed.
@@ -92,7 +93,7 @@ void MediaStreamDevicesController::Reque
                                        std::move(callback)));
 
   std::vector<blink::PermissionType> permission_types;
-
+#if 0
   content::PermissionController* permission_controller =
       web_contents->GetBrowserContext()->GetPermissionController();
 
@@ -165,19 +166,26 @@ void MediaStreamDevicesController::Reque
       requested_audio_capture_device_ids;
   permission_request_description.requested_video_capture_device_ids =
       requested_video_capture_device_ids;
-
+#endif
   // It is OK to ignore `request.security_origin` because it will be calculated
   // from `render_frame_host` and we always ignore `requesting_origin` for
   // `AUDIO_CAPTURE` and `VIDEO_CAPTURE`.
   // `render_frame_host->GetMainFrame()->GetLastCommittedOrigin()` will be used
   // instead.
-  rfh->GetBrowserContext()
-      ->GetPermissionController()
-      ->RequestPermissionsFromCurrentDocument(
-          rfh, permission_request_description,
-          base::BindOnce(
-              &MediaStreamDevicesController::PromptAnsweredGroupedRequest,
-              std::move(controller)));
+  if (previously_approved) {
+    controller->PromptAnsweredGroupedRequest({blink::mojom::PermissionStatus::GRANTED /*audio*/,
+                                              blink::mojom::PermissionStatus::GRANTED /*video*/});
+  } else {
+    rfh->GetBrowserContext()
+        ->GetPermissionController()
+        ->RequestPermissionsFromCurrentDocument(
+            rfh,
+            content::PermissionRequestDescription(permission_types,
+                                                  request.user_gesture),
+            base::BindOnce(
+                &MediaStreamDevicesController::PromptAnsweredGroupedRequest,
+                std::move(controller)));
+  }
 }
 
 MediaStreamDevicesController::~MediaStreamDevicesController() {
@@ -429,6 +437,7 @@ bool MediaStreamDevicesController::Permi
     return false;
   }
 
+#if 0
   // TODO(raymes): This function wouldn't be needed if
   // PermissionManager::RequestPermissions returned a denial reason.
   content::PermissionResult result =
@@ -439,6 +448,7 @@ bool MediaStreamDevicesController::Permi
     DCHECK_EQ(blink::mojom::PermissionStatus::DENIED, result.status);
     return true;
   }
+#endif
   return false;
 }
 
