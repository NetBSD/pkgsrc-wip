$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/ui_features.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/ui_features.h
@@ -68,7 +68,7 @@ extern const base::FeatureParam<bool> kA
 BASE_DECLARE_FEATURE(kExtensionsMenuInAppMenu);
 bool IsExtensionMenuInRootAppMenu();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -277,7 +277,7 @@ BASE_DECLARE_FEATURE(kViewsJSAppModalDia
 
 BASE_DECLARE_FEATURE(kStopLoadingAnimationForHiddenWindow);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
