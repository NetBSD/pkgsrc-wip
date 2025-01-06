$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/webrtc/modules/desktop_capture/linux/wayland/base_capturer_pipewire.cc.orig	2024-10-18 12:43:44.442822000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/base_capturer_pipewire.cc
@@ -111,6 +111,7 @@ void BaseCapturerPipeWire::OnScreenCastR
 void BaseCapturerPipeWire::OnScreenCastSessionClosed() {
   if (!capturer_failed_) {
     options_.screencast_stream()->StopScreenCastStream();
+    capturer_failed_ = true;
   }
   capturer_failed_ = true;
 }
