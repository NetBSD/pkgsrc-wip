$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/core/app/crashpad_win.cc.orig	2024-10-18 12:34:06.622489700 +0000
+++ components/crash/core/app/crashpad_win.cc
@@ -92,6 +92,7 @@ bool PlatformCrashpadInitialization(
 
     std::map<std::string, std::string> process_annotations;
     GetPlatformCrashpadAnnotations(&process_annotations);
+    crash_reporter_client->GetProcessSimpleAnnotations(&process_annotations);
 
     std::string url = crash_reporter_client->GetUploadUrl();
 
@@ -129,6 +130,13 @@ bool PlatformCrashpadInitialization(
 
     std::vector<std::string> arguments(start_arguments);
 
+    if (!crash_reporter_client->GetShouldRateLimit()) {
+      arguments.push_back("--no-rate-limit");
+    }
+    if (!crash_reporter_client->GetShouldCompressUploads()) {
+      arguments.push_back("--no-upload-gzip");
+    }
+
     if (crash_reporter_client->ShouldMonitorCrashHandlerExpensively()) {
       arguments.push_back("--monitor-self");
       for (const std::string& start_argument : start_arguments) {
