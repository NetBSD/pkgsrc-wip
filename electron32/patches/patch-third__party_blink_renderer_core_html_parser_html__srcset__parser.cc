$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/html/parser/html_srcset_parser.cc.orig	2024-10-18 12:34:35.468154700 +0000
+++ third_party/blink/renderer/core/html/parser/html_srcset_parser.cc
@@ -418,7 +418,9 @@ static unsigned AvoidDownloadIfHigherDen
     KURL url = document->CompleteURL(
         StripLeadingAndTrailingHTMLSpaces(image_candidates[i]->Url()));
     auto* resource = MemoryCache::Get()->ResourceForURL(
-        url, document->Fetcher()->GetCacheIdentifier(url));
+        url,
+        document->Fetcher()->GetCacheIdentifier(url,
+                                                /*skip_service_worker=*/false));
     if ((resource && resource->IsLoaded()) || url.ProtocolIsData()) {
       return i;
     }
