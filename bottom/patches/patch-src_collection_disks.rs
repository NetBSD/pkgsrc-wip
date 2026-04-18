$NetBSD$

Disable catch-all for disks in NetBSD.

--- src/collection/disks.rs.orig	2026-04-18 02:12:01.054885511 +0000
+++ src/collection/disks.rs
@@ -21,6 +21,9 @@ cfg_if! {
     } else if #[cfg(target_os = "macos")] {
         mod unix;
         pub(crate) use self::unix::*;
+    } else if #[cfg(target_os = "netbsd")] {
+        mod netbsd;
+        pub(crate) use self::netbsd::*;
     } else {
         mod other;
         pub(crate) use self::other::*;
@@ -79,7 +82,7 @@ cfg_if! {
 
             Ok(io_hash)
         }
-    } else if #[cfg(not(target_os = "freebsd"))] {
+    } else if #[cfg(not(any(target_os = "freebsd", target_os = "netbsd")))] {
         pub fn get_io_usage() -> anyhow::Result<IoHarvest> {
             anyhow::bail!("Unsupported OS");
         }
