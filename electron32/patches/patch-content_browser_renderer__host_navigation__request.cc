$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/navigation_request.cc.orig	2024-10-18 12:34:13.406903700 +0000
+++ content/browser/renderer_host/navigation_request.cc
@@ -10657,6 +10657,12 @@ NavigationRequest::GetOriginForURLLoader
     }
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
