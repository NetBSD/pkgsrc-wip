$NetBSD$

Detect physical memory on NetBSD; otherwise 16 GB is assumed when sizing
the GPU compositor budget.

--- crates/ui-egui/src/gpu_canvas.rs.orig	2026-10-08 09:07:59.968421994 +0000
+++ crates/ui-egui/src/gpu_canvas.rs
@@ -1062,7 +1062,13 @@ fn detect_physical_memory() -> Option<u64> {
     String::from_utf8(out.stdout).ok()?.trim().parse().ok()
 }
 
-#[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd")))]
+#[cfg(target_os = "netbsd")]
+fn detect_physical_memory() -> Option<u64> {
+    let out = std::process::Command::new("/sbin/sysctl").args(["-n", "hw.physmem64"]).output().ok()?;
+    String::from_utf8(out.stdout).ok()?.trim().parse().ok()
+}
+
+#[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd", target_os = "netbsd")))]
 fn detect_physical_memory() -> Option<u64> {
     None
 }
