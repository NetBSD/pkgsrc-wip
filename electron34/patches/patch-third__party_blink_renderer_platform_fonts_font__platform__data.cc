$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/fonts/font_platform_data.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/fonts/font_platform_data.cc
@@ -54,7 +54,7 @@
 namespace blink {
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Getting the system font render style takes a significant amount of time on
 // Linux because looking up fonts using fontconfig can be very slow. We fetch
 // the render style for each font family and text size, while it's very
@@ -133,7 +133,7 @@ FontPlatformData::FontPlatformData(sk_sp
   style_ = WebFontRenderStyle::GetDefault();
 #if !BUILDFLAG(IS_WIN)
   WebFontRenderStyle system_style;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool override_font_name_and_size =
       base::FeatureList::IsEnabled(kOptimizeLinuxFonts);
 #else
