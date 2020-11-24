$NetBSD$

Disable stack probes on SunOS.

--- compiler/rustc_target/src/spec/x86_64_sun_solaris.rs.orig	2020-11-16 14:01:53.000000000 +0000
+++ compiler/rustc_target/src/spec/x86_64_sun_solaris.rs
@@ -5,7 +5,6 @@ pub fn target() -> TargetResult {
     base.pre_link_args.insert(LinkerFlavor::Gcc, vec!["-m64".to_string()]);
     base.cpu = "x86-64".to_string();
     base.max_atomic_width = Some(64);
-    base.stack_probes = true;
 
     Ok(Target {
         llvm_target: "x86_64-pc-solaris".to_string(),
