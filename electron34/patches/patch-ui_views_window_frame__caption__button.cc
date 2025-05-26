$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/window/frame_caption_button.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/window/frame_caption_button.cc
@@ -107,7 +107,7 @@ FrameCaptionButton::FrameCaptionButton(P
 FrameCaptionButton::~FrameCaptionButton() = default;
 
 // static
-SkColor FrameCaptionButton::GetButtonColor(SkColor background_color) {
+SkColor FrameCaptionButton::GetAccessibleButtonColor(SkColor background_color) {
   // Use IsDark() to change target colors instead of PickContrastingColor(), so
   // that DefaultFrameHeader::GetTitleColor() (which uses different target
   // colors) can change between light/dark targets at the same time.  It looks
@@ -124,6 +124,22 @@ SkColor FrameCaptionButton::GetButtonCol
       .color;
 }
 
+SkColor FrameCaptionButton::GetButtonColor(SkColor background_color) {
+  // If the button color has been overridden, return that.
+  if (button_color_ != SkColor())
+    return button_color_;
+
+  return GetAccessibleButtonColor(background_color);
+}
+
+void FrameCaptionButton::SetButtonColor(SkColor button_color) {
+  if (button_color_ == button_color)
+    return;
+
+  button_color_ = button_color;
+  MaybeRefreshIconAndInkdropBaseColor();
+}
+
 // static
 float FrameCaptionButton::GetInactiveButtonColorAlphaRatio() {
   return 0.38f;
