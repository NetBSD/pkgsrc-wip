$NetBSD$

Unbreak this module.

I admit to this entirely being based on "cargo cult" and based on
what the compiler told me, but at least the rust compiler (cross-)builds
for NetBSD/risc64 with this, whereas it did not earlier.

--- vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/riscv64.rs.orig	2025-11-02 16:57:14.244169978 +0000
+++ vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/riscv64.rs
@@ -1,28 +1,53 @@
-use PT_FIRSTMACH;
-
 use crate::prelude::*;
+use crate::PT_FIRSTMACH;
 
 pub type __greg_t = u64;
-pub type __cpu_simple_lock_nv_t = c_int;
-pub type __gregset = [__greg_t; _NGREG];
-pub type __fregset = [__freg; _NFREG];
-
-s! {
-    pub struct mcontext_t {
-        pub __gregs: __gregset,
-        pub __fregs: __fpregset,
-        __spare: [crate::__greg_t; 7],
-    }
+pub union __fpreg {
+    pub u_u64: u64,
+    pub u_d: c_double,
+}
+pub type __cpu_simple_lock_nv_t = c_uint;
+pub type __gregset_t = [__greg_t; _NGREG];
+pub type __fregset_t = [__fpreg; _NFREG];
+
+#[derive(Debug)]
+pub struct mcontext_t {
+    pub __gregs: __gregset_t,
+    pub __fregs: __fregset_t,
+    __spare: [crate::__greg_t; 7],
 }
 
-s_no_extra_traits! {
-    pub union __fpreg {
-        pub u_u64: u64,
-        pub u_d: c_double,
+impl core::cmp::PartialEq for __fpreg {
+    fn eq(&self, other: &__fpreg) -> bool {
+        unsafe { self.u_u64 == other.u_u64 || self.u_d == other.u_d }
+    }
+}
+impl core::cmp::Eq for __fpreg {}
+impl core::marker::Copy for __fpreg {}
+impl core::clone::Clone for __fpreg {
+    fn clone(&self) -> __fpreg {
+        *self
+    }
+}
+impl hash::Hash for __fpreg {
+    fn hash<H: hash::Hasher>(&self, state: &mut H) {
+        unsafe {
+            self.u_u64.hash(state);
+        }
+    }
+}
+impl core::fmt::Debug for __fpreg {
+    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
+        unsafe {
+            f.debug_struct("__fpreg")
+                .field("u_u64", &self.u_u64)
+                .field("u_d", &self.u_d)
+                .finish()
+        }
     }
 }
 
-pub(crate) const _ALIGNBYTES: usize = size_of::<c_long>() - 1;
+pub(crate) const _ALIGNBYTES: usize = 0xf;
 
 pub const PT_GETREGS: c_int = PT_FIRSTMACH + 0;
 pub const PT_SETREGS: c_int = PT_FIRSTMACH + 1;
