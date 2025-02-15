$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/msl/writer/ast_raise/packed_vec3_test.cc.orig	2024-10-18 12:38:01.405487300 +0000
+++ third_party/dawn/src/tint/lang/msl/writer/ast_raise/packed_vec3_test.cc
@@ -67,11 +67,6 @@ var<private> p_v : vec3<f32>;
 var<private> p_m : mat3x3<f32>;
 var<private> p_a : array<vec3<f32>, 4>;
 
-var<workgroup> w_s : S;
-var<workgroup> w_v : vec3<f32>;
-var<workgroup> w_m : mat3x3<f32>;
-var<workgroup> w_a : array<vec3<f32>, 4>;
-
 fn f() {
   var f_s : S;
   var f_v : vec3<f32>;
@@ -6944,20 +6939,20 @@ struct S {
 
 @group(0) @binding(0) var<storage> P : S_tint_packed_vec3;
 
-var<workgroup> w1 : S;
+var<workgroup> w1 : S_tint_packed_vec3;
 
-var<workgroup> w2 : vec3<f32>;
+var<workgroup> w2 : __packed_vec3<f32>;
 
-var<workgroup> w3 : array<vec3<f32>, 4>;
+var<workgroup> w3 : array<tint_packed_vec3_f32_array_element, 4u>;
 
-var<workgroup> w4 : mat3x3<f32>;
+var<workgroup> w4 : array<tint_packed_vec3_f32_array_element, 3u>;
 
 fn f() {
-  let pv_1 : ptr<workgroup, vec3<f32>> = &(w1.v);
-  let pv_2 : ptr<workgroup, vec3<f32>> = &(w2);
-  let pv_3 : ptr<workgroup, vec3<f32>> = &(w3[0]);
-  let pv_4 : ptr<workgroup, mat3x3<f32>> = &(w1.m);
-  let pv_5 : ptr<workgroup, mat3x3<f32>> = &(w4);
+  let pv_1 : ptr<workgroup, __packed_vec3<f32>> = &(w1.v);
+  let pv_2 : ptr<workgroup, __packed_vec3<f32>> = &(w2);
+  let pv_3 : ptr<workgroup, __packed_vec3<f32>> = &(w3[0].elements);
+  let pv_4 : ptr<workgroup, array<tint_packed_vec3_f32_array_element, 3u>> = &(w1.m);
+  let pv_5 : ptr<workgroup, array<tint_packed_vec3_f32_array_element, 3u>> = &(w4);
 }
 )";
 
