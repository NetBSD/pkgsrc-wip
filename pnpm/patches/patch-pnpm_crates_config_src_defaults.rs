$NetBSD$

    Support NetBSD.

--- pnpm/crates/config/src/defaults.rs.orig	2026-08-12 13:26:39.996833944 +0000
+++ pnpm/crates/config/src/defaults.rs
@@ -99,7 +99,7 @@ where
 
     // <https://doc.rust-lang.org/std/env/consts/constant.OS.html>
     match env::consts::OS {
-        "linux" => home_dir.join(".local/share/pnpm/store").into(),
+        "linux" | "netbsd" => home_dir.join(".local/share/pnpm/store").into(),
         "macos" => home_dir.join("Library/pnpm/store").into(),
         _ => panic!("unsupported operating system: {}", env::consts::OS),
     }
