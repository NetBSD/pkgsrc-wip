$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/api/electron_api_safe_storage.h.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/shell/browser/api/electron_api_safe_storage.h
@@ -78,7 +78,7 @@ class SafeStorage final : public gin_hel
   v8::Local<v8::Promise> decryptStringAsync(v8::Isolate* isolate,
                                             v8::Local<v8::Value> buffer);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string GetSelectedLinuxBackend();
 #endif
 
