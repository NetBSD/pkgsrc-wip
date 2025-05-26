$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/crash/core/app/crash_reporter_client.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/crash/core/app/crash_reporter_client.h
@@ -7,6 +7,7 @@
 
 #include <stdint.h>
 
+#include <map>
 #include <string>
 
 #include "build/build_config.h"
@@ -129,6 +130,19 @@ class CrashReporterClient {
   // that case, |breakpad_enabled| is set to the value enforced by policies.
   virtual bool ReportingIsEnforcedByPolicy(bool* breakpad_enabled);
 
+  // Returns true if crash uploads should be rate limited. If false, no
+  // throttling will be applied for uploads.
+  virtual bool GetShouldRateLimit();
+
+  // Returns true if crash uploads should be compressed with gzip. If false,
+  // reports will be uploaded uncompressed.
+  virtual bool GetShouldCompressUploads();
+
+  // Allows the client to add or edit global annotations passed to the crashpad
+  // handler.
+  virtual void GetProcessSimpleAnnotations(
+      std::map<std::string, std::string>* annotations);
+
 #if BUILDFLAG(IS_ANDROID)
   // Used by WebView to sample crashes without generating the unwanted dumps. If
   // the returned value is less than 100, crash dumping will be sampled to that
