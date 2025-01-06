$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/core/app/crash_reporter_client.cc.orig	2024-10-18 12:34:06.622489700 +0000
+++ components/crash/core/app/crash_reporter_client.cc
@@ -141,6 +141,17 @@ bool CrashReporterClient::ReportingIsEnf
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
