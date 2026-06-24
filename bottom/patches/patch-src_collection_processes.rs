$NetBSD$

Enable process info collection for NetBSD.

--- src/collection/processes.rs.orig	2026-06-24 10:52:04.504828582 +0000
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
