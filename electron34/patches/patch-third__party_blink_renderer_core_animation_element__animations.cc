$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/animation/element_animations.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/animation/element_animations.cc
@@ -97,43 +97,59 @@ void ElementAnimations::RecalcComposited
     Element& element,
     AnimationEffect* effect) {
   if (KeyframeEffect* keyframe_effect = DynamicTo<KeyframeEffect>(effect)) {
-    if (CompositedBackgroundColorStatus() ==
-            ElementAnimations::CompositedPaintStatus::kComposited &&
-        keyframe_effect->Affects(
-            PropertyHandle(GetCSSPropertyBackgroundColor())) &&
-        element.GetLayoutObject()) {
-      SetCompositedBackgroundColorStatus(
-          ElementAnimations::CompositedPaintStatus::kNeedsRepaint);
-      element.GetLayoutObject()->SetShouldDoFullPaintInvalidation();
-    }
-
-    if (CompositedClipPathStatus() ==
-            ElementAnimations::CompositedPaintStatus::kComposited &&
-        keyframe_effect->Affects(PropertyHandle(GetCSSPropertyClipPath())) &&
-        element.GetLayoutObject()) {
-      SetCompositedClipPathStatus(
-          ElementAnimations::CompositedPaintStatus::kNeedsRepaint);
-      element.GetLayoutObject()->SetShouldDoFullPaintInvalidation();
-      // For clip paths, we also need to update the paint properties to switch
-      // from path based to mask based clip.
-      element.GetLayoutObject()->SetNeedsPaintPropertyUpdate();
+    if (RuntimeEnabledFeatures::CompositeBGColorAnimationEnabled()) {
+      if (CompositedBackgroundColorStatus() ==
+              ElementAnimations::CompositedPaintStatus::kComposited &&
+          keyframe_effect->Affects(
+              PropertyHandle(GetCSSPropertyBackgroundColor())) &&
+          element.GetLayoutObject()) {
+        SetCompositedBackgroundColorStatus(
+            ElementAnimations::CompositedPaintStatus::kNeedsRepaint);
+        element.GetLayoutObject()->SetShouldDoFullPaintInvalidation();
+      }
+    }
+
+    if (RuntimeEnabledFeatures::CompositeClipPathAnimationEnabled()) {
+      if (CompositedClipPathStatus() ==
+              ElementAnimations::CompositedPaintStatus::kComposited &&
+          keyframe_effect->Affects(PropertyHandle(GetCSSPropertyClipPath())) &&
+          element.GetLayoutObject()) {
+        SetCompositedClipPathStatus(
+            ElementAnimations::CompositedPaintStatus::kNeedsRepaint);
+        element.GetLayoutObject()->SetShouldDoFullPaintInvalidation();
+        // For clip paths, we also need to update the paint properties to switch
+        // from path based to mask based clip.
+        element.GetLayoutObject()->SetNeedsPaintPropertyUpdate();
+      }
     }
   }
 }
 
-void ElementAnimations::RecalcCompositedStatus(Element* element,
-                                               const CSSProperty& property) {
-  ElementAnimations::CompositedPaintStatus status =
-      HasAnimationForProperty(property)
-          ? ElementAnimations::CompositedPaintStatus::kNeedsRepaint
-          : ElementAnimations::CompositedPaintStatus::kNoAnimation;
+void ElementAnimations::RecalcCompositedStatus(Element* element) {
+  Animation::NativePaintWorkletReasons reasons = Animation::kNoPaintWorklet;
+  for (auto& entry : Animations()) {
+    if (entry.key->CalculateAnimationPlayState() ==
+        V8AnimationPlayState::Enum::kIdle) {
+      continue;
+    }
+    reasons |= entry.key->GetNativePaintWorkletReasons();
+  }
 
-  if (property.PropertyID() == CSSPropertyID::kBackgroundColor) {
+  if (RuntimeEnabledFeatures::CompositeBGColorAnimationEnabled()) {
+    ElementAnimations::CompositedPaintStatus status =
+        reasons & Animation::kBackgroundColorPaintWorklet
+            ? ElementAnimations::CompositedPaintStatus::kNeedsRepaint
+            : ElementAnimations::CompositedPaintStatus::kNoAnimation;
     if (SetCompositedBackgroundColorStatus(status) &&
         element->GetLayoutObject()) {
       element->GetLayoutObject()->SetShouldDoFullPaintInvalidation();
     }
-  } else if (property.PropertyID() == CSSPropertyID::kClipPath) {
+  }
+  if (RuntimeEnabledFeatures::CompositeClipPathAnimationEnabled()) {
+    ElementAnimations::CompositedPaintStatus status =
+        reasons & Animation::kClipPathPaintWorklet
+            ? ElementAnimations::CompositedPaintStatus::kNeedsRepaint
+            : ElementAnimations::CompositedPaintStatus::kNoAnimation;
     if (SetCompositedClipPathStatus(status) && element->GetLayoutObject()) {
       element->GetLayoutObject()->SetShouldDoFullPaintInvalidation();
       // For clip paths, we also need to update the paint properties to switch
