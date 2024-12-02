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

--- ../vendor/ring-0.17.8/src/arithmetic/montgomery.rs
+++ ../vendor/ring-0.17.8/src/arithmetic/montgomery.rs
@@ -128,7 +128,7 @@ unsafe fn mul_mont(
 #[cfg(not(any(
     target_arch = "aarch64",
     target_arch = "arm",
-    target_arch = "x86",
+    all(target_arch = "x86", target_feature = "sse2"),
     target_arch = "x86_64"
 )))]
 // TODO: Stop calling this from C and un-export it.
@@ -168,7 +168,7 @@ prefixed_export! {
     not(any(
         target_arch = "aarch64",
         target_arch = "arm",
-        target_arch = "x86",
+        all(target_arch = "x86", target_feature = "sse2"),
         target_arch = "x86_64"
     ))
 ))]
@@ -201,7 +201,7 @@ pub(super) fn limbs_from_mont_in_place(r
 #[cfg(not(any(
     target_arch = "aarch64",
     target_arch = "arm",
-    target_arch = "x86",
+    all(target_arch = "x86", target_feature = "sse2"),
     target_arch = "x86_64"
 )))]
 fn limbs_mul(r: &mut [Limb], a: &[Limb], b: &[Limb]) {
@@ -223,7 +223,7 @@ fn limbs_mul(r: &mut [Limb], a: &[Limb],
         target_arch = "aarch64",
         target_arch = "arm",
         target_arch = "x86_64",
-        target_arch = "x86"
+        all(target_arch = "x86", target_feature = "sse2")
     ))
 ))]
 prefixed_extern! {
@@ -236,7 +236,7 @@ prefixed_extern! {
     target_arch = "aarch64",
     target_arch = "arm",
     target_arch = "x86_64",
-    target_arch = "x86"
+    all(target_arch = "x86", target_feature = "sse2")
 ))]
 prefixed_extern! {
     // `r` and/or 'a' and/or 'b' may alias.
