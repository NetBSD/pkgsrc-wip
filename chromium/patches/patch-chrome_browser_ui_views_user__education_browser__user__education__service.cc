$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/user_education/browser_user_education_service.cc.orig	2024-10-26 07:00:01.207335000 +0000
+++ chrome/browser/ui/views/user_education/browser_user_education_service.cc
@@ -777,7 +777,7 @@ void MaybeRegisterChromeFeaturePromos(
                          "defaulted to saved for the first time.")));
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHSupervisedUserProfileSigninFeature
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
@@ -1003,7 +1003,7 @@ void MaybeRegisterChromeFeaturePromos(
                     FeaturePromoSpecification::AcceleratorInfo())
                     .SetBubbleArrow(HelpBubbleArrow::kTopLeft)));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // kIPHDesktopPWAsLinkCapturingLaunch:
   registry.RegisterFeature(std::move(
       FeaturePromoSpecification::CreateForCustomAction(
