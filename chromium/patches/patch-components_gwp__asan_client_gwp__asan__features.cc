$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/gwp_asan/client/gwp_asan_features.cc.orig	2024-07-24 02:44:34.104536000 +0000
+++ components/gwp_asan/client/gwp_asan_features.cc
@@ -9,7 +9,7 @@
 namespace gwp_asan::internal {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) ||                                          \
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) ||                     \
     (BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS))
 constexpr base::FeatureState kDefaultEnabled = base::FEATURE_ENABLED_BY_DEFAULT;
 #else
