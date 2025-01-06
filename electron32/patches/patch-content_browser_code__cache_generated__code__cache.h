$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/code_cache/generated_code_cache.h.orig	2024-10-18 12:34:12.259499800 +0000
+++ content/browser/code_cache/generated_code_cache.h
@@ -52,12 +52,14 @@ class CONTENT_EXPORT GeneratedCodeCache 
   // Cache type. Used for collecting statistics for JS and Wasm in separate
   // buckets.
   enum CodeCacheType {
-    // JavaScript from http(s) pages.
+    // JavaScript from pages of http(s) schemes or custom schemes registered by
+    // url::AddCodeCacheScheme.
     kJavaScript,
 
-    // WebAssembly from http(s) pages. This cache allows more total size and
-    // more size per item than the JavaScript cache, since some
-    // WebAssembly programs are very large.
+    // WebAssembly from pages of http(s) schemes or custom schemes registered by
+    // url::AddCodeCacheScheme. This cache allows more total size and more size
+    // per item than the JavaScript cache, since some WebAssembly programs are
+    // very large.
     kWebAssembly,
 
     // JavaScript from chrome and chrome-untrusted pages. The resource URLs are
