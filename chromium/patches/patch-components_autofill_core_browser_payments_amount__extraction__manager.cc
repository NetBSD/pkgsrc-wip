$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -178,7 +178,7 @@ void AmountExtractionManager::OnCheckout
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The result of amount extraction on domain "
@@ -206,7 +206,7 @@ void AmountExtractionManager::OnTimeoutR
   }
   // TODO(crbug.com/378517983): Add BNPL flow action logic here.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::kAutofillEnableAmountExtractionTesting)) {
       VLOG(3) << "The amount extraction on domain "
@@ -225,7 +225,7 @@ AmountExtractionManager::CheckEligibilit
   // Check eligibility of BNPL feature.
   // Currently, BNPL is only offered for desktop platforms.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (BnplManager* bnpl_manager = autofill_manager_->GetPaymentsBnplManager();
         bnpl_manager && bnpl_manager->IsEligibleForBnpl()) {
       eligible_features.insert(EligibleFeature::kBnpl);
