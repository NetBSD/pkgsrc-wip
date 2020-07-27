$NetBSD$

--- chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ chrome/browser/ui/views/chrome_browser_main_extra_parts_views.cc
@@ -32,7 +32,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -99,7 +99,7 @@ void ChromeBrowserMainExtraPartsViews::P
         devtools_server_->tracing_agent());
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // On the Linux desktop, we want to prevent the user from logging in as root,
   // so that we don't destroy the profile. Now that we have some minimal ui
   // initialized, check to see if we're running as root and bail if we are.
