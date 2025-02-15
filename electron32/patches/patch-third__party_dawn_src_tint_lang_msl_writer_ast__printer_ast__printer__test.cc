$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/msl/writer/ast_printer/ast_printer_test.cc.orig	2024-10-18 12:38:01.405487300 +0000
+++ third_party/dawn/src/tint/lang/msl/writer/ast_printer/ast_printer_test.cc
@@ -378,93 +378,137 @@ TEST_F(MslASTPrinterTest, WorkgroupMatri
     EXPECT_EQ(gen.Result(), R"(#include <metal_stdlib>
 
 using namespace metal;
+
+template<typename T, size_t N>
+struct tint_array {
+    const constant T& operator[](size_t i) const constant { return elements[i]; }
+    device T& operator[](size_t i) device { return elements[i]; }
+    const device T& operator[](size_t i) const device { return elements[i]; }
+    thread T& operator[](size_t i) thread { return elements[i]; }
+    const thread T& operator[](size_t i) const thread { return elements[i]; }
+    threadgroup T& operator[](size_t i) threadgroup { return elements[i]; }
+    const threadgroup T& operator[](size_t i) const threadgroup { return elements[i]; }
+    T elements[N];
+};
+
 struct tint_symbol_16 {
   float2x2 m1;
-  float2x3 m2;
   float2x4 m3;
 };
 
 struct tint_symbol_24 {
   float3x2 m4;
-  float3x3 m5;
   float3x4 m6;
 };
 
 struct tint_symbol_32 {
   float4x2 m7;
-  float4x3 m8;
   float4x4 m9;
 };
 
-void tint_zero_workgroup_memory(uint local_idx, threadgroup float2x2* const tint_symbol, threadgroup float2x3* const tint_symbol_1, threadgroup float2x4* const tint_symbol_2) {
+struct tint_packed_vec3_f32_array_element {
+  packed_float3 elements;
+};
+
+float2x3 tint_unpack_vec3_in_composite(tint_array<tint_packed_vec3_f32_array_element, 2> in) {
+  float2x3 result = float2x3(float3(in[0].elements), float3(in[1].elements));
+  return result;
+}
+
+float3x3 tint_unpack_vec3_in_composite_1(tint_array<tint_packed_vec3_f32_array_element, 3> in) {
+  float3x3 result = float3x3(float3(in[0].elements), float3(in[1].elements), float3(in[2].elements));
+  return result;
+}
+
+float4x3 tint_unpack_vec3_in_composite_2(tint_array<tint_packed_vec3_f32_array_element, 4> in) {
+  float4x3 result = float4x3(float3(in[0].elements), float3(in[1].elements), float3(in[2].elements), float3(in[3].elements));
+  return result;
+}
+
+tint_array<tint_packed_vec3_f32_array_element, 2> tint_pack_vec3_in_composite(float2x3 in) {
+  tint_array<tint_packed_vec3_f32_array_element, 2> result = tint_array<tint_packed_vec3_f32_array_element, 2>{{.elements=packed_float3(in[0])}, {.elements=packed_float3(in[1])}};
+  return result;
+}
+
+tint_array<tint_packed_vec3_f32_array_element, 3> tint_pack_vec3_in_composite_1(float3x3 in) {
+  tint_array<tint_packed_vec3_f32_array_element, 3> result = tint_array<tint_packed_vec3_f32_array_element, 3>{{.elements=packed_float3(in[0])}, {.elements=packed_float3(in[1])}, {.elements=packed_float3(in[2])}};
+  return result;
+}
+
+tint_array<tint_packed_vec3_f32_array_element, 4> tint_pack_vec3_in_composite_2(float4x3 in) {
+  tint_array<tint_packed_vec3_f32_array_element, 4> result = tint_array<tint_packed_vec3_f32_array_element, 4>{{.elements=packed_float3(in[0])}, {.elements=packed_float3(in[1])}, {.elements=packed_float3(in[2])}, {.elements=packed_float3(in[3])}};
+  return result;
+}
+
+void tint_zero_workgroup_memory(uint local_idx, threadgroup float2x2* const tint_symbol, threadgroup tint_array<tint_packed_vec3_f32_array_element, 2>* const tint_symbol_1, threadgroup float2x4* const tint_symbol_2) {
   if ((local_idx < 1u)) {
     *(tint_symbol) = float2x2(float2(0.0f), float2(0.0f));
-    *(tint_symbol_1) = float2x3(float3(0.0f), float3(0.0f));
+    *(tint_symbol_1) = tint_pack_vec3_in_composite(float2x3(float3(0.0f), float3(0.0f)));
     *(tint_symbol_2) = float2x4(float4(0.0f), float4(0.0f));
   }
   threadgroup_barrier(mem_flags::mem_threadgroup);
 }
 
-void tint_zero_workgroup_memory_1(uint local_idx_1, threadgroup float3x2* const tint_symbol_3, threadgroup float3x3* const tint_symbol_4, threadgroup float3x4* const tint_symbol_5) {
+void tint_zero_workgroup_memory_1(uint local_idx_1, threadgroup float3x2* const tint_symbol_3, threadgroup tint_array<tint_packed_vec3_f32_array_element, 3>* const tint_symbol_4, threadgroup float3x4* const tint_symbol_5) {
   if ((local_idx_1 < 1u)) {
     *(tint_symbol_3) = float3x2(float2(0.0f), float2(0.0f), float2(0.0f));
-    *(tint_symbol_4) = float3x3(float3(0.0f), float3(0.0f), float3(0.0f));
+    *(tint_symbol_4) = tint_pack_vec3_in_composite_1(float3x3(float3(0.0f), float3(0.0f), float3(0.0f)));
     *(tint_symbol_5) = float3x4(float4(0.0f), float4(0.0f), float4(0.0f));
   }
   threadgroup_barrier(mem_flags::mem_threadgroup);
 }
 
-void tint_zero_workgroup_memory_2(uint local_idx_2, threadgroup float4x2* const tint_symbol_6, threadgroup float4x3* const tint_symbol_7, threadgroup float4x4* const tint_symbol_8) {
+void tint_zero_workgroup_memory_2(uint local_idx_2, threadgroup float4x2* const tint_symbol_6, threadgroup tint_array<tint_packed_vec3_f32_array_element, 4>* const tint_symbol_7, threadgroup float4x4* const tint_symbol_8) {
   if ((local_idx_2 < 1u)) {
     *(tint_symbol_6) = float4x2(float2(0.0f), float2(0.0f), float2(0.0f), float2(0.0f));
-    *(tint_symbol_7) = float4x3(float3(0.0f), float3(0.0f), float3(0.0f), float3(0.0f));
+    *(tint_symbol_7) = tint_pack_vec3_in_composite_2(float4x3(float3(0.0f), float3(0.0f), float3(0.0f), float3(0.0f)));
     *(tint_symbol_8) = float4x4(float4(0.0f), float4(0.0f), float4(0.0f), float4(0.0f));
   }
   threadgroup_barrier(mem_flags::mem_threadgroup);
 }
 
-void main1_inner(uint local_invocation_index, threadgroup float2x2* const tint_symbol_9, threadgroup float2x3* const tint_symbol_10, threadgroup float2x4* const tint_symbol_11) {
+void main1_inner(uint local_invocation_index, threadgroup float2x2* const tint_symbol_9, threadgroup tint_array<tint_packed_vec3_f32_array_element, 2>* const tint_symbol_10, threadgroup float2x4* const tint_symbol_11) {
   tint_zero_workgroup_memory(local_invocation_index, tint_symbol_9, tint_symbol_10, tint_symbol_11);
   float2x2 const a1 = *(tint_symbol_9);
-  float2x3 const a2 = *(tint_symbol_10);
+  float2x3 const a2 = tint_unpack_vec3_in_composite(*(tint_symbol_10));
   float2x4 const a3 = *(tint_symbol_11);
 }
 
 kernel void main1(threadgroup tint_symbol_16* tint_symbol_13 [[threadgroup(0)]], uint local_invocation_index [[thread_index_in_threadgroup]]) {
   threadgroup float2x2* const tint_symbol_12 = &((*(tint_symbol_13)).m1);
-  threadgroup float2x3* const tint_symbol_14 = &((*(tint_symbol_13)).m2);
+  threadgroup tint_array<tint_packed_vec3_f32_array_element, 2> tint_symbol_14;
   threadgroup float2x4* const tint_symbol_15 = &((*(tint_symbol_13)).m3);
-  main1_inner(local_invocation_index, tint_symbol_12, tint_symbol_14, tint_symbol_15);
+  main1_inner(local_invocation_index, tint_symbol_12, &(tint_symbol_14), tint_symbol_15);
   return;
 }
 
-void main2_inner(uint local_invocation_index_1, threadgroup float3x2* const tint_symbol_17, threadgroup float3x3* const tint_symbol_18, threadgroup float3x4* const tint_symbol_19) {
+void main2_inner(uint local_invocation_index_1, threadgroup float3x2* const tint_symbol_17, threadgroup tint_array<tint_packed_vec3_f32_array_element, 3>* const tint_symbol_18, threadgroup float3x4* const tint_symbol_19) {
   tint_zero_workgroup_memory_1(local_invocation_index_1, tint_symbol_17, tint_symbol_18, tint_symbol_19);
   float3x2 const a1 = *(tint_symbol_17);
-  float3x3 const a2 = *(tint_symbol_18);
+  float3x3 const a2 = tint_unpack_vec3_in_composite_1(*(tint_symbol_18));
   float3x4 const a3 = *(tint_symbol_19);
 }
 
 kernel void main2(threadgroup tint_symbol_24* tint_symbol_21 [[threadgroup(0)]], uint local_invocation_index_1 [[thread_index_in_threadgroup]]) {
   threadgroup float3x2* const tint_symbol_20 = &((*(tint_symbol_21)).m4);
-  threadgroup float3x3* const tint_symbol_22 = &((*(tint_symbol_21)).m5);
+  threadgroup tint_array<tint_packed_vec3_f32_array_element, 3> tint_symbol_22;
   threadgroup float3x4* const tint_symbol_23 = &((*(tint_symbol_21)).m6);
-  main2_inner(local_invocation_index_1, tint_symbol_20, tint_symbol_22, tint_symbol_23);
+  main2_inner(local_invocation_index_1, tint_symbol_20, &(tint_symbol_22), tint_symbol_23);
   return;
 }
 
-void main3_inner(uint local_invocation_index_2, threadgroup float4x2* const tint_symbol_25, threadgroup float4x3* const tint_symbol_26, threadgroup float4x4* const tint_symbol_27) {
+void main3_inner(uint local_invocation_index_2, threadgroup float4x2* const tint_symbol_25, threadgroup tint_array<tint_packed_vec3_f32_array_element, 4>* const tint_symbol_26, threadgroup float4x4* const tint_symbol_27) {
   tint_zero_workgroup_memory_2(local_invocation_index_2, tint_symbol_25, tint_symbol_26, tint_symbol_27);
   float4x2 const a1 = *(tint_symbol_25);
-  float4x3 const a2 = *(tint_symbol_26);
+  float4x3 const a2 = tint_unpack_vec3_in_composite_2(*(tint_symbol_26));
   float4x4 const a3 = *(tint_symbol_27);
 }
 
 kernel void main3(threadgroup tint_symbol_32* tint_symbol_29 [[threadgroup(0)]], uint local_invocation_index_2 [[thread_index_in_threadgroup]]) {
   threadgroup float4x2* const tint_symbol_28 = &((*(tint_symbol_29)).m7);
-  threadgroup float4x3* const tint_symbol_30 = &((*(tint_symbol_29)).m8);
+  threadgroup tint_array<tint_packed_vec3_f32_array_element, 4> tint_symbol_30;
   threadgroup float4x4* const tint_symbol_31 = &((*(tint_symbol_29)).m9);
-  main3_inner(local_invocation_index_2, tint_symbol_28, tint_symbol_30, tint_symbol_31);
+  main3_inner(local_invocation_index_2, tint_symbol_28, &(tint_symbol_30), tint_symbol_31);
   return;
 }
 
@@ -479,11 +523,11 @@ kernel void main4_no_usages() {
     ASSERT_TRUE(allocations.count("main2"));
     ASSERT_TRUE(allocations.count("main3"));
     ASSERT_EQ(allocations.at("main1").size(), 1u);
-    EXPECT_EQ(allocations.at("main1")[0], 20u * sizeof(float));
+    EXPECT_EQ(allocations.at("main1")[0], 12u * sizeof(float));
     ASSERT_EQ(allocations.at("main2").size(), 1u);
-    EXPECT_EQ(allocations.at("main2")[0], 32u * sizeof(float));
+    EXPECT_EQ(allocations.at("main2")[0], 20u * sizeof(float));
     ASSERT_EQ(allocations.at("main3").size(), 1u);
-    EXPECT_EQ(allocations.at("main3")[0], 40u * sizeof(float));
+    EXPECT_EQ(allocations.at("main3")[0], 24u * sizeof(float));
     EXPECT_EQ(allocations.at("main4_no_usages").size(), 0u);
 }
 
