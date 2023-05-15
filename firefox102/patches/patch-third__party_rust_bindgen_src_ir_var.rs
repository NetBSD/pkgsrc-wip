$NetBSD$

rust-bindgen upstream (#2338 and #2319), Self
Updates the bundled rust-bindgen crate to be compatible
with Clang/LLVM 16.

clang: Detect anonymous items explicitly, rather than relying on empty names.
In Clang 16, anonymous items may return names like `(anonymous union at ...)`
rather than emoty names.
The right way to detect them is using clang_Cursor_isAnonymous.
Fixes https://github.com/rust-lang/rust-bindgen/issues/2312
Closes https://github.com/rust-lang/rust-bindgen/pull/2316

ir: Don't crash with built-in unexposed types from libclang.
This fixes https://github.com/rust-lang/rust-bindgen/issues/2325

The issue is that `__bf16` is not exposed at all by libclang, which
causes us to crash. It's a bit of a shame libclang doesn't expose it but
there's no rust equivalent I think, so this should be ok for now.

Unfortunately no test because the header crashes older clang versions.

--- third_party/rust/bindgen/src/ir/var.rs.orig	2023-05-13 01:44:21.240433172 +0200
+++ third_party/rust/bindgen/src/ir/var.rs	2023-05-13 01:47:51.806534744 +0200
@@ -301,11 +301,11 @@
                 let ty = match Item::from_ty(&ty, cursor, None, ctx) {
                     Ok(ty) => ty,
                     Err(e) => {
-                        assert_eq!(
-                            ty.kind(),
-                            CXType_Auto,
+                        assert!(
+                        matches!(ty.kind(), CXType_Auto | CXType_Unexposed),
                             "Couldn't resolve constant type, and it \
-                             wasn't an nondeductible auto type!"
+                             wasn't an nondeductible auto type or unexposed \
+                             type!"
                         );
                         return Err(e);
                     }
