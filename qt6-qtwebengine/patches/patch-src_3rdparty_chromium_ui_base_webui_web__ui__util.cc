$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/webui/web_ui_util.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/ui/base/webui/web_ui_util.cc
@@ -41,7 +41,7 @@ namespace {
 constexpr float kMaxScaleFactor = 1000.0f;
 
 std::string GetFontFamilyMd() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Roboto, " + GetFontFamily();
 #else
   return GetFontFamily();
@@ -219,7 +219,7 @@ std::string GetFontFamily() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   const base::CommandLine* cmdline = base::CommandLine::ForCurrentProcess();
   if (!cmdline->HasSwitch(switches::kSingleProcess)) {
     std::string font_name = ui::ResourceBundle::GetSharedInstance()
