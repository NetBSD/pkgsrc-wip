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

--- ../vendor/ring-0.17.8/src/cpu.rs
+++ ../vendor/ring-0.17.8/src/cpu.rs
@@ -27,13 +27,13 @@ pub(crate) fn features() -> Features {
     #[cfg(any(target_arch = "aarch64", target_arch = "arm"))]
     use arm::init_global_shared_with_assembly;
 
-    #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+    #[cfg(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64"))]
     use intel::init_global_shared_with_assembly;
 
     #[cfg(any(
         target_arch = "aarch64",
         target_arch = "arm",
-        target_arch = "x86",
+        all(target_arch = "x86", target_feature = "sse2"),
         target_arch = "x86_64",
     ))]
     {
@@ -47,5 +47,5 @@ pub(crate) fn features() -> Features {
 #[cfg(any(target_arch = "aarch64", target_arch = "arm"))]
 pub mod arm;
 
-#[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+#[cfg(any(all(target_arch = "x86", target_feature = "sse2"), target_arch = "x86_64"))]
 pub mod intel;
