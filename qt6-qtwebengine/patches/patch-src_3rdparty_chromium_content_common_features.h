$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/common/features.h.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/content/common/features.h
@@ -37,7 +37,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kDoc
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableBackForwardCacheForScreenReader);
 CONTENT_EXPORT BASE_DECLARE_FEATURE(
     kEnableBackForwardCacheForOngoingSubframeNavigation);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnableDevToolsJsErrorReporting);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kEnsureAllowBindingsIsAlwaysForWebUI);
@@ -58,7 +58,7 @@ CONTENT_EXPORT BASE_DECLARE_FEATURE(kFor
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGpuInfoCollectionSeparatePrefetch);
 #endif
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kGroupNIKByJoiningOrigin);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kHandleChildThreadTypeChangesInBrowser);
 #endif
 CONTENT_EXPORT BASE_DECLARE_FEATURE(kHighPriorityBeforeUnload);
