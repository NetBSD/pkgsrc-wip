$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/service_worker/service_worker_registry.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/service_worker/service_worker_registry.cc
@@ -1076,7 +1076,8 @@ ServiceWorkerRegistry::GetOrCreateRegist
     if (data.policy_container_policies) {
       version->set_policy_container_host(
           base::MakeRefCounted<PolicyContainerHost>(
-              PolicyContainerPolicies(*data.policy_container_policies)));
+              PolicyContainerPolicies(*data.policy_container_policies,
+                                      /*is_web_secure_context=*/true)));
     }
     if (data.router_rules && version->IsStaticRouterEnabled()) {
       auto error = version->SetupRouterEvaluator(*data.router_rules);
