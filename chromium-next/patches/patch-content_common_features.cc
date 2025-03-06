$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/features.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ content/common/features.cc
@@ -125,7 +125,7 @@ BASE_FEATURE(kEmbeddingRequiresOptIn,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              "EnableDevToolsJsErrorReporting",
              base::FEATURE_DISABLED_BY_DEFAULT);
