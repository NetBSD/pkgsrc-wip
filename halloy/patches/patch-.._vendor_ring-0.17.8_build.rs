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

--- ../vendor/ring-0.17.8/build.rs
+++ ../vendor/ring-0.17.8/build.rs
@@ -430,7 +430,7 @@ fn build_c_code(
 
     generate_prefix_symbols_asm_headers(out_dir, ring_core_prefix).unwrap();
 
-    let (asm_srcs, obj_srcs) = if let Some(asm_target) = asm_target {
+    let (mut asm_srcs, mut obj_srcs) = if let Some(asm_target) = asm_target {
         let perlasm_src_dsts = perlasm_src_dsts(asm_dir, asm_target);
 
         if !use_pregenerated {
@@ -454,6 +454,21 @@ fn build_c_code(
         (vec![], vec![])
     };
 
+    use std::env;
+
+    if target.arch == "x86" {
+        let mut havesse2 = false;
+        for target_feature in env::var("CARGO_CFG_TARGET_FEATURE").unwrap_or("".to_string()).split(",") {
+            if target_feature == "sse2" {
+                havesse2 = true;
+            }
+        }
+        if !havesse2 {
+            asm_srcs = vec![];
+            obj_srcs = vec![];
+        }
+    }
+
     let core_srcs = sources_for_arch(&target.arch)
         .into_iter()
         .filter(|p| !is_perlasm(p))
