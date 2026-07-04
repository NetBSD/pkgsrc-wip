$NetBSD$

Add NetBSD support.

--- src/collection/disks/netbsd.rs.orig	2026-07-04 15:51:19.498613258 +0000
+++ src/collection/disks/netbsd.rs
@@ -0,0 +1,57 @@
+//! Disk stats for NetBSD using sysinfo.
+
+use rustc_hash::FxHashMap as HashMap;
+
+use super::{DiskHarvest, IoData, IoHarvest, keep_disk_entry};
+use crate::collection::{DataCollector, error::CollectionResult};
+
+pub fn get_io_usage(collector: &DataCollector) -> CollectionResult<IoHarvest> {
+    let io_harvest: HashMap<String, Option<IoData>> = collector
+        .sys
+        .disks
+        .iter()
+        .map(|disk| {
+            let usage = disk.usage();
+            (
+                disk.mount_point().to_string_lossy().to_string(),
+                Some(IoData {
+                    read_bytes: usage.read_bytes,
+                    write_bytes: usage.written_bytes,
+                }),
+            )
+        })
+        .collect();
+
+    Ok(io_harvest)
+}
+
+pub fn get_disk_usage(collector: &DataCollector) -> CollectionResult<Vec<DiskHarvest>> {
+    let disk_filter = &collector.filters.disk_filter;
+    let mount_filter = &collector.filters.mount_filter;
+
+    let mut disks = Vec::new();
+
+    for disk in collector.sys.disks.iter() {
+        let name = disk.name().to_string_lossy().to_string();
+        let mount_point = disk.mount_point().to_string_lossy().to_string();
+
+        if !keep_disk_entry(&name, &mount_point, disk_filter, mount_filter) {
+            continue;
+        }
+
+        let total_space = Some(disk.total_space());
+        let available_space = Some(disk.available_space());
+        let used_space = total_space
+            .and_then(|total| available_space.map(|avail| total.saturating_sub(avail)));
+
+        disks.push(DiskHarvest {
+            name,
+            mount_point,
+            free_space: available_space,
+            used_space,
+            total_space,
+        });
+    }
+
+    Ok(disks)
+}
