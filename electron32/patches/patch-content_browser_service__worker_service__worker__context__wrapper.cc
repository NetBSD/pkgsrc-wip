$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/service_worker/service_worker_context_wrapper.cc.orig	2024-10-18 12:34:13.766717400 +0000
+++ content/browser/service_worker/service_worker_context_wrapper.cc
@@ -2024,6 +2024,26 @@ ServiceWorkerContextWrapper::GetLoaderFa
       loader_factory_bundle_info =
           context()->loader_factory_bundle_for_update_check()->Clone();
 
+  // Give the embedder a chance to register custom schemes that can
+  // handle loading the service worker main script.
+  // Previous registration triggered by
+  // ServiceWorkerContextWrapper::CreateNonNetworkPendingURLLoaderFactoryBundleForUpdateCheck
+  // happens early on browser startup before the JS in the main process
+  // is run by the embedder.
+  auto& pending_scheme_specific_factories =
+      static_cast<blink::PendingURLLoaderFactoryBundle*>(
+      loader_factory_bundle_info.get())
+      ->pending_scheme_specific_factories();
+  ContentBrowserClient::NonNetworkURLLoaderFactoryMap non_network_factories;
+  GetContentClient()
+      ->browser()
+      ->RegisterNonNetworkServiceWorkerUpdateURLLoaderFactories(
+          storage_partition_->browser_context(), &non_network_factories);
+  for (auto& [scheme, factory_remote] : non_network_factories) {
+    pending_scheme_specific_factories.emplace(
+        scheme, std::move(factory_remote));
+  }
+
   if (auto* config = content::WebUIConfigMap::GetInstance().GetConfig(
           browser_context(), scope)) {
     // If this is a Service Worker for a WebUI, the WebUI's URLDataSource
@@ -2043,9 +2063,7 @@ ServiceWorkerContextWrapper::GetLoaderFa
             features::kEnableServiceWorkersForChromeScheme) &&
         scope.scheme_piece() == kChromeUIScheme) {
       config->RegisterURLDataSource(browser_context());
-      static_cast<blink::PendingURLLoaderFactoryBundle*>(
-          loader_factory_bundle_info.get())
-          ->pending_scheme_specific_factories()
+      pending_scheme_specific_factories
           .emplace(kChromeUIScheme, CreateWebUIServiceWorkerLoaderFactory(
                                         browser_context(), kChromeUIScheme,
                                         base::flat_set<std::string>()));
@@ -2053,9 +2071,7 @@ ServiceWorkerContextWrapper::GetLoaderFa
                    features::kEnableServiceWorkersForChromeUntrusted) &&
                scope.scheme_piece() == kChromeUIUntrustedScheme) {
       config->RegisterURLDataSource(browser_context());
-      static_cast<blink::PendingURLLoaderFactoryBundle*>(
-          loader_factory_bundle_info.get())
-          ->pending_scheme_specific_factories()
+      pending_scheme_specific_factories
           .emplace(kChromeUIUntrustedScheme,
                    CreateWebUIServiceWorkerLoaderFactory(
                        browser_context(), kChromeUIUntrustedScheme,
