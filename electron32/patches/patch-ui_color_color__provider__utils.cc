$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/color_provider_utils.cc.orig	2024-10-18 12:35:12.440383700 +0000
+++ ui/color/color_provider_utils.cc
@@ -187,7 +187,7 @@ std::string_view SystemThemeName(ui::Sys
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
