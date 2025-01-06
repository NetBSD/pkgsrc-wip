$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/editing/ime/edit_context.cc.orig	2024-10-18 12:34:35.076335000 +0000
+++ third_party/blink/renderer/core/editing/ime/edit_context.cc
@@ -758,6 +758,9 @@ bool EditContext::GetCompositionCharacte
 bool EditContext::FirstRectForCharacterRange(uint32_t location,
                                              uint32_t length,
                                              gfx::Rect& rect_in_viewport) {
+  gfx::Rect rect_in_css_pixels;
+  bool found_rect = false;
+
   if (HasValidCompositionBounds()) {
     WebRange range = this->CompositionRange();
     CHECK_GE(range.StartOffset(), 0);
@@ -772,47 +775,52 @@ bool EditContext::FirstRectForCharacterR
       if (length == 0) {
         if (start_in_composition == character_bounds_.size()) {
           // Zero-width rect after the last character in the composition range
-          rect_in_viewport =
+          rect_in_css_pixels =
               gfx::Rect(character_bounds_[start_in_composition - 1].right(),
                         character_bounds_[start_in_composition - 1].y(), 0,
                         character_bounds_[start_in_composition - 1].height());
         } else {
           // Zero-width rect before the next character in the composition range
-          rect_in_viewport =
+          rect_in_css_pixels =
               gfx::Rect(character_bounds_[start_in_composition].x(),
                         character_bounds_[start_in_composition].y(), 0,
                         character_bounds_[start_in_composition].height());
         }
       } else {
-        gfx::Rect rect = character_bounds_[start_in_composition];
+        rect_in_css_pixels = character_bounds_[start_in_composition];
         for (size_t i = start_in_composition + 1; i < end_in_composition; ++i) {
-          rect.Union(character_bounds_[i]);
+          rect_in_css_pixels.Union(character_bounds_[i]);
         }
-
-        rect_in_viewport = rect;
       }
-      return true;
+      found_rect = true;
     }
   }
 
   // If we couldn't get a result from the composition bounds then we'll fall
   // back to using the selection bounds, since these will generally be close to
   // where the composition is happening.
-  if (!selection_bounds_.IsEmpty()) {
-    rect_in_viewport = selection_bounds_;
-    return true;
+  if (!found_rect && selection_bounds_ != gfx::Rect()) {
+    rect_in_css_pixels = selection_bounds_;
+    found_rect = true;
   }
 
   // If we have neither composition bounds nor selection bounds, we'll fall back
   // to using the control bounds. In this case the IME might not be drawn
   // exactly in the right spot, but will at least be adjacent to the editable
   // region rather than in the corner of the screen.
-  if (!control_bounds_.IsEmpty()) {
-    rect_in_viewport = control_bounds_;
-    return true;
+  if (!found_rect && control_bounds_ != gfx::Rect()) {
+    rect_in_css_pixels = control_bounds_;
+    found_rect = true;
+  }
+
+  if (found_rect) {
+    // EditContext's coordinates are in CSS pixels, which need to be converted
+    // to physical pixels before return.
+    rect_in_viewport = gfx::ScaleToEnclosingRect(
+        rect_in_css_pixels, DomWindow()->GetFrame()->DevicePixelRatio());
   }
 
-  return false;
+  return found_rect;
 }
 
 bool EditContext::HasValidCompositionBounds() const {
