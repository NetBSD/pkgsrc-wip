$NetBSD$

No 64-bit atomics on NetBSD/mipsel.

--- vendor/crossbeam-utils-0.8.16/no_atomic.rs.orig	2024-03-23 07:40:12.537157751 +0000
+++ vendor/crossbeam-utils-0.8.16/no_atomic.rs
@@ -37,6 +37,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-gnu",
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
+    "mipsel-unknown-netbsd",
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
