$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/io_surface_capture_device_base_mac.cc.orig	2024-10-18 12:34:12.795220900 +0000
+++ content/browser/media/capture/io_surface_capture_device_base_mac.cc
@@ -20,7 +20,7 @@ void IOSurfaceCaptureDeviceBase::Allocat
   client_ = std::move(client);
   capture_params_ = params;
 
-  OnStart();
+  OnStart(params.use_native_picker);
 }
 
 void IOSurfaceCaptureDeviceBase::StopAndDeAllocate() {
