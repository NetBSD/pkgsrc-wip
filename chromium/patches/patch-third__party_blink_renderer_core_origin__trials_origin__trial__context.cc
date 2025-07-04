$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2025-05-30 19:50:32.000000000 +0000
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -573,7 +573,7 @@ bool OriginTrialContext::CanEnableTrialF
   }
 
   if (trial_name == "TranslationAPI") {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(features::kTranslationAPI);
 #else
     return false;
