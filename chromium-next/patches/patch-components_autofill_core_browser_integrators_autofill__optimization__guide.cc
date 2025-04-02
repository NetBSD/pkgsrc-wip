$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/integrators/autofill_optimization_guide.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ components/autofill/core/browser/integrators/autofill_optimization_guide.cc
@@ -211,7 +211,7 @@ void AutofillOptimizationGuide::OnDidPar
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!server_cards.empty() &&
       base::FeatureList::IsEnabled(
           features::kAutofillEnableAmountExtractionDesktop)) {
