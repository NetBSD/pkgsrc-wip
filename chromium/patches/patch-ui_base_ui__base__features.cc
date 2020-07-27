$NetBSD$

--- ui/base/ui_base_features.cc.orig	2020-07-15 18:56:33.000000000 +0000
+++ ui/base/ui_base_features.cc
@@ -98,7 +98,7 @@ const base::Feature kCompositorThreadedS
 // native apps on Windows.
 const base::Feature kExperimentalFlingAnimation {
   "ExperimentalFlingAnimation",
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS))
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -130,7 +130,7 @@ const base::Feature kPrecisionTouchpadLo
     "PrecisionTouchpadLogging", base::FEATURE_DISABLED_BY_DEFAULT};
 #endif  // defined(OS_WIN)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 // Enables stylus appearing as touch when in contact with digitizer.
 const base::Feature kDirectManipulationStylus = {
     "DirectManipulationStylus",
@@ -179,7 +179,7 @@ bool IsCSSColorSchemeUARenderingEnabled(
 // Mac launch bug.
 const base::Feature kFormControlsRefresh = {"FormControlsRefresh",
 #if defined(OS_WIN) || defined(OS_CHROMEOS) || defined(OS_LINUX) || \
-    defined(OS_MACOSX)
+    defined(OS_MACOSX) || defined(OS_BSD)
                                             base::FEATURE_ENABLED_BY_DEFAULT
 #else
                                             base::FEATURE_DISABLED_BY_DEFAULT
