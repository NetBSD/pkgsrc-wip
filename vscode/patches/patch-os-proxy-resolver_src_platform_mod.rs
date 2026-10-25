$NetBSD$

* Add support to NetBSD and FreeBSD

--- os-proxy-resolver/src/platform/mod.rs.orig	2026-10-24 15:44:57.182930670 +0000
+++ os-proxy-resolver/src/platform/mod.rs
@@ -19,7 +19,7 @@ use crate::types::{PlatformProxyConfig, 
 #[cfg(target_os = "macos")]
 #[path = "macos.rs"]
 mod imp;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd", target_os = "netbsd"))]
 #[path = "linux.rs"]
 mod imp;
 #[cfg(windows)]
