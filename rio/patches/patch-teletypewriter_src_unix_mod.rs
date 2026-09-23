$NetBSD$

NetBSD support: TIOCSWINSZ (same value as FreeBSD), BSD termios branch, and no
IUTF8 (not in NetBSD libc).  c_ospeed=0 means B0, which makes the kernel PTY
path send SIGHUP to the session leader, so set B38400.

$SHELL in graphical sessions is often the display manager's /bin/ksh, so take
the login shell from getpwuid_r instead.

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
@@ -381,6 +383,13 @@
             },
         };
 
+        #[cfg(target_os = "netbsd")]
+        if let Ok(ref pw) = pw {
+            if !pw.shell.is_empty() {
+                shell = pw.shell.to_owned();
+            }
+        }
+
         Ok(Self { user, home, shell })
     }
 }
