$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/integrators/autofill_optimization_guide.cc.orig	2025-02-17 21:09:38.000000000 +0000
+++ components/autofill/core/browser/integrators/autofill_optimization_guide.cc
@@ -185,7 +185,7 @@ void AutofillOptimizationGuide::OnDidPar
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (has_credit_card_field &&
       !personal_data_manager.payments_data_manager()
            .GetServerCreditCards()
