$NetBSD$

--- chrome/browser/ui/views/frame/browser_frame.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame.cc
@@ -36,7 +36,7 @@
 #include "ui/native_theme/native_theme_dark_aura.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/views/frame/browser_command_handler_linux.h"
 #endif
 
@@ -88,7 +88,7 @@ void BrowserFrame::InitBrowserFrame() {
     non_client_view()->set_context_menu_controller(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   browser_command_handler_.reset(new BrowserCommandHandlerLinux(browser_view_));
 #endif
 }
