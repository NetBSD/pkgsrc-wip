$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/desktop_capture_device.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/media/capture/desktop_capture_device.cc
@@ -811,8 +811,14 @@ std::unique_ptr<media::VideoCaptureDevic
 
   switch (source.type) {
     case DesktopMediaID::TYPE_SCREEN: {
-      std::unique_ptr<webrtc::DesktopCapturer> screen_capturer(
-          webrtc::DesktopCapturer::CreateScreenCapturer(options));
+      std::unique_ptr<webrtc::DesktopCapturer> screen_capturer;
+      if (auto generic_capturer =
+              webrtc::DesktopCapturer::CreateGenericCapturer(options);
+          generic_capturer && generic_capturer->GetDelegatedSourceListController()) {
+        screen_capturer = std::move(generic_capturer);
+      } else {
+        screen_capturer = webrtc::DesktopCapturer::CreateScreenCapturer(options);
+      }
       if (screen_capturer && screen_capturer->SelectSource(source.id)) {
         capturer = std::make_unique<webrtc::DesktopAndCursorComposer>(
             std::move(screen_capturer), options);
@@ -825,8 +831,14 @@ std::unique_ptr<media::VideoCaptureDevic
     }
 
     case DesktopMediaID::TYPE_WINDOW: {
-      std::unique_ptr<webrtc::DesktopCapturer> window_capturer =
-          webrtc::DesktopCapturer::CreateWindowCapturer(options);
+      std::unique_ptr<webrtc::DesktopCapturer> window_capturer;
+      if (auto generic_capturer =
+              webrtc::DesktopCapturer::CreateGenericCapturer(options);
+          generic_capturer && generic_capturer->GetDelegatedSourceListController()) {
+        window_capturer = std::move(generic_capturer);
+      } else {
+        window_capturer = webrtc::DesktopCapturer::CreateWindowCapturer(options);
+      }
       if (window_capturer && window_capturer->SelectSource(source.id)) {
         capturer = std::make_unique<webrtc::DesktopAndCursorComposer>(
             std::move(window_capturer), options);
