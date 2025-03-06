$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -292,7 +292,7 @@ BASE_FEATURE(kAutofillSyncEwalletAccount
 #endif  // BUILDFLAG(IS_ANDROID)
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
