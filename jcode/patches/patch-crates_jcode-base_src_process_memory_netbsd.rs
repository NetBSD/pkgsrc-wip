$NetBSD$

Add the NetBSD process-memory probes.

NetBSD's /proc/self/status is the BSD single-line format and carries none of
the VmRSS-style keys the Linux implementation parses, and there is no
smaps_rollup, so the PSS breakdown has no equivalent and stays None.

What is available: /proc/self/statm is Linux-compatible, so resident and
virtual size come from there, peak RSS from getrusage(), and the thread count
from /proc/self/task. statm is parsed positionally rather than by filtering
out unparseable fields, since silently skipping a field would shift the
resident size into the virtual-size slot.

--- crates/jcode-base/src/process_memory_netbsd.rs.orig
+++ crates/jcode-base/src/process_memory_netbsd.rs
@@ -0,0 +1,137 @@
+//! NetBSD process-memory probes.
+//!
+//! NetBSD's procfs is only partly Linux-shaped. `/proc/self/statm` is
+//! Linux-compatible (whitespace-separated page counts), but `/proc/self/status`
+//! is the BSD single-line format with none of the `VmRSS:`-style keys the Linux
+//! implementation parses, and there is no `smaps_rollup`, so the PSS/dirty/clean
+//! breakdown has no equivalent here and callers see `None` for it.
+//!
+//! What is available: RSS and virtual size from `statm`, peak RSS from
+//! `getrusage`, and the thread count from `/proc/self/task`.
+
+use super::process_memory::{ProcessMemorySnapshot, allocator_info, record_snapshot};
+use crate::logging;
+
+/// NetBSD implementation of
+/// [`crate::process_memory::snapshot_with_source`]. Lives here rather than in
+/// the shared module so the platform-specific probes and their doc stay next
+/// to each other.
+pub fn snapshot_with_source(source: impl Into<String>) -> ProcessMemorySnapshot {
+    let source = source.into();
+    let (virtual_bytes, rss_bytes) = size_and_rss_bytes();
+    let snapshot = ProcessMemorySnapshot {
+        rss_bytes,
+        peak_rss_bytes: peak_rss_bytes(),
+        virtual_bytes,
+        thread_count: thread_count(),
+        main_stack_bytes: None,
+        os: None,
+        allocator: allocator_info(),
+    };
+    logging::debug(&format!(
+        "process memory snapshot source={source} rss={:?} peak_rss={:?} virtual={:?} allocator={}",
+        snapshot.rss_bytes,
+        snapshot.peak_rss_bytes,
+        snapshot.virtual_bytes,
+        snapshot.allocator.name
+    ));
+    record_snapshot(source, snapshot.clone());
+    snapshot
+}
+
+/// Page size for converting `statm`'s page counts to bytes.
+fn page_size() -> u64 {
+    // SAFETY: `sysconf` is thread-safe and takes no pointer arguments.
+    let raw = unsafe { libc::sysconf(libc::_SC_PAGESIZE) };
+    if raw > 0 { raw as u64 } else { 4096 }
+}
+
+/// `(virtual_bytes, rss_bytes)` from `/proc/self/statm`, whose first two
+/// fields are total program size and resident set size in pages.
+fn size_and_rss_bytes() -> (Option<u64>, Option<u64>) {
+    let Ok(statm) = std::fs::read_to_string("/proc/self/statm") else {
+        return (None, None);
+    };
+    let page_size = page_size();
+    // Parse positionally rather than filtering out unparseable fields: these
+    // are fixed positions, so silently skipping field 0 would promote the RSS
+    // value into the size slot instead of reporting the field as unknown.
+    let mut fields = statm.split_whitespace();
+    let mut next_bytes = || -> Option<u64> {
+        match fields.next()?.parse::<u64>() {
+            Ok(pages) => Some(pages.saturating_mul(page_size)),
+            Err(_) => None,
+        }
+    };
+    let size = next_bytes();
+    let rss = next_bytes();
+    (size, rss)
+}
+
+/// Peak RSS via `getrusage(RUSAGE_SELF)`. NetBSD reports `ru_maxrss` in
+/// kilobytes.
+fn peak_rss_bytes() -> Option<u64> {
+    // SAFETY: `usage` is a valid, fully-owned `rusage` that the kernel fills in;
+    // the return code is checked before any field is read.
+    let mut usage: libc::rusage = unsafe { std::mem::zeroed() };
+    let rc = unsafe { libc::getrusage(libc::RUSAGE_SELF, &mut usage) };
+    if rc != 0 {
+        return None;
+    }
+    match u64::try_from(usage.ru_maxrss) {
+        Ok(kb) => Some(kb.saturating_mul(1024)),
+        // A negative ru_maxrss is not meaningful; report "unknown" rather than
+        // a wrapped value.
+        Err(_) => None,
+    }
+}
+
+/// Thread count from `/proc/self/task`, which lists one entry per LWP.
+fn thread_count() -> Option<u64> {
+    let Ok(entries) = std::fs::read_dir("/proc/self/task") else {
+        return None;
+    };
+    let count = entries.filter(|entry| entry.is_ok()).count() as u64;
+    (count > 0).then_some(count)
+}
+
+#[cfg(test)]
+mod tests {
+    use super::*;
+
+    /// The NetBSD snapshot reads `/proc/self/statm`, `getrusage`, and
+    /// `/proc/self/task` rather than Linux's `/proc/self/status`. Assert it
+    /// returns live, self-consistent numbers: the whole point of this path is
+    /// that the previous fallback silently returned all-`None` defaults, which
+    /// no type-level check would catch.
+    #[test]
+    fn netbsd_snapshot_reports_live_process_memory() {
+        let snapshot = snapshot_with_source("test");
+
+        let rss = snapshot
+            .rss_bytes
+            .expect("rss should be readable via statm");
+        assert!(
+            rss > 1024 * 1024,
+            "a running test process should hold more than 1MiB, got {rss}"
+        );
+
+        let virt = snapshot
+            .virtual_bytes
+            .expect("virtual size should be readable via statm");
+        assert!(
+            virt >= rss,
+            "virtual size {virt} should be at least rss {rss}"
+        );
+
+        let peak = snapshot
+            .peak_rss_bytes
+            .expect("peak rss should be readable via getrusage");
+        assert!(peak >= rss, "peak rss {peak} should be at least rss {rss}");
+
+        let threads = snapshot
+            .thread_count
+            .expect("thread count should be readable via /proc/self/task");
+        assert!(threads >= 1, "expected at least one thread, got {threads}");
+    }
+}
