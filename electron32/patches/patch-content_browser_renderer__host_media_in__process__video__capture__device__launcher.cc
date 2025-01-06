$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/media/in_process_video_capture_device_launcher.cc.orig	2024-10-18 12:34:13.274972000 +0000
+++ content/browser/renderer_host/media/in_process_video_capture_device_launcher.cc
@@ -316,8 +316,16 @@ void InProcessVideoCaptureDeviceLauncher
         break;
       }
 
+#if defined(USE_AURA)
+      bool allow_window_id = false;
+#elif BUILDFLAG(IS_MAC)
+      bool allow_window_id =
+        desktop_id.id == DesktopMediaID::kMacOsNativePickerId;
+#endif
+
 #if defined(USE_AURA) || BUILDFLAG(IS_MAC)
-      if (desktop_id.window_id != DesktopMediaID::kNullId) {
+      if (!allow_window_id &&
+          desktop_id.window_id != DesktopMediaID::kNullId) {
         // For the other capturers, when a bug reports the type of capture it's
         // easy enough to determine which capturer was used, but it's a little
         // fuzzier with window capture.
@@ -344,13 +352,15 @@ void InProcessVideoCaptureDeviceLauncher
           std::move(after_start_capture_callback));
       break;
 #else
+      media::VideoCaptureParams updated_params = params;
+      updated_params.use_native_picker = stream_type != blink::mojom::MediaStreamType::GUM_DESKTOP_VIDEO_CAPTURE;
       // All cases other than tab capture or Aura desktop/window capture.
       TRACE_EVENT_INSTANT0(TRACE_DISABLED_BY_DEFAULT("video_and_image_capture"),
                            "UsingDesktopCapturer", TRACE_EVENT_SCOPE_THREAD);
       start_capture_closure = base::BindOnce(
           &InProcessVideoCaptureDeviceLauncher::
               DoStartDesktopCaptureOnDeviceThread,
-          base::Unretained(this), desktop_id, params,
+          base::Unretained(this), desktop_id, updated_params,
           CreateDeviceClient(media::VideoCaptureBufferType::kSharedMemory,
                              kMaxNumberOfBuffers, std::move(receiver),
                              std::move(receiver_on_io_thread)),
