$NetBSD$

Add NetBSD support.

--- src/collection.rs.orig	2026-09-22 06:56:15.000000000 +0200
+++ src/collection.rs
@@ -137,13 +137,20 @@
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
@@ -371,7 +378,7 @@
                 }
             }
 
-            #[cfg(any(target_os = "windows", target_os = "freebsd"))]
+            #[cfg(any(target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
             if self.widgets_to_harvest.use_disk {
                 if self.should_run_less_routine_tasks {
                     self.sys.disks.refresh(true);
