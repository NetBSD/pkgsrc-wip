$NetBSD$

Implement basic disk parsing for NetBSD.

--- src/collection/disks/netbsd.rs.orig	2026-06-24 12:25:02.110444670 +0000
+++ src/collection/disks/netbsd.rs
@@ -0,0 +1,50 @@
+//! Disk stats for NetBSD, parsed from `df -P`.
+
+use rustc_hash::FxHashMap as HashMap;
+
+use super::{DiskHarvest, IoHarvest, keep_disk_entry};
+use crate::collection::{DataCollector, error::CollectionResult};
+
+pub fn get_io_usage(collector: &DataCollector) -> CollectionResult<IoHarvest> {
+    Ok(HashMap::default())
+}
+
+pub fn get_disk_usage(collector: &DataCollector) -> CollectionResult<Vec<DiskHarvest>> {
+    let disk_filter = &collector.filters.disk_filter;
+    let mount_filter = &collector.filters.mount_filter;
+
+    let output = std::process::Command::new("df")
+        .args(["-P", "-l"])
+        .output()?;
+
+    let stdout = String::from_utf8_lossy(&output.stdout);
+    let mut disks = Vec::new();
+
+    for line in stdout.lines().skip(1) {
+        let fields: Vec<&str> = line.split_whitespace().collect();
+        // POSIX df -P: Filesystem 1K-blocks Used Available Capacity% Mounted-on
+        if fields.len() < 6 {
+            continue;
+        }
+        let name = fields[0].to_string();
+        let mount_point = fields[5].to_string();
+
+        if !keep_disk_entry(&name, &mount_point, disk_filter, mount_filter) {
+            continue;
+        }
+
+        let total_space = fields[1].parse::<u64>().ok().map(|b| b * 1024);
+        let used_space = fields[2].parse::<u64>().ok().map(|b| b * 1024);
+        let free_space = fields[3].parse::<u64>().ok().map(|b| b * 1024);
+
+        disks.push(DiskHarvest {
+            name,
+            mount_point,
+            free_space,
+            used_space,
+            total_space,
+        });
+    }
+
+    Ok(disks)
+}
