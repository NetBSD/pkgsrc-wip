$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -551,7 +551,7 @@ bool OriginTrialContext::CanEnableTrialF
   }
 
   if (trial_name == "TranslationAPI") {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(features::kEnableTranslationAPI);
 #else
     return false;
