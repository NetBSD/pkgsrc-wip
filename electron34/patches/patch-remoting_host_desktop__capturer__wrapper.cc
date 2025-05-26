$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/host/desktop_capturer_wrapper.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ remoting/host/desktop_capturer_wrapper.cc
@@ -13,7 +13,7 @@
 #include "third_party/webrtc/modules/desktop_capture/desktop_capturer.h"
 #include "third_party/webrtc/modules/desktop_capture/desktop_frame.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_desktop_capturer.h"
 #include "remoting/host/linux/wayland_utils.h"
 #endif
@@ -33,7 +33,7 @@ void DesktopCapturerWrapper::CreateCaptu
     SourceId id) {
   DCHECK(!capturer_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     capturer_ = std::make_unique<WaylandDesktopCapturer>(options);
   } else {
@@ -112,7 +112,7 @@ void DesktopCapturerWrapper::OnCaptureRe
 bool DesktopCapturerWrapper::SupportsFrameCallbacks() {
   DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return capturer_ && IsRunningWayland();
 #else
   return false;
