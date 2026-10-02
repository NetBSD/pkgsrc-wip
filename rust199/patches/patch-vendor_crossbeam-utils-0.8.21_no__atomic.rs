$NetBSD$

Add NetBSD/mipsel to non-atomic targets.

--- vendor/crossbeam-utils-0.8.21/no_atomic.rs.orig	2026-10-01 18:24:43.096581616 +0000
+++ vendor/crossbeam-utils-0.8.21/no_atomic.rs
@@ -5,5 +5,6 @@ const NO_ATOMIC: &[&str] = &[
     "bpfeb-unknown-none",
     "bpfel-unknown-none",
     "mipsel-sony-psx",
+    "mipsel-unknown-netbsd",
     "msp430-none-elf",
 ];
