$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/renderer/bindings/api_binding_util.cc.orig	2024-10-18 12:34:18.048533000 +0000
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -132,7 +132,7 @@ std::string GetPlatformString() {
   return "lacros";
 #elif BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
