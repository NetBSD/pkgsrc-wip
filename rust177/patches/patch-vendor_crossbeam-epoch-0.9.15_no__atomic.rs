$NetBSD$

Add "mipsel-unknown-netbsd" to the list who don't have 
native 64-bit atomic ops.

--- vendor/crossbeam-epoch-0.9.15/no_atomic.rs.orig	2024-03-23 07:58:15.197582364 +0000
+++ vendor/crossbeam-epoch-0.9.15/no_atomic.rs
@@ -37,6 +37,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-gnu",
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
+    "mipsel-unknown-netbsd",
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
