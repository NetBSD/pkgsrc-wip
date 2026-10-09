$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/v8_oom_diagnostics.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/common/v8_oom_diagnostics.cc
@@ -15,7 +15,7 @@
 
 namespace electron::v8_oom {
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 
 namespace {
 
@@ -140,6 +140,6 @@ bool RecordHeapDiagnostics(v8::Isolate*)
 void RecordErrorDetails(v8::Isolate*, const char*, const v8::OOMDetails&) {}
 void RecordJsStack(v8::Isolate*, std::string_view) {}
 
-#endif  // !IS_MAS_BUILD()
+#endif  // !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 
 }  // namespace electron::v8_oom
