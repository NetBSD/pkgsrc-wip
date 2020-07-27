$NetBSD$

--- components/feature_engagement/public/feature_constants.h.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/feature_engagement/public/feature_constants.h
@@ -18,7 +18,7 @@ extern const base::Feature kIPHDemoMode;
 extern const base::Feature kIPHDummyFeature;
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusModeFeature;
 extern const base::Feature kIPHGlobalMediaControlsFeature;
