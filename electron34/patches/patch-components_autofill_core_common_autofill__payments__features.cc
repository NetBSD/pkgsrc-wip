$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -13,7 +13,7 @@ BASE_FEATURE(kAutofillDisableLocalCardMi
              "AutofillDisableLocalCardMigration",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
 // When enabled, Chrome will extract the checkout amount from the checkout page
 // of the allowlisted merchant websites.
@@ -319,7 +319,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccount
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
