$NetBSD$

--- chrome/browser/web_applications/web_app.cc.orig	2017-02-02 02:02:50.000000000 +0000
+++ chrome/browser/web_applications/web_app.cc
@@ -507,7 +507,7 @@ void GetIconsInfo(const WebApplicationIn
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   base::i18n::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
