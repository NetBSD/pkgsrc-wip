$NetBSD$

--- weblayer/browser/system_network_context_manager.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ weblayer/browser/system_network_context_manager.cc
@@ -64,7 +64,7 @@ void SystemNetworkContextManager::Config
     network::mojom::NetworkContextParams* network_context_params,
     const std::string& user_agent) {
   network_context_params->user_agent = user_agent;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // We're not configuring the cookie encryption on these platforms yet.
   network_context_params->enable_encrypted_cookies = false;
 #endif
