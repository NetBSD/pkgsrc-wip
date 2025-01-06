$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/testing/internals.cc.orig	2024-10-18 12:34:35.720039000 +0000
+++ third_party/blink/renderer/core/testing/internals.cc
@@ -918,8 +918,8 @@ bool Internals::isLoading(const String& 
   if (!document_)
     return false;
   const KURL full_url = document_->CompleteURL(url);
-  const String cache_identifier =
-      document_->Fetcher()->GetCacheIdentifier(full_url);
+  const String cache_identifier = document_->Fetcher()->GetCacheIdentifier(
+      full_url, /*skip_service_worker=*/false);
   Resource* resource =
       MemoryCache::Get()->ResourceForURL(full_url, cache_identifier);
   // We check loader() here instead of isLoading(), because a multipart
@@ -931,8 +931,8 @@ bool Internals::isLoadingFromMemoryCache
   if (!document_)
     return false;
   const KURL full_url = document_->CompleteURL(url);
-  const String cache_identifier =
-      document_->Fetcher()->GetCacheIdentifier(full_url);
+  const String cache_identifier = document_->Fetcher()->GetCacheIdentifier(
+      full_url, /*skip_service_worker=*/false);
   Resource* resource =
       MemoryCache::Get()->ResourceForURL(full_url, cache_identifier);
   return resource && resource->GetStatus() == ResourceStatus::kCached;
