$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/policy/core/common/policy_loader_common.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/components/policy/core/common/policy_loader_common.cc
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
