$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_payments_features.h.orig	2025-02-17 21:09:38.000000000 +0000
+++ components/autofill/core/common/autofill_payments_features.h
@@ -17,7 +17,7 @@ COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillDisableLocalCardMigration);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillEnableAmountExtractionDesktop);
 #endif
