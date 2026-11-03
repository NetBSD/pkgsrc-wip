$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/api/electron_api_power_monitor.h.orig	2026-10-30 06:33:33.000000000 +0000
+++ electron/shell/browser/api/electron_api_power_monitor.h
@@ -56,7 +56,7 @@ class PowerMonitor final : public gin::W
   PowerMonitor& operator=(const PowerMonitor&) = delete;
 
  private:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetListeningForShutdown(bool);
 #endif
 
