$NetBSD: patch-webkit_glue_webkitclient__impl.h,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- webkit/glue/webkitclient_impl.h.orig	2011-04-13 08:01:08.000000000 +0000
+++ webkit/glue/webkitclient_impl.h
@@ -10,7 +10,7 @@
 #include "third_party/WebKit/Source/WebKit/chromium/public/WebKitClient.h"
 #if defined(OS_WIN)
 #include "webkit/glue/webthemeengine_impl_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "webkit/glue/webthemeengine_impl_linux.h"
 #elif defined(OS_MACOSX)
 #include "webkit/glue/webthemeengine_impl_mac.h"
@@ -91,7 +91,7 @@ class WebKitClientImpl : public WebKit::
   double shared_timer_fire_time_;
   int shared_timer_suspended_;  // counter
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   WebThemeEngineImpl theme_engine_;
 #endif
 };
