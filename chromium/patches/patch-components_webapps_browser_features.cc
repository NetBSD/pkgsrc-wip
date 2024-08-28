$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webapps/browser/features.cc.orig	2024-08-21 22:46:17.793373800 +0000
+++ components/webapps/browser/features.cc
@@ -59,7 +59,7 @@ extern const base::FeatureParam<int> kBa
 BASE_FEATURE(kWebAppsEnableMLModelForPromotion,
              "WebAppsEnableMLModelForPromotion",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
