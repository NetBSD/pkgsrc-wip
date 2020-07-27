$NetBSD$

--- chrome/browser/chrome_browser_interface_binders.cc.orig	2020-07-08 21:41:46.000000000 +0000
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -119,7 +119,7 @@
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #include "chrome/browser/ui/webui/discards/site_data.mojom.h"
@@ -573,7 +573,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
 
