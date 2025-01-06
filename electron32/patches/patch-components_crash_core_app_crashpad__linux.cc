$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/core/app/crashpad_linux.cc.orig	2024-10-18 12:34:06.622489700 +0000
+++ components/crash/core/app/crashpad_linux.cc
@@ -231,6 +231,7 @@ bool PlatformCrashpadInitialization(
     // where crash_reporter provides it's own values for lsb-release.
     annotations["lsb-release"] = base::GetLinuxDistro();
 #endif
+    crash_reporter_client->GetProcessSimpleAnnotations(&annotations);
 
     std::vector<std::string> arguments;
     if (crash_reporter_client->ShouldMonitorCrashHandlerExpensively()) {
@@ -252,6 +253,13 @@ bool PlatformCrashpadInitialization(
     }
 #endif
 
+    if (!crash_reporter_client->GetShouldRateLimit()) {
+      arguments.push_back("--no-rate-limit");
+    }
+    if (!crash_reporter_client->GetShouldCompressUploads()) {
+      arguments.push_back("--no-upload-gzip");
+    }
+
     CHECK(client.StartHandler(handler_path, *database_path, metrics_path, url,
                               annotations, arguments, false, false));
   } else {
