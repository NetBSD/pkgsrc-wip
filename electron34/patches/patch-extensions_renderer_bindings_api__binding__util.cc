$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/renderer/bindings/api_binding_util.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -128,7 +128,7 @@ void InvalidateContext(v8::Local<v8::Con
 std::string GetPlatformString() {
 #if BUILDFLAG(IS_CHROMEOS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
