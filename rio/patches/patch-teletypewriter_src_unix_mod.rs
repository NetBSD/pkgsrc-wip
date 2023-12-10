$NetBSD$

Add NetBSD support.

--- teletypewriter/src/unix/mod.rs.orig	2023-12-10 19:54:05.309009040 +0000
+++ teletypewriter/src/unix/mod.rs
@@ -29,7 +29,7 @@ use std::sync::Arc;
 const TIOCSWINSZ: libc::c_ulong = 0x5414;
 #[cfg(all(target_os = "linux", target_env = "musl"))]
 const TIOCSWINSZ: libc::c_int = 0x5414;
-#[cfg(target_os = "freebsd")]
+#[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
 const TIOCSWINSZ: libc::c_ulong = 0x80087467;
 #[cfg(target_os = "macos")]
 const TIOCSWINSZ: libc::c_ulong = 2148037735;
@@ -288,7 +288,7 @@ pub fn create_termp(utf8: bool) -> libc:
         c_line: 0,
     };
 
-    #[cfg(any(target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     let mut term = libc::termios {
         c_iflag: libc::ICRNL | libc::IXON | libc::IXANY | libc::IMAXBEL | libc::BRKINT,
         c_oflag: libc::OPOST | libc::ONLCR,
@@ -306,7 +306,7 @@ pub fn create_termp(utf8: bool) -> libc:
         c_ospeed: Default::default(),
     };
 
-    #[cfg(not(target_os = "freebsd"))]
+    #[cfg(not(any(target_os = "freebsd", target_os = "netbsd")))]
     {
         // Enable utf8 support if requested
         if utf8 {
@@ -400,10 +400,10 @@ pub fn create_pty_with_spawn(
     columns: u16,
     rows: u16,
 ) -> Result<Pty, Error> {
-    #[cfg(not(any(target_os = "macos", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd")))]
     let mut is_controling_terminal = true;
 
-    #[cfg(any(target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     let is_controling_terminal = true;
 
     let mut main: libc::c_int = 0;
@@ -452,7 +452,7 @@ pub fn create_pty_with_spawn(
         cmd
     };
 
-    #[cfg(not(any(target_os = "macos", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd")))]
     {
         // If running inside a flatpak sandbox.
         // Must retrieve $SHELL from outside the sandbox, so ask the host.
@@ -879,9 +879,9 @@ pub fn foreground_process_name(main_fd: 
         pid = shell_pid as libc::pid_t;
     }
 
-    #[cfg(not(any(target_os = "macos", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd")))]
     let comm_path = format!("/proc/{}/comm", pid);
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
     let comm_path = format!("/compat/linux/proc/{}/comm", pid);
 
     #[cfg(not(target_os = "macos"))]
@@ -907,9 +907,9 @@ pub fn foreground_process_path(
         pid = shell_pid as libc::pid_t;
     }
 
-    #[cfg(not(any(target_os = "macos", target_os = "freebsd")))]
+    #[cfg(not(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd")))]
     let link_path = format!("/proc/{}/cwd", pid);
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
     let link_path = format!("/compat/linux/proc/{}/cwd", pid);
 
     #[cfg(not(target_os = "macos"))]
