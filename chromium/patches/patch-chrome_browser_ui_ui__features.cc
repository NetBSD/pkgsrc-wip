$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/ui_features.cc.orig	2026-09-07 10:14:27.000000000 +0000
+++ chrome/browser/ui/ui_features.cc
@@ -102,7 +102,7 @@ bool IsWebuiRefresh2026Enabled() {
          base::FeatureList::IsEnabled(kWebuiRefresh2026);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDseIntegrity, base::FEATURE_ENABLED_BY_DEFAULT);
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
@@ -337,7 +337,7 @@ BASE_FEATURE(kTabsFromOtherDevicesSidePa
 BASE_FEATURE(kNonMilestoneUpdateToast, base::FEATURE_ENABLED_BY_DEFAULT);
 
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSessionRestoreInfobar, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE_PARAM(bool,
