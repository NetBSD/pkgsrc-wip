$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/webrtc/media_stream_devices_controller.h.orig	2024-10-18 12:34:11.771754300 +0000
+++ components/webrtc/media_stream_devices_controller.h
@@ -48,7 +48,8 @@ class MediaStreamDevicesController {
   // synchronously or asynchronously returned via |callback|.
   static void RequestPermissions(const content::MediaStreamRequest& request,
                                  MediaStreamDeviceEnumerator* enumerator,
-                                 ResultCallback callback);
+                                 ResultCallback callback,
+                                 bool previously_approved = false);
 
   ~MediaStreamDevicesController();
 
