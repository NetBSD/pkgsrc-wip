$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide.cc
@@ -231,7 +231,7 @@ void AutofillOptimizationGuide::OnDidPar
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto bnpl_issuer_allowlist_can_be_loaded =
       [&payments_data_manager](BnplIssuer::IssuerId issuer_id) {
         return base::Contains(payments_data_manager.GetBnplIssuers(), issuer_id,
