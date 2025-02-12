$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -92,7 +92,7 @@ bool DesktopMediaPickerController::IsSys
   } else {
     return base::FeatureList::IsEnabled(media::kMacLoopbackAudioForScreenShare);
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {
