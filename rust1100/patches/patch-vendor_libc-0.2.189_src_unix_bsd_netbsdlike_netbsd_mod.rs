$NetBSD$

Add m68k target.

--- vendor/libc-0.2.189/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2026-10-01 18:49:00.826338650 +0000
+++ vendor/libc-0.2.189/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2487,6 +2487,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "riscv64")] {
         mod riscv64;
         pub use self::riscv64::*;
+    } else if #[cfg(target_arch = "m68k")] {
+        mod m68k;
+        pub use self::m68k::*;
     } else {
         // Unknown target_arch
     }
