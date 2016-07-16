$NetBSD$

Support SIGWINCH.

--- src/liblibc/src/unix/solaris/mod.rs.orig	2016-03-03 01:03:58.000000000 +0000
+++ src/liblibc/src/unix/solaris/mod.rs
@@ -372,6 +372,7 @@ pub const SIGSEGV: ::c_int = 11;
 pub const SIGPIPE: ::c_int = 13;
 pub const SIGALRM: ::c_int = 14;
 pub const SIGTERM: ::c_int = 15;
+pub const SIGWINCH: ::c_int = 20;
 
 pub const WNOHANG: ::c_int = 0x40;
 
