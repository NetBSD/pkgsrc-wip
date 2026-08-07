$NetBSD$

Exclude NetBSD from the non-Windows TIOCSTI path. NetBSD's libc does not
provide TIOCSTI, so gate the libc import, ioctl extern, and use_tiocsti
body behind cfg(all(not(windows), not(target_os = "netbsd"))), and
provide a no-op stub on NetBSD so the symbol still resolves.

--- src/fake_typer.rs.ORIG	2026-08-04 14:00:00.000000000 +0100
+++ src/fake_typer.rs
@@ -1,8 +1,8 @@
-#[cfg(not(windows))]
+#[cfg(all(not(windows), not(target_os = "netbsd")))]
 use libc;
 
 // Should we be using https://docs.rs/libc/0.2.44/libc/fn.ioctl.html instead?
-#[cfg(not(windows))]
+#[cfg(all(not(windows), not(target_os = "netbsd")))]
 unsafe extern "C" {
     pub fn ioctl(fd: libc::c_int, request: libc::c_ulong, arg: ...) -> libc::c_int;
 }
@@ -10,4 +10,4 @@
-#[cfg(not(windows))]
+#[cfg(all(not(windows), not(target_os = "netbsd")))]
 #[allow(clippy::useless_conversion)]
 pub fn use_tiocsti(string: &str) {
     for byte in string.as_bytes() {
@@ -22,3 +22,6 @@
 pub fn use_tiocsti(string: &str) {
     autopilot::key::type_string(string, &[], 0.0, 0.0);
 }
+
+#[cfg(target_os = "netbsd")]
+pub fn use_tiocsti(_string: &str) {}
