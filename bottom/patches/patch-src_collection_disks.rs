$NetBSD$

Add NetBSD support.

--- src/collection/disks.rs.orig	2026-06-22 06:25:54.000000000 +0000
+++ src/collection/disks.rs
@@ -25,6 +25,10 @@ cfg_select! {
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
@@ -87,7 +91,7 @@ cfg_select! {
             Ok(io_hash)
         }
     }
-    not(target_os = "freebsd") => {
+    not(any(target_os = "freebsd", target_os = "netbsd")) => {
         use crate::collection::DataCollector;
         pub fn get_io_usage(_collector: &DataCollector) -> anyhow::Result<IoHarvest> {
             anyhow::bail!("Unsupported OS");
