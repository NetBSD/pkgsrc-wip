$NetBSD$

--- ../vendor/tokio-uds-0.2.2/src/ucred.rs.orig	2018-09-25 17:31:24.000000000 +0000
+++ ../vendor/tokio-uds-0.2.2/src/ucred.rs
@@ -12,7 +12,7 @@ pub struct UCred {
 #[cfg(any(target_os = "linux", target_os = "android"))]
 pub use self::impl_linux::get_peer_cred;
 
-#[cfg(any(target_os = "dragonfly", target_os = "macos", target_os = "ios", target_os = "freebsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "dragonfly", target_os = "macos", target_os = "ios", target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"))]
 pub use self::impl_macos::get_peer_cred;
 
 #[cfg(any(target_os = "linux", target_os = "android"))]
@@ -61,7 +61,7 @@ pub mod impl_linux {
     }
 }
 
-#[cfg(any(target_os = "dragonfly", target_os = "macos", target_os = "ios", target_os = "freebsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "dragonfly", target_os = "macos", target_os = "ios", target_os = "freebsd", target_os = "openbsd", target_os = "netbsd"))]
 pub mod impl_macos {
     use libc::getpeereid;
     use std::{io, mem};
