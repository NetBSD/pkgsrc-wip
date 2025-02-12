$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/printing/printing_features.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/printing/printing_features.h
@@ -21,7 +21,7 @@ namespace features {
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kEnableBorderlessPrinting);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_MAC)
 
