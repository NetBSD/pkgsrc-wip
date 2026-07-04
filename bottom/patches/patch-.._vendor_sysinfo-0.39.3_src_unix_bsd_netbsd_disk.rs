$NetBSD$

Extract device name correctly.

Patch not yet upstreamed.

--- ../vendor/sysinfo-0.39.3/src/unix/bsd/netbsd/disk.rs.orig	2026-07-04 11:34:38.984915123 +0000
+++ ../vendor/sysinfo-0.39.3/src/unix/bsd/netbsd/disk.rs
@@ -223,7 +223,15 @@ impl GetValues for DiskInner {
 }
 
 fn same_name(dev_id: &[c_char], drive_name: &[c_char]) -> bool {
+    // NetBSD iostats returns device names without partition letters (e.g., "ld0")
+    // but mount points use full device names with partitions (e.g., "ld0a").
+    // We need to match by checking if dev_id starts with drive_name.
+
     for (c1, c2) in dev_id.iter().zip(drive_name.iter()) {
+        // Stop comparison at null terminator in drive_name
+        if *c2 == 0 {
+            return true;
+        }
         if c1 != c2 {
             return false;
         }
@@ -347,10 +355,14 @@ pub unsafe fn get_all_list(
         if mount_point == "/boot/efi" {
             continue;
         }
-        let name = if mount_point == "/" {
-            OsString::from("root")
-        } else {
-            OsString::from(mount_point)
+
+        // Extract device name from f_mntfromname (e.g., "/dev/ld0a")
+        let name = match c_buf_to_utf8_str(&fs_info.f_mntfromname) {
+            Some(device_name) => OsString::from(device_name),
+            None => {
+                sysinfo_debug!("Cannot get disk device name, ignoring it.");
+                continue;
+            }
         };
 
         if let Some(disk) = container.iter_mut().find(|d| {
