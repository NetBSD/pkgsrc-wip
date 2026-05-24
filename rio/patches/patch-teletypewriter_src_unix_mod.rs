$NetBSD$

Add NetBSD support to teletypewriter: TIOCSWINSZ constant (same value as
FreeBSD), BSD termios branch, and exclude NetBSD from the Linux/macOS-only
IUTF8 flag (not defined in NetBSD libc).  Also set B38400 baud rate in the
PTY termios to prevent NetBSD tty.c B0 hangup semantics (c_ospeed=0 triggers
ttysig(SIGHUP) to the session leader via the kernel PTY path).

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
@@ -289,25 +291,25 @@
         c_line: 0,
     };
 
-    #[cfg(any(target_os = "macos", target_os = "freebsd"))]
+    #[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "netbsd"))]
     let mut term = libc::termios {
         c_iflag: libc::ICRNL | libc::IXON | libc::IXANY | libc::IMAXBEL | libc::BRKINT,
         c_oflag: libc::OPOST | libc::ONLCR,
         c_cflag: libc::CREAD | libc::CS8 | libc::HUPCL,
         c_lflag: libc::ICANON
             | libc::ISIG
             | libc::IEXTEN
             | libc::ECHO
             | libc::ECHOE
             | libc::ECHOK
             | libc::ECHOKE
             | libc::ECHOCTL,
         c_cc: Default::default(),
-        c_ispeed: Default::default(),
-        c_ospeed: Default::default(),
+        c_ispeed: libc::B38400 as libc::c_int,
+        c_ospeed: libc::B38400 as libc::c_int,
     };
 
-    #[cfg(not(target_os = "freebsd"))]
+    #[cfg(not(any(target_os = "freebsd", target_os = "netbsd")))]
     {
         // Enable utf8 support if requested
         if utf8 {
