$NetBSD$

--- vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-12-14 06:33:12.291690472 +0000
+++ vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,16 +1,16 @@
-use PT_FIRSTMACH;
+use crate::PT_FIRSTMACH;
 
 use crate::prelude::*;
 
 pub type __greg_t = u64;
 pub type __cpu_simple_lock_nv_t = c_int;
 pub type __gregset = [__greg_t; _NGREG];
-pub type __fregset = [__freg; _NFREG];
+pub type __fpregset = [__fpreg; _NFREG];
 
 s! {
     pub struct mcontext_t {
         pub __gregs: __gregset,
-        pub __fregs: __fpregset,
+        pub __fpregs: __fpregset,
         __spare: [crate::__greg_t; 7],
     }
 }
@@ -22,6 +22,55 @@ s_no_extra_traits! {
     }
 }
 
+cfg_if! {
+    if #[cfg(feature = "extra_traits")] {
+//      use ::self::fmt;
+//      use ::self::hash;
+        use core::marker::Copy;
+        use core::clone::Clone;
+        #[cfg(libc_union)]
+        impl PartialEq for __fpreg {
+            fn eq(&self, other: &__fpreg) -> bool {
+                unsafe {
+                    self.u_64 == other.u_64
+                        || self.u_d == other.u_d
+                }
+            }
+        }
+        #[cfg(libc_union)]
+        impl Eq for __fpreg {}
+        #[cfg(libc_union)]
+        impl ::fmt::Debug for __fpreg {
+            fn fmt(&self, f: &mut ::fmt::Formatter) -> ::fmt::Result {
+                unsafe {
+                    f.debug_struct("__fpreg")
+                        .field("u_u64", &self.u_64)
+                        .field("u_d", &self.u_d)
+                        .finish()
+                }
+            }
+        }
+        #[cfg(libc_union)]
+        impl ::hash::Hash for __fpreg {
+            fn hash<H: ::hash::Hasher>(&self, state: &mut H) {
+                unsafe {
+                    self.u_64.hash(state);
+                    self.u_d.hash(state);
+                }
+            }
+        }
+        #[cfg(libc_union)]
+        impl ::Copy for __fpreg {}
+        #[cfg(libc_union)]
+        impl ::Clone for __fpreg {
+            fn clone(&self) -> __fpreg {
+                *self
+            }
+        }
+    }
+}
+
+
 pub(crate) const _ALIGNBYTES: usize = size_of::<c_long>() - 1;
 
 pub const PT_GETREGS: c_int = PT_FIRSTMACH + 0;
