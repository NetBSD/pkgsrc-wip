$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/webrtc/modules/desktop_capture/desktop_capturer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/webrtc/modules/desktop_capture/desktop_capturer.cc
@@ -113,7 +113,7 @@ std::unique_ptr<DesktopCapturer> Desktop
   std::unique_ptr<DesktopCapturer> capturer;
 
 #if defined(WEBRTC_USE_PIPEWIRE)
-  if (options.allow_pipewire() && DesktopCapturer::IsRunningUnderWayland()) {
+  if (options.allow_pipewire() && BaseCapturerPipeWire::IsSupported()) {
     capturer = std::make_unique<BaseCapturerPipeWire>(
         options, CaptureType::kAnyScreenContent);
   }
