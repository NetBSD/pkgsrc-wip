$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/net/core/proxy_policy_utils.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/enterprise/net/core/proxy_policy_utils.cc
@@ -17,7 +17,7 @@
 namespace enterprise_net {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 bool IsUnaffiliatedUserProxyPolicyAllowed(const policy::PolicyMap& policies) {
   const policy::PolicyMap::Entry* entry =
       policies.Get(policy::key::kEnableProxyOverrideRulesForAllUsers);
