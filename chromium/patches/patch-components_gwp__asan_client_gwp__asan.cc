$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/gwp_asan/client/gwp_asan.cc.orig	2024-12-03 23:30:15.779391300 +0000
+++ components/gwp_asan/client/gwp_asan.cc
@@ -75,7 +75,7 @@ namespace {
 // ProcessSamplingBoost is the multiplier to increase the
 // ProcessSamplingProbability in scenarios where we want to perform additional
 // testing (e.g., on canary/dev builds).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr int kDefaultMaxAllocations = 50;
 constexpr int kDefaultMaxMetadata = 210;
 constexpr int kDefaultTotalPages = kCpuIs64Bit ? 2048 : kDefaultMaxMetadata * 2;
