$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/loader/fetch/resource_fetcher.cc.orig	2024-10-18 12:34:36.915490900 +0000
+++ third_party/blink/renderer/platform/loader/fetch/resource_fetcher.cc
@@ -973,7 +973,8 @@ Resource* ResourceFetcher::CreateResourc
   if (!archive_ && factory.GetType() == ResourceType::kRaw)
     return nullptr;
 
-  const String cache_identifier = GetCacheIdentifier(url);
+  const String cache_identifier = GetCacheIdentifier(
+      url, params.GetResourceRequest().GetSkipServiceWorker());
   // Most off-main-thread resource fetches use Resource::kRaw and don't reach
   // this point, but off-main-thread module fetches might.
   if (IsMainThread()) {
@@ -1414,7 +1415,10 @@ Resource* ResourceFetcher::RequestResour
         resource = nullptr;
       } else {
         resource = MemoryCache::Get()->ResourceForURL(
-            params.Url(), GetCacheIdentifier(params.Url()));
+            params.Url(),
+          GetCacheIdentifier(
+              params.Url(),
+              params.GetResourceRequest().GetSkipServiceWorker()));
       }
       if (resource) {
         policy = DetermineRevalidationPolicy(resource_type, params, *resource,
@@ -1712,7 +1716,8 @@ Resource* ResourceFetcher::CreateResourc
     const FetchParameters& params,
     const ResourceFactory& factory) {
   const String cache_identifier =
-      GetCacheIdentifier(params.GetResourceRequest().Url());
+      GetCacheIdentifier(params.GetResourceRequest().Url(),
+                         params.GetResourceRequest().GetSkipServiceWorker());
   if (!base::FeatureList::IsEnabled(
           blink::features::kScopeMemoryCachePerContext)) {
     DCHECK(!IsMainThread() || params.IsStaleRevalidation() ||
@@ -2784,9 +2789,11 @@ void ResourceFetcher::UpdateAllImageReso
   to_be_removed.clear();
 }
 
-String ResourceFetcher::GetCacheIdentifier(const KURL& url) const {
-  if (properties_->GetControllerServiceWorkerMode() !=
-      mojom::ControllerServiceWorkerMode::kNoController) {
+String ResourceFetcher::GetCacheIdentifier(const KURL& url,
+                                           bool skip_service_worker) const {
+  if (!skip_service_worker &&
+      properties_->GetControllerServiceWorkerMode() !=
+          mojom::ControllerServiceWorkerMode::kNoController) {
     return String::Number(properties_->ServiceWorkerId());
   }
 
