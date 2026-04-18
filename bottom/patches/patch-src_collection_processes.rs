$NetBSD$

Enable process info collection for NetBSD.

--- src/collection/processes.rs.orig	2026-04-18 01:11:47.496423789 +0000
+++ src/collection/processes.rs
@@ -171,7 +171,7 @@ impl DataCollector {
                     self,
                     time_diff,
                 )
-            } else if #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "windows", target_os = "android", target_os = "ios"))] {
+            } else if #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "macos", target_os = "windows", target_os = "android", target_os = "ios"))] {
                 sysinfo_process_data(self)
             } else {
                 Err(crate::collection::error::CollectionError::Unsupported)
