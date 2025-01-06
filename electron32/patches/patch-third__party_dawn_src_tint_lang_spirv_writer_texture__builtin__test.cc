$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/spirv/writer/texture_builtin_test.cc.orig	2024-10-18 12:38:01.453471700 +0000
+++ third_party/dawn/src/tint/lang/spirv/writer/texture_builtin_test.cc
@@ -1998,14 +1998,14 @@ TEST_F(SpirvWriterTest, TextureLoad_With
 
     ASSERT_TRUE(Generate()) << Error() << output_;
     EXPECT_INST(R"(
-         %13 = OpImageQuerySizeLod %v2uint %texture %uint_0
-         %15 = OpISub %v2uint %13 %16
-         %18 = OpExtInst %v2uint %19 UMin %coords %15
-         %20 = OpImageQueryLevels %uint %texture
-         %21 = OpISub %uint %20 %uint_1
-         %22 = OpBitcast %uint %level
-         %23 = OpExtInst %uint %19 UMin %22 %21
-     %result = OpImageFetch %v4float %texture %18 Lod %23
+         %13 = OpImageQueryLevels %uint %texture
+         %14 = OpISub %uint %13 %uint_1
+         %16 = OpBitcast %uint %level
+         %17 = OpExtInst %uint %18 UMin %16 %14
+         %19 = OpImageQuerySizeLod %v2uint %texture %17
+         %20 = OpISub %v2uint %19 %21
+         %22 = OpExtInst %v2uint %18 UMin %coords %20
+     %result = OpImageFetch %v4float %texture %22 Lod %17
 )");
 }
 
