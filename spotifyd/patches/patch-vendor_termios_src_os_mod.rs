$NetBSD$

Upstream PR is wip: https://github.com/dcuddeback/termios-rs/pull/22

--- ../vendor/termios-0.2.2/src/os/mod.rs.orig	2016-01-20 16:52:20.000000000 +0000
+++ ../vendor/termios-0.2.2/src/os/mod.rs
@@ -4,8 +4,10 @@
 #[cfg(target_os = "macos")] pub use self::macos as target;
 #[cfg(target_os = "freebsd")] pub use self::freebsd as target;
 #[cfg(target_os = "openbsd")] pub use self::openbsd as target;
+#[cfg(target_os = "netbsd")] pub use self::netbsd as target;
 
 #[cfg(target_os = "linux")] pub mod linux;
 #[cfg(target_os = "macos")] pub mod macos;
 #[cfg(target_os = "freebsd")] pub mod freebsd;
 #[cfg(target_os = "openbsd")] pub mod openbsd;
+#[cfg(target_os = "netbsd")] pub mod netbsd;
