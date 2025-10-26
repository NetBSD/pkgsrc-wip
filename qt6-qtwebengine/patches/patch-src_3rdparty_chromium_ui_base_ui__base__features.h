$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/ui_base_features.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ui_base_features.h
@@ -146,7 +146,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kWaylandTextInputV3);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kOverrideDefaultOzonePlatformHintToAuto);
 #endif  // BUILDFLAG(IS_LINUX)
