$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/host/me2me_desktop_environment.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ remoting/host/me2me_desktop_environment.cc
@@ -108,7 +108,7 @@ std::string Me2MeDesktopEnvironment::Get
     capabilities += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   if (!IsRunningWayland()) {
     capabilities += " ";
     capabilities += protocol::kMultiStreamCapability;
@@ -150,7 +150,7 @@ Me2MeDesktopEnvironment::Me2MeDesktopEnv
   // properly under Xvfb.
   mutable_desktop_capture_options()->set_use_update_notifications(true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Setting this option to false means that the capture differ wrapper will not
   // be used when the X11 capturer is selected. This reduces the X11 capture
   // time by a few milliseconds per frame and is safe because we can rely on
@@ -159,7 +159,7 @@ Me2MeDesktopEnvironment::Me2MeDesktopEnv
   mutable_desktop_capture_options()->set_detect_updated_region(false);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     mutable_desktop_capture_options()->set_prefer_cursor_embedded(false);
   }
@@ -184,7 +184,7 @@ bool Me2MeDesktopEnvironment::Initialize
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool want_user_interface = false;
 #elif BUILDFLAG(IS_APPLE)
   // Don't try to display any UI on top of the system's login screen as this
