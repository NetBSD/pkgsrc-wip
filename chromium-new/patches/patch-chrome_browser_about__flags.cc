$NetBSD$

--- chrome/browser/about_flags.cc.orig	2016-11-10 20:02:10.000000000 +0000
+++ chrome/browser/about_flags.cc
@@ -785,7 +785,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsLinux | kOsCrOS | kOsWin | kOsAndroid,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableSmoothScrolling,
                                switches::kDisableSmoothScrolling)},
-#if defined(USE_AURA) || defined(OS_LINUX)
+#if defined(USE_AURA) || defined(OS_LINUX) || defined(OS_BSD)
     {"overlay-scrollbars", IDS_FLAGS_OVERLAY_SCROLLBARS_NAME,
      IDS_FLAGS_OVERLAY_SCROLLBARS_DESCRIPTION,
      // Uses the system preference on Mac (a different implementation).
@@ -1823,7 +1823,7 @@ const FeatureEntry kFeatureEntries[] = {
      IDS_FLAGS_ENABLE_MATERIAL_DESIGN_EXTENSIONS_DESCRIPTION, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kMaterialDesignExtensions)},
 #endif
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", IDS_FLAGS_ENABLE_INPUT_IME_API_NAME,
      IDS_FLAGS_ENABLE_INPUT_IME_API_DESCRIPTION, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
