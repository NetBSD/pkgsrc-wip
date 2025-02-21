$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/search_engines/search_engines_switches.h.orig	2025-02-17 21:09:38.000000000 +0000
+++ components/search_engines/search_engines_switches.h
@@ -113,7 +113,7 @@ BASE_DECLARE_FEATURE(kTemplateUrlReconci
 COMPONENT_EXPORT(SEARCH_ENGINES_SWITCHES)
 extern const base::FeatureParam<bool> kReconcileWithAllKnownEngines;
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When the `country_codes::kCountryIDUnknown` is stored in prefs and this
 // feature is enabled the pref will be cleared allowing a valid country to be
 // set again.
