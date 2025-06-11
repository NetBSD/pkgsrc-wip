$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-05-26 15:57:59.000000000 +0000
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -109,7 +109,7 @@ bool AmountExtractionManager::ShouldTrig
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -123,7 +123,7 @@ bool AmountExtractionManager::ShouldTrig
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     return base::FeatureList::IsEnabled(
         ::autofill::features::kAutofillEnableAmountExtractionDesktop);
   } else {
@@ -190,7 +190,7 @@ void AmountExtractionManager::OnCheckout
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -214,7 +214,7 @@ void AmountExtractionManager::OnTimeoutR
       autofill_metrics::AmountExtractionResult::kTimeout);
   // TODO(crbug.com/378517983): Add BNPL flow action logic here.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
