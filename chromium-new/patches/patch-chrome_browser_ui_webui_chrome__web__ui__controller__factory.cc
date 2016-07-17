$NetBSD$

--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -269,7 +269,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host() == chrome::kChromeUISandboxHost
 #endif
