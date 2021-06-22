$NetBSD$

https://github.com/rust-lang/miri/commit/e5b340017e39dc90e3f9cf9966244faa585321b5

--- src/tools/miri/cargo-miri/build.rs.orig	2021-06-22 08:31:31.000000000 +0000
+++ src/tools/miri/cargo-miri/build.rs
@@ -7,5 +7,5 @@ fn main() {
     let mut gen_config = vergen::Config::default();
     *gen_config.git_mut().sha_kind_mut() = vergen::ShaKind::Short;
     *gen_config.git_mut().commit_timestamp_kind_mut() = vergen::TimestampKind::DateOnly;
-    vergen(gen_config).expect("Unable to generate vergen keys!");
+    vergen(gen_config).ok(); // Ignore failure (in case we are built outside a git repo)
 }
