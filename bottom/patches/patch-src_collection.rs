$NetBSD$

Add NetBSD support.

--- src/collection.rs.orig	2026-06-22 06:25:54.000000000 +0000
+++ src/collection.rs
@@ -357,7 +357,7 @@ impl DataCollector {
                 }
             }
 
-            #[cfg(any(target_os = "windows", target_os = "freebsd"))]
+            #[cfg(any(target_os = "windows", target_os = "freebsd", target_os = "netbsd"))]
             if self.widgets_to_harvest.use_disk {
                 if self.should_run_less_routine_tasks {
                     self.sys.disks.refresh(true);
