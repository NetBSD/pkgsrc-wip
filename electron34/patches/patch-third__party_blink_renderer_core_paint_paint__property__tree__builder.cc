$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/paint/paint_property_tree_builder.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/paint/paint_property_tree_builder.cc
@@ -1834,32 +1834,25 @@ void FragmentPaintPropertyTreeBuilder::U
         properties_->ViewTransitionEffect()
             ->SelfOrAncestorParticipatesInViewTransition();
 
-    const bool is_view_transition_element =
+    const bool needs_view_transition_effect =
         full_context_.direct_compositing_reasons &
         CompositingReason::kViewTransitionElement;
 
-    const bool needs_view_transition_effect =
-        is_view_transition_element ||
-        (object_.IsLayoutView() && !IsInLocalSubframe(object_) &&
-         !object_.GetDocument().IsSVGDocument());
-
     if (needs_view_transition_effect) {
       auto* transition =
           ViewTransitionUtils::GetTransition(object_.GetDocument());
-      DCHECK(!is_view_transition_element || transition);
+      DCHECK(transition);
 
       EffectPaintPropertyNode::State state;
+      state.direct_compositing_reasons =
+          CompositingReason::kViewTransitionElement;
       state.local_transform_space = context_.current.transform;
       state.output_clip = context_.current.clip;
       state.compositor_element_id = CompositorElementIdFromUniqueObjectId(
           object_.UniqueId(),
           CompositorElementIdNamespace::kViewTransitionElement);
-      if (is_view_transition_element) {
-        state.direct_compositing_reasons =
-            CompositingReason::kViewTransitionElement;
-        state.view_transition_element_resource_id =
-            transition->GetSnapshotId(object_);
-      }
+      state.view_transition_element_resource_id =
+          transition->GetSnapshotId(object_);
 
       // The value isn't set on the root, since clipping rules are different for
       // the root view transition element.
