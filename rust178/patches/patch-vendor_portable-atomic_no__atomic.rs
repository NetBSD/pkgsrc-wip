$NetBSD$

mipsel-unknown-netbsd doesn't have 64-bit atomics.

--- vendor/portable-atomic/no_atomic.rs.orig	2024-04-02 18:18:04.323714290 +0000
+++ vendor/portable-atomic/no_atomic.rs
@@ -40,6 +40,7 @@ static NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-gnu",
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
+    "mipsel-unknown-netbsd",
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
