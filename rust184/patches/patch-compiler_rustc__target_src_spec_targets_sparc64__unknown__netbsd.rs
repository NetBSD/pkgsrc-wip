$NetBSD$

Make more similar to other sparc64 target specs.

--- compiler/rustc_target/src/spec/targets/sparc64_unknown_netbsd.rs.orig	2025-01-27 23:20:59.000000000 +0000
+++ compiler/rustc_target/src/spec/targets/sparc64_unknown_netbsd.rs
@@ -1,11 +1,13 @@
 use crate::abi::Endian;
-use crate::spec::{Cc, LinkerFlavor, Lld, Target, TargetOptions, base};
+use crate::spec::{Cc, LinkerFlavor, Lld, Target, base};
 
 pub(crate) fn target() -> Target {
     let mut base = base::netbsd::opts();
     base.cpu = "v9".into();
     base.add_pre_link_args(LinkerFlavor::Gnu(Cc::Yes, Lld::No), &["-m64"]);
     base.max_atomic_width = Some(64);
+    base.endian = Endian::Big;
+    base.mcount = "__mcount".into();
 
     Target {
         llvm_target: "sparc64-unknown-netbsd".into(),
@@ -18,6 +20,6 @@ pub(crate) fn target() -> Target {
         pointer_width: 64,
         data_layout: "E-m:e-i64:64-i128:128-n32:64-S128".into(),
         arch: "sparc64".into(),
-        options: TargetOptions { endian: Endian::Big, mcount: "__mcount".into(), ..base },
+        options: base,
     }
 }
