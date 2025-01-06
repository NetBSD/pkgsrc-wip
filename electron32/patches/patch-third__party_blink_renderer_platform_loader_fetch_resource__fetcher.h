$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/loader/fetch/resource_fetcher.h.orig	2024-10-18 12:34:36.915490900 +0000
+++ third_party/blink/renderer/platform/loader/fetch/resource_fetcher.h
@@ -278,7 +278,11 @@ class PLATFORM_EXPORT ResourceFetcher
                          uint32_t inflight_keepalive_bytes);
   blink::mojom::ControllerServiceWorkerMode IsControlledByServiceWorker() const;
 
-  String GetCacheIdentifier(const KURL& url) const;
+  // Returns a cache identifier for MemoryCache.
+  // `url` is used for finding a matching WebBundle.
+  // If `skip_service_worker` is true, the identifier won't be a ServiceWorker's
+  // identifier to keep the cache separated.
+  String GetCacheIdentifier(const KURL& url, bool skip_service_worker) const;
 
   // If `url` exists as a resource in a subresource bundle in this frame,
   // returns its UnguessableToken; otherwise, returns std::nullopt.
