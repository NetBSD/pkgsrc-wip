$NetBSD$

Avoid using the x86-specific implementations on non-sse2 x86
(from Debian)

https://github.com/briansmith/ring/issues/1999#issuecomment-2351243983

Upstream has said that the x86-specific implementation requires sse2, and
now enforces this via a static assert.

This patch replaces all checks in "src" for x86 with checks for x86 with
sse2 and also inhibits the build of assembler on x86 without sse2. This should
cause the generic implementations to be used.

The changes to "src" were created with the command
for file in `find src -name '*.rs'` ; do sed -i 's/target_arch = "x86"/all(target_arch = "x86", target_feature = "sse2")/g' $file ; done

Author: Peter Michael Green <plugwash@debian.org>

--- ../vendor/ring-0.17.8/src/cpu/intel.rs
+++ ../vendor/ring-0.17.8/src/cpu/intel.rs
@@ -13,11 +13,11 @@
 // CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 
 #![cfg_attr(
-    not(any(target_arch = "x86", target_arch = "x86_64")),
+    not(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64")),
     allow(dead_code)
 )]
 
-#[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+#[cfg(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64"))]
 mod abi_assumptions {
     // TOOD: Support targets that do not have SSE and SSE2 enabled, such as
     // x86_64-unknown-linux-none. See
@@ -29,7 +29,7 @@ mod abi_assumptions {
 
     #[cfg(target_arch = "x86_64")]
     const _ASSUMED_POINTER_SIZE: usize = 8;
-    #[cfg(target_arch = "x86")]
+    #[cfg(all(target_arch = "x86", target_feature = "sse2"))]
     const _ASSUMED_POINTER_SIZE: usize = 4;
     const _ASSUMED_USIZE_SIZE: () = assert!(core::mem::size_of::<usize>() == _ASSUMED_POINTER_SIZE);
     const _ASSUMED_REF_SIZE: () =
@@ -43,7 +43,7 @@ pub(crate) struct Feature {
     mask: u32,
 }
 
-#[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+#[cfg(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64"))]
 pub(super) unsafe fn init_global_shared_with_assembly() {
     prefixed_extern! {
         fn OPENSSL_cpuid_setup();
@@ -57,7 +57,7 @@ impl Feature {
     #[allow(clippy::needless_return)]
     #[inline(always)]
     pub fn available(&self, _: super::Features) -> bool {
-        #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+        #[cfg(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64"))]
         {
             prefixed_extern! {
                 static mut OPENSSL_ia32cap_P: [u32; 4];
@@ -65,7 +65,7 @@ impl Feature {
             return self.mask == self.mask & unsafe { OPENSSL_ia32cap_P[self.word] };
         }
 
-        #[cfg(not(any(target_arch = "x86", target_arch = "x86_64")))]
+        #[cfg(not(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64")))]
         {
             return false;
         }
