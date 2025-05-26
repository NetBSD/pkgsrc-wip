$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/webrtc/modules/desktop_capture/linux/wayland/base_capturer_pipewire.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/base_capturer_pipewire.cc
@@ -111,6 +111,7 @@ void BaseCapturerPipeWire::OnScreenCastR
 void BaseCapturerPipeWire::OnScreenCastSessionClosed() {
   if (!capturer_failed_) {
     options_.screencast_stream()->StopScreenCastStream();
+    capturer_failed_ = true;
   }
   capturer_failed_ = true;
 }
