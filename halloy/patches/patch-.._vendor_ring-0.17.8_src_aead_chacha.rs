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

--- ../vendor/ring-0.17.8/src/aead/chacha.rs
+++ ../vendor/ring-0.17.8/src/aead/chacha.rs
@@ -20,7 +20,7 @@ use super::{quic::Sample, Nonce};
     not(any(
         target_arch = "aarch64",
         target_arch = "arm",
-        target_arch = "x86",
+        all(target_arch = "x86", target_feature = "sse2"),
         target_arch = "x86_64"
     ))
 ))]
@@ -75,7 +75,7 @@ impl Key {
         // has this limitation and come up with a better solution.
         //
         // https://rt.openssl.org/Ticket/Display.html?id=4362
-        if cfg!(any(target_arch = "arm", target_arch = "x86")) && src.start != 0 {
+        if cfg!(any(target_arch = "arm", all(target_arch = "x86", target_feature = "sse2"))) && src.start != 0 {
             let len = in_out.len() - src.start;
             in_out.copy_within(src, 0);
             self.encrypt_in_place(counter, &mut in_out[..len]);
@@ -91,7 +91,7 @@ impl Key {
         #[cfg(any(
             target_arch = "aarch64",
             target_arch = "arm",
-            target_arch = "x86",
+            all(target_arch = "x86", target_feature = "sse2"),
             target_arch = "x86_64"
         ))]
         #[inline(always)]
@@ -128,7 +128,7 @@ impl Key {
         #[cfg(not(any(
             target_arch = "aarch64",
             target_arch = "arm",
-            target_arch = "x86",
+            all(target_arch = "x86", target_feature = "sse2"),
             target_arch = "x86_64"
         )))]
         use fallback::ChaCha20_ctr32;
@@ -169,7 +169,7 @@ impl Counter {
         not(any(
             target_arch = "aarch64",
             target_arch = "arm",
-            target_arch = "x86",
+            all(target_arch = "x86", target_feature = "sse2"),
             target_arch = "x86_64"
         ))
     ))]
@@ -219,7 +219,7 @@ mod tests {
         let max_offset = if cfg!(any(
             target_arch = "aarch64",
             target_arch = "arm",
-            target_arch = "x86",
+            all(target_arch = "x86", target_feature = "sse2"),
             target_arch = "x86_64"
         )) {
             MAX_ALIGNMENT_AND_OFFSET
