$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/webrtc/modules/desktop_capture/desktop_capturer.cc.orig	2024-10-18 12:43:44.442822000 +0000
+++ third_party/webrtc/modules/desktop_capture/desktop_capturer.cc
@@ -113,7 +113,7 @@ std::unique_ptr<DesktopCapturer> Desktop
   std::unique_ptr<DesktopCapturer> capturer;
 
 #if defined(WEBRTC_USE_PIPEWIRE)
-  if (options.allow_pipewire() && DesktopCapturer::IsRunningUnderWayland()) {
+  if (options.allow_pipewire() && BaseCapturerPipeWire::IsSupported()) {
     capturer = std::make_unique<BaseCapturerPipeWire>(
         options, CaptureType::kAnyScreenContent);
   }
