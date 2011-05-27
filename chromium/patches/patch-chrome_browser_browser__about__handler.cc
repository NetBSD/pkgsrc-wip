$NetBSD: patch-chrome_browser_browser__about__handler.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/browser/browser_about_handler.cc.orig	2011-05-24 08:01:43.000000000 +0000
+++ chrome/browser/browser_about_handler.cc
@@ -71,7 +71,7 @@
 #include "chrome/browser/chromeos/login/wizard_controller.h"
 #include "chrome/browser/chromeos/version_loader.h"
 #include "content/browser/zygote_host_linux.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/browser/zygote_host_linux.h"
 #endif
 
@@ -126,7 +126,7 @@ const char kNetInternalsPath[] = "net-in
 const char kPluginsPath[] = "plugins";
 const char kSyncInternalsPath[] = "sync-internals";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kLinuxProxyConfigPath[] = "linux-proxy-config";
 const char kSandboxPath[] = "sandbox";
 #endif
@@ -160,7 +160,7 @@ const char *kAllAboutPaths[] = {
   kTcmallocPath,
   kTermsPath,
   kVersionPath,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   kSandboxPath,
 #endif
 #if defined(OS_CHROMEOS)
@@ -648,7 +648,7 @@ std::string AboutStats(const std::string
   return data;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   data.append("<!DOCTYPE HTML>\n");
@@ -863,7 +863,7 @@ void AboutSource::StartDataRequest(const
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_TERMS_HTML).as_string();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (path == kLinuxProxyConfigPath) {
     response = AboutLinuxProxyConfig();
   } else if (path == kSandboxPath) {
