$NetBSD$

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- compiler/rustc_target/src/spec/netbsd_base.rs.orig	2021-06-17 03:53:51.000000000 +0000
+++ compiler/rustc_target/src/spec/netbsd_base.rs
@@ -1,6 +1,14 @@
-use crate::spec::{RelroLevel, TargetOptions};
+use crate::spec::{LinkArgs, LinkerFlavor, RelroLevel, TargetOptions};
 
 pub fn opts() -> TargetOptions {
+    let mut args = LinkArgs::new();
+    args.insert (
+        LinkerFlavor::Gcc,
+        vec![
+            // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-L@PREFIX@/lib/libatomic".to_string(),
+        ],
+    );
     TargetOptions {
         os: "netbsd".to_string(),
         dynamic_linking: true,
