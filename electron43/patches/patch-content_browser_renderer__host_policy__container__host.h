$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/policy_container_host.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/policy_container_host.h
@@ -49,7 +49,8 @@ struct CONTENT_EXPORT PolicyContainerPol
       bool allow_cross_origin_isolation);
 
   explicit PolicyContainerPolicies(
-      const blink::mojom::PolicyContainerPolicies& policies);
+      const blink::mojom::PolicyContainerPolicies& policies,
+      bool is_web_secure_context);
 
   // Used when loading workers from network schemes.
   // WARNING: This does not populate referrer policy.
