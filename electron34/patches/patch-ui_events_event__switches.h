$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/events/event_switches.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/events/event_switches.h
@@ -13,7 +13,7 @@ namespace switches {
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 EVENTS_BASE_EXPORT extern const char kTouchSlopDistance[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
