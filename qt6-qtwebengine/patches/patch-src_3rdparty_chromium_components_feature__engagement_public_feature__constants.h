$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/components/feature_engagement/public/feature_constants.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(kUseClientConfigIPH
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHBatterySaverModeFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelRegionSearchFeature);
@@ -81,7 +81,7 @@ BASE_DECLARE_FEATURE(kIPHWebUiHelpBubble
 BASE_DECLARE_FEATURE(kIPHPriceTrackingInSidePanelFeature);
 BASE_DECLARE_FEATURE(kIPHBackNavigationMenuFeature);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
-        // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+        // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
 // All the features declared for Android below that are also used in Java,
 // should also be declared in:
@@ -253,7 +253,8 @@ extern const base::FeatureParam<int>
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardCVCSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardSuggestionFeature);
@@ -300,7 +301,7 @@ BASE_DECLARE_FEATURE(kIPHScalableIphHelp
 BASE_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunch);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
