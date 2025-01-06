$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/io_surface_capture_device_base_mac.h.orig	2024-10-18 12:34:12.795220900 +0000
+++ content/browser/media/capture/io_surface_capture_device_base_mac.h
@@ -25,7 +25,7 @@ class CONTENT_EXPORT IOSurfaceCaptureDev
   ~IOSurfaceCaptureDeviceBase() override;
 
   // OnStart is called by AllocateAndStart.
-  virtual void OnStart() = 0;
+  virtual void OnStart(std::optional<bool> use_native_picker) = 0;
 
   // OnStop is called by StopAndDeAllocate.
   virtual void OnStop() = 0;
