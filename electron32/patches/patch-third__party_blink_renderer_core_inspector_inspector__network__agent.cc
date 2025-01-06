$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/inspector/inspector_network_agent.cc.orig	2024-10-18 12:34:35.484147300 +0000
+++ third_party/blink/renderer/core/inspector/inspector_network_agent.cc
@@ -2440,7 +2440,8 @@ bool InspectorNetworkAgent::FetchResourc
   Resource* cached_resource = document->Fetcher()->CachedResource(url);
   if (!cached_resource) {
     cached_resource = MemoryCache::Get()->ResourceForURL(
-        url, document->Fetcher()->GetCacheIdentifier(url));
+        url, document->Fetcher()->GetCacheIdentifier(
+                 url, /*skip_service_worker=*/false));
   }
   if (cached_resource && InspectorPageAgent::CachedResourceContent(
                              cached_resource, content, base64_encoded)) {
