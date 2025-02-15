$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/wgsl/resolver/address_space_layout_validation_test.cc.orig	2024-10-18 12:38:01.509453300 +0000
+++ third_party/dawn/src/tint/lang/wgsl/resolver/address_space_layout_validation_test.cc
@@ -216,7 +216,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
 // multiple of 16 bytes
 TEST_F(ResolverAddressSpaceLayoutValidationTest, UniformBuffer_MembersOffsetNotMultipleOf16) {
     // struct Inner {
-    //   @align(1) @size(5) scalar : i32;
+    //   @align(4) @size(5) scalar : i32;
     // };
     //
     // struct Outer {
@@ -229,7 +229,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
 
     Structure(Ident(Source{{12, 34}}, "Inner"),
               Vector{
-                  Member("scalar", ty.i32(), Vector{MemberAlign(1_i), MemberSize(5_a)}),
+                  Member("scalar", ty.i32(), Vector{MemberAlign(4_i), MemberSize(5_a)}),
               });
 
     Structure(Source{{34, 56}}, "Outer",
@@ -247,13 +247,13 @@ TEST_F(ResolverAddressSpaceLayoutValidat
         R"(78:90 error: 'uniform' storage requires that the number of bytes between the start of the previous member of type struct and the current member be a multiple of 16 bytes, but there are currently 8 bytes between 'inner' and 'scalar'. Consider setting '@align(16)' on this member
 note: see layout of struct:
 /*            align(4) size(12) */ struct Outer {
-/* offset( 0) align(1) size( 5) */   inner : Inner,
-/* offset( 5) align(1) size( 3) */   // -- implicit field alignment padding --
+/* offset( 0) align(4) size( 8) */   inner : Inner,
 /* offset( 8) align(4) size( 4) */   scalar : i32,
 /*                              */ };
 12:34 note: and layout of previous member struct:
-/*           align(1) size(5) */ struct Inner {
-/* offset(0) align(1) size(5) */   scalar : i32,
+/*           align(4) size(8) */ struct Inner {
+/* offset(0) align(4) size(5) */   scalar : i32,
+/* offset(5) align(1) size(3) */   // -- implicit struct size padding --
 /*                            */ };
 22:24 note: 'Outer' used in address space 'uniform' here)");
 }
@@ -265,7 +265,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
     //   a : i32;
     //   b : i32;
     //   c : i32;
-    //   @align(1) @size(5) scalar : i32;
+    //   @align(4) @size(5) scalar : i32;
     // };
     //
     // struct Outer {
@@ -281,7 +281,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
                   Member("a", ty.i32()),
                   Member("b", ty.i32()),
                   Member("c", ty.i32()),
-                  Member("scalar", ty.i32(), Vector{MemberAlign(1_i), MemberSize(5_a)}),
+                  Member("scalar", ty.i32(), Vector{MemberAlign(4_i), MemberSize(5_a)}),
               });
 
     Structure(Source{{34, 56}}, "Outer",
@@ -307,7 +307,7 @@ note: see layout of struct:
 /* offset( 0) align(4) size( 4) */   a : i32,
 /* offset( 4) align(4) size( 4) */   b : i32,
 /* offset( 8) align(4) size( 4) */   c : i32,
-/* offset(12) align(1) size( 5) */   scalar : i32,
+/* offset(12) align(4) size( 5) */   scalar : i32,
 /* offset(17) align(1) size( 3) */   // -- implicit struct size padding --
 /*                              */ };
 22:24 note: 'Outer' used in address space 'uniform' here)");
@@ -316,7 +316,7 @@ note: see layout of struct:
 TEST_F(ResolverAddressSpaceLayoutValidationTest,
        UniformBuffer_MembersOffsetNotMultipleOf16_SuggestedFix) {
     // struct Inner {
-    //   @align(1) @size(5) scalar : i32;
+    //   @align(4) @size(5) scalar : i32;
     // };
     //
     // struct Outer {
@@ -328,7 +328,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
     // var<uniform> a : Outer;
 
     Structure("Inner", Vector{
-                           Member("scalar", ty.i32(), Vector{MemberAlign(1_i), MemberSize(5_a)}),
+                           Member("scalar", ty.i32(), Vector{MemberAlign(4_i), MemberSize(5_a)}),
                        });
 
     Structure("Outer", Vector{
@@ -659,7 +659,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
     // enable chromium_internal_relaxed_uniform_layout;
     //
     // struct Inner {
-    //   @align(1) @size(5) scalar : i32;
+    //   @align(4) @size(5) scalar : i32;
     // };
     //
     // struct Outer {
@@ -673,7 +673,7 @@ TEST_F(ResolverAddressSpaceLayoutValidat
     Enable(wgsl::Extension::kChromiumInternalRelaxedUniformLayout);
 
     Structure("Inner", Vector{
-                           Member("scalar", ty.i32(), Vector{MemberAlign(1_i), MemberSize(5_a)}),
+                           Member("scalar", ty.i32(), Vector{MemberAlign(4_i), MemberSize(5_a)}),
                        });
 
     Structure("Outer", Vector{
@@ -730,5 +730,97 @@ TEST_F(ResolverAddressSpaceLayoutValidat
     EXPECT_TRUE(r()->Resolve()) << r()->error();
 }
 
-}  // namespace
+TEST_F(ResolverAddressSpaceLayoutValidationTest, AlignAttributeTooSmall_Storage) {
+    // struct S {
+    //   @align(4) vector : vec4u;
+    //   scalar : u32;
+    // };
+    //
+    // @group(0) @binding(0)
+    // var<storage, read_write> a : array<S>;
+    Structure(
+        "S", Vector{
+                 Member("vector", ty.vec4<u32>(), Vector{MemberAlign(Expr(Source{{12, 34}}, 4_a))}),
+                 Member("scalar", ty.u32()),
+             });
+
+    GlobalVar(Source{{56, 78}}, "a", ty("S"), core::AddressSpace::kStorage,
+              core::Access::kReadWrite, Group(0_a), Binding(0_a));
+
+    ASSERT_FALSE(r()->Resolve());
+    EXPECT_EQ(
+        r()->error(),
+        R"(12:34 error: alignment must be a multiple of '16' bytes for the 'storage' address space
+56:78 note: 'S' used in address space 'storage' here)");
+}
+
+TEST_F(ResolverAddressSpaceLayoutValidationTest, AlignAttributeTooSmall_Workgroup) {
+    // struct S {
+    //   @align(4) vector : vec4u;
+    //   scalar : u32;
+    // };
+    //
+    // var<workgroup> a : array<S, 4>;
+    Structure(
+        "S", Vector{
+                 Member("vector", ty.vec4<u32>(), Vector{MemberAlign(Expr(Source{{12, 34}}, 4_a))}),
+                 Member("scalar", ty.u32()),
+             });
+
+    GlobalVar(Source{{56, 78}}, "a", ty("S"), core::AddressSpace::kWorkgroup, Group(0_a));
+
+    ASSERT_FALSE(r()->Resolve());
+    EXPECT_EQ(
+        r()->error(),
+        R"(12:34 error: alignment must be a multiple of '16' bytes for the 'workgroup' address space
+56:78 note: 'S' used in address space 'workgroup' here)");
+}
+
+TEST_F(ResolverAddressSpaceLayoutValidationTest, AlignAttributeTooSmall_Private) {
+    // struct S {
+    //   @align(4) vector : vec4u;
+    //   scalar : u32;
+    // };
+    //
+    // var<private> a : array<S, 4>;
+    Structure(
+        "S", Vector{
+                 Member("vector", ty.vec4<u32>(), Vector{MemberAlign(Expr(Source{{12, 34}}, 4_a))}),
+                 Member("scalar", ty.u32()),
+             });
+
+    GlobalVar(Source{{56, 78}}, "a", ty("S"), core::AddressSpace::kPrivate, Group(0_a));
+
+    ASSERT_FALSE(r()->Resolve());
+    EXPECT_EQ(
+        r()->error(),
+        R"(12:34 error: alignment must be a multiple of '16' bytes for the 'private' address space
+56:78 note: 'S' used in address space 'private' here)");
+}
+
+TEST_F(ResolverAddressSpaceLayoutValidationTest, AlignAttributeTooSmall_Function) {
+    // struct S {
+    //   @align(4) vector : vec4u;
+    //   scalar : u32;
+    // };
+    //
+    // fn foo() {
+    //   var a : array<S, 4>;
+    // }
+    Structure(
+        "S", Vector{
+                 Member("vector", ty.vec4<u32>(), Vector{MemberAlign(Expr(Source{{12, 34}}, 4_a))}),
+                 Member("scalar", ty.u32()),
+             });
+
+    GlobalVar(Source{{56, 78}}, "a", ty("S"), core::AddressSpace::kFunction, Group(0_a));
+
+    ASSERT_FALSE(r()->Resolve());
+    EXPECT_EQ(
+        r()->error(),
+        R"(12:34 error: alignment must be a multiple of '16' bytes for the 'function' address space
+56:78 note: 'S' used in address space 'function' here)");
+}
+
+ }  // namespace
 }  // namespace tint::resolver
