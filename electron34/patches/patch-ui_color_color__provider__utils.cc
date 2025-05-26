$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/color_provider_utils.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/color/color_provider_utils.cc
@@ -189,7 +189,7 @@ std::string_view SystemThemeName(ui::Sys
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
