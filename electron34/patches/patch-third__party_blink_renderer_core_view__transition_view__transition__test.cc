$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/view_transition/view_transition_test.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/view_transition/view_transition_test.cc
@@ -22,6 +22,7 @@
 #include "third_party/blink/renderer/core/dom/dom_token_list.h"
 #include "third_party/blink/renderer/core/dom/element.h"
 #include "third_party/blink/renderer/core/dom/node_computed_style.h"
+#include "third_party/blink/renderer/core/dom/layout_tree_builder_traversal.h"
 #include "third_party/blink/renderer/core/dom/pseudo_element.h"
 #include "third_party/blink/renderer/core/frame/frame_test_helpers.h"
 #include "third_party/blink/renderer/core/html/html_element.h"
@@ -32,7 +33,6 @@
 #include "third_party/blink/renderer/core/layout/physical_box_fragment.h"
 #include "third_party/blink/renderer/core/navigation_api/navigation_api.h"
 #include "third_party/blink/renderer/core/navigation_api/navigation_history_entry.h"
-#include "third_party/blink/renderer/core/paint/paint_and_raster_invalidation_test.h"
 #include "third_party/blink/renderer/core/paint/paint_layer.h"
 #include "third_party/blink/renderer/core/style/computed_style_constants.h"
 #include "third_party/blink/renderer/core/testing/core_unit_test_helper.h"
@@ -706,100 +706,6 @@ TEST_P(ViewTransitionTest, ViewTransitio
   UpdateAllLifecyclePhasesAndFinishDirectives();
 }
 
-namespace {
-void AssertOnlyViewTransitionElementsInvalidated(
-    PaintArtifactCompositor* compositor) {
-  const char kViewTransition[] = "view-transition";
-  const char kLayoutViewTransition[] = "ViewTransition";
-  compositor->ForAllContentLayersForTesting(
-      [&](ContentLayerClientImpl* client) {
-        if (::testing::Matcher<std::string>(
-                ::testing::ContainsRegex(kViewTransition))
-                .Matches(client->Layer().DebugName())) {
-          return;
-        }
-        if (::testing::Matcher<std::string>(
-                ::testing::ContainsRegex(kLayoutViewTransition))
-                .Matches(client->Layer().DebugName())) {
-          return;
-        }
-        auto* tracking = client->GetRasterInvalidator().GetTracking();
-        EXPECT_FALSE(tracking->HasInvalidations())
-            << client->Layer().DebugName();
-        for (const auto& invalidation : tracking->Invalidations()) {
-          LOG(ERROR) << "Invalidation " << invalidation;
-        }
-      });
-}
-}  // namespace
-
-TEST_P(ViewTransitionTest, NoInvalidationOnRoot) {
-  SetHtmlInnerHTML(R"HTML(
-    <style>
-      /* TODO(crbug.com/1336462): html.css is parsed before runtime flags are enabled */
-      html { view-transition-name: root; backgrond: grey; }
-      #element {
-        width: 100px;
-        height: 100px;
-        view-transition-name: shared;
-        will-change: transform;
-      }
-    </style>
-
-    <div id=element></div>
-    <div>test</div>
-  )HTML");
-
-  // Run all lifecycle phases to ensure paint is clean.
-  UpdateAllLifecyclePhasesForTest();
-
-  GetDocument().View()->SetTracksRasterInvalidations(true);
-
-  ScriptState* script_state = GetScriptState();
-  ScriptState::Scope scope(script_state);
-
-  auto start_setup_lambda =
-      [](const v8::FunctionCallbackInfo<v8::Value>& info) {};
-
-  // This callback sets the elements for the start phase of the transition.
-  auto start_setup_callback =
-      v8::Function::New(script_state->GetContext(), start_setup_lambda, {})
-          .ToLocalChecked();
-
-  auto* compositor = GetLocalFrameView()->GetPaintArtifactCompositor();
-  auto* transition = ViewTransitionSupplement::startViewTransition(
-      script_state, GetDocument(),
-      V8ViewTransitionCallback::Create(start_setup_callback),
-      ASSERT_NO_EXCEPTION);
-
-  UpdateAllLifecyclePhasesForTest();
-  {
-    SCOPED_TRACE("old dom capture");
-    AssertOnlyViewTransitionElementsInvalidated(compositor);
-  }
-
-  // Finish the prepare phase, mutate the DOM and start the animation.
-  UpdateAllLifecyclePhasesAndFinishDirectives();
-  test::RunPendingTasks();
-  EXPECT_EQ(GetState(transition), State::kAnimating);
-
-  // The start phase should generate pseudo elements for rendering new live
-  // content.
-  UpdateAllLifecyclePhasesAndFinishDirectives();
-  {
-    SCOPED_TRACE("animation started");
-    AssertOnlyViewTransitionElementsInvalidated(compositor);
-  }
-
-  // Finish the animations which should remove the pseudo element tree.
-  FinishTransition();
-  UpdateAllLifecyclePhasesAndFinishDirectives();
-  {
-    SCOPED_TRACE("transition finished");
-    AssertOnlyViewTransitionElementsInvalidated(compositor);
-  }
-}
-
 TEST_P(ViewTransitionTest, InspectorStyleResolver) {
   SetHtmlInnerHTML(R"HTML(
     <style>
