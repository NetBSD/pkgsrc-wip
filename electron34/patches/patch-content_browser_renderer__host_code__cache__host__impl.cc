$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/code_cache_host_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/code_cache_host_impl.cc
@@ -6,6 +6,7 @@
 
 #include <utility>
 
+#include "base/containers/contains.h"
 #include "base/functional/bind.h"
 #include "base/functional/callback_helpers.h"
 #include "base/metrics/histogram_functions.h"
@@ -29,6 +30,7 @@
 #include "third_party/blink/public/common/scheme_registry.h"
 #include "url/gurl.h"
 #include "url/origin.h"
+#include "url/url_util.h"
 
 using blink::mojom::CacheStorageError;
 
@@ -36,6 +38,11 @@ namespace content {
 
 namespace {
 
+bool ProcessLockURLIsCodeCacheScheme(const ProcessLock& process_lock) {
+  return base::Contains(url::GetCodeCacheSchemes(),
+                        process_lock.lock_url().scheme());
+}
+
 bool CheckSecurityForAccessingCodeCacheData(
     const GURL& resource_url,
     int render_process_id,
@@ -46,39 +53,57 @@ bool CheckSecurityForAccessingCodeCacheD
 
   // Code caching is only allowed for http(s) and chrome/chrome-untrusted
   // scripts. Furthermore, there is no way for http(s) pages to load chrome or
+  // Code caching is only allowed for scripts from:
+  // 1. http: and https: schemes.
+  // 2. chrome: and chrome-untrusted: schemes.
+  // 3. Schemes registered by content/ embedder via url::AddCodeCacheScheme.
+  //
+  // Furthermore, we know there are no way for http(s) pages to load chrome or
   // chrome-untrusted scripts, so any http(s) page attempting to store data
   // about a chrome or chrome-untrusted script would be an indication of
   // suspicious activity.
-  if (resource_url.SchemeIs(content::kChromeUIScheme) ||
-      resource_url.SchemeIs(content::kChromeUIUntrustedScheme)) {
-    if (!process_lock.is_locked_to_site()) {
-      // We can't tell for certain whether this renderer is doing something
-      // malicious, but we don't trust it enough to store data.
-      return false;
-    }
+  if (resource_url.SchemeIsHTTPOrHTTPS()) {
     if (process_lock.matches_scheme(url::kHttpScheme) ||
         process_lock.matches_scheme(url::kHttpsScheme)) {
-      if (operation == CodeCacheHostImpl::Operation::kWrite) {
+      return true;
+    }
+    // Pages in custom schemes like isolated-app: are allowed to load http(s)
+    // resources.
+    if (ProcessLockURLIsCodeCacheScheme(process_lock)) {
+      return true;
+    }
+    // It is possible for WebUI pages to include open-web content, but such
+    // usage is rare and we've decided that reasoning about security is easier
+    // if the WebUI code cache includes only WebUI scripts.
+    return false;
+  }
+
+  if (resource_url.SchemeIs(kChromeUIScheme) ||
+      resource_url.SchemeIs(kChromeUIUntrustedScheme)) {
+    if (process_lock.matches_scheme(kChromeUIScheme) ||
+        process_lock.matches_scheme(kChromeUIUntrustedScheme)) {
+      return true;
+    }
+    if (operation == CodeCacheHostImpl::Operation::kWrite) {
+      if (process_lock.matches_scheme(url::kHttpScheme) ||
+          process_lock.matches_scheme(url::kHttpsScheme)) {
         mojo::ReportBadMessage("HTTP(S) pages cannot cache WebUI code");
       }
+      if (ProcessLockURLIsCodeCacheScheme(process_lock)) {
+        mojo::ReportBadMessage(
+            "Page whose scheme are allowed by content/ embedders cannot cache "
+            "WebUI code. Did the embedder misconfigured content/?");
+      }
       return false;
     }
     // Other schemes which might successfully load chrome or chrome-untrusted
     // scripts, such as the PDF viewer, are unsupported but not considered
-    // dangerous.
-    return process_lock.matches_scheme(content::kChromeUIScheme) ||
-           process_lock.matches_scheme(content::kChromeUIUntrustedScheme);
-  }
-  if (resource_url.SchemeIsHTTPOrHTTPS() ||
-      blink::CommonSchemeRegistry::IsExtensionScheme(resource_url.scheme())) {
-    if (process_lock.matches_scheme(content::kChromeUIScheme) ||
-        process_lock.matches_scheme(content::kChromeUIUntrustedScheme)) {
-      // It is possible for WebUI pages to include open-web content, but such
-      // usage is rare and we've decided that reasoning about security is easier
-      // if the WebUI code cache includes only WebUI scripts.
-      return false;
-    }
-    return true;
+    // dangerous.  Similarly, the process might not be locked to a site.
+    return false;
+  }
+
+  if (base::Contains(url::GetCodeCacheSchemes(), resource_url.scheme())) {
+    return ProcessLockURLIsCodeCacheScheme(process_lock);
   }
 
   if (operation == CodeCacheHostImpl::Operation::kWrite) {
@@ -433,6 +458,7 @@ std::optional<GURL> CodeCacheHostImpl::G
       process_lock.matches_scheme(url::kHttpsScheme) ||
       process_lock.matches_scheme(content::kChromeUIScheme) ||
       process_lock.matches_scheme(content::kChromeUIUntrustedScheme) ||
+      ProcessLockURLIsCodeCacheScheme(process_lock) ||
       blink::CommonSchemeRegistry::IsExtensionScheme(
           process_lock.lock_url().scheme())) {
     return process_lock.lock_url();
