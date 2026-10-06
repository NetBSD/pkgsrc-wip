$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/desktop_capture_device_mac.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/media/capture/desktop_capture_device_mac.cc
@@ -28,7 +28,7 @@ class DesktopCaptureDeviceMac : public I
   ~DesktopCaptureDeviceMac() override = default;
 
   // IOSurfaceCaptureDeviceBase:
-  void OnStart() override {
+  void OnStart(std::optional<bool> use_native_picker) override {
     requested_format_ = capture_params().requested_format;
     requested_format_.pixel_format = media::PIXEL_FORMAT_NV12;
     DCHECK_GT(requested_format_.frame_size.GetArea(), 0);
