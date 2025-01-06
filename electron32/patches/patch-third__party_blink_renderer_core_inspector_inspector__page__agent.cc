$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/inspector/inspector_page_agent.cc.orig	2024-10-18 12:34:35.488145600 +0000
+++ third_party/blink/renderer/core/inspector/inspector_page_agent.cc
@@ -176,7 +176,8 @@ Resource* CachedResource(LocalFrame* fra
   Resource* cached_resource = document->Fetcher()->CachedResource(url);
   if (!cached_resource) {
     cached_resource = MemoryCache::Get()->ResourceForURL(
-        url, document->Fetcher()->GetCacheIdentifier(url));
+        url, document->Fetcher()->GetCacheIdentifier(
+                 url, /*skip_service_worker=*/false));
   }
   if (!cached_resource)
     cached_resource = loader->ResourceForURL(url);
