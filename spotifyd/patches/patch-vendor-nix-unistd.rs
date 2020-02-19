$NetBSD$

Later versions of libc have (correctly) removed `fexecve` for netbsd-like platforms therefore need
to patch earlier versions of nix that expect this to also be removed.

Fixed upstream in later versions:

https://github.com/nix-rust/nix/blob/922d5ee118a770435b14b08ec4be6f8ae9f7c30a/CHANGELOG.md#fixed-7

--- ../vendor/nix-0.10.0/src/unistd.rs.orig	2018-01-21 20:52:34.000000000 +0000
+++ ../vendor/nix-0.10.0/src/unistd.rs
@@ -633,7 +633,6 @@ pub fn execvp(filename: &CString, args: 
 #[cfg(any(target_os = "android",
           target_os = "freebsd",
           target_os = "linux",
-          target_os = "netbsd",
           target_os = "openbsd"))]
 #[inline]
 pub fn fexecve(fd: RawFd, args: &[CString], env: &[CString]) -> Result<Void> {
