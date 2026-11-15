$NetBSD$

* Add FreeBSD support

--- src/rust/build.rs.orig	2026-09-30 22:46:18.000000000 +0000
+++ src/rust/build.rs
@@ -77,7 +77,9 @@ fn main() {
         println!("cargo:rustc-link-search=native={}", webrtc_dir);
         println!("cargo:rustc-link-lib=webrtc");
 
-        if cfg!(target_os = "macos") {
+        if cfg!(target_os = "freebsd") {
+            println!("cargo:rustc-link-lib=dylib=c++");
+        } else if cfg!(target_os = "macos") {
             println!("cargo:rustc-link-lib=dylib=c++");
             println!("cargo:rustc-link-lib=framework=Foundation");
             println!("cargo:rustc-link-lib=framework=CoreAudio");
