$NetBSD$

--- ui/base/webui/web_ui_util.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ ui/base/webui/web_ui_util.cc
@@ -228,7 +228,7 @@ std::string GetFontFamily() {
 
 // TODO(dnicoara) Remove Ozone check when PlatformFont support is introduced
 // into Ozone: crbug.com/320050
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)
   font_family = ui::ResourceBundle::GetSharedInstance().GetFont(
       ui::ResourceBundle::BaseFont).GetFontName() + ", " + font_family;
 #endif
