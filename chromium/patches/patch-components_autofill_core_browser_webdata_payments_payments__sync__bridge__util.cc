$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc
@@ -1252,7 +1252,7 @@ bool AreMaskedBankAccountSupported() {
 
 bool IsBnplIssuerSupported() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kAutofillEnableBuyNowPayLaterSyncing);
 #else
