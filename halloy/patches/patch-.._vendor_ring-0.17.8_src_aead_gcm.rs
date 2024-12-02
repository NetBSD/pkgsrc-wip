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

--- ../vendor/ring-0.17.8/src/aead/gcm.rs
+++ ../vendor/ring-0.17.8/src/aead/gcm.rs
@@ -57,7 +57,7 @@ impl Key {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::CLMUL => {
                 prefixed_extern! {
@@ -185,7 +185,7 @@ impl Context {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::CLMUL => {
                 prefixed_extern! {
@@ -236,7 +236,7 @@ impl Context {
                 target_arch = "aarch64",
                 target_arch = "arm",
                 target_arch = "x86_64",
-                target_arch = "x86"
+                all(target_arch = "x86", target_feature = "sse2")
             ))]
             Implementation::CLMUL => {
                 prefixed_extern! {
@@ -339,7 +339,7 @@ enum Implementation {
         target_arch = "aarch64",
         target_arch = "arm",
         target_arch = "x86_64",
-        target_arch = "x86"
+        all(target_arch = "x86", target_feature = "sse2")
     ))]
     CLMUL,
 
@@ -356,7 +356,7 @@ fn detect_implementation(cpu_features: c
         target_arch = "aarch64",
         target_arch = "arm",
         target_arch = "x86_64",
-        target_arch = "x86"
+        all(target_arch = "x86", target_feature = "sse2")
     )))]
     let _cpu_features = cpu_features;
 
@@ -367,7 +367,7 @@ fn detect_implementation(cpu_features: c
         }
     }
 
-    #[cfg(any(target_arch = "x86_64", target_arch = "x86"))]
+    #[cfg(any(target_arch = "x86_64", all(target_arch = "x86", target_feature = "sse2")))]
     {
         if cpu::intel::FXSR.available(cpu_features) && cpu::intel::PCLMULQDQ.available(cpu_features)
         {
