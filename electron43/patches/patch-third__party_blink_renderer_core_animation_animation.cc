$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/animation/animation.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/animation/animation.cc
@@ -1269,14 +1269,7 @@ void Animation::setEffect(AnimationEffec
   ResolveTimelineOffsets(timeline_ ? timeline_->GetTimelineRange()
                                    : TimelineRange());
 
-  SetOutdated();
-
-  // 7. Run the procedure to update an animation’s finished state for animation
-  //    with the did seek flag set to false (continuous), and the synchronously
-  //    notify flag set to false (async).
-  UpdateFinishedState(UpdateType::kContinuous, NotificationType::kAsync);
-
-  SetCompositorPending(CompositorPendingReason::kPendingEffectChange);
+  EffectInvalidated();
 
   // Notify of a potential state change.
   NotifyProbe();
@@ -2373,6 +2366,26 @@ void Animation::StartAnimationOnComposit
           timeline()->IsMonotonicallyIncreasing(), boundary_aligned);
 }
 
+Animation::NativePaintWorkletReasons Animation::GetNativePaintWorkletReasons() {
+  if (native_paint_worklet_reasons_) {
+    return native_paint_worklet_reasons_.value();
+  }
+  NativePaintWorkletReasons reasons = kNoPaintWorklet;
+  if (KeyframeEffect* keyframe_effect = DynamicTo<KeyframeEffect>(effect())) {
+    if (RuntimeEnabledFeatures::CompositeBGColorAnimationEnabled() &&
+        keyframe_effect->Affects(
+            PropertyHandle(GetCSSPropertyBackgroundColor()))) {
+      reasons |= kBackgroundColorPaintWorklet;
+    }
+    if (RuntimeEnabledFeatures::CompositeClipPathAnimationEnabled() &&
+        keyframe_effect->Affects(PropertyHandle(GetCSSPropertyClipPath()))) {
+      reasons |= kClipPathPaintWorklet;
+    }
+  }
+  native_paint_worklet_reasons_ = reasons;
+  return reasons;
+}
+
 // TODO(crbug.com/960944): Rename to SetPendingCommit. This method handles both
 // composited and non-composited animations. The use of 'compositor' in the name
 // is confusing.
@@ -2831,7 +2844,7 @@ bool Animation::Update(TimingUpdateReaso
     // After updating the animation time if the animation is no longer current
     // blink will no longer composite the element (see
     // CompositingReasonFinder::RequiresCompositingFor*Animation).
-    if (!content_->IsCurrent()) {
+    if (!content_->IsCurrent() && HasActiveAnimationsOnCompositor()) {
       SetCompositorPending(CompositorPendingReason::kPendingCancel);
     }
   }
@@ -2872,6 +2885,9 @@ void Animation::UpdateIfNecessary() {
 }
 
 void Animation::EffectInvalidated() {
+  prior_native_paint_worklet_reasons_ = native_paint_worklet_reasons_;
+  native_paint_worklet_reasons_ = std::nullopt;
+
   SetOutdated();
   UpdateFinishedState(UpdateType::kContinuous, NotificationType::kAsync);
   // FIXME: Needs to consider groups when added.
@@ -3379,15 +3395,22 @@ bool Animation::IsInDisplayLockedSubtree
 }
 
 void Animation::UpdateCompositedPaintStatus() {
-  if (!NativePaintImageGenerator::NativePaintWorkletAnimationsEnabled()) {
-    return;
+  if (GetNativePaintWorkletReasons() == Animation::kNoPaintWorklet) {
+    if (!prior_native_paint_worklet_reasons_ ||
+        prior_native_paint_worklet_reasons_ == Animation::kNoPaintWorklet) {
+      return;
+    }
   }
 
+  prior_native_paint_worklet_reasons_ = GetNativePaintWorkletReasons();
+
   KeyframeEffect* keyframe_effect = DynamicTo<KeyframeEffect>(content_.Get());
   if (!keyframe_effect) {
     return;
   }
 
+  // TODO(crbug.com/383562308): If the target changed since the last update, we
+  // need to trigger an update for the previous and current target.
   Element* target = keyframe_effect->EffectTarget();
   if (!target) {
     return;
@@ -3396,14 +3419,7 @@ void Animation::UpdateCompositedPaintSta
   ElementAnimations* element_animations = target->GetElementAnimations();
   DCHECK(element_animations);
 
-  if (RuntimeEnabledFeatures::CompositeBGColorAnimationEnabled()) {
-    element_animations->RecalcCompositedStatus(target,
-                                               GetCSSPropertyBackgroundColor());
-  }
-  if (RuntimeEnabledFeatures::CompositeClipPathAnimationEnabled()) {
-    element_animations->RecalcCompositedStatus(target,
-                                               GetCSSPropertyClipPath());
-  }
+  element_animations->RecalcCompositedStatus(target);
 }
 
 void Animation::Trace(Visitor* visitor) const {
