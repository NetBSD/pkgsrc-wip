$NetBSD$

NetBSD doesn't actually need the same workaround as OpenBSD and Haiku;
on the TCP level, the TCP_KEEPALIVE socket option is recognized.

--- ../vendor/net2-0.2.36/src/ext.rs.orig	2020-09-07 17:29:04.000000000 +0000
+++ ../vendor/net2-0.2.36/src/ext.rs
@@ -668,7 +668,7 @@ impl<T: AsRawSocket> AsSock for T {
 cfg_if! {
     if #[cfg(any(target_os = "macos", target_os = "ios"))] {
         use libc::TCP_KEEPALIVE as KEEPALIVE_OPTION;
-    } else if #[cfg(any(target_os = "haiku", target_os = "netbsd", target_os = "openbsd"))] {
+    } else if #[cfg(any(target_os = "haiku", target_os = "openbsd"))] {
         use libc::SO_KEEPALIVE as KEEPALIVE_OPTION;
     } else if #[cfg(unix)] {
         use libc::TCP_KEEPIDLE as KEEPALIVE_OPTION;
