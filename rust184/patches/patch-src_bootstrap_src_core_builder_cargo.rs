$NetBSD$

Find external libunwind and libLLVM in pkgsrc (not just Linux).
Use @PREFIX@ in rpath.

Adapt fix to
https://github.com/rust-lang/rust/issues/133629
(files restructured upstream)

--- src/bootstrap/src/core/builder/cargo.rs.orig	2025-02-02 15:19:31.785846508 +0000
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -646,7 +646,10 @@ impl Builder<'_> {
                 // Build proc macros both for the host and the target unless proc-macros are not
                 // supported by the target.
                 if target != compiler.host && cmd_kind != Kind::Check {
-                    let error = command(self.rustc(compiler))
+                    let mut rustc_cmd = command(self.rustc(compiler));
+                    self.add_rustc_lib_path(compiler, &mut rustc_cmd);
+
+                    let error = rustc_cmd
                         .arg("--target")
                         .arg(target.rustc_target_arg())
                         .arg("--print=file-names")
@@ -1198,6 +1201,9 @@ impl Builder<'_> {
             rustflags.arg("-Zinline-mir-preserve-debug");
         }
 
+        // added for pkgsrc libunwind or external LLVM
+        rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX/lib");
+
         Cargo {
             command: cargo,
             compiler,
