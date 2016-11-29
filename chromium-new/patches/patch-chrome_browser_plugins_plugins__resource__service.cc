$NetBSD$

--- chrome/browser/plugins/plugins_resource_service.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/plugins/plugins_resource_service.cc
@@ -31,7 +31,7 @@ GURL GetPluginsServerURL() {
   std::string filename;
 #if defined(OS_WIN)
   filename = "plugins_win.json";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   filename = "plugins_linux.json";
 #elif defined(OS_MACOSX)
   filename = "plugins_mac.json";
