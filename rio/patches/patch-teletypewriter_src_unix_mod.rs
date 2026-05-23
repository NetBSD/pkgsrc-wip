$NetBSD$

Add NetBSD support to teletypewriter: TIOCSWINSZ constant (same value as
FreeBSD), BSD termios branch, and exclude NetBSD from the Linux/macOS-only
IUTF8 flag (not defined in NetBSD libc).

--- teletypewriter/src/unix/mod.rs.orig
+++ teletypewriter/src/unix/mod.rs
@@ -34,6 +34,8 @@
 const TIOCSWINSZ: libc::c_ulong = 0x80087467;
 #[cfg(target_os = "macos")]
 const TIOCSWINSZ: libc::c_ulong = 2148037735;
+#[cfg(target_os = "netbsd")]
+const TIOCSWINSZ: libc::c_ulong = 0x80087467;
 
 #[link(name = "util")]
 extern "C" {
@@ -289,7 +291,7 @@
         c_line: 0,
     };
 
-    #[cfg(any(target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     let mut term = libc::termios {
         c_iflag: libc::ICRNL | libc::IXON | libc::IXANY | libc::IMAXBEL | libc::BRKINT,
         c_oflag: libc::OPOST | libc::ONLCR,
@@ -307,7 +309,7 @@
         c_ospeed: Default::default(),
     };
 
-    #[cfg(not(target_os = "freebsd"))]
+    #[cfg(not(any(target_os = "freebsd", target_os = "netbsd")))]
     {
         // Enable utf8 support if requested
         if utf8 {
