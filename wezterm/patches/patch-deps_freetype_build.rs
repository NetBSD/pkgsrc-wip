$NetBSD$

pkgsrc-provided git checkouts don't include the .git directory.

--- deps/freetype/build.rs.orig	2026-01-17 15:44:28.000000000 +0000
+++ deps/freetype/build.rs
@@ -10,10 +10,6 @@ fn zlib() {
 }
 
 fn zlib() {
-    if !Path::new("zlib/.git").exists() {
-        git_submodule_update();
-    }
-
     let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
 
     let mut cfg = new_build();
@@ -47,10 +43,6 @@ fn libpng() {
 }
 
 fn libpng() {
-    if !Path::new("libpng/.git").exists() {
-        git_submodule_update();
-    }
-
     let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
 
     let mut cfg = new_build();
@@ -102,7 +94,7 @@ fn libpng() {
 
     fs::write(
         build_dir.join("pnglibconf.h"),
-        fs::read_to_string("libpng/scripts/pnglibconf.h.prebuilt").unwrap(),
+        fs::read_to_string("libpng/pnglibconf.h.prebuilt").unwrap(),
     )
     .unwrap();
 
@@ -110,10 +102,6 @@ fn freetype() {
 }
 
 fn freetype() {
-    if !Path::new("freetype2/.git").exists() {
-        git_submodule_update();
-    }
-
     let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());
 
     let mut cfg = new_build();
