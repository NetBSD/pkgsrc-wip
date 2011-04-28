$NetBSD: patch-chrome_browser_browser__about__handler.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/browser_about_handler.cc.orig	2011-04-13 08:01:44.000000000 +0000
+++ chrome/browser/browser_about_handler.cc
@@ -70,7 +70,7 @@
 #include "chrome/browser/zygote_host_linux.h"
 #elif defined(OS_MACOSX)
 #include "chrome/browser/ui/cocoa/about_ipc_dialog.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/zygote_host_linux.h"
 #endif
 
@@ -121,7 +121,7 @@ const char kNetInternalsPath[] = "net-in
 const char kPluginsPath[] = "plugins";
 const char kSyncInternalsPath[] = "sync-internals";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kLinuxProxyConfigPath[] = "linux-proxy-config";
 const char kSandboxPath[] = "sandbox";
 #endif
@@ -153,7 +153,7 @@ const char *kAllAboutPaths[] = {
   kTcmallocPath,
   kTermsPath,
   kVersionPath,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   kSandboxPath,
 #endif
 #if defined(OS_CHROMEOS)
@@ -544,7 +544,7 @@ std::string AboutStats() {
   return data;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::string AboutLinuxProxyConfig() {
   std::string data;
   data.append("<!DOCTYPE HTML>\n");
@@ -766,7 +766,7 @@ void AboutSource::StartDataRequest(const
   } else if (path == kTermsPath) {
     response = ResourceBundle::GetSharedInstance().GetRawDataResource(
         IDR_TERMS_HTML).as_string();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (path == kLinuxProxyConfigPath) {
     response = AboutLinuxProxyConfig();
   } else if (path == kSandboxPath) {
