$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/policy_container_host.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/policy_container_host.cc
@@ -135,9 +135,11 @@ PolicyContainerPolicies::PolicyContainer
       allow_cross_origin_isolation(allow_cross_origin_isolation) {}
 
 PolicyContainerPolicies::PolicyContainerPolicies(
-    const blink::mojom::PolicyContainerPolicies& policies)
+    const blink::mojom::PolicyContainerPolicies& policies,
+    bool is_web_secure_context)
     : referrer_policy(policies.referrer_policy),
       ip_address_space(policies.ip_address_space),
+      is_web_secure_context(is_web_secure_context),
       content_security_policies(
           mojo::Clone(policies.content_security_policies)),
       cross_origin_embedder_policy(policies.cross_origin_embedder_policy),
