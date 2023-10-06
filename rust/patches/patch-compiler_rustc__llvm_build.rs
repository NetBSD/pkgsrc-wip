$NetBSD$

Fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

Pick up -latomic tweak from
https://github.com/rust-lang/rust/issues/104220
and
https://github.com/rust-lang/rust/pull/104572

--- compiler/rustc_llvm/build.rs.orig	2023-10-03 02:52:17.000000000 +0000
+++ compiler/rustc_llvm/build.rs
@@ -249,12 +249,21 @@ fn main() {
     {
         // 32-bit targets need to link libatomic.
         println!("cargo:rustc-link-lib=atomic");
+        println!("cargo:rustc-link-lib=z");
     } else if target.contains("windows-gnu") {
         println!("cargo:rustc-link-lib=shell32");
         println!("cargo:rustc-link-lib=uuid");
     } else if target.contains("haiku") || target.contains("darwin") {
         println!("cargo:rustc-link-lib=z");
     } else if target.contains("netbsd") {
+        // We build for i486, and then need -latomic for 64-bit atomics
+        if target.starts_with("i386")
+           || target.starts_with("i486")
+           || target.starts_with("i586")
+           || target.starts_with("i686")
+        {
+          println!("cargo:rustc-link-lib=atomic");
+        }
         println!("cargo:rustc-link-lib=z");
         println!("cargo:rustc-link-lib=execinfo");
     }
@@ -343,7 +352,13 @@ fn main() {
         "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
-        "stdc++_p"
+	if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            "c++_pic"
+	} else {
+            "stdc++_pic"
+	}
+    } else if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+	"c++"
     } else if llvm_use_libcxx.is_some() {
         "c++"
     } else {
