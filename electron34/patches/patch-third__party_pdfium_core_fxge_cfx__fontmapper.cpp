$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -157,7 +157,7 @@ constexpr AltFontFamily kAltFontFamilies
     {"ForteMT", "Forte"},
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS) || BUILDFLAG(IS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif BUILDFLAG(IS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";
