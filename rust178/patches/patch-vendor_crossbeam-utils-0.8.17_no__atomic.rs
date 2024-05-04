$NetBSD$

Add NetBSD/mipsel to list of those who have no atomics.

--- vendor/crossbeam-utils-0.8.17/no_atomic.rs.orig	2024-05-03 22:51:16.357431380 +0000
+++ vendor/crossbeam-utils-0.8.17/no_atomic.rs
@@ -5,6 +5,7 @@ const NO_ATOMIC: &[&str] = &[
     "bpfeb-unknown-none",
     "bpfel-unknown-none",
     "mipsel-sony-psx",
+    "mipsel-unknown-netbsd",
     "msp430-none-elf",
     "riscv32i-unknown-none-elf",
     "riscv32im-unknown-none-elf",
