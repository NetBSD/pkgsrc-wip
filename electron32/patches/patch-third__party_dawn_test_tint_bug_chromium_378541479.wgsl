$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/test/tint/bug/chromium/378541479.wgsl.orig	2025-03-03 17:47:27.689210004 +0000
+++ third_party/dawn/test/tint/bug/chromium/378541479.wgsl
@@ -0,0 +1,10 @@
+// flags: --transform robustness
+
+@group(0) @binding(0) var<uniform> level : u32;
+@group(0) @binding(1) var<uniform> coords : vec2<u32>;
+@group(0) @binding(2) var tex: texture_depth_2d;
+
+@compute @workgroup_size(1)
+fn compute_main() {
+  var res: f32 = textureLoad(tex, coords, level);
+}
