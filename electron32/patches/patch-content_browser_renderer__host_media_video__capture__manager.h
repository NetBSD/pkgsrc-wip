$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/media/video_capture_manager.h.orig	2024-10-18 12:34:13.310953400 +0000
+++ content/browser/renderer_host/media/video_capture_manager.h
@@ -297,7 +297,7 @@ class CONTENT_EXPORT VideoCaptureManager
   // Finds a VideoCaptureController for the indicated |capture_session_id|,
   // creating a fresh one if necessary. Returns nullptr if said
   // |capture_session_id| is invalid.
-  VideoCaptureController* GetOrCreateController(
+  scoped_refptr<VideoCaptureController> GetOrCreateController(
       const media::VideoCaptureSessionId& capture_session_id,
       const media::VideoCaptureParams& params);
 
@@ -309,7 +309,7 @@ class CONTENT_EXPORT VideoCaptureManager
   // another request pending start.
   void QueueStartDevice(
       const media::VideoCaptureSessionId& session_id,
-      VideoCaptureController* controller,
+      scoped_refptr<VideoCaptureController> controller,
       const media::VideoCaptureParams& params,
       mojo::PendingRemote<video_effects::mojom::VideoEffectsProcessor>
           video_effects_processor);
