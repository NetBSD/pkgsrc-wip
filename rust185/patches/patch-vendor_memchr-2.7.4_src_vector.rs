$NetBSD$

Don't try to do neon / SIMD on big-endian aarch64.

--- vendor/memchr-2.7.4/src/vector.rs.orig	2024-09-22 14:16:06.473207292 +0000
+++ vendor/memchr-2.7.4/src/vector.rs
@@ -289,7 +289,7 @@ mod x86avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64neon {
     use core::arch::aarch64::*;
 
