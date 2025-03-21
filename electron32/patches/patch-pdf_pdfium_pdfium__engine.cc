$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- pdf/pdfium/pdfium_engine.cc.orig	2024-10-18 12:34:31.661922000 +0000
+++ pdf/pdfium/pdfium_engine.cc
@@ -93,7 +93,7 @@
 #include "gin/public/cppgc.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -524,7 +524,7 @@ void InitializeSDK(bool enable_v8,
 
   FPDF_InitLibraryWithConfig(&config);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   g_font_mapping_mode = font_mapping_mode;
   InitializeLinuxFontMapper();
 #endif
