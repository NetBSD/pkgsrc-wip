$NetBSD$

--- chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/ui/webui/chrome_web_ui_controller_factory.cc
@@ -287,7 +287,7 @@ bool IsAboutUI(const GURL& url) {
 #if !defined(OS_ANDROID)
           || url.host() == chrome::kChromeUITermsHost
 #endif
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
           || url.host() == chrome::kChromeUILinuxProxyConfigHost ||
           url.host() == chrome::kChromeUISandboxHost
 #endif
