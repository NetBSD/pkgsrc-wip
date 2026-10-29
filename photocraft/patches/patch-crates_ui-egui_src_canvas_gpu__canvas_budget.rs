$NetBSD$

Detect physical memory on NetBSD; otherwise 16 GB is assumed when sizing
the GPU compositor budget.

--- crates/ui-egui/src/canvas/gpu_canvas/budget.rs.orig
+++ crates/ui-egui/src/canvas/gpu_canvas/budget.rs
@@ -114,7 +114,13 @@
     winsafe::GlobalMemoryStatusEx().map(|m| m.ullTotalPhys).ok().filter(|b| *b > 0)
 }
 
-#[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd", windows)))]
+#[cfg(target_os = "netbsd")]
+fn detect_physical_memory() -> Option<u64> {
+    let out = std::process::Command::new("/sbin/sysctl").args(["-n", "hw.physmem64"]).output().ok()?;
+    String::from_utf8(out.stdout).ok()?.trim().parse().ok()
+}
+
+#[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd", target_os = "netbsd", windows)))]
 fn detect_physical_memory() -> Option<u64> {
     None
 }
