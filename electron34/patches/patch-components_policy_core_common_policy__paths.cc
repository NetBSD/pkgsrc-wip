$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/policy/core/common/policy_paths.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/policy/core/common/policy_paths.cc
@@ -17,6 +17,10 @@ namespace policy {
 const char kPolicyPath[] = "/etc/opt/chrome/policies";
 #elif BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 const char kPolicyPath[] = "/etc/opt/chrome_for_testing/policies";
+#elif BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/chromium/policies";
+#elif BUILDFLAG(IS_NETBSD)
+const char kPolicyPath[] = "@PKG_SYSCONFBASE@/chromium/policies";
 #else
 const char kPolicyPath[] = "/etc/chromium/policies";
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
