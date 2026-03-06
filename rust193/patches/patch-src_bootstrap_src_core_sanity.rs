$NetBSD$

Temporarily add m68k-unknown-netbsd to STAGE0_MISSING_TARGETS.
...while we bootstrap the target.

--- src/bootstrap/src/core/sanity.rs.orig	2026-02-24 22:45:56.679440377 +0000
+++ src/bootstrap/src/core/sanity.rs
@@ -42,6 +42,7 @@ const STAGE0_MISSING_TARGETS: &[&str] = 
     // just a dummy comment so the list doesn't get onelined
     "riscv64gc-unknown-redox",
     "hexagon-unknown-qurt",
+    "m68k-unknown-netbsd",
 ];
 
 /// Minimum version threshold for libstdc++ required when using prebuilt LLVM
