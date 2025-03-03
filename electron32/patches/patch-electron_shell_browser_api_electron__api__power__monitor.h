$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -40,7 +40,7 @@ class PowerMonitor final : public gin::W
   explicit PowerMonitor(v8::Isolate* isolate);
   ~PowerMonitor() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
