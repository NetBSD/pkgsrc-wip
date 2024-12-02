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

--- ../vendor/ring-0.17.8/src/aead/aes.rs
+++ ../vendor/ring-0.17.8/src/aead/aes.rs
@@ -149,7 +149,7 @@ impl Key {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::HWAES => {
                 set_encrypt_key!(aes_hw_set_encrypt_key, bytes, key_bits, &mut key)?
@@ -159,7 +159,7 @@ impl Key {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::VPAES_BSAES => {
                 set_encrypt_key!(vpaes_set_encrypt_key, bytes, key_bits, &mut key)?
@@ -180,7 +180,7 @@ impl Key {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::HWAES => encrypt_block!(aes_hw_encrypt, a, self),
 
@@ -188,7 +188,7 @@ impl Key {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::VPAES_BSAES => encrypt_block!(vpaes_encrypt, a, self),
 
@@ -219,7 +219,7 @@ impl Key {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::HWAES => {
                 ctr32_encrypt_blocks!(aes_hw_ctr32_encrypt_blocks, in_out, src, &self.inner, ctr)
@@ -263,7 +263,7 @@ impl Key {
                 ctr32_encrypt_blocks!(vpaes_ctr32_encrypt_blocks, in_out, src, &self.inner, ctr)
             }
 
-            #[cfg(target_arch = "x86")]
+            #[cfg(all(target_arch = "x86", target_feature = "sse2"))]
             Implementation::VPAES_BSAES => {
                 super::shift::shift_full_blocks(in_out, src, |input| {
                     self.encrypt_iv_xor_block(ctr.increment(), Block::from(input), cpu_features)
@@ -365,7 +365,7 @@ pub enum Implementation {
         target_arch = "aarch64",
         target_arch = "arm",
         target_arch = "x86_64",
-        target_arch = "x86"
+        all(target_arch = "x86", target_feature = "sse2")
     ))]
     HWAES = 1,
 
@@ -374,7 +374,7 @@ pub enum Implementation {
         target_arch = "aarch64",
         target_arch = "arm",
         target_arch = "x86_64",
-        target_arch = "x86"
+        all(target_arch = "x86", target_feature = "sse2")
     ))]
     VPAES_BSAES = 2,
 
@@ -387,7 +387,7 @@ fn detect_implementation(cpu_features: c
         target_arch = "aarch64",
         target_arch = "arm",
         target_arch = "x86_64",
-        target_arch = "x86"
+        all(target_arch = "x86", target_feature = "sse2")
     )))]
     let _cpu_features = cpu_features;
 
@@ -398,14 +398,14 @@ fn detect_implementation(cpu_features: c
         }
     }
 
-    #[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
+    #[cfg(any(target_arch = "x86_64", all(target_arch = "x86", target_feature = "sse2")))]
     {
         if cpu::intel::AES.available(cpu_features) {
             return Implementation::HWAES;
         }
     }
 
-    #[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
+    #[cfg(any(target_arch = "x86_64", all(target_arch = "x86", target_feature = "sse2")))]
     {
         if cpu::intel::SSSE3.available(cpu_features) {
             return Implementation::VPAES_BSAES;
