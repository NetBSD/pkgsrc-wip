$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -121,7 +121,7 @@ void EnsureApiBrowserContextKeyedService
   MessagingAPIMessageFilter::EnsureAssociatedFactoryBuilt();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   OffscreenDocumentManager::GetFactory();
