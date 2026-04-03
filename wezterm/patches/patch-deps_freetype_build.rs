$NetBSD$

Use dependencies from pkgsrc.

--- deps/freetype/build.rs.orig	2026-01-17 15:44:28.000000000 +0000
+++ deps/freetype/build.rs
@@ -238,6 +238,11 @@ fn main() {
 }
 
 fn main() {
+    // Use system libraries
+    println!("cargo:rustc-link-lib=freetype");
+    println!("cargo:rustc-link-lib=png");
+    println!("cargo:rustc-link-lib=z");
+    return;
     zlib();
     libpng();
     freetype();
