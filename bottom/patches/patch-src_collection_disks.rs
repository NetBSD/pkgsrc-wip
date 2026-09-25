$NetBSD$

Add NetBSD support.

--- src/collection/disks.rs.orig	2026-09-22 06:56:15.000000000 +0200
+++ src/collection/disks.rs
@@ -26,6 +26,10 @@
         mod unix;
         pub(crate) use self::unix::*;
     }
+   target_os = "netbsd" => {
+        mod netbsd;
+        pub(crate) use self::netbsd::*;
+    }
     _ => {
         mod other;
         pub(crate) use self::other::*;
@@ -88,7 +92,7 @@
             Ok(io_hash)
         }
     }
-    not(target_os = "freebsd") => {
+    not(any(target_os = "freebsd", target_os = "netbsd")) => {
         use crate::collection::DataCollector;
         pub fn get_io_usage(_collector: &DataCollector) -> anyhow::Result<IoHarvest> {
             anyhow::bail!("Unsupported OS");
