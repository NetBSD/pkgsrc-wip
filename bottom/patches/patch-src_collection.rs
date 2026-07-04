$NetBSD$

Add NetBSD support.

--- src/collection.rs.orig	2026-07-04 06:55:31.000000000 +0000
+++ src/collection.rs
@@ -136,13 +136,20 @@ impl Default for SysinfoSource {
     fn default() -> Self {
         use sysinfo::*;
 
+        #[cfg(not(any(target_os = "linux", target_os = "macos")))]
+        let disks = {
+            let mut d = Disks::new();
+            d.refresh(true);
+            d
+        };
+
         Self {
             system: System::new(),
             network: Networks::new(),
             #[cfg(not(target_os = "linux"))]
             temps: Components::new(),
             #[cfg(not(any(target_os = "linux", target_os = "macos")))]
-            disks: Disks::new(),
+            disks,
             #[cfg(target_os = "windows")]
             users: Users::new(),
         }
@@ -357,7 +364,7 @@ impl DataCollector {
                 }
             }
 
-            #[cfg(any(target_os = "windows", target_os = "freebsd"))]
+            #[cfg(any(target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
             if self.widgets_to_harvest.use_disk {
                 if self.should_run_less_routine_tasks {
                     self.sys.disks.refresh(true);
