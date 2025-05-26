$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/webui/web_ui_util.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/base/webui/web_ui_util.cc
@@ -43,7 +43,7 @@ namespace {
 constexpr float kMaxScaleFactor = 1000.0f;
 
 std::string GetFontFamilyMd() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Roboto, " + GetFontFamily();
 #else
   return GetFontFamily();
@@ -218,7 +218,7 @@ void AppendWebUiCssTextDefaults(std::str
 std::string GetFontFamily() {
   std::string font_family = l10n_util::GetStringUTF8(IDS_WEB_FONT_FAMILY);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string font_name = ui::ResourceBundle::GetSharedInstance()
                               .GetFont(ui::ResourceBundle::BaseFont)
                               .GetFontName();
