$NetBSD$

See: https://github.com/Spotifyd/spotifyd/pull/796

--- src/utils.rs.orig	2021-01-14 14:52:28.000000000 +0000
+++ src/utils.rs
@@ -3,7 +3,7 @@ use std::env;
 #[cfg(target_os = "macos")]
 use whoami;
 
-#[cfg(any(target_os = "freebsd", target_os = "linux"))]
+#[cfg(any(target_os = "netbsd", target_os = "freebsd", target_os = "linux"))]
 fn get_shell_ffi() -> Option<String> {
     use libc::{geteuid, getpwuid_r};
     use std::{ffi::CStr, mem, ptr};
