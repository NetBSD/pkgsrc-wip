$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/common/content_client.h.orig	2024-10-18 12:34:14.458361100 +0000
+++ content/public/common/content_client.h
@@ -142,6 +142,9 @@ class CONTENT_EXPORT ContentClient {
     // Registers a URL scheme as strictly empty documents, allowing them to
     // commit synchronously.
     std::vector<std::string> empty_document_schemes;
+    // Registers a URL scheme whose js and wasm scripts have V8 code cache
+    // enabled.
+    std::vector<std::string> code_cache_schemes;
     // Registers a URL scheme as extension scheme.
     std::vector<std::string> extension_schemes;
     // Registers a URL scheme with a predefined default custom handler.
