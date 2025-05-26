$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/code_cache/generated_code_cache.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/code_cache/generated_code_cache.cc
@@ -12,6 +12,7 @@
 #include <iostream>
 #include <string_view>
 
+#include "base/containers/contains.h"
 #include "base/feature_list.h"
 #include "base/functional/bind.h"
 #include "base/functional/callback_helpers.h"
@@ -36,6 +37,7 @@
 #include "net/http/http_cache.h"
 #include "third_party/blink/public/common/scheme_registry.h"
 #include "url/gurl.h"
+#include "url/url_util.h"
 
 using storage::BigIOBuffer;
 
@@ -48,7 +50,7 @@ constexpr char kSeparator[] = " \n";
 
 // We always expect to receive valid URLs that can be used as keys to the code
 // cache. The relevant checks (for ex: resource_url is valid, origin_lock is
-// not opque etc.,) must be done prior to requesting the code cache.
+// not opaque etc.,) must be done prior to requesting the code cache.
 //
 // This function doesn't enforce anything in the production code. It is here
 // to make the assumptions explicit and to catch any errors when DCHECKs are
@@ -58,33 +60,55 @@ void CheckValidKeys(const GURL& resource
                     GeneratedCodeCache::CodeCacheType cache_type) {
   // If the resource url is invalid don't cache the code.
   DCHECK(resource_url.is_valid());
-  bool resource_url_is_chrome_or_chrome_untrusted =
+
+  // There are 3 kind of URL scheme compatible for the `resource_url`.
+  // 1. http: and https: URLs.
+  // 2. chrome: and chrome-untrusted: URLs.
+  // 3. URLs whose scheme are allowed by the content/ embedder.
+  const bool resource_url_http = resource_url.SchemeIsHTTPOrHTTPS();
+  const bool resource_url_webui =
       resource_url.SchemeIs(content::kChromeUIScheme) ||
       resource_url.SchemeIs(content::kChromeUIUntrustedScheme);
-  DCHECK(resource_url.SchemeIsHTTPOrHTTPS() ||
-         resource_url_is_chrome_or_chrome_untrusted ||
-         blink::CommonSchemeRegistry::IsExtensionScheme(resource_url.scheme()));
-
-  // |origin_lock| should be either empty or should have
-  // Http/Https/chrome/chrome-untrusted schemes and it should not be a URL with
-  // opaque origin. Empty origin_locks are allowed when the renderer is not
-  // locked to an origin.
-  bool origin_lock_is_chrome_or_chrome_untrusted =
+
+  const bool resource_url_embedder =
+      base::Contains(url::GetCodeCacheSchemes(), resource_url.scheme());
+  DCHECK(resource_url_http || resource_url_webui || resource_url_embedder);
+
+  // |origin_lock| should be either empty or should have code cache allowed
+  // schemes (http/https/chrome/chrome-untrusted or other custom schemes added
+  // by url::AddCodeCacheScheme), and it should not be a URL with opaque
+  // origin. Empty origin_locks are allowed when the renderer is not locked to
+  // an origin.
+  const bool origin_lock_empty = origin_lock.is_empty();
+  const bool origin_lock_for_http = origin_lock.SchemeIsHTTPOrHTTPS();
+  const bool origin_lock_for_webui =
       origin_lock.SchemeIs(content::kChromeUIScheme) ||
       origin_lock.SchemeIs(content::kChromeUIUntrustedScheme);
-  DCHECK(
-      origin_lock.is_empty() ||
-      ((origin_lock.SchemeIsHTTPOrHTTPS() ||
-        origin_lock_is_chrome_or_chrome_untrusted ||
-        blink::CommonSchemeRegistry::IsExtensionScheme(origin_lock.scheme())) &&
-       !url::Origin::Create(origin_lock).opaque()));
-
-  // The chrome and chrome-untrusted schemes are only used with the WebUI
-  // code cache type.
-  DCHECK_EQ(origin_lock_is_chrome_or_chrome_untrusted,
-            cache_type == GeneratedCodeCache::kWebUIJavaScript);
-  DCHECK_EQ(resource_url_is_chrome_or_chrome_untrusted,
-            cache_type == GeneratedCodeCache::kWebUIJavaScript);
+  const bool origin_lock_for_embedder =
+      base::Contains(url::GetCodeCacheSchemes(), origin_lock.scheme());
+
+  DCHECK(origin_lock_empty || ((origin_lock_for_http || origin_lock_for_webui ||
+                                origin_lock_for_embedder) &&
+                               !url::Origin::Create(origin_lock).opaque()));
+
+  // The webui schemes are only used with their dedicated code cache type.
+  switch (cache_type) {
+    case GeneratedCodeCache::kJavaScript:
+    case GeneratedCodeCache::kWebAssembly:
+      DCHECK(!origin_lock_for_webui);
+      DCHECK(!resource_url_webui);
+      break;
+    case GeneratedCodeCache::kWebUIJavaScript:
+      DCHECK(origin_lock_for_webui);
+      DCHECK(resource_url_webui);
+      break;
+  }
+
+  // The custom schemes share the cache type with http(s).
+  if (origin_lock_for_embedder || resource_url_embedder) {
+    DCHECK(cache_type == GeneratedCodeCache::kJavaScript ||
+           cache_type == GeneratedCodeCache::kWebAssembly);
+  }
 }
 
 // Generates the cache key for the given |resource_url|, |origin_lock| and
