$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/display/screen.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/display/screen.cc
@@ -86,7 +86,7 @@ void Screen::SetDisplayForNewWindows(int
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Screen::ScreenSaverSuspender::~ScreenSaverSuspender() = default;
 
 std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {
