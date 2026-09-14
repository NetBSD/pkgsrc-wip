$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/glic_settings_util_desktop.cc.orig	2026-09-07 10:14:27.000000000 +0000
+++ chrome/browser/glic/glic_settings_util_desktop.cc
@@ -113,7 +113,7 @@ std::string_view GetPlatformHelpSuffix()
   return "_mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "_chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "_linux";
 #else
   return "";
