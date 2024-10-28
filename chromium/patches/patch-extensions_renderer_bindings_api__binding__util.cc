$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/renderer/bindings/api_binding_util.cc.orig	2024-10-26 07:00:17.540257700 +0000
+++ extensions/renderer/bindings/api_binding_util.cc
@@ -133,7 +133,7 @@ std::string GetPlatformString() {
   return "lacros";
 #elif BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   return "chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_MAC)
   return "mac";
