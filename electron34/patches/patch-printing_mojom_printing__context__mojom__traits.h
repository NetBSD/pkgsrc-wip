$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- printing/mojom/printing_context_mojom_traits.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ printing/mojom/printing_context_mojom_traits.h
@@ -166,7 +166,7 @@ struct StructTraits<printing::mojom::Pri
     return s.pages_per_sheet();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static const printing::PrintSettings::AdvancedSettings& advanced_settings(
       const printing::PrintSettings& s) {
     return s.advanced_settings();
