$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/feature_engagement/public/feature_constants.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/feature_engagement/public/feature_constants.cc
@@ -18,7 +18,7 @@ BASE_FEATURE(kIPHDemoMode, "IPH_DemoMode
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
 BASE_FEATURE(kEsbDownloadRowPromoFeature,
              "EsbDownloadRowPromo",
@@ -646,7 +646,8 @@ BASE_FEATURE(kDefaultBrowserTriggerCrite
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillCreditCardBenefitFeature,
              "IPH_AutofillCreditCardBenefit",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -789,7 +790,7 @@ BASE_FEATURE(kIPHScalableIphGamingFeatur
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This can be enabled by default, as the DesktopPWAsLinkCapturing
 // flag is needed for the IPH linked to this feature to work, and
 // use-cases to show the IPH are guarded by that flag.
