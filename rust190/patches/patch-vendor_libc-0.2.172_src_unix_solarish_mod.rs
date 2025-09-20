$NetBSD$

Fix xattr build.

--- vendor/libc-0.2.172/src/unix/solarish/mod.rs.orig	2025-06-28 07:52:15.632394747 +0000
+++ vendor/libc-0.2.172/src/unix/solarish/mod.rs
@@ -1421,6 +1421,8 @@ pub const EBFONT: c_int = 57;
 pub const EOWNERDEAD: c_int = 58;
 pub const ENOTRECOVERABLE: c_int = 59;
 pub const ENOSTR: c_int = 60;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ENODATA: c_int = 61;
 pub const ETIME: c_int = 62;
 pub const ENOSR: c_int = 63;
