$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/app/electron_crash_reporter_client.cc.orig	2025-02-26 12:22:11.000000000 +0000
+++ electron/shell/app/electron_crash_reporter_client.cc
@@ -95,7 +95,7 @@ ElectronCrashReporterClient::ElectronCra
 
 ElectronCrashReporterClient::~ElectronCrashReporterClient() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ElectronCrashReporterClient::SetCrashReporterClientIdFromGUID(
     const std::string& client_guid) {
   crash_keys::SetMetricsClientIdFromGUID(client_guid);
@@ -196,7 +196,7 @@ void ElectronCrashReporterClient::GetPro
   (*annotations)["ver"] = ELECTRON_VERSION_STRING;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 bool ElectronCrashReporterClient::ShouldMonitorCrashHandlerExpensively() {
   return false;
 }
