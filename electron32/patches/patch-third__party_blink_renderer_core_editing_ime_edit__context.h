$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/editing/ime/edit_context.h.orig	2024-10-18 12:34:35.076335000 +0000
+++ third_party/blink/renderer/core/editing/ime/edit_context.h
@@ -139,6 +139,8 @@ class CORE_EXPORT EditContext final : pu
   WebTextInputInfo TextInputInfo() override;
   int ComputeWebTextInputNextPreviousFlags() override { return 0; }
   WebRange CompositionRange() const override;
+  // Populate `bounds` with the bounds of each item in EditContext's
+  // stored character bounds, scaled to physical pixels.
   bool GetCompositionCharacterBounds(WebVector<gfx::Rect>& bounds) override;
   WebRange GetSelectionOffsets() const override;
 
@@ -154,7 +156,7 @@ class CORE_EXPORT EditContext final : pu
   void Blur();
 
   // Populate |control_bounds| and |selection_bounds| with the bounds fetched
-  // from the active EditContext.
+  // from the active EditContext, in physical pixels.
   void GetLayoutBounds(gfx::Rect* control_bounds,
                        gfx::Rect* selection_bounds) override;
 
@@ -197,7 +199,7 @@ class CORE_EXPORT EditContext final : pu
                     int end,
                     bool dispatch_text_update_event = false);
 
-  // Sets rect_in_viewport to the surrounding rect, in CSS pixels,
+  // Sets rect_in_viewport to the surrounding rect, in physical pixels,
   // for the character range specified by `location` and `length`.
   // Returns true on success, false on failure (in which case
   // rect_in_viewport) is not changed.
@@ -285,6 +287,7 @@ class CORE_EXPORT EditContext final : pu
   uint32_t selection_start_ = 0;
   uint32_t selection_end_ = 0;
 
+  // The following bounds are in CSS pixels.
   gfx::Rect control_bounds_;
   gfx::Rect selection_bounds_;
   WebVector<gfx::Rect> character_bounds_;
