$NetBSD$

--- vendor/libc-0.2.137/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2023-01-25 01:49:16.000000000 +0000
+++ vendor/libc-0.2.137/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3044,7 +3044,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "mips")] {
+	mod mips;
+	pub use self::mips::*;
     } else {
-        // Unknown target_arch
+        // Unknown target_arch, this should error out
+	mod unknown;
+	pub use self::unknown::*;
     }
 }
