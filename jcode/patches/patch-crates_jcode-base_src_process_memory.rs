$NetBSD$

Report process memory on NetBSD.

Memory accounting was gated on Linux only, so NetBSD silently fell back to
a stub returning all-None and every memory figure read as zero. Dispatch to
the new NetBSD implementation instead.

--- crates/jcode-base/src/process_memory.rs.orig
+++ crates/jcode-base/src/process_memory.rs
@@ -177,7 +177,10 @@ pub fn snapshot_with_source(source: impl Into<String>) -> ProcessMemorySnapshot
     snapshot
 }
 
-#[cfg(not(target_os = "linux"))]
+#[cfg(target_os = "netbsd")]
+pub use crate::process_memory_netbsd::snapshot_with_source;
+
+#[cfg(not(any(target_os = "linux", target_os = "netbsd")))]
 pub fn snapshot_with_source(source: impl Into<String>) -> ProcessMemorySnapshot {
     let source = source.into();
     logging::debug(&format!(
@@ -664,7 +667,7 @@ fn parse_retention_trim_threshold(value: Option<&str>) -> u64 {
     }
 }
 
-fn record_snapshot(source: String, snapshot: ProcessMemorySnapshot) {
+pub(crate) fn record_snapshot(source: String, snapshot: ProcessMemorySnapshot) {
     let Ok(mut history) = memory_history().lock() else {
         logging::error("process memory history lock poisoned; dropping snapshot");
         return;
