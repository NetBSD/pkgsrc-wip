$NetBSD$

--- vendor/aho-corasick/src/packed/teddy/builder.rs.orig	2024-02-18 10:54:27.960401196 +0000
+++ vendor/aho-corasick/src/packed/teddy/builder.rs
@@ -230,7 +230,7 @@ impl Builder {
                 }
             }
         }
-        #[cfg(target_arch = "aarch64")]
+        #[cfg(all(target_arch = "aarch64", target_feature = "neon", target_endian = "little"))]
         {
             use self::aarch64::SlimNeon;
 
@@ -301,7 +301,7 @@ impl Builder {
         }
         #[cfg(not(any(
             all(target_arch = "x86_64", target_feature = "sse2"),
-            target_arch = "aarch64"
+            all(target_arch = "aarch64", target_feature = "neon", target_endian = "little")
         )))]
         {
             None
@@ -705,7 +705,7 @@ mod x86_64 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_feature = "neon", target_endian = "little"))]
 mod aarch64 {
     use core::arch::aarch64::uint8x16_t;
 
