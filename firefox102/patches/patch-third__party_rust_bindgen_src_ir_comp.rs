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

--- third_party/rust/bindgen/src/ir/comp.rs.orig	2023-05-13 03:05:52.709272405 +0200
+++ third_party/rust/bindgen/src/ir/comp.rs	2023-05-13 03:08:36.774355149 +0200
@@ -1372,7 +1372,7 @@
 
                     // A declaration of an union or a struct without name could
                     // also be an unnamed field, unfortunately.
-                    if cur.spelling().is_empty() &&
+                    if cur.is_anonymous() &&
                         cur.kind() != CXCursor_EnumDecl
                     {
                         let ty = cur.cur_type();
