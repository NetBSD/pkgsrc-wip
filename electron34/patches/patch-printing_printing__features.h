$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/printing_features.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ printing/printing_features.h
@@ -22,7 +22,7 @@ COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAddPrinterViaPrintscanmgr);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
