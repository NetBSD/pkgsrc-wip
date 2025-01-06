$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/ui_features.cc.orig	2024-10-18 12:34:03.304300000 +0000
+++ chrome/browser/ui/ui_features.cc
@@ -108,7 +108,7 @@ BASE_FEATURE(kEvDetailsInPageInfo,
              "EvDetailsInPageInfo",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations,
@@ -381,7 +381,7 @@ BASE_FEATURE(kTopChromeWebUIUsesSpareRen
              "TopChromeWebUIUsesSpareRenderer",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables alternate update-related text to be displayed in browser app menu
 // button, menu item and confirmation dialog.
 BASE_FEATURE(kUpdateTextOptions,
@@ -457,7 +457,7 @@ BASE_FEATURE(kStopLoadingAnimationForHid
              "StopLoadingAnimationForHiddenWindow",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor,
              "UsePortalAccentColor",
              base::FEATURE_ENABLED_BY_DEFAULT);
