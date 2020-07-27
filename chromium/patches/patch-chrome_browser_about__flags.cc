$NetBSD$

--- chrome/browser/about_flags.cc.orig	2020-07-08 21:41:46.000000000 +0000
+++ chrome/browser/about_flags.cc
@@ -181,7 +181,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/native_theme/native_theme_features.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -837,7 +837,7 @@ const FeatureEntry::Choice kMemlogSampli
      heap_profiling::kMemlogSamplingRate5MB},
 };
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -2488,7 +2488,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCloudPrintXpsDescription, kOsWin,
      SINGLE_VALUE_TYPE(switches::kEnableCloudPrintXps)},
 #endif  // OS_WIN
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl2-compute-context",
      flag_descriptions::kWebGL2ComputeContextName,
      flag_descriptions::kWebGL2ComputeContextDescription,
@@ -2682,7 +2682,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableOfflinePreviewsDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(previews::features::kOfflinePreviews)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3426,7 +3426,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          omnibox::kHistoryQuickProviderAllowMidwordContinuations)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -3720,7 +3720,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
@@ -4408,7 +4408,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"remote-copy-receiver", flag_descriptions::kRemoteCopyReceiverName,
      flag_descriptions::kRemoteCopyReceiverDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kRemoteCopyReceiver)},
@@ -4451,7 +4451,7 @@ const FeatureEntry kFeatureEntries[] = {
          send_tab_to_self::kSendTabToSelfOmniboxSendingAnimation)},
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"sharing-peer-connection-receiver",
      flag_descriptions::kSharingPeerConnectionReceiverName,
      flag_descriptions::kSharingPeerConnectionReceiverDescription, kOsDesktop,
@@ -4537,7 +4537,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-reopen-tab-in-product-help",
      flag_descriptions::kReopenTabInProductHelpName,
      flag_descriptions::kReopenTabInProductHelpDescription, kOsDesktop,
@@ -5004,7 +5004,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableSyncTrustedVaultDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kSyncSupportTrustedVaultPassphrase)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
      kOsWin | kOsMac | kOsLinux,
