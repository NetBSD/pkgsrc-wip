$NetBSD$

--- components/feature_engagement/public/feature_constants.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ components/feature_engagement/public/feature_constants.cc
@@ -15,7 +15,7 @@ const base::Feature kIPHDummyFeature{"IP
                                      base::FEATURE_DISABLED_BY_DEFAULT};
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 const base::Feature kIPHDesktopTabGroupsNewGroupFeature{
     "IPH_DesktopTabGroupsNewGroup", base::FEATURE_DISABLED_BY_DEFAULT};
 const base::Feature kIPHFocusModeFeature{"IPH_FocusMode",
