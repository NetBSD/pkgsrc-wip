$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/core/app/crashpad_mac.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/crash/core/app/crashpad_mac.mm
@@ -86,6 +86,8 @@ std::map<std::string, std::string> GetPr
     }  // @autoreleasepool
     return process_annotations;
   }();
+  CrashReporterClient* crash_reporter_client = GetCrashReporterClient();
+  crash_reporter_client->GetProcessSimpleAnnotations(&annotations);
   return annotations;
 }
 
@@ -156,6 +158,13 @@ bool PlatformCrashpadInitialization(
 
       std::vector<std::string> arguments;
 
+      if (!crash_reporter_client->GetShouldRateLimit()) {
+        arguments.push_back("--no-rate-limit");
+      }
+      if (!crash_reporter_client->GetShouldCompressUploads()) {
+        arguments.push_back("--no-upload-gzip");
+      }
+
       if (crash_reporter_client->ShouldMonitorCrashHandlerExpensively()) {
         arguments.push_back("--monitor-self");
       }
