$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/io_surface_capture_device_base_mac.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/media/capture/io_surface_capture_device_base_mac.cc
@@ -20,7 +20,7 @@ void IOSurfaceCaptureDeviceBase::Allocat
   client_ = std::move(client);
   capture_params_ = params;
 
-  OnStart();
+  OnStart(params.use_native_picker);
 }
 
 void IOSurfaceCaptureDeviceBase::StopAndDeAllocate() {
