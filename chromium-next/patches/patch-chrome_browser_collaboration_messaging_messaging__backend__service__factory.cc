$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/collaboration/messaging/messaging_backend_service_factory.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/collaboration/messaging/messaging_backend_service_factory.cc
@@ -100,7 +100,7 @@ MessagingBackendServiceFactory::BuildSer
   // This configuration object allows us to control platform specific behavior.
   MessagingBackendConfiguration configuration;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   configuration.clear_chip_on_tab_selection = false;
 #endif
 
