$NetBSD$

Later versions of libc have (correctly) removed `fexecve` for netbsd-like platforms therefore need
to patch earlier versions of nix that expect this to also remove.

--- ../vendor/nix-0.11.0/src/unistd.rs.orig	2018-06-01 02:14:43.000000000 +0000
+++ ../vendor/nix-0.11.0/src/unistd.rs
@@ -644,7 +644,6 @@ pub fn execvp(filename: &CString, args: 
 #[cfg(any(target_os = "android",
           target_os = "freebsd",
           target_os = "linux",
-          target_os = "netbsd",
           target_os = "openbsd"))]
 #[inline]
 pub fn fexecve(fd: RawFd, args: &[CString], env: &[CString]) -> Result<Void> {
