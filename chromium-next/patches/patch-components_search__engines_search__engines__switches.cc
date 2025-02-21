$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/search_engines/search_engines_switches.cc.orig	2025-02-17 21:09:38.000000000 +0000
+++ components/search_engines/search_engines_switches.cc
@@ -107,7 +107,7 @@ const base::FeatureParam<bool> kReconcil
     "reconcile_with_all_known_engines",
     false);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(SEARCH_ENGINES_SWITCHES)
 BASE_FEATURE(kClearPrefForUnknownCountry,
              "ClearCountryPrefForStoredUnknownCountry",
