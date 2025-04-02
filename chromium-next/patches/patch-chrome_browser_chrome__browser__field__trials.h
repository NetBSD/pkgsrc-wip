$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.h.orig	2025-03-20 19:11:33.000000000 +0000
+++ chrome/browser/chrome_browser_field_trials.h
@@ -33,7 +33,7 @@ class ChromeBrowserFieldTrials : public 
       const variations::EntropyProviders& entropy_providers,
       base::FeatureList* feature_list) override;
   void RegisterSyntheticTrials() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void RegisterFeatureOverrides(base::FeatureList* feature_list) override;
 #endif
 
