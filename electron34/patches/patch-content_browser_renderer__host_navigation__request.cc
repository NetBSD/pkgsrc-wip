$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/navigation_request.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/navigation_request.cc
@@ -10806,6 +10806,12 @@ NavigationRequest::GetOriginForURLLoader
         "blob");
   }
 
+  if (!common_params().url.IsStandard()) {
+    return std::make_pair(url::Origin::Resolve(common_params().url,
+                                               url::Origin()),
+                          "url_non_standard");
+  }
+
   // In cases not covered above, URLLoaderFactory should be associated with the
   // origin of |common_params.url| and/or |common_params.initiator_origin|.
   url::Origin resolved_origin = url::Origin::Resolve(
