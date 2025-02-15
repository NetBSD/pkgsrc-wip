$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/dawn/src/tint/lang/wgsl/resolver/validator.cc.orig	2024-10-18 12:38:01.525448000 +0000
+++ third_party/dawn/src/tint/lang/wgsl/resolver/validator.cc
@@ -577,10 +577,6 @@ bool Validator::AddressSpaceLayout(const
         return true;
     }
 
-    if (!core::IsHostShareable(address_space)) {
-        return true;
-    }
-
     auto note_usage = [&] {
         AddNote(source) << style::Type(store_ty->FriendlyName()) << " used in address space "
                         << style::Enum(address_space) << " here";
@@ -661,6 +657,22 @@ bool Validator::AddressSpaceLayout(const
                     return false;
                 }
             }
+
+            // If an alignment was explicitly specified, we need to validate that it satisfies the
+            // alignment requirement of the address space.
+            auto* align_attr =
+                ast::GetAttribute<ast::StructMemberAlignAttribute>(m->Declaration()->attributes);
+            if (align_attr && !enabled_extensions_.Contains(
+                                  wgsl::Extension::kChromiumInternalRelaxedUniformLayout)) {
+                auto align = sem_.GetVal(align_attr->expr)->ConstantValue()->ValueAs<uint32_t>();
+                if (align % required_align != 0) {
+                    AddError(align_attr->expr->source)
+                        << "alignment must be a multiple of " << style::Literal(required_align)
+                        << " bytes for the " << style::Enum(address_space) << " address space";
+                    note_usage();
+                    return false;
+                }
+            }
         }
     }
 
