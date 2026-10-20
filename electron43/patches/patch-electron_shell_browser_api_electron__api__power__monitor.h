$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -44,7 +44,7 @@ class PowerMonitor final : public gin::W
   PowerMonitor& operator=(const PowerMonitor&) = delete;
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
