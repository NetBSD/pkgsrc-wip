$NetBSD$

Add NetBSD support.

--- src/collection/processes.rs.orig	2026-06-22 06:25:54.000000000 +0000
+++ src/collection/processes.rs
@@ -181,7 +181,7 @@ impl DataCollector {
                     time_diff,
                 )
             }
-            any(target_os = "freebsd", target_os = "macos", target_os = "windows", target_os = "android", target_os = "ios") => {
+            any(target_os = "freebsd", target_os = "macos", target_os = "netbsd", target_os = "windows", target_os = "android", target_os = "ios") => {
                 sysinfo_process_data(self)
             }
             _ => {
@@ -226,7 +226,7 @@ pub(super) fn process_status_str(status:
                 _ => "Unknown",
             }
         }
-        target_os = "freebsd" => {
+        any(target_os = "freebsd", target_os = "netbsd") => {
             match status {
                 ProcessStatus::Idle => "Idle",
                 ProcessStatus::Run => "Runnable",
@@ -235,6 +235,8 @@ pub(super) fn process_status_str(status:
                 ProcessStatus::Zombie => "Zombie",
                 ProcessStatus::Dead => "Dead",
                 ProcessStatus::LockBlocked => "LockBlocked",
+                ProcessStatus::Suspended => "Suspended",
+                ProcessStatus::Tracing => "Tracing",
                 _ => "Unknown",
             }
         }
