$NetBSD$

Detect physical memory on NetBSD; otherwise the cache budget falls back
to a fixed 1.5 GiB cap instead of a quarter of RAM.

--- crates/engine/src/memory.rs.orig	2026-10-08 09:57:52.619463993 +0000
+++ crates/engine/src/memory.rs
@@ -49,7 +49,12 @@ fn total_ram() -> Option<usize> {
         let out = std::process::Command::new("/sbin/sysctl").args(["-n", "hw.physmem"]).output().ok()?;
         String::from_utf8_lossy(&out.stdout).trim().parse().ok()
     }
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "freebsd")))]
+    #[cfg(target_os = "netbsd")]
+    {
+        let out = std::process::Command::new("/sbin/sysctl").args(["-n", "hw.physmem64"]).output().ok()?;
+        String::from_utf8_lossy(&out.stdout).trim().parse().ok()
+    }
+    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "freebsd", target_os = "netbsd")))]
     {
         None
     }
