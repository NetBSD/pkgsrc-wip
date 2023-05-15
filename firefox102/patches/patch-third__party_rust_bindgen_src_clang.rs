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

--- third_party/rust/bindgen/src/clang.rs.orig	2023-05-13 01:13:19.851639954 +0200
+++ third_party/rust/bindgen/src/clang.rs	2023-05-13 01:15:51.240925636 +0200
@@ -54,6 +54,11 @@
         unsafe { clang_isDeclaration(self.kind()) != 0 }
     }
 
+    /// Is this cursor's referent an anonymous record or so?
+    pub fn is_anonymous(&self) -> bool {
+        unsafe { clang_Cursor_isAnonymous(self.x) != 0 }
+    }
+
     /// Get this cursor's referent's spelling.
     pub fn spelling(&self) -> String {
         unsafe { cxstring_into_string(clang_getCursorSpelling(self.x)) }
