$NetBSD$

--- vendor/libc-0.2.176/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-12-14 09:45:59.454696633 +0000
+++ vendor/libc-0.2.176/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,27 +1,58 @@
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
 
-s_no_extra_traits! {
-    pub union __fpreg {
-        pub u_u64: u64,
-        pub u_d: c_double,
+#[derive(Clone,Copy)]
+pub union __fpreg {
+    pub u_u64: u64,
+    pub u_d: c_double,
+}
+
+cfg_if! {
+    if #[cfg(feature = "extra_traits")] {
+        impl PartialEq for __fpreg {
+            fn eq(&self, other: &__fpreg) -> bool {
+                unsafe {
+                    self.u_u64 == other.u_u64
+                        || self.u_d == other.u_d
+                }
+            }
+        }
+        impl Eq for __fpreg {}
+        impl hash::Hash for __fpreg {
+            fn hash<H: hash::Hasher>(&self, state: &mut H) {
+                unsafe {
+                    self.u_u64.hash(state);
+                }
+            }
+        }
+        impl fmt::Debug for __fpreg {
+            fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
+                unsafe {
+                    f.debug_struct("__fpreg")
+                        .field("u_u64", &self.u_u64)
+                        .field("u_d", &self.u_d)
+                        .finish()
+                }
+            }
+        }
     }
 }
 
+
 pub(crate) const _ALIGNBYTES: usize = size_of::<c_long>() - 1;
 
 pub const PT_GETREGS: c_int = PT_FIRSTMACH + 0;
