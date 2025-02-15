$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/media/video_capture_manager.cc.orig	2024-10-18 12:34:13.310953400 +0000
+++ content/browser/renderer_host/media/video_capture_manager.cc
@@ -15,6 +15,7 @@
 #include "base/location.h"
 #include "base/logging.h"
 #include "base/memory/raw_ptr.h"
+#include "base/memory/scoped_refptr.h"
 #include "base/metrics/histogram_functions.h"
 #include "base/observer_list.h"
 #include "base/ranges/algorithm.h"
@@ -61,12 +62,14 @@ namespace content {
 class VideoCaptureManager::CaptureDeviceStartRequest {
  public:
   CaptureDeviceStartRequest(
-      VideoCaptureController* controller,
+      scoped_refptr<VideoCaptureController> controller,
       const media::VideoCaptureSessionId& session_id,
       const media::VideoCaptureParams& params,
       mojo::PendingRemote<video_effects::mojom::VideoEffectsProcessor>
           video_effects_processor);
-  VideoCaptureController* controller() const { return controller_; }
+  scoped_refptr<VideoCaptureController> controller() const {
+    return controller_;
+  }
   const base::UnguessableToken& session_id() const { return session_id_; }
   media::VideoCaptureParams params() const { return params_; }
 
@@ -76,7 +79,7 @@ class VideoCaptureManager::CaptureDevice
   }
 
  private:
-  const raw_ptr<VideoCaptureController> controller_;
+  const scoped_refptr<VideoCaptureController> controller_;
   const base::UnguessableToken session_id_;
   const media::VideoCaptureParams params_;
   mojo::PendingRemote<video_effects::mojom::VideoEffectsProcessor>
@@ -84,12 +87,12 @@ class VideoCaptureManager::CaptureDevice
 };
 
 VideoCaptureManager::CaptureDeviceStartRequest::CaptureDeviceStartRequest(
-    VideoCaptureController* controller,
+    scoped_refptr<VideoCaptureController> controller,
     const media::VideoCaptureSessionId& session_id,
     const media::VideoCaptureParams& params,
     mojo::PendingRemote<video_effects::mojom::VideoEffectsProcessor>
         video_effects_processor)
-    : controller_(controller),
+    : controller_(std::move(controller)),
       session_id_(session_id),
       params_(params),
       video_effects_processor_(std::move(video_effects_processor)) {}
@@ -258,14 +261,15 @@ void VideoCaptureManager::ApplySubCaptur
 
 void VideoCaptureManager::QueueStartDevice(
     const media::VideoCaptureSessionId& session_id,
-    VideoCaptureController* controller,
+    scoped_refptr<VideoCaptureController> controller,
     const media::VideoCaptureParams& params,
     mojo::PendingRemote<video_effects::mojom::VideoEffectsProcessor>
         video_effects_processor) {
   DCHECK_CURRENTLY_ON(BrowserThread::IO);
   DCHECK(lock_time_.is_null());
-  device_start_request_queue_.push_back(CaptureDeviceStartRequest(
-      controller, session_id, params, std::move(video_effects_processor)));
+  device_start_request_queue_.push_back(
+      CaptureDeviceStartRequest(std::move(controller), session_id, params,
+                                std::move(video_effects_processor)));
   if (device_start_request_queue_.size() == 1)
     ProcessDeviceStartRequestQueue();
 }
@@ -311,7 +315,8 @@ void VideoCaptureManager::ProcessDeviceS
   if (request == device_start_request_queue_.end())
     return;
 
-  VideoCaptureController* const controller = request->controller();
+  scoped_refptr<VideoCaptureController> const controller =
+      request->controller();
 
   EmitLogMessage("VideoCaptureManager::ProcessDeviceStartRequestQueue", 3);
   // The unit test VideoCaptureManagerTest.OpenNotExisting requires us to fail
@@ -329,7 +334,7 @@ void VideoCaptureManager::ProcessDeviceS
         GetDeviceInfoById(controller->device_id());
     if (!device_info) {
       OnDeviceLaunchFailed(
-          controller,
+          controller.get(),
           media::VideoCaptureError::
               kVideoCaptureManagerProcessDeviceStartQueueDeviceInfoNotFound);
       return;
@@ -350,7 +355,7 @@ void VideoCaptureManager::ProcessDeviceS
       base::BindOnce([](scoped_refptr<VideoCaptureManager>,
                         scoped_refptr<VideoCaptureController>) {},
                      scoped_refptr<VideoCaptureManager>(this),
-                     GetControllerSharedRef(controller)),
+                     std::move(controller)),
       request->TakeVideoEffectsProcessor());
 }
 
@@ -434,7 +439,7 @@ void VideoCaptureManager::ConnectClient(
     EmitLogMessage(string_stream.str(), 1);
   }
 
-  VideoCaptureController* controller =
+  scoped_refptr<VideoCaptureController> controller =
       GetOrCreateController(session_id, params);
   if (!controller) {
     std::move(done_cb).Run(nullptr);
@@ -908,7 +913,8 @@ media::VideoCaptureDeviceInfo* VideoCapt
   return nullptr;
 }
 
-VideoCaptureController* VideoCaptureManager::GetOrCreateController(
+scoped_refptr<VideoCaptureController>
+VideoCaptureManager::GetOrCreateController(
     const media::VideoCaptureSessionId& capture_session_id,
     const media::VideoCaptureParams& params) {
   DCHECK_CURRENTLY_ON(BrowserThread::IO);
@@ -930,10 +936,12 @@ VideoCaptureController* VideoCaptureMana
     return existing_device;
   }
 
-  VideoCaptureController* new_controller = new VideoCaptureController(
-      device_info.id, device_info.type, params,
-      video_capture_provider_->CreateDeviceLauncher(), emit_log_message_cb_);
-  controllers_.emplace_back(new_controller);
+  scoped_refptr<VideoCaptureController> new_controller =
+      base::MakeRefCounted<VideoCaptureController>(
+          device_info.id, device_info.type, params,
+          video_capture_provider_->CreateDeviceLauncher(),
+          emit_log_message_cb_);
+  controllers_.push_back(new_controller);
   return new_controller;
 }
 
