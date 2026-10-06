$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/app/electron_crash_reporter_client.h.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/app/electron_crash_reporter_client.h
@@ -30,7 +30,7 @@ class ElectronCrashReporterClient : publ
       const std::map<std::string, std::string>& annotations);
 
   // crash_reporter::CrashReporterClient implementation.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetCrashReporterClientIdFromGUID(
       const std::string& client_guid) override;
   void GetProductNameAndVersion(const char** product_name,
@@ -69,7 +69,7 @@ class ElectronCrashReporterClient : publ
   bool ReportingIsEnforcedByPolicy(bool* breakpad_enabled) override;
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool ShouldMonitorCrashHandlerExpensively() override;
 #endif
 
