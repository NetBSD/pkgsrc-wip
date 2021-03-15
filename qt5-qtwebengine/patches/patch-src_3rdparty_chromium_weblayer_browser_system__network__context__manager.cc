$NetBSD$

--- src/3rdparty/chromium/weblayer/browser/system_network_context_manager.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/weblayer/browser/system_network_context_manager.cc
@@ -52,7 +52,7 @@ SystemNetworkContextManager::CreateDefau
   network::mojom::NetworkContextParamsPtr network_context_params =
       network::mojom::NetworkContextParams::New();
   network_context_params->user_agent = user_agent;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // We're not configuring the cookie encryption on these platforms yet.
   network_context_params->enable_encrypted_cookies = false;
 #endif
