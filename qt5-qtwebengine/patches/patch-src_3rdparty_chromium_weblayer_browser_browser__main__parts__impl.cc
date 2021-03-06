$NetBSD$

--- src/3rdparty/chromium/weblayer/browser/browser_main_parts_impl.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/browser_main_parts_impl.cc
@@ -56,7 +56,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -140,7 +140,7 @@ int BrowserMainPartsImpl::PreEarlyInitia
 #if defined(USE_X11)
   ui::SetDefaultX11ErrorHandlers();
 #endif
-#if defined(USE_AURA) && defined(OS_LINUX)
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
