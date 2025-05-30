$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/ui_features.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/ui_features.cc
@@ -90,7 +90,7 @@ bool IsExtensionMenuInRootAppMenu() {
   return base::FeatureList::IsEnabled(kExtensionsMenuInAppMenu);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations,
@@ -300,7 +300,7 @@ BASE_FEATURE(kTabOrganizationAppMenuItem
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kMultiTabOrganization,
              "MultiTabOrganization",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -463,7 +463,7 @@ BASE_FEATURE(kStopLoadingAnimationForHid
              "StopLoadingAnimationForHiddenWindow",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor,
              "UsePortalAccentColor",
              base::FEATURE_ENABLED_BY_DEFAULT);
