$NetBSD$

Use spawn, not fork, on NetBSD: create_pty_with_fork never forwards shell args
such as --login to execvp.  macOS already does this.

--- rio-backend/src/config/defaults.rs.orig
+++ rio-backend/src/config/defaults.rs
@@ -60,12 +60,12 @@
 
 #[inline]
 pub fn default_use_fork() -> bool {
-    #[cfg(target_os = "macos")]
+    #[cfg(any(target_os = "macos", target_os = "netbsd"))]
     {
         false
     }
 
-    #[cfg(not(target_os = "macos"))]
+    #[cfg(not(any(target_os = "macos", target_os = "netbsd")))]
     {
         true
     }
