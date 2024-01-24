$NetBSD$

Add unmerged pull request
https://github.com/darfink/region-rs/pull/14/

--- ../vendor/region-3.0.0/src/os/mod.rs.orig	2024-01-24 09:23:06.401589627 +0000
+++ ../vendor/region-3.0.0/src/os/mod.rs
@@ -39,3 +39,9 @@ mod openbsd;
 
 #[cfg(target_os = "openbsd")]
 pub use self::openbsd::*;
+
+#[cfg(target_os = "netbsd")]
+mod netbsd;
+
+#[cfg(target_os = "netbsd")]
+pub use self::netbsd::*;
