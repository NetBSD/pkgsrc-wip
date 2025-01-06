$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/test/tint/bug/chromium/378541479.wgsl.expected.ir.dxc.hlsl.orig	2025-01-06 07:57:04.977241480 +0000
+++ third_party/dawn/test/tint/bug/chromium/378541479.wgsl.expected.ir.dxc.hlsl
@@ -0,0 +1,22 @@
+
+cbuffer cbuffer_level : register(b0) {
+  uint4 level[1];
+};
+cbuffer cbuffer_coords : register(b1) {
+  uint4 coords[1];
+};
+Texture2D tex : register(t2);
+[numthreads(1, 1, 1)]
+void compute_main() {
+  Texture2D v = tex;
+  uint2 v_1 = coords[0u].xy;
+  uint v_2 = level[0u].x;
+  uint3 v_3 = (0u).xxx;
+  v.GetDimensions(0u, v_3[0u], v_3[1u], v_3[2u]);
+  uint v_4 = min(v_2, (v_3.z - 1u));
+  uint3 v_5 = (0u).xxx;
+  v.GetDimensions(uint(v_4), v_5[0u], v_5[1u], v_5[2u]);
+  int2 v_6 = int2(min(v_1, (v_5.xy - (1u).xx)));
+  float res = v.Load(int3(v_6, int(v_4))).x;
+}
+
