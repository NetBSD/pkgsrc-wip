$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/webrtc/modules/desktop_capture/screen_capturer_linux.cc.orig	2024-10-18 12:43:44.458822700 +0000
+++ third_party/webrtc/modules/desktop_capture/screen_capturer_linux.cc
@@ -34,11 +34,10 @@ std::unique_ptr<DesktopCapturer> Desktop
 #endif  // defined(WEBRTC_USE_PIPEWIRE)
 
 #if defined(WEBRTC_USE_X11)
-  if (!DesktopCapturer::IsRunningUnderWayland())
-    return ScreenCapturerX11::CreateRawScreenCapturer(options);
-#endif  // defined(WEBRTC_USE_X11)
-
+  return ScreenCapturerX11::CreateRawScreenCapturer(options);
+#else
   return nullptr;
+#endif  // defined(WEBRTC_USE_X11)
 }
 
 }  // namespace webrtc
