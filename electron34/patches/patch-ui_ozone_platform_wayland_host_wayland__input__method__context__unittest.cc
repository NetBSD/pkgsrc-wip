$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/ozone/platform/wayland/host/wayland_input_method_context_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_input_method_context_unittest.cc
@@ -1174,6 +1174,34 @@ TEST_P(WaylandInputMethodContextTest, Se
   });
 }
 
+TEST_P(WaylandInputMethodContextTest, OnPreeditChangedDefaultCompositionStyle) {
+  constexpr std::string_view kPreeditString("PreeditString");
+  constexpr gfx::Range kSelection{7, 13};
+  input_method_context_->OnPreeditString(
+      kPreeditString,
+      // No composition style provided.
+      {{1,
+        3,
+        {{ImeTextSpan::Type::kMisspellingSuggestion,
+          ImeTextSpan::Thickness::kNone}}}},
+      kSelection);
+  EXPECT_TRUE(input_method_context_delegate_->was_on_preedit_changed_called());
+  EXPECT_EQ(input_method_context_delegate_->last_preedit()->ime_text_spans,
+            (ImeTextSpans{ImeTextSpan(ImeTextSpan::Type::kMisspellingSuggestion,
+                                      1, 4, ImeTextSpan::Thickness::kNone),
+                          // Default composition should be applied.
+                          ImeTextSpan(ImeTextSpan::Type::kComposition, 0,
+                                      kPreeditString.size(),
+                                      ImeTextSpan::Thickness::kThin)}));
+  EXPECT_EQ(
+      input_method_context_->predicted_state_for_testing().surrounding_text,
+      u"PreeditString");
+  EXPECT_EQ(input_method_context_->predicted_state_for_testing().composition,
+            gfx::Range(0, kPreeditString.size()));
+  EXPECT_EQ(input_method_context_->predicted_state_for_testing().selection,
+            kSelection);
+}
+
 TEST_P(WaylandInputMethodContextTest, OnPreeditChanged) {
   constexpr std::string_view kPreeditString("PreeditString");
   constexpr gfx::Range kSelection{7, 13};
@@ -1181,13 +1209,19 @@ TEST_P(WaylandInputMethodContextTest, On
       kPreeditString,
       {{0,
         static_cast<uint32_t>(kPreeditString.size()),
-        {{ImeTextSpan::Type::kComposition, ImeTextSpan::Thickness::kThin}}}},
+        {{ImeTextSpan::Type::kComposition, ImeTextSpan::Thickness::kThick}}},
+       {1,
+        3,
+        {{ImeTextSpan::Type::kMisspellingSuggestion,
+          ImeTextSpan::Thickness::kNone}}}},
       kSelection);
   EXPECT_TRUE(input_method_context_delegate_->was_on_preedit_changed_called());
   EXPECT_EQ(input_method_context_delegate_->last_preedit()->ime_text_spans,
-            ImeTextSpans{ImeTextSpan(ImeTextSpan::Type::kComposition, 0,
-                                     kPreeditString.size(),
-                                     ImeTextSpan::Thickness::kThin)});
+            (ImeTextSpans{ImeTextSpan(ImeTextSpan::Type::kComposition, 0,
+                                      kPreeditString.size(),
+                                      ImeTextSpan::Thickness::kThick),
+                          ImeTextSpan(ImeTextSpan::Type::kMisspellingSuggestion,
+                                      1, 4, ImeTextSpan::Thickness::kNone)}));
   EXPECT_EQ(
       input_method_context_->predicted_state_for_testing().surrounding_text,
       u"PreeditString");
