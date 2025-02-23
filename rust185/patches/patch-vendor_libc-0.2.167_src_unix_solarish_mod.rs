$NetBSD$

Fix xattr build.

--- vendor/libc-0.2.167/src/unix/solarish/mod.rs.orig	2024-08-29 18:03:17.866520790 +0000
+++ vendor/libc-0.2.167/src/unix/solarish/mod.rs
@@ -1441,6 +1441,8 @@ pub const EOWNERDEAD: c_int = 58;
 pub const ENOTRECOVERABLE: c_int = 59;
 pub const ENOSTR: c_int = 60;
 pub const ENODATA: c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: c_int = 62;
 pub const ENOSR: c_int = 63;
 pub const ENONET: c_int = 64;
