$NetBSD$

Extract proper read / write statistics.

Patch not yet upstreamed.

--- ../vendor/sysinfo-0.39.3/src/unix/bsd/netbsd/process.rs.orig	2026-07-04 11:34:38.991541351 +0000
+++ ../vendor/sysinfo-0.39.3/src/unix/bsd/netbsd/process.rs
@@ -44,10 +44,10 @@ impl ProcessInner {
 
     pub(crate) fn disk_usage(&self) -> DiskUsage {
         DiskUsage {
-            written_bytes: 0,       // self.written_bytes.saturating_sub(self.old_written_bytes),
-            total_written_bytes: 0, // self.written_bytes,
-            read_bytes: 0,          // self.read_bytes.saturating_sub(self.old_read_bytes),
-            total_read_bytes: 0,    // self.read_bytes,
+            written_bytes: self.written_bytes.saturating_sub(self.old_written_bytes),
+            total_written_bytes: self.written_bytes,
+            read_bytes: self.read_bytes.saturating_sub(self.old_read_bytes),
+            total_read_bytes: self.read_bytes,
         }
     }
 
@@ -123,9 +123,10 @@ fn update_proc_info(
 
     if refresh_kind.disk_usage() {
         proc_.old_read_bytes = proc_.read_bytes;
-        proc_.read_bytes = kproc.p_uru_inblock as _;
+        // NetBSD reports I/O in 512-byte blocks, convert to bytes
+        proc_.read_bytes = (kproc.p_uru_inblock as u64) * 512;
         proc_.old_written_bytes = proc_.written_bytes;
-        proc_.written_bytes = kproc.p_uru_oublock as _;
+        proc_.written_bytes = (kproc.p_uru_oublock as u64) * 512;
     }
 
     if refresh_kind.cpu() {
