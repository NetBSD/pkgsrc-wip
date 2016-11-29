$NetBSD$

--- chrome/browser/web_applications/web_app.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/web_applications/web_app.cc
@@ -507,7 +507,7 @@ void GetIconsInfo(const WebApplicationIn
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 std::string GetWMClassFromAppName(std::string app_name) {
   base::i18n::ReplaceIllegalCharactersInPath(&app_name, '_');
   base::TrimString(app_name, "_", &app_name);
