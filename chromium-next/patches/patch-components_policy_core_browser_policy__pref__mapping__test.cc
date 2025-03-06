$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -408,7 +408,7 @@ class PolicyTestCase {
     const std::string os("chromeos_ash");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
