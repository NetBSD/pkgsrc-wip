$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/window/frame_caption_button.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/window/frame_caption_button.h
@@ -44,8 +44,18 @@ class VIEWS_EXPORT FrameCaptionButton : 
   FrameCaptionButton& operator=(const FrameCaptionButton&) = delete;
   ~FrameCaptionButton() override;
 
+  // Gets the color to use for a frame caption button with accessible contrast
+  // to the given background color.
+  static SkColor GetAccessibleButtonColor(SkColor background_color);
+
   // Gets the color to use for a frame caption button.
-  static SkColor GetButtonColor(SkColor background_color);
+  SkColor GetButtonColor(SkColor background_color);
+
+  // Sets the color to use for a frame caption button.
+  // The color is by default calculated to be an accessible contrast
+  // to the background color, so you should keep that in mind when
+  // overriding that behavior.
+  void SetButtonColor(SkColor button_color);
 
   // Gets the alpha ratio for the colors of inactive frame caption buttons.
   static float GetInactiveButtonColorAlphaRatio();
@@ -134,6 +144,7 @@ class VIEWS_EXPORT FrameCaptionButton : 
   // TODO(b/292154873): Store the foreground color instead of the background
   // color for the SkColor type.
   absl::variant<ui::ColorId, SkColor> color_ = gfx::kPlaceholderColor;
+  SkColor button_color_ = SkColor();
 
   // Whether the button should be painted as active.
   bool paint_as_active_ = false;
