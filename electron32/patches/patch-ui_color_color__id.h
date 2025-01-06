$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/color_id.h.orig	2024-10-18 12:35:12.440383700 +0000
+++ ui/color/color_id.h
@@ -405,6 +405,10 @@
   E_CPONLY(kColorRadioButtonForegroundUnchecked) \
   E_CPONLY(kColorRadioButtonForegroundDisabled) \
   E_CPONLY(kColorRadioButtonForegroundChecked) \
+  E_CPONLY(kColorResultsTableNormalBackground) \
+  E_CPONLY(kColorResultsTableHoveredBackground) \
+  E_CPONLY(kColorResultsTableNormalText) \
+  E_CPONLY(kColorResultsTableDimmedText) \
   E_CPONLY(kColorSegmentedButtonBorder) \
   E_CPONLY(kColorSegmentedButtonFocus) \
   E_CPONLY(kColorSegmentedButtonForegroundChecked) \
@@ -509,6 +513,7 @@
   E_CPONLY(kColorTreeNodeForeground) \
   E_CPONLY(kColorTreeNodeForegroundSelectedFocused) \
   E_CPONLY(kColorTreeNodeForegroundSelectedUnfocused) \
+  E_CPONLY(kColorUnfocusedBorder) \
   /* These colors are used to paint the controls defined in */ \
   /* ui::NativeThemeBase::ControlColorId. */ \
   E_CPONLY(kColorWebNativeControlAccent) \
@@ -621,7 +626,7 @@
   \
   E_CPONLY(kColorCrosSysPositive) \
   E_CPONLY(kColorCrosSysComplementVariant)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeButtonBorder)\
   E_CPONLY(kColorNativeHeaderButtonBorderActive) \
