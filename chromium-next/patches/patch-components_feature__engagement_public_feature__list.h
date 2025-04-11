$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/feature_list.h.orig	2025-03-31 15:23:48.000000000 +0000
+++ components/feature_engagement/public/feature_list.h
@@ -302,7 +302,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSDownloadAu
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 DEFINE_VARIATION_PARAM(kEsbDownloadRowPromoFeature, "EsbDownloadRowPromo");
 #endif
@@ -415,7 +415,8 @@ DEFINE_VARIATION_PARAM(kIPHTabGroupsShar
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillCreditCardBenefitFeature,
                        "IPH_AutofillCreditCardBenefit");
 
@@ -509,7 +510,7 @@ DEFINE_VARIATION_PARAM(kIPHScalableIphHe
 DEFINE_VARIATION_PARAM(kIPHScalableIphGamingFeature, "IPH_ScalableIphGaming");
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunch,
                        "IPH_DesktopPWAsLinkCapturingLaunch");
 DEFINE_VARIATION_PARAM(kIPHDesktopPWAsLinkCapturingLaunchAppInTab,
@@ -682,7 +683,7 @@ inline constexpr flags_ui::FeatureEntry:
             kIPHiOSReminderNotificationsOverflowMenuNewBadgeFeature),
         VARIATION_ENTRY(kIPHiOSDownloadAutoDeletionFeature),
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHBatterySaverModeFeature),
         VARIATION_ENTRY(kIPHCompanionSidePanelFeature),
         VARIATION_ENTRY(kIPHCompanionSidePanelRegionSearchFeature),
@@ -743,7 +744,8 @@ inline constexpr flags_ui::FeatureEntry:
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHAutofillCreditCardBenefitFeature),
         VARIATION_ENTRY(kIPHAutofillCardInfoRetrievalSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillDisabledVirtualCardSuggestionFeature),
@@ -795,7 +797,7 @@ inline constexpr flags_ui::FeatureEntry:
         VARIATION_ENTRY(kIPHScalableIphGamingFeature),
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunch),
         VARIATION_ENTRY(kIPHDesktopPWAsLinkCapturingLaunchAppInTab),
         VARIATION_ENTRY(kIPHSupervisedUserProfileSigninFeature),
