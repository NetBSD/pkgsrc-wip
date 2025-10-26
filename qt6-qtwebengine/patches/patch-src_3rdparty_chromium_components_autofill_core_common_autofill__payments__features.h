$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.h
@@ -14,7 +14,7 @@ namespace autofill::features {
 
 // All features in alphabetical order.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(AUTOFILL)
 BASE_DECLARE_FEATURE(kAutofillEnableAmountExtractionDesktop);
 #endif
