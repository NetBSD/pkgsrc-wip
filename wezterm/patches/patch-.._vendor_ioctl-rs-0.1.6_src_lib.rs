$NetBSD$

--- ../vendor/ioctl-rs-0.1.6/src/lib.rs.orig	2017-11-20 03:11:32.000000000 +0000
+++ ../vendor/ioctl-rs-0.1.6/src/lib.rs	2021-05-16 17:56:29.599821657 +0000
@@ -21,6 +21,9 @@
 #[cfg(target_os = "openbsd")]
 pub use os::openbsd::*;
 
+#[cfg(target_os = "netbsd")]
+pub use os::netbsd::*;
+
 mod os;
 
 
