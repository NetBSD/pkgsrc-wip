$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/feature_engagement/public/feature_list.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/feature_engagement/public/feature_list.cc
@@ -160,7 +160,7 @@ const base::Feature* const kAllFeatures[
     &kIPHiOSLensOverlayEntrypointTipFeature,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
     &kEsbDownloadRowPromoFeature,
 #endif
@@ -230,7 +230,8 @@ const base::Feature* const kAllFeatures[
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
     &kIPHAutofillCreditCardBenefitFeature,
     &kIPHAutofillDisabledVirtualCardSuggestionFeature,
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
@@ -283,7 +284,7 @@ const base::Feature* const kAllFeatures[
     &kIPHScalableIphGamingFeature,
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     &kIPHDesktopPWAsLinkCapturingLaunch,
     &kIPHDesktopPWAsLinkCapturingLaunchAppInTab,
     &kIPHToolbarManagementButtonFeature,
