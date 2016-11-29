$NetBSD$

--- net/proxy/proxy_service.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/proxy/proxy_service.cc
@@ -47,7 +47,7 @@
 #elif defined(OS_MACOSX)
 #include "net/proxy/proxy_config_service_mac.h"
 #include "net/proxy/proxy_resolver_mac.h"
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD) || defined(OS_NETBSD)
 #include "net/proxy/proxy_config_service_linux.h"
 #elif defined(OS_ANDROID)
 #include "net/proxy/proxy_config_service_android.h"
@@ -1531,7 +1531,7 @@ ProxyService::CreateSystemProxyConfigSer
              << "profile_io_data.cc::CreateProxyConfigService and this should "
              << "be used only for examples.";
   return base::WrapUnique(new UnsetProxyConfigService);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   std::unique_ptr<ProxyConfigServiceLinux> linux_config_service(
       new ProxyConfigServiceLinux());
 
