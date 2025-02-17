$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/test/tint/bug/chromium/378541479.wgsl.expected.fxc.hlsl.orig	2025-02-17 11:32:29.544424401 +0000
+++ third_party/dawn/test/tint/bug/chromium/378541479.wgsl.expected.fxc.hlsl
@@ -0,0 +1,13 @@
+cbuffer cbuffer_level : register(b0) {
+  uint4 level[1];
+};
+cbuffer cbuffer_coords : register(b1) {
+  uint4 coords[1];
+};
+Texture2D tex : register(t2);
+
+[numthreads(1, 1, 1)]
+void compute_main() {
+  float res = tex.Load(uint3(coords[0].xy, level[0].x)).x;
+  return;
+}
