$NetBSD$

Use spawn (not fork) on NetBSD to ensure configured shell args (e.g.
--login) are actually passed when launching the PTY shell.  The fork path
(create_pty_with_fork) never forwards args to execvp; the spawn path
(create_pty_with_spawn) does.  macOS already uses spawn for the same reason.

--- rio-backend/src/config/defaults.rs.orig
+++ rio-backend/src/config/defaults.rs
@@ -60,11 +60,11 @@
 
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
