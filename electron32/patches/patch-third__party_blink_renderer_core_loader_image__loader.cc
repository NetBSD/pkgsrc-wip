$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/loader/image_loader.cc.orig	2024-10-18 12:34:35.544119800 +0000
+++ third_party/blink/renderer/core/loader/image_loader.cc
@@ -710,7 +710,8 @@ bool ImageLoader::ShouldLoadImmediately(
   // content when style recalc is over and DOM mutation is allowed again.
   if (!url.IsNull()) {
     Resource* resource = MemoryCache::Get()->ResourceForURL(
-        url, element_->GetDocument().Fetcher()->GetCacheIdentifier(url));
+        url, element_->GetDocument().Fetcher()->GetCacheIdentifier(
+                 url, /*skip_service_worker=*/false));
 
     if (resource && !resource->ErrorOccurred() &&
         CanReuseFromListOfAvailableImages(
