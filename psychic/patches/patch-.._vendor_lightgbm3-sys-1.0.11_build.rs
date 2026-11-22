$NetBSD$

Allow linking on NetBSD.

--- ../vendor/lightgbm3-sys-1.0.11/build.rs.orig	2026-11-22 10:18:06.994004271 +0000
+++ ../vendor/lightgbm3-sys-1.0.11/build.rs
@@ -77,7 +77,7 @@ fn main() {
     // link to appropriate C++ lib
     if target.contains("apple") {
         println!("cargo:rustc-link-lib=c++");
-    } else if target.contains("linux") {
+    } else if target.contains("linux") || target.contains("netbsd") {
         println!("cargo:rustc-link-lib=stdc++");
     }
     #[cfg(feature = "openmp")]
