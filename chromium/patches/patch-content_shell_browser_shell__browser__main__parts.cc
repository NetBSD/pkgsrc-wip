$NetBSD$

--- content/shell/browser/shell_browser_main_parts.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -50,7 +50,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 #if defined(OS_CHROMEOS)
@@ -137,7 +137,7 @@ int ShellBrowserMainParts::PreEarlyIniti
   if (!features::IsUsingOzonePlatform())
     ui::SetDefaultX11ErrorHandlers();
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
