$NetBSD$

Fix xattr build.

--- vendor/libc-0.2.154/src/unix/solarish/mod.rs.orig	2024-08-29 18:02:22.936992533 +0000
+++ vendor/libc-0.2.154/src/unix/solarish/mod.rs
@@ -1524,6 +1524,8 @@ pub const EOWNERDEAD: ::c_int = 58;
 pub const ENOTRECOVERABLE: ::c_int = 59;
 pub const ENOSTR: ::c_int = 60;
 pub const ENODATA: ::c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: ::c_int = 62;
 pub const ENOSR: ::c_int = 63;
 pub const ENONET: ::c_int = 64;
