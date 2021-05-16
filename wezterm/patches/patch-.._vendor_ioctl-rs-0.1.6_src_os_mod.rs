$NetBSD$

--- ../vendor/ioctl-rs-0.1.6/src/os/mod.rs.orig	2017-11-20 03:11:32.000000000 +0000
+++ ../vendor/ioctl-rs-0.1.6/src/os/mod.rs	2021-05-16 17:55:51.157707560 +0000
@@ -12,3 +12,6 @@
 
 #[cfg(target_os = "openbsd")]
 pub mod openbsd;
+
+#[cfg(target_os = "netbsd")]
+pub mod netbsd;
