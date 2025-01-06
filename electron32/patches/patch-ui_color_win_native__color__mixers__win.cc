$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/win/native_color_mixers_win.cc.orig	2024-10-18 12:35:12.444382000 +0000
+++ ui/color/win/native_color_mixers_win.cc
@@ -171,6 +171,10 @@ void AddNativeUiColorMixer(ColorProvider
       SetAlpha(kColorNotificationInputForeground, gfx::kGoogleGreyAlpha700);
   mixer[kColorSliderTrack] = AlphaBlend(
       kColorNativeHighlight, kColorNativeWindow, gfx::kGoogleGreyAlpha400);
+  mixer[kColorResultsTableHoveredBackground] = AlphaBlend(
+      kColorNativeHighlight, kColorNativeWindow, gfx::kGoogleGreyAlpha400);
+  mixer[kColorResultsTableDimmedText] = AlphaBlend(
+      kColorNativeWindowText, kColorNativeWindow, gfx::kGoogleGreyAlpha600);
 
   // Window Background
   mixer[kColorBubbleFooterBackground] = {kColorNativeWindow};
@@ -179,6 +183,7 @@ void AddNativeUiColorMixer(ColorProvider
   mixer[kColorFrameInactive] = {kColorNativeWindow};
   mixer[kColorPrimaryBackground] = {kColorNativeWindow};
   mixer[kColorTooltipBackground] = {kColorNativeWindow};
+  mixer[kColorResultsTableNormalBackground] = {kColorNativeWindow};
 
   // Window Text
   mixer[kColorAlertLowSeverity] = {kColorNativeWindowText};
@@ -192,6 +197,7 @@ void AddNativeUiColorMixer(ColorProvider
   mixer[kColorTableGroupingIndicator] = {kColorNativeWindowText};
   mixer[kColorThrobber] = {kColorNativeWindowText};
   mixer[kColorTooltipForeground] = {kColorNativeWindowText};
+  mixer[kColorResultsTableNormalText] = {kColorNativeWindowText};
 
   // Hyperlinks
   mixer[kColorLinkForegroundDefault] = {kColorNativeHotlight};
@@ -234,6 +240,7 @@ void AddNativeUiColorMixer(ColorProvider
   mixer[kColorTextfieldForeground] = {kColorNativeBtnText};
   mixer[kColorTextfieldForegroundPlaceholder] = {kColorNativeBtnText};
   mixer[kColorTextfieldForegroundDisabled] = {kColorNativeBtnText};
+  mixer[kColorUnfocusedBorder] = {kColorNativeBtnText};
 
   // Highlight/Selected Background
   mixer[kColorAccent] = {kColorNativeHighlight};
