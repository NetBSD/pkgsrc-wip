$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.cc
@@ -6,7 +6,7 @@
 
 namespace switches {
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kClearPrefForUnknownCountry,
              "ClearCountryPrefForStoredUnknownCountry",
              base::FEATURE_DISABLED_BY_DEFAULT);
