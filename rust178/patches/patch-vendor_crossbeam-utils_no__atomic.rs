$NetBSD$

Add NetBSD/mipsel to list of non-atomic targets.

--- vendor/crossbeam-utils/no_atomic.rs.orig	2024-05-03 22:55:08.657084841 +0000
+++ vendor/crossbeam-utils/no_atomic.rs
@@ -5,6 +5,7 @@ const NO_ATOMIC: &[&str] = &[
     "bpfeb-unknown-none",
     "bpfel-unknown-none",
     "mipsel-sony-psx",
+    "mipsel-unknown-netbsd",
     "msp430-none-elf",
     "riscv32i-unknown-none-elf",
     "riscv32im-unknown-none-elf",
