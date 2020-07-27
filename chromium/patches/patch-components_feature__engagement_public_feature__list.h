$NetBSD$

--- components/feature_engagement/public/feature_list.h.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/feature_engagement/public/feature_list.h
@@ -116,7 +116,7 @@ DEFINE_VARIATION_PARAM(kIPHBadgedTransla
 #endif  // defined(OS_IOS)
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 DEFINE_VARIATION_PARAM(kIPHDesktopTabGroupsNewGroupFeature,
                        "IPH_DesktopTabGroupsNewGroup");
 DEFINE_VARIATION_PARAM(kIPHFocusModeFeature, "IPH_FocusMode");
@@ -184,7 +184,7 @@ constexpr flags_ui::FeatureEntry::Featur
         VARIATION_ENTRY(kIPHBadgedReadingListFeature),
         VARIATION_ENTRY(kIPHBadgedTranslateManualTriggerFeature),
 #elif defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
         VARIATION_ENTRY(kIPHDesktopTabGroupsNewGroupFeature),
         VARIATION_ENTRY(kIPHFocusModeFeature),
         VARIATION_ENTRY(kIPHGlobalMediaControls),
