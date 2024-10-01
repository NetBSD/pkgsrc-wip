$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/autofill_optimization_guide.cc.orig	2024-09-24 20:49:24.071474800 +0000
+++ components/autofill/core/browser/autofill_optimization_guide.cc
@@ -186,7 +186,7 @@ void AutofillOptimizationGuide::OnDidPar
     }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (has_credit_card_field &&
         !personal_data_manager->payments_data_manager()
              .GetServerCreditCards()
