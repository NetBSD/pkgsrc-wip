$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/core/ir/transform/robustness.cc.orig	2024-10-18 12:38:01.301521300 +0000
+++ third_party/dawn/src/tint/lang/core/ir/transform/robustness.cc
@@ -316,7 +316,6 @@ struct State {
                 break;
             }
             case core::BuiltinFn::kTextureLoad: {
-                clamp_coords(1u);
                 uint32_t next_arg = 2u;
                 if (type::IsTextureArray(texture->dim())) {
                     clamp_array_index(next_arg++);
@@ -324,6 +323,7 @@ struct State {
                 if (texture->IsAnyOf<type::SampledTexture, type::DepthTexture>()) {
                     clamp_level(next_arg++);
                 }
+                clamp_coords(1u);  // Must run after clamp_level
                 break;
             }
             case core::BuiltinFn::kTextureStore: {
