$NetBSD$

Add m68k target.

--- vendor/libc-0.2.178/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2026-03-02 23:18:25.000000000 +0000
+++ vendor/libc-0.2.178/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2437,6 +2437,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "riscv64")] {
         mod riscv64;
         pub use self::riscv64::*;
+    } else if #[cfg(target_arch = "m68k")] {
+        mod m68k;
+        pub use self::m68k::*;
     } else {
         // Unknown target_arch
     }
