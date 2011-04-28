$NetBSD: patch-net_proxy_proxy__service.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- net/proxy/proxy_service.cc.orig	2011-04-13 08:01:16.000000000 +0000
+++ net/proxy/proxy_service.cc
@@ -25,7 +25,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "net/proxy/proxy_config_service_linux.h"
 #endif
 #include "net/proxy/proxy_resolver.h"
@@ -795,7 +795,7 @@ ProxyConfigService* ProxyService::Create
   NOTREACHED() << "ProxyConfigService for ChromeOS should be created in "
                << "chrome_url_request_context.cc::CreateProxyConfigService.";
   return NULL;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ProxyConfigServiceLinux* linux_config_service
       = new ProxyConfigServiceLinux();
 
