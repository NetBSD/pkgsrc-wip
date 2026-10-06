$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/core/app/crash_reporter_client.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/crash/core/app/crash_reporter_client.cc
@@ -122,6 +122,17 @@ bool CrashReporterClient::ReportingIsEnf
   return false;
 }
 
+bool CrashReporterClient::GetShouldRateLimit() {
+  return true;
+}
+
+bool CrashReporterClient::GetShouldCompressUploads() {
+  return true;
+}
+
+void CrashReporterClient::GetProcessSimpleAnnotations(std::map<std::string, std::string>* annotations) {
+}
+
 #if BUILDFLAG(IS_ANDROID)
 unsigned int CrashReporterClient::GetCrashDumpPercentage() {
   return 100;
