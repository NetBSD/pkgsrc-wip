$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/color/ui_color_mixer.cc.orig	2024-10-18 12:35:12.444382000 +0000
+++ ui/color/ui_color_mixer.cc
@@ -180,6 +180,17 @@ void AddUiColorMixer(ColorProvider* prov
   mixer[kColorProgressBarPaused] = {kColorDisabledForeground};
   mixer[kColorRadioButtonForegroundChecked] = {kColorButtonForeground};
   mixer[kColorRadioButtonForegroundUnchecked] = {kColorSecondaryForeground};
+  mixer[kColorResultsTableNormalBackground] = {SK_ColorWHITE};
+  mixer[kColorResultsTableHoveredBackground] =
+      SetAlpha(kColorResultsTableNormalText, 0x0D);
+  mixer[kColorResultsTableNormalText] = {SK_ColorBLACK};
+  mixer[kColorResultsTableDimmedText] = {SkColorSetRGB(0x64, 0x64, 0x64)};
+  if (dark_mode) {
+    mixer[kColorResultsTableNormalBackground] = {SkColorSetRGB(0x28, 0x28, 0x28)};
+    mixer[kColorResultsTableNormalText] = {SK_ColorWHITE};
+    mixer[kColorResultsTableDimmedText] =
+      SetAlpha(kColorResultsTableNormalText, 0x80);
+  }
   mixer[kColorSeparator] = {kColorMidground};
   mixer[kColorShadowBase] = {dark_mode ? SK_ColorBLACK : gfx::kGoogleGrey800};
   mixer[kColorShadowValueAmbientShadowElevationThree] =
@@ -291,6 +302,7 @@ void AddUiColorMixer(ColorProvider* prov
   mixer[kColorTreeNodeForegroundSelectedFocused] = {kColorTreeNodeForeground};
   mixer[kColorTreeNodeForegroundSelectedUnfocused] = {
       kColorTreeNodeForegroundSelectedFocused};
+  mixer[kColorUnfocusedBorder] = {kColorMidground};
   mixer[kColorWebNativeControlAccent] = {dark_mode
                                              ? SkColorSetRGB(0x99, 0xC8, 0xFF)
                                              : SkColorSetRGB(0x00, 0x75, 0xFF)};
