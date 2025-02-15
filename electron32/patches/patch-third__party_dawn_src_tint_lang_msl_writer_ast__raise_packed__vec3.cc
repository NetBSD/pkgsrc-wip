$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/msl/writer/ast_raise/packed_vec3.cc.orig	2024-10-18 12:38:01.405487300 +0000
+++ third_party/dawn/src/tint/lang/msl/writer/ast_raise/packed_vec3.cc
@@ -83,6 +83,14 @@ struct PackedVec3::State {
     /// A map from type to the name of a helper function used to unpack that type.
     Hashmap<const core::type::Type*, Symbol, 4> unpack_helpers;
 
+    /// @returns true if @p addrspace requires vec3 types to be packed
+    bool AddressSpaceNeedsPacking(core::AddressSpace addrspace) {
+        // Host-shareable address spaces need to be packed to match the memory layout on the host.
+        // The workgroup address space needs to be packed so that the size of generated threadgroup
+        // variables matches the size of the original WGSL declarations.
+        return core::IsHostShareable(addrspace) || addrspace == core::AddressSpace::kWorkgroup;
+    }
+
     /// @param ty the type to test
     /// @returns true if `ty` is a vec3, false otherwise
     bool IsVec3(const core::type::Type* ty) {
@@ -373,7 +381,7 @@ struct PackedVec3::State {
         // if the transform is necessary.
         for (auto* decl : src.AST().GlobalVariables()) {
             auto* var = sem.Get<sem::GlobalVariable>(decl);
-            if (var && core::IsHostShareable(var->AddressSpace()) &&
+            if (var && AddressSpaceNeedsPacking(var->AddressSpace()) &&
                 ContainsVec3(var->Type()->UnwrapRef())) {
                 return true;
             }
@@ -410,7 +418,7 @@ struct PackedVec3::State {
                 [&](const sem::TypeExpression* type) {
                     // Rewrite pointers to types that contain vec3s.
                     auto* ptr = type->Type()->As<core::type::Pointer>();
-                    if (ptr && core::IsHostShareable(ptr->AddressSpace())) {
+                    if (ptr && AddressSpaceNeedsPacking(ptr->AddressSpace())) {
                         auto new_store_type = RewriteType(ptr->StoreType());
                         if (new_store_type) {
                             auto access = ptr->AddressSpace() == core::AddressSpace::kStorage
@@ -423,7 +431,7 @@ struct PackedVec3::State {
                     }
                 },
                 [&](const sem::Variable* var) {
-                    if (!core::IsHostShareable(var->AddressSpace())) {
+                    if (!AddressSpaceNeedsPacking(var->AddressSpace())) {
                         return;
                     }
 
@@ -439,7 +447,7 @@ struct PackedVec3::State {
                         auto* lhs = sem.GetVal(assign->lhs);
                         auto* rhs = sem.GetVal(assign->rhs);
                         if (!ContainsVec3(rhs->Type()) ||
-                            !core::IsHostShareable(
+                            !AddressSpaceNeedsPacking(
                                 lhs->Type()->As<core::type::Reference>()->AddressSpace())) {
                             // Skip assignments to address spaces that are not host-shareable, or
                             // that do not contain vec3 types.
@@ -467,7 +475,7 @@ struct PackedVec3::State {
                 [&](const sem::Load* load) {
                     // Unpack loads of types that contain vec3s in host-shareable address spaces.
                     if (ContainsVec3(load->Type()) &&
-                        core::IsHostShareable(load->ReferenceType()->AddressSpace())) {
+                        AddressSpaceNeedsPacking(load->ReferenceType()->AddressSpace())) {
                         to_unpack.Add(load);
                     }
                 },
@@ -477,7 +485,7 @@ struct PackedVec3::State {
                     // struct.
                     if (auto* ref = accessor->Type()->As<core::type::Reference>()) {
                         if (IsVec3(ref->StoreType()) &&
-                            core::IsHostShareable(ref->AddressSpace())) {
+                            AddressSpaceNeedsPacking(ref->AddressSpace())) {
                             ctx.Replace(node, b.MemberAccessor(ctx.Clone(accessor->Declaration()),
                                                                kStructMemberName));
                         }
