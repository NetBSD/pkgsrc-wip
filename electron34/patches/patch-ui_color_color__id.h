$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/color_id.h.orig	2025-02-24 19:59:26.000000000 +0000
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
@@ -510,6 +514,7 @@
   E_CPONLY(kColorTreeNodeForeground) \
   E_CPONLY(kColorTreeNodeForegroundSelectedFocused) \
   E_CPONLY(kColorTreeNodeForegroundSelectedUnfocused) \
+  E_CPONLY(kColorUnfocusedBorder) \
   /* These colors are used to paint the controls defined in */ \
   /* ui::NativeThemeBase::ControlColorId. */ \
   E_CPONLY(kColorWebNativeControlAccent) \
@@ -618,7 +623,7 @@
   \
   E_CPONLY(kColorCrosSysPositive) \
   E_CPONLY(kColorCrosSysComplementVariant)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeButtonBorder)\
   E_CPONLY(kColorNativeHeaderButtonBorderActive) \
