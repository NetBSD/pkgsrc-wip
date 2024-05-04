$NetBSD$

--- vendor/aho-corasick/src/packed/vector.rs.orig	2024-02-18 10:12:16.371081231 +0000
+++ vendor/aho-corasick/src/packed/vector.rs
@@ -595,7 +595,7 @@ mod x86_64_avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_feature = "neon", target_endian = "little"))]
 mod aarch64_neon {
     use core::arch::aarch64::*;
 
