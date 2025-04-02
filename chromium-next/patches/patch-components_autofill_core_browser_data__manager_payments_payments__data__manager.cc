$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/data_manager/payments/payments_data_manager.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.cc
@@ -1168,7 +1168,7 @@ bool PaymentsDataManager::IsServerCard(c
 bool PaymentsDataManager::ShouldShowCardsFromAccountOption() const {
 // The feature is only for Linux, Windows, Mac, and Fuchsia.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // This option should only be shown for users that have not enabled the Sync
   // Feature and that have server credit cards available.
   // TODO(crbug.com/40066949): Simplify once ConsentLevel::kSync and
@@ -2021,7 +2021,7 @@ bool PaymentsDataManager::AreEwalletAcco
 
 bool PaymentsDataManager::AreBnplIssuersSupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kAutofillEnableBuyNowPayLaterSyncing);
 #else
