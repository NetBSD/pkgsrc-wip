$NetBSD$

--- vendor/crossbeam-utils-0.8.12/no_atomic.rs.orig	2023-01-25 01:49:15.000000000 +0000
+++ vendor/crossbeam-utils-0.8.12/no_atomic.rs
@@ -41,6 +41,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
     "mipsel-unknown-none",
+    "mipsel-unknown-netbsd",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
     "msp430-none-elf",
