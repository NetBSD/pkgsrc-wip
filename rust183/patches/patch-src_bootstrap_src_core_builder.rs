$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.5 2024/07/27 02:35:24 tnn Exp $

Find external libunwind on Linux.
Use @PREFIX@ in rpath.

Also, following up on
https://github.com/rust-lang/rust/issues/133629, reverse
https://github.com/rust-lang/rust/pull/130899/commits/68034f837a39387e49fc7d7c5b088f5372a1127e
to see if this fixes the cross-compile failure.

--- src/bootstrap/src/core/builder.rs.orig	2024-11-26 10:12:09.000000000 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -1698,24 +1698,10 @@ impl<'a> Builder<'a> {
         match mode {
             Mode::Std | Mode::ToolBootstrap | Mode::ToolStd => {}
             Mode::Rustc | Mode::Codegen | Mode::ToolRustc => {
-                // Build proc macros both for the host and the target unless proc-macros are not
-                // supported by the target.
+		// Build proc macros both for the host and the target
                 if target != compiler.host && cmd_kind != Kind::Check {
-                    let error = command(self.rustc(compiler))
-                        .arg("--target")
-                        .arg(target.rustc_target_arg())
-                        .arg("--print=file-names")
-                        .arg("--crate-type=proc-macro")
-                        .arg("-")
-                        .run_capture(self)
-                        .stderr();
-                    let not_supported = error
-                        .lines()
-                        .any(|line| line.contains("unsupported crate type `proc-macro`"));
-                    if !not_supported {
-                        cargo.arg("-Zdual-proc-macros");
-                        rustflags.arg("-Zdual-proc-macros");
-                    }
+		    cargo.arg("-Zdual-proc-macros");
+		    rustflags.arg("-Zdual-proc-macros");
                 }
             }
         }
@@ -2262,6 +2248,11 @@ impl<'a> Builder<'a> {
             rustdocflags.arg("--cfg=parallel_compiler");
         }
 
+	// added for pkgsrc libunwind
+	if target.contains("linux") {
+		rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+	}
+
         Cargo {
             command: cargo,
             compiler,
