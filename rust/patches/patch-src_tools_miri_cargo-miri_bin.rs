$NetBSD$

https://github.com/rust-lang/miri/commit/e5b340017e39dc90e3f9cf9966244faa585321b5

--- src/tools/miri/cargo-miri/bin.rs.orig	2021-06-22 08:33:05.000000000 +0000
+++ src/tools/miri/cargo-miri/bin.rs
@@ -6,6 +6,7 @@ use std::io::{self, BufRead, BufReader, 
 use std::ops::Not;
 use std::path::{Path, PathBuf};
 use std::process::Command;
+use std::fmt::{Write as _};
 
 use serde::{Deserialize, Serialize};
 
@@ -90,12 +91,13 @@ fn show_help() {
 }
 
 fn show_version() {
-    println!(
-        "miri {} ({} {})",
-        env!("CARGO_PKG_VERSION"),
-        env!("VERGEN_GIT_SHA_SHORT"),
-        env!("VERGEN_GIT_COMMIT_DATE")
-    );
+    let mut version = format!("miri {}", env!("CARGO_PKG_VERSION"));
+     // Only use `option_env` on vergen variables to ensure the build succeeds
+     // when vergen failed to find the git info.
+     if let Some(sha) = option_env!("VERGEN_GIT_SHA_SHORT") {
+         write!(&mut version, " ({} {})", sha, option_env!("VERGEN_GIT_COMMIT_DATE").unwrap()).unwrap();
+     }
+     println!("{}", version);
 }
 
 fn show_error(msg: String) -> ! {
