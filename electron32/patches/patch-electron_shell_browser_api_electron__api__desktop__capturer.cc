$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -46,7 +46,7 @@
 #endif
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 base::flat_map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
