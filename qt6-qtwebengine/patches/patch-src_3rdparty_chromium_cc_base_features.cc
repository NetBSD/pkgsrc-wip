$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/cc/base/features.cc.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/cc/base/features.cc
@@ -89,7 +89,7 @@ BASE_FEATURE(kNormalPriorityImageDecodin
 // Note that kUseDMSAAForTiles only controls vulkan launch on android. We will
 // be using a separate flag to control the launch on GL.
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseDMSAAForTiles,
              "UseDMSAAForTiles",
              base::FEATURE_ENABLED_BY_DEFAULT);
