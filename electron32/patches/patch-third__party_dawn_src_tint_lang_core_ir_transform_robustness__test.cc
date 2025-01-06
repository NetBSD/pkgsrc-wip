$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/core/ir/transform/robustness_test.cc.orig	2024-10-18 12:38:01.313517300 +0000
+++ third_party/dawn/src/tint/lang/core/ir/transform/robustness_test.cc
@@ -2103,28 +2103,28 @@ $B1: {  # root
 %load_signed = func(%coords:i32, %level:i32):vec4<f32> {
   $B2: {
     %5:texture_1d<f32> = load %texture
-    %6:u32 = textureDimensions %5
+    %6:u32 = textureNumLevels %5
     %7:u32 = sub %6, 1u
-    %8:u32 = convert %coords
+    %8:u32 = convert %level
     %9:u32 = min %8, %7
-    %10:u32 = textureNumLevels %5
+    %10:u32 = textureDimensions %5, %9
     %11:u32 = sub %10, 1u
-    %12:u32 = convert %level
+    %12:u32 = convert %coords
     %13:u32 = min %12, %11
-    %14:vec4<f32> = textureLoad %5, %9, %13
+    %14:vec4<f32> = textureLoad %5, %13, %9
     ret %14
   }
 }
 %load_unsigned = func(%coords_1:u32, %level_1:u32):vec4<f32> {  # %coords_1: 'coords', %level_1: 'level'
   $B3: {
     %18:texture_1d<f32> = load %texture
-    %19:u32 = textureDimensions %18
+    %19:u32 = textureNumLevels %18
     %20:u32 = sub %19, 1u
-    %21:u32 = min %coords_1, %20
-    %22:u32 = textureNumLevels %18
+    %21:u32 = min %level_1, %20
+    %22:u32 = textureDimensions %18, %21
     %23:u32 = sub %22, 1u
-    %24:u32 = min %level_1, %23
-    %25:vec4<f32> = textureLoad %18, %21, %24
+    %24:u32 = min %coords_1, %23
+    %25:vec4<f32> = textureLoad %18, %24, %21
     ret %25
   }
 }
@@ -2200,28 +2200,28 @@ $B1: {  # root
 %load_signed = func(%coords:vec2<i32>, %level:i32):vec4<f32> {
   $B2: {
     %5:texture_2d<f32> = load %texture
-    %6:vec2<u32> = textureDimensions %5
-    %7:vec2<u32> = sub %6, vec2<u32>(1u)
-    %8:vec2<u32> = convert %coords
-    %9:vec2<u32> = min %8, %7
-    %10:u32 = textureNumLevels %5
-    %11:u32 = sub %10, 1u
-    %12:u32 = convert %level
-    %13:u32 = min %12, %11
-    %14:vec4<f32> = textureLoad %5, %9, %13
+    %6:u32 = textureNumLevels %5
+    %7:u32 = sub %6, 1u
+    %8:u32 = convert %level
+    %9:u32 = min %8, %7
+    %10:vec2<u32> = textureDimensions %5, %9
+    %11:vec2<u32> = sub %10, vec2<u32>(1u)
+    %12:vec2<u32> = convert %coords
+    %13:vec2<u32> = min %12, %11
+    %14:vec4<f32> = textureLoad %5, %13, %9
     ret %14
   }
 }
 %load_unsigned = func(%coords_1:vec2<u32>, %level_1:u32):vec4<f32> {  # %coords_1: 'coords', %level_1: 'level'
   $B3: {
     %18:texture_2d<f32> = load %texture
-    %19:vec2<u32> = textureDimensions %18
-    %20:vec2<u32> = sub %19, vec2<u32>(1u)
-    %21:vec2<u32> = min %coords_1, %20
-    %22:u32 = textureNumLevels %18
-    %23:u32 = sub %22, 1u
-    %24:u32 = min %level_1, %23
-    %25:vec4<f32> = textureLoad %18, %21, %24
+    %19:u32 = textureNumLevels %18
+    %20:u32 = sub %19, 1u
+    %21:u32 = min %level_1, %20
+    %22:vec2<u32> = textureDimensions %18, %21
+    %23:vec2<u32> = sub %22, vec2<u32>(1u)
+    %24:vec2<u32> = min %coords_1, %23
+    %25:vec4<f32> = textureLoad %18, %24, %21
     ret %25
   }
 }
@@ -2300,35 +2300,35 @@ $B1: {  # root
 %load_signed = func(%coords:vec2<i32>, %layer:i32, %level:i32):vec4<f32> {
   $B2: {
     %6:texture_2d_array<f32> = load %texture
-    %7:vec2<u32> = textureDimensions %6
-    %8:vec2<u32> = sub %7, vec2<u32>(1u)
-    %9:vec2<u32> = convert %coords
-    %10:vec2<u32> = min %9, %8
-    %11:u32 = textureNumLayers %6
+    %7:u32 = textureNumLayers %6
+    %8:u32 = sub %7, 1u
+    %9:u32 = convert %layer
+    %10:u32 = min %9, %8
+    %11:u32 = textureNumLevels %6
     %12:u32 = sub %11, 1u
-    %13:u32 = convert %layer
+    %13:u32 = convert %level
     %14:u32 = min %13, %12
-    %15:u32 = textureNumLevels %6
-    %16:u32 = sub %15, 1u
-    %17:u32 = convert %level
-    %18:u32 = min %17, %16
-    %19:vec4<f32> = textureLoad %6, %10, %14, %18
+    %15:vec2<u32> = textureDimensions %6, %14
+    %16:vec2<u32> = sub %15, vec2<u32>(1u)
+    %17:vec2<u32> = convert %coords
+    %18:vec2<u32> = min %17, %16
+    %19:vec4<f32> = textureLoad %6, %18, %10, %14
     ret %19
   }
 }
 %load_unsigned = func(%coords_1:vec2<u32>, %layer_1:u32, %level_1:u32):vec4<f32> {  # %coords_1: 'coords', %layer_1: 'layer', %level_1: 'level'
   $B3: {
     %24:texture_2d_array<f32> = load %texture
-    %25:vec2<u32> = textureDimensions %24
-    %26:vec2<u32> = sub %25, vec2<u32>(1u)
-    %27:vec2<u32> = min %coords_1, %26
-    %28:u32 = textureNumLayers %24
+    %25:u32 = textureNumLayers %24
+    %26:u32 = sub %25, 1u
+    %27:u32 = min %layer_1, %26
+    %28:u32 = textureNumLevels %24
     %29:u32 = sub %28, 1u
-    %30:u32 = min %layer_1, %29
-    %31:u32 = textureNumLevels %24
-    %32:u32 = sub %31, 1u
-    %33:u32 = min %level_1, %32
-    %34:vec4<f32> = textureLoad %24, %27, %30, %33
+    %30:u32 = min %level_1, %29
+    %31:vec2<u32> = textureDimensions %24, %30
+    %32:vec2<u32> = sub %31, vec2<u32>(1u)
+    %33:vec2<u32> = min %coords_1, %32
+    %34:vec4<f32> = textureLoad %24, %33, %27, %30
     ret %34
   }
 }
@@ -2404,28 +2404,28 @@ $B1: {  # root
 %load_signed = func(%coords:vec3<i32>, %level:i32):vec4<f32> {
   $B2: {
     %5:texture_3d<f32> = load %texture
-    %6:vec3<u32> = textureDimensions %5
-    %7:vec3<u32> = sub %6, vec3<u32>(1u)
-    %8:vec3<u32> = convert %coords
-    %9:vec3<u32> = min %8, %7
-    %10:u32 = textureNumLevels %5
-    %11:u32 = sub %10, 1u
-    %12:u32 = convert %level
-    %13:u32 = min %12, %11
-    %14:vec4<f32> = textureLoad %5, %9, %13
+    %6:u32 = textureNumLevels %5
+    %7:u32 = sub %6, 1u
+    %8:u32 = convert %level
+    %9:u32 = min %8, %7
+    %10:vec3<u32> = textureDimensions %5, %9
+    %11:vec3<u32> = sub %10, vec3<u32>(1u)
+    %12:vec3<u32> = convert %coords
+    %13:vec3<u32> = min %12, %11
+    %14:vec4<f32> = textureLoad %5, %13, %9
     ret %14
   }
 }
 %load_unsigned = func(%coords_1:vec3<u32>, %level_1:u32):vec4<f32> {  # %coords_1: 'coords', %level_1: 'level'
   $B3: {
     %18:texture_3d<f32> = load %texture
-    %19:vec3<u32> = textureDimensions %18
-    %20:vec3<u32> = sub %19, vec3<u32>(1u)
-    %21:vec3<u32> = min %coords_1, %20
-    %22:u32 = textureNumLevels %18
-    %23:u32 = sub %22, 1u
-    %24:u32 = min %level_1, %23
-    %25:vec4<f32> = textureLoad %18, %21, %24
+    %19:u32 = textureNumLevels %18
+    %20:u32 = sub %19, 1u
+    %21:u32 = min %level_1, %20
+    %22:vec3<u32> = textureDimensions %18, %21
+    %23:vec3<u32> = sub %22, vec3<u32>(1u)
+    %24:vec3<u32> = min %coords_1, %23
+    %25:vec4<f32> = textureLoad %18, %24, %21
     ret %25
   }
 }
@@ -2589,28 +2589,28 @@ $B1: {  # root
 %load_signed = func(%coords:vec2<i32>, %level:i32):f32 {
   $B2: {
     %5:texture_depth_2d = load %texture
-    %6:vec2<u32> = textureDimensions %5
-    %7:vec2<u32> = sub %6, vec2<u32>(1u)
-    %8:vec2<u32> = convert %coords
-    %9:vec2<u32> = min %8, %7
-    %10:u32 = textureNumLevels %5
-    %11:u32 = sub %10, 1u
-    %12:u32 = convert %level
-    %13:u32 = min %12, %11
-    %14:f32 = textureLoad %5, %9, %13
+    %6:u32 = textureNumLevels %5
+    %7:u32 = sub %6, 1u
+    %8:u32 = convert %level
+    %9:u32 = min %8, %7
+    %10:vec2<u32> = textureDimensions %5, %9
+    %11:vec2<u32> = sub %10, vec2<u32>(1u)
+    %12:vec2<u32> = convert %coords
+    %13:vec2<u32> = min %12, %11
+    %14:f32 = textureLoad %5, %13, %9
     ret %14
   }
 }
 %load_unsigned = func(%coords_1:vec2<u32>, %level_1:u32):f32 {  # %coords_1: 'coords', %level_1: 'level'
   $B3: {
     %18:texture_depth_2d = load %texture
-    %19:vec2<u32> = textureDimensions %18
-    %20:vec2<u32> = sub %19, vec2<u32>(1u)
-    %21:vec2<u32> = min %coords_1, %20
-    %22:u32 = textureNumLevels %18
-    %23:u32 = sub %22, 1u
-    %24:u32 = min %level_1, %23
-    %25:f32 = textureLoad %18, %21, %24
+    %19:u32 = textureNumLevels %18
+    %20:u32 = sub %19, 1u
+    %21:u32 = min %level_1, %20
+    %22:vec2<u32> = textureDimensions %18, %21
+    %23:vec2<u32> = sub %22, vec2<u32>(1u)
+    %24:vec2<u32> = min %coords_1, %23
+    %25:f32 = textureLoad %18, %24, %21
     ret %25
   }
 }
@@ -2688,35 +2688,35 @@ $B1: {  # root
 %load_signed = func(%coords:vec2<i32>, %layer:i32, %level:i32):f32 {
   $B2: {
     %6:texture_depth_2d_array = load %texture
-    %7:vec2<u32> = textureDimensions %6
-    %8:vec2<u32> = sub %7, vec2<u32>(1u)
-    %9:vec2<u32> = convert %coords
-    %10:vec2<u32> = min %9, %8
-    %11:u32 = textureNumLayers %6
+    %7:u32 = textureNumLayers %6
+    %8:u32 = sub %7, 1u
+    %9:u32 = convert %layer
+    %10:u32 = min %9, %8
+    %11:u32 = textureNumLevels %6
     %12:u32 = sub %11, 1u
-    %13:u32 = convert %layer
+    %13:u32 = convert %level
     %14:u32 = min %13, %12
-    %15:u32 = textureNumLevels %6
-    %16:u32 = sub %15, 1u
-    %17:u32 = convert %level
-    %18:u32 = min %17, %16
-    %19:f32 = textureLoad %6, %10, %14, %18
+    %15:vec2<u32> = textureDimensions %6, %14
+    %16:vec2<u32> = sub %15, vec2<u32>(1u)
+    %17:vec2<u32> = convert %coords
+    %18:vec2<u32> = min %17, %16
+    %19:f32 = textureLoad %6, %18, %10, %14
     ret %19
   }
 }
 %load_unsigned = func(%coords_1:vec2<u32>, %layer_1:u32, %level_1:u32):f32 {  # %coords_1: 'coords', %layer_1: 'layer', %level_1: 'level'
   $B3: {
     %24:texture_depth_2d_array = load %texture
-    %25:vec2<u32> = textureDimensions %24
-    %26:vec2<u32> = sub %25, vec2<u32>(1u)
-    %27:vec2<u32> = min %coords_1, %26
-    %28:u32 = textureNumLayers %24
+    %25:u32 = textureNumLayers %24
+    %26:u32 = sub %25, 1u
+    %27:u32 = min %layer_1, %26
+    %28:u32 = textureNumLevels %24
     %29:u32 = sub %28, 1u
-    %30:u32 = min %layer_1, %29
-    %31:u32 = textureNumLevels %24
-    %32:u32 = sub %31, 1u
-    %33:u32 = min %level_1, %32
-    %34:f32 = textureLoad %24, %27, %30, %33
+    %30:u32 = min %level_1, %29
+    %31:vec2<u32> = textureDimensions %24, %30
+    %32:vec2<u32> = sub %31, vec2<u32>(1u)
+    %33:vec2<u32> = min %coords_1, %32
+    %34:f32 = textureLoad %24, %33, %27, %30
     ret %34
   }
 }
@@ -3148,28 +3148,28 @@ $B1: {  # root
 %load_signed = func(%coords:vec2<i32>, %layer:i32):vec4<f32> {
   $B2: {
     %5:texture_storage_2d_array<rgba8unorm, read_write> = load %texture
-    %6:vec2<u32> = textureDimensions %5
-    %7:vec2<u32> = sub %6, vec2<u32>(1u)
-    %8:vec2<u32> = convert %coords
-    %9:vec2<u32> = min %8, %7
-    %10:u32 = textureNumLayers %5
-    %11:u32 = sub %10, 1u
-    %12:u32 = convert %layer
-    %13:u32 = min %12, %11
-    %14:vec4<f32> = textureLoad %5, %9, %13
+    %6:u32 = textureNumLayers %5
+    %7:u32 = sub %6, 1u
+    %8:u32 = convert %layer
+    %9:u32 = min %8, %7
+    %10:vec2<u32> = textureDimensions %5
+    %11:vec2<u32> = sub %10, vec2<u32>(1u)
+    %12:vec2<u32> = convert %coords
+    %13:vec2<u32> = min %12, %11
+    %14:vec4<f32> = textureLoad %5, %13, %9
     ret %14
   }
 }
 %load_unsigned = func(%coords_1:vec2<u32>, %layer_1:u32):vec4<f32> {  # %coords_1: 'coords', %layer_1: 'layer'
   $B3: {
     %18:texture_storage_2d_array<rgba8unorm, read_write> = load %texture
-    %19:vec2<u32> = textureDimensions %18
-    %20:vec2<u32> = sub %19, vec2<u32>(1u)
-    %21:vec2<u32> = min %coords_1, %20
-    %22:u32 = textureNumLayers %18
-    %23:u32 = sub %22, 1u
-    %24:u32 = min %layer_1, %23
-    %25:vec4<f32> = textureLoad %18, %21, %24
+    %19:u32 = textureNumLayers %18
+    %20:u32 = sub %19, 1u
+    %21:u32 = min %layer_1, %20
+    %22:vec2<u32> = textureDimensions %18
+    %23:vec2<u32> = sub %22, vec2<u32>(1u)
+    %24:vec2<u32> = min %coords_1, %23
+    %25:vec4<f32> = textureLoad %18, %24, %21
     ret %25
   }
 }
