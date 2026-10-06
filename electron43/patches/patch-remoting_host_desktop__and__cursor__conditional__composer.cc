$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/host/desktop_and_cursor_conditional_composer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ remoting/host/desktop_and_cursor_conditional_composer.cc
@@ -7,7 +7,7 @@
 #include "base/functional/bind.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_utils.h"
 #endif
 
@@ -96,7 +96,7 @@ bool DesktopAndCursorConditionalComposer
 }
 
 bool DesktopAndCursorConditionalComposer::SupportsFrameCallbacks() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return IsRunningWayland();
 #else
   return false;
