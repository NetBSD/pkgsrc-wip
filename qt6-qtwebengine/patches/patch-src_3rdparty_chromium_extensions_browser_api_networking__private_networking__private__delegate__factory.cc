$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -14,7 +14,7 @@
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "extensions/browser/api/networking_private/networking_private_lacros.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -67,7 +67,7 @@ NetworkingPrivateDelegateFactory::BuildS
   delegate = std::make_unique<NetworkingPrivateChromeOS>(browser_context);
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   delegate = std::make_unique<NetworkingPrivateLacros>(browser_context);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate = std::make_unique<NetworkingPrivateLinux>();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
