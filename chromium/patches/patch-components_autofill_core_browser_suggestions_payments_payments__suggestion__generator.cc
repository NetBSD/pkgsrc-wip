$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator.cc
@@ -1436,7 +1436,7 @@ std::vector<Suggestion> GetCreditCardSug
                              /*extracted_amount_in_micros=*/std::nullopt));
     manager.GetCreditCardFormEventLogger().OnBnplSuggestionShown();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     manager.client()
         .GetPersonalDataManager()
         .payments_data_manager()
