$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/common/policy_loader_common.cc.orig	2024-07-24 02:44:34.800603600 +0000
+++ components/policy/core/common/policy_loader_common.cc
@@ -46,7 +46,7 @@ const char* kSensitivePolicies[] = {
     key::kDefaultSearchProviderEnabled,
     key::kSafeBrowsingEnabled,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     key::kAutoOpenFileTypes,
     key::kHomepageIsNewTabPage,
     key::kPasswordProtectionChangePasswordURL,
@@ -56,7 +56,7 @@ const char* kSensitivePolicies[] = {
     key::kSafeBrowsingAllowlistDomains,
     key::kSiteSearchSettings,
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     key::kCommandLineFlagSecurityWarningsEnabled,
 #endif
 #if !BUILDFLAG(IS_IOS)
