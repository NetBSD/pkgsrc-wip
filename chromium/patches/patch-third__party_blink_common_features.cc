$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/common/features.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ third_party/blink/common/features.cc
@@ -683,7 +683,7 @@ BASE_FEATURE(kDevToolsImprovedNetworkErr
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
              "DirectCompositorThreadIpc",
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
