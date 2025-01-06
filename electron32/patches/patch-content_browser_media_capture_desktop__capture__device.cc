$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/media/capture/desktop_capture_device.cc.orig	2024-10-18 12:34:12.787225000 +0000
+++ content/browser/media/capture/desktop_capture_device.cc
@@ -822,8 +822,14 @@ std::unique_ptr<media::VideoCaptureDevic
               DesktopCapturerLacros::CaptureType::kScreen,
               webrtc::DesktopCaptureOptions());
 #else
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
 #endif
       if (screen_capturer && screen_capturer->SelectSource(source.id)) {
         capturer = std::make_unique<webrtc::DesktopAndCursorComposer>(
@@ -842,8 +848,14 @@ std::unique_ptr<media::VideoCaptureDevic
           new DesktopCapturerLacros(DesktopCapturerLacros::CaptureType::kWindow,
                                     webrtc::DesktopCaptureOptions()));
 #else
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
 #endif
       if (window_capturer && window_capturer->SelectSource(source.id)) {
         capturer = std::make_unique<webrtc::DesktopAndCursorComposer>(
