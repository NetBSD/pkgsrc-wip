$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/renderer/api/electron_api_crash_reporter_renderer.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/renderer/api/electron_api_crash_reporter_renderer.cc
@@ -6,7 +6,7 @@
 #include "shell/common/gin_helper/dictionary.h"
 #include "shell/common/node_includes.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -14,13 +14,13 @@ namespace {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
 }
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -31,7 +31,7 @@ void Initialize(v8::Local<v8::Object> ex
                 void* priv) {
   v8::Isolate* const isolate = v8::Isolate::GetCurrent();
   gin_helper::Dictionary dict{isolate, exports};
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
   dict.SetMethod("addExtraParameter", &SetCrashKeyStub);
   dict.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
