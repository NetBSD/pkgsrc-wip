$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/media/webrtc/chrome_screen_enumerator.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/media/webrtc/chrome_screen_enumerator.h
@@ -20,7 +20,7 @@ namespace aura {
 class Window;
 }
 
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace webrtc {
 class DesktopCapturer;
 }
@@ -42,7 +42,7 @@ class ChromeScreenEnumerator : public me
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   static void SetRootWindowsForTesting(
       std::vector<raw_ptr<aura::Window, VectorExperimental>> root_windows);
-#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static void SetDesktopCapturerForTesting(
       std::unique_ptr<webrtc::DesktopCapturer> capturer);
 #endif
