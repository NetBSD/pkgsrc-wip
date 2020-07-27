$NetBSD$

--- components/feature_engagement/public/feature_list.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/feature_engagement/public/feature_list.cc
@@ -62,7 +62,7 @@ const base::Feature* const kAllFeatures[
     &kIPHBadgedTranslateManualTriggerFeature,
 #endif  // defined(OS_IOS)
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     &kIPHDesktopTabGroupsNewGroupFeature,
     &kIPHFocusModeFeature,
     &kIPHGlobalMediaControlsFeature,
